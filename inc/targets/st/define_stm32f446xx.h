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

#ifndef YSS_DEFINE_STM32F446XX__H_
#define YSS_DEFINE_STM32F446XX__H_

#if defined(STM32F446xx)

namespace define
{
	namespace gpio
	{
		namespace altfunc
		{
			enum
			{
				PA0_TIM2_CH1 = 1,
				PA0_TIM2_ETR = 1,
				PA0_TIM5_CH1 = 2,
				PA0_TIM8_ETR = 3,
				PA0_USART2_CTS = 7,
				PA0_UART4_TX = 8,
				PA0_EVENTOUT = 15,

				PA1_TIM2_CH2 = 1,
				PA1_TIM5_CH2 = 2,
				PA1_USART2_RTS = 7,
				PA1_UART4_RX = 8,
				PA1_QUADSPI_BK1_IO3 = 9,
				PA1_SAI2_MCLK_B = 10,
				PA1_EVENTOUT = 15,

				PA2_TIM2_CH3 = 1,
				PA2_TIM5_CH3 = 2,
				PA2_TIM9_CH1 = 3,
				PA2_USART2_TX = 7,
				PA2_SAI2_SCK_B = 8,
				PA2_EVENTOUT = 15,
	
				PA3_TIM2_CH4 = 1,
				PA3_TIM5_CH4 = 2,
				PA3_TIM9_CH2 = 3,
				PA3_SAI1_FS_A = 6,
				PA3_USART2_RX = 7,
				PA3_OTG_HS_ULPI_D0 = 10,
				PA3_EVENTOUT = 15,
	
				PA4_SPI1_NSS = 5,
				PA4_I2S1_WS = 5,
				PA4_SPI3_NSS = 6,
				PA4_I2S3_WS = 6,
				PA4_USART2_CK = 7,
				PA4_OTG_HS_SOF = 12,
				PA4_DCMI_HSYNC = 13,
				PA4_EVENTOUT = 15,
	
				PA5_TIM2_CH1 = 1,
				PA5_TIM2_ETR = 1,
				PA5_TIM8_CH1N = 3,
				PA5_SPI1_SCK = 5,
				PA5_I2S1_CK = 5,
				PA5_OTG_HS_ULPI_CK = 10,
				PA5_EVENTOUT = 15,

				PA6_TIM1_BKIN = 1,
				PA6_TIM3_CH1 = 2,
				PA6_TIM8_BKIN = 3,
				PA6_SPI1_MISO = 5,
				PA6_I2S2_MCK = 6,
				PA6_TIM13_CH1 = 9,
				PA6_DCMI_PIXCLK = 13,
				PA6_EVENTOUT = 15,

				PA7_TIM1_CH1N = 1,
				PA7_TIM3_CH2 = 2,
				PA7_TIM8_CH1N = 3,
				PA7_SPI1_MOSI = 5,
				PA7_I2S1_SD = 5,
				PA7_TIM14_CH1 = 9,
				PA7_FMC_SDNWE = 12,
				PA7_EVENTOUT = 15,

				PA8_MCO1 = 0,
				PA8_TIM1_CH1 = 1,
				PA8_I2C3_SCL = 4,
				PA8_USART1_CK = 7,
				PA8_OTG_FS_SOF = 10,
				PA8_EVENTOUT = 15,

				PA9_TIM1_CH2 = 1,
				PA9_I2C3_SMBA = 4,
				PA9_SPI2_SCK = 5,
				PA9_I2S2_CK = 5,
				PA9_SAI1_SD_B = 6,
				PA9_USART1_TX = 7,
				PA9_DCMI_D0 = 13,
				PA9_EVENTOUT = 15,

				PA10_TIM1_CH3 = 1,
				PA10_USART1_RX = 7,
				PA10_OTG_FS_ID = 10,
				PA10_DCMI_D1 = 13,
				PA10_EVENTOUT = 15,

				PA11_TIM1_CH4 = 1,
				PA11_USART1_CTS = 7,
				PA11_CAN1_RX = 9,
				PA11_OTG_FS_DM = 10,
				PA11_EVENTOUT = 15,

