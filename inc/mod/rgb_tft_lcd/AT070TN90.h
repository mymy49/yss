/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_AT070TN90__H_
#define YSS_MOD_TFT_AT070TN90__H_

#include <drv/Ltdc.h>
#include <sac/RgbBusTftLcd.h>

#if !defined(YSS_DRV_LTDC_UNSUPPORTED)

class AT070TN90 : public RgbBusTftLcd
{
  public:
	const Ltdc::specification_t* getSpecification(void); // virtual 0
};

#endif

#endif

