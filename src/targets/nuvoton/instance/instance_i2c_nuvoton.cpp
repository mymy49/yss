/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/nuvoton/bitfield_m4xx.h>



#if I2C0_ENABLE && defined(I2C0)
static void enableI2c0Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_I2C0CKEN_Pos, en);
}

static void enableI2c0Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(I2C0_IRQn, en);
}

static void resetI2c0(void)
{
}

static uint32_t getI2c0ClockFrequency(void)
{
	return clock.getApb0ClockFrequency();
}

static const Drv::setup_t gDrvI2c0Setup = 
{
	enableI2c0Clock,		//void (*clockFunc)(bool en);
	enableI2c0Interrupt,	//void (*nvicFunc)(bool en);
	resetI2c0,				//void (*resetFunc)(void);
	getI2c0ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const I2c::setup_t gI2c0Setup = 
{
	I2C0			//YSS_SPI_Peri *peri;
};

I2c i2c0(gDrvI2c0Setup, gI2c0Setup);

extern "C"
{
	void I2C0_IRQHandler(void)
	{
		i2c0.isr();
	}
}

#endif



#if I2C1_ENABLE && defined(I2C1)
static void enableI2c1Clock(bool en)
{
	// enableApb0Clock() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	clock.enableApb0Clock(CLK_APBCLK0_I2C1CKEN_Pos, en);
}

static void enableI2c1Interrupt(bool en)
{
	// enableInterrupt() 함수 내부에서 인터럽트를 끄기 때문에 Mutex lock(), unlock()을 하지 않음.
	nvic.enableInterrupt(I2C1_IRQn, en);
}

static void resetI2c1(void)
{
}

static uint32_t getI2c1ClockFrequency(void)
{
	return clock.getApb1ClockFrequency();
}

static const Drv::setup_t gDrvI2c1Setup = 
{
	enableI2c1Clock,		//void (*clockFunc)(bool en);
	enableI2c1Interrupt,	//void (*nvicFunc)(bool en);
	resetI2c1,				//void (*resetFunc)(void);
	getI2c1ClockFrequency	//uint32_t (*getClockFreq)(void);
};

static const I2c::setup_t gI2c1Setup = 
{
	I2C1			//YSS_SPI_Peri *peri;
};

I2c i2c1(gDrvI2c1Setup, gI2c1Setup);

extern "C"
{
	void I2C1_IRQHandler(void)
	{
		i2c1.isr();
	}
}

#endif

#endif

