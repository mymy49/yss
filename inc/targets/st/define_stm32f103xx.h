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

#ifndef YSS_DEFINE_STM32F103XX__H_
#define YSS_DEFINE_STM32F103XX__H_

namespace define
{
	namespace clock
	{
		namespace pll
		{
			namespace src
			{
				enum
				{
					HSI_DIV2 = 0,
					HSE = 1
				};
			}

			namespace xtpre
			{
				enum
				{
					NO_DIV = 0,
					DIV2 = 1
				};
			}
		}

		namespace usbclk
		{
			namespace src
			{
				enum
				{
					MAIN_PLL = 0,
					SAI_PLL = 1,
				};
			}
		}

		namespace sysclk
		{
			namespace src
			{
				enum
				{
					HSI = 0,
					HSE = 1,
					PLL = 2
				};
			}
		}

		namespace divFactor
		{
			namespace ahb
			{
				enum
				{
					NO_DIV = 0,
					DIV2 = 0x8,
					DIV4 = 0x9,
					DIV8 = 0xa,
					DIV16 = 0xb,
					DIV64 = 0xc,
					DIV128 = 0xd,
					DIV256 = 0xe,
					DIV512 = 0xf
				};
			}

			namespace apb
			{
				enum
				{
					NO_DIV = 0,
					DIV2 = 0x4,
					DIV4 = 0x5,
					DIV8 = 0x6,
					DIV16 = 0x7,
				};
			}
		}
	}

	namespace spi
	{
		namespace mode
		{
			enum
			{
				MODE0 = 0,
				MODE1,
				MODE2,
				MODE3
			};
		}

		namespace bit
		{
			enum
			{
				BIT8 = 0,
				BIT16,
			};
		}
	}

	namespace dma
	{
		namespace priorityLevel
		{
			enum
			{
				LOW = 0,
				MEDIUM = 1,
				HIGH = 2,
				VERY_HIGH = 3
			};
		}

		namespace dir
		{
			enum
			{
				PERI_TO_MEM = 0,
				MEM_TO_PERI = 1,
				MEM_TO_MEM = 2
			};
		}

		namespace addr
		{
			enum
			{
				FIXED = 0,
				ADDR_INC = 1
			};
		}

		namespace burst
		{
			enum
			{
				SINGLE = 0,
				INCR4 = 1,
				INCR8 = 2,
				INCR16 = 3
			};
		}

		namespace size
		{
			enum
			{
				BYTE = 0,
				HALF_WORD = 1,
				WORD = 2
			};
		}
	}

	namespace i2c
	{
		namespace speed
		{
			enum
			{
				STANDARD = 0,
				FAST = 1,
			};
		}
	}

	namespace gpio
	{
		namespace altfunc
		{
			enum
			{
				PA0_WKUP,
				PA0_USART2_CTS,
				PA0_TIM2_CH1_ETR,
				PA0_TIM5_CH1,
				PA0_TIM8_ETR,
				PA1_USART2_RTS,
				PA1_TIM5_CH2,
				PA1_TIM2_CH2,
				PA2_USART2_TX,
				PA2_TIM5_CH3,
				PA2_TIM9_CH1,
				PA2_TIM2_CH3,
				PA3_USART2_RX,
				PA3_TIM5_CH4,
				PA3_TIM2_CH4,
				PA3_TIM9_CH2,
				PA4_SPI1_NSS,
				PA4_USART2_CK,
				PA4_DAC_OUT1,
				PA5_SPI1_SCK,
				PA5_DAC_OUT2,
				PA6_SPI1_MISO,
				PA6_TIM8_BKIN,
				PA6_TIM3_CH1,
				PA6_TIM13_CH1,
				PA7_SPI1_MOSI,
				PA7_TIM8_CH1N,
				PA7_TIM3_CH2,
				PA7_TIM14_CH1,
				PA8_USART1_CK,
				PA8_TIM1_CH1,
				PA8_MCO,
				PA9_USART1_TX,
				PA9_TIM1_CH2,
				PA10_USART1_RX,
				PA10_TIM1_CH3,
				PA11_USART1_CTS,
				PA11_USB_DM,
				PA11_CAN_RX,
				PA11_TIM1_CH4,
				PA12_USART1_RTS,
				PA12_USB_DP,
				PA12_CAN_TX,
				PA12_TIM1_ETR,
				PA13,
				PA13_JTMS_SWDIO,
				PA14,
				PA14_JTCK_SWCLK,
				PA15,
				PA15_JTDI,
				PA15_SPI3_NSS,
				PA15_I2S3_WS,
				PA15_TIM2_CH1_ETR,
				PA15_SPI1_NSS,

