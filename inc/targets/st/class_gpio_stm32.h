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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_CLASS_GPIO_STM32__H_
#define YSS_CLASS_GPIO_STM32__H_

#include <yss/error.h>
#include <drv/Drv.h>

class Gpio : public Drv
{
public:
#if defined(STM32F1)
#include "define_gpio_stm32f1.h"
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