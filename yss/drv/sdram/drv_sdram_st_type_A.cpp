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

#if defined(STM32F746xx) || defined(STM32F745xx) ||                                                 \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
    defined(STM32F405xx) || defined(STM32F415xx) ||                                                 \
    defined(STM32F407xx) || defined(STM32F417xx) ||                                                 \
    defined(STM32F427xx) || defined(STM32F437xx) ||                                                 \
    defined(STM32F429xx) || defined(STM32F439xx)

#include <config.h>
#include <drv/peripherals.h>
#include <drv/sdram/drv_st_sdram_type_A_register.h>
#include <instance/instance_clock.h>

#if defined(FMC_Bank5_6)

#define PERIPHERAL FMC_Bank5_6

#define CMD_NORMAL_MODE 0
#define CMD_CLOCK_CONFIG_ENABLE 1
#define CMD_PALL 2
#define CMD_AUTO_REFRESH 3
#define CMD_LOAD_MODE_REGISTER 4
#define CMD_SELF_REFRESH 5
#define CMD_POWER_DOWN 6


namespace drv
{
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
static void setSdcr(unsigned char bank, Sdcr obj);
static void setCmd(unsigned char bank, unsigned short mrd, unsigned char nrfs, unsigned char mode);

Sdram::Sdram(void (*clockFunc)(bool en), void (*nvicFunc)(bool en)) : Drv(clockFunc, nvicFunc)
{
}

bool Sdram::init(unsigned char bank, config::sdram::Config &config)
{
    unsigned char sdclk, rpipe;
    unsigned long clk = clock.getSysClkFreq(), comp, t;

    if (config.maxFrequency > (clk >> 1))
    {
        sdclk = define::sdram::sdclk::HCLKx2;
        clk = clk / 2000;
    }
    else if (config.maxFrequency > (clk / 3))
    {
        sdclk = define::sdram::sdclk::HCLKx3;
        clk = clk / 3000;
    }

    t = 1000000000 / clk;
    comp = config.tOh + config.tAc;
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
            config.columnAddress,
            config.rowAddress,
            config.dbusWidth,
            config.internalBank,
            config.casLatency,
            config.writeProtection,
            sdclk,
            config.burstRead,
            rpipe,
            0};

    setSdcr(bank, obj);

    PERIPHERAL->SDTR[0] = 0x0;
    PERIPHERAL->SDTR[1] = 0x0;

    setSdramSdtrTmrd(bank, (unsigned char)(config.tMrd / t));
    setSdramSdtrTxsr(bank, (unsigned char)(config.tXsr / t));
    setSdramSdtrTras(bank, (unsigned char)(config.tRas / t));
    setSdramSdtrTrc(define::sdram::bank::BANK1, (unsigned char)(config.tRc / t)); // BANK2	Don't care
    setSdramSdtrTwr(bank, (unsigned char)(config.tWr / t));
    setSdramSdtrTrp(define::sdram::bank::BANK1, (unsigned char)(config.tRp / t)); // BANK2	Don't care
    setSdramSdtrTrcd(bank, (unsigned char)(config.tRcd / t));

    waitWhileBusy();
    setCmd(bank, 0, 0, CMD_CLOCK_CONFIG_ENABLE);
    for (volatile unsigned long i = 0; i < 1000000; i++)
        ;

    waitWhileBusy();
    setCmd(bank, 0, 0, CMD_PALL);

    waitWhileBusy();
    setCmd(bank, 0, 7, CMD_AUTO_REFRESH);

    waitWhileBusy();

    setCmd(bank, config.mode, 0, CMD_LOAD_MODE_REGISTER);

    setSdramSdrtrRtr((unsigned short)(config.tRefresh / 1000 * clk / config.numOfRow));
    waitWhileBusy();

    return true;
}

static void waitWhileBusy(void)
{
    while (PERIPHERAL->SDSR & (1 << 5))
        ;
}

static void setSdcr(unsigned char bank, Sdcr obj)
{
    if (bank == define::sdram::bank::BANK1)
    {
        unsigned long *buf = (unsigned long *)(&obj);
        PERIPHERAL->SDCR[0] = *buf;
    }
    else
    {
        unsigned long lsdcr = PERIPHERAL->SDCR[0];
        unsigned long *psdcr = (unsigned long *)(&obj);
        Sdcr *ssdcr = (Sdcr *)(&lsdcr);

        lsdcr &= ~(0x7fffUL);
        ssdcr->rburst = obj.rburst;
        ssdcr->rpipe = obj.rpipe;
        ssdcr->sdclk = obj.sdclk;

        PERIPHERAL->SDCR[0] = lsdcr;
        PERIPHERAL->SDCR[1] = *psdcr;
    }
}

static void setCmd(unsigned char bank, unsigned short mrd, unsigned char nrfs, unsigned char mode)
{
    unsigned char cbt;

    if (bank == define::sdram::bank::BANK1)
        cbt = 0x2;
    else
        cbt = 0x1;

    PERIPHERAL->SDCMR = (mrd << 9 & 0x1FFFUL << 9) | (nrfs << 5 & 0xFUL << 5) | (cbt << 3) | (mode & 0x7UL);
}
}

#endif

#endif