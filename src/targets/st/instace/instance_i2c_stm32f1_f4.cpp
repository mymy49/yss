/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(STM32F4) || defined(STM32F1)

#include <config.h>
#include <yss.h>
#include <targets/st/bitfield.h>

#if I2C1_ENABLE || I2C2_ENABLE || I2C3_ENABLE
static uint32_t getApb1ClockFrequency(void)
{
	return clock.getApb1ClockFrequency();
}
#endif

#if defined(I2C1) && I2C1_ENABLE
static void enableI2c1Clock(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_I2C1EN_Pos, en);
	clock.unlock();
}

static void enableI2c1Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(I2C1_EV_IRQn, en);
	nvic.unlock();
}

static void resetI2c1(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_I2C1RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvI2c1Setup = 
{
	enableI2c1Clock,		//void (*clockFunc)(bool en);
	enableI2c1Interrupt,	//void (*nvicFunc)(bool en);
	resetI2c1,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const I2c::setup_t gI2c1Setup = 
{
	I2C1			//YSS_I2C_Peri *peri;
};

I2c i2c1(gDrvI2c1Setup, gI2c1Setup);

extern "C"
{
void I2C1_EV_IRQHandler(void)
{
	i2c1.isr();
}
}
#endif



#if defined(I2C2) && I2C2_ENABLE
static void enableI2c2Clock(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_I2C2EN_Pos, en);
	clock.unlock();
}

static void enableI2c2Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(I2C2_EV_IRQn, en);
	nvic.unlock();
}

static void resetI2c2(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_I2C2RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvI2c2Setup = 
{
	enableI2c2Clock,		//void (*clockFunc)(bool en);
	enableI2c2Interrupt,	//void (*nvicFunc)(bool en);
	resetI2c2,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const I2c::setup_t gI2c2Setup = 
{
	I2C2			//YSS_I2C_Peri *peri;
};

I2c i2c2(gDrvI2c2Setup, gI2c2Setup);

extern "C"
{
void I2C2_EV_IRQHandler(void)
{
	i2c2.isr();
}
}
#endif



#if defined(I2C3) && I2C3_ENABLE
static void enableI2c3Clock(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_I2C3EN_Pos, en);
	clock.unlock();
}

static void enableI2c3Interrupt(bool en)
{
	nvic.lock();
	nvic.enableInterrupt(I2C3_EV_IRQn, en);
	nvic.unlock();
}

static void resetI2c3(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_I2C3RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvI2c3Setup = 
{
	enableI2c3Clock,		//void (*clockFunc)(bool en);
	enableI2c3Interrupt,	//void (*nvicFunc)(bool en);
	resetI2c3,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const I2c::setup_t gI2c3Setup = 
{
	I2C3			//YSS_I2C_Peri *peri;
};

I2c i2c3(gDrvI2c3Setup, gI2c3Setup);

extern "C"
{
void I2C3_EV_IRQHandler(void)
{
	i2c3.isr();
}
}
#endif

#endif

