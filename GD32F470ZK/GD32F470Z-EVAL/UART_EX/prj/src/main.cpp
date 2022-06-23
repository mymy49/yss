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
#include <string.h>
#include <yss/yss.h>
#include <util/time.h>
#include <util/Period.h>
#include <mod/tft/SF_TC240T_9370_T.h>
#include <mod/sdram/MT48LC16M16A2_6A.h>
#include <mod/rgb_tft_lcd/GD32_RGB_LCD.h>

void init(void);
void thread_handleLed1(void);
void thread_handleLed2(void);
void thread_handleLed3(void);

GD32_RGB_LCD lcd;
SF_TC240T_9370_T lcd2;

void thread_uart1Rx(void)
{
	unsigned char data;
	while (1)
	{
		data = uart0.getWaitUntilReceive();
		debug_printf("0x%02x\n", data);
	}
}

int main(void)
{
	yss::init();
	init();

	thread::add(thread_uart1Rx, 1024);
	thread::add(thread_handleLed1, 1024);
	thread::add(thread_handleLed2, 1024);
	thread::add(thread_handleLed3, 1024);

	const char *str = "hello world!!\n\r";

	while (1)
	{
		debug_printf("%d\r", time::getRunningMsec());
		uart0.send(str, strlen(str));
	}
	return 0;
}

void init(void)
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
	gpioB.setAsAltFunc(0, altfunc::PB0_LCD_R3, ospeed::FAST, otype::PUSH_PULL);
	gpioA.setAsAltFunc(11, altfunc::PA11_LCD_R4, ospeed::FAST, otype::PUSH_PULL);
	gpioA.setAsAltFunc(12, altfunc::PA12_LCD_R5, ospeed::FAST, otype::PUSH_PULL);
	gpioA.setAsAltFunc(8, altfunc::PA8_LCD_R6, ospeed::FAST, otype::PUSH_PULL);
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
	
	gpioD.setAsOutput(11);
	gpioE.setAsOutput(3);
	gpioG.setAsOutput(13);
	gpioG.setAsOutput(14);

	GD32_RGB_LCD::Config lcdConfig =
	{
		{&gpioG, 14},	//drv::Gpio::Pin mosi;
		{&gpioG, 13},	//drv::Gpio::Pin sck;
		{&gpioD, 11},	//drv::Gpio::Pin chipSelect;
		{&gpioE, 3},	//drv::Gpio::Pin dataCommand;
		{0, 0}			//drv::Gpio::Pin reset;
	};
	
	lcd.setConfig(lcdConfig);
	lcd.init();

	lcd.init();
	ltdc.setClockEn(true);
	ltdc.init(lcd.getSpecification());
	ltdc.setInterruptEn(true);
}

void thread_handleLed1(void)
{
	Period period(250000);
	
	while(1)
	{
		period.wait();
		gpioD.setOutput(4, true);

		period.wait();
		gpioD.setOutput(4, false);
	}
}

void thread_handleLed2(void)
{
	Period period(500000);
	
	while(1)
	{
		period.wait();
		gpioD.setOutput(5, true);

		period.wait();
		gpioD.setOutput(5, false);
	}
}

void thread_handleLed3(void)
{
	Period period(1000000);
	
	while(1)
	{
		period.wait();
		gpioG.setOutput(3, true);

		period.wait();
		gpioG.setOutput(3, false);
	}
}

void initSdram(void)
{
	using namespace define::gpio::altfunc;

	drv::Gpio::AltFunc sdramPort[39]{
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
