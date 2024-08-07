/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(MAX32672)

#include <drv/peripheral.h>
#include <drv/Clock.h>
#include <yss/reg.h>
#include <targets/maxim/max32672/gcr_regs.h>
#include <targets/maxim/max32672/mcr_regs.h>
#include <targets/maxim/max32672/pwrseq_regs.h>
#include <targets/maxim/max32672/flc_regs.h>
#include <targets/maxim/max32672/icc_regs.h>
#include <assert.h>

static const uint32_t gIpoClockFrequency[3] = {12000000, 50000000, 100000000};

uint32_t Clock::mErfoFrequency __attribute__((section(".non_init")));

void Clock::initialize(void)
{
	mErfoFrequency = 0;
}

error Clock::enableErfo(uint32_t clkFreq, bool en)
{
	uint8_t ovr = getFieldData(MXC_PWRSEQ->lpcn, MXC_F_PWRSEQ_LPCN_OVR, MXC_F_PWRSEQ_LPCN_OVR_POS);

	// 현재 OVR 값에 대한 ERFO의 주파수가 적절한지 검사
	switch(ovr)
	{
	case 0 :
		assert(16000000 <= clkFreq && clkFreq <= 20000000);
		break;

	case 1 :
		assert(20000000 <= clkFreq && clkFreq <= 25000000);
		break;
		
	case 2 :
		assert(25000000 <= clkFreq && clkFreq <= 32000000);
		break;
	}
	
	// ERFO 활성화
	setBitData(MXC_GCR->clkctrl, en, MXC_F_GCR_CLKCTRL_ERFO_EN_POS);

	// ERFO가 활성화 될때까지 대기
	if(en)
		while(!getBitData(MXC_GCR->clkctrl, MXC_F_GCR_CLKCTRL_ERFO_RDY_POS));

	mErfoFrequency = clkFreq;

	return error::ERROR_NONE;
}

error Clock::enableIbro(bool en)
{
	// IBRO 활성화
	setBitData(MXC_GCR->clkctrl, en, MXC_F_GCR_CLKCTRL_IBRO_EN_POS);

	// ERFO가 활성화 될때까지 대기
	if(en)
		while(!getBitData(MXC_GCR->clkctrl, MXC_F_GCR_CLKCTRL_IBRO_RDY_POS));

	return error::ERROR_NONE;
}

error Clock::enableErtco(bool en)
{
	// ERTCO 활성화
	setBitData(MXC_MCR->clkctrl, !en, MXC_F_MCR_CLKCTRL_ERTCO_PD_POS);
	setBitData(MXC_MCR->clkctrl, en, MXC_F_MCR_CLKCTRL_ERTCO_EN_POS);

	if(en)
		while(!getBitData(MXC_GCR->clkctrl, MXC_F_GCR_CLKCTRL_ERTCO_RDY_POS));

	return error::ERROR_NONE;
}

error Clock::setSysclk(uint8_t sysclkSrc, uint8_t sysclkDiv)
{
	uint32_t clk, div;
	uint8_t ovr, fws;

	assert(2 <= sysclkSrc && sysclkSrc <= 7);
	assert(0 <= sysclkDiv && sysclkDiv <= 7);
	
	using namespace define::clock::sysclk;
	
	// 해당 클럭 소스의 준비가 되어 있는지 확인하고 그에 대한 주파수 값을 얻어옴
	switch(sysclkSrc)
	{
	case src::ERFO :
		assert(getBitData(MXC_GCR->clkctrl, MXC_F_GCR_CLKCTRL_ERFO_RDY_POS));
		clk = mErfoFrequency;
		break;

	case src::IPO :
		ovr = getFieldData(MXC_PWRSEQ->lpcn, MXC_F_PWRSEQ_LPCN_OVR, MXC_F_PWRSEQ_LPCN_OVR_POS);
		clk = gIpoClockFrequency[ovr];		
		break;
	
	case src::IBRO :
		assert(getBitData(MXC_GCR->clkctrl, MXC_F_GCR_CLKCTRL_IBRO_RDY_POS));
		clk = IBRO_FREQ;
		break;
	
	case src::ERTCO :
		assert(getBitData(MXC_GCR->clkctrl, MXC_F_GCR_CLKCTRL_ERTCO_RDY_POS));
		clk = ERTCO_FREQ;
		break;

	case src::INRO :
		clk = INRO_FREQ;
		break;

	default :
		return error::WRONG_CONFIG;
	}
	
	// Flash Wait State 값 계산
	div = 1 << sysclkDiv;
	clk /= div;

	fws = clk / 25000000;
	if(fws > 2)
		fws = 2;

	// Flash Wait State를 주파수가 가장 빠른 값에 대한 설정으로 변경
	setFieldData(MXC_GCR->memctrl, MXC_F_GCR_MEMCTRL_FWS, 5, MXC_F_GCR_MEMCTRL_FWS_POS);

	// SYS_OSC의 분주비 변경
	setFieldData(MXC_GCR->clkctrl, MXC_F_GCR_CLKCTRL_SYSCLK_DIV, sysclkDiv, MXC_F_GCR_CLKCTRL_SYSCLK_DIV_POS);

	// SYS_OSC의 소스를 INRO로 변경
	setFieldData(MXC_GCR->clkctrl, MXC_F_GCR_CLKCTRL_SYSCLK_SEL, sysclkSrc, MXC_F_GCR_CLKCTRL_SYSCLK_SEL_POS);

	// SYS_OSC의 소스 변경 완료 대기
	__DSB();
	while(!getBitData(MXC_GCR->clkctrl, MXC_F_GCR_CLKCTRL_SYSCLK_RDY_POS));
	
	// 현재 클록 주파수에 맞는 Flash Wait State로 변경
	setFieldData(MXC_GCR->memctrl, MXC_F_GCR_MEMCTRL_FWS, fws, MXC_F_GCR_MEMCTRL_FWS_POS);
	
	return error::ERROR_NONE;
}

