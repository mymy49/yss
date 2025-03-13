/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INSTANCE_M48X__H_
#define YSS_INSTANCE_M48X__H_

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
extern Bpwm bpwm0;
extern Bpwm bpwm1;
#endif

extern Clock clock;

#if defined(__M480_FAMILY)
extern DmaChannel1 dmaChannel1;
extern DmaChannel2 dmaChannel2;
extern DmaChannel3 dmaChannel3;
extern DmaChannel4 dmaChannel4;
extern DmaChannel5 dmaChannel5;
extern DmaChannel6 dmaChannel6;
extern DmaChannel7 dmaChannel7;
extern DmaChannel8 dmaChannel8;
extern DmaChannel9 dmaChannel9;
extern DmaChannel10 dmaChannel10;
extern DmaChannel11 dmaChannel11;
extern DmaChannel12 dmaChannel12;
extern DmaChannel13 dmaChannel13;
extern DmaChannel14 dmaChannel14;
extern DmaChannel15 dmaChannel15;
extern DmaChannel16 dmaChannel16;
#elif defined(__M4xx_FAMILY)
extern DmaChannel1 dmaChannel1;
extern DmaChannel2 dmaChannel2;
extern DmaChannel3 dmaChannel3;
extern DmaChannel4 dmaChannel4;
extern DmaChannel5 dmaChannel5;
extern DmaChannel6 dmaChannel6;
extern DmaChannel7 dmaChannel7;
extern DmaChannel8 dmaChannel8;
extern DmaChannel9 dmaChannel9;
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
extern Epwm epwm0;
extern Epwm epwm1;
#endif

extern Flash flash;

extern Gpio gpioA;
extern Gpio gpioB;
extern Gpio gpioC;
extern Gpio gpioD;
extern Gpio gpioE;
extern Gpio gpioF;
extern Gpio gpioG;
extern Gpio gpioH;

#if defined(__M480_FAMILY)
extern I2c i2c0;
extern I2c i2c1;
extern I2c i2c2;
#elif defined(__M4xx_FAMILY)
extern I2c i2c0;
extern I2c i2c1;
#endif

#if defined(__M480_FAMILY)
extern I2s i2s0;
extern I2s i2s1;
extern I2s i2s2;
extern I2s i2s3;
#elif defined(__M4xx_FAMILY)
extern I2s i2s0;
extern I2s i2s1;
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
extern PwmCh1 pwm0;
extern PwmCh1 pwm1;
extern PwmCh1 pwm2;
extern PwmCh1 pwm3;
#endif

#if defined(__M480_FAMILY)
extern Spi spi0;
extern Spi spi1;
extern Spi spi2;
extern Spi spi3;
#elif defined(__M4xx_FAMILY)
extern Spi spi0;
extern Spi spi1;
#endif

extern Timer timer0;
extern Timer timer1;
extern Timer timer2;
extern Timer timer3;

#if defined(__M480_FAMILY)
extern Uart uart0;
extern Uart uart1;
extern Uart uart2;
extern Uart uart3;
extern Uart uart4;
extern Uart uart5;
extern Uart uart6;
extern Uart uart7;
#elif defined(__M4xx_FAMILY)
extern Uart uart0;
extern Uart uart1;
extern Uart uart2;
extern Uart uart3;
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
extern Usbd usbd;
#endif

#endif

