////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>

#if defined(STM32F4_N) || defined(STM32F1_N)

#include <config.h>
#include <yss.h>

#if defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#elif defined(STM32F429xx)
#include <targets/st/bitfield_stm32f429xx.h>
#elif defined(STM32F103xB)
#include <targets/st/bitfield_stm32f103xx.h>
#endif

#if I2C1_ENABLE || I2C2_ENABLE || I2C3_ENABLE
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

static const Drv::Setup gDrvI2c1Setup = 
{
	enableI2c1Clock,		//void (*clockFunc)(bool en);
	enableI2c1Interrupt,	//void (*nvicFunc)(bool en);
	resetI2c1,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const I2c::Setup gI2c1Setup = 
{
	I2C1,			//YSS_I2C_Peri *peri;
	dmaChannel6,	//Dma &txDma;
	gDmaDummy,		//Dma::DmaInfo txDmaInfo;
	dmaChannel7,	//Dma &rxDma;
	gDmaDummy		//Dma::DmaInfo rxDmaInfo;
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

static const Drv::Setup gDrvI2c2Setup = 
{
	enableI2c2Clock,		//void (*clockFunc)(bool en);
	enableI2c2Interrupt,	//void (*nvicFunc)(bool en);
	resetI2c2,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const I2c::Setup gI2c2Setup = 
{
	I2C2,			//YSS_I2C_Peri *peri;
	dmaChannel4,	//Dma &txDma;
	gDmaDummy,		//Dma::DmaInfo txDmaInfo;
	dmaChannel5,	//Dma &rxDma;
	gDmaDummy		//Dma::DmaInfo rxDmaInfo;
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

static const Drv::Setup gDrvI2c3Setup = 
{
	enableI2c3Clock,		//void (*clockFunc)(bool en);
	enableI2c3Interrupt,	//void (*nvicFunc)(bool en);
	resetI2c3,				//void (*resetFunc)(void);
	getApb1ClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const I2c::Setup gI2c3Setup = 
{
	I2C3,			//YSS_I2C_Peri *peri;
	dmaChannel4,	//Dma &txDma;
	gDmaDummy,		//Dma::DmaInfo txDmaInfo;
	dmaChannel5,	//Dma &rxDma;
	gDmaDummy		//Dma::DmaInfo rxDmaInfo;
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

