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
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/mcu.h>

#if defined(STM32F4) || defined(STM32F1) || defined(STM32F7)

#include <__cross_studio_io.h>

#include <drv/drv_Can.h>
#include <drv/can/drv_st_can_type_A_register.h>
#include <yss/malloc.h>

namespace drv
{
Can::Can(CAN_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), unsigned int (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
    mPeri = peri;
    mGetClockFreq = getClockFreq;
    mHead = 0;
    mTail = 0;
    mData = 0;
    mMaxDepth = 0;
}

bool Can::init(unsigned int baudRate, unsigned int bufDepth, float samplePoint)
{
    unsigned int clk = mGetClockFreq(), ts1, ts2, pres;

#if defined(YSS_PERI_REPORT)
    debug_printf("\n########## CAN 장치 설정 ##########\n\n");
    debug_printf("CAN 장치 클럭 = %d MHz\n", clk / 1000000);
#endif
    clk /= baudRate;

    ts1 = (unsigned int)((float)clk * samplePoint);
    ts2 = clk - ts1;
    for (pres = ts2; pres > 0; pres--)
        if (((ts1 % pres) == 0) && ((ts2 % pres) == 0))
            break;

    ts1 -= pres;
    ts1 /= pres;
    ts2 /= pres;

    if (pres > 1 && pres <= 1024)
        pres--;
    else
        goto retry1;

    if (ts1 > 0 && ts1 <= 16)
        ts1--;
    else
        goto retry1;

    if (ts2 > 0 && ts2 <= 8)
        ts2--;
    else
        goto retry1;

    goto next;
retry1:

    ts1 = (unsigned int)((float)clk * samplePoint);
    ts1++;

    ts2 = clk - ts1;
    for (pres = ts2; pres > 0; pres--)
        if (((ts1 % pres) == 0) && ((ts2 % pres) == 0))
            break;

    ts1 -= pres;
    ts1 /= pres;
    ts2 /= pres;

    if (pres > 1 && pres <= 1024)
        pres--;
    else
        goto retry2;

    if (ts1 > 0 && ts1 <= 16)
        ts1--;
    else
        goto retry2;

    if (ts2 > 0 && ts2 <= 8)
        ts2--;
    else
        goto retry2;

    goto next;
retry2:
    ts1 = (unsigned int)((float)clk * samplePoint);
    ts1--;

    ts2 = clk - ts1;
    for (pres = ts2; pres > 0; pres--)
        if (((ts1 % pres) == 0) && ((ts2 % pres) == 0))
            break;

    ts1 -= pres;
    ts1 /= pres;
    ts2 /= pres;

    if (pres > 1 && pres <= 1024)
        pres--;
    else
        return false;

    if (ts1 > 0 && ts1 <= 16)
        ts1--;
    else
        return false;

    if (ts2 > 0 && ts2 <= 8)
        ts2--;
    else
        return false;

next:
    setCanModeRequest(mPeri, CAN_MODE_INIT);
    while (getCanInitModeStatus(mPeri) == false)
        thread::switchContext();

    //		mPeri->BTR |= (1 << CAN_BTR_SILM_Pos) | (1 << CAN_BTR_LBKM_Pos);

    setCanNoAutoRetransmission(mPeri, true);
    //		setCanAutoWakeupMode(mPeri, true);
    //		setCanAutoBusoff(mPeri, true);

    setCanBaudratePrescaler(mPeri, pres);
    setCanTimeSegment1(mPeri, ts1);
    setCanTimeSegment2(mPeri, ts2);
    setCanResyncJumpWidth(mPeri, 0);

    mPeri->sFilterRegister[0].FR1 = 0;
    mPeri->sFilterRegister[0].FR2 = 0;
    setCanFilterScaleConfig(mPeri, 0, 1);
    setCanFilterActive(mPeri, 0, 1);
    setCanActiveFilterMode(mPeri, false);

    setCanFifoPending0IntEn(mPeri, true);

    if (mMaxDepth != bufDepth)
    {
        if (mData)
#if YSS_L_HEAP_USE == true
            lfree(mData);
        mData = (unsigned int *)lmalloc(bufDepth * 16);
#else
            hfree(mData);
        mData = (unsigned int *)hmalloc(bufDepth * 16);
#endif
    }

    if (mData == 0)
    {
        return false;
    }

    mMaxDepth = bufDepth;
    mHead = 0;
    mTail = 0;

    setCanModeRequest(mPeri, CAN_MODE_NORMAL);
    while (getCanModeAck(mPeri))
        thread::switchContext();

#if defined(YSS_PERI_REPORT)
    samplePoint = (float)(ts1 + 2);
    samplePoint /= (float)(ts1 + 3 + ts2);

    debug_printf("Buad Rate = %d kbps\n", baudRate / 1000);
    debug_printf("Sample Point = %.3f %\n", samplePoint);
    debug_printf("장치 설정 완료.\n");
#endif

    return true;
error:
#if defined(YSS_PERI_REPORT)
    debug_printf("오류! 적절한 sample point 계산에 실패하였습니다.\n sample point를 조절하여 다시 시도해 주세요.\n");
#endif
    return false;
}

void Can::push(unsigned int rixr, unsigned int rdtxr, unsigned int rdlxr, unsigned int rdhxr)
{
    unsigned int offset = mHead++ * 4;

    mData[offset++] = rixr;
    mData[offset++] = rdtxr;
    mData[offset++] = rdlxr;
    mData[offset++] = rdhxr;

    if (mHead >= mMaxDepth)
        mHead = 0;
}

bool Can::isReceived(void)
{
    bool rt;
    if (mHead != mTail)
        rt = true;
    else
        rt = false;
    return rt;
}

bool Can::isStandard(void)
{
    unsigned int offset = mTail * 4;

    if (mData[offset] & 0x00000004)
        return false;
    else
        return true;
}

unsigned int Can::getIdentifier(void)
{
    unsigned int offset = mTail * 4;
    unsigned int rt;
    rt = mData[offset] >> 21;
    return rt;
}

unsigned char Can::getPriority(void)
{
    unsigned int offset = mTail * 4;
    unsigned int rt;
    rt = mData[offset] >> 29;
    return (unsigned char)rt;
}

unsigned short Can::getPgn(void)
{
    unsigned int offset = mTail * 4;
    unsigned int rt;
    rt = mData[offset] >> 11;
    return (unsigned short)(rt & 0xffff);
}

unsigned char Can::getSrcAddr(void)
{
    unsigned int offset = mTail * 4;
    unsigned int rt;
    rt = mData[offset] >> 3;
    return (unsigned short)(rt & 0xff);
}

void Can::releaseFifo(void)
{
    mTail++;
    if (mTail >= mMaxDepth)
        mTail = 0;
}

char *Can::getData(void)
{
    unsigned int offset = mTail * 4 + 2;
    return (char *)&mData[offset];
}

unsigned char Can::getSize(void)
{
    unsigned int offset = mTail * 4 + 1;
    return (unsigned char)mData[offset] & 0x0f;
}

bool Can::send(unsigned char priority, unsigned short pgn, unsigned char srcAddr, void *data, unsigned char size)
{
    unsigned int tir = 5, tdlr, tdhr;
    char *src = (char *)data;
    tir |= (priority & 0x7) << 29;
    tir |= pgn << 11;
    tir |= srcAddr << 3;

    tdlr = src[0];
    tdlr |= src[1] << 8;
    tdlr |= src[2] << 16;
    tdlr |= src[3] << 24;

    tdhr = src[4];
    tdhr |= src[5] << 8;
    tdhr |= src[6] << 16;
    tdhr |= src[7] << 24;

retry:
    if (getCanTransmitEmpty0(mPeri))
    {
        setCanTxHighRegister(mPeri->sTxMailBox[0], tdhr);
        setCanTxLowRegister(mPeri->sTxMailBox[0], tdlr);
        setCanTxLengthRegister(mPeri->sTxMailBox[0], size);
        setCanTxIdentifierRegister(mPeri->sTxMailBox[0], tir);
    }
    else if (getCanTransmitEmpty1(mPeri))
    {
        setCanTxHighRegister(mPeri->sTxMailBox[1], tdhr);
        setCanTxLowRegister(mPeri->sTxMailBox[1], tdlr);
        setCanTxLengthRegister(mPeri->sTxMailBox[1], size);
        setCanTxIdentifierRegister(mPeri->sTxMailBox[1], tir);
    }
    else if (getCanTransmitEmpty2(mPeri))
    {
        setCanTxHighRegister(mPeri->sTxMailBox[2], tdhr);
        setCanTxLowRegister(mPeri->sTxMailBox[2], tdlr);
        setCanTxLengthRegister(mPeri->sTxMailBox[2], size);
        setCanTxIdentifierRegister(mPeri->sTxMailBox[2], tir);
    }
    else
    {
        thread::switchContext();
        goto retry;
    }

    return true;
}

bool Can::send(unsigned short id, void *data, unsigned char size)
{
    char *src = (char *)data;
    unsigned int tir = 1, tdlr, tdhr;
    tir |= id << 21;

    tdlr = src[0];
    tdlr |= src[1] << 8;
    tdlr |= src[2] << 16;
    tdlr |= src[3] << 24;

    tdhr = src[4];
    tdhr |= src[5] << 8;
    tdhr |= src[6] << 16;
    tdhr |= src[7] << 24;

retry:
    if (getCanTransmitEmpty0(mPeri))
    {
        setCanTxHighRegister(mPeri->sTxMailBox[0], tdhr);
        setCanTxLowRegister(mPeri->sTxMailBox[0], tdlr);
        setCanTxLengthRegister(mPeri->sTxMailBox[0], size);
        setCanTxIdentifierRegister(mPeri->sTxMailBox[0], tir);
    }
    else if (getCanTransmitEmpty1(mPeri))
    {
        setCanTxHighRegister(mPeri->sTxMailBox[1], tdhr);
        setCanTxLowRegister(mPeri->sTxMailBox[1], tdlr);
        setCanTxLengthRegister(mPeri->sTxMailBox[1], size);
        setCanTxIdentifierRegister(mPeri->sTxMailBox[1], tir);
    }
    else if (getCanTransmitEmpty2(mPeri))
    {
        setCanTxHighRegister(mPeri->sTxMailBox[2], tdhr);
        setCanTxLowRegister(mPeri->sTxMailBox[2], tdlr);
        setCanTxLengthRegister(mPeri->sTxMailBox[2], size);
        setCanTxIdentifierRegister(mPeri->sTxMailBox[2], tir);
    }
    else
    {
        goto retry;
    }

    return true;
}

void Can::flush(void)
{
    mTail = mHead = 0;
}

void Can::isr(void)
{
    setCanFifoPending0IntEn(CAN1, false);
    push(mPeri->sFIFOMailBox[0].RIR, mPeri->sFIFOMailBox[0].RDTR, mPeri->sFIFOMailBox[0].RDLR, mPeri->sFIFOMailBox[0].RDHR);
    releaseFifo0MailBox(mPeri);
    setCanFifoPending0IntEn(mPeri, true);
}
}

#endif