////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2021.10.19 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <external/crc16.h>
#include <protocol/Dynamixel_V2.h>
#include <string.h>
#include <util/ElapsedTime.h>
#include <yss/thread.h>

static const unsigned short crc_table[256] = {
    0x0000, 0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011,
    0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027, 0x0022,
    0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D, 0x8077, 0x0072,
    0x0050, 0x8055, 0x805F, 0x005A, 0x804B, 0x004E, 0x0044, 0x8041,
    0x80C3, 0x00C6, 0x00CC, 0x80C9, 0x00D8, 0x80DD, 0x80D7, 0x00D2,
    0x00F0, 0x80F5, 0x80FF, 0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1,
    0x00A0, 0x80A5, 0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1,
    0x8093, 0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082,
    0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197, 0x0192,
    0x01B0, 0x81B5, 0x81BF, 0x01BA, 0x81AB, 0x01AE, 0x01A4, 0x81A1,
    0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB, 0x01FE, 0x01F4, 0x81F1,
    0x81D3, 0x01D6, 0x01DC, 0x81D9, 0x01C8, 0x81CD, 0x81C7, 0x01C2,
    0x0140, 0x8145, 0x814F, 0x014A, 0x815B, 0x015E, 0x0154, 0x8151,
    0x8173, 0x0176, 0x017C, 0x8179, 0x0168, 0x816D, 0x8167, 0x0162,
    0x8123, 0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132,
    0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104, 0x8101,
    0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D, 0x8317, 0x0312,
    0x0330, 0x8335, 0x833F, 0x033A, 0x832B, 0x032E, 0x0324, 0x8321,
    0x0360, 0x8365, 0x836F, 0x036A, 0x837B, 0x037E, 0x0374, 0x8371,
    0x8353, 0x0356, 0x035C, 0x8359, 0x0348, 0x834D, 0x8347, 0x0342,
    0x03C0, 0x83C5, 0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1,
    0x83F3, 0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2,
    0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7, 0x03B2,
    0x0390, 0x8395, 0x839F, 0x039A, 0x838B, 0x038E, 0x0384, 0x8381,
    0x0280, 0x8285, 0x828F, 0x028A, 0x829B, 0x029E, 0x0294, 0x8291,
    0x82B3, 0x02B6, 0x02BC, 0x82B9, 0x02A8, 0x82AD, 0x82A7, 0x02A2,
    0x82E3, 0x02E6, 0x02EC, 0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2,
    0x02D0, 0x82D5, 0x82DF, 0x02DA, 0x82CB, 0x02CE, 0x02C4, 0x82C1,
    0x8243, 0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252,
    0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264, 0x8261,
    0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E, 0x0234, 0x8231,
    0x8213, 0x0216, 0x021C, 0x8219, 0x0208, 0x820D, 0x8207, 0x0202};

namespace Instruction
{
enum
{
    NOP,
    PING,
    WRITE,
    REG_WRITE,
};
}

DynamixelV2::DynamixelV2(drv::Uart &uart)
{
    mUart = &uart;
    mHeader[0] = mHeader[1] = 0xFF;
    mHeader[2] = 0xFD;
    mHeader[3] = 0x00;

    mNumOfMotor = 0;
    memset(mIdList, 0x00, sizeof(mIdList));

    mPreCalculatedCrc = calculateCrc16(mHeader, 4, 0);
}

bool DynamixelV2::getByte(void)
{
    ElapsedTime timeout;
    signed short data;

    while (1)
    {
        if (timeout.getMsec() >= 500)
            return false;
        data = mUart->get();
        if (data >= 0)
        {
            mRcvByte = data;
            return true;
        }
        thread::yield();
    }
}

bool DynamixelV2::checkReceivedDataPatten(const char *patten, unsigned char len)
{
    for (int i = 0; i < len; i++)
    {
        if (getByte() == false)
            return false;

        if (mRcvByte != patten[i])
            return false;
    }

    return true;
}

bool DynamixelV2::init(void)
{
    unsigned short crc = mPreCalculatedCrc;
    char id, sendBuf[4] = {0xFE, 0x03, 0x00, Instruction::PING};
    unsigned char data;
    const char patten1[4] = {0xFF, 0xFF, 0xFD, 0x00};
    const char patten2[3] = {0x07, 0x00, 0x55};

    mUart->lock();
    mUart->flush();
    mUart->send(mHeader, sizeof(mHeader));
    crc = calculateCrc16(sendBuf, sizeof(sendBuf), crc);
    mUart->send(sendBuf, sizeof(sendBuf));
    mUart->send(&crc, sizeof(crc));

    if (checkReceivedDataPatten(patten1, 4) == false)
        goto error;
    crc = mPreCalculatedCrc;
    if (getByte() == false)
        goto error;
    id -= mRcvByte;

    if (checkReceivedDataPatten(patten2, 3) == false)
        goto error;
    crc = calculateCrc16(patten2, sizeof(patten2), crc);

    if (getByte() == false) // 에러 코드
        goto error;

    if (getByte() == false) // P1
        goto error;

    if (getByte() == false) // P2
        goto error;

    if (getByte() == false) // P3
        goto error;

error:
    mUart->unlock();
    return false;
}

DynamixelV2::~DynamixelV2(void)
{
}

unsigned short DynamixelV2::calculateCrc16(const void *buf, int len, unsigned short crc)
{
    unsigned short i;

    for (int j = 0; j < len; j++)
    {
        i = ((unsigned short)(crc >> 8) ^ ((char *)buf)[j]) & 0xFF;
        crc = (crc << 8) ^ crc_table[i];
    }

    return crc;
}