				PB0_TIM3_CH3,
				PB0_TIM8_CH2N,
				PB0_TIM1_CH2N,
				PB1_TIM3_CH4,
				PB1_TIM8_CH3N,
				PB1_TIM1_CH3N,
				PB3,
				PB3_SPI3_SCK,
				PB3_I2S3_CK,
				PB3_TRACESWO,
				PB3_TIM2_CH2,
				PB3_SPI1_SCK,
				PB4,
				PB4_SPI3_MISO,
				PB4_TIM3_CH1,
				PB4_SPI1_MISO,
				PB5_I2C1_SMBA,
				PB5_SPI3_MOSI,
				PB5_I2S3_SD,
				PB5_TIM3_CH2,
				PB5_SPI1_MOSI,
				PB6_I2C1_SCL,
				PB6_TIM4_CH1,
				PB6_USART1_TX,
				PB7_I2C1_SDA,
				PB7_FSMC_NADV,
				PB7_TIM4_CH2,
				PB7_USART1_RX,
				PB8_TIM4_CH3,
				PB8_SDIO_D4,
				PB8_TIM10_CH1,
				PB8_I2C1_SCL,
				PB8_CAN_RX,
				PB9_TIM4_CH4,
				PB9_SDIO_D5,
				PB9_TIM11_CH1,
				PB9_I2C1_SDA,
				PB9_CAN_TX,
				PB10_I2C2_SCL,
				PB10_USART3_TX,
				PB10_TIM2_CH3,
				PB11_I2C2_SDA,
				PB11_USART3_RX,
				PB11_TIM2_CH4,
				PB12_SPI2_NSS,
				PB12_I2S2_WS,
				PB12_I2C2_SMBA,
				PB12_USART3_CK,
				PB12_TIM1_BKIN,
				PB13_SPI2_SCK,
				PB13_I2S2_CK,
				PB13_USART3_CTS,
				PB13_TIM1_CH1N,
				PB14_SPI2_MISO,
				PB14_TIM1_CH2N,
				PB14_USART3_RTS,
				PB14_TIM12_CH1,
				PB15_SPI2_MOSI,
				PB15_I2S2_SD,
				PB15_TIM1_CH3N,
				PB15_TIM12_CH2,

				PC6_I2S2_MCK,
				PC6_TIM8_CH1,
				PC6_SDIO_D6,
				PC6_TIM3_CH1,
				PC7_I2S3_MCK,
				PC7_TIM8_CH2,
				PC7_SDIO_D7,
				PC7_TIM3_CH2,
				PC8_TIM8_CH3,
				PC8_SDIO_D0,
				PC8_TIM3_CH3,
				PC9_TIM8_CH4,
				PC9_SDIO_D1,
				PC9_TIM3_CH4,
				PC10_UART4_TX,
				PC10_SDIO_D2,
				PC10_USART3_TX,
				PC11_UART4_RX,
				PC11_SDIO_D3,
				PC11_USART3_RX,
				PC12_UART5_TX,
				PC12_SDIO_CK,
				PC12_USART3_CK,
				PC13_TAMPER_RTC,
				PC14_OSC32_IN,
				PC15_OSC32_OUT,

