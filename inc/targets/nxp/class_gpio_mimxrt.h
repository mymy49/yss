/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_GPIO_NXP_MIMXRT__H_
#define YSS_CLASS_GPIO_NXP_MIMXRT__H_

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

	//void setPackageAsAltFunc(altFunc_t *altport, uint8_t numOfPort, uint8_t ospeed, uint8_t otype);

	//error setAsAltFunc(uint8_t pin, uint16_t altFunc, uint8_t ospeed = define::gpio::ospeed::MID, uint8_t otype = define::gpio::otype::PUSH_PULL);

	//void setAsInput(uint8_t pin, uint8_t pullUpDown = define::gpio::pupd::NONE);

	//void setAsAnalog(uint8_t pin);

	// 핀의 출력 값을 설정합니다.
	// 
	// uint8_t pin
	//		출력을 변경할 핀의 번호를 설정합니다.
	// bool data
	//		출력의 값을 설정합니다.
	void setOutput(uint8_t pin, bool data) __attribute__((optimize("-O1")));

	//void setPullUpDown(uint8_t pin, uint8_t pupd);

	//void setExti(uint8_t pin);
	
	//bool getInputData(uint8_t pin);

	// 아래 함수들은 시스템 함수로 사용자 호출을 금한다.
	struct setup_t
	{
		//YSS_GPIO_Peri *dev;
		//PORTX_TypeDef *afc;
		//PORTX_TypeDef *padcon;
		//const int8_t *outputAf;
	};

	Gpio(const Drv::setup_t drvSetup, const setup_t setup);

private:
	YSS_GPIO_Peri *mDev;
	//PORTX_TypeDef *mAfc;
	//PORTX_TypeDef *mPadcon;
	//const int8_t *mOutputAf;
};

#endif