				PA12_TIM1_ETR = 1,
				PA12_USART1_RTS = 7,
				PA12_SAI2_FS_B = 8,
				PA12_CAN1_TX = 9,
				PA12_OTG_FS_DP = 10,
				PA12_EVENTOUT = 15,

				PA13_JTMS = 0,
				PA13_SWDIO = 0,
				PA13_EVENTOUT = 15,

				PA14_JTCK = 0,
				PA14_SWCLK = 0,
				PA14_EVENTOUT = 15,

				PA15_JTDI = 0,
				PA15_TIM2_CH1 = 1,
				PA15_TIM2_ETR = 1,
				PA15_HDMI_CEC = 4,
				PA15_SPI1_NSS = 5,
				PA15_I2S1_WS = 5,
				PA15_SPI3_NSS = 6,
				PA15_I2S3_WS = 6,
				PA15_UART4_RTS = 8,
				PA15_EVENTOUT = 15,

				PB0_TIM1_CH2N = 1,
				PB0_TIM3_CH3 = 2,
				PB0_TIM8_CH2N = 3,
				PB0_SPI3_MOSI = 7,
				PB0_I2S3_SD = 7,
				PB0_UART4_CTS = 8,
				PB0_OTG_HS_ULPI_D1 = 10,
				PB0_SDIO_D1 = 12,
				PB0_EVENTOUT = 15,

				PB1_TIM1_CH3N = 1,
				PB1_TIM3_CH4 = 2,
				PB1_TIM8_CH3N = 3,
				PB1_OTG_HS_ULPI_D2 = 10,
				PB1_SDIO_D2 = 12,
				PB1_EVENTOUT = 15,
	
				PB2_TIM2_CH4 = 1,
				PB2_SAI1_SD_A = 6,
				PB2_SPI3_MOSI = 7,
				PB2_I2S3_SD = 7,
				PB2_QUADSPI_CLK = 9,
				PB2_OTG_HS_ULPI_D4 = 10,
				PB2_SDIO_CK = 12,
				PB2_EVENTOUT = 15,

				PB3_JTDO = 0,
				PB3_TRACESWO = 0,
				PB3_TIM2_CH2 = 1,
				PB3_I2C2_SDA = 4,
				PB3_SPI1_SCK = 5,
				PB3_I2S1_CK = 5,
				PB3_SPI3_SCK = 6,
				PB3_I2S3_CK = 6,
				PB3_EVENTOUT = 15,

				PB4_NJTRST = 0,
				PB4_TIM3_CH1 = 2,
				PB4_I2C3_SDA = 4,
				PB4_SPI1_MISO = 5,
				PB4_SPI3_MISO = 6,
				PB4_SPI2_NSS = 7,
				PB4_I2S2_WS = 7,
				PB4_EVENTOUT = 15,

				PB5_TIM3_CH2 = 2,
				PB5_I2C1_SMBA = 4,
				PB5_SPI1_MOSI = 5,
				PB5_I2S1_SD = 5,
				PB5_SPI3_MOSI = 6,
				PB5_I2S3_SD = 6,
				PB5_CAN2_RX = 9,
				PB5_OTG_HS_ULPI_D7 = 10,
				PB5_FMC_SDCKE1 = 12,
				PB5_DCMI_D10 = 13,
				PB5_EVENTOUT = 15,

				PB6_TIM4_CH1 = 2,
				PB6_HDMI_CEC = 3,
				PB6_I2C1_SCL = 4,
				PB6_USART1_TX = 7,
				PB6_CAN2_TX = 9,
				PB6_QUADSPI_BK1_NCS = 10,
				PB6_FMC_SDNE1 = 12,
				PB6_DCMI_D5 = 13,
				PB6_EVENTOUT = 15,

				PB7_TIM4_CH2 = 2,
				PB7_I2C1_SDA = 4,
				PB7_USART1_RX = 7,
				PB7_SPDIF_RX0 = 8,
				PB7_FMC_NL = 12,
				PB7_DCMI_VSYNC = 13,
				PB7_EVENTOUT = 15,
	
				PB8_TIM2_CH1 = 1,
				PB8_TIM2_ETR = 1,
				PB8_TIM4_CH3 = 2,
				PB8_TIM10_CH1 = 3,
				PB8_I2C1_SCL = 4,
				PB8_CAN1_RX = 9,
				PB8_SDIO_D4 = 12,
				PB8_DCMI_D6 = 13,
				PB8_EVENTOUT = 15,
	
