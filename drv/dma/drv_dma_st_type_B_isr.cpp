////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if	defined(STM32F100xB) || defined(STM32F100xE) || \
	defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
	defined(STM32F102x6) || defined(STM32F102xB) || \
	defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) || \
    defined(STM32F107xC)

#include <__cross_studio_io.h>

#include <config.h>

#include <drv/peripherals.h>
#include <drv/dma/drv_st_dma_type_B_register.h>

extern "C"
{
#define checkError(sr)		(sr & 0x08)
#define checkComplete(sr)	(sr & 0x03)

#if defined(DMA1_STREAM1_ENABLE) && defined(DMA1)
	void DMA1_Channel1_IRQHandler(void)
	{
		unsigned long sr = getDmaStream1Sr(DMA1);
		clrDmaStream1Sr(DMA1, sr);
		if(checkError(sr))
			dma1Stream1.setError();
		if(checkComplete(sr))
			dma1Stream1.setComplete();
	}
#endif
#if defined(DMA1_STREAM2_ENABLE) && defined(DMA1)
	void DMA1_Channel2_IRQHandler(void)
	{
		unsigned long sr = getDmaStream2Sr(DMA1);
		clrDmaStream2Sr(DMA1, sr);
		if(checkError(sr))
			dma1Stream2.setError();
		if(checkComplete(sr))
			dma1Stream2.setComplete();
	}
#endif
#if defined(DMA1_STREAM3_ENABLE) && defined(DMA1)
	void DMA1_Channel3_IRQHandler(void)
	{
		unsigned long sr = getDmaStream3Sr(DMA1);
		clrDmaStream3Sr(DMA1, sr);
		if(checkError(sr))
			dma1Stream3.setError();
		if(checkComplete(sr))
			dma1Stream3.setComplete();
	}
#endif
#if defined(DMA1_STREAM4_ENABLE) && defined(DMA1)
	void DMA1_Channel4_IRQHandler(void)
	{
		unsigned long sr = getDmaStream4Sr(DMA1);
		clrDmaStream4Sr(DMA1, sr);
		if(checkError(sr))
			dma1Stream4.setError();
		if(checkComplete(sr))
			dma1Stream4.setComplete();
	}
#endif
#if defined(DMA1_STREAM5_ENABLE) && defined(DMA1)
	void DMA1_Channel5_IRQHandler(void)
	{
		unsigned long sr = getDmaStream5Sr(DMA1);
		clrDmaStream5Sr(DMA1, sr);
		if(checkError(sr))
			dma1Stream5.setError();
		if(checkComplete(sr))
			dma1Stream5.setComplete();
	}
#endif
#if defined(DMA1_STREAM6_ENABLE) && defined(DMA1)
	void DMA1_Channel6_IRQHandler(void)
	{
		unsigned long sr = getDmaStream6Sr(DMA1);
		clrDmaStream6Sr(DMA1, sr);
		if(checkError(sr))
			dma1Stream6.setError();
		if(checkComplete(sr))
			dma1Stream6.setComplete();
	}
#endif
#if defined(DMA1_STREAM7_ENABLE) && defined(DMA1)
	void DMA1_Channel7_IRQHandler(void)
	{
		unsigned long sr = getDmaStream7Sr(DMA1);
		clrDmaStream7Sr(DMA1, sr);
		if(checkError(sr))
			dma1Stream7.setError();
		if(checkComplete(sr))
			dma1Stream7.setComplete();
	}
#endif
#if defined(DMA2_STREAM1_ENABLE) && defined(DMA2)
	void DMA2_Channel1_IRQHandler(void)
	{
		unsigned long sr = getDmaStream1Sr(DMA2);
		clrDmaStream1Sr(DMA2, sr);
		if(checkError(sr))
			dma2Stream1.setError();
		if(checkComplete(sr))
			dma2Stream1.setComplete();
	}
#endif
#if defined(DMA2_STREAM2_ENABLE) && defined(DMA2)
	void DMA2_Channel2_IRQHandler(void)
	{
		unsigned long sr = getDmaStream2Sr(DMA2);
		clrDmaStream2Sr(DMA2, sr);
		if(checkError(sr))
			dma2Stream2.setError();
		if(checkComplete(sr))
			dma2Stream2.setComplete();
	}
#endif
#if defined(DMA2_STREAM3_ENABLE) && defined(DMA2)
	void DMA2_Channel3_IRQHandler(void)
	{
		unsigned long sr = getDmaStream3Sr(DMA2);
		clrDmaStream3Sr(DMA2, sr);
		if(checkError(sr))
			dma2Stream3.setError();
		if(checkComplete(sr))
			dma2Stream3.setComplete();
	}
#endif
#if (defined(DMA2_STREAM4_ENABLE) || defined(DMA2_STREAM5_ENABLE)) && defined(DMA2)
	void DMA2_Channel4_5_IRQHandler(void)
	{
		unsigned long sr = getDmaStream4Sr(DMA2);
		clrDmaStream4Sr(DMA2, sr);
		if(checkError(sr))
			dma2Stream4.setError();
		if(checkComplete(sr))
			dma2Stream4.setComplete();
//		unsigned long sr = getDmaStream4Sr(DMA2);
//		clrDmaStream4Sr(DMA2, sr);
//
//		dma2Stream4.clearMutex();

	}
#endif
}

#endif
