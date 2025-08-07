/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INSTANCE_M2XX__H_
#define YSS_INSTANCE_M2XX__H_

#include <drv/peripheral.h>

#if defined(__M2xx_FAMILY)
extern Bpwm bpwm0;
extern Bpwm bpwm1;
#endif

extern Clock clock;

#if defined(__M2xx_FAMILY)
extern DmaChannel1 dmaChannel1;
extern DmaChannel2 dmaChannel2;
extern DmaChannel3 dmaChannel3;
extern DmaChannel4 dmaChannel4;
extern DmaChannel5 dmaChannel5;
extern DmaChannel6 dmaChannel6;
extern DmaChannel7 dmaChannel7;
extern DmaChannel8 dmaChannel8;
#endif

extern Gpio gpioA;
extern Gpio gpioB;
extern Gpio gpioC;
extern Gpio gpioD;
extern Gpio gpioE;
extern Gpio gpioF;
extern Gpio gpioG;
extern Gpio gpioH;

#if defined(__M251KG6AE__)
extern Spi spi0;
#endif

#if defined(__M25x_SUBFAMILY)
extern Uart uart0;
extern Uart uart1;
extern Uart uart2;
#endif

#if defined(__M25x_SUBFAMILY)
extern Usbd usbd;
#endif

#endif