				PB9_TIM2_CH2 = 1,
				PB9_TIM4_CH4 = 2,
				PB9_TIM11_CH1 = 3,
				PB9_I2C1_SDA = 4,
				PB9_SPI2_NSS = 5,
				PB9_I2S2_WS = 5,
				PB9_SAI1_FS_B = 6,
				PB9_CAN1_TX = 9,
				PB9_SDIO_D5 = 12,
				PB9_DCMI_D7 = 13,
				PB9_EVENTOUT = 15,

				PB10_TIM2_CH3 = 1,
				PB10_I2C2_SCL = 4,
				PB10_SPI2_SCK = 5,
				PB10_I2S2_CK = 5,
				PB10_SAI1_SCK_A = 6,
				PB10_USART3_TX = 7,
				PB10_OTG_HS_ULPI_D3 = 10,
				PB10_EVENTOUT = 15,

				PB11_TIM2_CH4 = 1,
				PB11_I2C2_SDA = 4,
				PB11_USART3_RX = 7,
				PB11_SAI2_SD_A = 8,
				PB11_EVENTOUT = 15,

				PB12_TIM1_BKIN = 1,
				PB12_I2C2_SMBA = 4,
				PB12_SPI2_NSS = 5,
				PB12_I2S2_WS = 5,
				PB12_SAI1_SCK_B = 6,
				PB12_USART3_CK = 7,
				PB12_CAN2_RX = 9,
				PB12_OTG_HSULPI_D5 = 10,
				PB12_OTG_HS_ID = 12,
				PB12_EVENTOUT = 15,

				PB13_TIM1_CH1N = 1,
				PB13_SPI2_SCK = 5,
				PB13_I2S2_CK = 5,
				PB13_USART3_CTS = 7,
				PB13_CAN2_TX = 9,
				PB13_OTG_HS_ULPI_D6 = 10,
				PB13_EVENTOUT = 15,

				PB14_TIM1_CH2N = 1,
				PB14_TIM8_CH2N = 3,
				PB14_SPI2_MISO = 5,
				PB14_USART3_RTS = 7,
				PB14_TIM12_CH1 = 9,
				PB14_OTG_HS_DM = 12,
				PB14_EVENTOUT = 15,

				PB15_RTC_REFIN = 0,
				PB15_TIM1_CH3N = 1,
				PB15_TIM8_CH3N = 3,
				PB15_SPI2_MOSI = 5,
				PB15_I2S2_SD = 5,
				PB15_TIM12_CH2 = 9,
				PB15_OTG_HS_DP = 12,
				PB15_EVENTOUT = 15,
	
				PC0_SAI1_MCLK_B = 6,
				PC0_OTG_HS_ULPI_STP = 10,
				PC0_FMC_SDNWE = 12,
				PC0_EVENTOUT = 15,
	
				PC1_SPI3_MOSI = 5,
				PC1_I2S3_SD = 5,
				PC1_SAI1_SD_A = 6,
				PC1_SPI2_MOSI = 7,
				PC1_I2S2_SD = 7,
				PC1_EVENTOUT = 15,
	
				PC2_SPI2_MISO = 5,
				PC2_OTG_HS_ULPI_DIR = 10,
				PC2_FMC_SDNE0 = 12,
				PC2_EVENTOUT = 15,

				PC3_SPI2_MOSI = 5,
				PC3_I2S2_SD = 5,
				PC3_OTG_HS_ULPI_NXT = 10,
				PC3_FMC_SDCKE0 = 12,
				PC3_EVENTOUT = 15,
	
				PC4_I2S1_MCK = 5,
				PC4_SPDIF_RX2 = 8,
				PC4_FMC_SDNE0 = 12,
				PC4_EVENTOUT = 15,
	
				PC5_USART3_RX = 7,
				PC5_SPDIF_RX3 = 8,
				PC5_FMC_SDCKE0 = 12,
				PC5_EVENTOUT = 15,

				PC6_TIM3_CH1 = 2,
				PC6_TIM8_CH1 = 3,
				PC6_FMPI2C1_SCL = 4,
				PC6_I2S2_MCK = 5,
				PC6_USART6_TX = 8,
				PC6_SDIO_D6 = 12,
				PC6_DCMI_D0 = 13,
				PC6_EVENTOUT = 15,

