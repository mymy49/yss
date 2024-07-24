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

#include <mod/rgb_tft_lcd/AT070TN90.h>

static const Ltdc::specification_t gSpec =
{
	800,		// width
	480,		// height
	20,			// hsyncWidth
	10,			// vsyncWidth
	28,			// hbp
	13,			// vbp
	210,		// hfp
	22,			// vfp
	define::ltdc::format::RGB888	// pixelFormat
};

const Ltdc::specification_t* AT070TN90::getSpecification(void)
{
	return &gSpec;
}

#endif

#endif

