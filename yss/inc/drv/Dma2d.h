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

#ifndef YSS_DRV_DMA2D__H_
#define YSS_DRV_DMA2D__H_

#include "mcu.h"

#if defined(STM32F7) || defined(STM32F4)

#include "dma2d/define_dma2d_stm32f4_f7.h"

typedef DMA2D_TypeDef		YSS_DMA2D_Peri;

#elif defined(GD32F4)

#include "dma2d/define_dma2d_gd32f4.h"

typedef uint32_t		YSS_DMA2D_Peri;

#else

#define YSS_DRV_DMA2D_UNSUPPORTED

#endif

#if !defined(YSS_DRV_DMA2D_UNSUPPORTED)

#include <drv/Drv.h>
#include <yss/gui.h>
#include <yss/thread.h>
#include <yss/error.h>

class Dma2d : public Drv
{
	YSS_DMA2D_Peri *mPeri;
	FontInfo mFontInfo;
//#warning "mMutex 삭제 위해서는 호출하는 곳에서 lock 사용해야 함"
	Mutex mMutex;
	int32_t  mThreadId;
	bool mCompleteFlag, mErrorFlag;

  public:
	
	struct Config
	{
		YSS_DMA2D_Peri *peri;
	};

	struct FillConfig
	{
		void *address;
		uint32_t color;
		uint8_t colorMode;
		Size size;
	};

	struct CopyConfig
	{
		void *sourceAddress;
		uint16_t sourceOffset;
		uint8_t sourceColorMode;

		void *destinationAddress;
		uint16_t destinationOffset;
		uint8_t destinationColorMode;

		Size size;
	};

	struct DrawCharConfig
	{
		void *sourceAddress;
		uint16_t sourceOffset;
		uint8_t sourceColorMode;

		void *destinationAddress;
		uint16_t destinationOffset;
		uint8_t destinationColorMode;

		Size size;
	};

	Dma2d(const Drv::Config drvConfig, const Config config);
	Dma2d(YSS_DMA2D_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en));
	void init(void);

	void fill(FillConfig &config);
	void copy(CopyConfig &config);
	void copyWithBlending(CopyConfig &config);
	void drawCharacter(DrawCharConfig &config);

	error waitUntilComplete(void);

	void isr(void);
};

#endif

#endif
