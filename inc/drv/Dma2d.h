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

#ifndef YSS_DRV_DMA2D__H_
#define YSS_DRV_DMA2D__H_

#include "peripheral.h"
#include <stdint.h>

#if false

#include "dma2d/define_dma2d_stm32f4_f7.h"

typedef volatile uint32_t	YSS_DMA2D_Peri;

#elif defined(DMA2D) && (defined(GD32F4) || defined(STM32F4) || defined(STM32F7))

#include <targets/st_gigadevice/define_dma2d_stm32_gd32f4.h>

typedef volatile uint32_t	YSS_DMA2D_Peri;

#elif defined(DMA2D) && (defined(STM32F7_N) || defined(STM32F4_N))

typedef DMA2D_TypeDef		YSS_DMA2D_Peri;

#else

#define YSS_DRV_DMA2D_UNSUPPORTED
typedef volatile uint32_t	YSS_DMA2D_Peri;

#endif

#include "Drv.h"
#include <yss/error.h>
#include <gui/util.h>
#include <yss/thread.h>

class Dma2d : public Drv
{
	YSS_DMA2D_Peri *mPeri;
	FontInfo mFontInfo;
	threadId  mThreadId;
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
		int16_t destinationOffset;
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

	struct BlendConfig
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
		uint32_t color;
	};

	Dma2d(const Drv::Config drvConfig, const Config config);
	Dma2d(YSS_DMA2D_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en));
	void initialize(void);

	void fill(FillConfig &config);
	void copy(CopyConfig &config);
	void blend(BlendConfig &config);
	void copyWithBlending(CopyConfig &config);
	void drawCharacter(DrawCharConfig &config);

	error waitUntilComplete(void);

	void isr(void);
};

#endif

