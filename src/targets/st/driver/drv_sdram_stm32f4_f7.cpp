////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>

#if defined(STM32F4_N) || defined(STM32F7_N)

#include <drv/Sdram.h>
#include <yss.h>
#include <yss/reg.h>

#if defined(STM32F446xx)
#include <targets/st/define_stm32f446xx.h>
#include <targets/st/bitfield_stm32f446xx.h>
#elif defined(STM32F429xx)
#include <targets/st/define_stm32f429xx.h>
#include <targets/st/bitfield_stm32f429xx.h>
#elif defined(STM32F746xx)
#include <targets/st/bitfield_stm32f746xx.h>
#elif defined(STM32F767xx)
#include <targets/st/bitfield_stm32f767xx.h>
#endif

#if defined(FMC_Bank5_6)

#define CMD_NORMAL_MODE 0
#define CMD_CLOCK_CONFIG_ENABLE 1
#define CMD_PALL 2
#define CMD_AUTO_REFRESH 3
#define CMD_LOAD_MODE_REGISTER 4
#define CMD_SELF_REFRESH 5
#define CMD_POWER_DOWN 6

struct Sdcr
{
	unsigned nc : 2;
	unsigned nr : 2;
	unsigned mwid : 2;
	unsigned nb : 1;
	unsigned cas : 2;
	unsigned wp : 1;
	unsigned sdclk : 2;
	unsigned rburst : 1;
	unsigned rpipe : 2;
	unsigned rsv : 16;
};

static void waitWhileBusy(void);
static void setSdcr(uint8_t bank, Sdcr obj);
static void setCmd(uint8_t bank, uint16_t mrd, uint8_t nrfs, uint8_t mode);

Sdram::Sdram(const Drv::Config drvConfig) : Drv(drvConfig)
{
	
}

bool Sdram::initialize(uint8_t bank, const Specification &spec, uint32_t freq)
{
	uint8_t sdclk, rpipe;
	uint32_t clk = freq, buf, t;

	if (spec.maxFrequency > (clk >> 1))
	{
		sdclk = define::sdram::sdclk::HCLKx2;
		clk = clk / 2000;
	}
	else if (spec.maxFrequency > (clk / 3))
	{
		sdclk = define::sdram::sdclk::HCLKx3;
		clk = clk / 3000;
	}

	t = 1000000000 / clk;
	buf = spec.tOh + spec.tAc;
	if (t > buf)
	{
		rpipe = define::sdram::rpipe::NO_DELAY;
	}
	else if (t * 2 > buf)
	{
		rpipe = define::sdram::rpipe::ONE_DELAY;
	}
	else if (t * 3 > buf)
	{
		rpipe = define::sdram::rpipe::TWO_DELAY;
	}
	else
	{
		return false;
	}

	Sdcr obj =
		{
			spec.columnAddress,
			spec.rowAddress,
			spec.dbusWidth,
			spec.internalBank,
			spec.casLatency,
			spec.writeProtection,
			sdclk,
			spec.burstRead,
			rpipe,
			0};

	setSdcr(bank, obj);
	FMC_Bank5_6->SDTR[0] = 0;
	FMC_Bank5_6->SDTR[1] = 0;
	FMC_Bank5_6->SDTR[bank] = (spec.tRcd / t & 0xF) << FMC_SDTR1_TRCD_Pos | (spec.tWr / t & 0xF) << FMC_SDTR1_TWR_Pos | (spec.tRas / t & 0xF) << FMC_SDTR1_TRAS_Pos | (spec.tXsr / t & 0xF) << FMC_SDTR1_TXSR_Pos | (spec.tMrd / t & 0xF);
	FMC_Bank5_6->SDTR[0] |= (spec.tRp / t & 0xF) << FMC_SDTR1_TRP_Pos | (spec.tRc / t & 0xF) << FMC_SDTR1_TRC_Pos;

	waitWhileBusy();
	setCmd(bank, 0, 0, CMD_CLOCK_CONFIG_ENABLE);

	waitWhileBusy();
	setCmd(bank, 0, 0, CMD_PALL);

	waitWhileBusy();
	setCmd(bank, 0, 7, CMD_AUTO_REFRESH);

	waitWhileBusy();
	setCmd(bank, spec.mode, 0, CMD_LOAD_MODE_REGISTER);
	
	setFieldData(FMC_Bank5_6->SDRTR, FMC_SDRTR_COUNT_Msk, spec.tRefresh / 1000 * clk / spec.numOfRow, FMC_SDRTR_COUNT_Pos);
	waitWhileBusy();

	return true;
}

static void waitWhileBusy(void)
{
	__DSB();
	while (FMC_Bank5_6->SDSR & FMC_SDSR_BUSY_Msk)
		;
}

static void setSdcr(uint8_t bank, Sdcr obj)
{
	uint32_t *peri = (uint32_t*)FMC_Bank5_6;

	if (bank == define::sdram::bank::BANK1)
	{
		uint32_t *buf = (uint32_t *)(&obj);
		FMC_Bank5_6->SDCR[0] = *buf;
	}
	else
	{
		uint32_t lsdcr = FMC_Bank5_6->SDCR[0];
		uint32_t *psdcr = (uint32_t *)(&obj);
		Sdcr *ssdcr = (Sdcr *)(&lsdcr);

		lsdcr &= ~(0x7fffUL);
		ssdcr->rburst = obj.rburst;
		ssdcr->rpipe = obj.rpipe;
		ssdcr->sdclk = obj.sdclk;
	
		FMC_Bank5_6->SDCR[0] = lsdcr;
		FMC_Bank5_6->SDCR[1] = *psdcr;
	}
}

static void setCmd(uint8_t bank, uint16_t mrd, uint8_t nrfs, uint8_t mode)
{
	uint8_t cbt;

	if (bank == define::sdram::bank::BANK1)
		cbt = 0x2;
	else
		cbt = 0x1;

	FMC_Bank5_6->SDCMR = (mrd << 9 & 0x1FFFUL << 9) | (nrfs << 5 & 0xFUL << 5) | (cbt << 3) | (mode & 0x7UL);
}

#endif

#endif

