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

#include <drv/peripherals.h>
#include <mod/sdram/MT48LC4M32B2B5_6A.h>
#include <mod/tft/RK043FN48H.h>
#include <mod/ctouch/FT5336.h>

void initSdram(void)
{
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

	gpioA.setToAltFunc(sdramPort, 38, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);

	clock.peripheral.setFmcEn(true);
	sdram.init(define::sdram::bank::BANK1,	mod::sdram::MT48LC4M32B2B5_6A);
}

namespace bsp
{
	mod::tft::RK043FN48H lcd;
	mod::ctouch::FT5336 ft5336;

	void init(void)
	{
		using namespace define::gpio;

		// TFT LCD 초기화
		config::gpio::AltFunc lcdPort[28] =
		{
			{GPIOJ, 6, altfunc::LCD_AF14},	//	R7
			{GPIOJ, 5, altfunc::LCD_AF14},	//	R6
			{GPIOJ, 4, altfunc::LCD_AF14},	//	R5
			{GPIOJ, 3, altfunc::LCD_AF14},	//	R4
			{GPIOJ, 2, altfunc::LCD_AF14},	//	R3
			{GPIOJ, 1, altfunc::LCD_AF14},	//	R2
			{GPIOJ, 0, altfunc::LCD_AF14},	//	R1
			{GPIOI, 15, altfunc::LCD_AF14},	//	R0

			{GPIOK, 2, altfunc::LCD_AF14},	//	G7
			{GPIOK, 1, altfunc::LCD_AF14},	//	G6
			{GPIOK, 0, altfunc::LCD_AF14},	//	G5
			{GPIOJ, 11, altfunc::LCD_AF14},	//	G4
			{GPIOJ, 10, altfunc::LCD_AF14},	//	G3
			{GPIOJ, 9, altfunc::LCD_AF14},	//	G2
			{GPIOJ, 8, altfunc::LCD_AF14},	//	G1
			{GPIOJ, 7, altfunc::LCD_AF14},	//	G0

			{GPIOK, 6, altfunc::LCD_AF14},	//	B7
			{GPIOK, 5, altfunc::LCD_AF14},	//	B6
			{GPIOK, 4, altfunc::LCD_AF14},	//	B5
			{GPIOG, 12, altfunc::LCD_AF9},	//	B4
			{GPIOJ, 15, altfunc::LCD_AF14},	//	B3
			{GPIOJ, 14, altfunc::LCD_AF14},	//	B2
			{GPIOJ, 13, altfunc::LCD_AF14},	//	B1
			{GPIOE, 4, altfunc::LCD_AF14},	//	B0

			{GPIOI, 9, altfunc::LCD_AF14},	//	VSYNC
			{GPIOI, 10, altfunc::LCD_AF14},	//	HSYNC
			{GPIOK, 7, altfunc::LCD_AF14},	//	ENABLE
			{GPIOI, 14, altfunc::LCD_AF14}	//	CLOCK
		};

		gpioA.setToAltFunc(lcdPort, 28, ospeed::FAST, otype::PUSH_PULL);
		gpioI.setToOutput(12, ospeed::LOW, otype::PUSH_PULL);
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
		gpioH.setToAltFunc(7, altfunc::I2C3_AF4, ospeed::LOW, otype::OPEN_DRAIN);
		gpioH.setToAltFunc(8, altfunc::I2C3_AF4, ospeed::LOW, otype::OPEN_DRAIN);

		i2c3.setClockEn(true);
		i2c3.init(define::i2c::speed::STANDARD);
		i2c3.setIntEn(true);

		config::gpio::Set touchIsr = {&gpioI, 13};

		ft5336.init(i2c3, touchIsr);

		////UART Init
		gpioA.setToAltFunc(9, altfunc::USART1_AF7, ospeed::MID, otype::PUSH_PULL);
		gpioB.setToAltFunc(7, altfunc::USART1_AF7, ospeed::MID, otype::PUSH_PULL);

		uart1.setClockEn(true);
		uart1.init(9600, 1024);
		uart1.setIntEn(true);
	}
}

