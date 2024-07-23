/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(GD32F4) || defined(STM32L1)

#if defined(GPIOA)
Gpio gpioA((YSS_GPIO_Peri*)GPIOA, 0, 0, define::gpio::Exti::PORTA);
#endif

#if defined(GPIOB)
Gpio gpioB((YSS_GPIO_Peri*)GPIOB, 0, 0, define::gpio::Exti::PORTB);
#endif

#if defined(GPIOC)
Gpio gpioC((YSS_GPIO_Peri*)GPIOC, 0, 0, define::gpio::Exti::PORTC);
#endif

#if defined(GPIOD)
Gpio gpioD((YSS_GPIO_Peri*)GPIOD, 0, 0, define::gpio::Exti::PORTD);
#endif

#if defined(GPIOE)
Gpio gpioE((YSS_GPIO_Peri*)GPIOE, 0, 0, define::gpio::Exti::PORTE);
#endif

#if defined(GPIOF)
Gpio gpioF((YSS_GPIO_Peri*)GPIOF, 0, 0, define::gpio::Exti::PORTF);
#endif

#if defined(GPIOG)
Gpio gpioG((YSS_GPIO_Peri*)GPIOG, 0, 0, define::gpio::Exti::PORTG);
#endif

#if defined(GPIOH)
Gpio gpioH((YSS_GPIO_Peri*)GPIOH, 0, 0, define::gpio::Exti::PORTH);
#endif

#if defined(GPIOI)
Gpio gpioI((YSS_GPIO_Peri*)GPIOI, 0, 0, define::gpio::Exti::PORTI);
#endif

#elif defined(STM32F4) || defined(STM32F7) || defined(STM32F0) || defined (STM32F1) || defined(STM32G4)

const static Drv::setup_t gDrvSetupGpio =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

#if defined(GPIOA)
const static Gpio::setup_t gConfigGpioA =
{
	GPIOA,		//YSS_GPIO_Peri *dev;
	Exti::PORTA	//uint8_t port;
};

Gpio gpioA(gDrvSetupGpio, gConfigGpioA);
#endif

#if defined(GPIOB)
const static Gpio::setup_t gConfigGpioB =
{
	GPIOB,		//YSS_GPIO_Peri *dev;
	Exti::PORTB	//uint8_t port;
};

Gpio gpioB(gDrvSetupGpio, gConfigGpioB);
#endif

#if defined(GPIOC)
const static Gpio::setup_t gConfigGpioC =
{
	GPIOC,		//YSS_GPIO_Peri *dev;
	Exti::PORTC	//uint8_t port;
};

Gpio gpioC(gDrvSetupGpio, gConfigGpioC);
#endif

#if defined(GPIOD)
const static Gpio::setup_t gConfigGpioD =
{
	GPIOD,		//YSS_GPIO_Peri *dev;
	Exti::PORTD	//uint8_t port;
};

Gpio gpioD(gDrvSetupGpio, gConfigGpioD);
#endif

#if defined(GPIOE)
const static Gpio::setup_t gConfigGpioE =
{
	GPIOE,		//YSS_GPIO_Peri *dev;
	Exti::PORTE	//uint8_t port;
};

Gpio gpioE(gDrvSetupGpio, gConfigGpioE);
#endif

#if defined(GPIOF)
const static Gpio::setup_t gConfigGpioF =
{
	GPIOF,		//YSS_GPIO_Peri *dev;
	Exti::PORTF	//uint8_t port;
};

Gpio gpioF(gDrvSetupGpio, gConfigGpioF);
#endif

#if defined(GPIOG)
const static Gpio::setup_t gConfigGpioG =
{
	GPIOG,		//YSS_GPIO_Peri *dev;
	Exti::PORTG	//uint8_t port;
};

Gpio gpioG(gDrvSetupGpio, gConfigGpioG);
#endif

#if defined(GPIOH)
const static Gpio::setup_t gConfigGpioH =
{
	GPIOH,		//YSS_GPIO_Peri *dev;
	Exti::PORTH	//uint8_t port;
};

Gpio gpioH(gDrvSetupGpio, gConfigGpioH);
#endif

#if defined(GPIOI)
const static Gpio::setup_t gConfigGpioI =
{
	GPIOI,		//YSS_GPIO_Peri *dev;
	Exti::PORTI	//uint8_t port;
};

Gpio gpioI(gDrvSetupGpio, gConfigGpioI);
#endif



#if defined(GPIOJ)
const static Gpio::setup_t gConfigGpioJ =
{
	GPIOJ,		//YSS_GPIO_Peri *dev;
	Exti::PORTJ	//uint8_t port;
};

Gpio gpioJ(gDrvSetupGpio, gConfigGpioJ);
#endif



#if defined(GPIOK)
const static Drv::setup_t gDrvSetupGpioK =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioK =
{
	GPIOK,		//YSS_GPIO_Peri *dev;
	Exti::PORTK	//uint8_t port;
};

Gpio gpioK(gDrvSetupGpioK, gConfigGpioK);
#endif

#endif

