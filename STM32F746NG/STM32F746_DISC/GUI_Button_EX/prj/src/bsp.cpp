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
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <mod/ctouch/FT5336.h>
#include <mod/sdram/MT48LC4M32B2B5_6A.h>
#include <mod/tft/RK043FN48H.h>
#include <yss/instance.h>

void initSdram(void)
{
	using namespace define::gpio::altfunc;

	drv::Gpio::AltFunc sdramPort[38]{
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
		{GPIOH, 5, PH5_FMC_SDNWE},
		{GPIOF, 11, PF11_FMC_SDNRAS},
		{GPIOG, 15, PG15_FMC_SDNCAS},
		{GPIOC, 3, PC3_FMC_SDCKE0},
		{GPIOH, 3, PH3_FMC_SDNE0}
	};

	gpioA.setPackageAsAltFunc(sdramPort, 38, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);

	clock.peripheral.setFmcEn(true);
	sdram.init(define::sdram::bank::BANK1, mod::sdram::MT48LC4M32B2B5_6A);
}

namespace bsp
{
mod::tft::RK043FN48H lcd;
mod::ctouch::FT5336 ft5336;

void init(void)
{
	using namespace define::gpio;

	// TFT LCD 초기화
	drv::Gpio::AltFunc lcdPort[28] =
		{
			{GPIOJ, 6, altfunc::PJ6_LCD_R7},
			{GPIOJ, 5, altfunc::PJ5_LCD_R6},
			{GPIOJ, 4, altfunc::PJ4_LCD_R5},
			{GPIOJ, 3, altfunc::PJ3_LCD_R4},
			{GPIOJ, 2, altfunc::PJ2_LCD_R3},
			{GPIOJ, 1, altfunc::PJ1_LCD_R2},
			{GPIOJ, 0, altfunc::PJ0_LCD_R1},
			{GPIOI, 15, altfunc::PI15_LCD_R0},

			{GPIOK, 2, altfunc::PK2_LCD_G7},
			{GPIOK, 1, altfunc::PK1_LCD_G6},
			{GPIOK, 0, altfunc::PK0_LCD_G5},
			{GPIOJ, 11, altfunc::PJ11_LCD_G4},
			{GPIOJ, 10, altfunc::PJ10_LCD_G3},
			{GPIOJ, 9, altfunc::PJ9_LCD_G2},
			{GPIOJ, 8, altfunc::PJ8_LCD_G1},
			{GPIOJ, 7, altfunc::PJ7_LCD_G0},

			{GPIOK, 6, altfunc::PK6_LCD_B7},
			{GPIOK, 5, altfunc::PK5_LCD_B6},
			{GPIOK, 4, altfunc::PK4_LCD_B5},
			{GPIOG, 12, altfunc::PG12_LCD_B4},
			{GPIOJ, 15, altfunc::PJ15_LCD_B3},
			{GPIOJ, 14, altfunc::PJ14_LCD_B2},
			{GPIOJ, 13, altfunc::PJ13_LCD_B1},
			{GPIOE, 4, altfunc::PE4_LCD_B0},

			{GPIOI, 9, altfunc::PI9_LCD_VSYNC},
			{GPIOI, 10, altfunc::PI10_LCD_HSYNC},
			{GPIOK, 7, altfunc::PK7_LCD_DE},
			{GPIOI, 14, altfunc::PI14_LCD_CLK}
		};

	gpioA.setPackageAsAltFunc(lcdPort, 28, ospeed::FAST, otype::PUSH_PULL);
	gpioI.setAsOutput(12, ospeed::LOW, otype::PUSH_PULL);
	gpioI.setOutput(12, true);

	bsp::lcd.init();
	ltdc.setClockEn(true);
	ltdc.init(lcd.getConfig());
	ltdc.setIntEn(true);

	// DMA2D 초기화
	dma2d.setClockEn(true);
	dma2d.init();
	dma2d.setIntEn(true);

	// I2C3 초기화
	gpioH.setAsAltFunc(7, altfunc::PH7_I2C3_SCL, ospeed::LOW, otype::OPEN_DRAIN);
	gpioH.setAsAltFunc(8, altfunc::PH8_I2C3_SDA, ospeed::LOW, otype::OPEN_DRAIN);

	i2c3.setClockEn(true);
	i2c3.init(define::i2c::speed::STANDARD);
	i2c3.setIntEn(true);

	drv::Gpio::Pin touchIsr = {&gpioI, 13};

	ft5336.init(i2c3, touchIsr);

	////UART Init
	gpioA.setAsAltFunc(9, altfunc::PA9_USART1_TX, ospeed::MID, otype::PUSH_PULL);
	gpioB.setAsAltFunc(7, altfunc::PB7_USART1_RX, ospeed::MID, otype::PUSH_PULL);

	uart1.setClockEn(true);
	uart1.init(9600, 1024);
	uart1.setIntEn(true);
}
}