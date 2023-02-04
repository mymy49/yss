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

#ifndef YSS_DRV_DMA_ST_TYPE_A_MAP__H_
#define YSS_DRV_DMA_ST_TYPE_A_MAP__H_

#include <drv/mcu.h>

#if defined(STM32F7) || defined(STM32F4)

#define YSS_DMA_MAP_UART1_TX_STREAM &dma2Stream7
#define YSS_DMA_MAP_UART1_TX_CHANNEL define::dma2::stream7::USART1_TX

#define YSS_DMA_MAP_UART2_TX_STREAM &dma1Stream6
#define YSS_DMA_MAP_UART2_TX_CHANNEL define::dma1::stream6::USART2_TX

#define YSS_DMA_MAP_UART3_TX_STREAM &dma1Stream3
#define YSS_DMA_MAP_UART3_TX_CHANNEL define::dma1::stream3::USART3_TX

#define YSS_DMA_MAP_UART4_TX_STREAM &dma1Stream4
#define YSS_DMA_MAP_UART4_TX_CHANNEL define::dma1::stream4::UART4_TX

#define YSS_DMA_MAP_UART5_TX_STREAM &dma1Stream7
#define YSS_DMA_MAP_UART5_TX_CHANNEL define::dma1::stream7::UART5_TX

#define YSS_DMA_MAP_UART6_TX_STREAM &dma2Stream6
#define YSS_DMA_MAP_UART6_TX_CHANNEL define::dma2::stream6::USART6_TX

#define YSS_DMA_MAP_UART7_TX_STREAM &dma1Stream1
#define YSS_DMA_MAP_UART7_TX_CHANNEL define::dma1::stream1::UART7_TX

#define YSS_DMA_MAP_UART8_TX_STREAM &dma1Stream0
#define YSS_DMA_MAP_UART8_TX_CHANNEL define::dma1::stream0::UART8_TX

#define YSS_DMA_MAP_I2C1_TX_STREAM &dma1Stream6
#define YSS_DMA_MAP_I2C1_TX_CHANNEL define::dma1::stream6::I2C1_TX

#define YSS_DMA_MAP_I2C2_TX_STREAM &dma1Stream7
#define YSS_DMA_MAP_I2C2_TX_CHANNEL define::dma1::stream7::I2C2_TX

#define YSS_DMA_MAP_I2C3_TX_STREAM &dma1Stream4
#define YSS_DMA_MAP_I2C3_TX_CHANNEL define::dma1::stream4::I2C3_TX

#define YSS_DMA_MAP_I2C4_TX_STREAM &dma1Stream6
#define YSS_DMA_MAP_I2C4_TX_CHANNEL define::dma1::stream6::I2C4_TX

#define YSS_DMA_MAP_I2C1_RX_STREAM &dma1Stream0
#define YSS_DMA_MAP_I2C1_RX_CHANNEL define::dma1::stream0::I2C1_RX

#define YSS_DMA_MAP_I2C2_RX_STREAM &dma1Stream2
#define YSS_DMA_MAP_I2C2_RX_CHANNEL define::dma1::stream2::I2C2_RX

#define YSS_DMA_MAP_I2C3_RX_STREAM &dma1Stream2
#define YSS_DMA_MAP_I2C3_RX_CHANNEL define::dma1::stream2::I2C3_RX

#define YSS_DMA_MAP_I2C4_RX_STREAM &dma1Stream1
#define YSS_DMA_MAP_I2C4_RX_CHANNEL define::dma1::stream1::I2C4_RX

#define YSS_DMA_MAP_QUADSPI_STREAM &dma2Stream7
#define YSS_DMA_MAP_QUADSPI_CHANNEL define::dma2::stream7::QUADSPI_DMA

#define YSS_DMA_MAP_SDMMC1_STREAM &dma2Stream3
#define YSS_DMA_MAP_SDMMC1_CHANNEL define::dma2::stream3::SDIO_DMA

#define YSS_DMA_MAP_SPI1_RX_STREAM &dma2Stream0
#define YSS_DMA_MAP_SPI1_RX_CHANNEL define::dma2::stream0::SPI1_RX

#define YSS_DMA_MAP_SPI1_TX_STREAM &dma2Stream3
#define YSS_DMA_MAP_SPI1_TX_CHANNEL define::dma2::stream3::SPI1_TX

#define YSS_DMA_MAP_SPI2_RX_STREAM &dma1Stream3
#define YSS_DMA_MAP_SPI2_RX_CHANNEL define::dma1::stream3::SPI2_RX

#define YSS_DMA_MAP_SPI2_TX_STREAM &dma1Stream4
#define YSS_DMA_MAP_SPI2_TX_CHANNEL define::dma1::stream4::SPI2_TX

#define YSS_DMA_MAP_SPI3_RX_STREAM &dma1Stream0
#define YSS_DMA_MAP_SPI3_RX_CHANNEL define::dma1::stream0::SPI3_RX

#define YSS_DMA_MAP_SPI3_TX_STREAM &dma1Stream5
#define YSS_DMA_MAP_SPI3_TX_CHANNEL define::dma1::stream5::SPI3_TX

#define YSS_DMA_MAP_SPI4_RX_STREAM &dma2Stream0
#define YSS_DMA_MAP_SPI4_RX_CHANNEL define::dma2::stream0::SPI4_RX

#define YSS_DMA_MAP_SPI4_TX_STREAM &dma2Stream1
#define YSS_DMA_MAP_SPI4_TX_CHANNEL define::dma2::stream1::SPI4_TX

#define YSS_DMA_MAP_SPI5_RX_STREAM &dma2Stream3
#define YSS_DMA_MAP_SPI5_RX_CHANNEL define::dma2::stream3::SPI5_RX

#define YSS_DMA_MAP_SPI5_TX_STREAM &dma2Stream3
#define YSS_DMA_MAP_SPI5_TX_CHANNEL define::dma2::stream4::SPI5_TX

#define YSS_DMA_MAP_SPI6_RX_STREAM &dma2Stream6
#define YSS_DMA_MAP_SPI6_RX_CHANNEL define::dma2::stream6::SPI6_RX

#define YSS_DMA_MAP_SPI6_TX_STREAM &dma2Stream5
#define YSS_DMA_MAP_SPI6_TX_CHANNEL define::dma2::stream5::SPI6_TX

#define YSS_DMA_MAP_SAI1_A_STREAM &dma2Stream1
#define YSS_DMA_MAP_SAI1_A_CHANNEL define::dma2::stream1::SAI1_A

#define YSS_DMA_MAP_SAI1_B_STREAM &dma2Stream5
#define YSS_DMA_MAP_SAI1_B_CHANNEL define::dma2::stream5::SAI1_B

#define YSS_DMA_MAP_SAI2_A_STREAM &dma2Stream4
#define YSS_DMA_MAP_SAI2_A_CHANNEL define::dma2::stream4::SAI2_A

#define YSS_DMA_MAP_SAI2_B_STREAM &dma2Stream4
#define YSS_DMA_MAP_SAI2_B_CHANNEL define::dma2::stream6::SAI2_B

#endif

#endif