				PC7_TIM3_CH2 = 2,
				PC7_TIM8_CH2 = 3,
				PC7_FMPI2C1_SDA = 4,
				PC7_SPI2_SCK = 5,
				PC7_I2S2_CK = 5,
				PC7_I2S3_MCK = 6,
				PC7_SPDIF_RX1 = 7,
				PC7_USART6_RX = 8,
				PC7_SDIO_D7 = 12,
				PC7_DCMI_D1 = 13,
				PC7_EVENTOUT = 15,
	
				PC8_TRACED0 = 0,
				PC8_TIM3_CH3 = 2,
				PC8_TIM8_CH3 = 3,
				PC8_UART5_RTS = 7,
				PC8_USART6_CK = 8,
				PC8_SDIO_D0 = 12,
				PC8_DCMI_D2 = 13,
				PC8_EVENTOUT = 15,

				PC9_MCO2 = 0,
				PC9_TIM3_CH4 = 2,
				PC9_TIM8_CH4 = 3,
				PC9_I2C3_SDA = 4,
				PC9_I2S_CKIN = 5,
				PC9_UART5_CTS = 7,
				PC9_QUADSPI_BK1_IO0 = 9,
				PC9_SDIO_D1 = 12,
				PC9_DCMI_D3 = 13,
				PC9_EVENTOUT = 15,

				PC10_SPI3_SCK = 6,
				PC10_I2S3_CK = 6,
				PC10_USART3_TX = 7,
				PC10_UART4_TX = 8,
				PC10_QUADSPI_BK1_IO1 = 9,
				PC10_SDIO_D2 = 12,
				PC10_DCMI_D8 = 13,
				PC10_EVENTOUT = 15,

				PC11_SPI3_MISO = 6,
				PC11_USART3_RX = 7,
				PC11_UART4_RX = 8,
				PC11_QUADSPI_BK2_NCS = 9,
				PC11_SDIO_D3 = 12,
				PC11_DCMI_D4 = 13,
				PC11_EVENTOUT = 15,

				PC12_I2C2_SDA = 4,
				PC12_SPI3_MOSI = 6,
				PC12_I2S3_SD = 6,
				PC12_USART3_CK = 7,
				PC12_UART5_TX = 8,
				PC12_SDIO_CK = 12,
				PC12_DCMI_D9 = 13,
				PC12_EVENTOUT = 15,

				PC13_EVENTOUT = 15,

				PC14_EVENTOUT = 15,

				PC15_EVENTOUT = 15,
	
				PD0_SPI4_MISO = 5,
				PD0_SPI3_MOSI = 6,
				PD0_I2S3_SD = 6,
				PD0_CAN1_RX = 9,
				PD0_FMC_D2 = 12,
				PD0_EVENTOUT = 15,
	
				PD1_SPI2_NSS = 7,
				PD1_I2S2_WS = 7,
				PD1_CAN1_TX = 9,
				PD1_FMC_D3 = 12,
				PD1_EVENTOUT = 15,

				PD2_TIM3_ETR = 2,
				PD2_UART5_RX = 8,
				PD2_SDIO_CMD = 12,
				PD2_DCMI_D11 = 13,
				PD2_EVENTOUT = 15,
	
				PD3_TRACED1 = 0,
				PD3_SPI2_SCK = 5,
				PD3_I2S2_CK = 5,
				PD3_USART2_CTS = 7,
				PD3_QUADSPI_CLK = 9,
				PD3_FMC_CLK = 12,
				PD3_DCMI_D5 = 13,
				PD3_EVENTOUT = 15,

				PD4_USART2_RTS = 7,
				PD4_FMC_NOE = 12,
				PD4_EVENTOUT = 15,

				PD5_USART2_TX = 7,
				PD5_FMC_NWE = 12,
				PD5_EVENTOUT = 15,

				PD6_SPI3_MOSI = 5,
				PD6_I2S3_SD = 5,
				PD6_SAI1_SD_A = 6,
				PD6_USART2_RX = 7,
				PD6_FMC_NWAIT = 12,
				PD6_DCMI_D10 = 13,
				PD6_EVENTOUT = 15,

