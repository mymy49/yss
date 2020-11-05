////////////////////////////////////////////////////////////////////////////////////////
//
//	저작권	표기	License_ver_1.2
//	본 소스코드의	소유권은 홍윤기에게 있습니다.
//	본 소스코드는	아래 사항에 동의할 경우에 사용 가능합니다.
//	아래 사항에 대해 동의하지 않거나 이해하지	못했을	경우 사용을 금합니다.
//	본 소스코드를	사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주	합니다.
//	본 소스코드의	상업적	또는 비상업적	이용이	가능합니다.
//	본 소스코드의	내용을	임의로	수정하여 재배포하는 행위를 금합니다.
//	본 소스코드의	내용을	무단 전재하는	행위를	금합니다.
//	본 소스코드의	사용으로 인해	발생하는 모든	사고에	대해서	어떤한	법적 책임을 지지 않습니다.
//
//	E-mail : mymy49@nate.com
//	Home Page :	http://cafe.naver.com/yssoperatingsystem
//	Copyright 2017.	Yoon-Ki	Hong all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <config.h>

#if defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <drv/peripherals.h>


#if DMA1_STREAM0_ENABLE_CHECK
drv::Stream	dma1Stream0(DMA1_Stream0);
#endif

#if DMA1_STREAM1_ENABLE_CHECK
drv::Stream	dma1Stream1(DMA1_Stream1);
#endif

#if DMA1_STREAM2_ENABLE_CHECK
drv::Stream	dma1Stream2(DMA1_Stream2);
#endif

#if DMA1_STREAM3_ENABLE_CHECK
drv::Stream	dma1Stream3(DMA1_Stream3);
#endif

#if DMA1_STREAM4_ENABLE_CHECK
drv::Stream	dma1Stream4(DMA1_Stream4);
#endif

#if DMA1_STREAM5_ENABLE_CHECK
drv::Stream	dma1Stream5(DMA1_Stream5);
#endif

#if DMA1_STREAM6_ENABLE_CHECK
drv::Stream	dma1Stream6(DMA1_Stream6);
#endif

#if DMA1_STREAM7_ENABLE_CHECK
drv::Stream	dma1Stream7(DMA1_Stream7);
#endif

#if DMA2_STREAM0_ENABLE_CHECK
drv::Stream	dma2Stream0(DMA2_Stream0);
#endif

#if DMA2_STREAM1_ENABLE_CHECK
drv::Stream	dma2Stream1(DMA2_Stream1);
#endif

#if DMA2_STREAM2_ENABLE_CHECK
drv::Stream	dma2Stream2(DMA2_Stream2);
#endif

#if DMA2_STREAM3_ENABLE_CHECK
drv::Stream	dma2Stream3(DMA2_Stream3);
#endif

#if DMA2_STREAM4_ENABLE_CHECK
drv::Stream	dma2Stream4(DMA2_Stream4);
#endif

#if DMA2_STREAM5_ENABLE_CHECK
drv::Stream	dma2Stream5(DMA2_Stream5);
#endif

#if DMA2_STREAM6_ENABLE_CHECK
drv::Stream	dma2Stream6(DMA2_Stream6);
#endif

#if DMA2_STREAM7_ENABLE_CHECK
drv::Stream	dma2Stream7(DMA2_Stream7);
#endif

unsigned long getTimerApb2ClkFreq(void)
{
	return clock.peripheral.getTimerApb2ClkFreq();
}

unsigned long getTimerApb1ClkFreq(void)
{
	return clock.peripheral.getTimerApb1ClkFreq();
}


#if	defined(SYSCFG)
//drv::Syscfg	syscfg;
#endif

#if	defined(RTC)
//drv::Rtc rtc(YSS_BSP.rtcConfig);
#endif

#if	defined(USART1)
//drv::Uart1 uart1(USART1, YSS_DMA_MAP_UART1_TX_STREAM, YSS_DMA_MAP_UART1_TX_CHANNEL, define::dma::priorityLevel::LOW);
#endif

#if	defined(USART2)
//drv::Uart2 uart2(USART2, YSS_DMA_MAP_UART2_TX_STREAM, YSS_DMA_MAP_UART2_TX_CHANNEL, define::dma::priorityLevel::LOW);
#endif

#if	defined(USART3)
//drv::Uart3 uart3(USART3, YSS_DMA_MAP_UART3_TX_STREAM, YSS_DMA_MAP_UART3_TX_CHANNEL, define::dma::priorityLevel::LOW);
#endif

