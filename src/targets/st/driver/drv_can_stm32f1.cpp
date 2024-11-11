/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F7) || defined(STM32F4)

#include <drv/Can.h>
#include <yss/thread.h>
#include <std_ext/malloc.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

#define CAN_MODE_SLEEP		0x02
#define CAN_MODE_INIT		0x01
#define CAN_MODE_NORMAL		0X00

Can::Can(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mHead = 0;
	mTail = 0;
	mRxBufferDepth = 0;
}

error_t Can::initialize(config_t config)
{
	uint32_t clk = getClockFrequency(), ts1, ts2, pres;
	
	// Baudrate 계산
	clk /= config.baudrate;

	for(uint32_t i=0;i<4;i++)
	{
		ts1 = (uint32_t)((float)clk * config.samplePoint);
		ts2 = clk - ts1;

		switch(i)
		{
		case 0 :
			break;
		
		case 1 :
			ts1++;
			break;

		case 2 :
			ts1--;
			break;
		
		case 3 :
			return error_t::WRONG_CONFIG;
		}

		for (pres = ts2; pres > 0; pres--)
			if (((ts1 % pres) == 0) && ((ts2 % pres) == 0))
				break;

		ts1 = (ts1 - pres) / pres;
		ts2 /= pres;

		if (pres > 1 && pres <= 1024)
			pres--;
		else
			continue;

		if (0 < ts1 && ts1 <= 16)
			ts1--;
		else
			continue;

		if (0 < ts2 && ts2 <= 8)
			ts2--;
		else
			continue;

		break;		
	}

	setFieldData(mDev->MCR, CAN_MCR_INRQ_Msk | CAN_MCR_SLEEP_Msk, CAN_MODE_INIT, CAN_MCR_INRQ_Pos); // CAN init 모드 진입
	while (getFieldData(mDev->MSR, CAN_MCR_INRQ_Msk, CAN_MCR_INRQ_Pos) != CAN_MODE_INIT)
		thread::yield();
	
	setBitData(mDev->MCR, true, CAN_MCR_NART_Pos);
	setBitData(mDev->BTR, config.enableSilent, CAN_BTR_SILM_Pos); // Silent 통신 모드
	setBitData(mDev->BTR, config.enableLoopback, CAN_BTR_LBKM_Pos); // Loopback 통신 모드 
	
	// Baudrate 설정
	setThreeFieldData(mDev->BTR,	CAN_BTR_BRP_Msk, pres, CAN_BTR_BRP_Pos, 
									CAN_BTR_TS1_Msk, ts1, CAN_BTR_TS1_Pos, 
									CAN_BTR_TS2_Msk, ts2, CAN_BTR_TS2_Pos); 
	
	mDev->IER = CAN_IER_FMPIE0_Msk | 
				CAN_IER_SLKIE_Msk |
				CAN_IER_WKUIE_Msk |
				CAN_IER_ERRIE_Msk |
				CAN_IER_LECIE_Msk |
				CAN_IER_BOFIE_Msk |
				CAN_IER_EPVIE_Msk |
				CAN_IER_EWGIE_Msk |
				CAN_IER_FOVIE0_Msk;
			
	// 인터럽트 상태 레지스터 클리어		
	mDev->MSR = CAN_MSR_SLAKI_Msk | CAN_MSR_WKUI_Msk | CAN_MSR_ERRI_Msk;

	if (mRxBufferDepth != config.rxBufferDepth)
	{
		if (mCanFrame)
			delete mCanFrame;
		mCanFrame = new canFrame_t[config.rxBufferDepth];
	}

	if (mCanFrame == 0)
	{
		return error_t::MALLOC_FAILED;
	}

	mRxBufferDepth = config.rxBufferDepth;
	mHead = 0;
	mTail = 0;
	
	setBitData(mDev->MCR, true, CAN_MCR_ABOM_Pos); // Automatic bus-off recovery 활성화
	setFieldData(mDev->MCR, CAN_MCR_INRQ_Msk, CAN_MODE_NORMAL, CAN_MCR_INRQ_Pos); // CAN normal 모드 진입
	setFieldData(mDev->FMR, CAN_FMR_CAN2SB_Msk, 14, CAN_FMR_CAN2SB_Pos); // CAN normal 모드 진입

	return error_t::ERROR_NONE;
}

error_t Can::disableFilter(uint8_t index)
{
	if(index >= 28)
		return error_t::INDEX_OVER;
	
	setBitData(CAN1->FMR, true, 0);	// Filter Lock 비활성화
	setBitData(CAN1->FA1R, false, index);	// Filter 비활성화
	setBitData(CAN1->FMR, false, 0);	// Filter Lock 활성화
	
	return error_t::ERROR_NONE;
}

error_t Can::setStdMaskFilter(uint8_t index, uint16_t id, uint16_t mask)
{
	if(index >= 28)
		return error_t::INDEX_OVER;

	setBitData(CAN1->FMR, true, 0);	// Filter Lock 비활성화
	
	CAN1->sFilterRegister[index].FR1 = (id & 0x7FF) << 21;
	CAN1->sFilterRegister[index].FR2 = (mask & 0x7FF) << 21;

	setBitData(CAN1->FM1R, false, index);	// Filter Mask Mode 설정
	setBitData(CAN1->FS1R, true, index);	// Filter width 32bit 설정
	setBitData(CAN1->FA1R, true, index);		// Filter 활성화

	setBitData(CAN1->FMR, false, 0);	// Filter Lock 활성화

	return error_t::ERROR_NONE;
}

