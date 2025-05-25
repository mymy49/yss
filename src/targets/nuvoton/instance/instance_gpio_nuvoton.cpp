/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

const static Drv::setup_t gDrvSetupGpio =
{
	0,	// void (*clockFunc)(bool en);
	0,	// void (*nvicFunc)(bool en);
	0,	// void (*resetFunc)(void);
	0	// uint32_t (*getClockFunc)(void);
};



#if defined(PA)
static void enableGpioAInterrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(GPA_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioA =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioAInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioA =
{
	PA,				// YSS_GPIO_Peri *dev;
	&SYS->GPA_MFPL	// volatile uint32_t *mfp;
};

Gpio gpioA(gDrvSetupGpioA, gConfigGpioA);

extern "C"
{
	void GPA_IRQHandler(void)
	{
		gpioA.isr();
	}
}
#endif



#if defined(PB)
static void enableGpioBInterrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
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
	&SYS->GPB_MFPL	// volatile uint32_t *mfp;
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



#if defined(PC)
static void enableGpioCInterrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
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
	&SYS->GPC_MFPL	// volatile uint32_t *mfp;
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



#if defined(PD)
static void enableGpioDInterrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
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
	&SYS->GPD_MFPL	// volatile uint32_t *mfp;
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



#if defined(PE)
static void enableGpioEInterrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
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
	&SYS->GPE_MFPL	// volatile uint32_t *mfp;
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



#if defined(PF)
static void enableGpioFInterrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(GPF_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioF =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioEInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioF =
{
	PF,				// YSS_GPIO_Peri *dev;
	&SYS->GPF_MFPL	// volatile uint32_t *mfp;
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



#if defined(PG)
static void enableGpioGInterrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
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
	&SYS->GPG_MFPL	// volatile uint32_t *mfp;
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



#if defined(PH)
static void enableGpioHInterrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
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
	&SYS->GPH_MFPL	// volatile uint32_t *mfp;
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

#endif

