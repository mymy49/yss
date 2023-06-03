////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(GD32F1)

#include <config.h>
#include <yss.h>
#include <targets/st/bitfield_stm32f103xx.h>

#define YSS_I2C1_EV_IRQHandler		I2C1_EV_IRQHandler
#define YSS_I2C2_EV_IRQHandler		I2C2_EV_IRQHandler
#define YSS_I2C3_EV_IRQHandler		I2C3_EV_IRQHandler

static const Dma::DmaInfo gDmaDummy = 
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

static const Drv::Config gDrvI2c1Config = 
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
	gDmaDummy,		//Dma::DmaInfo txDmaInfo;
	dmaChannel7,	//Dma &rxDma;
	gDmaDummy		//Dma::DmaInfo rxDmaInfo;
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

static const Drv::Config gDrvI2c2Config = 
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
	gDmaDummy,		//Dma::DmaInfo txDmaInfo;
	dmaChannel5,	//Dma &rxDma;
	gDmaDummy		//Dma::DmaInfo rxDmaInfo;
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

static const Drv::Config gDrvI2c3Config = 
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
	gDmaDummy,		//Dma::DmaInfo txDmaInfo;
	dmaChannel5,	//Dma &rxDma;
	gDmaDummy		//Dma::DmaInfo rxDmaInfo;
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

