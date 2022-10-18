////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>
/*
#if defined(STM32F1) || defined(STM32F4)

#include <config.h>

static const Dma::DmaInfo gDmaDummy = 
{
	0,			// uint32_t controlRegister2
	0,			// uint32_t controlRegister3
	0,			//void *dataRegister;
};

static int32_t  getI2cClockFrequency(void)
{
//	return clock.getApb1ClkFreq();
}

#if defined(I2C1) && defined(I2C1_ENABLE)
static void setI2c1ClockEn(bool en)
{
	if(en)
		RCC->APB1ENR |= RCC_APB1ENR_I2C1EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_I2C1EN_Msk;
}

static void setI2c1InterruptEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(I2C1_EV_IRQn);
	else
		NVIC_DisableIRQ(I2C1_EV_IRQn);
}

static void resetI2c1(void)
{
	RCC->APB1RSTR |= RCC_APB1RSTR_I2C1RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C1RST_Msk;
}

static const Drv::Config gDrvI2c1Config
{
	setI2c1ClockEn,			//void (*clockFunc)(bool en);
	setI2c1InterruptEn,		//void (*nvicFunc)(bool en);
	resetI2c1,				//void (*resetFunc)(void);
	getI2cClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const I2c::Config gI2c1Config
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
void I2C1_EV_IRQHandler(void)
{
	i2c1.isr();
}
}
#endif



#if defined(I2C2) && defined(I2C2_ENABLE)
static void setI2c2ClockEn(bool en)
{
	if(en)
		RCC->APB1ENR |= RCC_APB1ENR_I2C2EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_I2C2EN_Msk;
}

static void setI2c2InterruptEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(I2C2_EV_IRQn);
	else
		NVIC_DisableIRQ(I2C2_EV_IRQn);
}

static void resetI2c2(void)
{
	RCC->APB1RSTR |= RCC_APB1RSTR_I2C2RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C2RST_Msk;
}

static const Drv::Config gDrvI2c2Config
{
	setI2c2ClockEn,			//void (*clockFunc)(bool en);
	setI2c2InterruptEn,		//void (*nvicFunc)(bool en);
	resetI2c2,				//void (*resetFunc)(void);
	getI2cClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const I2c::Config gI2c2Config
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
void I2C2_EV_IRQHandler(void)
{
	i2c2.isr();
}
}
#endif



#if defined(I2C3) && defined(I2C3_ENABLE)
static void setI2c3ClockEn(bool en)
{
	if(en)
		RCC->APB1ENR |= RCC_APB1ENR_I2C3EN_Msk;
	else
		RCC->APB1ENR &= ~RCC_APB1ENR_I2C3EN_Msk;
}

static void setI2c3InterruptEn(bool en)
{
	if(en)
		NVIC_EnableIRQ(I2C3_EV_IRQn);
	else
		NVIC_DisableIRQ(I2C3_EV_IRQn);
}

static void resetI2c3(void)
{
	RCC->APB1RSTR |= RCC_APB1RSTR_I2C3RST_Msk;
	RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C3RST_Msk;
}

static const Drv::Config gDrvI2c3Config
{
	setI2c3ClockEn,			//void (*clockFunc)(bool en);
	setI2c3InterruptEn,		//void (*nvicFunc)(bool en);
	resetI2c3,				//void (*resetFunc)(void);
	getI2cClockFrequency	//uint32_t (*getClockFunc)(void);
};

static const I2c::Config gI2c3Config
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
void I2C3_EV_IRQHandler(void)
{
	i2c3.isr();
}
}
#endif

#endif
*/
