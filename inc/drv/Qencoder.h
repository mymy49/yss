/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_QENCODER__H_
#define YSS_DRV_QENCODER__H_

#include "peripheral.h"

#if defined(STM32F4) || defined(STM32F7)

typedef TIM_TypeDef			YSS_QENCODER_Peri;

#else

#define YSS_DRV_QENCODER_UNSUPPORTED
typedef volatile uint32_t	YSS_QENCODER_Peri;

#endif

#include "Drv.h"

class Qencoder : public Drv
{
public:
	struct setup_t
	{
		YSS_QENCODER_Peri *peri;
	};

	Qencoder(const Drv::setup_t &drvSetup, const setup_t &setup);
	
	void initialize(void);
	
	void start(void);

	void stop(void);

	int16_t getCount(void);

	void resetCount(void);
	
protected:
	YSS_QENCODER_Peri *mPeri;
};

#endif

