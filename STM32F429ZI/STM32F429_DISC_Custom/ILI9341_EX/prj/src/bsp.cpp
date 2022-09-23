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

#include <bsp.h>
#include <yss/instance.h>
#include <mod/rtouch/STMPE811.h>
#include <mod/sdram/IS42S16400J_7TL.h>
#include <yss/yss.h>

#include <__cross_studio_io.h>

#include <util/time.h>

Bmp565BrushSwappedByte gBrush(100 * 100);

void initSdram(void)
{
	using namespace define::gpio::altfunc;

	Gpio::AltFunc sdramPort[38]{
		{GPIOF, 0, PF0_FMC_A0},
		{GPIOF, 1, PF1_FMC_A1},
		{GPIOF, 2, PF2_FMC_A2},
		{GPIOF, 3, PF3_FMC_A3},
		{GPIOF, 4, PF4_FMC_A4},
		{GPIOF, 5, PF5_FMC_A5},
		{GPIOF, 12, PF12_FMC_A6},
		{GPIOF, 13, PF13_FMC_A7},
		{GPIOF, 14, PF14_FMC_A8},
		{GPIOF, 15, PF15_FMC_A9},
		{GPIOG, 0, PG0_FMC_A10},
		{GPIOG, 1, PG1_FMC_A11},
		{GPIOG, 4, PG4_FMC_BA0},
		{GPIOG, 5, PG5_FMC_BA1},
		{GPIOD, 14, PD14_FMC_D0},
		{GPIOD, 15, PD15_FMC_D1},
		{GPIOD, 0, PD0_FMC_D2},
		{GPIOD, 1, PD1_FMC_D3},
		{GPIOE, 7, PE7_FMC_D4},
		{GPIOE, 8, PE8_FMC_D5},
		{GPIOE, 9, PE9_FMC_D6},
		{GPIOE, 10, PE10_FMC_D7},
		{GPIOE, 11, PE11_FMC_D8},
		{GPIOE, 12, PE12_FMC_D9},
		{GPIOE, 13, PE13_FMC_D10},
		{GPIOE, 14, PE14_FMC_D11},
		{GPIOE, 15, PE15_FMC_D12},
		{GPIOD, 8, PD8_FMC_D13},
		{GPIOD, 9, PD9_FMC_D14},
		{GPIOD, 10, PD10_FMC_D15},
		{GPIOE, 0, PE0_FMC_NBL0},
		{GPIOE, 1, PE1_FMC_NBL1},
		{GPIOG, 8, PG8_FMC_SDCLK},
		{GPIOC, 0, PC0_FMC_SDNWE},
		{GPIOF, 11, PF11_FMC_SDNRAS},
		{GPIOG, 15, PG15_FMC_SDNCAS},
		{GPIOB, 5, PB5_FMC_SDCKE1},
		{GPIOB, 6, PB6_FMC_SDNE1}
	};

	gpioA.setPackageAsAltFunc(sdramPort, 38, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);

	clock.peripheral.setFmcEn(true);
	sdram.init(define::sdram::bank::BANK2, IS42S16400J_7TL);
}

SF_TC240T_9370_T lcd1;
MSP2402 lcd2;
STMPE811 touch;

