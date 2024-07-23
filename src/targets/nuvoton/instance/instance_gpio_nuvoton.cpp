/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)

const static Drv::setup_t gDrvSetupGpio =
{
	0,	// void (*clockFunc)(bool en);
	0,	// void (*nvicFunc)(bool en);
	0,	// void (*resetFunc)(void);
	0	// uint32_t (*getClockFunc)(void);
};



#if defined(PA)
const static Gpio::setup_t gConfigGpioA =
{
	PA,				// YSS_GPIO_Peri *dev;
	&SYS->GPA_MFPL	// volatile uint32_t *mfp;
};

Gpio gpioA(gDrvSetupGpio, gConfigGpioA);
#endif



#if defined(PB)
const static Gpio::setup_t gConfigGpioB =
{
	PB,				// YSS_GPIO_Peri *dev;
	&SYS->GPB_MFPL	// volatile uint32_t *mfp;
};

Gpio gpioB(gDrvSetupGpio, gConfigGpioB);
#endif



#if defined(PC)
const static Gpio::setup_t gConfigGpioC =
{
	PC,				// YSS_GPIO_Peri *dev;
	&SYS->GPC_MFPL	// volatile uint32_t *mfp;
};

Gpio gpioC(gDrvSetupGpio, gConfigGpioC);
#endif



#if defined(PD)
const static Gpio::setup_t gConfigGpioD =
{
	PD,				// YSS_GPIO_Peri *dev;
	&SYS->GPD_MFPL	// volatile uint32_t *mfp;
};

Gpio gpioD(gDrvSetupGpio, gConfigGpioD);
#endif



#if defined(PE)
const static Gpio::setup_t gConfigGpioE =
{
	PE,				// YSS_GPIO_Peri *dev;
	&SYS->GPE_MFPL	// volatile uint32_t *mfp;
};

Gpio gpioE(gDrvSetupGpio, gConfigGpioE);
#endif



#if defined(PH)
const static Gpio::setup_t gConfigGpioH =
{
	PH,				//YSS_GPIO_Peri *dev;
	&SYS->GPH_MFPL	// volatile uint32_t *mfp;
};

Gpio gpioH(gDrvSetupGpio, gConfigGpioH);
#endif

#endif

