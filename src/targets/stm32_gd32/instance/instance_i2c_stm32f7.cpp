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

#if defined(STM32F7)

#include <config.h>
#include <yss.h>

#include <targets/st_gigadevice/rcc_stm32_gd32f4_f7.h>
#include <targets/st_gigadevice/dma_stm32_gd32f4_f7.h>
#include <targets/st_gigadevice/i2c_stm32f7.h>

#if defined(I2C1) && defined(I2C1_ENABLE)
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
	resetI2c1			//void (*resetFunc)(void);
};

static const Dma::DmaInfo gI2c1TxDmaInfo = 
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
	(void*)&I2C1[I2C_REG::TXDR]									//void *dataRegister;
};

static const Dma::DmaInfo gI2c1RxDmaInfo = 
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
	(void*)&I2C1[I2C_REG::RXDR]									//void *dataRegister;
};

static const I2c::Config gI2c1Config
{
	I2C1,			//YSS_I2C_Peri *peri;
	dmaChannel7,	//Dma &txDma;
	gI2c1TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel1,	//Dma &rxDma;
	gI2c1RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};

I2c i2c1(gDrvI2c1Config, gI2c1Config);

#endif

#if defined(I2C2) && defined(I2C2_ENABLE)
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
	resetI2c2			//void (*resetFunc)(void);
};

static const Dma::DmaInfo gI2c2TxDmaInfo = 
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
	(void*)&I2C2[I2C_REG::TXDR]									//void *dataRegister;
};

static const Dma::DmaInfo gI2c2RxDmaInfo = 
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
	(void*)&I2C2[I2C_REG::RXDR]									//void *dataRegister;
};

static const I2c::Config gI2c2Config
{
	I2C2,			//YSS_I2C_Peri *peri;
	dmaChannel8,	//Dma &txDma;
	gI2c2TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel3,	//Dma &rxDma;
	gI2c2RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};

I2c i2c2(gDrvI2c2Config, gI2c2Config);

#endif

#if defined(I2C3) && defined(I2C3_ENABLE)
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

static const Drv::Config gDrvI2c3Config
{
	setI2c3ClockEn,		//void (*clockFunc)(bool en);
	0,					//void (*nvicFunc)(bool en);
	resetI2c3			//void (*resetFunc)(void);
};

static const Dma::DmaInfo gI2c3TxDmaInfo = 
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
	(void*)&I2C3[I2C_REG::TXDR]									//void *dataRegister;
};

static const Dma::DmaInfo gI2c3RxDmaInfo = 
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
	(void*)&I2C3[I2C_REG::RXDR]									//void *dataRegister;
};

static const I2c::Config gI2c3Config
{
	I2C3,			//YSS_I2C_Peri *peri;
	dmaChannel5,	//Dma &txDma;
	gI2c3TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel3,	//Dma &rxDma;
	gI2c3RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};

I2c i2c3(gDrvI2c3Config, gI2c3Config);
#endif



#if defined(I2C4) && defined(I2C4_ENABLE)
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

static const Drv::Config gDrvI2c4Config
{
	setI2c4ClockEn,		//void (*clockFunc)(bool en);
	0,					//void (*nvicFunc)(bool en);
	resetI2c4			//void (*resetFunc)(void);
};

static const Dma::DmaInfo gI2c4TxDmaInfo = 
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
	(void*)&I2C4[I2C_REG::TXDR]									//void *dataRegister;
};

static const Dma::DmaInfo gI2c4RxDmaInfo = 
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
	(void*)&I2C4[I2C_REG::RXDR]									//void *dataRegister;
};

static const I2c::Config gI2c4Config
{
	I2C4,			//YSS_I2C_Peri *peri;
	dmaChannel7,	//Dma &txDma;
	gI2c4TxDmaInfo,	//Dma::DmaInfo txDmaInfo;
	dmaChannel2,	//Dma &rxDma;
	gI2c4RxDmaInfo	//Dma::DmaInfo rxDmaInfo;
};

I2c i2c4(gDrvI2c4Config, gI2c4Config);

#endif

#endif

