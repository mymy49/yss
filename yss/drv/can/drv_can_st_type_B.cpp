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
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if defined(STM32G431xx) || defined(STM32G441xx) || \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)

#include <__cross_studio_io.h>

#include <config.h>
#include <drv/can/drv_st_can_type_A_register.h>
#include <drv/peripherals.h>
#include <string.h>
#include <yss/malloc.h>

static unsigned int getClockFreq(void)
{
    return clock.peripheral.getCan1ClkFreq();
}

//********** can1 구성 설정 및 변수 선언 **********
#if defined(CAN1_ENABLE) && defined(FDCAN1)

static void setCan1ClockEn(bool en)
{
    clock.peripheral.setCan1En(en);
}

static void setCan1IntEn(bool en)
{
    nvic.setCan1En(en);
}

drv::Can can1(FDCAN1, setCan1ClockEn, setCan1IntEn, getClockFreq);

extern "C"
{
    void FDCAN1_IT0_IRQHandler(void)
    {
        can1.isr();
    }
}

#endif

//********** can2 구성 설정 및 변수 선언 **********
#if defined(CAN2_ENABLE) && defined(FDCAN2)

static void setCan2ClockEn(bool en)
{
    clock.peripheral.setCan2En(en);
}

static void setCan2IntEn(bool en)
{
    nvic.setCan2En(en);
}

drv::Can can2(CAN2, setCan2ClockEn, setCan2IntEn, getClockFreq);

extern "C"
{
    void CAN2_RX0_IRQHandler(void)
    {
        can2.push(CAN2->sFIFOMailBox[0].RIR, CAN2->sFIFOMailBox[0].RDTR, CAN2->sFIFOMailBox[0].RDLR, CAN2->sFIFOMailBox[0].RDHR);
        releaseFifo0MailBox(CAN2);
    }
}
#endif