				PD0,
				PD0_FSMC_D2,
				PD0_CAN_RX,
				PD0_OSC_IN,
				PD1,
				PD1_FSMC_D3,
				PD1_CAN_TX,
				PD1_OSC_OUT,
				PD2_TIM3_ETR,
				PD2_USART5_RX,
				PD2_SDIO_CMD,
				PD3_FSMC_CLK,
				PD3_USART2_CTS,
				PD4_FSMC_NOE,
				PD4_USART2_RTS,
				PD5_FSMC_NWE,
				PD5_USART2_TX,
				PD6_FSMC_NWAIT,
				PD6_USART2_RX,
				PD7_FSMC_NE1,
				PD7_FSMC_NCE2,
				PD7_USART2_CK,
				PD8_FSMC_D13,
				PD8_USART3_TX,
				PD9_FSMC_D14,
				PD9_USART3_RX,
				PD10_FSMC_D15,
				PD10_USART3_CK,
				PD11_FSMC_A16,
				PD11_USART3_CTS,
				PD12_FSMC_A17,
				PD12_TIM4_CH1,
				PD12_USART3_RTS,
				PD13_FSMC_A18,
				PD13_TIM4_CH2,
				PD14_FSMC_D0,
				PD14_TIM4_CH3,
				PD15_FSMC_D1,
				PD15_TIM4_CH4,

				PE0_TIM4_ETR,
				PE2_TRACECK,
				PE2_FSMC_A23,
				PE3_TRACED0,
				PE3_FSMC_A19,
				PE4_TRACED1,
				PE4_FSMC_A20,
				PE5_TRACED2,
				PE5_FSMC_A21,
				PE5_TIM9_CH1,
				PE6_TRACED3,
				PE6_FSMC_A22,
				PE6_TIM9_CH2,
				PE7_FSMC_D4,
				PE7_TIM1_ETR,
				PE8_FSMC_D5,
				PE8_TIM1_CH1N,
				PE9_FSMC_D6,
				PE9_TIM1_CH1,
				PE10_FSMC_D7,
				PE10_TIM1_CH2N,
				PE11_FSMC_D8,
				PE11_TIM1_CH2,
				PE12_FSMC_D9,
				PE12_TIM1_CH3N,
				PE13_FSMC_D10,
				PE13_TIM1_CH3,
				PE14_FSMC_D11,
				PE14_TIM1_CH4,
				PE15_FSMC_D12,
				PE15_TIM1_BKIN,

				PF0_FSMC_A0,
				PF1_FSMC_A1,
				PF2_FSMC_A2,
				PF3_FSMC_A3,
				PF4_FSMC_A4,
				PF5_FSMC_A5,
				PF6_FSMC_NIORD,
				PF6_TIM10_CH1,
				PF7_FSMC_NREG,
				PF7_TIM11_CH1,
				PF8_FSMC_NIOWR,
				PF8_TIM13_CH1,
				PF9_FSMC_CD,
				PF9_TIM14_CH1,
				PF10_FSMC_INTR,
				PF11_FSMC_NIOS16,
				PF12_FSMC_A6,
				PF13_FSMC_A7,
				PF14_FSMC_A8,
				PF15_FSMC_A9,

				PG0_FSMC_A10,
				PG1_FSMC_A11,
				PG2_FSMC_A12,
				PG3_FSMC_A13,
				PG4_FSMC_A14,
				PG5_FSMC_A15,
				PG6_FSMC_INT2,
				PG7_FSMC_INT3,
				PG9_FSMC_NE2,
				PG9_FSMC_NCE3,
				PG10_NCE4_1,
				PG10_NE3,
				PG11_NCE4_2,
				PG12_NE4,
				PG13_A24,
				PG14_A25,
			};
		}

		namespace ospeed
		{
			enum
			{
				LOW = 2,
				MID = 1,
				FAST = 3,
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
				PULL_UP,
				PULL_DOWN
			};
		}
	}

	namespace capture
	{
		namespace option
		{
			enum
			{
				RISING_EDGE = 0,
				FALLING_EDGE
			};
		}
	}

	namespace usart
	{
		namespace stopBit
		{
			enum
			{
				BIT_1 = 0,
				BIT_0_5,
				BIT_2,
				BIT_1_5,
			};
		}
	}

	namespace uart
	{
		namespace stopBit
		{
			enum
			{
				BIT_1 = 0,
				BIT_2,
			};
		}
	}
}

