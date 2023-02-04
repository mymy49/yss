////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_CRC32__H_
#define YSS_DRV_CRC32__H_

#include "mcu.h"

#if defined(GD32F1) || defined(STM32F1)
typedef volatile uint32_t YSS_CRC32_Peri;
#else
typedef void YSS_CRC32_Peri;
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
	Crc32(YSS_CRC32_Peri *peri, const Drv::Config drvConfig);

private:
	YSS_CRC32_Peri *mPeri;
};

#endif

// 초기화 방법
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급한다.
//		- 클럭을 공급하면 바로 사용 가능한 상태가 된다.

// 사용 방법
//		- resetCrc32Value() 함수를 호출하여 계산 값을 초기화 한다.
//		- 데이터 구성이 빅 엔디안인지 리틀 엔디안인지 구분하여 calculateInLittleEndian() 또는 calculateInBigEndian() 함수를 호출하여 계산한다.
//		- getCrc32Value() 함수를 사용하여 결과를 얻어온다.