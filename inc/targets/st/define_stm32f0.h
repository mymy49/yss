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
}


// 사용 가능한 DMA 채널 정의
#define DMA_CH1			0
#define DMA_CH2			1
#define DMA_CH3			2
#define DMA_CH4			3
#define DMA_CH5			4

#endif