#define setGpioA(x)		GPIOA-ODR = x
#define setGpioA0()		GPIOA->BSRR = (1 << 0)
#define setGpioA1()		GPIOA->BSRR = (1 << 1)
#define setGpioA2()		GPIOA->BSRR = (1 << 2)
#define setGpioA3()		GPIOA->BSRR = (1 << 3)
#define setGpioA4()		GPIOA->BSRR = (1 << 4)
#define setGpioA5()		GPIOA->BSRR = (1 << 5)
#define setGpioA6()		GPIOA->BSRR = (1 << 6)
#define setGpioA7()		GPIOA->BSRR = (1 << 7)
#define setGpioA8()		GPIOA->BSRR = (1 << 8)
#define setGpioA9()		GPIOA->BSRR = (1 << 9)
#define setGpioA10()	GPIOA->BSRR = (1 << 10)
#define setGpioA11()	GPIOA->BSRR = (1 << 11)
#define setGpioA12()	GPIOA->BSRR = (1 << 12)
#define setGpioA13()	GPIOA->BSRR = (1 << 13)
#define setGpioA14()	GPIOA->BSRR = (1 << 14)
#define setGpioA15()	GPIOA->BSRR = (1 << 15)

#define resetGpioA0()	GPIOA->BRR = (1 << 0)
#define resetGpioA1()	GPIOA->BRR = (1 << 1)
#define resetGpioA2()	GPIOA->BRR = (1 << 2)
#define resetGpioA3()	GPIOA->BRR = (1 << 3)
#define resetGpioA4()	GPIOA->BRR = (1 << 4)
#define resetGpioA5()	GPIOA->BRR = (1 << 5)
#define resetGpioA6()	GPIOA->BRR = (1 << 6)
#define resetGpioA7()	GPIOA->BRR = (1 << 7)
#define resetGpioA8()	GPIOA->BRR = (1 << 8)
#define resetGpioA9()	GPIOA->BRR = (1 << 9)
#define resetGpioA10()	GPIOA->BRR = (1 << 10)
#define resetGpioA11()	GPIOA->BRR = (1 << 11)
#define resetGpioA12()	GPIOA->BRR = (1 << 12)
#define resetGpioA13()	GPIOA->BRR = (1 << 13)
#define resetGpioA14()	GPIOA->BRR = (1 << 14)
#define resetGpioA15()	GPIOA->BRR = (1 << 15)

#define setGpioB(x)		GPIOB-ODR = x
#define setGpioB0()		GPIOB->BSRR = (1 << 0)
#define setGpioB1()		GPIOB->BSRR = (1 << 1)
#define setGpioB2()		GPIOB->BSRR = (1 << 2)
#define setGpioB3()		GPIOB->BSRR = (1 << 3)
#define setGpioB4()		GPIOB->BSRR = (1 << 4)
#define setGpioB5()		GPIOB->BSRR = (1 << 5)
#define setGpioB6()		GPIOB->BSRR = (1 << 6)
#define setGpioB7()		GPIOB->BSRR = (1 << 7)
#define setGpioB8()		GPIOB->BSRR = (1 << 8)
#define setGpioB9()		GPIOB->BSRR = (1 << 9)
#define setGpioB10()	GPIOB->BSRR = (1 << 10)
#define setGpioB11()	GPIOB->BSRR = (1 << 11)
#define setGpioB12()	GPIOB->BSRR = (1 << 12)
#define setGpioB13()	GPIOB->BSRR = (1 << 13)
#define setGpioB14()	GPIOB->BSRR = (1 << 14)
#define setGpioB15()	GPIOB->BSRR = (1 << 15)

#define resetGpioB0()	GPIOB->BRR = (1 << 0)
#define resetGpioB1()	GPIOB->BRR = (1 << 1)
#define resetGpioB2()	GPIOB->BRR = (1 << 2)
#define resetGpioB3()	GPIOB->BRR = (1 << 3)
#define resetGpioB4()	GPIOB->BRR = (1 << 4)
#define resetGpioB5()	GPIOB->BRR = (1 << 5)
#define resetGpioB6()	GPIOB->BRR = (1 << 6)
#define resetGpioB7()	GPIOB->BRR = (1 << 7)
#define resetGpioB8()	GPIOB->BRR = (1 << 8)
#define resetGpioB9()	GPIOB->BRR = (1 << 9)
#define resetGpioB10()	GPIOB->BRR = (1 << 10)
#define resetGpioB11()	GPIOB->BRR = (1 << 11)
#define resetGpioB12()	GPIOB->BRR = (1 << 12)
#define resetGpioB13()	GPIOB->BRR = (1 << 13)
#define resetGpioB14()	GPIOB->BRR = (1 << 14)
#define resetGpioB15()	GPIOB->BRR = (1 << 15)

