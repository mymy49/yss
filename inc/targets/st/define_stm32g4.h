/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DEFINE_STM32G4__H_
#define YSS_DEFINE_STM32G4__H_

namespace define
{
	// Clock
	namespace clock
	{
		namespace pll
		{
			namespace src
			{
				enum
				{
					HSI16 = 2,
					HSE = 3
				};
			}

			namespace pdiv
			{
				enum
				{
					DIV2 = 2,
					DIV3 = 3,
					DIV4 = 4,
					DIV5 = 5,
					DIV6 = 6,
					DIV7 = 7,
					DIV8 = 8,
					DIV9 = 9,
					DIV10 = 10,
					DIV11 = 11,
					DIV12 = 12,
					DIV13 = 13,
					DIV14 = 14,
					DIV15 = 15,
					DIV16 = 16,
					DIV17 = 17,
					DIV18 = 18,
					DIV19 = 19,
					DIV20 = 20,
					DIV21 = 21,
					DIV22 = 22,
					DIV23 = 23,
					DIV24 = 24,
					DIV25 = 25,
					DIV26 = 26,
					DIV27 = 27,
					DIV28 = 28,
					DIV29 = 29,
					DIV30 = 30,
					DIV31 = 31,
				};
			}

			namespace qdiv
			{
				enum
				{
					DIV2 = 0,
					DIV4,
					DIV6,
					DIV8,
				};
			}

			namespace rdiv
			{
				enum
				{
					DIV2 = 0,
					DIV4,
					DIV6,
					DIV8,
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
					HSI16 = 1,
					HSE = 2,
					PLL = 3,
				};
			}

			namespace ahbDiv
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

			namespace apbDiv
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

		namespace divisionFactor
		{
			namespace ltdc
			{
				enum
				{
					DIV2 = 0,
					DIV4 = 1,
					DIV8 = 2,
					DIV16 = 3,
				};
			}
		}

		namespace i2s
		{
			namespace src
			{
				enum
				{
					PLLI2S_R = 0,
					I2S_CKIN,
					PLL_R,
					PLLSRC
				};
			}
		}

		namespace sai
		{
			namespace src
			{
				enum
				{
					PLLI2S_R = 0,
					I2S_CKIN,
					PLL_R,
					PLLSRC
				};
			}
		}

		namespace  powerScale
		{
			enum
			{
				SCALE1_MODE = 1,
				SCALE2_MODE,
			};
		}
	}
	
	// DMA
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

