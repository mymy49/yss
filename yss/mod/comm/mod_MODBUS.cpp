#include <__cross_studio_io.h>
#include <mod/comm/MODBUS.h>
#include <string.h>

namespace mod
{
namespace comm
{
static void thread_handleModbus(void *var);

enum
{
    READ_INPUT_REGISTER = 0x04,
    WRITE_SINGLE_REGISTER = 0x06,
    WRITE_MULTI_REGISTER = 0x10
};

MODBUS::MODBUS(unsigned short rcvBufSize, unsigned short memoryDepth)
{
    mPeri = 0;
    setRx = 0;
    setTx = 0;
    mSendFlag = false;
    mReceiveFlag = false;
    rcvHandler = 0;
    mId = 0;
    mRcvBuf = new signed short[rcvBufSize];
    mMemory = new signed short[memoryDepth];
    mMemoryDepth = memoryDepth;
    mRcvBufSize = rcvBufSize;

    memset(mMemory, 0x00, memoryDepth * sizeof(signed short));
}

void MODBUS::setId(unsigned char id)
{
    mId = id;
}

bool MODBUS::init(Config config)
{
    mPeri = &config.peri;
    setRx = config.setRx;
    setTx = config.setTx;
    rcvHandler = config.receiveHandler;

    if (mRcvBuf && mMemory)
    {
        mThreadId = thread::add(thread_handleModbus, this, config.threadStacksize);
        // 이 시점부터 다른 장치가 접근 못하도록 unlock이 없음.
        mPeri->lock();
        return true;
    }
    else
    {
        return false;
    }
}

extern const unsigned char gCRCHi[256];
extern const unsigned char gCRCLo[256];

void MODBUS::calculateCrc(unsigned char byte)
{
    unsigned char buf;

    buf = mCrcHi ^ byte;
    mCrcHi = mCrcLo ^ gCRCHi[buf];
    mCrcLo = gCRCLo[buf];
}

void MODBUS::calculateCrc(void *src, unsigned short size)
{
    unsigned char *buf = (unsigned char *)src;

    for (unsigned short i = 0; i < size; i++)
    {
        calculateCrc(*buf++);
    }
}

void MODBUS::resetCrc(void)
{
    mCrcLo = 0xFF;
    mCrcHi = 0xFF;
}

void MODBUS::responseReadInputRegister(unsigned short addr, unsigned short size)
{
    if (size > 127)
        size = 127;
    else if (size + addr > mMemoryDepth)
        size = mMemoryDepth - addr;

    size *= 2;

    unsigned char sendBuf[3] = {mId, READ_INPUT_REGISTER, (unsigned char)(size)};

    resetCrc();
    calculateCrc(sendBuf, sizeof(sendBuf));

    if (setTx)
        setTx();

    mPeri->send(sendBuf, sizeof(sendBuf));

    lock();
    calculateCrc(&mMemory[addr], size);
    mPeri->send(&mMemory[addr], size);
    unlock();

    sendBuf[0] = mCrcHi;
    sendBuf[1] = mCrcLo;

    mPeri->send(sendBuf, 2);
}

void MODBUS::responseWriteSingleRegister(unsigned short addr)
{
    unsigned char sendBuf[6] = {mId, WRITE_SINGLE_REGISTER, (unsigned char)(addr >> 8), (unsigned char)(addr), (unsigned char)(mRcvBuf[0] >> 8), (unsigned char)mRcvBuf[0]};

    resetCrc();
    calculateCrc(sendBuf, sizeof(sendBuf));

    if (setTx)
        setTx();

    mPeri->send(sendBuf, sizeof(sendBuf));

    sendBuf[0] = mCrcHi;
    sendBuf[1] = mCrcLo;

    mPeri->send(sendBuf, 2);
}

void MODBUS::responseWriteMultiRegister(unsigned short addr, unsigned short size)
{
    unsigned char sendBuf[6] = {mId, WRITE_MULTI_REGISTER, (unsigned char)(addr >> 8), (unsigned char)(addr), (unsigned char)(size >> 8), (unsigned char)size};

    resetCrc();
    calculateCrc(sendBuf, sizeof(sendBuf));

    if (setTx)
        setTx();

    mPeri->send(sendBuf, sizeof(sendBuf));

    sendBuf[0] = mCrcHi;
    sendBuf[1] = mCrcLo;

    mPeri->send(sendBuf, 2);
}

void MODBUS::process(void)
{
    unsigned char data, func, count;
    unsigned short addr, size, crc;

    while (1)
    {
    start:
        if (setRx)
            setRx();

        resetCrc();

        data = mPeri->getWaitUntilReceive();
        if (data != mId)
            goto start;
        calculateCrc(data);

        func = mPeri->getWaitUntilReceive();
        if (!(func == READ_INPUT_REGISTER || func == WRITE_SINGLE_REGISTER || func == WRITE_MULTI_REGISTER))
            goto start;
        calculateCrc(func);

        data = mPeri->getWaitUntilReceive();
        calculateCrc(data);
        addr = (unsigned short)data << 8;

        data = mPeri->getWaitUntilReceive();
        calculateCrc(data);
        addr |= (unsigned short)data;

        if (func == READ_INPUT_REGISTER || func == WRITE_MULTI_REGISTER)
        {
            data = mPeri->getWaitUntilReceive();
            calculateCrc(data);
            size = (unsigned short)data << 8;

            data = mPeri->getWaitUntilReceive();
            calculateCrc(data);
            size |= (unsigned short)data;
        }
        else if (func == WRITE_SINGLE_REGISTER)
        {
            data = mPeri->getWaitUntilReceive();
            calculateCrc(data);
            mRcvBuf[0] = (unsigned short)data << 8;

            data = mPeri->getWaitUntilReceive();
            calculateCrc(data);
            mRcvBuf[0] |= (unsigned short)data;
        }

        if (func == WRITE_MULTI_REGISTER)
        {
            count = mPeri->getWaitUntilReceive();
            calculateCrc(count);

            if (size != count)
                size = count / 2;

            for (unsigned short i = 0; i < size; i++)
            {
                data = mPeri->getWaitUntilReceive();
                calculateCrc(data);
                mRcvBuf[i] = (unsigned short)data << 8;

                data = mPeri->getWaitUntilReceive();
                calculateCrc(data);
                mRcvBuf[i] |= (unsigned short)data;
            }
        }

        data = mPeri->getWaitUntilReceive();
        if (data != mCrcHi)
            goto start;

        data = mPeri->getWaitUntilReceive();
        if (data != mCrcLo)
            goto start;

        mReceiveFlag = true;

        switch (func)
        {
        case READ_INPUT_REGISTER:
            responseReadInputRegister(addr, size);
            mSendFlag = true;
            break;
        case WRITE_SINGLE_REGISTER:
            if (rcvHandler)
                rcvHandler(addr, mRcvBuf[0]);
            responseWriteSingleRegister(addr);
            mSendFlag = true;
            break;
        case WRITE_MULTI_REGISTER:
            for (unsigned short i = 0; i < size; i++)
            {
                if (rcvHandler)
                    rcvHandler(addr+i, mRcvBuf[i]);
            }
            responseWriteMultiRegister(addr, size);
            mSendFlag = true;
            break;
        }
    }
}

union Swap
{
    unsigned char byte[2];
    signed short halfword;
};

void MODBUS::setData(unsigned short addr, signed short data)
{
    Swap swap1, swap2;
    swap1.halfword = data;
    swap2.byte[0] = swap1.byte[1];
    swap2.byte[1] = swap1.byte[0];

    lock();
    if (addr < mMemoryDepth)
        mMemory[addr] = swap2.halfword;
    unlock();
}

signed short MODBUS::getData(unsigned short addr)
{
    Swap swap1, swap2;
    signed short data;

    lock();
    if (addr < mMemoryDepth)
        data = mMemory[addr];
    else
        data = 0;
    unlock();

    swap1.halfword = data;
    swap2.byte[0] = swap1.byte[1];
    swap2.byte[1] = swap1.byte[0];

    return swap2.halfword;
}

bool MODBUS::isReceived(void)
{
    bool data = mReceiveFlag;
    mReceiveFlag = false;
    return data;
}

bool MODBUS::isSent(void)
{
    bool data = mSendFlag;
    mSendFlag = false;
    return data;
}

static void thread_handleModbus(void *var)
{
    MODBUS *modbus = (MODBUS *)var;
    modbus->process();
}

const unsigned char gCRCHi[256] = {
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
    0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
    0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81,
    0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
    0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
    0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
    0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
    0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
    0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
    0x40};

const unsigned char gCRCLo[256] = {
    0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7, 0x05, 0xC5, 0xC4,
    0x04, 0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
    0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F, 0xDD,
    0x1D, 0x1C, 0xDC, 0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
    0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32, 0x36, 0xF6, 0xF7,
    0x37, 0xF5, 0x35, 0x34, 0xF4, 0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
    0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA, 0xEE,
    0x2E, 0x2F, 0xEF, 0x2D, 0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
    0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 0x61, 0xA1, 0x63, 0xA3, 0xA2,
    0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
    0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 0x78, 0xB8, 0xB9, 0x79, 0xBB,
    0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
    0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0, 0x50, 0x90, 0x91,
    0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
    0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98, 0x88,
    0x48, 0x49, 0x89, 0x4B, 0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
    0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83, 0x41, 0x81, 0x80,
    0x40};
}
}