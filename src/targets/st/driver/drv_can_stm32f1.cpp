////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(GD32F1) || defined(STM32F1_N)

#include <drv/Can.h>
#include <yss/thread.h>
#include <std_ext/malloc.h>
#include <yss/reg.h>
#include <targets/st/bitfield_stm32f103xx.h>

#define CAN_MODE_SLEEP		0x02
#define CAN_MODE_INIT		0x01
#define CAN_MODE_NORMAL		0X00

Can::Can(const Drv::Setup drvSetup, const Setup setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mHead = 0;
	mTail = 0;
	mMaxDepth = 0;
}

bool Can::initialize(uint32_t baudRate, uint32_t bufDepth, float samplePoint)
{
	uint32_t clk = getClockFrequency(), ts1, ts2, pres;

	clk /= baudRate;

	ts1 = (uint32_t)((float)clk * samplePoint);
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

	ts1 = (uint32_t)((float)clk * samplePoint);
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
	ts1 = (uint32_t)((float)clk * samplePoint);
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
	setFieldData(mDev->MCR, 0x3 << 0, CAN_MODE_INIT, 0);	// CAN init 모드 진입
	while (getFieldData(mDev->MSR, 0x3, 0) != CAN_MODE_INIT)
		thread::yield();
	
	setBitData(mDev->MCR, true, 4);	// Auto retransmission Disable
	
	//setBitData(mDev->BTR, true, 31);	// Silent 통신 모드
	//setBitData(mDev->BTR, true, 30);	// Loopback 통신 모드 

	setThreeFieldData(mDev->BTR, 0x3FF << 0, pres, 0, 0xF << 16, ts1, 16, 0x7 << 20, ts2, 20); // Baudrate 설정
	
	setBitData(mDev->IER, true, 1); // Fifo0 Pending Interrupt Enable
	
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
	
	setBitData(mDev->MCR, true, 6);	// Automatic bus-off recovery 활성화
	setFieldData(mDev->MCR, 0x3 << 0, CAN_MODE_NORMAL, 0);	// CAN init 모드 진입

	return true;
error:
	return false;
}

bool Can::disableFilter(uint8_t index)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return false;
#else
	if(index >= 28)
		return false;
#endif /* GD32F10X_CL */  
	
	setBitData(mDev->FMR, true, 0);	// Filter Lock 비활성화
	setBitData(mDev->FA1R, false, index);	// Filter 비활성화
	setBitData(mDev->FMR, false, 0);	// Filter Lock 활성화
	
	return true;
}

bool Can::setStandardMaskFilter(uint8_t index, uint16_t id, uint16_t mask)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return false;
#else
	if(index >= 28)
		return false;
#endif /* GD32F10X_CL */  

	setBitData(mDev->FMR, true, 0);	// Filter Lock 비활성화
	
	uint32_t *reg = (uint32_t*)&mDev->sFilterRegister[index];
	*(reg) = (id & 0x7FF) << 21;
	*(reg+1) = (mask & 0x7FF) << 21;

	setBitData(mDev->FM1R, false, index);	// Filter Mask Mode 설정
	setBitData(mDev->FS1R, true, index);	// Filter width 32bit 설정
	setBitData(mDev->FA1R, true, index);		// Filter 활성화

	setBitData(mDev->FMR, false, 0);	// Filter Lock 활성화

	return true;
}

bool Can::setExtendedMaskFilter(uint8_t index, uint32_t id, uint32_t mask)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return false;
#else
	if(index >= 28)
		return false;
#endif /* GD32F10X_CL */  

	setBitData(mDev->FMR, true, 0);	// Filter Lock 비활성화

	uint32_t *reg = (uint32_t*)&mDev->sFilterRegister[index];
	*(reg) = (id & 0x1FFFFFFF) << 3;
	*(reg+1) = (mask & 0x1FFFFFFF) << 3;

	setBitData(mDev->FM1R, false, index);	// Filter Mask Mode 설정
	setBitData(mDev->FS1R, true, index);	// Filter width 32bit 설정
	setBitData(mDev->FA1R, true, index);		// Filter 활성화

	setBitData(mDev->FMR, false, 0);	// Filter Lock 활성화

	return true;
}

bool Can::setStandardMatchFilter(uint8_t index, uint16_t id)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return false;
#else
	if(index >= 28)
		return false;
#endif /* GD32F10X_CL */  

	setBitData(mDev->FMR, true, 0);	// Filter Lock 비활성화

	uint32_t *reg = (uint32_t*)&mDev->sFilterRegister[index];
	*(reg) = 0X00;
	*(reg+1) = (id & 0x7FF) << 21;

	setBitData(mDev->FM1R, true, index);	// Filter Mask Mode 설정
	setBitData(mDev->FS1R, true, index);	// Filter width 32bit 설정
	setBitData(mDev->FA1R, true, index);		// Filter 활성화

	setBitData(mDev->FMR, false, 0);	// Filter Lock 활성화

	return true;
}

bool Can::setExtendedMatchFilter(uint8_t index, uint32_t id)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return false;
#else
	if(index >= 28)
		return false;
#endif /* GD32F10X_CL */  

	setBitData(mDev->FMR, true, 0);	// Filter Lock 비활성화
	
	uint32_t *reg = (uint32_t*)&mDev->sFilterRegister[index];
	*(reg) = 0X00;
	setFieldData(*(reg+1), 0x1FFFFFFF << 3, id, 3);

	setBitData(mDev->FM1R, true, index);	// Filter Mask Mode 설정
	setBitData(mDev->FS1R, true, index);	// Filter width 32bit 설정
	setBitData(mDev->FA1R, true, index);	// Filter 활성화

	setBitData(mDev->FMR, false, 0);		// Filter Lock 활성화

	return true;
}

bool Can::send(CanFrame packet)
{
	uint32_t *des = (uint32_t*)&mDev->sTxMailBox[0].TDHR;
	uint32_t *src = (uint32_t*)&packet;
	src[0] |= 0x01;

	if(packet.extension == 0)
		packet.id <<= 18;

	src = &src[3];
	*des-- = *src--;
	*des-- = *src--;
	*des-- = *src--;
	*des-- = *src--;

	while (~mDev->TSR & CAN_TSR_TXOK0_Msk)
		thread::yield();

	mDev->TSR = CAN_TSR_TXOK0_Msk;

	return true;
}

uint8_t Can::getSendErrorCount(void)
{
	return (mDev->ESR >> 16);
}

uint8_t Can::getReceiveErrorCount(void)
{
	return (mDev->ESR >> 24);
}

J1939Frame Can::generateJ1939FrameBuffer(uint8_t priority, uint16_t pgn, uint8_t sa, uint8_t count)
{
	J1939Frame buf = {0, 0, true, sa, pgn, 0, 0, priority, count, 0, 0,};
	return buf;
}

void Can::isr(void)
{
	uint32_t *src = (uint32_t*)&mDev->sFIFOMailBox[0];

	setBitData(mDev->IER, false, 1); // Fifo0 Pending Interrupt Disable
	push((CanFrame*)src);
	setBitData(mDev->RF0R, true, 5); // Receive FIFO0 dequeue
	setBitData(mDev->IER, true, 1); // Fifo0 Pending Interrupt Enable
}

#endif