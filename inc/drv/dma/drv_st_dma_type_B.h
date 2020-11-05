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

#ifndef YSS_DRV_DMA_ST_TYPE_B__H_
#define YSS_DRV_DMA_ST_TYPE_B__H_

#if	defined(STM32F100xB) || defined(STM32F100xE) || \
	defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
	defined(STM32F102x6) || defined(STM32F102xB) || \
	defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) || \
    defined(STM32F107xC)

#include <sac/Comm.h>
#include "drv_st_dma_type_B_map.h"
#include "drv_st_dma_type_B_define.h"
#include <yss/thread.h>
#include <drv/Drv.h>

namespace drv
{
	class Dma : public Drv
	{
	public :
		Dma(void (*clockFunc)(bool en), void (*nvicFunc)(bool en));
		void init(void);
	};

	class Stream : public Drv
	{
		Mutex mMutex;
		bool mCompleteFlag, mErrorFlag;

	protected :
		DMA_Channel_TypeDef *mPeri;

	public :
		Stream(DMA_Channel_TypeDef *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en));
		void init(void);
		bool send(sac::Comm *obj, void *src, unsigned long size, unsigned long timeout);
		void pendTx(sac::Comm *obj, void *src, unsigned long size);
		void pendRx(sac::Comm *obj, void *des, unsigned long size);

		bool wait(unsigned long long timeout);
		void stop(void);
		bool receive(sac::Comm *obj, void *des, unsigned long size, unsigned long timeout);
		void setComplete(void);
		void setError(void);
	};
}

#if defined(DMA1)
extern drv::Dma dma;
#endif

#if defined(DMA1_STREAM1_ENABLE) && defined(DMA1_Channel1)
extern drv::Stream	dma1Stream1;
#endif

#if defined(DMA1_STREAM2_ENABLE) && defined(DMA1_Channel2)
extern drv::Stream	dma1Stream2;
#endif

#if defined(DMA1_STREAM3_ENABLE) && defined(DMA1_Channel3)
extern drv::Stream	dma1Stream3;
#endif

#if defined(DMA1_STREAM4_ENABLE) && defined(DMA1_Channel4)
extern drv::Stream	dma1Stream4;
#endif

#if defined(DMA1_STREAM5_ENABLE) && defined(DMA1_Channel5)
extern drv::Stream	dma1Stream5;
#endif

#if defined(DMA1_STREAM6_ENABLE) && defined(DMA1_Channel6)
extern drv::Stream	dma1Stream6;
#endif

#if defined(DMA1_STREAM7_ENABLE) && defined(DMA1_Channel7)
extern drv::Stream	dma1Stream7;
#endif

#if defined(DMA2_STREAM1_ENABLE) && defined(DMA2_Channel1)
extern drv::Stream	dma2Stream1;
#endif

#if defined(DMA2_STREAM2_ENABLE) && defined(DMA2_Channel2)
extern drv::Stream	dma2Stream2;
#endif

#if defined(DMA2_STREAM3_ENABLE) && defined(DMA2_Channel3)
extern drv::Stream	dma2Stream3;
#endif

#if defined(DMA2_STREAM4_ENABLE) && defined(DMA2_Channel4)
extern drv::Stream	dma2Stream4;
#endif

#if defined(DMA2_STREAM5_ENABLE) && defined(DMA2_Channel5)
extern drv::Stream	dma2Stream5;
#endif

#if defined(DMA2_STREAM6_ENABLE) && defined(DMA2_Channel6)
extern drv::Stream	dma2Stream6;
#endif

#if defined(DMA2_STREAM7_ENABLE) && defined(DMA2_Channel7)
extern drv::Stream	dma2Stream7;
#endif

#endif

#endif
