/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(EFM32PG22) || defined(EFR32BG22)

#if defined(EFM32PG22)
#include <targets/siliconlabs/efm32pg22_cmu.h>
#elif defined(EFR32BG22)
#include <targets/siliconlabs/efr32bg22_cmu.h>
#endif

#if defined(GPIO_PA_INDEX)
const static Drv::setup_t gDrvSetupGpioA =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

const static Gpio::Setup gSetupGpioA =
{
	GPIO_S,			//YSS_GPIO_Peri *dev;
	Gpio::PORTA,	//uint8_t port;
	GPIO_PA_COUNT	//uint8_t pinCount;
};

Gpio gpioA(gDrvSetupGpioA, gSetupGpioA);
#endif

#if defined(GPIO_PB_INDEX)
const static Drv::setup_t gDrvSetupGpioB =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

const static Gpio::Setup gSetupGpioB =
{
	GPIO_S,			//YSS_GPIO_Peri *dev;
	Gpio::PORTB,	//uint8_t port;
	GPIO_PB_COUNT	//uint8_t pinCount;
};

Gpio gpioB(gDrvSetupGpioB, gSetupGpioB);
#endif

#if defined(GPIO_PC_INDEX)
const static Drv::setup_t gDrvSetupGpioC =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

const static Gpio::Setup gSetupGpioC =
{
	GPIO_S,			//YSS_GPIO_Peri *dev;
	Gpio::PORTC,	//uint8_t port;
	GPIO_PC_COUNT	//uint8_t pinCount;
};

Gpio gpioC(gDrvSetupGpioC, gSetupGpioC);
#endif

#if defined(GPIO_PD_INDEX)
const static Drv::setup_t gDrvSetupGpioD =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

const static Gpio::Setup gSetupGpioD =
{
	GPIO_S,			//YSS_GPIO_Peri *dev;
	Gpio::PORTD,	//uint8_t port;
	GPIO_PD_COUNT	//uint8_t pinCount;
};

Gpio gpioD(gDrvSetupGpioD, gSetupGpioD);
#endif

#endif

