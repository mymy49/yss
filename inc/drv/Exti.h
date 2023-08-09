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

#ifndef YSS_DRV_EXTI__H_
#define YSS_DRV_EXTI__H_

#include "mcu.h"

#if defined(GD32F1) || defined(STM32F1) || defined(STM32F7) || defined(STM32F4) || defined(GD32F4) || defined(STM32F4_N) || defined(STM32F7_N) || defined(STM32F0_N)

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
		FALLING = 0x2,

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

	error add(Gpio &gpio, uint8_t pin, uint8_t mode, void (*func)(void));

	error add(Gpio &gpio, uint8_t pin, uint8_t mode, int32_t  trigger);
	
	// 외부 인터럽트 장치를 일시적으로 활성화/비활성화 하는 목적으로 사용한다.
	// add를 하는 시점에서 기본적으로 exti는 활성화 되지 않는다.
	// (이전에는 add 시점에 활성화 됐으나 2023.07.13일 기준으로 변경됨.
	//
	// uint8_t pin
	//		인터럽트를 활성화/비활성화 시킬 외부 인터럽트 핀번호를 입력한다.
	// bool enable
	//		활성화(true)/비활성화(false)로 설정한다.
	void enable(uint8_t pin, bool enable = true);

	void isr(int32_t  num);
};

#endif

