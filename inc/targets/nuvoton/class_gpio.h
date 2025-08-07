/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_GPIO_NUVOTON__H_
#define YSS_CLASS_GPIO_NUVOTON__H_

#include <yss/error.h>
#include <drv/peripheral.h>
#include <drv/Drv.h>

class Gpio : public Drv
{
public:
	/*
		GPIO의 출력 타입을 정의합니다.
	*/
	typedef enum 
	{
		PUSH_PULL = 1,
		OPEN_DRAIN,
		QUASI_BIDIR
	}otype_t;
	
	typedef enum
	{
		ALTFUNC_GPIO = 0,

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
		PA11_BPWM0_CH0 = 9,
		PA0_BPWM0_CH0 = 12,
		PG14_BPWM0_CH0 = 12,
		PE2_BPWM0_CH0 = 13,

		PA10_BPWM0_CH1 = 9,
		PA1_BPWM0_CH1 = 12,
		PG13_BPWM0_CH1 = 12,
		PE3_BPWM0_CH1 = 13,

		PA9_BPWM0_CH2 = 9,
		PA2_BPWM0_CH2 = 12,
		PG12_BPWM0_CH2 = 12,
		PE4_BPWM0_CH2 = 13,

		PA8_BPWM0_CH3 = 9,
		PA3_BPWM0_CH3 = 12,
		PG11_BPWM0_CH3 = 12,
		PE5_BPWM0_CH3 = 13,

		PF5_BPWM0_CH4 = 8,
		PC13_BPWM0_CH4 = 9,
		PA4_BPWM0_CH4 = 12,
		PG10_BPWM0_CH4 = 12,
		PE6_BPWM0_CH4 = 13,

		PF4_BPWM0_CH5 = 8,
		PD12_BPWM0_CH5 = 9,
		PA5_BPWM0_CH5 = 12,
		PG9_BPWM0_CH5 = 12,
		PE7_BPWM0_CH5 = 13,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
		PB11_BPWM1_CH0 = 10,
		PF3_BPWM1_CH0 = 11,
		PC7_BPWM1_CH0 = 12,
		PF0_BPWM1_CH0 = 12,

		PB10_BPWM1_CH1 = 10,
		PF2_BPWM1_CH1 = 11,
		PC6_BPWM1_CH1 = 12,
		PF1_BPWM1_CH1 = 12,
	
		PB9_BPWM1_CH2 = 10,
		PA12_BPWM1_CH2 = 11,
		PA7_BPWM1_CH2 = 12,

		PB8_BPWM1_CH3 = 10,
		PA13_BPWM1_CH3 = 11,
		PA6_BPWM1_CH3 = 12,

		PB7_BPWM1_CH4 = 10,
		PA14_BPWM1_CH4 = 11,
		PC8_BPWM1_CH4 = 12,

		PB6_BPWM1_CH5 = 10,
		PA15_BPWM1_CH5 = 11,
		PE13_BPWM1_CH5 = 12,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		PE8_EPWM0_BRAKE0 = 11,
		PB1_EPWM0_BRAKE0 = 13,

		PE9_EPWM0_BRAKE1 = 11,
		PB0_EPWM0_BRAKE1 = 13,

		PE8_EPWM0_CH0 = 10,
		PB5_EPWM0_CH0 = 11,
		PG8_EPWM0_CH0 = 11,
		PE7_EPWM0_CH0 = 12,
		PA5_EPWM0_CH0 = 13,

		PE9_EPWM0_CH1 = 10,
		PB4_EPWM0_CH1 = 11,
		PG7_EPWM0_CH1 = 11,
		PE6_EPWM0_CH1 = 12,
		PA4_EPWM0_CH1 = 13,

		PE10_EPWM0_CH2 = 10,
		PB3_EPWM0_CH2 = 11,
		PG6_EPWM0_CH2 = 11,
		PE5_EPWM0_CH2 = 12,
		PA3_EPWM0_CH2 = 13,

		PE11_EPWM0_CH3 = 10,
		PB2_EPWM0_CH3 = 11,
		PG5_EPWM0_CH3 = 11,
		PE4_EPWM0_CH3 = 12,
		PA2_EPWM0_CH3 = 13,

		PE12_EPWM0_CH4 = 10,
		PB1_EPWM0_CH4 = 11,
		PD14_EPWM0_CH4 = 11,
		PE3_EPWM0_CH4 = 12,
		PA1_EPWM0_CH4 = 13,

		PE13_EPWM0_CH5 = 10,
		PB0_EPWM0_CH5 = 11,
		PH11_EPWM0_CH5 = 11,
		PE2_EPWM0_CH5 = 12,
		PA0_EPWM0_CH5 = 13,

		PC14_EPWM0_SYNC_IN = 11,
		PA15_EPWM0_SYNC_IN = 12,

		PF5_EPWM0_SYNC_OUT = 9,
		PA11_EPWM0_SYNC_OUT = 10,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		PC12_I2C0_SCL = 4,
		PD7_I2C0_SCL = 4,
		PE13_I2C0_SCL = 4,
		PF3_I2C0_SCL = 4,
		PG0_I2C0_SCL = 4,

		PB5_I2C0_SCL = 6,
		PH2_I2C0_SCL = 6,
		PA5_I2C0_SCL = 9,
		PB9_I2C0_SCL = 9,
		PC1_I2C0_SCL = 9,

		PC8_I2C0_SDA = 4,
		PC11_I2C0_SDA = 4,
		PD6_I2C0_SDA = 4,
		PF2_I2C0_SDA = 4,
		PG1_I2C0_SDA = 4,
		PB4_I2C0_SDA = 6,
		PH3_I2C0_SDA = 6,
		PA4_I2C0_SDA = 9,
		PB8_I2C0_SDA = 9,
		PC0_I2C0_SDA = 9,

		PG2_I2C0_SMBAL = 4,
		PC3_I2C0_SMBAL = 9,
		PA3_I2C0_SMBAL = 10,

		PG3_I2C0_SMBSUS = 4,
		PC2_I2C0_SMBSUS = 9,
		PA2_I2C0_SMBSUS = 10,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		PF0_I2C1_SCL = 3,
		PA12_I2C1_SCL = 4,
		PD5_I2C1_SCL = 4,
		PG2_I2C1_SCL = 5,
		PB11_I2C1_SCL = 7,
		PA7_I2C1_SCL = 8,
		PE1_I2C1_SCL = 8,
		PA3_I2C1_SCL = 12,
		PB1_I2C1_SCL = 9,
		PC5_I2C1_SCL = 9,
		PB3_I2C1_SCL = 12,

		PF1_I2C1_SDA = 3,
		PA13_I2C1_SDA = 4,
		PD4_I2C1_SDA = 4,
		PG3_I2C1_SDA = 5,
		PB10_I2C1_SDA = 7,
		PA6_I2C1_SDA = 8,
		PE0_I2C1_SDA = 8,
		PA2_I2C1_SDA = 9,
		PB0_I2C1_SDA = 9,
		PC4_I2C1_SDA = 9,
		PB2_I2C1_SDA = 12,

		PG0_I2C1_SMBAL = 5,
		PB9_I2C1_SMBAL = 7,
		PC7_I2C1_SMBAL = 8,
		PH8_I2C1_SMBAL = 8,

		PG1_I2C1_SMBAL = 5,
		PB8_I2C1_SMBAL = 7,
		PC6_I2C1_SMBAL = 8,
		PH9_I2C1_SMBAL = 8,
#endif

#if defined(__M480_FAMILY)
		PD9_I2C2_SCL = 3,
		PA14_I2C2_SCL = 6,
		PD1_I2C2_SCL = 6,
		PA11_I2C2_SCL = 7,
		PB13_I2C2_SCL = 8,
		PA1_I2C2_SCL = 9,
		PH8_I2C2_SCL = 9,

		PD8_I2C2_SDA = 3,
		PA15_I2C2_SDA = 6,
		PD0_I2C2_SDA = 6,
		PA10_I2C2_SDA = 7,
		PB12_I2C2_SDA = 8,
		PA0_I2C2_SDA = 9,
		PH9_I2C2_SDA = 9,

		PB15_I2C2_SMBAL = 8,

		PB14_I2C2_SMBSUS = 8,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
		PA2_SPI0_CLK = 4,
		PA2_SPI0_I2S_BCLK = 4,
		PB14_SPI0_CLK = 4,
		PB14_SPI0_I2S_BCLK = 4,
		PD2_SPI0_CLK = 4,
		PD2_SPI0_I2S_BCLK = 4,
		PF8_SPI0_CLK = 5,
		PF8_SPI0_I2S_BCLK = 5,

		PA4_SPI0_I2S_MCLK = 4,
		PC14_SPI0_I2S_MCLK = 4,
		PD13_SPI0_I2S_MCLK = 4,
		PD14_SPI0_I2S_MCLK = 5,
		PF10_SPI0_I2S_MCLK = 5,
		PB0_SPI0_I2S_MCLK = 8,
		PB11_SPI0_I2S_MCLK = 9,

		PA1_SPI0_MISO = 4,
		PA1_SPI0_I2S_DI = 4,
		PB13_SPI0_MISO = 4,
		PB13_SPI0_I2S_DI = 4,
		PD1_SPI0_MISO = 4,
		PD1_SPI0_I2S_DI = 4,
		PF7_SPI0_MISO = 5,
		PF7_SPI0_I2S_DI = 5,

		PA0_SPI0_MOSI = 4,
		PA0_SPI0_I2S_DO = 4,
		PB12_SPI0_MOSI = 4,
		PB12_SPI0_I2S_DO = 4,
		PD0_SPI0_MOSI = 4,
		PD0_SPI0_I2S_DO = 4,
		PF6_SPI0_MOSI = 5,
		PF6_SPI0_I2S_DO = 5,

		PA3_SPI0_SS = 4,
		PA3_SPI0_I2S_LRCLK = 4,
		PB15_SPI0_SS = 4,
		PB15_SPI0_I2S_LRCLK = 4,
		PD3_SPI0_SS = 4,
		PD3_SPI0_I2S_LRCLK = 4,
		PF9_SPI0_SS = 5,
		PF9_SPI0_I2S_LRCLK = 5,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		PH6_SPI1_CLK = 3,
		PH6_SPI1_I2S_BCLK = 3,
		PA7_SPI1_CLK = 4,
		PA7_SPI1_I2S_BCLK = 4,
		PB3_SPI1_CLK = 5,
		PB3_SPI1_I2S_BCLK = 5,
		PH8_SPI1_CLK = 6,
		PH8_SPI1_I2S_BCLK = 6,
		PC1_SPI1_CLK = 7,
		PC1_SPI1_I2S_BCLK = 7,
		
		PA5_SPI1_I2SMCLK = 4,
		PB1_SPI1_I2SMCLK = 5,
		PD13_SPI1_I2SMCLK = 5,
		PH10_SPI1_I2SMCLK = 6,
		PC4_SPI1_I2SMCLK = 7,
		
		PH4_SPI1_MISO = 3,
		PH4_SPI1_I2S_DI = 3,
		PC7_SPI1_MISO = 4,
		PC7_SPI1_I2S_DI = 4,
		PB5_SPI1_MISO = 5,
		PB5_SPI1_I2S_DI = 5,
		PE1_SPI1_MISO = 6,
		PE1_SPI1_I2S_DI = 6,
		PC3_SPI1_MISO = 7,
		PC3_SPI1_I2S_DI = 7,
		
		PH5_SPI1_MOSI = 3,
		PH5_SPI1_I2S_DO = 3,
		PC6_SPI1_MOSI = 4,
		PC6_SPI1_I2S_DO = 4,
		PB4_SPI1_MOSI = 5,
		PB4_SPI1_I2S_DO = 5,
		PE0_SPI1_MOSI = 6,
		PE0_SPI1_I2S_DO = 6,
		PC2_SPI1_MOSI = 7,
		PC2_SPI1_I2S_DO = 7,
		
		PH7_SPI1_SS = 3,
		PH7_SPI1_I2S_LRCLK = 3,
		PA6_SPI1_SS = 4,
		PA6_SPI1_I2S_LRCLK = 4,
		PB2_SPI1_SS = 5,
		PB2_SPI1_I2S_LRCLK = 5,
		PH9_SPI1_SS = 6,
		PH9_SPI1_I2S_LRCLK = 6,
		PC0_SPI1_SS = 7,
		PC0_SPI1_I2S_LRCLK = 7,
#endif

#if defined(__M480_FAMILY)
		PG3_SPI2_CLK = 3,
		PG3_SPI2_I2S_BCLK = 3,
		PA10_SPI2_CLK = 4,
		PA10_SPI2_I2S_BCLK = 4,
		PA13_SPI2_CLK = 5,
		PA13_SPI2_I2S_BCLK = 5,
		PE8_SPI2_CLK = 5,
		PE8_SPI2_I2S_BCLK = 5,

		PB0_SPI2_I2SMCLK = 4,
		PC13_SPI2_I2SMCLK = 4,
		PE12_SPI2_I2SMCLK = 5,
		
		PG4_SPI2_MISO = 3,
		PG4_SPI2_I2S_DI = 3,
		PA9_SPI2_MISO = 4,
		PA9_SPI2_I2S_DI = 4,
		PA14_SPI2_MISO = 5,
		PA14_SPI2_I2S_DI = 5,
		PE9_SPI2_MISO = 5,
		PE9_SPI2_I2S_DI = 5,
		
		PF11_SPI2_MOSI = 3,
		PF11_SPI2_I2S_D0 = 3,
		PA8_SPI2_MOSI = 4,
		PA8_SPI2_I2S_D0 = 4,
		PA15_SPI2_MOSI = 5,
		PA15_SPI2_I2S_D0 = 5,
		PE10_SPI2_MOSI = 5,
		PE10_SPI2_I2S_D0 = 5,
		
		PG2_SPI2_SS = 3,
		PG2_SPI2_I2S_LRCLK = 3,
		PA11_SPI2_SS = 4,
		PA11_SPI2_I2S_LRCLK = 4,
		PA12_SPI2_SS = 5,
		PA12_SPI2_I2S_LRCLK = 5,
		PE11_SPI2_SS = 5,
		PE11_SPI2_I2S_LRCLK = 5,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		PG2_PWM0_TM0 = 13,
		PB5_PWM0_TM0 = 14,
		PC7_PWM0_TM0 = 14,
		PA11_PWM0_TM0_EXT = 13,
		PB15_PWM0_TM0_EXT = 13,
		PH0_PWM0_TM0_EXT = 13,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		PC14_PWM1_TM1 = 13,
		PG3_PWM1_TM1 = 13,
		PB4_PWM1_TM1 = 14,
		PC6_PWM1_TM1 = 14,
		PA10_PWM1_TM1_EXT = 13,
		PB14_PWM1_TM1_EXT = 13,
		PH1_PWM1_TM1_EXT = 13,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		PG4_PWM2_TM2 = 13,
		PA7_PWM2_TM2 = 14,
		PB3_PWM2_TM2 = 14,
		PD0_PWM2_TM1 = 14,
		PA9_PWM2_TM2_EXT = 13,
		PB13_PWM2_TM2_EXT = 13,
		PH2_PWM2_TM2_EXT = 13,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		PF11_PWM3_TM3 = 13,
		PA6_PWM3_TM3 = 14,
		PB2_PWM3_TM3 = 14,
		PA8_PWM3_TM3_EXT = 13,
		PB12_PWM3_TM3_EXT = 13,
		PH3_PWM3_TM3_EXT = 13,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
		PA15_UART0_RXD = 3,
		PC11_UART0_RXD = 3,
		PF2_UART0_RXD = 3,
		PF1_UART0_RXD = 4,
		PB8_UART0_RXD = 5,
		PB12_UART0_RXD = 6,
		PA0_UART0_RXD = 7,
		PA6_UART0_RXD = 7,
		PH11_UART0_RXD = 8,
		PD2_UART0_RXD = 9,
		PA4_UART0_RXD = 11,
		
		PA14_UART0_TXD = 3,
		PC12_UART0_TXD = 3,
		PF3_UART0_TXD = 3,
		PB9_UART0_TXD = 5,
		PB13_UART0_TXD = 6,
		PA1_UART0_TXD = 7,
		PA7_UART0_TXD = 7,
		PH10_UART0_TXD = 8,
		PD3_UART0_TXD = 9,
		PA5_UART0_TXD = 11,

		PB11_UART0_nCTS = 5,
		PB15_UART0_nCTS = 6,
		PA5_UART0_nCTS = 7,
		PC7_UART0_nCTS = 7,

		PB10_UART0_nRTS = 5,
		PB14_UART0_nRTS = 6,
		PA4_UART0_nRTS = 7,
		PC6_UART0_nRTS = 7,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		PF1_UART1_RXD = 2,
		PD6_UART1_RXD = 3,
		PD10_UART1_RXD = 3,
		PB2_UART1_RXD = 6,
		PB6_UART1_RXD = 6,
		PA8_UART1_RXD = 7,
		PA2_UART1_RXD = 8,
		PC8_UART1_RXD = 8,
		PG1_UART1_RXD = 8,
		PH9_UART1_RXD = 10,
		
		PF0_UART1_TXD = 2,
		PD7_UART1_TXD = 3,
		PD11_UART1_TXD = 3,
		PB3_UART1_TXD = 6,
		PB7_UART1_TXD = 6,
		PA9_UART1_TXD = 7,
		PA3_UART1_TXD = 8,
		PE13_UART1_TXD = 8,
		PG0_UART1_TXD = 8,
		PH8_UART1_TXD = 10,

		PB9_UART1_nCTS = 6,
		PA1_UART1_nCTS = 8,
		PE11_UART1_nCTS = 8,

		PB8_UART1_nRTS = 6,
		PA0_UART1_nRTS = 8,
		PE12_UART1_nRTS = 8,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		PF5_UART2_RXD = 2,
		PE15_UART2_RXD = 3,
		PG0_UART2_RXD = 6,
		PB0_UART2_RXD = 7,
		PD12_UART2_RXD = 7,
		PE9_UART2_RXD = 7,
		PC0_UART2_RXD = 8,
		PC4_UART2_RXD = 8,
		PB4_UART2_RXD = 12,
		
		PF4_UART2_TXD = 2,
		PE14_UART2_TXD = 3,
		PG1_UART2_TXD = 6,
		PB1_UART2_TXD = 7,
		PC13_UART2_TXD = 7,
		PE8_UART2_TXD = 7,
		PC1_UART2_TXD = 8,
		PC5_UART2_TXD = 12,

		PD9_UART2_nCTS = 4,
		PF5_UART2_nCTS = 4,
		PC2_UART2_nCTS = 8,

		PD8_UART2_nRTS = 4,
		PF4_UART2_nRTS = 4,
		PC3_UART2_nRTS = 8,
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		PA14_USBD_DP = 14,
		PA13_USBD_DN = 14,
		PA15_USB_OTG_ID = 14,
		PA12_USB_VBUS = 14,
#endif
	}altFunc_t;

