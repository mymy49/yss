/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(GD32F1)

#include <config.h>
#include <yss.h>
#include <targets/st/bitfield_stm32f103xx.h>

#define YSS_I2C1_EV_IRQHandler		I2C1_EV_IRQHandler
#define YSS_I2C2_EV_IRQHandler		I2C2_EV_IRQHandler
#define YSS_I2C3_EV_IRQHandler		I2C3_EV_IRQHandler

static const Dma::dmaInfo_t gDmaDummy = 
{
	0,			// uint32_t controlRegister2
	0,			// uint32_t controlRegister3
	0,			//void *dataRegister;
};

static uint32_t getApb1ClockFrequency(void)
{
	return clock.getApb1ClockFrequency();
}

#if defined(I2C1) && defined(I2C1_ENABLE)
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

static const Drv::setup_t gDrvI2c1Config = 
{
	enableI2c1Clock,		//void (*clockFunc)(bool en);
	enableI2c1Interrupt,	//void (*nvicFunc)(bool en);
	resetI2c1,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const I2c::Config gI2c1Config = 
{
	I2C1,			//YSS_I2C_Peri *peri;
	dmaChannel6,	//Dma &txDma;
	gDmaDummy,		//Dma::dmaInfo_t txDmaInfo;
	dmaChannel7,	//Dma &rxDma;
	gDmaDummy		//Dma::dmaInfo_t rxDmaInfo;
};

I2c i2c1(gDrvI2c1Config, gI2c1Config);

extern "C"
{
void YSS_I2C1_EV_IRQHandler(void)
{
	i2c1.isr();
}
}
#endif



#if defined(I2C2) && defined(I2C2_ENABLE)
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

static const Drv::setup_t gDrvI2c2Config = 
{
	enableI2c2Clock,		//void (*clockFunc)(bool en);
	enableI2c2Interrupt,	//void (*nvicFunc)(bool en);
	resetI2c2,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const I2c::Config gI2c2Config = 
{
	I2C2,			//YSS_I2C_Peri *peri;
	dmaChannel4,	//Dma &txDma;
	gDmaDummy,		//Dma::dmaInfo_t txDmaInfo;
	dmaChannel5,	//Dma &rxDma;
	gDmaDummy		//Dma::dmaInfo_t rxDmaInfo;
};

I2c i2c2(gDrvI2c2Config, gI2c2Config);

extern "C"
{
void YSS_I2C2_EV_IRQHandler(void)
{
	i2c2.isr();
}
}
#endif



#if defined(I2C3) && defined(I2C3_ENABLE)
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

static const Drv::setup_t gDrvI2c3Config = 
{
	enableI2c3Clock,		//void (*clockFunc)(bool en);
	enableI2c3Interrupt,	//void (*nvicFunc)(bool en);
	resetI2c3,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const I2c::Config gI2c3Config = 
{
	I2C3,			//YSS_I2C_Peri *peri;
	dmaChannel4,	//Dma &txDma;
	gDmaDummy,		//Dma::dmaInfo_t txDmaInfo;
	dmaChannel5,	//Dma &rxDma;
	gDmaDummy		//Dma::dmaInfo_t rxDmaInfo;
};

I2c i2c3(gDrvI2c3Config, gI2c3Config);

extern "C"
{
void YSS_I2C3_EV_IRQHandler(void)
{
	i2c3.isr();
}
}
#endif

#endif

