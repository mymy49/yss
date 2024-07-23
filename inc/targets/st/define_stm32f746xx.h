/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DEFINE_STM32F767XX__H_
#define YSS_DEFINE_STM32F767XX__H_

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
				PA0_USART2_CTS = 7,
				PA0_UART4_TX = 8,
				PA0_ETH_MII_CRS = 11,
				PA0_EVENTOUT = 15,

				PA1_TIM2_CH2 = 1,
				PA1_TIM5_CH2 = 2,
				PA1_USART2_RTS = 7,
				PA1_UART4_RX = 8,
				PA1_ETH_MII_RX_CLK = 11,
				PA1_ETH_RMII_REF_CLK = 11,
				PA1_EVENTOUT = 15,

				PA2_TIM2_CH3 = 1,
				PA2_TIM5_CH3 = 2,
				PA2_TIM9_CH1 = 3,
				PA2_USART2_TX = 7,
				PA2_ETH_MDIO = 11,
				PA2_EVENTOUT = 15,

				PA3_TIM2_CH4 = 1,
				PA3_TIM5_CH4 = 2,
				PA3_TIM9_CH2 = 3,
				PA3_USART2_RX = 7,
				PA3_OTG_HS_ULPI_D0 = 10,
				PA3_ETH_MII_COL = 11,
				PA3_LCD_B5 = 14,
				PA3_EVENTOUT = 15,
	
				PA4_SPI1_NSS = 5,
				PA4_SPI3_NSS = 6,
				PA4_I2S3_WS = 6,
				PA4_USART2_CK = 7,
				PA4_OTG_HS_SOF = 12,
				PA4_DCMI_HSYNC = 13,
				PA4_LCD_VSYNC = 14,
				PA4_EVENTOUT = 15,
	
				PA5_TIM2_CH1 = 1,
				PA5_TIM2_ETR = 1,
				PA5_TIM8_CH1N = 3,
				PA5_SPI1_SCK = 5,
				PA5_OTG_HS_ULPI_CK = 10,
				PA5_EVENTOUT = 15,

				PA6_TIM1_BKIN = 1,
				PA6_TIM3_CH1 = 2,
				PA6_TIM8_BKIN = 3,
				PA6_SPI1_MISO = 5,
				PA6_TIM13_CH1 = 9,
				PA6_DCMI_PIXCLK = 13,
				PA6_LCD_G2 = 14,
				PA6_EVENTOUT = 15,

				PA7_TIM1_CH1N = 1,
				PA7_TIM3_CH2 = 2,
				PA7_TIM8_CH1N = 3,
				PA7_SPI1_MOSI = 5,
				PA7_TIM14_CH1 = 9,
				PA7_ETH_MII_RX_DV = 11,
				PA7_ETH_RMII_CRS_DV = 11,
				PA7_EVENTOUT = 15,

				PA8_MCO1 = 0,
				PA8_TIM1_CH1 = 1,
				PA8_I2C3_SCL = 4,
				PA8_USART1_CK = 7,
				PA8_OTG_FS_SOF = 10,
				PA8_LCD_R6 = 14,
				PA8_EVENTOUT = 15,

				PA9_TIM1_CH2 = 1,
				PA9_I2C3_SMBA = 4,
				PA9_SPI2_SCK = 5,
				PA9_I2S2_CK = 5,
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
				PA11_LCD_R4 = 14,
				PA11_EVENTOUT = 15,

				PA12_TIM1_ETR = 1,
				PA12_USART1_RTS = 7,
				PA12_CAN1_TX = 9,
				PA12_OTG_FS_DP = 10,
				PA12_LCD_R5 = 14,
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
				PA15_SPI1_NSS = 5,
				PA15_SPI3_NSS = 6,
				PA15_I2S3_WS = 6,
				PA15_EVENTOUT = 15,

				PB0_TIM1_CH2N = 1,
				PB0_TIM3_CH3 = 2,
				PB0_TIM8_CH2N = 3,
				PB0_LCD_R3 = 9,
				PB0_OTG_HS_ULPI_D1 = 10,
				PB0_ETH_MII_RXD2 = 11,
				PB0_EVENTOUT = 15,

				PB1_TIM1_CH3N = 1,
				PB1_TIM3_CH4 = 2,
				PB1_TIM8_CH3N = 3,
				PB1_LCD_R6 = 9,
				PB1_OTG_HS_ULPI_D2 = 10,
				PB1_ETH_MII_RXD3 = 11,
				PB1_EVENTOUT = 15,
				
				PB2_SAI1_SD_A = 6,
				PB2_SPI3_MOSI = 7,
				PB2_I2S3_SD = 7,
				PB2_QUADSPI_CLK = 9,
				PB2_EVENTOUT = 15,

				PB3_JTDO = 0,
				PB3_TRACESWO = 0,
				PB3_TIM2_CH2 = 1,
				PB3_SPI1_SCK = 5,
				PB3_SPI3_SCK = 6,
				PB3_I2S3_CK = 6,
				PB3_EVENTOUT = 15,

				PB4_NJTRST = 0,
				PB4_TIM3_CH1 = 2,
				PB4_SPI1_MISO = 5,
				PB4_SPI3_MISO = 6,
				PB4_SPI2_NSS = 7,
				PB4_I2S2_WS = 7,
				PB4_EVENTOUT = 15,

				PB5_TIM3_CH2 = 2,
				PB5_I2C1_SMBA = 4,
				PB5_SPI1_MOSI = 5,
				PB5_SPI3_MOSI = 6,
				PB5_I2S3_SD = 6,
				PB5_CAN2_RX = 9,
				PB5_OTG_HS_ULPI_D7 = 10,
				PB5_ETH_PPS_OUT = 11,
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
				PB7_FMC_NL = 12,
				PB7_DCMI_VSYNC = 13,
				PB7_EVENTOUT = 15,

				PB8_TIM4_CH3 = 2,
				PB8_TIM10_CH1 = 3,
				PB8_I2C1_SCL = 4,
				PB8_CAN1_RX = 9,
				PB8_ETH_MII_TXD3 = 11,
				PB8_SDIO_D4 = 12,
				PB8_DCMI_D6 = 13,
				PB8_LCD_B6 = 14,
				PB8_EVENTOUT = 15,

				PB9_TIM4_CH4 = 2,
				PB9_TIM11_CH1 = 3,
				PB9_I2C1_SDA = 4,
				PB9_SPI2_NSS = 5,
				PB9_I2S2_WS = 5,
				PB9_CAN1_TX = 9,
				PB9_SDIO_D5 = 12,
				PB9_DCMI_D7 = 13,
				PB9_LCD_B7 = 14,
				PB9_EVENTOUT = 15,

				PB10_TIM2_CH3 = 1,
				PB10_I2C2_SCL = 4,
				PB10_SPI2_SCK = 5,
				PB10_I2S2_CK = 5,
				PB10_USART3_TX = 7,
				PB10_OTG_HS_ULPI_D3 = 10,
				PB10_ETH_MII_RX_ER = 11,
				PB10_LCD_G4 = 14,
				PB10_EVENTOUT = 15,

				PB11_TIM2_CH4 = 1,
				PB11_I2C2_SDA = 4,
				PB11_USART3_RX = 7,
				PB11_OTG_HS_ULPI_D4 = 10,
				PB11_ETH_MII_TX_EN = 11,
				PB11_ETH_RMII_TX_EN = 11,
				PB11_LCD_G5 = 14,
				PB11_EVENTOUT = 15,

				PB12_TIM1_BKIN = 1,
				PB12_I2C2_SMBA = 4,
				PB12_SPI2_NSS = 5,
				PB12_I2S2_WS = 5,
				PB12_USART3_CK = 7,
				PB12_CAN2_RX = 9,
				PB12_OTG_HSULPI_D5 = 10,
				PB12_ETH_MII_TXD0 = 11,
				PB12_ETH_RMII_TXD0 = 11,
				PB12_OTG_HS_ID = 12,
				PB12_EVENTOUT = 15,

				PB13_TIM1_CH1N = 1,
				PB13_SPI2_SCK = 5,
				PB13_I2S2_CK = 5,
				PB13_USART3_CTS = 7,
				PB13_CAN2_TX = 9,
				PB13_OTG_HS_ULPI_D6 = 10,
				PB13_ETH_MII_TXD1 = 11,
				PB13_EVENTOUT = 15,

				PB14_TIM1_CH2N = 1,
				PB14_TIM8_CH2N = 3,
				PB14_SPI2_MISO = 5,
				PB14_I2S2_EXT_SD = 6,
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

				PC0_OTG_HS_ULPI_STP = 10,
				PC0_FMC_SDNWE = 12,
				PC0_EVENTOUT = 15,

				PC1_SPI2_MOSI = 5,
				PC1_I2S2_SD = 5,
				PC1_ETH_MDC = 11,
				PC1_EVENTOUT = 15,
	
				PC2_SPI2_MISO = 5,
				PC2_I2S2EXT_SD = 6,
				PC2_OTG_HS_ULPI_DIR = 10,
				PC2_ETH_MII_TXD2 = 11,
				PC2_FMC_SDNE0 = 12,
				PC2_EVENTOUT = 15,

				PC3_SPI2_MOSI = 5,
				PC3_I2S2_SD = 5,
				PC3_OTG_HS_ULPI_NXT = 10,
				PC3_ETH_MII_TX_CLK = 11,
				PC3_FMC_SDCKE0 = 12,
				PC3_EVENTOUT = 15,

				PC4_ETH_MII_RXD0 = 11,
				PC4_ETH_RMII_RXD0 = 11,
				PC4_EVENTOUT = 15,

				PC5_ETH_MII_RXD1 = 11,
				PC5_ETH_RMII_RXD1 = 11,
				PC5_EVENTOUT = 15,

				PC6_TIM3_CH1 = 2,
				PC6_TIM8_CH1 = 3,
				PC6_I2S2_MCK = 5,
				PC6_USART6_TX = 8,
				PC6_SDIO_D6 = 12,
				PC6_DCMI_D0 = 13,
				PC6_LCD_HSYNC = 14,
				PC6_EVENTOUT = 15,

				PC7_TIM3_CH2 = 2,
				PC7_TIM8_CH2 = 3,
				PC7_I2S3_MCK = 6,
				PC7_USART6_RX = 8,
				PC7_SDIO_D7 = 12,
				PC7_DCMI_D1 = 13,
				PC7_LCD_G6 = 14,
				PC7_EVENTOUT = 15,

				PC8_TIM3_CH3 = 2,
				PC8_TIM8_CH3 = 3,
				PC8_USART6_CK = 8,
				PC8_SDIO_D0 = 12,
				PC8_DCMI_D2 = 13,
				PC8_EVENTOUT = 15,

				PC9_MCO2 = 0,
				PC9_TIM3_CH4 = 2,
				PC9_TIM8_CH4 = 3,
				PC9_I2C3_SDA = 4,
				PC9_I2S_CKIN = 5,
				PC9_SDIO_D1 = 12,
				PC9_DCMI_D3 = 13,
				PC9_EVENTOUT = 15,

				PC10_SPI3_SCK = 6,
				PC10_I2S3_CK = 6,
				PC10_USART3_TX = 7,
				PC10_UART4_TX = 8,
				PC10_SDIO_D2 = 12,
				PC10_DCMI_D8 = 13,
				PC10_LCD_R2 = 14,
				PC10_EVENTOUT = 15,

				PC11_I2SEXT_SD = 5,
				PC11_SPI3_MISO = 6,
				PC11_USART3_RX = 7,
				PC11_UART4_RX = 8,
				PC11_SDIO_D3 = 12,
				PC11_DCMI_D4 = 13,
				PC11_EVENTOUT = 15,

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

				PD0_CAN1_RX = 9,
				PD0_FMC_D2 = 12,
				PD0_EVENTOUT = 15,

				PD1_CAN1_TX = 9,
				PD1_FMC_D3 = 12,
				PD1_EVENTOUT = 15,

				PD2_TIM3_ETR = 2,
				PD2_UART5_RX = 8,
				PD2_SDIO_CMD = 12,
				PD2_DCMI_D11 = 13,
				PD2_EVENTOUT = 15,

				PD3_SPI2_SCK = 5,
				PD3_I2S2_CK = 5,
				PD3_USART2_CTS = 7,
				PD3_FMC_CLK = 12,
				PD3_DCMI_D5 = 13,
				PD3_LCD_G7 = 14,
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
				PD6_LCD_B2 = 14,
				PD6_EVENTOUT = 15,

				PD7_USART2_CK = 7,
				PD7_FMC_NE1 = 12,
				PD7_FMC_NCE2 = 12,
				PD7_EVENTOUT = 15,

				PD8_USART3_TX = 7,
				PD8_FMC_D13 = 12,
				PD8_EVENTOUT = 15,

				PD9_USART3_RX = 7,
				PD9_FMC_D14 = 12,
				PD9_EVENTOUT = 15,

				PD10_USART3_CK = 7,
				PD10_FMC_D15 = 12,
				PD10_LCD_B3 = 14,
				PD10_EVENTOUT = 15,
				
				PD11_I2C4_SMBA = 4,
				PD11_USART3_CTS = 7,
				PD11_QUADSPI_BK1_IO0 = 9,
				PD11_SAI2_SD_A = 10,
				PD11_FMC_A16 = 12,
				PD11_FMC_CLE = 12,
				PD11_EVENTOUT = 15,

				PD12_TIM4_CH1 = 2,
				PD12_LPTIM1_IN1 = 3,
				PD12_I2C4_SCL = 4,
				PD12_USART3_RTS = 7,
				PD12_QUADSPI_BK1_IO1 = 9,
				PD12_SAI2_FS_A = 10,
				PD12_FMC_A17 = 12,
				PD12_EVENTOUT = 15,

				PD13_TIM4_CH2 = 2,
				PD13_LPTIM1_OUT = 3,
				PD13_I2C4_SDA = 4,
				PD13_QUADSPI_BK1_IO3 = 9,
				PD13_SAI2_SCK_A = 10,
				PD13_FMC_A18 = 12,
				PD13_EVENTOUT = 15,

				PD14_TIM4_CH3 = 2,
				PD14_FMC_D0 = 12,
				PD14_EVENTOUT = 15,

				PD15_TIM4_4 = 2,
				PD15_FMC_D1 = 12,
				PD15_EVENTOUT = 15,

				PE0_TIM4_ETR = 2,
				PE0_UART8_RX = 8,
				PE0_FMC_NBL0 = 12,
				PE0_DCMI_D2 = 13,
				PE0_EVENTOUT = 15,

				PE1_UART8_TX = 8,
				PE1_FMC_NBL1 = 12,
				PE1_DCMI_D3 = 13,
				PE1_EVENTOUT = 15,

				PE2_TRACECLK = 0,
				PE2_SPI4_SCK = 5,
				PE2_SAI1_MCLK_A = 6,
				PE2_QUADSPI_BK1_IO2 = 9,
				PE2_ETH_MII_TXD3 = 11,
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
				PE4_LCD_B0 = 14,
				PE4_EVENTOUT = 15,

				PE5_TRACED2 = 0,
				PE5_TIM9_CH1 = 3,
				PE5_SPI4_MISO = 5,
				PE5_SAI1_SCK_A = 6,
				PE5_FMC_A21 = 12,
				PE5_DCMI_D6 = 13,
				PE5_LCD_G0 = 14,
				PE5_EVENTOUT = 15,

				PE6_TRACED3 = 0,
				PE6_TIM9_CH2 = 3,
				PE6_SPI4_MOSI = 5,
				PE6_SAI1_SD_A = 6,
				PE6_FMC_A22 = 12,
				PE6_DCMI_D7 = 13,
				PE6_LCD_G1 = 14,
				PE6_EVENTOUT = 15,

				PE7_TIM1_ETR = 1,
				PE7_UART7_RX = 8,
				PE7_FMC_D4 = 12,
				PE7_EVENTOUT = 15,

				PE8_TIM1_CH1N = 1,
				PE8_UART7_TX = 8,
				PE8_FMC_D5 = 12,
				PE8_EVENTOUT = 15,

				PE9_TIM1_CH1 = 1,
				PE9_FMC_D6 = 12,
				PE9_EVENTOUT = 15,

				PE10_TIM1_CH2N = 1,
				PE10_FMC_D7 = 12,
				PE10_EVENTOUT = 15,

				PE11_TIM1_CH2 = 1,
				PE11_SPI4_NSS = 5,
				PE11_FMC_D8 = 12,
				PE11_LCD_G3 = 14,
				PE11_EVENTOUT = 15,

				PE12_TIM1_CH3N = 1,
				PE12_SPI4_SCK = 5,
				PE12_FMC_D9 = 12,
				PE12_LCD_B4 = 14,
				PE12_EVENTOUT = 15,

				PE13_TIM1_CH3 = 1,
				PE13_SPI4_MISO = 5,
				PE13_FMC_D10 = 12,
				PE13_LCD_DE = 14,
				PE13_EVENTOUT = 15,

				PE14_TIM1_CH4 = 1,
				PE14_SPI4_MOSI = 5,
				PE14_FMC_D11 = 12,
				PE14_LCD_CLK = 14,
				PE14_EVENTOUT = 15,

				PE15_TIM1_BKIN = 1,
				PE15_FMC_D12 = 12,
				PE15_LCD_R7 = 14,
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
				PF6_SPI5_NSS = 5,
				PF6_SAI1_SD_B = 6,
				PF6_UART7_RX = 8,
				PF6_FMC_NIORD = 12,
				PF6_EVENTOUT = 15,

				PF7_TIM11_CH1 = 3,
				PF7_SPI5_SCK = 5,
				PF7_SAI1_MCLK_B = 6,
				PF7_UART7_TX = 8,
				PF7_FMC_NREG = 12,
				PF7_EVENTOUT = 15,

				PF8_SPI5_MISO = 5,
				PF8_SAI1_SCK_B = 6,
				PF8_TIM13_CH1 = 9,
				PF8_FMC_NIOWR = 12,
				PF8_EVENTOUT = 15,

				PF9_SPI5_MOSI = 5,
				PF9_SAI1_FS_B = 6,
				PF9_TIM14_CH1 = 9,
				PF9_FMC_CD = 12,
				PF9_EVENTOUT = 15,

				PF10_FMC_INTR = 12,
				PF10_DCMI_D11 = 13,
				PF10_LCD_DE = 14,
				PF10_EVENTOUT = 15,

				PF11_SPI5_MOSI = 5,
				PF11_FMC_SDNRAS = 12,
				PF11_DCMI_D12 = 13,
				PF11_EVENTOUT = 15,

				PF12_FMC_A6 = 12,
				PF12_EVENTOUT = 15,

				PF13_FMC_A7 = 12,
				PF13_EVENTOUT = 15,

				PF14_FMC_A8 = 12,
				PF14_EVENTOUT = 15,

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
	
				PG6_FMC_INT2 = 12,
				PG6_DCMI_D12 = 13,
				PG6_LCD_R7 = 14,
				PG6_EVENTOUT = 15,

				PG7_USART6_CK = 8,
				PG7_FMC_INT3 = 12,
				PG7_DCMI_D13 = 13,
				PG7_LCD_CLK = 14,
				PG7_EVENTOUT = 15,

				PG8_SPI6_NSS = 5,
				PG8_USART6_RTS = 8,
				PG8_ETH_PPS_OUT = 11,
				PG8_FMC_SDCLK = 12,
				PG8_EVENTOUT = 15,

				PG9_USART6_RX = 8,
				PG9_FMC_NE2 = 12,
				PG9_FMC_NCE3 = 12,
				PG9_DCMI_VSYNC = 13,
				PG9_EVENTOUT = 15,

				PG10_LCD_G3 = 9,
				PG10_FMC_NCE4_1 = 12,
				PG10_FMC_NE3 = 12,
				PG10_DCMI_D2 = 13,
				PG10_LCD_B2 = 14,
				PG10_EVENTOUT = 15,

				PG11_ETH_MII_TX_EN = 11,
				PG11_ETH_RMII_TX_EN = 11,
				PG11_FMC_NCE4_2 = 12,
				PG11_DCMI_D3 = 13,
				PG11_LCD_B3 = 14,
				PG11_EVENTOUT = 15,

				PG12_SPI6_MISO = 5,
				PG12_USART6_RTS = 8,
				PG12_LCD_B4 = 9,
				PG12_FMC_NE4 = 12,
				PG12_LCD_B1 = 14,
				PG12_EVENTOUT = 15,

				PG13_SPI6_SCK = 5,
				PG13_USART6_CTS = 8,
				PG13_ETH_MII_TXD0 = 11,
				PG13_ETH_RMII_TXD0 = 11,
				PG13_FMC_A24 = 12,
				PG13_EVENTOUT = 15,

				PG14_SPI6_MOSI = 5,
				PG14_USART6_TX = 8,
				PG14_ETH_MII_TXD1 = 11,
				PG14_ETH_RMII_TXD1 = 11,
				PG14_FMC_A25 = 12,
				PG14_LCD_B0 = 14,
				PG14_EVENTOUT = 15,

				PG15_USART6_CTS = 8,
				PG15_FMC_SDNCAS = 12,
				PG15_DCMI_D13 = 13,
				PG15_EVENTOUT = 15,

				PH0_EVENTOUT = 15,

				PH1_EVENTOUT = 15,

				PH2_ETH_MII_CRS = 11,
				PH2_FMC_SDCKE0 = 12,
				PH2_LCD_R0 = 14,
				PH2_EVENTOUT = 15,

				PH3_ETH_MII_COL = 11,
				PH3_FMC_SDNE0 = 12,
				PH3_LCD_R1 = 14,
				PH3_EVENTOUT = 15,
	
				PH4_I2C2_SCL = 4,
				PH4_OTG_HS_ULPI_NXT = 10,
				PH4_EVENTOUT = 15,

				PH5_I2C2_SDA = 4,
				PH5_SPI5_NSS = 5,
				PH5_FMC_SDNWE = 12,
				PH5_EVENTOUT = 15,

				PH6_I2C2_SMBA = 4,
				PH6_SPI5_SCK = 5,
				PH6_TIM12_CH1 = 9,
				PH6_FMC_SDNE1 = 12,
				PH6_DCMI_D8 = 13,

				PH7_I2C3_SCL = 4,
				PH7_SPI5_MISO = 5,
				PH7_ETH_MII_RXD3 = 11,
				PH7_SDCKE1 = 12,
				PH7_DCMI_D9 = 13,

				PH8_I2C3_SDA = 4,
				PH8_FMC_D16 = 12,
				PH8_DCMI_HSYNC = 13,
				PH8_LCD_R2 = 14,
				PH8_EVENTOUT = 15,

				PH9_I2C3_SMBA = 4,
				PH9_TIM12_CH2 = 9,
				PH9_FMC_D17 = 12,
				PH9_DCMI_D0 = 13,
				PH9_LCD_R3 = 14,
				PH9_EVENTOUT = 15,

				PH10_TIM5_CH1 = 2,
				PH10_FMC_D18 = 12,
				PH10_DCMI_D1 = 13,
				PH10_LCD_R4 = 14,
				PH10_EVENTOUT = 15,

				PH11_TIM5_CH2 = 2,
				PH11_FMC_D19 = 12,
				PH11_DCMI_D2 = 13,
				PH11_LCD_R5 = 14,
				PH11_EVENTOUT = 15,

				PH12_TIM5_CH3 = 2,
				PH12_FMC_D20 = 12,
				PH12_DCMI_D3 = 13,
				PH12_LCD_R6 = 14,
				PH12_EVENTOUT = 15,

				PH13_TIM8_CH1N = 3,
				PH13_CAN1_TX = 9,
				PH13_FMC_D21 = 12,
				PH13_LCD_G2 = 14,
				PH13_EVENTOUT = 15,

				PH14_TIM8_CH2N = 3,
				PH14_FMC_D22 = 12,
				PH14_DCMI_D4 = 13,
				PH14_LCD_G3 = 14,
				PH14_EVENTOUT = 15,

				PH15_TIM8_CH3N = 3,
				PH15_FMC_D23 = 12,
				PH15_DCMI_D11 = 13,
				PH15_LCD_G4 = 14,
				PH15_EVENTOUT = 15,

				PI0_TIM5_CH4 = 2,
				PI0_SPI2_NSS = 5,
				PI0_I2S2_WS = 5,
				PI0_FMC_D24 = 12,
				PI0_DCMI_D13 = 13,
				PI0_LCD_G5 = 14,
				PI0_EVENTOUT = 15,

				PI1_SPI2_SCK = 5,
				PI1_I2S2_CK = 5,
				PI1_FMC_D25 = 12,
				PI1_DCMI_D8 = 13,
				PI1_LCD_G6 = 14,
				PI1_EVENTOUT = 15,

				PI2_TIM8_CH4 = 3,
				PI2_SPI2_MISO = 5,
				PI2_I2S2_EXT_SD = 6,
				PI2_FMC_D26 = 12,
				PI2_DCMI_D9 = 13,
				PI2_LCD_G7 = 14,
				PI2_EVENTOUT = 15,

				PI3_TIM8_ETR = 3,
				PI3_SPI2_MOSI = 5,
				PI3_I2S2_SD = 5,
				PI3_FCM_D27 = 12,
				PI3_DCMI_D10 = 13,
				PI3_EVENTOUT = 15,

				PI4_TIM8_BKIN = 3,
				PI4_FMC_NBL2 = 12,
				PI4_DCMI_D5 = 13,
				PI4_LCD_B4 = 14,
				PI4_EVENTOUT = 15,

				PI5_TIM8_CH1 = 3,
				PI5_FMC_NBL3 = 12,
				PI5_DCMI_VSYNC = 13,
				PI5_LCD_B5 = 14,
				PI5_EVENTOUT = 15,

				PI6_TIM8_CH2 = 3,
				PI6_FMC_D28 = 12,
				PI6_DCMI_D6 = 13,
				PI6_LCD_B6 = 14,
				PI6_EVENTOUT = 15,

				PI7_TIM8_CH3 = 3,
				PI7_FMC_D29 = 12,
				PI7_DCMI_D7 = 13,
				PI7_LCD_B7 = 14,
				PI7_EVENTOUT = 15,

				PI8_EVENTOUT = 15,

				PI9_CAN1_RX = 9,
				PI9_FMC_D30 = 12,
				PI9_LCD_VSYNC = 14,
				PI9_EVENTOUT = 15,


				PI10_ETH_MII_RX_ER = 11,
				PI10_FMC_D31 = 12,
				PI10_LCD_HSYNC = 14,
				PI10_EVENTOUT = 15,

				PI11_OTG_HS_ULPI_DIR = 10,
				PI11_EVENTOUT = 15,

				PI12_LCD_HSYNC = 14,
				PI12_EVENTOUT = 15,

				PI13_LCD_VSYNC = 14,
				PI13_EVENTOUT = 15,

				PI14_LCD_CLK = 14,
				PI14_EVENTOUT = 15,

				PI15_LCD_R0 = 14,
				PI15_EVENTOUT = 15,

				PJ0_LCD_R1 = 14,
				PJ0_EVENTOUT = 15,

				PJ1_LCD_R2 = 14,
				PJ1_EVENTOUT = 15,

				PJ2_LCD_R3 = 14,
				PJ2_EVENTOUT = 15,

				PJ3_LCD_R4 = 14,
				PJ3_EVENTOUT = 15,

				PJ4_LCD_R5 = 14,
				PJ4_EVENTOUT = 15,

				PJ5_LCD_R6 = 14,
				PJ5_EVENTOUT = 15,

				PJ6_LCD_R7 = 14,
				PJ6_EVENTOUT = 15,

				PJ7_LCD_G0 = 14,
				PJ7_EVENTOUT = 15,

				PJ8_LCD_G1 = 14,
				PJ8_EVENTOUT = 15,

				PJ9_LCD_G2 = 14,
				PJ9_EVENTOUT = 15,

				PJ10_LCD_G3 = 14,
				PJ10_EVENTOUT = 15,

				PJ11_LCD_G4 = 14,
				PJ11_EVENTOUT = 15,

				PJ12_LCD_B0 = 14,
				PJ12_EVENTOUT = 15,

				PJ13_LCD_B1 = 14,
				PJ13_EVENTOUT = 15,

				PJ14_LCD_B2 = 14,
				PJ14_EVENTOUT = 15,

				PJ15_LCD_B3 = 14,
				PJ15_EVENTOUT = 15,

				PK0_LCD_G5 = 14,
				PK0_EVENTOUT = 15,

				PK1_LCD_G6 = 14,
				PK1_EVENTOUT = 15,

				PK2_LCD_G7 = 14,
				PK2_EVENTOUT = 15,

				PK3_LCD_B4 = 14,
				PK3_EVENTOUT = 15,

				PK4_LCD_B5 = 14,
				PK4_EVENTOUT = 15,

				PK5_LCD_B6 = 14,
				PK5_EVENTOUT = 15,

				PK6_LCD_B7 = 14,
				PK6_EVENTOUT = 15,

				PK7_LCD_DE = 14,
				PK7_EVENTOUT = 15,
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