				PD7_USART2_CK = 7,
				PD7_SPDIF_RX0 = 8,
				PD7_FMC_NE1 = 12,
				PD7_EVENTOUT = 15,

				PD8_USART3_TX = 7,
				PD8_SPDIF_RX1 = 8,
				PD8_FMC_D13 = 12,
				PD8_EVENTOUT = 15,

				PD9_USART3_RX = 7,
				PD9_FMC_D14 = 12,
				PD9_EVENTOUT = 15,

				PD10_USART3_CK = 7,
				PD10_FMC_D15 = 12,
				PD10_EVENTOUT = 15,

				PD11_FMPI2C1_SMBA = 4,
				PD11_USART3_CTS = 7,
				PD11_QUADSPI_BK1_IO0 = 9,
				PD11_SAI2_SD_A = 10,
				PD11_FMC_A16 = 12,
				PD11_EVENTOUT = 15,

				PD12_TIM4_CH1 = 2,
				PD12_FMPI2C1_SCL = 4,
				PD12_USART3_RTS = 7,
				PD12_QUADSPI_BK1_IO1 = 9,
				PD12_SAI2_FS_A = 10,
				PD12_FMC_A17 = 12,
				PD12_EVENTOUT = 15,

				PD13_TIM4_CH2 = 2,
				PD13_FMPI2C1_SDA = 4,
				PD13_QUADSPI_BK1_IO3 = 9,
				PD13_SAI2_SCK_A = 10,
				PD13_FMC_A18 = 12,
				PD13_EVENTOUT = 15,

				PD14_TIM4_CH3 = 2,
				PD14_FMPI2C1_SCL = 4,
				PD14_SAI2_SCK_A = 8,
				PD14_FMC_D0 = 12,
				PD14_EVENTOUT = 15,

				PD15_TIM4_CH4 = 2,
				PD15_FMPI2C1_SDA = 4,
				PD15_FMC_D1 = 12,
				PD15_EVENTOUT = 15,

				PE0_TIM4_ETR = 2,
				PE0_SAI2_MCLK_A = 10,
				PE0_FMC_NBL0 = 12,
				PE0_DCMI_D2 = 13,
				PE0_EVENTOUT = 15,

				PE1_FMC_NBL1 = 12,
				PE1_DCMI_D3 = 13,
				PE1_EVENTOUT = 15,

				PE2_TRACECLK = 0,
				PE2_SPI4_CLK = 5,
				PE2_SAI1_MCLK_A = 6,
				PE2_QUADSPI_BK1_IO2 = 9,
				PE2_FMC_A23 = 12,
				PE2_EVENTOUT = 15,

				PE3_TRACED0 = 0,
				PE3_SAI1_SD_B = 6,
				PE3_FMC_A19 = 12,
				PE3_EVENTOUT = 15,

				PE4_TRACED1 = 0,
				PE4_SPI4_NSS = 5,
				PE4_SAI1_FS_A = 6,
				PE4_FMC_A20 = 12,
				PE4_DCMI_D4 = 13,
				PE4_EVENTOUT = 15,

				PE5_TRACED2 = 0,
				PE5_TIM9_CH1 = 3,
				PE5_SPI4_MISO = 5,
				PE5_SAI1_SCK_A = 6,
				PE5_FMC_A21 = 12,
				PE5_DCMI_D6 = 13,
				PE5_EVENTOUT = 15,

				PE6_TRACED3 = 0,
				PE6_TIM9_CH2 = 3,
				PE6_SPI4_MOSI = 5,
				PE6_SAI1_SD_A = 6,
				PE6_FMC_A22 = 12,
				PE6_DCMI_D7 = 13,
				PE6_EVENTOUT = 15,

				PE7_TIM1_ETR = 1,
				PE7_UART5_RX = 8,
				PE7_QUADSPI_BK2_IO0 = 10,
				PE7_FMC_D4 = 12,
				PE7_EVENTOUT = 15,

				PE8_TIM1_CH1N = 1,
				PE8_UART5_TX = 8,
				PE8_QUADSPI_BK2_IO1 = 10,
				PE8_FMC_D5 = 12,
				PE8_EVENTOUT = 15,

