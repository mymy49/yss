/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_CLOCK__H_
#define YSS_DRV_CLOCK__H_

#include "peripheral.h"

#if defined(STM32F1) || defined(GD32F1)
#define IncludeSubClassHeader	<targets/st/class_clock_stm32f1.h>
#elif defined(STM32F4) || defined(STM32F7)
#include <targets/st/class_clock_stm32f4_f7.h>
#elif defined(STM32G4)
#include <targets/st/class_clock_stm32g4.h>
#elif defined(STM32F0)
#define IncludeSubClassHeader	<targets/st/class_clock_stm32f0.h>
#elif defined(EFM32PG22) || defined(EFR32BG22)
#define IncludeSubClassHeader	<targets/siliconlabs/class_clock_efm32pg22_efr32bg22.h>
#elif defined(NRF52840_XXAA)
#include <targets/nordic/ec_clock_nrf52840.h>
#include <targets/nordic/define_clock_nrf52840.h>
#elif defined(MAX32672)
#define IncludeSubClassHeader	<targets/maxim/max32672/class_clock_max32672.h>
#elif defined(W7500)
#include <targets/wiznet/class_clock_w7500x.h>
#elif defined(CPU_MIMXRT1011DAE5A)
#include <targets/nxp/class_clock_mimxrt.h>
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
#include <targets/nuvoton/class_clock.h>
#else
#define YSS_DRV_CLOCK_UNSUPPORTED

class Clock
{

};
#endif

#include <yss/Mutex.h>
#include <yss/error.h>

#ifndef YSS_DRV_CLOCK_UNSUPPORTED

#if defined(STM32G4) || defined(STM32F7) || defined(STM32F4) || defined(W7500) || defined(CPU_MIMXRT1011DAE5A) || defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

#else
class ClockBase : public Mutex
{
public :
	virtual uint32_t getCoreClockFrequency(void) = 0;
};

#include IncludeSubClassHeader
#endif

#endif	

#endif

// 주의 사항
// yss OS에서 micro second를 정상적으로 사용하기 위해서 반드시 Timer의 소스 클럭은 MHz 단위로 사용해야 합니다. 