	typedef enum
	{
		PUPD_NONE = 0,
		PUPD_PULL_UP,
		PUPD_PULL_DOWN
	}pupd_t;
	
	/*
		GPIO 인터럽트가 감지하는 소스를 정의합니다.
	*/
	typedef enum
	{
		EDGE_RISING,
		EDGE_FALLING,
		EDGE_BOTH,
		LEVEL_HIGH,
		LEVEL_LOW
	}source_t;

	// 핀을 출력으로 설정합니다.
	// 
	// 반환
	//		에러를 반환합니다.
	// uint8_t pin
	//		출력으로 변경할 핀의 번호를 설정합니다.
	// otype_t otype
	//		출력핀의 출력 종류를 설정합니다.
	error_t setAsOutput(uint8_t pin, otype_t otype = PUSH_PULL) __attribute__((optimize("-O1")));

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
	// otype_t otype
	//		출력핀의 출력 종류를 설정합니다.
	error_t setAsAltFunc(uint8_t pin, altFunc_t altfunc, otype_t otype = PUSH_PULL) __attribute__((optimize("-O1")));

	// 핀의 Pull Up/Pull Down 설정을 합니다.
	//
	// uint8_t pin
	//		Pull Up/Pull Down 설정을 변경할 핀의 번호를 설정합니다.
	// pupd_t pupd
	//		핀의 Pull Up/Pull Down을 설정합니다.
	error_t setPullUpDown(uint8_t pin, pupd_t pupd);

