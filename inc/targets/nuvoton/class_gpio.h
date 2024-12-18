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

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)
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

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)
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

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)
		PA0_SPI0_MOSI = 4,
		PA0_SPI0_I2S_DO = 4,
		PA1_SPI0_MISO = 4,
		PA1_SPI0_I2S_DI = 4,
		PA2_SPI0_CLK = 4,
		PA2_SPI0_I2S_BCLK = 4,
		PA3_SPI0_SS = 4,
		PA3_SPI0_I2S_LRCLK = 4,
		PA4_SPI0_I2S_MCLK = 4,
		PB0_SPI0_I2S_MCLK = 8,
#endif

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)
		PC0_SPI1_SS = 7,
		PC0_SPI1_I2S_LRCLK = 7,
		PC1_SPI1_CLK = 7,
		PC1_SPI1_I2S_BCLK = 7,
		PC2_SPI1_MOSI = 7,
		PC2_SPI1_I2S_DO = 7,
		PC3_SPI1_MISO = 7,
		PC3_SPI1_I2S_DI = 7,
		PC4_SPI1_I2SMCLK = 7,
#endif

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)
		PA8_SPI2_MOSI = 4,
		PA8_SPI2_I2S_D0 = 4,
		PA9_SPI2_MISO = 4,
		PA9_SPI2_I2S_DI = 4,
		PA10_SPI2_CLK = 4,
		PA10_SPI2_I2S_BCLK = 4,
		PA11_SPI2_SS = 4,
		PA11_SPI2_I2S_LRCLK = 4,
#endif

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)
		PA11_PWM0_TM0_EXT = 13,
		PB15_PWM0_TM0_EXT = 13,
		PB5_PWM0_TM0 = 14,
		PC7_PWM0_TM0 = 14,
		PG2_PWM0_TM0 = 13,
		PH0_PWM0_TM0_EXT = 13,
#endif

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)
		PC14_PWM1_TM1_EXT = 13,
#endif

#if defined(__M480_FAMILY) || defined(__M43x_FAMILY)
		PB12_UART0_RXD = 6,
		PB13_UART0_TXD = 6,
#endif


	}altfunc_t;

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
	error_t setAsAltFunc(uint8_t pin, altfunc_t altfunc, otype_t otype = PUSH_PULL) __attribute__((optimize("-O1")));

	// 핀의 Pull Up/Pull Down 설정을 합니다.
	//
	// uint8_t pin
	//		Pull Up/Pull Down 설정을 변경할 핀의 번호를 설정합니다.
	// pupd_t pupd
	//		핀의 Pull Up/Pull Down을 설정합니다.
	error_t setPullUpDown(uint8_t pin, pupd_t pupd);

	/*
		GPIO를 엣지 또는 레벨 인터럽트로 활성화합니다.
		ISR 함수에서는 문맥전환을 유발하는 모든 함수의 호출을 금지합니다.
		yss.h 파일에서 문맥전환을 유발하는 함수 유형의 설명을 참고하세요.
		yss.h 파일에서 ISR 함수와 Callback 함수에 대한 구분 설명을 참고하세요. 
		.
		@ return : 에러를 반환합니다.
		.
		@ pin : 인터럽트를 설정한 포트의 핀 번호를 설정합니다.
		@ edge : 인터럽트를 감지할 엣지를 설정합니다.
		@ * isr : ISR 함수의 포인터를 설정합니다.
	*/
	error_t enablInterrupt(uint8_t pin, source_t src, void (*isr)(void));
	
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