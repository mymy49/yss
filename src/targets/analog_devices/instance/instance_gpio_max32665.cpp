/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
/**
 * @file instance_gpio_nuvoton.cpp
 * @brief Global driver instances initialization for Nuvoton GPIO peripheral.
 */

#include <yss/instance.h>

#if defined(__MAX32665_FAMILY)

const static Drv::setup_t gDrvSetupGpio =
{
	0,	// void (*clockFunc)(bool en);
	0,	// void (*nvicFunc)(bool en);
	0,	// void (*resetFunc)(void);
	0	// uint32_t (*getClockFunc)(void);
};

static void enableGpioAInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	//nvic.enableInterrupt(GPA_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioA =
{
	0,						// void (*clockFunc)(bool en);
	0,						// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioA =
{
	MXC_GPIO0,		// YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPA_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	&SYS->GPA_MFPL	// volatile uint32_t *mfp;
#endif

};

Gpio gpio0(gDrvSetupGpioA, gConfigGpioA);

extern "C"
{
	void GPA_IRQHandler(void)
	{
		gpio0.isr();
	}
}

#if defined(PB) && defined(PB_EXIST)
static void enableGpioBInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(GPB_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioB =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioBInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioB =
{
	PB,				// YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPB_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	&SYS->GPB_MFPL	// volatile uint32_t *mfp;
#endif
};

Gpio gpioB(gDrvSetupGpioB, gConfigGpioB);

extern "C"
{
	void GPB_IRQHandler(void)
	{
		gpioB.isr();
	}
}
#endif



#if defined(PC) && defined(PC_EXIST)
static void enableGpioCInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(GPC_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioC =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioCInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioC =
{
	PC,				// YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPC_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	&SYS->GPC_MFPL	// volatile uint32_t *mfp;
#endif
};

Gpio gpioC(gDrvSetupGpioC, gConfigGpioC);

extern "C"
{
	void GPC_IRQHandler(void)
	{
		gpioC.isr();
	}
}
#endif



#if defined(PD) && defined(PD_EXIST)
static void enableGpioDInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(GPD_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioD =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioDInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioD =
{
	PD,				// YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPD_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	&SYS->GPD_MFPL	// volatile uint32_t *mfp;
#endif
};

Gpio gpioD(gDrvSetupGpioD, gConfigGpioD);

extern "C"
{
	void GPD_IRQHandler(void)
	{
		gpioD.isr();
	}
}
#endif



#if defined(PE) && defined(PE_EXIST)
static void enableGpioEInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(GPE_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioE =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioEInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioE =
{
	PE,				// YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPE_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	&SYS->GPE_MFPL	// volatile uint32_t *mfp;
#endif
};

Gpio gpioE(gDrvSetupGpioE, gConfigGpioE);

extern "C"
{
	void GPE_IRQHandler(void)
	{
		gpioE.isr();
	}
}
#endif



#if defined(PF) && defined(PF_EXIST)
static void enableGpioFInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(GPF_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioF =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioFInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioF =
{
	PF,				// YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPF_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	&SYS->GPF_MFPL	// volatile uint32_t *mfp;
#endif
};

Gpio gpioF(gDrvSetupGpioF, gConfigGpioF);

extern "C"
{
	void GPF_IRQHandler(void)
	{
		gpioF.isr();
	}
}
#endif



#if defined(PG) && defined(PG_EXIST)
static void enableGpioGInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(GPG_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioG =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioGInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioG =
{
	PG,				// YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPG_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	&SYS->GPG_MFPL	// volatile uint32_t *mfp;
#endif
};

Gpio gpioG(gDrvSetupGpioG, gConfigGpioG);

extern "C"
{
	void GPG_IRQHandler(void)
	{
		gpioG.isr();
	}
}
#endif



#if defined(PH) && defined(PH_EXIST)
static void enableGpioHInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(GPH_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioH =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioHInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioH =
{
	PH,				//YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPH_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	&SYS->GPH_MFPL	// volatile uint32_t *mfp;
#endif
};

Gpio gpioH(gDrvSetupGpioH, gConfigGpioH);

extern "C"
{
	void GPH_IRQHandler(void)
	{
		gpioH.isr();
	}
}
#endif



#if defined(PI) && defined(PI_EXIST)
static void enableGpioIInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(GPI_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioI =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioIInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioI =
{
	PH,				//YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPI_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	&SYS->GPI_MFPL	// volatile uint32_t *mfp;
#endif
};

Gpio gpioI(gDrvSetupGpioH, gConfigGpioH);

extern "C"
{
	void GPI_IRQHandler(void)
	{
		gpioH.isr();
	}
}
#endif



#if defined(PJ) && defined(PJ_EXIST)
static void enableGpioJInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within enableInterrupt().
	nvic.enableInterrupt(GPJ_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioJ =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioJInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioJ =
{
	PJ,				//YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPJ_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	&SYS->GPJ_MFPL	// volatile uint32_t *mfp;
#endif
};

Gpio gpioJ(gDrvSetupGpioH, gConfigGpioH);

extern "C"
{
	void GPJ_IRQHandler(void)
	{
		gpioH.isr();
	}
}
#endif

#endif

