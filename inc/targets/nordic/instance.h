/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INSTANCE_NRF_52__H_
#define YSS_INSTANCE_NRF_52__H_

#include <nrf52840.h>

// YSS OS RUNTIME 설정 관련 정의
#define RUNTIME_TIMER0		1
#define RUNTIME_TIMER1		2
#define RUNTIME_TIMER2		3
#define RUNTIME_TIMER3		4

// YSS OS DELAY 설정 관련 정의
#define DELAY_TIMER0		1
#define DELAY_TIMER1		2
#define DELAY_TIMER2		3
#define DELAY_TIMER3		4

#include "nRF52_Gpio.h"
#if defined(NRF_P0)
extern Gpio gpio0;
#endif

#if defined(NRF_P1)
extern Gpio gpio1;
#endif

#if defined(NRF_TIMER0)
#include "nRF52_Timer.h"
extern nRF52_Timer timer0;
#endif

#if defined(NRF_TIMER1)
extern nRF52_Timer timer1;
#endif

#if defined(NRF_TIMER2)
extern nRF52_Timer timer2;
#endif

#if defined(NRF_TIMER3)
extern nRF52_Timer timer3;
#endif

#if defined(NRF_TIMER4)
extern nRF52_Timer timer4;
#endif

#if defined(NRF_UARTE0)
#include "nRF52_Uart.h"
extern nRF52_Uart uart0;
#endif

#if defined(NRF_UARTE1)
extern nRF52_Uart uart1;
#endif

#endif

