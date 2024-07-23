/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INSTANCE_W7500X__H_
#define YSS_INSTANCE_W7500X__H_

#include <drv/peripheral.h>

extern Clock clock;

extern DmaChannel1 dmaChannel1;
extern DmaChannel2 dmaChannel2;
extern DmaChannel3 dmaChannel3;
extern DmaChannel4 dmaChannel4;
extern DmaChannel5 dmaChannel5;
extern DmaChannel6 dmaChannel6;

extern Gpio gpioA;
extern Gpio gpioB;
extern Gpio gpioC;
extern Gpio gpioD;

extern PwmCh1 pwm0;
extern PwmCh1 pwm1;
extern PwmCh1 pwm2;
extern PwmCh1 pwm3;
extern PwmCh1 pwm4;
extern PwmCh1 pwm5;
extern PwmCh1 pwm6;
extern PwmCh1 pwm7;

extern Timer timer0;
extern Timer timer1;
extern Timer timer2;
extern Timer timer3;
extern Timer timer4;
extern Timer timer5;
extern Timer timer6;
extern Timer timer7;

extern Uart uart0;
extern Uart uart1;

#endif