error_t Can::setExtMaskFilter(uint8_t index, uint32_t id, uint32_t mask)
{
	if(index >= 28)
		return error_t::INDEX_OVER;

	setBitData(CAN1->FMR, true, 0);	// Filter Lock 비활성화

	CAN1->sFilterRegister[index].FR1 = (id & 0x1FFFFFFF) << 3;
	CAN1->sFilterRegister[index].FR2 = (mask & 0x1FFFFFFF) << 3;

	setBitData(CAN1->FM1R, false, index);	// Filter Mask Mode 설정
	setBitData(CAN1->FS1R, true, index);	// Filter width 32bit 설정
	setBitData(CAN1->FA1R, true, index);		// Filter 활성화

	setBitData(CAN1->FMR, false, 0);	// Filter Lock 활성화

	return error_t::ERROR_NONE;
}

error_t Can::setStdMatchFilter(uint8_t index, uint16_t id)
{
	if(index >= 28)
		return error_t::INDEX_OVER;

	setBitData(CAN1->FMR, true, 0);	// Filter Lock 비활성화

	CAN1->sFilterRegister[index].FR1 = 0X00;
	CAN1->sFilterRegister[index].FR2 = (id & 0x7FF) << 21;

	setBitData(CAN1->FM1R, true, index);	// Filter Mask Mode 설정
	setBitData(CAN1->FS1R, true, index);	// Filter width 32bit 설정
	setBitData(CAN1->FA1R, true, index);		// Filter 활성화

	setBitData(CAN1->FMR, false, 0);	// Filter Lock 활성화

	return error_t::ERROR_NONE;
}

error_t Can::setExtMatchFilter(uint8_t index, uint32_t id)
{
	if(index >= 28)

	setBitData(CAN1->FMR, true, 0);	// Filter Lock 비활성화
	
	CAN1->sFilterRegister[index].FR1 = 0x00;
	setFieldData(CAN1->sFilterRegister[index].FR2, 0x1FFFFFFF << 3, id, 3);

	setBitData(CAN1->FM1R, true, index);	// Filter Mask Mode 설정
	setBitData(CAN1->FS1R, true, index);	// Filter width 32bit 설정
	setBitData(CAN1->FA1R, true, index);	// Filter 활성화

	setBitData(CAN1->FMR, false, 0);		// Filter Lock 활성화

	return error_t::ERROR_NONE;
}

error_t Can::send(canFrame_t packet)
{
	uint32_t *des = (uint32_t*)&mDev->sTxMailBox[0].TDHR;
	uint32_t *src = (uint32_t*)&packet;
	src[0] |= CAN_TI0R_TXRQ_Msk; // 송신 요청 비트 세트
	
	// 패킷이 CAN 확장 패킷이면 id의 위치를 재조정
	if(packet.extension == 0)
		packet.id <<= 18;
	
	// 송신 레지스터가 비워질 때까지 대기	
	while (~mDev->TSR & CAN_TSR_TME0_Msk)
		thread::yield();

	// mailbox 0의 송신 레지스터에 데이터를 채우고 데이터 송신
	src = &src[3];
	*des-- = *src--;
	*des-- = *src--;
	*des-- = *src--;
	*des-- = *src--; // 이 시점에 송신 가능 상태가 되고 버스가 준비되면 전송이 시작됨

	return error_t::ERROR_NONE;
}

uint8_t Can::getTxErrorCount(void)
{
	return (mDev->ESR >> 16);
}

uint8_t Can::getRxErrorCount(void)
{
	return (mDev->ESR >> 24);
}

void Can::isrRx(void)
{
	uint32_t *src = (uint32_t*)&mDev->sFIFOMailBox[0];

	setBitData(mDev->IER, false, 1); // Fifo0 Pending Interrupt Disable
	push((canFrame_t*)src);
	setBitData(mDev->RF0R, true, 5); // Receive FIFO0 dequeue
	setBitData(mDev->IER, true, 1); // Fifo0 Pending Interrupt Enable
}

void Can::isrEvent(void)
{
	uint32_t sr = mDev->MSR;

	if(sr)
	{
		if(sr & CAN_MSR_SLAKI_Msk)
		{
			if(mIsrForEvent)
				mIsrForEvent(error_t::SLEEP_ACK_INTERRUPT);
			mDev->MSR = CAN_MSR_SLAKI_Msk;
		}
		
		if(sr & CAN_MSR_WKUI_Msk)
		{
			if(mIsrForEvent)
				mIsrForEvent(error_t::WAKEUP_INTERRUPT);
			mDev->MSR = CAN_MSR_WKUI_Msk;
		}

		if(sr & CAN_MSR_ERRI_Msk)
		{
			if(mIsrForEvent)
				mIsrForEvent(error_t::ERROR_INTERRUP);
			mDev->MSR = CAN_MSR_ERRI_Msk;
		}
	}
}

#endif