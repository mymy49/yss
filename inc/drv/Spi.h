/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_SPI__H_
#define YSS_DRV_SPI__H_

#include "Drv.h"
#include <yss/error.h>

class Spi : public Drv
{
  public:
	typedef enum
	{
		MODE_MAIN = 0,
		MODE_SUB,
	}mode_t;
	
	typedef enum
	{
		CLOCK_MODE_MODE0 = 0,
		CLOCK_MODE_MODE1,
		CLOCK_MODE_MODE2,
		CLOCK_MODE_MODE3,
	}clockMode_t;

	typedef enum
	{
		BIT_BIT4 = 0,
		BIT_BIT5,
		BIT_BIT6,
		BIT_BIT7,
		BIT_BIT8,
		BIT_BIT9,
		BIT_BIT10,
		BIT_BIT11,
		BIT_BIT12,
		BIT_BIT13,
		BIT_BIT14,
		BIT_BIT15,
		BIT_BIT16,
		BIT_BIT17,
		BIT_BIT18,
		BIT_BIT19,
		BIT_BIT20,
		BIT_BIT21,
		BIT_BIT22,
		BIT_BIT23,
		BIT_BIT24,
		BIT_BIT25,
		BIT_BIT26,
		BIT_BIT27,
		BIT_BIT28,
		BIT_BIT29,
		BIT_BIT30,
		BIT_BIT31,
		BIT_BIT32,
	}bit_t;

	typedef struct
	{
		clockMode_t mode;
		int32_t maxFreq;
		bit_t bit;
	}specification_t;

	typedef struct
	{
		mode_t mode;
	}config_t;

	// SPI 장치를 초기화 한다. 초기화만 했을 뿐, 장치는 활성화 되어 있지 않다.
	// 
	// 반환
	//		에러를 반환한다.
	virtual error_t initialize(config_t config) __attribute__((optimize("-O1"))) = 0;

	// SPI 장치의 전송 세부 사항을 설정한다. 
	// 설정 전에 반드시 enable(false) 를 호출하여 장치를 먼저 비활성화 시키는게 필요하다.
	// 세부 설정 사항은 구조체 specification_t를 사용한다.
	// 
	// 반환
	//		에러를 반환한다.
	virtual error_t setSpecification(const specification_t &spec) __attribute__((optimize("-O1"))) = 0;
	
	// 데이터 한 바이트를 전송한다.
	// 수신 데이터는 무시한다.
	// 
	// int8_t data
	//		전송할 데이터 한 바이트를 설정한다.
	virtual void send(uint32_t data) __attribute__((optimize("-O1"))) = 0;
	
	// 여러 데이터를 전송한다.
	// 수신 데이터는 무시한다.
	// 
	// 반환
	//		에러를 반환한다.
	// void *src
	//		전송할 데이터의 포인터를 설정한다.
	// int32_t size
	//		전송할 데이터의 전체 크기를 설정한다.
	virtual error_t send(void *src, int32_t  size) __attribute__((optimize("-O1"))) = 0;

	// 데이터 한 바이트를 교환한다.
	// 한 바이트를 보내고 전달하는 동안 수신된 데이터를 반환한다.
	// 
	// 반환
	//		수신된 바이트를 반환한다.
	// int8_t data
	//		전송할 데이터 한 바이트를 설정한다.
	virtual uint32_t exchange(uint32_t data) __attribute__((optimize("-O1"))) = 0;

	// 여러 데이터를 교환한다.
	// 여러 바이트를 보내고 보내는 동안 수신된 데이터를 송신 버퍼에 다시 채운다.
	//
	// 반환
	//		에러를 반환한다.
	// void *des
	//		교환이 일어날 데이터의 버퍼를 설정한다. 전송한 버퍼는 다시 수신한 데이터로 채워진다.
	// int32_t size
	//		교환할 데이터의 전체 크기를 설정한다.
	virtual error_t exchange(void *des, int32_t size) __attribute__((optimize("-O1"))) = 0;

	// 인터럽트 벡터에서 호출되는 함수입니다.
	// 사용자 임의의 호출은 금지합니다.
	Spi(const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

protected:
	const specification_t *mLastSpec;
	mode_t mMode;

	// SPI 장치를 활성화/비활성화 시킨다.
	// 정상적인 전송을 위해 enable(true)를 하기 전에 setSpecification()를 사용하여 타겟 장치에 맞는 
	// 올바른 전송 사양 설정이 먼저 이뤄져야 한다.
	//
	// bool en
	//		활성화(true)/비활성화(false)로 설정한다.
	virtual void enable(bool en) __attribute__((optimize("-O1"))) = 0;
};

#endif

// 초기화 방법
//		- GPIO의 setAsAltFunc()함수를 사용해 관련된 포트를 SPI 포트로 변경한다.
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급한다.
//		- initialize() 함수를 사용해 장치를 마스터로 초기화 한다.
//		- enableInterrupt() 함수를 사용해 장치의 인터럽트를 활성화 한다.

// 전송 방법
//		- lock() 함수를 호출하여 다른 쓰레드에서 접근을 막는다.
//		- setSpecification() 함수를 호출하여 타겟에 맞는 전송 규격을 설정한다.
//		- enable(true) 함수를 호출하여 SPI를 활성화 시킨다.
//		- 포트를 설정하여 타겟의 Chip Select 핀을 Low로 설정한다.
//		- send() 함수 또는 excahnge() 함수를 이용하여 데이터를 전송 또는 교환한다.
//		- 포트를 설정하여 타겟의 Chip Select 핀을 High로 설정한다.
//		- enable(false) 함수를 호출하여 SPI를 비활성화 시킨다.
//		- unlock() 함수를 호출하여 현재 소유권을 해제하고 다른 쓰레드에게 접근을 개방한다.