namespace drv
{
inline void setStdFilter(void *des, unsigned char type, unsigned char config, unsigned short id1, unsigned short id2)
{
    *(unsigned int *)des = (type & 0x3) << 30 | (config & 0x7) << 27 | (id1 & 0x3FF) << 16 | (id2 & 0x3FF);
}

Can::Can(FDCAN_GlobalTypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), unsigned int (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc)
{
    unsigned int sa = (unsigned int)peri;

    mPeri = peri;
    mGetClockFreq = getClockFreq;
    mHead = 0;
    mTail = 0;
    mData = 0;
    mMaxDepth = 0;
    mTxFifoIndex = 0;
    mRxFifoIndex0 = 0;

    sa += 0x4000;
    mCanStdFilter = (unsigned int *)(sa + 0x000);
    mCanExtFilter = (unsigned int *)(sa + 0x070);
    mCanRxFifo0 = (unsigned int *)(sa + 0x0B0);
    mCanRxFifo1 = (unsigned int *)(sa + 0x188);
    mCanTxEventFifo = (unsigned int *)(sa + 0x260);
    mCanTxBuffer = (unsigned int *)(sa + 0x278);

    mRxFifo0[0] = (unsigned int *)((unsigned int)mPeri + 0x40B0 + 0x00);
    mRxFifo0[1] = (unsigned int *)((unsigned int)mPeri + 0x40B0 + 0x48);
    mRxFifo0[2], (unsigned int *)((unsigned int)mPeri + 0x40B0 + 0x90);

    mTxbuf[0] = (unsigned int *)((unsigned int)mPeri + 0x4278 + 0x00);
    mTxbuf[1] = (unsigned int *)((unsigned int)mPeri + 0x4278 + 0x48);
    mTxbuf[2] = (unsigned int *)((unsigned int)mPeri + 0x4278 + 0x90);
}

bool Can::init(unsigned int baudRate, unsigned int bufDepth, float samplePoint)
{
    unsigned int clk = mGetClockFreq(), ts1, ts2, pres;

#if defined(YSS_PERI_REPORT)
    debug_printf("\n########## CAN 장치 설정 ##########\n\n");
    debug_printf("CAN 장치 클럭 = %d kHz\n", clk / 1000);
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

    if (pres > 1 && pres <= 32)
        pres--;
    else
        goto retry1;

    if (ts1 > 0 && ts1 <= 32)
        ts1--;
    else
        goto retry1;

    if (ts2 > 0 && ts2 <= 16)
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

    if (pres > 1 && pres <= 32)
        pres--;
    else
        goto retry2;

    if (ts1 > 0 && ts1 <= 32)
        ts1--;
    else
        goto retry2;

    if (ts2 > 0 && ts2 <= 16)
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

    if (pres > 1 && pres <= 32)
        pres--;
    else
        goto error;

    if (ts1 > 0 && ts1 <= 32)
        ts1--;
    else
        goto error;

    if (ts2 > 0 && ts2 <= 16)
        ts2--;
    else
        goto error;

next:
    mPeri->CCCR = FDCAN_CCCR_CCE_Msk | FDCAN_CCCR_INIT_Msk;
    mPeri->CCCR = FDCAN_CCCR_PXHD_Msk | FDCAN_CCCR_DAR_Msk | FDCAN_CCCR_CCE_Msk | FDCAN_CCCR_INIT_Msk;
    mPeri->DBTP = pres << FDCAN_DBTP_DBRP_Pos | ts1 << FDCAN_DBTP_DTSEG1_Pos | ts2 << FDCAN_DBTP_DTSEG2_Pos | ts2 << FDCAN_DBTP_DSJW_Pos;
    mPeri->NBTP = pres << FDCAN_NBTP_NBRP_Pos | ts1 << FDCAN_NBTP_NTSEG1_Pos | ts2 << FDCAN_NBTP_NTSEG2_Pos | ts2 << FDCAN_NBTP_NSJW_Pos;
    if (mMaxDepth != bufDepth)
    {
        if (mData)
#if YSS_L_HEAP_USE == true
            lfree(mData);
        mData = (unsigned int *)lmalloc(bufDepth * 16);
#elif YSS_C_HEAP_USE == true
            cfree(mData);
        mData = (unsigned int *)cmalloc(bufDepth * 16);
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

    memset(mCanStdFilter, 0x00, 1024);
    mPeri->RXGFC = 1 << FDCAN_RXGFC_LSS_Pos | 0 << FDCAN_RXGFC_ANFS_Pos | 0 << FDCAN_RXGFC_ANFE_Pos;

    mPeri->IE = FDCAN_IE_RF0NE_Msk | FDCAN_IE_RF1NE_Msk;
    mPeri->ILE = FDCAN_ILE_EINT0_Msk | FDCAN_ILE_EINT1_Msk;
    mPeri->CCCR &= ~FDCAN_CCCR_INIT_Msk;

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

void Can::push(unsigned int *data)
{
    unsigned int offset = mHead++ * 4;

    mData[offset++] = *data++;
    mData[offset++] = *data++;
    mData[offset++] = *data++;
    mData[offset++] = *data++;

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

    if (mData[offset] & 0x40000000)
        return false;
    else
        return true;
}

unsigned int Can::getIdentifier(void)
{
    unsigned int offset = mTail * 4;
    return (mData[offset] >> 18) & 0x7ff;
}

unsigned char Can::getPriority(void)
{
    unsigned int offset = mTail * 4;
    unsigned int rt;
    rt = mData[offset] >> 26;
    return (unsigned char)rt & 0x07;
}

unsigned short Can::getPgn(void)
{
    unsigned int offset = mTail * 4;
    unsigned int rt;
    rt = mData[offset] >> 8;
    return (unsigned short)(rt & 0xffff);
}

unsigned char Can::getSrcAddr(void)
{
    unsigned int offset = mTail * 4;
    return (unsigned short)(mData[offset] & 0xff);
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
    unsigned int sendBuf[4];
    unsigned int *des, *src = sendBuf;

    if (size > 8)
        size = 8;

    sendBuf[0] = (unsigned int)(priority & 0x07) << 26 | (unsigned int)(pgn & 0xffff) << 8 | srcAddr | 1 << 30;
    sendBuf[1] = size << 16;
    sendBuf[2] = ((unsigned int *)data)[0];
    sendBuf[3] = ((unsigned int *)data)[1];

    des = (unsigned int *)mTxbuf[0];
    *des++ = *src++;
    *des++ = *src++;
    *des++ = *src++;
    *des++ = *src++;

    mPeri->IR = FDCAN_IR_TFE_Msk;
    mPeri->TXBAR = 1;

    while (!(mPeri->IR & FDCAN_IR_TFE_Msk))
        thread::yield();

    return true;
}

bool Can::send(unsigned short id, void *data, unsigned char size)
{
    unsigned int sendBuf[4];
    unsigned int *des, *src = sendBuf;

    if (size > 8)
        size = 8;

    sendBuf[0] = (unsigned int)(id & 0x7ff) << 18;
    sendBuf[1] = size << 16;
    sendBuf[2] = ((unsigned int *)data)[0];
    sendBuf[3] = ((unsigned int *)data)[1];

    des = (unsigned int *)mTxbuf[0];
    *des++ = *src++;
    *des++ = *src++;
    *des++ = *src++;
    *des++ = *src++;

    mPeri->IR = FDCAN_IR_TFE_Msk;
    mPeri->TXBAR = 1;

    while (!(mPeri->IR & FDCAN_IR_TFE_Msk))
        thread::yield();

    return true;
}

void Can::flush(void)
{
    mTail = mHead = 0;
}

void Can::isr(void)
{
    if (mPeri->IE & FDCAN_IE_RF0NE_Msk && mPeri->IR & FDCAN_IR_RF0N_Msk)
    {
        push((unsigned int *)mRxFifo0[mRxFifoIndex0]);
        mPeri->RXF0A = mRxFifoIndex0++;
        if (mRxFifoIndex0 > 2)
            mRxFifoIndex0 = 0;
        FDCAN1->IR = FDCAN_IR_RF0N_Msk;
    }
}
}

#endif