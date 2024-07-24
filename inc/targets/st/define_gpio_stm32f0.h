/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GPIO_ALTFUNC_STM32F1__H_
#define YSS_GPIO_ALTFUNC_STM32F1__H_

#if defined(STM32F030xC)
typedef enum
{
	PA0_USART1_CTS = 1,
	PA0_USART2_CTS = 1,
	PA0_USART4_TX = 4,

	PA1_EVENTOUT = 0,
	PA1_USART1_RTS = 1,
	PA1_USART2_RTS = 1,
	PA1_USART4_RX = 4,
	PA1_TIM15_CH1N = 5,

	PA2_TIM15_CH1 = 0,
	PA2_USART1_TX = 1,
	PA2_USART2_TX = 1,

	PA3_TIM15_CH2 = 0,
	PA3_USART1_RX = 1,
	PA3_USART2_RX = 1,

	PB6_USART1_TX = 0,
	PB6_I2C1_SCL = 1,
	PB6_TIM16_CH1N = 2,

	PB7_USART1_RX = 0,
	PB7_I2C1_SDA = 1,
	PB7_TIM17_CH1N = 2,
	PB7_USART4_CTS = 4,

	PB8_I2C1_SCL = 1,
	PB8_TIM16_CH1 = 2,

	PB9_IR_OUT = 0,
	PB9_I2C1_SDA = 1,
	PB9_TIM17_CH1 = 2,
	PB9_EVENTOUT = 3,
	PB9_SPI2_NSS = 5,

	PB10_I2C1_SCL = 1,
	PB10_I2C2_SCL = 1,
	PB10_USART3_TX = 4,
	PB10_SPI2_SCK = 5,

	PB11_EVENTOUT = 0,
	PB11_I2C1_SDA = 1,
	PB11_I2C2_SDA = 1,
	PB11_USART3_RX = 4,

	PB12_SPI1_NSS = 0,
	PB12_SPI2_NSS = 0,
	PB12_EVENTOUT = 1,
	PB12_TIM1_BKIN = 2,
	PB12_USART3_RTS = 4,
	PB12_TIM15 = 5,

	PB13_SPI1_SCK = 0,
	PB13_SPI2_SCK = 0,
	PB13_TIM1_CH1N = 2,
	PB13_USART3_CTS = 4,
	PB13_I2C2_SCL = 5,

	PB14_SPI1_MISO = 0,
	PB14_SPI2_MISO = 0,
	PB14_TIM15_CH1 = 1,
	PB14_TIM1_CH2N = 2,
	PB14_USART3_RTS = 4,
	PB14_I2C2_SDA = 5,

	PB15_SPI1_MOSI = 0,
	PB15_SPI2_MOSI = 0,
	PB15_TIM15_CH2 = 1,
	PB15_TIM1_CH3N = 2,
	PB15_TIM15_CH1N = 3,
}altFunc_t;
#endif

typedef enum
{
	OSPEED_LOW = 0,
	OSPEED_MID,
	OSPEED_FAST,
	OSPEED_HIGH,
}ospeed_t;

typedef enum
{
	OTYPE_PUSH_PULL = 0,
	OTYPE_OPEN_DRAINS,
}otype_t;

typedef struct
{
	YSS_GPIO_Peri *port;
	uint8_t pin;
	altFunc_t func;
}altFuncPort_t;

typedef enum
{
	PUPD_NONE = 0,
	PUPD_PULL_UP,
	PUPD_PULL_DOWN
}pupd_t;

typedef enum
{
	MODE_INPUT = 0,
	MODE_OUTPUT,
	MODE_ALT_FUNC,
	MODE_ANALOG
}mode_t;

#endif

