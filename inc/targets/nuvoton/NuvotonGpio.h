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
#include <yss/thread.h>

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
		AF_PUSH_PULL = 0,
		AF_OPEN_DRAIN,
	}atype_t;
	
	typedef enum
	{
		SLEWRATE_NORMAL = 0,
		SLEWRATE_HIGH,
		SLEWRATE_FAST
	}slewrate_t;
	
	// altFunc_t
#if defined(__M46x_SUBFAMILY)
#include "def_gpio_m46x.h"
#elif defined(__M251_SUBFAMILY)
#include "def_gpio_m25x.h"
#elif defined(__M43x_SUBFAMILY)
#include "def_gpio_m43x.h"
#endif
	typedef struct
	{
		GPIO_T *port;
		uint8_t pin;
		altFunc_t func;
	}altFuncPackage_t;

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
	error_t setAsOutput(uint8_t pin, otype_t otype = PUSH_PULL, slewrate_t slewrate = SLEWRATE_NORMAL) __attribute__((optimize("-O1")));

	error_t setAsInput(uint8_t pin) __attribute__((optimize("-O1")));

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
	error_t setAsAltFunc(uint8_t pin, altFunc_t altfunc, atype_t atype = AF_PUSH_PULL, slewrate_t slewrate = SLEWRATE_NORMAL) __attribute__((optimize("-O1")));

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
	error_t setGpioInterrupt(uint8_t pin, source_t src, void (*isr)(void));

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
	error_t setGpioInterrupt(uint8_t pin, source_t src, triggerId_t trigger);
	
	/*
	 *	핀 묶음을 한번에 대체 기능으로 설정합니다.
	 *	Startup 코드에서 bss 초기화 전에 호출하는 목적으로 사용됩니다.
	 *	bss 초기화가 이뤄지기 전에 이 함수 외의 다른 함수를 사용하면 의도하지 않은 동작을 하게됩니다.
	 *	.
	 *	@ return : 에러를 반환합니다.
	 *	.
	 *	@ *package : 핀의 대체 기능을 설정하는 altFunc_t의 배열을 설정합니다.
	 *	@ count : 총 배열의 개수를 설정합니다.
	 */
	error_t setPackageAsAltFunc(altFuncPackage_t *package, uint8_t count, atype_t atype = AF_PUSH_PULL, slewrate_t slewrate = SLEWRATE_NORMAL);

	/*
	 *	GPIO 핀의 현재 상태를 읽어옵니다.
	 *	.
	 *	@ return : 핀의 상태에 따라 High는 true, Low는 false를 반환합니다.
	 */
	bool getInputData(uint8_t pin);
	
	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	struct setup_t
	{
		GPIO_T *dev;
		volatile uint32_t *mfp;
	};

	Gpio(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void);

private:
	GPIO_T *mDev;
	volatile uint32_t *mMfp, *mOutputReg;
	void (*mIsr[16])(void);
	bool mTriggerFlag[16];
	int32_t  mTriggerNum[16];
};

#endif