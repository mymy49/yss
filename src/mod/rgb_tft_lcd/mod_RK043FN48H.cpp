/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI == true

#include <drv/Ltdc.h>

#if !defined(YSS_DRV_LTDC_UNSUPPORTED)

#include <mod/rgb_tft_lcd/RK043FN48H.h>

static const Ltdc::specification_t gSpec =
{
	480,		// width
	272,		// height
	1,			// hsyncWidth
	1,			// vsyncWidth
	40,			// hbp
	8,			// vbp
	5,			// hfp
	8,			// vfp
	define::ltdc::format::RGB888	// pixelFormat
};

const Ltdc::specification_t* RK043FN48H::getSpecification(void)
{
	return &gSpec;
}

#endif

#endif

