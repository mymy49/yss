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

#include <yss.h>
#include <config.h>

#if defined(STM32F0) || defined(STM32F7)

#if defined(STM32F0) || defined(STM32F7)
#include <targets/st/bitfield.h>
#endif

void memcpyd(void* des, void* src, uint32_t size)
{

	Dma::DmaInfo dmaInfo = 
	{
#if defined(STM32F030xC)
		(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		 // uint32_t controlRegister1
		(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
		(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
		DMA_CCR_PINC_Msk | 
		DMA_CCR_MINC_Msk | 
		DMA_CCR_TCIE_Msk | 
		DMA_CCR_TEIE_Msk | 
		DMA_CCR_MEM2MEM_Msk |
		DMA_CCR_EN_Msk ,
		0xF << (4 * 4),												// uint32_t controlRegister2
		0x0 << (4 * 4),												// uint32_t controlRegister3
		src															//void *dataRegister;
#elif defined(STM32F7)
		(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) |		// uint32_t controlRegister1
		(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
		(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
		(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
		(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
		DMA_SxCR_PINC_Msk | 
		DMA_SxCR_MINC_Msk | 
		(define::dma::dir::MEM_TO_MEM << DMA_SxCR_DIR_Pos) | 
		DMA_SxCR_TCIE_Msk | 
		DMA_SxCR_TEIE_Msk | 
		DMA_SxCR_EN_Msk,
		0x03,														// uint32_t controlRegister2
		0,															// uint32_t controlRegister3
		src,														//void *dataRegister;
#endif
	};

	COPY_DMA.lock();
	COPY_DMA.transfer(dmaInfo, des, size);
	COPY_DMA.unlock();
}

void memsetd(void* des, uint8_t data, uint32_t size)
{

	Dma::DmaInfo dmaInfo = 
	{
#if defined(STM32F030xC)
		(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		 // uint32_t controlRegister1
		(define::dma::size::BYTE << DMA_CCR_MSIZE_Pos) |
		(define::dma::size::BYTE << DMA_CCR_PSIZE_Pos) |
		DMA_CCR_MINC_Msk | 
		DMA_CCR_TCIE_Msk | 
		DMA_CCR_TEIE_Msk | 
		DMA_CCR_MEM2MEM_Msk |
		DMA_CCR_EN_Msk ,
		0xF << (4 * 4),												// uint32_t controlRegister2
		0x0 << (4 * 4),												// uint32_t controlRegister3
		&data														//void *dataRegister;
#elif defined(STM32F7)
		(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) |		// uint32_t controlRegister1
		(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
		(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
		(define::dma::size::BYTE << DMA_SxCR_MSIZE_Pos) |
		(define::dma::size::BYTE << DMA_SxCR_PSIZE_Pos) |
		DMA_SxCR_MINC_Msk | 
		(define::dma::dir::MEM_TO_MEM << DMA_SxCR_DIR_Pos) | 
		DMA_SxCR_TCIE_Msk | 
		DMA_SxCR_TEIE_Msk | 
		DMA_SxCR_EN_Msk,
		0x03,														// uint32_t controlRegister2
		0,															// uint32_t controlRegister3
		&data,														//void *dataRegister;
#endif
	};

	COPY_DMA.lock();
	COPY_DMA.transfer(dmaInfo, des, size);
	COPY_DMA.unlock();
}

void memsetd(void* des, uint16_t data, uint32_t size)
{
	Dma::DmaInfo dmaInfo = 
	{
#if defined(STM32F030xC)
		(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		 // uint32_t controlRegister1
		(define::dma::size::HALF_WORD << DMA_CCR_MSIZE_Pos) |
		(define::dma::size::HALF_WORD << DMA_CCR_PSIZE_Pos) |
		DMA_CCR_MINC_Msk | 
		DMA_CCR_TCIE_Msk | 
		DMA_CCR_TEIE_Msk | 
		DMA_CCR_MEM2MEM_Msk |
		DMA_CCR_EN_Msk ,
		0xF << (4 * 4),												// uint32_t controlRegister2
		0x0 << (4 * 4),												// uint32_t controlRegister3
		&data														//void *dataRegister;
#elif defined(STM32F7)
		(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) |		// uint32_t controlRegister1
		(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
		(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
		(define::dma::size::HALF_WORD << DMA_SxCR_MSIZE_Pos) |
		(define::dma::size::HALF_WORD << DMA_SxCR_PSIZE_Pos) |
		DMA_SxCR_MINC_Msk | 
		(define::dma::dir::MEM_TO_MEM << DMA_SxCR_DIR_Pos) | 
		DMA_SxCR_TCIE_Msk | 
		DMA_SxCR_TEIE_Msk | 
		DMA_SxCR_EN_Msk,
		0x03,														// uint32_t controlRegister2
		0,															// uint32_t controlRegister3
		&data,														//void *dataRegister;
#endif
	};

	COPY_DMA.lock();
	COPY_DMA.send(dmaInfo, des, size);
	COPY_DMA.unlock();
}

void memsetd(void* des, uint32_t data, uint32_t size)
{
	Dma::DmaInfo dmaInfo = 
	{
#if defined(STM32F030xC)
		(define::dma::priorityLevel::LOW << DMA_CCR_PL_Pos) |		 // uint32_t controlRegister1
		(define::dma::size::WORD << DMA_CCR_MSIZE_Pos) |
		(define::dma::size::WORD << DMA_CCR_PSIZE_Pos) |
		DMA_CCR_MINC_Msk | 
		DMA_CCR_TCIE_Msk | 
		DMA_CCR_TEIE_Msk | 
		DMA_CCR_MEM2MEM_Msk |
		DMA_CCR_EN_Msk ,
		0xF << (4 * 4),												// uint32_t controlRegister2
		0x0 << (4 * 4),												// uint32_t controlRegister3
		&data														//void *dataRegister;
#elif defined(STM32F7)
		(define::dma::burst::SINGLE << DMA_SxCR_MBURST_Pos) |		// uint32_t controlRegister1
		(define::dma::burst::SINGLE << DMA_SxCR_PBURST_Pos) | 
		(define::dma::priorityLevel::LOW << DMA_SxCR_PL_Pos) |
		(define::dma::size::WORD << DMA_SxCR_MSIZE_Pos) |
		(define::dma::size::WORD << DMA_SxCR_PSIZE_Pos) |
		DMA_SxCR_MINC_Msk | 
		(define::dma::dir::MEM_TO_MEM << DMA_SxCR_DIR_Pos) | 
		DMA_SxCR_TCIE_Msk | 
		DMA_SxCR_TEIE_Msk | 
		DMA_SxCR_EN_Msk,
		0x03,														// uint32_t controlRegister2
		0,															// uint32_t controlRegister3
		&data,														//void *dataRegister;
#endif
	};

	COPY_DMA.lock();
	COPY_DMA.send(dmaInfo, des, size);
	COPY_DMA.unlock();
}

#endif

