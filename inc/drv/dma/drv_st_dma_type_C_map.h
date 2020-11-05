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

#if	defined (STM32G431xx) || defined (STM32G441xx) || \
	defined (STM32G471xx) || defined (STM32G473xx) || defined (STM32G474xx) || defined (STM32G483xx) || defined (STM32G484xx) || defined (STM32GBK1CB)
/*
#if defined(DMA1_STREAM6_ENABLE)
#define YSS_DMA_MAP_I2C1_TX_STREAM		&dma1Stream6
#else
#define YSS_DMA_MAP_I2C1_TX_STREAM		*(drv::Stream*)0
#endif

#if defined(DMA1_STREAM7_ENABLE)
#define YSS_DMA_MAP_I2C1_RX_STREAM		&dma1Stream7
#else
#define YSS_DMA_MAP_I2C1_RX_STREAM		*(drv::Stream*)0
#endif

#if defined(DMA1_STREAM4_ENABLE)
#define YSS_DMA_MAP_I2C2_TX_STREAM		&dma1Stream4
#else
#define YSS_DMA_MAP_I2C2_TX_STREAM		*(drv::Stream*)0
#endif

#if defined(DMA1_STREAM5_ENABLE)
#define YSS_DMA_MAP_I2C2_RX_STREAM		&dma1Stream5
#else
#define YSS_DMA_MAP_I2C2_RX_STREAM		*(drv::Stream*)0
#endif

#if defined(DMA1_STREAM4_ENABLE)
#define YSS_DMA_MAP_UART1_TX_STREAM		&dma1Stream4
#else
#define YSS_DMA_MAP_UART1_TX_STREAM		*(drv::Stream*)0
#endif
#define YSS_DMA_MAP_UART1_TX_CHANNEL	0

#if defined(DMA1_STREAM7_ENABLE)
#define YSS_DMA_MAP_UART2_TX_STREAM		&dma1Stream7
#else
#define YSS_DMA_MAP_UART2_TX_STREAM		*(drv::Stream*)0
#endif
#define YSS_DMA_MAP_UART2_TX_CHANNEL	0

#if defined(DMA1_STREAM2_ENABLE)
#define YSS_DMA_MAP_UART3_TX_STREAM		&dma1Stream2
#else
#define YSS_DMA_MAP_UART3_TX_STREAM		*(drv::Stream*)0
#endif
#define YSS_DMA_MAP_UART3_TX_CHANNEL	0

#if defined(DMA2_STREAM5_ENABLE)
#define YSS_DMA_MAP_UART4_TX_STREAM		&dma2Stream5
#else
#define YSS_DMA_MAP_UART4_TX_STREAM		*(drv::Stream*)0
#endif
#define YSS_DMA_MAP_UART4_TX_CHANNEL	0

#if defined(DMA1_STREAM7_ENABLE)
#define YSS_DMA_MAP_UART5_TX_STREAM		&dma1Stream7
#else
#define YSS_DMA_MAP_UART5_TX_STREAM		*(drv::Stream*)0
#endif
#define YSS_DMA_MAP_UART5_TX_CHANNEL	0

#if defined(DMA1_STREAM3_ENABLE)
#define YSS_DMA_MAP_SPI1_TX_STREAM		&dma1Stream3
#else
#define YSS_DMA_MAP_SPI1_TX_STREAM		0
#endif
#define YSS_DMA_MAP_SPI1_TX_CHANNEL		0

#if defined(DMA1_STREAM2_ENABLE)
#define YSS_DMA_MAP_SPI1_RX_STREAM		&dma1Stream2
#else
#define YSS_DMA_MAP_SPI1_RX_STREAM		0
#endif
#define YSS_DMA_MAP_SPI1_RX_CHANNEL		0

#if defined(DMA1_STREAM5_ENABLE)
#define YSS_DMA_MAP_SPI2_TX_STREAM		&dma1Stream5
#else
#define YSS_DMA_MAP_SPI2_TX_STREAM		0
#endif
#define YSS_DMA_MAP_SPI2_TX_CHANNEL		0

#if defined(DMA1_STREAM4_ENABLE)
#define YSS_DMA_MAP_SPI2_RX_STREAM		&dma1Stream4
#else
#define YSS_DMA_MAP_SPI2_RX_STREAM		0
#endif
#define YSS_DMA_MAP_SPI2_RX_CHANNEL		0

#if defined(DMA2_STREAM2_ENABLE)
#define YSS_DMA_MAP_SPI3_TX_STREAM		&dma2Stream2
#else
#define YSS_DMA_MAP_SPI3_TX_STREAM		0
#endif
#define YSS_DMA_MAP_SPI3_TX_CHANNEL		0

#if defined(DMA2_STREAM1_ENABLE)
#define YSS_DMA_MAP_SPI3_RX_STREAM		&dma2Stream1
#else
#define YSS_DMA_MAP_SPI3_RX_STREAM		0
#endif
#define YSS_DMA_MAP_SPI3_RX_CHANNEL		0
*/
/*




#if DMA2_STREAM6_ENABLE_CHECK
#define YSS_DMA_MAP_UART6_TX_STREAM		dma2Stream6
#define YSS_DMA_MAP_UART6_TX_CHANNEL	define::dma2::stream6::USART6_TX
#elif DMA2_STREAM7_ENABLE_CHECK
#define YSS_DMA_MAP_UART6_TX_STREAM		dma2Stream7
#define YSS_DMA_MAP_UART6_TX_CHANNEL	define::dma2::stream7::USART6_TX
#else
#define YSS_DMA_MAP_UART6_TX_STREAM		0
#define YSS_DMA_MAP_UART6_TX_CHANNEL	0
#endif

#if DMA1_STREAM1_ENABLE_CHECK
#define YSS_DMA_MAP_UART7_TX_STREAM		dma1Stream1
#define YSS_DMA_MAP_UART7_TX_CHANNEL	define::dma1::stream1::UART7_TX
#else
#define YSS_DMA_MAP_UART7_TX_STREAM		0
#define YSS_DMA_MAP_UART7_TX_CHANNEL	0
#endif

#if DMA1_STREAM0_ENABLE_CHECK
#define YSS_DMA_MAP_UART8_TX_STREAM		dma1Stream0
#define YSS_DMA_MAP_UART8_TX_CHANNEL	define::dma1::stream0::UART8_TX
#elif DMA1_STREAM0_ENABLE_CHECK
#define YSS_DMA_MAP_UART8_TX_STREAM		dma1Stream6
#define YSS_DMA_MAP_UART8_TX_CHANNEL	define::dma1::stream6::UART8_TX
#else
#define YSS_DMA_MAP_UART8_TX_STREAM		0
#define YSS_DMA_MAP_UART8_TX_CHANNEL	0
#endif


#if DMA1_STREAM4_ENABLE_CHECK
#define YSS_DMA_MAP_I2C3_TX_STREAM		dma1Stream4
#define YSS_DMA_MAP_I2C3_TX_CHANNEL		define::dma1::stream4::I2C3_TX
#else
#define YSS_DMA_MAP_I2C3_TX_STREAM		0
#define YSS_DMA_MAP_I2C3_TX_CHANNEL		0
#endif

#if DMA1_STREAM6_ENABLE_CHECK
#define YSS_DMA_MAP_I2C4_TX_STREAM		dma1Stream6
#define YSS_DMA_MAP_I2C4_TX_CHANNEL		define::dma1::stream6::I2C4_TX
#else
#define YSS_DMA_MAP_I2C4_TX_STREAM		0
#define YSS_DMA_MAP_I2C4_TX_CHANNEL		0
#endif




#if DMA1_STREAM2_ENABLE_CHECK
#define YSS_DMA_MAP_I2C3_RX_STREAM		dma1Stream2
#define YSS_DMA_MAP_I2C3_RX_CHANNEL		define::dma1::stream2::I2C3_RX
#else
#define YSS_DMA_MAP_I2C3_RX_STREAM		0
#define YSS_DMA_MAP_I2C3_RX_CHANNEL		0
#endif

#if DMA1_STREAM1_ENABLE_CHECK
#define YSS_DMA_MAP_I2C4_RX_STREAM		dma1Stream1
#define YSS_DMA_MAP_I2C4_RX_CHANNEL		define::dma1::stream1::I2C4_RX
#else
#define YSS_DMA_MAP_I2C4_RX_STREAM		0
#define YSS_DMA_MAP_I2C4_RX_CHANNEL		0
#endif

#if DMA2_STREAM7_ENABLE_CHECK
#define YSS_DMA_MAP_QUADSPI_STREAM		dma2Stream7
#define YSS_DMA_MAP_QUADSPI_CHANNEL		define::dma1::stream1::QUADSPI
#else
#define YSS_DMA_MAP_QUADSPI_STREAM		0
#define YSS_DMA_MAP_QUADSPI_CHANNEL		0
#endif
*/
#endif

#endif
