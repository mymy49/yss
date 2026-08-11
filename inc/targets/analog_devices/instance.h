/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INSTANCE_M2XX__H_
#define YSS_INSTANCE_M2XX__H_

#if defined(__MAX32665_FAMILY)
#include <max32665.h>
#endif

// YSS OS RUNTIME 설정 관련 정의
#define RUNTIME_TMR0		1
#define RUNTIME_TMR1		2
#define RUNTIME_TMR2		3
#define RUNTIME_TMR3		4
#define RUNTIME_TMR4		5
#define RUNTIME_TMR5		6

#include "Max32665Clock.h"
extern Clock clock;

#include "Max32665Gpio.h"
#if defined(MXC_GPIO0)
extern Gpio gpio0;
#endif

#include "Max32665Timer.h"
#if defined(MXC_TMR0)
extern Max32665Timer timer0;
#endif

#if defined(MXC_TMR1)
extern Max32665Timer timer1;
#endif

#if defined(MXC_TMR0)
extern Max32665Timer timer2;
#endif

#if defined(MXC_TMR0)
extern Max32665Timer timer3;
#endif

#if defined(MXC_TMR0)
extern Max32665Timer timer4;
#endif

#if defined(MXC_TMR0)
extern Max32665Timer timer5;
#endif

#endif

