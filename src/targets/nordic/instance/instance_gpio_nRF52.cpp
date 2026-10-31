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

#if defined(NRF52840_XXAA)

#include <yss/instance.h>

#pragma GCC optimize("O1")

#if defined(NRF_P0)
const static Drv::setup_t gDrvSetupGpio =
{
	0,	// void (*clockFunc)(bool en);
	0,	// void (*nvicFunc)(bool en);
	0,	// void (*resetFunc)(void);
	0	// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpio0 =
{
	NRF_P0	// NRF_GPIO_Type *dev;
};

Gpio gpio0(gDrvSetupGpio, gConfigGpio0);
#endif



#if defined(NRF_P1)
const static Drv::setup_t gDrvSetupGpi1 =
{
	0,	// void (*clockFunc)(bool en);
	0,	// void (*nvicFunc)(bool en);
	0,	// void (*resetFunc)(void);
	0	// uint32_t (*getClockFunc)(void);
};

const static Gpio::setup_t gConfigGpio1 =
{
	NRF_P1	// NRF_GPIO_Type *dev;
};

Gpio gpio1(gDrvSetupGpio, gConfigGpio1);
#endif

#endif

