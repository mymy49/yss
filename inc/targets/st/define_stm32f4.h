/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DEFINE_STM32F4__H_
#define YSS_DEFINE_STM32F4__H_

namespace define
{
	// Capture
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

	// Clock
	namespace clock
	{
		namespace pll
		{
			namespace src
			{
				enum
				{
					HSI = 0,
					HSE = 1
				};
			}

			namespace pdiv
			{
				enum
				{
					DIV2 = 0,
					DIV4 = 1,
					DIV6 = 2,
					DIV8 = 3
				};
			}

			namespace qdiv
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
					DIV15 = 15
				};
			}

			namespace rdiv
			{
				enum
				{
					DIV2 = 2,
					DIV3 = 3,
					DIV4 = 4,
					DIV5 = 5,
					DIV6 = 6,
					DIV7 = 7
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
					PLL = 2,
#if defined(STM32F446xx)
					PLL_R = 3,
#endif
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
#if defined(STM32F407xx)
		namespace  powerScale
		{
			enum
			{
				SCALE2_MODE = 0,
				SCALE1_MODE,
			};
		}
#else
		namespace  powerScale
		{
			enum
			{
				SCALE3_MODE = 1,
				SCALE2_MODE,
				SCALE1_MODE,
			};
		}
#endif
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

// 사용 가능한 DMA 채널 정의

#define DMA1_CH0		0
#define DMA1_CH1		1
#define DMA1_CH2		2
#define DMA1_CH3		3
#define DMA1_CH4		4
#define DMA1_CH5		5
#define DMA1_CH6		6
#define DMA1_CH7		7

#define DMA2_CH0		8
#define DMA2_CH1		9
#define DMA2_CH2		10
#define DMA2_CH3		11
#define DMA2_CH4		12
#define DMA2_CH5		13
#define DMA2_CH6		14
#define DMA2_CH7		15

//enum
//{
//	DMA1_CH0,
//	DMA1_CH1,
//	DMA1_CH2,
//	DMA1_CH3,
//	DMA1_CH4,
//	DMA1_CH5,
//	DMA1_CH6,
//	DMA1_CH7,

//	DMA2_CH0,
//	DMA2_CH1,
//	DMA2_CH2,
//	DMA2_CH3,
//	DMA2_CH4,
//	DMA2_CH5,
//	DMA2_CH6,
//	DMA2_CH7,
//};

#endif