#if	defined(UART4)
//drv::Uart4 uart4(UART4,	YSS_DMA_MAP_UART4_TX_STREAM, YSS_DMA_MAP_UART4_TX_CHANNEL,	define::dma::priorityLevel::LOW);
#endif

#if	defined(UART5)
//drv::Uart5 uart5(UART5,	YSS_DMA_MAP_UART5_TX_STREAM, YSS_DMA_MAP_UART5_TX_CHANNEL,	define::dma::priorityLevel::LOW);
#endif

#if	defined(USART6)
//drv::Uart6 uart6(USART6, YSS_DMA_MAP_UART6_TX_STREAM, YSS_DMA_MAP_UART6_TX_CHANNEL, define::dma::priorityLevel::LOW);
#endif

#if	defined(UART7)
//drv::Uart7 uart7(UART7,	YSS_DMA_MAP_UART7_TX_STREAM, YSS_DMA_MAP_UART7_TX_CHANNEL,	define::dma::priorityLevel::LOW);
#endif

#if	defined(UART8)
//drv::Uart8 uart8(UART8,	YSS_DMA_MAP_UART8_TX_STREAM, YSS_DMA_MAP_UART8_TX_CHANNEL,	define::dma::priorityLevel::LOW);
#endif

#if	defined(I2C1)
//drv::I2c i2c1(I2C1, YSS_DMA_MAP_I2C1_TX_STREAM, YSS_DMA_MAP_I2C1_RX_STREAM, YSS_DMA_MAP_I2C1_TX_CHANNEL, YSS_DMA_MAP_I2C1_RX_CHANNEL, define::dma::priorityLevel::LOW);
#endif

#if	defined(I2C2)
//drv::I2c i2c2(I2C2, YSS_DMA_MAP_I2C2_TX_STREAM, YSS_DMA_MAP_I2C2_RX_STREAM, YSS_DMA_MAP_I2C2_TX_CHANNEL, YSS_DMA_MAP_I2C2_RX_CHANNEL, define::dma::priorityLevel::LOW);
#endif

#if	defined(I2C3)
//drv::I2c i2c3(I2C3, YSS_DMA_MAP_I2C3_TX_STREAM, YSS_DMA_MAP_I2C3_RX_STREAM, YSS_DMA_MAP_I2C3_TX_CHANNEL, YSS_DMA_MAP_I2C3_RX_CHANNEL, define::dma::priorityLevel::LOW);
#endif

#if	defined(I2C4)
drv::I2c i2c4(I2C4, YSS_DMA_MAP_I2C4_TX_STREAM, YSS_DMA_MAP_I2C4_RX_STREAM, YSS_DMA_MAP_I2C4_TX_CHANNEL, YSS_DMA_MAP_I2C4_RX_CHANNEL, define::dma::priorityLevel::LOW);
#endif

#if defined(EXTI)
//drv::Exti exti;
#endif

#if defined(LTDC)
//drv::Ltdc ltdc;
#endif

#if defined(DMA2D) && USE_GUI == true
//drv::Dma2d dma2d;
#endif

/*
#if defined(USB_OTG_FS)
static config::usbd::Config gUsbdFsConfig =
{
	USB_OTG_FS,
	5,
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x20),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x40),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x60),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x80),
	0,
	0,
	0,
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x20),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x40),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x60),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x80),
	0,
	0,
	0,
	320,		// unsigned short maxFifoSize;
	0x80,		// unsigned short outFifoSize;
	0x40,		// unsigned short inFifoSize[8];
	0x0,
	0x40
};
drv::Usbd usbdFs(gUsbdFsConfig);
#endif

#if defined(USB_OTG_HS)
static config::usbd::Config gUsbdHsConfig =
{
	USB_OTG_HS,
	5,
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x20),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x40),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x60),
	(USB_OTG_INEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_IN_ENDPOINT_BASE + 0x80),
	0,
	0,
	0,
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x20),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x40),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x60),
	(USB_OTG_OUTEndpointTypeDef*)((unsigned long)USB_OTG_FS + USB_OTG_OUT_ENDPOINT_BASE + 0x80),
	0,
	0,
	0,
	320,		// unsigned short maxFifoSize;
	0x40,		// unsigned short outFifoSize;
	0x40,		// unsigned short inFifoSize[8];
	0x0,
	0x40
};
drv::Usbd usbdHs(gUsbdHsConfig);
#endif
*/
#if defined(QUADSPI)
drv::Quadspi quadspi(YSS_DMA_MAP_QUADSPI_STREAM, YSS_DMA_MAP_QUADSPI_CHANNEL, define::dma::priorityLevel::LOW);
#endif

#endif
