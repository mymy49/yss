/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
/**
 * @file instance_gpio_nuvoton.cpp
 * @brief Global driver instances initialization for Nuvoton GPIO peripheral.
 */

#include <yss/instance.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY) || defined(__MA35H0_FAMILY)

const static Drv::setup_t gDrvSetupGpio =
{
	0,	// void (*clockFunc)(bool en);
	0,	// void (*nvicFunc)(bool en);
	0,	// void (*resetFunc)(void);
	0	// uint32_t (*getClockFunc)(void);
};



#if defined(PA) && defined(PA_EXIST)
static void enableGpioAInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
#if defined(__MA35H0_FAMILY)

#else
	nvic.enableInterrupt(GPA_IRQn, en);
#endif
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
#if defined(__M46x_SUBFAMILY)
	&SYS->GPA_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	(uint32_t*)&SYS->GPA_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPA_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPAB_MFOS,	// volatile uint32_t *mfos;
	false
#endif

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



#if defined(PB) && defined(PB_EXIST)
static void enableGpioBInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
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
	(uint32_t*)&SYS->GPB_MFPL,	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPB_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPAB_MFOS,	// volatile uint32_t *mfos;
	true
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
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
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
	(uint32_t*)&SYS->GPC_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPC_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPCD_MFOS,	// volatile uint32_t *mos;
	false
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
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
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
	(uint32_t*)&SYS->GPD_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPD_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPCD_MFOS,	// volatile uint32_t *mfos;
	true
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
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
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
	(uint32_t*)&SYS->GPE_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPE_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPEF_MFOS,	// volatile uint32_t *mfos;
	false
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
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
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
	(uint32_t*)&SYS->GPF_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPF_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPEF_MFOS,	// volatile uint32_t *mfos;
	true
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
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
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
	(uint32_t*)&SYS->GPG_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPG_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPGH_MFOS,	// volatile uint32_t *mfos;
	false
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
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
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
	(uint32_t*)&SYS->GPH_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPH_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPGH_MFOS,	// volatile uint32_t *mfos;
	true
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
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
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
	PI,				//YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPI_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	(uint32_t*)&SYS->GPI_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPI_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPIJ_MFOS,	// volatile uint32_t *mfos;
	false
#endif
};

Gpio gpioI(gDrvSetupGpioI, gConfigGpioI);

extern "C"
{
	void GPI_IRQHandler(void)
	{
		gpioI.isr();
	}
}
#endif



#if defined(PJ) && defined(PJ_EXIST)
static void enableGpioJInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
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
	(uint32_t*)&SYS->GPJ_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPJ_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPIJ_MFOS,	// volatile uint32_t *mfos;
	true
#endif
};

Gpio gpioJ(gDrvSetupGpioJ, gConfigGpioJ);

extern "C"
{
	void GPJ_IRQHandler(void)
	{
		gpioJ.isr();
	}
}
#endif

#if defined(PK) && defined(PK_EXIST)
static void enableGpioKInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
	nvic.enableInterrupt(GPK_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioK =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioKInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioK =
{
	PK,				//YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPJ_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	(uint32_t*)&SYS->GPK_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPK_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPKL_MFOS,	// volatile uint32_t *mfos;
	false
#endif
};

Gpio gpioK(gDrvSetupGpioK, gConfigGpioK);

extern "C"
{
	void GPK_IRQHandler(void)
	{
		gpioK.isr();
	}
}
#endif

#if defined(PL) && defined(PL_EXIST)
static void enableGpioLInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
	nvic.enableInterrupt(GPL_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioL =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioLInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioL =
{
	PL,				//YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPL_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	(uint32_t*)&SYS->GPL_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPL_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPKL_MFOS,	// volatile uint32_t *mfos;
	true
#endif
};

Gpio gpioL(gDrvSetupGpioL, gConfigGpioL);

extern "C"
{
	void GPL_IRQHandler(void)
	{
		gpioL.isr();
	}
}
#endif

#if defined(PM) && defined(PM_EXIST)
static void enableGpioMInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
	nvic.enableInterrupt(GPM_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioM =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioMInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioM =
{
	PM,				//YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPJ_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	(uint32_t*)&SYS->GPM_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPM_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPMN_MFOS,	// volatile uint32_t *mfos;
	false
#endif
};

Gpio gpioM(gDrvSetupGpioM, gConfigGpioM);

extern "C"
{
	void GPM_IRQHandler(void)
	{
		gpioM.isr();
	}
}
#endif

#if defined(PN) && defined(PN_EXIST)
static void enableGpioNInterrupt(bool en)
{
	// Mutex lock/unlock is not performed because interrupts are disabled internally within __enableInterrupt().
	nvic.enableInterrupt(GPN_IRQn, en);
}

const static Drv::setup_t gDrvSetupGpioN =
{
	0,						// void (*clockFunc)(bool en);
	enableGpioNInterrupt,	// void (*nvicFunc)(bool en);
	0,						// void (*resetFunc)(void);
	0						// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpioN =
{
	PN,				//YSS_GPIO_Peri *dev;
#if defined(__M46x_SUBFAMILY)
	&SYS->GPN_MFP0	// volatile uint32_t *mfp;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY) || defined(__M25x_FAMILY)
	(uint32_t*)&SYS->GPN_MFPL	// volatile uint32_t *mfp;
#elif defined(__MA35H0_FAMILY)
	(uint32_t*)&SYS->GPN_MFPL,	// volatile uint32_t *mfp;
	(uint32_t*)&SYS->GPMN_MFOS,	// volatile uint32_t *mfos;
	true
#endif
};

Gpio gpioN(gDrvSetupGpioN, gConfigGpioN);

extern "C"
{
	void GPN_IRQHandler(void)
	{
		gpioN.isr();
	}
}
#endif

#endif

