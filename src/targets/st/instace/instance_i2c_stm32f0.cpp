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

#if defined(STM32F0_N)

#include <config.h>
#include <yss.h>

#if defined(STM32F030xC)
#include <targets/st/bitfield_stm32f030xx.h>
#endif

#if defined(I2C1) && defined(I2C1_ENABLE)
#if defined(STM32F030xC)
static uint32_t getI2c1Clock(void)
{
	if(RCC->CFGR3 & RCC_CFGR3_I2C1SW_Msk)
		return clock.getSystemClockFrequency();
	else
		return 8000000;
}
#endif

static void setI2c1ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_I2C1EN_Pos, en);
	clock.unlock();
}

static void resetI2c1(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_I2C1RST_Pos);
	clock.unlock();
}

static const Drv::Config gDrvI2c1Config
{
	setI2c1ClockEn,		//void (*clockFunc)(bool en);
	0,					//void (*nvicFunc)(bool en);
	resetI2c1,			//void (*resetFunc)(void);
	getI2c1Clock			//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gI2c1TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0x0F << (4 * 1),		// uint32_t controlRegister2
	0x03 << (4 * 1),		// uint32_t controlRegister3
	(void*)&I2C1->TXDR,		//void *dataRegister;
};

static const Dma::DmaInfo gI2c1RxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0x0F << (4 * 2),		// uint32_t controlRegister2
	0x03 << (4 * 2),		// uint32_t controlRegister3
	(void*)&I2C1->RXDR,		//void *dataRegister;
};

static const I2c::Config gI2c1Config
{
	I2C1,			//YSS_I2C_Peri *peri;
	dmaChannel2,	//Dma &txDma;
	gI2c1TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel3,	//Dma &rxDma;
	gI2c1RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};

I2c i2c1(gDrvI2c1Config, gI2c1Config);

#endif

#if defined(I2C2) && defined(I2C2_ENABLE)
#if defined(STM32F030xC)
static uint32_t getI2c2Clock(void)
{
	return clock.getApb1ClockFrequency();
}
#endif
static void setI2c2ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_I2C2EN_Pos, en);
	clock.unlock();
}

static void resetI2c2(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_I2C2RST_Pos);
	clock.unlock();
}

static const Drv::Config gDrvI2c2Config
{
	setI2c2ClockEn,		//void (*clockFunc)(bool en);
	0,					//void (*nvicFunc)(bool en);
	resetI2c2,			//void (*resetFunc)(void);
	getI2c2Clock			//uint32_t (*getClockFunc)(void);
};

static const Dma::DmaInfo gI2c2TxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0x0F << (4 * 3),		// uint32_t controlRegister2
	0x03 << (4 * 3),		// uint32_t controlRegister3
	(void*)&I2C2->TXDR,		//void *dataRegister;
};

static const Dma::DmaInfo gI2c2RxDmaInfo = 
{
	(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) | // uint32_t controlRegister1
	(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
	DMA_CCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_CCR_DIR_Pos) | 
	DMA_CCR_TCIE_Msk | 
	DMA_CCR_TEIE_Msk | 
	DMA_CCR_EN_Msk,
	0x0F << (4 * 3),		// uint32_t controlRegister2
	0x03 << (4 * 3),		// uint32_t controlRegister3
	(void*)&I2C2->RXDR,		//void *dataRegister;
};

static const I2c::Config gI2c2Config
{
	I2C2,			//YSS_I2C_Peri *peri;
	dmaChannel4,	//Dma &txDma;
	gI2c2TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel5,	//Dma &rxDma;
	gI2c2RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};

I2c i2c2(gDrvI2c2Config, gI2c2Config);

#endif

#endif

