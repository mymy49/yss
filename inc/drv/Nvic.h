/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NVIC__H_
#define YSS_DRV_NVIC__H_

#include "peripheral.h"
#include "Drv.h"

class Nvic : public Drv
{
  public:
	Nvic(void);
	void enableInterrupt(IRQn_Type position, bool en = true);
};

#endif

