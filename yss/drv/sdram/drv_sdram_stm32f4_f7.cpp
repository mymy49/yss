////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
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

#if defined(STM32F7) || defined(STM32F4)

#include <drv/Sdram.h>
#include <drv/sdram/register_sdram_stm32f4_f7.h>
#include <yss/yss.h>

#if defined(FMC_Bank5_6)

#define PERIPHERAL FMC_Bank5_6

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

bool Sdram::init(uint8_t bank, const Specification &spec)
{
	uint8_t sdclk, rpipe;
	uint32_t clk = yss::getSystemClockFrequency(), comp, t;

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
	comp = spec.tOh + spec.tAc;
	if (t > comp)
	{
		rpipe = define::sdram::rpipe::NO_DELAY;
	}
	else if (t * 2 > comp)
	{
		rpipe = define::sdram::rpipe::ONE_DELAY;
	}
	else if (t * 3 > comp)
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

	PERIPHERAL->SDTR[0] = 0x0;
	PERIPHERAL->SDTR[1] = 0x0;

	setSdramSdtrTmrd(bank, (uint8_t)(spec.tMrd / t));
	setSdramSdtrTxsr(bank, (uint8_t)(spec.tXsr / t));
	setSdramSdtrTras(bank, (uint8_t)(spec.tRas / t));
	setSdramSdtrTrc(define::sdram::bank::BANK1, (uint8_t)(spec.tRc / t)); // BANK2	Don't care
	setSdramSdtrTwr(bank, (uint8_t)(spec.tWr / t));
	setSdramSdtrTrp(define::sdram::bank::BANK1, (uint8_t)(spec.tRp / t)); // BANK2	Don't care
	setSdramSdtrTrcd(bank, (uint8_t)(spec.tRcd / t));

	waitWhileBusy();
	setCmd(bank, 0, 0, CMD_CLOCK_CONFIG_ENABLE);
	for (volatile uint32_t i = 0; i < 1000000; i++)
		;

	waitWhileBusy();
	setCmd(bank, 0, 0, CMD_PALL);

	waitWhileBusy();
	setCmd(bank, 0, 7, CMD_AUTO_REFRESH);

	waitWhileBusy();

	setCmd(bank, spec.mode, 0, CMD_LOAD_MODE_REGISTER);

	setSdramSdrtrRtr((uint16_t)(spec.tRefresh / 1000 * clk / spec.numOfRow));
	waitWhileBusy();

	return true;
}

static void waitWhileBusy(void)
{
	while (PERIPHERAL->SDSR & (1 << 5))
		;
}

static void setSdcr(uint8_t bank, Sdcr obj)
{
	if (bank == define::sdram::bank::BANK1)
	{
		uint32_t *buf = (uint32_t *)(&obj);
		PERIPHERAL->SDCR[0] = *buf;
	}
	else
	{
		uint32_t lsdcr = PERIPHERAL->SDCR[0];
		uint32_t *psdcr = (uint32_t *)(&obj);
		Sdcr *ssdcr = (Sdcr *)(&lsdcr);

		lsdcr &= ~(0x7fffUL);
		ssdcr->rburst = obj.rburst;
		ssdcr->rpipe = obj.rpipe;
		ssdcr->sdclk = obj.sdclk;

		PERIPHERAL->SDCR[0] = lsdcr;
		PERIPHERAL->SDCR[1] = *psdcr;
	}
}

static void setCmd(uint8_t bank, uint16_t mrd, uint8_t nrfs, uint8_t mode)
{
	uint8_t cbt;

	if (bank == define::sdram::bank::BANK1)
		cbt = 0x2;
	else
		cbt = 0x1;

	PERIPHERAL->SDCMR = (mrd << 9 & 0x1FFFUL << 9) | (nrfs << 5 & 0xFUL << 5) | (cbt << 3) | (mode & 0x7UL);
}

#endif

#endif