				PE9_TIM1_CH1 = 1,
				PE9_QUADSPI_BK2_IO2 = 10,
				PE9_FMC_D6 = 12,
				PE9_EVENTOUT = 15,

				PE10_TIM1_CH2N = 1,
				PE10_QUADSPI_BK2_IO3 = 10,
				PE10_FMC_D7 = 12,
				PE10_EVENTOUT = 15,

				PE11_TIM1_CH2 = 1,
				PE11_SPI4_NSS = 5,
				PE11_SAI2_SD_B = 10,
				PE11_FMC_D8 = 12,
				PE11_EVENTOUT = 15,

				PE12_TIM1_CH3N = 1,
				PE12_SPI4_SCK = 5,
				PE12_SAI2_SCK_B = 10,
				PE12_FMC_D9 = 12,
				PE12_EVENTOUT = 15,

				PE13_TIM1_CH3 = 1,
				PE13_SPI4_MISO = 5,
				PE13_SAI2_FS_B = 10,
				PE13_FMC_D10 = 12,
				PE13_EVENTOUT = 15,

				PE14_TIM1_CH4 = 1,
				PE14_SPI4_MOSI = 5,
				PE14_SAI2_MCLK_B = 10,
				PE14_FMC_D11 = 12,
				PE14_EVENTOUT = 15,

				PE15_TIM1_BKIN = 1,
				PE15_FMC_D12 = 12,
				PE15_EVENTOUT = 15,

				PF0_I2C2_SDA = 4,
				PF0_FMC_A0 = 12,
				PF0_EVENTOUT = 15,

				PF1_I2C2_SCL = 4,
				PF1_FMC_A1 = 12,
				PF1_EVENTOUT = 15,

				PF2_I2C2_SMBA = 4,
				PF2_FMC_A2 = 12,
				PF2_EVENTOUT = 15,

				PF3_FMC_A3 = 12,
				PF3_EVENTOUT = 15,

				PF4_FMC_A4 = 12,
				PF4_EVENTOUT = 15,

				PF5_FMC_A5 = 12,
				PF5_EVENTOUT = 15,

				PF6_TIM10_CH1 = 3,
				PF6_SAI1_SD_B = 6,
				PF6_QUADSPI_BK1_IO3 = 9,
				PF6_EVENTOUT = 15,

				PF7_TIM11_CH1 = 3,
				PF7_SAI1_MCLK_B = 6,
				PF7_QUADSPI_BK1_IO2 = 9,
				PF7_EVENTOUT = 15,

				PF8_SAI1_SCK_B = 6,
				PF8_TIM13_CH1 = 9,
				PF8_QUADSPI_BK1_IO0 = 10,
				PF8_EVENTOUT = 15,

				PF9_SAI1_FS_B = 6,
				PF9_TIM14_CH1 = 9,
				PF9_QUADSPI_BK1_IO1 = 10,
				PF9_EVENTOUT = 15,

				PF10_DCMI_D11 = 13,
				PF10_EVENTOUT = 15,
	
				PF11_SAI2_SD_B = 10,
				PF11_FMC_SDNRAS = 12,
				PF11_DCMI_D12 = 13,
				PF11_EVENTOUT = 15,

				PF12_FMC_A6 = 12,
				PF12_EVENTOUT = 15,
	
				PF13_FMPI2C1_SMBA = 4,
				PF13_FMC_A7 = 12,
				PF13_EVENTOUT = 15,
	
				PF14_FMPI2C1_SCL = 4,
				PF14_FMC_A8 = 12,
				PF14_EVENTOUT = 15,
	
				PF15_FMPI2C1_SDA = 4,
				PF15_FMC_A9 = 12,
				PF15_EVENTOUT = 15,

				PG0_FMC_A10 = 12,
				PG0_EVENTOUT = 15,

				PG1_FMC_A11 = 12,
				PG1_EVENTOUT = 15,

				PG2_FMC_A12 = 12,
				PG2_EVENTOUT = 15,

				PG3_FMC_A13 = 12,
				PG3_EVENTOUT = 15,

				PG4_FMC_A14 = 12,
				PG4_FMC_BA0 = 12,
				PG4_EVENTOUT = 15,

				PG5_FMC_A15 = 12,
				PG5_FMC_BA1 = 12,
				PG5_EVENTOUT = 15,
	
