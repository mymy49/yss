/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_LTDC__H_
#define YSS_DRV_LTDC__H_

#include "peripheral.h"
#include <stdint.h>

#if defined(LTDC) && (defined(STM32F7) || defined(STM32F4))

#else

#define YSS_DRV_LTDC_UNSUPPORTED
typedef volatile uint32_t	YSS_LTDC_Peri;

#endif

#include <yss/gui.h>
#include <yss/error.h>
#include "Drv.h"

class Ltdc : public Drv
{
public:
	struct specification_t
	{
		uint16_t width;
		uint16_t height;
		uint8_t hsyncWidth;
		uint8_t vsyncWidth;
		uint8_t hbp;
		uint8_t vbp;
		uint8_t hfp;
		uint8_t vfp;
		uint8_t pixelFormat;
	};

	Ltdc(const Drv::setup_t drvSetup);

	error_t initialize(const Ltdc::specification_t *spec);
	void setFrameBuffer(void *frame);
	//void setFrameBuffer(FrameBuffer &obj);
	//void setFrameBuffer(FrameBuffer *obj);
	Size_t getLcdSize(void);

private:
	const specification_t *mSpec;
};

#endif

