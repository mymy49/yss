////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 소스 코드 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(STM32F4) || defined(STM32F1) || defined(STM32F7)

#include <drv/Can.h>
#include <drv/can/register_can_stm32f1_4_7.h>
#include <yss/thread.h>
#include <yss/malloc.h>

Can::Can(YSS_CAN_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void), unsigned int (*getClockFreq)(void)) : Drv(clockFunc, nvicFunc, resetFunc)
{
	mPeri = peri;
	mGetClockFreq = getClockFreq;
	mHead = 0;
	mTail = 0;
	mMaxDepth = 0;
}

bool Can::init(unsigned int baudRate, unsigned int bufDepth, float samplePoint)
{
	unsigned int clk = mGetClockFreq(), ts1, ts2, pres;

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
		thread::yield();

	//		mPeri->BTR |= (1 << CAN_BTR_SILM_Pos) | (1 << CAN_BTR_LBKM_Pos);

	setCanNoAutoRetransmission(mPeri, true);
	//		setCanAutoWakeupMode(mPeri, true);
	//		setCanAutoBusoff(mPeri, true);

	setCanBaudratePrescaler(mPeri, pres);
	setCanTimeSegment1(mPeri, ts1);
	setCanTimeSegment2(mPeri, ts2);
	setCanResyncJumpWidth(mPeri, 0);
	mPeri->MCR |= CAN_MCR_AWUM_Msk;
	mPeri->FMR &= ~CAN_FMR_FINIT;

	setCanFifoPending0IntEn(mPeri, true);

	if (mMaxDepth != bufDepth)
	{
		if (mCanFrame)
			delete mCanFrame;
		mCanFrame = new CanFrame[bufDepth];
	}

	if (mCanFrame == 0)
	{
		return false;
	}

	mMaxDepth = bufDepth;
	mHead = 0;
	mTail = 0;

	setCanModeRequest(mPeri, CAN_MODE_NORMAL);

	// 버스 OFF 자동 복구 기능 활성화
	mPeri->MCR |= CAN_MCR_ABOM_Msk;

	return true;
error:
	return false;
}

bool Can::disableFilter(unsigned char index)
{
	if(index > 27)
		return false;

	mPeri->FMR |= CAN_FMR_FINIT;
	mPeri->FA1R &= ~(1 << index);
	mPeri->FMR &= ~CAN_FMR_FINIT;
	
	return true;
}

bool Can::setStandardMaskFilter(unsigned char index, unsigned short id, unsigned short mask)
{
	if(index > 27)
		return false;
	
	id &= 0x7FF;
	mask &= 0x7FF;

	mPeri->FMR |= CAN_FMR_FINIT;

	mPeri->sFilterRegister[index].FR1 = id << 21;
	mPeri->sFilterRegister[index].FR2 = mask << 21;
	mPeri->FM1R &= ~(1 << index);
	mPeri->FS1R |= 1 << index;
	mPeri->FA1R |= 1 << index;

	mPeri->FMR &= ~CAN_FMR_FINIT;

	return true;
}

bool Can::setExtendedMaskFilter(unsigned char index, unsigned int id, unsigned int mask)
{
	if(index > 27)
		return false;
	
	id &= 0x1FFFFFFF;
	mask &= 0x1FFFFFFF;

	mPeri->FMR |= CAN_FMR_FINIT;

	mPeri->sFilterRegister[index].FR1 = id << 3;
	mPeri->sFilterRegister[index].FR2 = mask << 3;
	mPeri->FM1R &= ~(1 << index);
	mPeri->FS1R |= 1 << index;
	mPeri->FA1R |= 1 << index;

	mPeri->FMR &= ~CAN_FMR_FINIT;

	return true;
}

bool Can::setStandardMatchFilter(unsigned char index, unsigned short id)
{
	if(index > 27)
		return false;
	
	id &= 0x7FF;

	mPeri->FMR |= CAN_FMR_FINIT;

	mPeri->sFilterRegister[index].FR1 = 0x0;
	mPeri->sFilterRegister[index].FR2 = id << 21;
	mPeri->FM1R |= 1 << index;
	mPeri->FS1R |= 1 << index;
	mPeri->FA1R |= 1 << index;

	mPeri->FMR &= ~CAN_FMR_FINIT;

	return true;
}

bool Can::setExtendedMatchFilter(unsigned char index, unsigned int id)
{
	if(index > 27)
		return false;
	
	id &= 0x1FFFFFFF;

	mPeri->FMR |= CAN_FMR_FINIT;

	mPeri->sFilterRegister[index].FR1 = 0x0;
	mPeri->sFilterRegister[index].FR2 = id << 3;
	mPeri->FM1R |= 1 << index;
	mPeri->FS1R |= 1 << index;
	mPeri->FA1R |= 1 << index;

	mPeri->FMR &= ~CAN_FMR_FINIT;

	return true;
}

bool Can::send(CanFrame packet)
{
	unsigned int *src = (unsigned int*)&packet;
	src[0] |= 0x01;

	if(packet.extension == 0)
		packet.id <<= 18;
	
	while(!(mPeri->TSR & CAN_TSR_TME0_Msk))
		thread::yield();
	
	mPeri->sTxMailBox[0].TDHR = src[3];
	mPeri->sTxMailBox[0].TDLR = src[2];
	mPeri->sTxMailBox[0].TDTR = src[1];
	mPeri->sTxMailBox[0].TIR = src[0];

	return true;
}

unsigned char Can::getSendErrorCount(void)
{
	return (mPeri->ESR >> CAN_ESR_REC_Pos);
}

unsigned char Can::getReceiveErrorCount(void)
{
	return (mPeri->ESR >> CAN_ESR_TEC_Pos);
}

J1939Frame Can::generateJ1939FrameBuffer(unsigned char priority, unsigned short pgn, unsigned short sa, unsigned char count)
{
	J1939Frame buf = {0, 0, true, sa, pgn, 0, 0, priority, count, 0, 0,};
	return buf;
}

void Can::isr(void)
{
	while(mPeri->IER & CAN_IER_FMPIE0_Msk && mPeri->RF0R & CAN_RF0R_FMP0_Msk)
	{
		setCanFifoPending0IntEn(CAN1, false);
		push((CanFrame*)&mPeri->sFIFOMailBox[0].RIR);
		releaseFifo0MailBox(mPeri);
		setCanFifoPending0IntEn(mPeri, true);
	}
}

#endif