				PG6_QUADSPI_BK1_NCS = 10,	
				PG6_DCMI_D12 = 13,
				PG6_EVENTOUT = 15,

				PG7_USART6_CK = 8,
				PG7_FMC_INT3 = 12,
				PG7_DCMI_D13 = 13,
				PG7_EVENTOUT = 15,
	
				PG8_SPDIFRX_IN2 = 7,
				PG8_USART6_RTS = 8,
				PG8_FMC_SDCLK = 12,
				PG8_EVENTOUT = 15,
	
				PG9_SPDIFRX_IN3 = 7,
				PG9_USART6_RX = 8,
				PG9_QUADSPI_BK2_IO2 = 9,
				PG9_SAI2_FS_B = 10,
				PG9_FMC_NE2 = 12,
				PG9_FMC_NCE3 = 12,
				PG9_DCMI_VSYNC = 13,
				PG9_EVENTOUT = 15,
	
				PG10_SAI2_SD_B = 10,
				PG10_FMC_NE3 = 12,
				PG10_DCMI_D2 = 13,
				PG10_EVENTOUT = 15,
	
				PG11_SPI4_SCK = 6,
				PG11_SPDIFRX_IN0 = 7,
				PG11_DCMI_D3 = 13,
				PG11_EVENTOUT = 15,

				PG12_SPI4_MISO = 6,
				PG12_SPDIFRX_IN1 = 7,
				PG12_USART6_RTS = 8,
				PG12_FMC_NE4 = 12,
				PG12_EVENTOUT = 15,
	
				PG13_TRACED2 = 0,
				PG13_SPI4_MOSI = 6,
				PG13_USART6_CTS = 8,
				PG13_FMC_A24 = 12,
				PG13_EVENTOUT = 15,
	
				PG14_TRACED3 = 0,
				PG14_SPI4_NSS = 6,
				PG14_USART6_TX = 8,
				PG14_QUADSPI_BK2_IO3 = 9,
				PG14_FMC_A25 = 12,
				PG14_EVENTOUT = 15,

				PG15_USART6_CTS = 8,
				PG15_FMC_SDNCAS = 12,
				PG15_DCMI_D13 = 13,
				PG15_EVENTOUT = 15,

				PH0_EVENTOUT = 15,

				PH1_EVENTOUT = 15,
			};
		}

		namespace ospeed
		{
			enum
			{
				LOW = 0,
				MID = 1,
				FAST = 2,
				HIGH = 3,
			};
		}

		namespace otype
		{
			enum
			{
				PUSH_PULL = 0,
				OPEN_DRAIN = 1,
			};
		}

		namespace mode
		{
			enum
			{
				INPUT = 0,
				OUTPUT = 1,
				ALT_FUNC = 2,
				ANALOG = 3
			};
		}

		namespace pupd
		{
			enum
			{
				NONE = 0,
				PULL_UP = 1,
				PULL_DOWN = 2
			};
		}
	}

	namespace dma1
	{
		namespace stream0
		{
			enum
			{
				SPI3_RX = 0,
				I2C1_RX = 1,
				TIM4_CH1 = 2,
				I2S3_EXT_RX = 3,
				UART5_RX = 4,
				UART8_TX = 5,
				TIM5_CH3 = 6,
				TIM5_UP = 6
			};
		}

		namespace stream1
		{
			enum
			{
				TIM2_UP = 3,
				TIM2_CH3 = 3,
				UART3_RX = 4,
				UART7_TX = 5,
				TIM5_CH4 = 6,
				TIM5_TRIG = 6,
				TIM6_UP = 7,
				I2C4_RX = 8
			};
		}

		namespace stream2
		{
			enum
			{
				SPI3_RX = 0,
				TIM7_UP = 1,
				I2S3_EXT_RX = 2,
				I2C3_RX = 3,
				UART4_RX = 4,
				TIM3_CH4 = 5,
				TIM3_UP = 5,
				TIM5_CH1 = 6,
				I2C2_RX = 7
			};
		}

		namespace stream3
		{
			enum
			{
				SPI2_RX = 0,
				TIM4_CH2 = 2,
				I2S2_EXT_RX = 3,
				USART3_TX = 4,
				UART7_RX = 5,
				TIM5_CH4 = 6,
				TIM5_TRIG = 6,
				I2C2_RX = 7
			};
		}