void initBoard(void)
{
	using namespace define::gpio;

	// LED 초기화
	gpioG.setAsOutput(13, ospeed::MID, otype::PUSH_PULL);
	gpioG.setAsOutput(14, ospeed::MID, otype::PUSH_PULL);

	// SPI5 초기화
	gpioF.setAsAltFunc(7, altfunc::PF7_SPI5_SCK, ospeed::FAST, otype::PUSH_PULL); // SCK
	gpioF.setAsAltFunc(9, altfunc::PF9_SPI5_MOSI, ospeed::FAST, otype::PUSH_PULL); // MOSI

	spi5.setClockEn(true);
	spi5.init();
	spi5.setIntEn(true);

	// 그래픽 LCD 초기화
	gpioB.setAsAltFunc(0, altfunc::PB0_LCD_R3, ospeed::FAST, otype::PUSH_PULL);
	gpioA.setAsAltFunc(11, altfunc::PA11_LCD_R4, ospeed::FAST, otype::PUSH_PULL);
	gpioA.setAsAltFunc(12, altfunc::PA12_LCD_R5, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setAsAltFunc(1, altfunc::PB1_LCD_R6, ospeed::FAST, otype::PUSH_PULL);
	gpioG.setAsAltFunc(6, altfunc::PG6_LCD_R7, ospeed::FAST, otype::PUSH_PULL);

	gpioA.setAsAltFunc(6, altfunc::PA6_LCD_G2, ospeed::FAST, otype::PUSH_PULL);
	gpioG.setAsAltFunc(10, altfunc::PG10_LCD_G3, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setAsAltFunc(10, altfunc::PB10_LCD_G4, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setAsAltFunc(11, altfunc::PB11_LCD_G5, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsAltFunc(7, altfunc::PC7_LCD_G6, ospeed::FAST, otype::PUSH_PULL);
	gpioD.setAsAltFunc(3, altfunc::PD3_LCD_G7, ospeed::FAST, otype::PUSH_PULL);

	gpioG.setAsAltFunc(11, altfunc::PG11_LCD_B3, ospeed::FAST, otype::PUSH_PULL);
	gpioG.setAsAltFunc(12, altfunc::PG12_LCD_B4, ospeed::FAST, otype::PUSH_PULL);
	gpioA.setAsAltFunc(3, altfunc::PA3_LCD_B5, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setAsAltFunc(8, altfunc::PB8_LCD_B6, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setAsAltFunc(9, altfunc::PB9_LCD_B7, ospeed::FAST, otype::PUSH_PULL);

	gpioA.setAsAltFunc(4, altfunc::PA4_LCD_VSYNC, ospeed::FAST, otype::PUSH_PULL);
	gpioC.setAsAltFunc(6, altfunc::PC6_LCD_HSYNC, ospeed::FAST, otype::PUSH_PULL);
	gpioF.setAsAltFunc(10, altfunc::PF10_LCD_DE, ospeed::FAST, otype::PUSH_PULL);
	gpioG.setAsAltFunc(7, altfunc::PG7_LCD_CLK, ospeed::FAST, otype::PUSH_PULL);

	gpioC.setAsOutput(2, ospeed::FAST, otype::PUSH_PULL);  // CS
	gpioD.setAsOutput(13, ospeed::FAST, otype::PUSH_PULL); // DCX

	Gpio::Pin lcdCs = {&gpioC, 2};
	Gpio::Pin lcdDcx = {&gpioD, 13};

	lcd1.init(spi5, lcdCs, lcdDcx);
	ltdc.setClockEn(true);
	ltdc.init(lcd1.getSpec());
	ltdc.setIntEn(true);

	// DMA2D 초기화
	dma2d.setClockEn(true);
	dma2d.init();
	dma2d.setIntEn(true);

	// SPI4 초기화
	gpioE.setToAltFunc(2, altfunc::PE2_SPI4_CLK, ospeed::FAST, otype::PUSH_PULL);
	gpioE.setToAltFunc(5, altfunc::PE5_SPI4_MISO, ospeed::FAST, otype::PUSH_PULL);
	gpioE.setToAltFunc(6, altfunc::PE6_SPI4_MOSI, ospeed::FAST, otype::PUSH_PULL);

	spi4.setClockEn(true);
	spi4.init();
	spi4.setIntEn(true);

	// ILI9341 초기화
	gpioA.setToOutput(5, ospeed::FAST, otype::PUSH_PULL);
	gpioB.setToOutput(4, ospeed::FAST, otype::PUSH_PULL);

	const ILI9341::Config lcdConfig =
	{
		spi4,             // drv::Spi &peri;
		{&gpioA, 5},      // config::gpio::Set chipSelect;
		{&gpioB, 4},      // config::gpio::Set dataCommand;
		{0, 0},           // config::gpio::Set reset;
	};
	
	lcd2.setConfig(lcdConfig);
	lcd2.init();
	lcd2.setBmp565Brush(gBrush);
	lcd2.setDirection(true, false, false);
}