#define setGpioC(x)		GPIOC->ODR = x
#define setGpioC0()		GPIOC->BSRR = (1 << 0)
#define setGpioC1()		GPIOC->BSRR = (1 << 1)
#define setGpioC2()		GPIOC->BSRR = (1 << 2)
#define setGpioC3()		GPIOC->BSRR = (1 << 3)
#define setGpioC4()		GPIOC->BSRR = (1 << 4)
#define setGpioC5()		GPIOC->BSRR = (1 << 5)
#define setGpioC6()		GPIOC->BSRR = (1 << 6)
#define setGpioC7()		GPIOC->BSRR = (1 << 7)
#define setGpioC8()		GPIOC->BSRR = (1 << 8)
#define setGpioC9()		GPIOC->BSRR = (1 << 9)
#define setGpioC10()	GPIOC->BSRR = (1 << 10)
#define setGpioC11()	GPIOC->BSRR = (1 << 11)
#define setGpioC12()	GPIOC->BSRR = (1 << 12)
#define setGpioC13()	GPIOC->BSRR = (1 << 13)
#define setGpioC14()	GPIOC->BSRR = (1 << 14)
#define setGpioC15()	GPIOC->BSRR = (1 << 15)

#define resetGpioC0()	GPIOC->BRR = (1 << 0)
#define resetGpioC1()	GPIOC->BRR = (1 << 1)
#define resetGpioC2()	GPIOC->BRR = (1 << 2)
#define resetGpioC3()	GPIOC->BRR = (1 << 3)
#define resetGpioC4()	GPIOC->BRR = (1 << 4)
#define resetGpioC5()	GPIOC->BRR = (1 << 5)
#define resetGpioC6()	GPIOC->BRR = (1 << 6)
#define resetGpioC7()	GPIOC->BRR = (1 << 7)
#define resetGpioC8()	GPIOC->BRR = (1 << 8)
#define resetGpioC9()	GPIOC->BRR = (1 << 9)
#define resetGpioC10()	GPIOC->BRR = (1 << 10)
#define resetGpioC11()	GPIOC->BRR = (1 << 11)
#define resetGpioC12()	GPIOC->BRR = (1 << 12)
#define resetGpioC13()	GPIOC->BRR = (1 << 13)
#define resetGpioC14()	GPIOC->BRR = (1 << 14)
#define resetGpioC15()	GPIOC->BRR = (1 << 15)

#define setGpioD(x)		GPIOD-ODR = x
#define setGpioD0()		GPIOD->BSRR = (1 << 0)
#define setGpioD1()		GPIOD->BSRR = (1 << 1)
#define setGpioD2()		GPIOD->BSRR = (1 << 2)
#define setGpioD3()		GPIOD->BSRR = (1 << 3)
#define setGpioD4()		GPIOD->BSRR = (1 << 4)
#define setGpioD5()		GPIOD->BSRR = (1 << 5)
#define setGpioD6()		GPIOD->BSRR = (1 << 6)
#define setGpioD7()		GPIOD->BSRR = (1 << 7)
#define setGpioD8()		GPIOD->BSRR = (1 << 8)
#define setGpioD9()		GPIOD->BSRR = (1 << 9)
#define setGpioD10()	GPIOD->BSRR = (1 << 10)
#define setGpioD11()	GPIOD->BSRR = (1 << 11)
#define setGpioD12()	GPIOD->BSRR = (1 << 12)
#define setGpioD13()	GPIOD->BSRR = (1 << 13)
#define setGpioD14()	GPIOD->BSRR = (1 << 14)
#define setGpioD15()	GPIOD->BSRR = (1 << 15)

