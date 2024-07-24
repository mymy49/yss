/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_CRC32__H_
#define YSS_DRV_CRC32__H_

#include "peripheral.h"

#if defined(GD32F1) || defined(STM32F4) || defined(STM32F7) || defined(STM32F1)
typedef CRC_TypeDef		YSS_CRC32_Dev;
#else
typedef void YSS_CRC32_Dev;
#define YSS_DRV_CRC32_UNSUPPORTED
#endif

#include "Drv.h"

class Crc32 : public Drv
{
public:
	// 현재까지 계산된 CRC32의 값을 모두 초기화 한다.
	void resetCrc32Value(void);
	
	// 설정된 데이터 스트림을 리틀 엔디언 방식으로 32비트 단위로 계산한다.
	// 
	//	void *src
	//		CRC32를 계산할 데이터의 소스를 설정한다.
	//	uint32_t size
	//		src의 데이터 크기를 설정한다.
	void calculateInLittleEndian(void *src, uint32_t size);

	// 설정된 데이터 스트림을 빅 엔디언 방식으로 32비트 단위로 계산한다.
	// 
	//	void *src
	//		CRC32를 계산할 데이터의 소스를 설정한다.
	//	uint32_t size
	//		src의 데이터 크기를 설정한다.
	void calculateInBigEndian(void *src, uint32_t size);
	
	// 현재 계산된 CRC32의 값을 얻어온다.
	//
	// 반환
	//		현재까지 계산된 CRC32의 값을 반환한다.
	uint32_t getCrc32Value(void);
	
	// 아래 함수들은 시스템 함수로 사용자 호출을 금한다.
	Crc32(YSS_CRC32_Dev *peri, const Drv::setup_t drvSetup);

private:
	YSS_CRC32_Dev *mPeri;
};

#endif

// 초기화 방법
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급한다.
//		- 클럭을 공급하면 바로 사용 가능한 상태가 된다.

// 사용 방법
//		- resetCrc32Value() 함수를 호출하여 계산 값을 초기화 한다.
//		- 데이터 구성이 빅 엔디안인지 리틀 엔디안인지 구분하여 calculateInLittleEndian() 또는 calculateInBigEndian() 함수를 호출하여 계산한다.
//		- getCrc32Value() 함수를 사용하여 결과를 얻어온다.