/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_WDOG__H_
#define YSS_DRV_WDOG__H_

#include "peripheral.h"

#if defined(STM32F0)

typedef IWDG_TypeDef		YSS_WDOG_peri;

#else

typedef void WDOG_peri;
#define YSS_DRV_WDOG_UNSUPPORTED

#endif

#ifndef YSS_DRV_WDOG_UNSUPPORTED

#include "Drv.h"
#include <yss/error.h>

class Wdog : public Drv
{
public:
	error_t initialize(uint8_t prescale, uint16_t reload);

	void update(void);

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	struct Config
	{
		YSS_WDOG_peri *dev;
	};

	Wdog(const Drv::setup_t drvConfig, const Config config);

private:
	YSS_WDOG_peri *mPeri;
	uint16_t mReload;
};

#endif

#endif
