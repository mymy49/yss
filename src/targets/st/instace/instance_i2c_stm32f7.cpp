/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F7)

#include <yss/instance.h>
#include <config.h>
#include <yss.h>
#include <targets/st/bitfield.h>

#if defined(I2C1) && I2C1_ENABLE
static uint32_t getI2c1Clock(void)
{
	switch(getFieldData(RCC->DCKCFGR2, RCC_DCKCFGR2_I2C1SEL_Msk, RCC_DCKCFGR2_I2C1SEL_Pos))
	{
	case 0 : // APB1 Clock
		return clock.getApb1ClockFrequency();

	case 1 : // Sysclk
		return clock.getSystemClockFrequency();
	
	case 2 : // HSI Clock
	default:
		return 16000000;
	}
}

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
	getI2c1Clock		//uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gI2c1TxDmaInfo = 
{
	(define::dma1::stream6::I2C1_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&I2C1->TXDR											//void *dataRegister;
};

static const Dma::dmaInfo_t gI2c1RxDmaInfo = 
{
	(define::dma1::stream0::I2C1_RX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&I2C1->RXDR											//void *dataRegister;
};

static const I2c::setup_t gI2c1Setup = 
{
	I2C1,			//YSS_I2C_Peri *peri;
	dmaChannel7,	//Dma &txDma;
	gI2c1TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel1,	//Dma &rxDma;
	gI2c1RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

I2c i2c1(gDrvI2c1Setup, gI2c1Setup);

#endif



#if defined(I2C2) && I2C2_ENABLE
static uint32_t getI2c2Clock(void)
{
	switch(getFieldData(RCC->DCKCFGR2, RCC_DCKCFGR2_I2C2SEL_Msk, RCC_DCKCFGR2_I2C2SEL_Pos))
	{
	case 0 : // APB1 Clock
		return clock.getApb1ClockFrequency();

	case 1 : // Sysclk
		return clock.getSystemClockFrequency();
	
	case 2 : // HSI Clock
	default:
		return 16000000;
	}
}

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

static const Drv::setup_t gDrvI2c2Setup = 
{
	setI2c2ClockEn,		//void (*clockFunc)(bool en);
	0,					//void (*nvicFunc)(bool en);
	resetI2c2,			//void (*resetFunc)(void);
	getI2c2Clock		//uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gI2c2TxDmaInfo = 
{
	(define::dma1::stream7::I2C2_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&I2C2->TXDR											//void *dataRegister;
};

static const Dma::dmaInfo_t gI2c2RxDmaInfo = 
{
	(define::dma1::stream2::I2C2_RX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&I2C2->RXDR											//void *dataRegister;
};

static const I2c::setup_t gI2c2Setup = 
{
	I2C2,			//YSS_I2C_Peri *peri;
	dmaChannel8,	//Dma &txDma;
	gI2c2TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel3,	//Dma &rxDma;
	gI2c2RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

I2c i2c2(gDrvI2c2Setup, gI2c2Setup);
#endif



#if defined(I2C3) && I2C3_ENABLE
static uint32_t getI2c3Clock(void)
{
	switch(getFieldData(RCC->DCKCFGR2, RCC_DCKCFGR2_I2C3SEL_Msk, RCC_DCKCFGR2_I2C3SEL_Pos))
	{
	case 0 : // APB1 Clock
		return clock.getApb1ClockFrequency();

	case 1 : // Sysclk
		return clock.getSystemClockFrequency();
	
	case 2 : // HSI Clock
	default:
		return 16000000;
	}
}

static void setI2c3ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_I2C3EN_Pos, en);
	clock.unlock();
}

static void resetI2c3(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_I2C3RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvI2c3Setup = 
{
	setI2c3ClockEn,		//void (*clockFunc)(bool en);
	0,					//void (*nvicFunc)(bool en);
	resetI2c3,			//void (*resetFunc)(void);
	getI2c3Clock		//uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gI2c3TxDmaInfo = 
{
	(define::dma1::stream4::I2C3_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&I2C3->TXDR											//void *dataRegister;
};

static const Dma::dmaInfo_t gI2c3RxDmaInfo = 
{
	(define::dma1::stream2::I2C3_RX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&I2C3->RXDR											//void *dataRegister;
};

static const I2c::setup_t gI2c3Setup = 
{
	I2C3,			//YSS_I2C_Peri *peri;
	dmaChannel5,	//Dma &txDma;
	gI2c3TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel3,	//Dma &rxDma;
	gI2c3RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

I2c i2c3(gDrvI2c3Setup, gI2c3Setup);
#endif



#if defined(I2C4) && I2C4_ENABLE
static uint32_t getI2c4Clock(void)
{
	switch(getFieldData(RCC->DCKCFGR2, RCC_DCKCFGR2_I2C4SEL_Msk, RCC_DCKCFGR2_I2C4SEL_Pos))
	{
	case 0 : // APB1 Clock
		return clock.getApb1ClockFrequency();

	case 1 : // Sysclk
		return clock.getSystemClockFrequency();
	
	case 2 : // HSI Clock
	default:
		return 16000000;
	}
}

static void setI2c4ClockEn(bool en)
{
	clock.lock();
    clock.enableApb1Clock(RCC_APB1ENR_I2C4EN_Pos, en);
	clock.unlock();
}

static void resetI2c4(void)
{
	clock.lock();
    clock.resetApb1(RCC_APB1RSTR_I2C4RST_Pos);
	clock.unlock();
}

static const Drv::setup_t gDrvI2c4Setup
{
	setI2c4ClockEn,		//void (*clockFunc)(bool en);
	0,					//void (*nvicFunc)(bool en);
	resetI2c4,			//void (*resetFunc)(void);
	getI2c4Clock		//uint32_t (*getClockFunc)(void);
};

static const Dma::dmaInfo_t gI2c4TxDmaInfo = 
{
	(define::dma1::stream6::I2C4_TX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::MEM_TO_PERI << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&I2C4->TXDR											//void *dataRegister;
};

static const Dma::dmaInfo_t gI2c4RxDmaInfo = 
{
	(define::dma1::stream1::I2C4_RX << DMA_SxCR_CHSEL_Pos) |	// uint32_t controlRegister1
	(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) | 
	(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
	(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
	(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
	DMA_SxCR_MINC_Msk | 
	(define::dma::dir::PERI_TO_MEM << DMA_SxCR_DIR_Pos) | 
	DMA_SxCR_TCIE_Msk | 
	DMA_SxCR_TEIE_Msk | 
	DMA_SxCR_EN_Msk,
	DMA_SxFCR_DMDIS_Msk,										// uint32_t controlRegister2
	0,															// uint32_t controlRegister3
	(void*)&I2C4->RXDR											//void *dataRegister;
};

static const I2c::setup_t gI2c4Setup
{
	I2C4,			//YSS_I2C_Peri *peri;
	dmaChannel7,	//Dma &txDma;
	gI2c4TxDmaInfo,	//Dma::dmaInfo_t txDmaInfo;
	dmaChannel2,	//Dma &rxDma;
	gI2c4RxDmaInfo	//Dma::dmaInfo_t rxDmaInfo;
};

I2c i2c4(gDrvI2c4Setup, gI2c4Setup);

#endif

#endif

