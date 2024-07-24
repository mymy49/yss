/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_GPIO_WIZNET_W7500X__H_
#define YSS_CLASS_GPIO_WIZNET_W7500X__H_

#include <yss/error.h>
#include <drv/peripheral.h>

class Gpio : public GpioBase
{
public:
	typedef enum 
	{
		PUSH_PULL = 0,
		OPEN_DRAIN
	}otype_t;

	typedef enum
	{
		HIGH = 0,
		LOW
	}strength_t;

	typedef enum
	{
		PA0_PWM6 = 2,
		PA0_CAP6 = 2,

		PA1_PWM7 = 2,
		PA1_CAP7 = 2,

		PA2_CLKOUT = 2,

		PA3_SWD_SWCLK = 0,
		PA3_PWM0 = 3,
		PA3_CAP0 = 3,

		PA4_SWD_SWDIO = 0,
		PA4_PWM1 = 3,
		PA4_CAP1 = 3,

		PA5_SPI0_SSEL = 0,
		PA5_I2C1_SCL = 2,
		PA5_PWM2 = 3,
		PA5_CAP2 = 3,

		PA6_SPI0_SCLK = 0,
		PA6_I2C1_SDA = 2,
		PA6_PWM3 = 3,
		PA6_CAP3 = 3,

		PA7_SPI0_MISO = 0,
		PA7_UART1_CTS = 2,
		PA7_PWM4 = 3,
		PA7_CAP4 = 3,

		PA8_SPI0_MOSI = 0,
		PA8_UART1_RTS = 2,
		PA8_PWM5 = 3,
		PA8_CAP5 = 3,

		PA9_I2C0_SCL = 0,
		PA9_UART1_TXD = 2,
		PA9_PWM6 = 3,
		PA9_CAP6 = 3,

		PA10_I2C0_SDA = 0,
		PA10_UART1_RXD = 2,
		PA10_PWM7 = 3,
		PA10_CAP7 = 3,

		PA11_UART0_CTS = 0,
		PA11_SPI1_SSEL = 2,

		PA12_UART0_RTS = 0,
		PA12_SPI1_SCLK = 1,

		PA13_UART0_TXD = 0,
		PA13_SPI1_MISO = 2,

		PA14_UART0_RXD = 0,
		PA14_SPI1_MOSI = 2,

		PB0_SPI1_SSEL = 0,
		PB0_UART0_CTS = 2,

		PB1_SPI1_SCLK = 0,
		PB1_UART0_RTS = 2,

		PB2_SPI1_MISO = 0,
		PB2_UART0_TXD = 2,

		PB3_SPI1_MOSI = 0,
		PB3_UART0_RXD = 2,

		PB4_ETH_TXEN = 0,

		PB5_ETH_COL = 0,

		PB6_ETH_RXD3 = 0,

		PB7_ETH_RXCLK = 0,

		PB8_ETH_DUP = 0,

		PB9_ETH_TXCLK = 0,

		PB10_ETH_TXD0 = 0,

		PB11_ETH_TXD1 = 0,

		PB12_ETH_TXD2 = 0,

		PB13_ETH_TXD3 = 0,

		PC0_UART1_CTS = 0,
		PC0_PWM0 = 2,
		PC0_CAP0 = 2,

		PC1_UART1_RTS = 0,
		PC1_PWM1 = 2,
		PC1_CAP1 = 2,

		PC2_UART1_TXD = 0,
		PC2_PWM2 = 2,
		PC2_CAP2 = 2,
		
		PC3_UART1_RXD = 0,
		PC3_PWM3 = 2,
		PC3_CAP3 = 2,

		PC4_I2C1_SCL = 0,
		PC4_PWM4 = 2,
		PC4_CAP4 = 2,

		PC5_I2C1_SDA = 0,
		PC5_PWM5 = 2,
		PC5_CAP5 = 2,

		PC6_UART2_TXD = 2,

		PC7_UART2_RXD = 2,

		PC8_PWM0 = 0,
		PC8_CAP0 = 0,
		PC8_I2C0_SCL = 2,
		
		PC9_PWM1 = 0,
		PC9_CAP1 = 0,
		PC9_I2C0_SDA = 2,

		PC10_UART2_TXD = 0,
		PC10_PWM2 = 2,
		PC10_CAP2 = 2,

		PC11_UART2_RXD = 0,
		PC11_PWM3 = 2,
		PC11_CAP3 = 2,

		PC12_SPI0_SSEL = 2,
		
		PC13_SPI0_SCLK = 2,

		PC14_SPI0_MISO = 2,

		PC15_SPI0_MOSI = 2,

		PD0_ETH_CRS = 0,

		PD1_ETH_RXDV = 0,

		PD2_ETH_RXD0 = 0,

		PD3_ETH_RXD1 = 0,

		PD4_ETH_RXD2 = 0
	}altfunc_t;

	// 핀을 출력으로 설정합니다.
	// 
	// 반환
	//		에러를 반환합니다.
	// uint8_t pin
	//		출력으로 변경할 핀의 번호를 설정합니다.
	// strength_t strength
	//		출력의 전류 세기를 설정합니다. (LOW = 3mA / HIGH = 6mA)
	// otype_t otype
	//		출력핀의 출력 종류를 설정합니다.
	error_t setAsOutput(uint8_t pin, strength_t strength = HIGH, otype_t otype = PUSH_PULL) __attribute__((optimize("-O1")));

	// 핀의 출력 값을 설정합니다.
	// 
	// uint8_t pin
	//		출력을 변경할 핀의 번호를 설정합니다.
	// bool data
	//		출력의 값을 설정합니다.
	void setOutput(uint8_t pin, bool data) __attribute__((optimize("-O1")));

	// 핀을 대체 기능으로 설정합니다
	//
	// uint8_t pin
	//		대체 기능으로 변경할 핀의 번호를 설정합니다.
	// altfunc_t altFunc
	//		핀의 대체 기능을 설정합니다.
	// strength_t strength
	//		출력의 전류 세기를 설정합니다. (LOW = 3mA / HIGH = 6mA)
	// otype_t otype
	//		출력핀의 출력 종류를 설정합니다.
	error_t setAsAltFunc(uint8_t pin, altfunc_t altfunc, strength_t strength = HIGH, otype_t otype = PUSH_PULL) __attribute__((optimize("-O1")));

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	struct setup_t
	{
		YSS_GPIO_Peri *dev;
		PORTX_TypeDef *afc;
		PORTX_TypeDef *padcon;
		const int8_t *outputAf;
	};

	Gpio(const Drv::setup_t drvSetup, const setup_t setup);

private:
	YSS_GPIO_Peri *mDev;
	PORTX_TypeDef *mAfc;
	PORTX_TypeDef *mPadcon;
	const int8_t *mOutputAf;
};

#endif