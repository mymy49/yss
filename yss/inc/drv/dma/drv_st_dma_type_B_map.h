////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_DMA_ST_TYPE_B_MAP__H_
#define YSS_DRV_DMA_ST_TYPE_B_MAP__H_

#include <config.h>

#if defined(STM32F100xB) || defined(STM32F100xE) ||                                                 \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC)

#if defined(DMA1_STREAM6_ENABLE)
#define YSS_DMA_MAP_I2C1_TX_STREAM &dma1Stream6
#else
#define YSS_DMA_MAP_I2C1_TX_STREAM *(drv::Stream *)0
#endif

#if defined(DMA1_STREAM7_ENABLE)
#define YSS_DMA_MAP_I2C1_RX_STREAM &dma1Stream7
#else
#define YSS_DMA_MAP_I2C1_RX_STREAM *(drv::Stream *)0
#endif

#if defined(DMA1_STREAM4_ENABLE)
#define YSS_DMA_MAP_I2C2_TX_STREAM &dma1Stream4
#else
#define YSS_DMA_MAP_I2C2_TX_STREAM *(drv::Stream *)0
#endif

#if defined(DMA1_STREAM5_ENABLE)
#define YSS_DMA_MAP_I2C2_RX_STREAM &dma1Stream5
#else
#define YSS_DMA_MAP_I2C2_RX_STREAM *(drv::Stream *)0
#endif

#if defined(DMA1_STREAM4_ENABLE)
#define YSS_DMA_MAP_UART1_TX_STREAM &dma1Stream4
#else
#define YSS_DMA_MAP_UART1_TX_STREAM *(drv::Stream *)0
#endif
#define YSS_DMA_MAP_UART1_TX_CHANNEL 0

#if defined(DMA1_STREAM7_ENABLE)
#define YSS_DMA_MAP_UART2_TX_STREAM &dma1Stream7
#else
#define YSS_DMA_MAP_UART2_TX_STREAM *(drv::Stream *)0
#endif
#define YSS_DMA_MAP_UART2_TX_CHANNEL 0

#if defined(DMA1_STREAM2_ENABLE)
#define YSS_DMA_MAP_UART3_TX_STREAM &dma1Stream2
#else
#define YSS_DMA_MAP_UART3_TX_STREAM *(drv::Stream *)0
#endif
#define YSS_DMA_MAP_UART3_TX_CHANNEL 0

#if defined(DMA2_STREAM5_ENABLE)
#define YSS_DMA_MAP_UART4_TX_STREAM &dma2Stream5
#else
#define YSS_DMA_MAP_UART4_TX_STREAM *(drv::Stream *)0
#endif
#define YSS_DMA_MAP_UART4_TX_CHANNEL 0

#if defined(DMA1_STREAM7_ENABLE)
#define YSS_DMA_MAP_UART5_TX_STREAM &dma1Stream7
#else
#define YSS_DMA_MAP_UART5_TX_STREAM *(drv::Stream *)0
#endif
#define YSS_DMA_MAP_UART5_TX_CHANNEL 0

#if defined(DMA1_STREAM3_ENABLE)
#define YSS_DMA_MAP_SPI1_TX_STREAM &dma1Stream3
#else
#define YSS_DMA_MAP_SPI1_TX_STREAM 0
#endif
#define YSS_DMA_MAP_SPI1_TX_CHANNEL 0

#if defined(DMA1_STREAM2_ENABLE)
#define YSS_DMA_MAP_SPI1_RX_STREAM &dma1Stream2
#else
#define YSS_DMA_MAP_SPI1_RX_STREAM 0
#endif
#define YSS_DMA_MAP_SPI1_RX_CHANNEL 0

#if defined(DMA1_STREAM5_ENABLE)
#define YSS_DMA_MAP_SPI2_TX_STREAM &dma1Stream5
#else
#define YSS_DMA_MAP_SPI2_TX_STREAM 0
#endif
#define YSS_DMA_MAP_SPI2_TX_CHANNEL 0

#if defined(DMA1_STREAM4_ENABLE)
#define YSS_DMA_MAP_SPI2_RX_STREAM &dma1Stream4
#else
#define YSS_DMA_MAP_SPI2_RX_STREAM 0
#endif
#define YSS_DMA_MAP_SPI2_RX_CHANNEL 0

#if defined(DMA2_STREAM2_ENABLE)
#define YSS_DMA_MAP_SPI3_TX_STREAM &dma2Stream2
#else
#define YSS_DMA_MAP_SPI3_TX_STREAM 0
#endif
#define YSS_DMA_MAP_SPI3_TX_CHANNEL 0

#if defined(DMA2_STREAM1_ENABLE)
#define YSS_DMA_MAP_SPI3_RX_STREAM &dma2Stream1
#else
#define YSS_DMA_MAP_SPI3_RX_STREAM 0
#endif
#define YSS_DMA_MAP_SPI3_RX_CHANNEL 0

#elif defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                 \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                 \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                         \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                         \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                         \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

#if defined(DMA1_STREAM4_ENABLE)
#define YSS_DMA_MAP_UART1_TX_STREAM &dma1Stream4
#else
#define YSS_DMA_MAP_UART1_TX_STREAM *(drv::Stream *)0
#endif
#define YSS_DMA_MAP_UART1_TX_CHANNEL 0

#if defined(DMA1_STREAM7_ENABLE)
#define YSS_DMA_MAP_UART2_TX_STREAM &dma1Stream7
#else
#define YSS_DMA_MAP_UART2_TX_STREAM *(drv::Stream *)0
#endif
#define YSS_DMA_MAP_UART2_TX_CHANNEL 0


#endif

#endif