error Clock::setOperatingVoltageRange(uint8_t ovr)
{
	bool ldoDis = getBitData(MXC_PWRSEQ->lpcn, MXC_F_PWRSEQ_LPCN_LDO_DIS_POS), lve;
	uint8_t src = getFieldData(MXC_GCR->clkctrl, MXC_F_GCR_CLKCTRL_SYSCLK_SEL, MXC_F_GCR_CLKCTRL_SYSCLK_SEL_POS);
	uint8_t fws = getFieldData(MXC_GCR->memctrl, MXC_F_GCR_MEMCTRL_FWS, MXC_F_GCR_MEMCTRL_FWS_POS);
	
	// 내장 LDO를 활성화 시킴
	setBitData(MXC_PWRSEQ->lpcn, false, MXC_F_PWRSEQ_LPCN_LDO_DIS_POS);

	// SYS_OSC의 소스를 INRO로 변경
	setFieldData(MXC_GCR->clkctrl, MXC_F_GCR_CLKCTRL_SYSCLK_SEL, define::clock::sysclk::src::INRO, MXC_F_GCR_CLKCTRL_SYSCLK_SEL_POS);
	
	// SYS_OSC의 소스 변경 완료 대기
	__DSB();
	while(!getBitData(MXC_GCR->clkctrl, MXC_F_GCR_CLKCTRL_SYSCLK_RDY_POS));
	
	// Flash Wait State를 주파수가 가장 빠른 값에 대한 설정으로 변경
	setFieldData(MXC_GCR->memctrl, MXC_F_GCR_MEMCTRL_FWS, 5, MXC_F_GCR_MEMCTRL_FWS_POS);
	
	// OVR 업데이트
	setFieldData(MXC_PWRSEQ->lpcn, MXC_F_PWRSEQ_LPCN_OVR, ovr, MXC_F_PWRSEQ_LPCN_OVR_POS);
	
	// FLASH의 LVE값 업데이트 
	switch(ovr)
	{
	case define::clock::ovr::V_CORE_1_1V :
		lve = false;
		break;

	case define::clock::ovr::V_CORE_1_0V :
	case define::clock::ovr::V_CORE_0_9V :
		lve = true;		
		break;	
	}

	setBitData(MXC_FLC0->ctrl, lve, MXC_F_FLC_CTRL_LVE_POS);	
	setBitData(MXC_FLC1->ctrl, lve, MXC_F_FLC_CTRL_LVE_POS);	
	
	// 주변장치 리셋
	MXC_GCR->rst0 = MXC_F_GCR_RST0_PERIPH;
	
	// 리셋 완료까지 대기	
	__DSB();
	while(MXC_GCR->rst0);

	return error::ERROR_NONE;
}

uint8_t Clock::getCacheId(void)
{
	return getFieldData(MXC_ICC->info, MXC_F_ICC_INFO_ID, MXC_F_ICC_INFO_ID_POS);
}

uint8_t Clock::getCachePartNumber(void)
{
	return getFieldData(MXC_ICC->info, MXC_F_ICC_INFO_PARTNUM, MXC_F_ICC_INFO_PARTNUM_POS);
}

uint8_t Clock::getCacheReleaseNumber(void)
{
	return getFieldData(MXC_ICC->info, MXC_F_ICC_INFO_RELNUM, MXC_F_ICC_INFO_RELNUM_POS);
}

void Clock::enableCache(bool en)
{
	if(en)
		invalidateCache();

	// 캐쉬 활성화/비활성화
	setBitData(MXC_ICC->ctrl, en, MXC_F_ICC_CTRL_EN_POS);
	
	if(en)
	{
		// 캐쉬가 준비 상태가 될때까지 대기
		__DSB();
		while(!getBitData(MXC_ICC->ctrl, MXC_F_ICC_CTRL_RDY_POS));
	}
}

void Clock::invalidateCache(void)
{
	// 캐쉬 비우기
	MXC_ICC->invalidate = 1;

	// 캐쉬가 준비 상태가 될때까지 대기
	__DSB();
	while(!getBitData(MXC_ICC->ctrl, MXC_F_ICC_CTRL_RDY_POS));
}

uint32_t Clock::getCacheAddressAbleMemorySize(void)
{
	return getFieldData(MXC_ICC->sz, MXC_F_ICC_SZ_MEM, MXC_F_ICC_SZ_MEM_POS) * 128;
}

uint16_t Clock::getCacheSize(void)
{
	return getFieldData(MXC_ICC->sz, MXC_F_ICC_SZ_CCH, MXC_F_ICC_SZ_CCH_POS);
}

uint32_t Clock::getCoreClockFrequency(void)
{
	return 0;
}

#endif