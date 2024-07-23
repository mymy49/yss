/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_PBUS__H_
#define YSS_DRV_PBUS__H_

#include "peripheral.h"

#if defined(STM32F7)

#else

#define YSS_DRV_PBUS_UNSUPPORTED

#endif

#include "Drv.h"
#include "Dma.h"
#include <yss/error.h>

class Pbus : public Drv
{
public:
	typedef struct
	{
		uint8_t dataLatency;		// HCLK * dataLatency
		uint8_t clockDiv;			// HCLK / clockDiv
		uint8_t busTurnaround;		// HCLK * busTurnaround
		uint8_t data;				// HCLK * data
		uint8_t addrHold;			// HCLK * addrHold
		uint8_t addrSetup;			// HCLK * addrSetup
	}specification_t;
	
	// Pbus 장치를 초기화 한다.
	//
	// 반환
	//		에러를 반환한다.
	error_t initialize(void);

	// Pbus 장치의 전송 세부 사항을 설정한다. 
	// 세부 설정 사항은 구조체 specification_t를 사용한다.
	// 
	// 반환
	//		에러를 반환한다.
	error_t setSpecification(const specification_t &spec);

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	Pbus(const Drv::setup_t drvSetup);

private:
};

#endif