#define resetGpioD0()	GPIOD->BRR = (1 << 0)
#define resetGpioD1()	GPIOD->BRR = (1 << 1)
#define resetGpioD2()	GPIOD->BRR = (1 << 2)
#define resetGpioD3()	GPIOD->BRR = (1 << 3)
#define resetGpioD4()	GPIOD->BRR = (1 << 4)
#define resetGpioD5()	GPIOD->BRR = (1 << 5)
#define resetGpioD6()	GPIOD->BRR = (1 << 6)
#define resetGpioD7()	GPIOD->BRR = (1 << 7)
#define resetGpioD8()	GPIOD->BRR = (1 << 8)
#define resetGpioD9()	GPIOD->BRR = (1 << 9)
#define resetGpioD10()	GPIOD->BRR = (1 << 10)
#define resetGpioD11()	GPIOD->BRR = (1 << 11)
#define resetGpioD12()	GPIOD->BRR = (1 << 12)
#define resetGpioD13()	GPIOD->BRR = (1 << 13)
#define resetGpioD14()	GPIOD->BRR = (1 << 14)
#define resetGpioD15()	GPIOD->BRR = (1 << 15)

#define setGpioE(x)		GPIOE-ODR = x
#define setGpioE0()		GPIOE->BSRR = (1 << 0)
#define setGpioE1()		GPIOE->BSRR = (1 << 1)
#define setGpioE2()		GPIOE->BSRR = (1 << 2)
#define setGpioE3()		GPIOE->BSRR = (1 << 3)
#define setGpioE4()		GPIOE->BSRR = (1 << 4)
#define setGpioE5()		GPIOE->BSRR = (1 << 5)
#define setGpioE6()		GPIOE->BSRR = (1 << 6)
#define setGpioE7()		GPIOE->BSRR = (1 << 7)
#define setGpioE8()		GPIOE->BSRR = (1 << 8)
#define setGpioE9()		GPIOE->BSRR = (1 << 9)
#define setGpioE10()	GPIOE->BSRR = (1 << 10)
#define setGpioE11()	GPIOE->BSRR = (1 << 11)
#define setGpioE12()	GPIOE->BSRR = (1 << 12)
#define setGpioE13()	GPIOE->BSRR = (1 << 13)
#define setGpioE14()	GPIOE->BSRR = (1 << 14)
#define setGpioE15()	GPIOE->BSRR = (1 << 15)

#define resetGpioE0()	GPIOE->BRR = (1 << 0)
#define resetGpioE1()	GPIOE->BRR = (1 << 1)
#define resetGpioE2()	GPIOE->BRR = (1 << 2)
#define resetGpioE3()	GPIOE->BRR = (1 << 3)
#define resetGpioE4()	GPIOE->BRR = (1 << 4)
#define resetGpioE5()	GPIOE->BRR = (1 << 5)
#define resetGpioE6()	GPIOE->BRR = (1 << 6)
#define resetGpioE7()	GPIOE->BRR = (1 << 7)
#define resetGpioE8()	GPIOE->BRR = (1 << 8)
#define resetGpioE9()	GPIOE->BRR = (1 << 9)
#define resetGpioE10()	GPIOE->BRR = (1 << 10)
#define resetGpioE11()	GPIOE->BRR = (1 << 11)
#define resetGpioE12()	GPIOE->BRR = (1 << 12)
#define resetGpioE13()	GPIOE->BRR = (1 << 13)
#define resetGpioE14()	GPIOE->BRR = (1 << 14)
#define resetGpioE15()	GPIOE->BRR = (1 << 15)

#define setGpioF(x)		GPIOF-ODR = x
#define setGpioF0()		GPIOF->BSRR = (1 << 0)
#define setGpioF1()		GPIOF->BSRR = (1 << 1)
#define setGpioF2()		GPIOF->BSRR = (1 << 2)
#define setGpioF3()		GPIOF->BSRR = (1 << 3)
#define setGpioF4()		GPIOF->BSRR = (1 << 4)
#define setGpioF5()		GPIOF->BSRR = (1 << 5)
#define setGpioF6()		GPIOF->BSRR = (1 << 6)
#define setGpioF7()		GPIOF->BSRR = (1 << 7)
#define setGpioF8()		GPIOF->BSRR = (1 << 8)
#define setGpioF9()		GPIOF->BSRR = (1 << 9)
#define setGpioF10()	GPIOF->BSRR = (1 << 10)
#define setGpioF11()	GPIOF->BSRR = (1 << 11)
#define setGpioF12()	GPIOF->BSRR = (1 << 12)
#define setGpioF13()	GPIOF->BSRR = (1 << 13)
#define setGpioF14()	GPIOF->BSRR = (1 << 14)
#define setGpioF15()	GPIOF->BSRR = (1 << 15)

