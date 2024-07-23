/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DEFINE_STM32F103XX__H_
#define YSS_DEFINE_STM32F103XX__H_

namespace define
{
	namespace clock
	{
		namespace pll
		{
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