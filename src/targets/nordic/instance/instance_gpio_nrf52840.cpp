/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <yss/instance.h>

#if defined(NRF_P0)
static Drv::setup_t gDrvConfigGpioA =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

static Gpio::Config gConfigGpioA =
{
	NRF_P0,	//YSS_GPIO_Peri *peri;
	0,		//uint8_t exti
};

Gpio gpio0(gDrvConfigGpioA, gConfigGpioA);
#endif

#if defined(NRF_P1)
static Drv::setup_t gDrvConfigGpioB =
{
	0,	//void (*clockFunc)(bool en);
	0,	//void (*nvicFunc)(bool en);
	0,	//void (*resetFunc)(void);
	0	//uint32_t (*getClockFunc)(void);
};

static Gpio::Config gConfigGpioB =
{
	NRF_P1,	//YSS_GPIO_Peri *peri;
	0,		//uint8_t exti
};

Gpio gpio1(gDrvConfigGpioB, gConfigGpioB);
#endif

#endif
