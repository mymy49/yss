/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_GPIO_STM32__H_
#define YSS_CLASS_GPIO_STM32__H_

#include <yss/error.h>
#include <drv/Drv.h>

class Gpio : public Drv
{
public:
#if defined(STM32F1)
#include "define_gpio_stm32f1.h"
#elif defined(STM32F4)
#include "define_gpio_stm32f4.h"
#elif defined(STM32F7)
#include "define_gpio_stm32f7.h"
#elif defined(STM32F0)
#include "define_gpio_stm32f0.h"
#endif

	// 핀을 출력으로 설정합니다.
	// 
	// 반환
	//		에러를 반환한다.
	// uint8_t pin
	//		출력으로 변경할 핀의 번호를 설정합니다.
	// ospeed_t ospeed
	//		출력핀의 상승/하강 속도를 설정합니다.
	// otype_t otype
	//		출력핀의 출력 타입을 설정합니다.
	error_t setAsOutput(uint8_t pin, ospeed_t ospeed = OSPEED_MID, otype_t otype = OTYPE_PUSH_PULL);

	// 핀의 출력 값을 설정합니다.
	// 
	// uint8_t pin
	//		출력으로 변경할 핀의 번호를 설정합니다.
	// bool data
	//		출력의 값을 설정합니다.
	void setOutput(uint8_t pin, bool data);

	// 핀 묶음을 한번에 대체 기능으로 설정합니다.
	// ospeed와 otype은 일괄적으로 동일하게 설정됩니다.
	//
	// altFunc_t *altport
	//		핀의 대체 기능을 설정하는 altFunc_t의 배열을 설정합니다.
	// uint8_t numOfPort
	//		altport의 총 배열의 개수를 설정합니다.
	// ospeed_t ospeed
	//		출력핀의 출력 종류를 설정합니다.
	void setPackageAsAltFunc(altFuncPort_t *altport, uint8_t numOfPort, ospeed_t ospeed, otype_t otype);

	// 핀을 대체 기능으로 설정합니다.
	//
	// altFunc_t *altport
	//		핀의 대체 기능을 설정하는 altFunc_t의 배열을 설정합니다.
	// uint8_t numOfPort
	//		altport의 총 배열의 개수를 설정합니다.
	// ospeed_t ospeed
	//		출력핀의 출력 종류를 설정합니다.
	error_t setAsAltFunc(uint8_t pin, altFunc_t altFunc, ospeed_t ospeed = OSPEED_MID, otype_t otype = OTYPE_PUSH_PULL);
	
	// 핀을 입력으로 설정합니다.
	//
	// uint8_t pin
	//		입력으로 변경할 핀의 번호를 설정합니다.
	// pupd_t pupd
	//		입력 핀의 Pull Up/Pull Down을 설정합니다.
	void setAsInput(uint8_t pin, pupd_t pupd = PUPD_NONE);
	
	// 핀을 아날로그 핀으로 설정합니다.
	//
	// uint8_t pin
	//		아날로그 입력으로 변경할 핀의 번호를 설정합니다.
	void setAsAnalog(uint8_t pin);
	
	// 핀의 Pull Up/Pull Down 설정을 합니다.
	//
	// uint8_t pin
	//		Pull Up/Pull Down 설정을 변경할 핀의 번호를 설정합니다.
	// pupd_t pupd
	//		핀의 Pull Up/Pull Down을 설정합니다.
	void setPullUpDown(uint8_t pin, pupd_t pupd);
		
	// 지정된 핀의 현재 레밸을 읽어 옵니다.
	//
	// 반환
	//		지정된 핀의 Low 레벨은 false, High 레벨은 true를 반환합니다.	
	// uint8_t pin
	//		레벨을 읽어올 핀의 번호를 설정합니다.
	bool getInputData(uint8_t pin);

	// 아래 함수들은 시스템 함수로 사용자 호출을 금한다.
	struct setup_t
	{
		YSS_GPIO_Peri *dev;
		uint8_t exti;
	};

	Gpio(const Drv::setup_t drvSetup, const setup_t setup);

	// 지정된 핀을 현재 포트의 외부 인터럽트 핀으로 설정합니다.
	//
	// uint8_t pin
	//		외부 인터럽트로 변경할 핀의 번호를 설정합니다.
	void setExti(uint8_t pin);

private:
	YSS_GPIO_Peri *mDev;
	uint8_t mExti;
};

#endif