	// DMAMUX
	namespace dmamux
	{
		namespace input
		{
			enum
			{
				Req_G0_DMAMUX = 1,		// 1
				Req_G1_DMAMUX,
				Req_G2_DMAMUX,
				Req_G3_DMAMUX,
				ADC1_DMAMUX,
				DAC1_CH1,
				DAC1_CH2,
				TIM6_UP,
				TIM7_UP,
				SPI1_RX,
				SPI1_TX,				// 11
				SPI2_RX,
				SPI2_TX,
				SPI3_RX,
				SPI3_TX,
				I2C1_RX,
				I2C1_TX,
				I2C2_RX,
				I2C2_TX,
				I2C3_RX,
				I2C3_TX,				// 21
				I2C4_RX,
				I2C4_TX,
				USART1_RX,
				USART1_TX,
				USART2_RX,
				USART2_TX,
				USART3_RX,
				USART3_TX,
				UART4_RX,
				UART4_TX,				// 31
				UART5_RX,
				UART5_TX,
				LPUART1_RX,
				LPUART1_TX,
				ADC2_DMAMUX,
				ADC3_DMAMUX,
				ADC4_DMAMUX,
				ADC5_DMAMUX,
				QUADSPI_DMAMUX,
				DAC2_CH1,				// 41
				TIM1_CH1,
				TIM1_CH2,
				TIM1_CH3,
				TIM1_CH4,
				TIM1_UP,
				TIM1_TRIG,
				TIM1_COM,
				TIM8_CH1,
				TIM8_CH2,
				TIM8_CH3,				// 51
				TIM8_CH4,
				TIM8_UP,
				TIM8_TRIG,
				TIM8_COM,
				TIM2_CH1,
				TIM2_CH2,
				TIM2_CH3,
				TIM2_CH4,
				TIM2_UP,
				TIM3_CH1,				// 61
				TIM3_CH2,
				TIM3_CH3,
				TIM3_CH4,
				TIM3_UP,
				TIM3_TRIG,
				TIM4_CH1,
				TIM4_CH2,
				TIM4_CH3,
				TIM4_CH4,
				TIM4_UP,				// 71
				TIM5_CH1,
				TIM5_CH2,
				TIM5_CH3,
				TIM5_CH4,
				TIM5_UP,
				TIM5_TRIG,
				TIM15_CH1,
				TIM15_UP,
				TIM15_TRIG,
				TIM15_COM,				// 81
				TIM16_CH1,
				TIM16_UP,
				TIM17_CH1,
				TIM17_UP,
				TIM20_CH1,
				TIM20_CH2,
				TIM20_CH3,
				TIM20_CH4,
				TIM20_UP,
				AES_IN,					// 91
				AES_OUT,
				TIM20_TRIG,
				TIM20_COM,
				HRTIM_MASTER,
				HRTIM_TIMA,
				HRTIM_TIMB,
				HRTIM_TIMC,
				HRTIM_TIMD,
				HRTIM_TIME,
				HRTIM_TIMF,				// 101
				DAC3_CH1,
				DAC3_CH2,
				DAC4_CH1,
				DAC4_CH2,
				SPI4_RX,
				SPI4_TX,
				SAI1_A,
				SAI1_B,
				FMAC_Read,
				FMAC_Write,				// 111
				Cordic_Read,
				Cordic_Write,
				UCPD1_RX,
				UCPD1_TX
			};
		}
	}

	// LTDC
	namespace ltdc
	{
		namespace format
		{
			enum
			{
				ARGB8888 = 0,
				RGB888 = 1,
				RGB565 = 2,
				ARGB1555 = 3,
				ARGB4444 = 4,
				L8 = 5,
				AL44 = 6,
				AL88 = 7
			};
		}

		namespace colorMode
		{
			enum
			{
				ARGB8888 = 0,
				RGB888 = 1,
				RGB565 = 2,
				ARGB1555 = 3,
				ARGB4444 = 4,
				MODE_L8 = 5,
				AL44 = 6,
				AL88 = 7,
				L4 = 8,
				A8 = 9,
				A4 = 10
			};
		}
	}

	// I2C
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

	// SDRAM
	namespace sdram
	{
		namespace sdclk
		{
			enum
			{
				HCLKx2 = 2,
				HCLKx3 = 3,
			};
		}

		namespace bank
		{
			enum
			{
				BANK1 = 0,
				BANK2 = 1
			};
		}

		namespace columnAddress
		{
			enum
			{
				BIT8 = 0,
				BIT9 = 1,
				BIT10 = 2,
				BIT11 = 3
			};
		}

		namespace rowAddress
		{
			enum
			{
				BIT11 = 0,
				BIT12 = 1,
				BIT13 = 2
			};
		}

		namespace dbusWidth
		{
			enum
			{
				BIT8 = 0,
				BIT16 = 1,
				BIT32 = 2
			};
		}

		namespace internalBank
		{
			enum
			{
				TWO = 0,
				FOUR = 1
			};
		}

		namespace casLatency
		{
			enum
			{
				ONE = 1,
				TWO = 2,
				THREE = 3
			};
		}

		namespace rpipe
		{
			enum
			{
				NO_DELAY = 0,
				ONE_DELAY = 1,
				TWO_DELAY = 2
			};
		}

		namespace apbDivisionFactor
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
	
	// SPI
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
	
	// UART
	namespace uart
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

	// USART
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
}

#endif

