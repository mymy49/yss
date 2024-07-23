/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>

#if defined(STM32F0)

#include <config.h>
#include <yss.h>

#if defined(STM32F030xC)
#include <targets/st/bitfield_stm32f030xx.h>
#endif

#if defined(I2C1) && I2C1_ENABLE
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

static const Drv::setup_t gDrvI2c1Setup
{
	setI2c1ClockEn,		//void (*clockFunc)(bool en);
	0,					//void (*nvicFunc)(bool en);
	resetI2c1,			//void (*resetFunc)(void);
	getI2c1Clock			//uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gI2c1TxDmaInfo = 
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

static const Dma::dmaInfo_t gI2c1RxDmaInfo = 
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

static const I2c::setup_t gI2c1Setup
{
	I2C1,			//YSS_I2C_Peri *peri;
	dmaChannel2,	//Dma &txDma;
	gI2c1TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel3,	//Dma &rxDma;
	gI2c1RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

I2c i2c1(gDrvI2c1Setup, gI2c1Setup);

#endif

#if defined(I2C2) && I2C2_ENABLE
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

static const Drv::setup_t gDrvI2c2Setup
{
	setI2c2ClockEn,		//void (*clockFunc)(bool en);
	0,					//void (*nvicFunc)(bool en);
	resetI2c2,			//void (*resetFunc)(void);
	getI2c2Clock			//uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gI2c2TxDmaInfo = 
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

static const Dma::dmaInfo_t gI2c2RxDmaInfo = 
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

static const I2c::setup_t gI2c2Setup
{
	I2C2,			//YSS_I2C_Peri *peri;
	dmaChannel4,	//Dma &txDma;
	gI2c2TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel5,	//Dma &rxDma;
	gI2c2RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

I2c i2c2(gDrvI2c2Setup, gI2c2Setup);

#endif

#endif