#define resetGpioF0()	GPIOF->BRR = (1 << 0)
#define resetGpioF1()	GPIOF->BRR = (1 << 1)
#define resetGpioF2()	GPIOF->BRR = (1 << 2)
#define resetGpioF3()	GPIOF->BRR = (1 << 3)
#define resetGpioF4()	GPIOF->BRR = (1 << 4)
#define resetGpioF5()	GPIOF->BRR = (1 << 5)
#define resetGpioF6()	GPIOF->BRR = (1 << 6)
#define resetGpioF7()	GPIOF->BRR = (1 << 7)
#define resetGpioF8()	GPIOF->BRR = (1 << 8)
#define resetGpioF9()	GPIOF->BRR = (1 << 9)
#define resetGpioF10()	GPIOF->BRR = (1 << 10)
#define resetGpioF11()	GPIOF->BRR = (1 << 11)
#define resetGpioF12()	GPIOF->BRR = (1 << 12)
#define resetGpioF13()	GPIOF->BRR = (1 << 13)
#define resetGpioF14()	GPIOF->BRR = (1 << 14)
#define resetGpioF15()	GPIOF->BRR = (1 << 15)

#define setGpioG(x)		GPIOG-ODR = x
#define setGpioG0()		GPIOG->BSRR = (1 << 0)
#define setGpioG1()		GPIOG->BSRR = (1 << 1)
#define setGpioG2()		GPIOG->BSRR = (1 << 2)
#define setGpioG3()		GPIOG->BSRR = (1 << 3)
#define setGpioG4()		GPIOG->BSRR = (1 << 4)
#define setGpioG5()		GPIOG->BSRR = (1 << 5)
#define setGpioG6()		GPIOG->BSRR = (1 << 6)
#define setGpioG7()		GPIOG->BSRR = (1 << 7)
#define setGpioG8()		GPIOG->BSRR = (1 << 8)
#define setGpioG9()		GPIOG->BSRR = (1 << 9)
#define setGpioG10()	GPIOG->BSRR = (1 << 10)
#define setGpioG11()	GPIOG->BSRR = (1 << 11)
#define setGpioG12()	GPIOG->BSRR = (1 << 12)
#define setGpioG13()	GPIOG->BSRR = (1 << 13)
#define setGpioG14()	GPIOG->BSRR = (1 << 14)
#define setGpioG15()	GPIOG->BSRR = (1 << 15)

#define resetGpioG0()	GPIOG->BRR = (1 << 0)
#define resetGpioG1()	GPIOG->BRR = (1 << 1)
#define resetGpioG2()	GPIOG->BRR = (1 << 2)
#define resetGpioG3()	GPIOG->BRR = (1 << 3)
#define resetGpioG4()	GPIOG->BRR = (1 << 4)
#define resetGpioG5()	GPIOG->BRR = (1 << 5)
#define resetGpioG6()	GPIOG->BRR = (1 << 6)
#define resetGpioG7()	GPIOG->BRR = (1 << 7)
#define resetGpioG8()	GPIOG->BRR = (1 << 8)
#define resetGpioG9()	GPIOG->BRR = (1 << 9)
#define resetGpioG10()	GPIOG->BRR = (1 << 10)
#define resetGpioG11()	GPIOG->BRR = (1 << 11)
#define resetGpioG12()	GPIOG->BRR = (1 << 12)
#define resetGpioG13()	GPIOG->BRR = (1 << 13)
#define resetGpioG14()	GPIOG->BRR = (1 << 14)
#define resetGpioG15()	GPIOG->BRR = (1 << 15)

#endif