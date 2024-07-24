/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DEFINE_STM32F0__H_
#define YSS_DEFINE_STM32F0__H_

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

	namespace i2c
	{
		namespace speed
		{
			enum
			{
				STANDARD = 0,
				FAST,
				FAST_PLUS,
			};
		}
	}

	namespace adc
	{
		namespace sampleTime
		{
			enum
			{
				CYCLE_1_5 = 0,
				CYCLE_7_5,
				CYCLE_13_5,
				CYCLE_28_5,
				CYCLE_41_5,
				CYCLE_55_5,
				CYCLE_71_5,
				CYCLE_239_5,
			};
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
				BIT4 = 3,
				BIT5,
				BIT6,
				BIT7,
				BIT8,
				BIT9,
				BIT10,
				BIT11,
				BIT12,
				BIT13,
				BIT14,
				BIT15,
				BIT16,
			};
		}
	}

	namespace flash
	{
		namespace bank
		{
			enum
			{
				DUAL_BANK = 0,
				SINGLE_BANK,
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
				BIT_2,
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
}


// 사용 가능한 DMA 채널 정의
#define DMA_CH1			0
#define DMA_CH2			1
#define DMA_CH3			2
#define DMA_CH4			3
#define DMA_CH5			4

#endif