		namespace stream4
		{
			enum
			{
				SPI2_TX = 0,
				TIM7_UP = 1,
				I2S2_EXT_TX = 2,
				I2C3_TX = 3,
				UART4_TX = 4,
				TIM3_CH1 = 5,
				TIM3_TRIG = 5,
				TIM5_CH2 = 6,
				USART3_TX = 7
			};
		}

		namespace stream5
		{
			enum
			{
				SPI3_TX = 0,
				I2C1_RX = 1,
				I2S3_EXT_TX = 2,
				TIM2_CH1 = 3,
				USART2_RX = 4,
				TIM3_CH2 = 5,
				DAC_CH1 = 7
			};
		}

		namespace stream6
		{
			enum
			{
				I2C1_TX = 1,
				TIM4_UP = 2,
				TIM2_CH2 = 3,
				TIM2_CH4 = 3,
				USART2_TX = 4,
				UART8_RX = 5,
				TIM5_UP = 6,
				DAC_CH2 = 7,
				I2C4_TX = 8
			};
		}

		namespace stream7
		{
			enum
			{
				SPI3_TX = 0,
				I2C1_TX = 1,
				TIM4_CH3 = 2,
				TIM2_UP = 3,
				TIM2_CH4 = 3,
				UART5_TX = 4,
				TIM3_CH3 = 5,
				I2C2_TX = 7
			};
		}
	}

	namespace dma2
	{
		namespace stream0
		{
			enum
			{
				ADC_CH1 = 0,
				ADC_CH3 = 2,
				SPI1_RX = 3,
				SPI4_RX = 4,
				TIM1_TRIG = 6
			};
		}

		namespace stream1
		{
			enum
			{
				SAI1_A = 0,
				DCMI_DMA = 1,
				ADC_CH3 = 2,
				SPI4_TX = 4,
				USART6_RX = 5,
				TIM1_CH1 = 6,
				TIM8_UP = 7
			};
		}

		namespace stream2
		{
			enum
			{
				TIM8_CH1_0 = 0,
				TIM8_CH2 = 0,
				TIM8_CH3 = 0,
				ADC_CH2 = 1,
				SPI1_RX = 3,
				USART1_RX = 4,
				USART6_RX = 5,
				TIM1_CH2 = 6,
				TIM8_CH1_7 = 7
			};
		}

		namespace stream3
		{
			enum
			{
				SAI1_A = 0,
				ADC_CH2 = 1,
				SPI5_RX = 2,
				SPI1_TX = 3,
				SDIO_DMA = 4,
				SPI4_RX = 5,
				TIM1_CH1 = 6,
				TIM8_CH2 = 7
			};
		}

		namespace stream4
		{
			enum
			{
				ADC_CH1 = 0,
				SAI1_B = 1,
				SPI5_TX = 2,
				SAI2_A = 3,
				SPI4_TX = 5,
				TIM1_CH4 = 6,
				TIM1_TRIG = 6,
				TIM1_COM = 6,
				TIM8_CH3 = 7
			};
		}

		namespace stream5
		{
			enum
			{
				SAI1_B = 0,
				SPI6_TX = 1,
				CRYP_OUT = 2,
				SPI1_TX = 3,
				USART1_RX = 4,
				TIM1_UP = 6,
				SPI5_RX = 7
			};
		}

		namespace stream6
		{
			enum
			{
				TIM1_CH1 = 0,
				TIM1_CH2 = 0,
				TIM1_CH3_0 = 0,
				SPI6_RX = 1,
				CRYP_IN = 2,
				SAI2_B = 3,
				SDIO_DMA = 4,
				USART6_TX = 5,
				TIM1_CH3_6 = 6,
				SPI5_TX = 7
			};
		}

		namespace stream7
		{
			enum
			{
				DCMI_DMA = 1,
				HASH_IN = 2,
				QUADSPI_DMA = 3,
				USART1_TX = 4,
				USART6_TX = 5,
				TIM8_CH4 = 7,
				TIM8_TRIG = 7,
				TIM8_COM = 7
			};
		}
	}
}

#endif

#endif