	/*
	 *	GPIO를 엣지 또는 레벨 인터럽트로 활성화합니다.
	 *	ISR 함수에서는 문맥전환을 유발하는 모든 함수의 호출을 금지합니다.
	 *	yss.h 파일에서 문맥전환을 유발하는 함수 유형의 설명을 참고하세요.
	 *	yss.h 파일에서 ISR 함수와 Callback 함수에 대한 구분 설명을 참고하세요. 
	 *	.
	 *	@ return : 에러를 반환합니다.
	 *	.
	 *	@ pin : 인터럽트를 설정한 포트의 핀 번호를 설정합니다.
	 *	@ edge : 인터럽트를 감지할 엣지를 설정합니다.
	 *	@ * isr : ISR 함수의 포인터를 설정합니다.
	 */
	error_t enablInterrupt(uint8_t pin, source_t src, void (*isr)(void));

	/*
	 *	GPIO 핀의 현재 상태를 읽어옵니다.
	 *	.
	 *	@ return : 핀의 상태에 따라 High는 true, Low는 false를 반환합니다.
	 */
	bool getInputData(uint8_t pin);
	
	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	struct setup_t
	{
		YSS_GPIO_Peri *dev;
		volatile uint32_t *mfp;
	};

	Gpio(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void);

private:
	YSS_GPIO_Peri *mDev;
	volatile uint32_t *mMfp, *mOutputReg;
	void (*mIsr[16])(void);
};

#endif