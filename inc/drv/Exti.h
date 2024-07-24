/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_EXTI__H_
#define YSS_DRV_EXTI__H_

#include "mcu.h"

#if defined(GD32F1) || defined(GD32F4) || defined(STM32F4) || defined(STM32F7) || defined(STM32F0) || defined(STM32F1)

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
#include <yss/thread.h>

class Exti : public Drv
{
public:
	typedef enum
	{
		RISING = 0x1,
		FALLING = 0x2
	}mode_t;

	enum
	{
		PORTA = 0,
		PORTB,
		PORTC,
		PORTD,
		PORTE,
		PORTF,
		PORTG,
		PORTH,
		PORTI,
		PORTJ,
		PORTK,
	};

	Exti(void (*clockFunc)(bool en), void (*nvicFunc)(bool en));

	error_t add(Gpio &gpio, uint8_t pin, mode_t mode, void (*func)(void));

	error_t add(Gpio &gpio, uint8_t pin, mode_t mode, triggerId_t trigger);
	
	// 외부 인터럽트 장치를 일시적으로 활성화/비활성화 하는 목적으로 사용한다.
	// add를 하는 시점에서 기본적으로 exti는 활성화 되지 않는다.
	// (이전에는 add 시점에 활성화 됐으나 2023.07.13일 기준으로 변경됨.)
	//
	// uint8_t pin
	//		인터럽트를 활성화/비활성화 시킬 외부 인터럽트 핀번호를 입력한다.
	// bool enable
	//		활성화(true)/비활성화(false)로 설정한다.
	void enable(uint8_t pin, bool enable = true);

	void isr(int32_t  num);
private:
	void (*mIsr[EXTI_COUNT])(void);

	bool mTriggerFlag[EXTI_COUNT];

	int32_t  mTriggerNum[EXTI_COUNT];
};

#endif

