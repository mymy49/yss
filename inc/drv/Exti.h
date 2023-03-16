////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_EXTI__H_
#define YSS_DRV_EXTI__H_

#include "mcu.h"

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F7) || defined(STM32F4) || defined(GD32F4) || defined(STM32F4_N) || defined(STM32F7_N)

#define EXTI_COUNT		16

#elif defined(NRF52840_XXAA)

#define EXTI_COUNT		8

#else

#define YSS_DRV_EXTI_UNSUPPORTED
#define EXTI_COUNT		0

#endif

#include "Drv.h"
#include "Gpio.h"
#include <yss/error.h>

class Exti : public Drv
{
	void (*mIsr[EXTI_COUNT])(void);
	bool mTriggerFlag[EXTI_COUNT];
	int32_t  mTriggerNum[EXTI_COUNT];

  public:
	enum
	{
		RISING = 0x1,
		FALLING = 0x2
	};

	Exti(void (*clockFunc)(bool en), void (*nvicFunc)(bool en));

#if !defined(YSS_DRV_GPIO_UNSUPPORTED)
	error add(Gpio &gpio, uint8_t pin, uint8_t mode, void (*func)(void));

	error add(Gpio &gpio, uint8_t pin, uint8_t mode, int32_t  trigger);
#endif

	void isr(int32_t  num);
};

#endif

