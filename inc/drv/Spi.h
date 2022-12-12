////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_DRV_SPI__H_
#define YSS_DRV_SPI__H_

#include "mcu.h"
#include <stdint.h>

#if defined(GD32F1) || defined(GD32F4) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0)

typedef volatile uint32_t	YSS_SPI_Peri;

#else

#define YSS_DRV_SPI_UNSUPPORTED

#endif

#ifndef YSS_DRV_SPI_UNSUPPORTED

#include <targets/common/drv_spi_common.h>

#include "Drv.h"
#include "Dma.h"
#include <yss/thread.h>

class Spi : public Drv
{
  public:
	struct Config
	{
		YSS_SPI_Peri *peri;
		Dma &txDma;
		Dma::DmaInfo txDmaInfo;
		Dma &rxDma;
		Dma::DmaInfo rxDmaInfo;
	};

	struct Specification
	{
		int8_t mode;
		int32_t  maxFreq;
		int8_t bit;
	};

	Spi(const Drv::Config drvConfig, const Config config);

	// SPI 장치를 마스터로 초기화 한다. 초기화만 했을 뿐, 장치는 활성화 되어 있지 않다.
	// 
	// 반환
	//		에러를 반환한다.
	error initialize(void);

	// SPI 장치의 전송 세부 사항을 설정한다. 설정 전에 enable(false) 를 호출하여 장치를 먼저 비활성화 시킨다.
	// 세부 설정 사항은 구조체 Specification를 사용한다.
	// 
	// 반환
	//		에러를 반환한다.
	bool setSpecification(const Specification &spec);
	
	// SPI 장치를 활성화/비활성화 시킨다.
	// 정상적인 전송을 위해 enable(true)를 하기 전에 setSpecification()를 사용하여 타겟 장치에 맞는 
	// 올바른 전송 사양 설정이 먼저 이뤄져야 한다.
	void enable(bool en);

	error send(void *src, int32_t  size);
	int8_t exchange(int8_t data);
	error exchange(void *des, int32_t  size);
	void send(int8_t data);
	void isr(void);

  private:
	YSS_SPI_Peri *mPeri;
	Dma *mTxDma, *mRxDma;
	Dma::DmaInfo mTxDmaInfo, mRxDmaInfo;
	const Specification *mLastSpec;
	uint8_t mRxData;
	threadId  mThreadId;
	bool mCompleteFlag;
};

#endif

#endif

// 초기화 방법
//		- GPIO의 setAsAltFunc()함수를 사용해 관련된 포트를 SPI 포트로 변경한다.
//		- enableClock() 함수를 사용해 장치가 동작할 수 있도록 클럭을 공급한다.
//		- initialize() 함수를 사용해 장치를 마스터로 초기화 한다.
//		- enableInterrupt() 함수를 사용해 장치의 인터럽트를 활성화 한다.

