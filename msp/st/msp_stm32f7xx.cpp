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

#include <__cross_studio_io.h>

#if	defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) ||	defined(STM32F767xx) ||	defined(STM32F768xx) ||	defined(STM32F769xx)

#include <config.h>

#if YSS_USE_DEFAULT_MSP == true

#include <drv/peripherals.h>

void __attribute__((weak))initSystem(void)
{
	clock.enableHse(HSE_CLOCK_FREQ);
    clock.enableLsi();
    clock.setUsbClkSrc(define::clock::usbclk::src::MAIN_PLL);

	clock.pll.enable
	(
		define::clock::pll::src::HSE,		// unsigned char src
		320,								// unsigned long vcoMhz
		define::clock::pll::pdiv::DIV2,		// unsigned char pDiv
		define::clock::pll::qdiv::DIV7,		// unsigned char qDiv
		0									// unsigned char rDiv
	);

	//clock.saipll.enable
	//(
	//	120,								// unsigned long vcoMhz
	//	0,									// unsigned char pDiv
	//	define::clock::saipll::qdiv::DIV10, // unsigned char qDiv
	//	define::clock::saipll::rdiv::DIV4	// unsigned char rDiv
	//);

	//clock.setSysclk
	//(
	//	define::clock::sysclk::src::PLL,		// unsigned char sysclkSrc;
	//	define::clock::divFactor::ahb::NO_DIV,	// unsigned char ahb;
	//	define::clock::divFactor::apb::DIV4,	// unsigned char apb1;
	//	define::clock::divFactor::apb::DIV2,	// unsigned char apb2;
	//	33										// unsigned char vcc
	//);

	//flash.setPrefetchEn(true);
 //   flash.setDCacheEn(true);
 //   flash.setICacheEn(true);

	//clock.peripheral.setGpioAEn(true);
	//clock.peripheral.setGpioBEn(true);
	//clock.peripheral.setGpioCEn(true);
	//clock.peripheral.setGpioDEn(true);
	//clock.peripheral.setGpioEEn(true);
	//clock.peripheral.setGpioFEn(true);
	//clock.peripheral.setGpioGEn(true);
	//clock.peripheral.setGpioHEn(true);
	//clock.peripheral.setGpioIEn(true);
	//clock.peripheral.setGpioJEn(true);
	//clock.peripheral.setGpioKEn(true);

	//clock.peripheral.setPwrEn(true);
}

#endif

#endif

