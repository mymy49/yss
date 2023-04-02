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

#ifndef YSS_DRV_DEFINE_EFM32PG22__H_
#define YSS_DRV_DEFINE_EFM32PG22__H_

namespace define
{
	namespace gpio
	{
		namespace otype
		{
			enum
			{
				PUSHPULL = 4,
				OPEN_DRAIN = 8,
				OPEN_DRAIN_WITH_PULLUP = 10,
			};
		}

		namespace alttype
		{
			enum
			{
				INPUT = 1,
				PUSHPULL = 5,
				OPEN_DRAIN = 12,
				OPEN_DRAIN_WITH_PULLUP = 14
			};
		}

		namespace altfunc
		{
			enum
			{
				UART0_RX = 0,
				UART0_TX,
				UART1_RX,
				UART1_TX,
				PDM_CLK,
				PDM_DAT0,
				PDM_DAT1,
				SPI0_SCK,
				SPI0_MISO,
				SPI0_MOSI,
				SPI1_SCK,
				SPI1_MISO,
				SPI1_MOSI,
			};
		}
	}

	namespace pdm
	{
		namespace chClkPol
		{
			enum
			{
				NORMAL = 0,
				INVERT
			};
		}

		namespace stereoMode
		{
			enum
			{
				DISABLE = 0,
				CH01ENABLE
			};
		}

		namespace fifoLevel
		{
			enum
			{
				ONE = 0,
				TWO,
				THREE,
				FOUR
			};
		}

		namespace dataFormat
		{
			enum
			{
				RIGHT16 = 0,
				DOUBLE16,
				RIGHT24,
				FULL32BIT,
				LEFT16,
				LEFT24,
				RAW32BIT
			};
		}

		namespace numOfCh
		{
			enum
			{
				ONE = 0,
				TWO
			};
		}

		namespace filterOrder
		{
			enum
			{
				SECOND = 0,
				THIRD,
				FOURTH,
				FIFTH
			};
		}

		namespace delayMuxSel
		{
			enum
			{
				ONE = 0,
				TWO,
				THREE,
				FOUR,
			};
		}

		namespace prescale
		{
			enum
			{
				Insert_number_between_0_to_1023 = 1023
			};
		}
	}

	namespace dma
	{
		namespace dstinc
		{
			enum
			{
				ONE = 0,
				TWO,
				FOUR,
				NONE
			};
		}

		namespace size
		{
			enum
			{
				BYTE = 0,
				HALFWORD,
				WORD
			};
		}

		namespace srcinc
		{
			enum
			{
				ONE = 0,
				TWO,
				FOUR,
				NONE
			};
		}

		namespace reqmode
		{
			enum
			{
				BLOCK = 0,
				ALL
			};
		}

		namespace blocksize
		{
			enum
			{
				UNIT1 = 0,
				UNIT2,
				UNIT3,
				UNIT4,
				UNIT6,
				UNIT16,
				UNIT32,
				UNIT64,
				UNIT128,
				UNIT256,
				UNIT512,
				UNIT1024,
				ALL
			};
		}

		namespace structtype
		{
			enum
			{
				TRANSFER = 0,
				SYNCHRONIZE,
				WRITE
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
				MODE2,
				MODE1,
				MODE3
			};
		}

		namespace bit
		{
			enum
			{
				BIT4 = 1,
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
}
#endif
