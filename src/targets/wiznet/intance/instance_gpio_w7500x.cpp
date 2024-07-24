/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(W7500)

//using namespace define::gpio;

const static Drv::setup_t gDrvSetupGpio =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

#if defined(GPIOA)
const static int8_t gPortAOutputAf[15] = {0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0};

const static Gpio::setup_t gConfigGpioA =
{
	GPIOA,			//YSS_GPIO_Peri *dev;
	AFC_PA,			//PORTX_TypeDef *afc;
	PADCON_PA,		//PORTX_TypeDef *padcon;
	gPortAOutputAf	//int8_t *outputAf;
};

Gpio gpioA(gDrvSetupGpio, gConfigGpioA);
#endif

#if defined(GPIOB)
const static int8_t gPortBOutputAf[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

const static Gpio::setup_t gConfigGpioB =
{
	GPIOB,			//YSS_GPIO_Peri *dev;
	AFC_PB,			//PORTX_TypeDef *afc;
	PADCON_PB,		//PORTX_TypeDef *padcon;
	gPortBOutputAf	//int8_t *outputAf;
};

Gpio gpioB(gDrvSetupGpio, gConfigGpioB);
#endif

#if defined(GPIOC)
const static int8_t gPortCOutputAf[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

const static Gpio::setup_t gConfigGpioC =
{
	GPIOC,			//YSS_GPIO_Peri *dev;
	AFC_PC,			//PORTX_TypeDef *afc;
	PADCON_PC,		//PORTX_TypeDef *padcon;
	gPortCOutputAf	//int8_t *outputAf;
};

Gpio gpioC(gDrvSetupGpio, gConfigGpioC);
#endif

#if defined(GPIOD)
const static int8_t gPortDOutputAf[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

const static Gpio::setup_t gConfigGpioD =
{
	GPIOD,			//YSS_GPIO_Peri *dev;
	AFC_PD,			//PORTX_TypeDef *afc;
	PADCON_PD,		//PORTX_TypeDef *padcon;
	gPortDOutputAf	//int8_t *outputAf;
};

Gpio gpioD(gDrvSetupGpio, gConfigGpioD);
#endif

#endif

