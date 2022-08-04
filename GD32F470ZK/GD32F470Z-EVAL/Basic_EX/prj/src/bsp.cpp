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

#include <__cross_studio_io.h>
#include <yss/yss.h>
#include <bsp.h>
#include <yss/reg.h>
#include <mod/sdram/MT48LC16M16A2_6A.h>

GD32_RGB_LCD lcd;

void initBoard(void)
{
	using namespace define::gpio;

	//UART 초기화 9600 baudrate, 수신 링버퍼 크기는 512 바이트
	gpioA.setAsAltFunc(9, altfunc::PA9_USART0_TX);
	gpioA.setAsAltFunc(10, altfunc::PA10_USART0_RX);
	
	uart0.setClockEn(true);
	uart0.init(9600, 512);
	uart0.setInterruptEn(true);

	// LED 초기화
	gpioD.setAsOutput(4);
	gpioD.setAsOutput(5);
	gpioG.setAsOutput(3);

	// LCD 초기화
	gpioB.setAsAltFunc(0, altfunc::PB0_LCD_R3, ospeed::MID, otype::PUSH_PULL);
	gpioA.setAsAltFunc(11, altfunc::PA11_LCD_R4, ospeed::MID, otype::PUSH_PULL);
	gpioA.setAsAltFunc(12, altfunc::PA12_LCD_R5, ospeed::MID, otype::PUSH_PULL);
	gpioA.setAsAltFunc(8, altfunc::PA8_LCD_R6, ospeed::MID, otype::PUSH_PULL);
	gpioG.setAsAltFunc(6, altfunc::PG6_LCD_R7, ospeed::MID, otype::PUSH_PULL);

	gpioA.setAsAltFunc(6, altfunc::PA6_LCD_G2, ospeed::MID, otype::PUSH_PULL);
	gpioG.setAsAltFunc(10, altfunc::PG10_LCD_G3, ospeed::MID, otype::PUSH_PULL);
	gpioB.setAsAltFunc(10, altfunc::PB10_LCD_G4, ospeed::MID, otype::PUSH_PULL);
	gpioB.setAsAltFunc(11, altfunc::PB11_LCD_G5, ospeed::MID, otype::PUSH_PULL);
	gpioC.setAsAltFunc(7, altfunc::PC7_LCD_G6, ospeed::MID, otype::PUSH_PULL);
	gpioD.setAsAltFunc(3, altfunc::PD3_LCD_G7, ospeed::MID, otype::PUSH_PULL);

	gpioG.setAsAltFunc(11, altfunc::PG11_LCD_B3, ospeed::MID, otype::PUSH_PULL);
	gpioG.setAsAltFunc(12, altfunc::PG12_LCD_B4, ospeed::MID, otype::PUSH_PULL);
	gpioA.setAsAltFunc(3, altfunc::PA3_LCD_B5, ospeed::MID, otype::PUSH_PULL);
	gpioB.setAsAltFunc(8, altfunc::PB8_LCD_B6, ospeed::MID, otype::PUSH_PULL);
	gpioB.setAsAltFunc(9, altfunc::PB9_LCD_B7, ospeed::MID, otype::PUSH_PULL);

	gpioA.setAsAltFunc(4, altfunc::PA4_LCD_VSYNC, ospeed::MID, otype::PUSH_PULL);
	gpioC.setAsAltFunc(6, altfunc::PC6_LCD_HSYNC, ospeed::MID, otype::PUSH_PULL);
	gpioF.setAsAltFunc(10, altfunc::PF10_LCD_DE, ospeed::MID, otype::PUSH_PULL);
	gpioG.setAsAltFunc(7, altfunc::PG7_LCD_CLK, ospeed::MID, otype::PUSH_PULL);
	
	gpioD.setAsOutput(11);
	gpioE.setAsOutput(3);
	gpioG.setAsOutput(13);
	gpioG.setAsOutput(14);

	GD32_RGB_LCD::Config lcdConfig =
	{
		{&gpioG, 14},	//Gpio::Pin mosi;
		{&gpioG, 13},	//Gpio::Pin sck;
		{&gpioD, 11},	//Gpio::Pin chipSelect;
		{&gpioE, 3},	//Gpio::Pin dataCommand;
		{0, 0}			//Gpio::Pin reset;
	};
	
	lcd.setConfig(lcdConfig);
	lcd.init();

	lcd.init();
	ltdc.setClockEn(true);
	ltdc.init(lcd.getSpecification());
	ltdc.setInterruptEn(true);
}

