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
	mRxBufferDepth = 0;
}

error Can::initialize(Config_t config)
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
			return error::WRONG_CONFIG;
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

	setFieldData(mDev->MCR, CAN_MCR_INRQ_Msk, CAN_MODE_INIT, CAN_MCR_INRQ_Pos); // CAN init 모드 진입
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
		mCanFrame = new CanFrame[config.rxBufferDepth];
	}

	if (mCanFrame == 0)
	{
		return error::MALLOC_FAILED;
	}

	mRxBufferDepth = config.rxBufferDepth;
	mHead = 0;
	mTail = 0;
	
	setBitData(mDev->MCR, true, CAN_MCR_ABOM_Pos); // Automatic bus-off recovery 활성화
	setFieldData(mDev->MCR, CAN_MCR_INRQ_Msk, CAN_MODE_NORMAL, CAN_MCR_INRQ_Pos); // CAN normal 모드 진입

	return error::ERROR_NONE;
}

error Can::disableFilter(uint8_t index)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return error::INDEX_OVER;
#else
	if(index >= 28)
		return error::INDEX_OVER;
#endif /* GD32F10X_CL */  
	
	setBitData(mDev->FMR, true, 0);	// Filter Lock 비활성화
	setBitData(mDev->FA1R, false, index);	// Filter 비활성화
	setBitData(mDev->FMR, false, 0);	// Filter Lock 활성화
	
	return error::ERROR_NONE;
}

error Can::setStdMaskFilter(uint8_t index, uint16_t id, uint16_t mask)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return error::INDEX_OVER;
#else
	if(index >= 28)
		return error::INDEX_OVER;
#endif /* GD32F10X_CL */  

	setBitData(mDev->FMR, true, 0);	// Filter Lock 비활성화
	
	uint32_t *reg = (uint32_t*)&mDev->sFilterRegister[index];
	*(reg) = (id & 0x7FF) << 21;
	*(reg+1) = (mask & 0x7FF) << 21;

	setBitData(mDev->FM1R, false, index);	// Filter Mask Mode 설정
	setBitData(mDev->FS1R, true, index);	// Filter width 32bit 설정
	setBitData(mDev->FA1R, true, index);		// Filter 활성화

	setBitData(mDev->FMR, false, 0);	// Filter Lock 활성화

	return error::ERROR_NONE;
}

error Can::setExtMaskFilter(uint8_t index, uint32_t id, uint32_t mask)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return error::INDEX_OVER;
#else
	if(index >= 28)
		return error::INDEX_OVER;
#endif /* GD32F10X_CL */  

	setBitData(mDev->FMR, true, 0);	// Filter Lock 비활성화

	uint32_t *reg = (uint32_t*)&mDev->sFilterRegister[index];
	*(reg) = (id & 0x1FFFFFFF) << 3;
	*(reg+1) = (mask & 0x1FFFFFFF) << 3;

	setBitData(mDev->FM1R, false, index);	// Filter Mask Mode 설정
	setBitData(mDev->FS1R, true, index);	// Filter width 32bit 설정
	setBitData(mDev->FA1R, true, index);		// Filter 활성화

	setBitData(mDev->FMR, false, 0);	// Filter Lock 활성화

	return error::ERROR_NONE;
}

error Can::setStdMatchFilter(uint8_t index, uint16_t id)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return error::INDEX_OVER;
#else
	if(index >= 28)
		return error::INDEX_OVER;
#endif /* GD32F10X_CL */  

	setBitData(mDev->FMR, true, 0);	// Filter Lock 비활성화

	uint32_t *reg = (uint32_t*)&mDev->sFilterRegister[index];
	*(reg) = 0X00;
	*(reg+1) = (id & 0x7FF) << 21;

	setBitData(mDev->FM1R, true, index);	// Filter Mask Mode 설정
	setBitData(mDev->FS1R, true, index);	// Filter width 32bit 설정
	setBitData(mDev->FA1R, true, index);		// Filter 활성화

	setBitData(mDev->FMR, false, 0);	// Filter Lock 활성화

	return error::ERROR_NONE;
}

error Can::setExtMatchFilter(uint8_t index, uint32_t id)
{
#ifndef GD32F10X_CL
	if(index >= 14)
		return error::INDEX_OVER;
#else
	if(index >= 28)
		return error::INDEX_OVER;
#endif /* GD32F10X_CL */  

	setBitData(mDev->FMR, true, 0);	// Filter Lock 비활성화
	
	uint32_t *reg = (uint32_t*)&mDev->sFilterRegister[index];
	*(reg) = 0X00;
	setFieldData(*(reg+1), 0x1FFFFFFF << 3, id, 3);

	setBitData(mDev->FM1R, true, index);	// Filter Mask Mode 설정
	setBitData(mDev->FS1R, true, index);	// Filter width 32bit 설정
	setBitData(mDev->FA1R, true, index);	// Filter 활성화

	setBitData(mDev->FMR, false, 0);		// Filter Lock 활성화

	return error::ERROR_NONE;
}

error Can::send(CanFrame packet)
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

	return error::ERROR_NONE;
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
	push((CanFrame*)src);
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
				mIsrForEvent(error::SLEEP_ACK_INTERRUP);
			mDev->MSR = CAN_MSR_SLAKI_Msk;
		}
		
		if(sr & CAN_MSR_WKUI_Msk)
		{
			if(mIsrForEvent)
				mIsrForEvent(error::WAKEUP_INTERRUPT);
			mDev->MSR = CAN_MSR_WKUI_Msk;
		}

		if(sr & CAN_MSR_ERRI_Msk)
		{
			if(mIsrForEvent)
				mIsrForEvent(error::ERROR_INTERRUP);
			mDev->MSR = CAN_MSR_ERRI_Msk;
		}
	}
}

#endif