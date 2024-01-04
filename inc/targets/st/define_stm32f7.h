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

#ifndef YSS_DEFINE_STM32F7__H_
#define YSS_DEFINE_STM32F7__H_

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

		namespace saipll
		{
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

		namespace i2spll
		{
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
				SCALE3_MODE = 1,
				SCALE2_MODE,
				SCALE1_MODE,
			};
		}

		namespace  sdmmc
		{
			namespace src
			{
				enum
				{
					USB_CLK = 0,
					SYSCLK
				};
			}
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
	
	// DMA2D
	namespace dma2d
	{
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

		namespace mode
		{
			enum
			{
				MEM_TO_MEM = 0,
				MEM_TO_MEM_PFC = 1,
				MEM_TO_MEM_BLENDING = 2,
				REG_TO_MEM = 3,
			};
		}
	}
	
	// FLASH
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

	// QUADSPI
	namespace quadspi
	{
		namespace bank
		{
			enum
			{
				BANK1 = 0,
				BANK2
			};
		}

		namespace clockMode
		{
			enum
			{
				MODE0 = 0,
				MODE3,
			};
		}

		namespace mode
		{
			enum
			{
				NO = 0,
				SINGLE = 1,
				DOUBLE = 2,
				QUAD = 3,
			};
		}

		namespace size
		{
			enum
			{
				BIT8 = 0,
				BIT16 = 1,
				BIT24 = 2,
				BIT32 = 3,
			};
		}

		namespace flashSize
		{
			enum
			{
				B2 = 0,
				B4 = 1,
				B8 = 2,
				B16 = 3,
				B32 = 4,
				B64 = 5,
				B128 = 6,
				B256 = 7,
				B512 = 8,
				KB1 = 9,
				KB2 = 10,
				KB4 = 11,
				KB8 = 12,
				KB16 = 13,
				KB32 = 14,
				KB64 = 15,
				KB128 = 16,
				KB256 = 17,
				KB512 = 18,
				MB1 = 19,
				MB2 = 20,
				MB4 = 21,
				MB8 = 22,
				MB16 = 23,
				MB32 = 24,
				MB64 = 25,
				MB128 = 26,
				MB256 = 27,
				MB512 = 28,
				GB1 = 29,
				GB2 = 30,
				GB4 = 31
			};
		}

		namespace pmm
		{
			enum
			{
				AND = 0,
				OR
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