void initSdram(void)
{
	using namespace define::gpio::altfunc;

	Gpio::AltFunc sdramPort[39]{
		{(YSS_GPIO_Peri*)GPIOF, 0, PF0_FMC_A0},
		{(YSS_GPIO_Peri*)GPIOF, 1, PF1_FMC_A1},
		{(YSS_GPIO_Peri*)GPIOF, 2, PF2_FMC_A2},
		{(YSS_GPIO_Peri*)GPIOF, 3, PF3_FMC_A3},
		{(YSS_GPIO_Peri*)GPIOF, 4, PF4_FMC_A4},
		{(YSS_GPIO_Peri*)GPIOF, 5, PF5_FMC_A5},
		{(YSS_GPIO_Peri*)GPIOF, 12, PF12_FMC_A6},
		{(YSS_GPIO_Peri*)GPIOF, 13, PF13_FMC_A7},
		{(YSS_GPIO_Peri*)GPIOF, 14, PF14_FMC_A8},
		{(YSS_GPIO_Peri*)GPIOF, 15, PF15_FMC_A9},
		{(YSS_GPIO_Peri*)GPIOG, 0, PG0_FMC_A10},
		{(YSS_GPIO_Peri*)GPIOG, 1, PG1_FMC_A11},
		{(YSS_GPIO_Peri*)GPIOG, 2, PG2_FMC_A12},

		{(YSS_GPIO_Peri*)GPIOG, 4, PG4_FMC_BA0},
		{(YSS_GPIO_Peri*)GPIOG, 5, PG5_FMC_BA1},

		{(YSS_GPIO_Peri*)GPIOD, 14, PD14_FMC_D0},
		{(YSS_GPIO_Peri*)GPIOD, 15, PD15_FMC_D1},
		{(YSS_GPIO_Peri*)GPIOD, 0, PD0_FMC_D2},
		{(YSS_GPIO_Peri*)GPIOD, 1, PD1_FMC_D3},
		{(YSS_GPIO_Peri*)GPIOE, 7, PE7_FMC_D4},
		{(YSS_GPIO_Peri*)GPIOE, 8, PE8_FMC_D5},
		{(YSS_GPIO_Peri*)GPIOE, 9, PE9_FMC_D6},
		{(YSS_GPIO_Peri*)GPIOE, 10, PE10_FMC_D7},
		{(YSS_GPIO_Peri*)GPIOE, 11, PE11_FMC_D8},
		{(YSS_GPIO_Peri*)GPIOE, 12, PE12_FMC_D9},
		{(YSS_GPIO_Peri*)GPIOE, 13, PE13_FMC_D10},
		{(YSS_GPIO_Peri*)GPIOE, 14, PE14_FMC_D11},
		{(YSS_GPIO_Peri*)GPIOE, 15, PE15_FMC_D12},
		{(YSS_GPIO_Peri*)GPIOD, 8, PD8_FMC_D13},
		{(YSS_GPIO_Peri*)GPIOD, 9, PD9_FMC_D14},
		{(YSS_GPIO_Peri*)GPIOD, 10, PD10_FMC_D15},

		{(YSS_GPIO_Peri*)GPIOE, 0, PE0_FMC_NBL0},
		{(YSS_GPIO_Peri*)GPIOE, 1, PE1_FMC_NBL1},
		{(YSS_GPIO_Peri*)GPIOG, 8, PG8_FMC_SDCLK},
		{(YSS_GPIO_Peri*)GPIOC, 0, PC0_FMC_SDNWE},
		{(YSS_GPIO_Peri*)GPIOF, 11, PF11_FMC_SDNRAS},
		{(YSS_GPIO_Peri*)GPIOG, 15, PG15_FMC_SDNCAS},
		{(YSS_GPIO_Peri*)GPIOC, 3, PC3_FMC_SDCKE0},
		{(YSS_GPIO_Peri*)GPIOC, 2, PC2_FMC_SDNE0}
	};

	gpioA.setPackageAsAltFunc(sdramPort, 39, define::gpio::ospeed::FAST, define::gpio::otype::PUSH_PULL);
	
	clock.peripheral.setFmcEn(true);
	sdram.init(define::sdram::bank::BANK1, MT48LC16M16A2_6A);
}

/*
void initSystem(void)
{
	clock.peripheral.setPwrEn(true);
	clock.enableHse(HSE_CLOCK_FREQ);

	using namespace define::clock;

	clock.enableMainPll(
		pll::src::HSE,				// unsigned char src
		HSE_CLOCK_FREQ / 1000000,	// unsigned char m
		360,						// unsigned short n
		pll::pdiv::DIV2,			// unsigned char pDiv
		pll::qdiv::DIV8,			// unsigned char qDiv
		0							// unsigned char rDiv
	);

	clock.enableSaiPll(
		96,						// unsigned short n
		saipll::pdiv::DIV2,			// unsigned char pDiv / 48 MHz Source
		0,							// unsigned char qDiv / 아무 효과 없음
		saipll::rdiv::DIV7			// unsigned char rDiv / LCD Source
	);

	clock.setSysclk(
		sysclk::src::PLL,		// unsigned char sysclkSrc;
		divFactor::ahb::NO_DIV, // unsigned char ahb;
		divFactor::apb::DIV4,	// unsigned char apb1;
		divFactor::apb::DIV2	// unsigned char apb2;
	);

	clock.peripheral.setGpioAEn(true);
	clock.peripheral.setGpioBEn(true);
	clock.peripheral.setGpioCEn(true);
	clock.peripheral.setGpioDEn(true);
	clock.peripheral.setGpioEEn(true);
	clock.peripheral.setGpioFEn(true);
	clock.peripheral.setGpioGEn(true);
	clock.peripheral.setGpioHEn(true);
	clock.peripheral.setGpioIEn(true);
}
*/

