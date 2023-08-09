////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_CLOCK__H_
#define YSS_DRV_CLOCK__H_

#include "peripheral.h"

#if defined(STM32F1_N) || defined(GD32F1)
#define IncludeSubClassHeader	<targets/st/class_clock_stm32f1.h>
#elif defined(STM32F4)
#define IncludeSubClassHeader	<targets/st_gigadevice/class_clock_stm32_gd32f4_f7.h>
#elif defined(STM32F4_N) || defined(STM32F7_N)
#define IncludeSubClassHeader	<targets/st/class_clock_stm32f4_f7.h>
#elif defined(STM32F0_N)
#define IncludeSubClassHeader	<targets/st/class_clock_stm32f0.h>
#elif defined(EFM32PG22) || defined(EFR32BG22)
#define IncludeSubClassHeader	<targets/siliconlabs/class_clock_efm32pg22_efr32bg22.h>
#elif defined(NRF52840_XXAA)
#include <targets/nordic/ec_clock_nrf52840.h>
#include <targets/nordic/define_clock_nrf52840.h>
#elif defined(STM32L1)
#include <targets/st_gigadevice/define_clock_stm32l1.h>
#include <targets/st_gigadevice/ec_clock_stm32l1.h>
#elif defined(STM32F0)
#include <targets/st_gigadevice/ec_clock_stm32f0.h>
#include <targets/st_gigadevice/define_clock_stm32f0.h>
#elif defined(MAX32672)
#define IncludeSubClassHeader	<targets/maxim/max32672/class_clock_max32672.h>
#else
#define YSS_DRV_CLOCK_UNSUPPORTED

class Clock
{

};
#endif

#include <yss/Mutex.h>
#include <yss/error.h>

#ifndef YSS_DRV_CLOCK_UNSUPPORTED
class ClockBase : public Mutex
{
public :
	virtual uint32_t getCoreClockFrequency(void) = 0;
};

#include IncludeSubClassHeader

#endif	

#endif

// 주의 사항
// yss OS에서 micro second를 정상적으로 사용하기 위해서 반드시 Timer의 소스 클럭은 MHz 단위로 사용해야 합니다. 

