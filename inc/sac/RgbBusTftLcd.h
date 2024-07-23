/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_RGB_BUS_TFT_LCD__H_
#define YSS_SAC_RGB_BUS_TFT_LCD__H_

#include <drv/Ltdc.h>

#if !defined(YSS_DRV_LTDC_UNSUPPORTED)

class RgbBusTftLcd
{
  public:
	virtual const Ltdc::specification_t* getSpecification(void) = 0;
};

#endif

#endif

