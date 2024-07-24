/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_DMA2D__H_
#define YSS_DRV_DMA2D__H_

#include "peripheral.h"
#include <stdint.h>

#if defined(DMA2D) && (defined(STM32F7) || defined(STM32F4))

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
//	FontInfo mFontInfo;
	threadId_t  mThreadId;
	bool mCompleteFlag, mErrorFlag;

  public:
	
	struct setup_t
	{
		YSS_DMA2D_Peri *peri;
	};

	struct FillConfig
	{
		void *address;
		uint32_t color;
		uint8_t colorMode;
		int16_t destinationOffset;
		Size_t size;
	};

	struct CopyConfig
	{
		void *sourceAddress;
		uint16_t sourceOffset;
		uint8_t sourceColorMode;

		void *destinationAddress;
		uint16_t destinationOffset;
		uint8_t destinationColorMode;

		Size_t size;
	};

	struct BlendConfig
	{
		void *sourceAddress;
		uint16_t sourceOffset;
		uint8_t sourceColorMode;

		void *destinationAddress;
		uint16_t destinationOffset;
		uint8_t destinationColorMode;

		Size_t size;
	};

	struct DrawCharConfig
	{
		void *sourceAddress;
		uint16_t sourceOffset;
		uint8_t sourceColorMode;

		void *destinationAddress;
		uint16_t destinationOffset;
		uint8_t destinationColorMode;

		Size_t size;
		uint32_t color;
	};

	Dma2d(const Drv::setup_t drvSetup, const setup_t config);
	Dma2d(YSS_DMA2D_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en));
	void initialize(void);

	void fill(FillConfig &config);
	void copy(CopyConfig &config);
	void blend(BlendConfig &config);
	void copyWithBlending(CopyConfig &config);
	void drawCharacter(DrawCharConfig &config);

	error_t waitUntilComplete(void);

	void isr(void);
};

#endif