/*
#include <__cross_studio_io.h>

#if defined(STM32F746xx)
#include <yss/malloc.h>
#include <yss/yss.h>
#include <yss/fs.h>
#include <drv/peripherals.h>
#include <mod/sdram/MT48LC4M32B2B5_6A.h>
#include <mod/ctouch/FT5336.h>
#include <mod/tft/RK043FN48H.h>
#include <mod/usbd/MassStorage.h>
#include <mod/qsflash/N25Q128A1.h>

namespace bsp
{
namespace st
{
	static void init(void);
	static void SystemInit(void);

	//setting::Bsp stm32f746Discovery =
	//{
	//	init,
	//	SystemInit,
	//};

	//mod::ctouch::FT5336 ft5336;

	static config::rtc::Config gRtcConfig =
	{
		define::rtc::clockSrc::LSE,		// unsigned	char clkSrc;
		3,								// unsigned	char clkDrive;
		0x7f,							// unsigned	char asynchronousPrescaler;
		0xff,							// unsigned	short synchronousPrescaler;
	};


	static void SystemInit(void)
	{
		clock.enableHse(25);
		clock.enableLsi();
		clock.setUsbClkSrc(define::clock::usbclk::src::MAIN_PLL);

		clock.setSdmmcClkSrc(define::clock::sdmmc1::src::USBCLK);
		
		// PLLCLK = 216 MHz
		// PLLQ = 48 MHz
		config::clock::Pll pllConfig =
		{
			25,								//	unsigned char m;
			define::clock::pll::src::HSE,	//	unsigned char src;
			432,							//	unsigned short n;
			0,								//	unsigned char p;
			9								//	unsigned char q;
		};
		clock.pll.enable(pllConfig);
	
		// PLLSAIP(USB) = 48 MHz
		// PLLSAIQ = 12.8 MHz
		// SAI2CLK = 1.422 MHz
		// PLLSAIR = 32 MHz
		// LTDCCLK = 8 MHz
		config::clock::Saipll saipllConfig =
		{
			192,	//	unsigned short n;
			1,		//	unsigned char p;
			15,		//	unsigned char pllq;
			8,		//	unsigned char saiq;
			6,		//	unsigned char pllr;
			1		//	unsigned char lcdr;
		};
		clock.saipll.enable(saipllConfig);

		// SYSCLK = 216 MHz
		// AHBCLK = 216 MHz
		// APB1CLK = 54 MHz
		// APB2CLK = 108 MHz
		config::clock::Sysclk sysclk =
		{
			define::clock::sysclk::src::PLL,		// unsigned char sysclkSrc;
			define::clock::divFactor::ahb::NO_DIV,	// unsigned char ahb;
			define::clock::divFactor::apb::DIV4,	// unsigned char apb1;
			define::clock::divFactor::apb::DIV2,	// unsigned char apb2;
			33,										// unsigned char vcc
		};
		clock.system.setSysclk(sysclk);
		flash.setPrefetchEn(true);

		config::gpio::AltFunc sdramPort[38]
		{
			{GPIOF, 0, define::gpio::altfunc::SDRAM_AF12},	//	ADDR0
			{GPIOF, 1, define::gpio::altfunc::SDRAM_AF12},	//	ADDR1
			{GPIOF, 2, define::gpio::altfunc::SDRAM_AF12},	//	ADDR2
			{GPIOF, 3, define::gpio::altfunc::SDRAM_AF12},	//	ADDR3
			{GPIOF, 4, define::gpio::altfunc::SDRAM_AF12},	//	ADDR4
			{GPIOF, 5, define::gpio::altfunc::SDRAM_AF12},	//	ADDR5
			{GPIOF, 12, define::gpio::altfunc::SDRAM_AF12},	//	ADDR6
			{GPIOF, 13, define::gpio::altfunc::SDRAM_AF12},	//	ADDR7
			{GPIOF, 14, define::gpio::altfunc::SDRAM_AF12},	//	ADDR8
			{GPIOF, 15, define::gpio::altfunc::SDRAM_AF12},	//	ADDR9
			{GPIOG, 0, define::gpio::altfunc::SDRAM_AF12},	//	ADDR10
			{GPIOG, 1, define::gpio::altfunc::SDRAM_AF12},	//	ADDR11
			{GPIOG, 4, define::gpio::altfunc::SDRAM_AF12},	//	BA0
			{GPIOG, 5, define::gpio::altfunc::SDRAM_AF12},	//	BA1
			{GPIOD, 14, define::gpio::altfunc::SDRAM_AF12},	//	DATA0
			{GPIOD, 15, define::gpio::altfunc::SDRAM_AF12},	//	DATA1
			{GPIOD, 0, define::gpio::altfunc::SDRAM_AF12},	//	DATA2
			{GPIOD, 1, define::gpio::altfunc::SDRAM_AF12},	//	DATA3
			{GPIOE, 7, define::gpio::altfunc::SDRAM_AF12},	//	DATA4
			{GPIOE, 8, define::gpio::altfunc::SDRAM_AF12},	//	DATA5
			{GPIOE, 9, define::gpio::altfunc::SDRAM_AF12},	//	DATA6
			{GPIOE, 10, define::gpio::altfunc::SDRAM_AF12},	//	DATA7
			{GPIOE, 11, define::gpio::altfunc::SDRAM_AF12},	//	DATA8
			{GPIOE, 12, define::gpio::altfunc::SDRAM_AF12},	//	DATA9
			{GPIOE, 13, define::gpio::altfunc::SDRAM_AF12},	//	DATA10
			{GPIOE, 14, define::gpio::altfunc::SDRAM_AF12},	//	DATA11
			{GPIOE, 15, define::gpio::altfunc::SDRAM_AF12},	//	DATA12
			{GPIOD, 8, define::gpio::altfunc::SDRAM_AF12},	//	DATA13
			{GPIOD, 9, define::gpio::altfunc::SDRAM_AF12},	//	DATA14
			{GPIOD, 10, define::gpio::altfunc::SDRAM_AF12},	//	DATA15
			{GPIOE, 0, define::gpio::altfunc::SDRAM_AF12},	//	NBL0
			{GPIOE, 1, define::gpio::altfunc::SDRAM_AF12},	//	NBL1
			{GPIOG, 8, define::gpio::altfunc::SDRAM_AF12},	//	SDCLK
			{GPIOH, 5, define::gpio::altfunc::SDRAM_AF12},	//	SDNWE
			{GPIOF, 11, define::gpio::altfunc::SDRAM_AF12},	//	SDNRAS
			{GPIOG, 15, define::gpio::altfunc::SDRAM_AF12},	//	SDNCAS
			{GPIOC, 3, define::gpio::altfunc::SDRAM_AF12},	//	SDCKE
			{GPIOH, 3, define::gpio::altfunc::SDRAM_AF12}	//	SDNE
		};


		clock.peripheral.setGpioAEn(true);
		clock.peripheral.setGpioBEn(true);
		clock.peripheral.setGpioCEn(true);
		clock.peripheral.setGpioDEn(true);
		clock.peripheral.setGpioEEn(true);
		clock.peripheral.setGpioFEn(true);
		clock.peripheral.setGpioGEn(true);
		clock.peripheral.setGpioHEn(true);
		clock.peripheral.setGpioIEn(true);
		clock.peripheral.setGpioJEn(true);
		clock.peripheral.setGpioKEn(true);

		gpioA.setToAltFunc(sdramPort, 38, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);

		clock.peripheral.setFmcEn(true);
		sdram.init(define::sdram::bank::BANK1,	mod::sdram::MT48LC4M32B2B5_6A);

		clock.peripheral.setSyscfgEn(true);
		syscfg.swapFmc(true);

		yss::initLheap()

	}

	bool getSdmmcDetect(void)
	{
		return gpioC.getData(13);
	}

	static void init(void)
	{

		// I2C3 초기화
		gpioH.setAltFunc(7, define::gpio::altfunc::I2C3_AF4, define::gpio::ospeed::LOW, define::gpio::otype::OPEN_DRAIN);
		gpioH.setAltFunc(8, define::gpio::altfunc::I2C3_AF4, define::gpio::ospeed::LOW, define::gpio::otype::OPEN_DRAIN);

		clock.peripheral.setI2c3En(true);
		i2c3.init(define::i2c::speed::STANDARD);

		// 정전용량형 터치패널 초기화
		mod::ctouch::FT5336_config ft5336Config =
		{
			i2c3,		// drv::I2c &peri;
			0x70,		// char addr;
			0,			// drv::Gpio *resetPort;
			0,			// unsigned char resetPin;
			&gpioI,		// drv::Gpio *IsrPort;
			13			// unsigned char IsrPin;
		};
		ft5336.init(ft5336Config);

		// SDMMC1 초기화
		gpioC.setAltFunc(8, define::gpio::altfunc::SDMMC1_AF12, define::gpio::ospeed::MID, define::gpio::otype::PUSH_PULL);
		gpioC.setAltFunc(9, define::gpio::altfunc::SDMMC1_AF12, define::gpio::ospeed::MID, define::gpio::otype::PUSH_PULL);
		gpioC.setAltFunc(10, define::gpio::altfunc::SDMMC1_AF12, define::gpio::ospeed::MID, define::gpio::otype::PUSH_PULL);
		gpioC.setAltFunc(11, define::gpio::altfunc::SDMMC1_AF12, define::gpio::ospeed::MID, define::gpio::otype::PUSH_PULL);
		gpioC.setAltFunc(12, define::gpio::altfunc::SDMMC1_AF12, define::gpio::ospeed::MID, define::gpio::otype::PUSH_PULL);
		gpioD.setAltFunc(2, define::gpio::altfunc::SDMMC1_AF12, define::gpio::ospeed::MID, define::gpio::otype::PUSH_PULL);
		gpioC.setPullUpDown(13, define::gpio::pupd::PULL_UP);
		
		clock.peripheral.setSdmmc(true);
		config::gpio::Set detect = {&gpioC, 13};
		config::sdmmc::Config sdmmcConfig = 
		{
			detect,		// Detect 포트 셋
			3.3			// MCU의	전원 전압
		};
		sdmmc.init(sdmmcConfig);

		// TFT LCD 초기화
		config::gpio::AltFunc lcdPort[28] =
		{
			{GPIOJ, 6, define::gpio::altfunc::LCD_AF14},	//	R7
			{GPIOJ, 5, define::gpio::altfunc::LCD_AF14},	//	R6
			{GPIOJ, 4, define::gpio::altfunc::LCD_AF14},	//	R5
			{GPIOJ, 3, define::gpio::altfunc::LCD_AF14},	//	R4
			{GPIOJ, 2, define::gpio::altfunc::LCD_AF14},	//	R3
			{GPIOJ, 1, define::gpio::altfunc::LCD_AF14},	//	R2
			{GPIOJ, 0, define::gpio::altfunc::LCD_AF14},	//	R1
			{GPIOI, 15, define::gpio::altfunc::LCD_AF14},	//	R0

			{GPIOK, 2, define::gpio::altfunc::LCD_AF14},	//	G7
			{GPIOK, 1, define::gpio::altfunc::LCD_AF14},	//	G6
			{GPIOK, 0, define::gpio::altfunc::LCD_AF14},	//	G5
			{GPIOJ, 11, define::gpio::altfunc::LCD_AF14},	//	G4
			{GPIOJ, 10, define::gpio::altfunc::LCD_AF14},	//	G3
			{GPIOJ, 9, define::gpio::altfunc::LCD_AF14},	//	G2
			{GPIOJ, 8, define::gpio::altfunc::LCD_AF14},	//	G1
			{GPIOJ, 7, define::gpio::altfunc::LCD_AF14},	//	G0

			{GPIOK, 6, define::gpio::altfunc::LCD_AF14},	//	B7
			{GPIOK, 5, define::gpio::altfunc::LCD_AF14},	//	B6
			{GPIOK, 4, define::gpio::altfunc::LCD_AF14},	//	B5
			{GPIOG, 12, define::gpio::altfunc::LCD_AF9},	//	B4
			{GPIOJ, 15, define::gpio::altfunc::LCD_AF14},	//	B3
			{GPIOJ, 14, define::gpio::altfunc::LCD_AF14},	//	B2
			{GPIOJ, 13, define::gpio::altfunc::LCD_AF14},	//	B1
			{GPIOE, 4, define::gpio::altfunc::LCD_AF14},	//	B0

			{GPIOI, 9, define::gpio::altfunc::LCD_AF14},	//	VSYNC
			{GPIOI, 10, define::gpio::altfunc::LCD_AF14},	//	HSYNC
			{GPIOK, 7, define::gpio::altfunc::LCD_AF14},	//	ENABLE
			{GPIOI, 14, define::gpio::altfunc::LCD_AF14}	//	CLOCK
		};

		gpioA.setAltFunc(lcdPort, 28, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);
//		ltdc.setClockEn(true);
//		ltdc.init();
		gpioI.setOutput(12, define::gpio::ospeed::LOW, define::gpio::otype::PUSH_PULL);
		gpioI.setOutputData(12, true);






//		unsigned char *buf = (unsigned char*)lmalloc(4096), *des = (unsigned char*)lmalloc(4096);
//
//		for(unsigned short i=0;i<4096;i++)
//		{
//			buf[i] = 0x1a;
//			des[i] = 0;
//		}
//
//		debug_printf("%d\n", gN25q128a1.write(0, buf));
//
//		gN25q128a1.read(0, des);
//		for(unsigned short i=0;i<4096;i++)
//			debug_printf("[%d]0x%02x\n",i, des[i]);

	}
}
}

#endif
*/
