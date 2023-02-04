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

#ifndef YSS_DRV_SPI__H_
#define YSS_DRV_SPI__H_

#include "mcu.h"
#include <stdint.h>

#if defined(GD32F1) || defined(GD32F4) || defined(STM32F1) || defined(STM32F4) || defined(STM32F0)

typedef volatile uint32_t	YSS_SPI_Peri;

#else

typedef volatile uint32_t	YSS_SPI_Peri;

#define YSS_DRV_SPI_UNSUPPORTED

#endif

#include <targets/common/drv_spi_common.h>

#include "Drv.h"
#include "Dma.h"
#include <yss/thread.h>

class Spi : public Drv
{
  public:
	enum
	{
		MODE0 = 0,
		MODE1 = 1,
		MODE2 = 2,
		MODE3 = 3,

		BIT4 = 0,
		BIT5 = 1,
		BIT6 = 2,
		BIT7 = 3,
		BIT8 = 4,
		BIT9 = 5,
		BIT10 = 6,
		BIT11 = 7,
		BIT12 = 8,
		BIT13 = 9,
		BIT14 = 10,
		BIT15 = 11,
		BIT16 = 12,
	};

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

	// SPI 장치의 전송 세부 사항을 설정한다. 
	// 설정 전에 반드시 enable(false) 를 호출하여 장치를 먼저 비활성화 시키는게 필요하다.
	// 세부 설정 사항은 구조체 Specification를 사용한다.
	// 
	// 반환
	//		에러를 반환한다.
	bool setSpecification(const Specification &spec);
	
	// SPI 장치를 활성화/비활성화 시킨다.
	// 정상적인 전송을 위해 enable(true)를 하기 전에 setSpecification()를 사용하여 타겟 장치에 맞는 
	// 올바른 전송 사양 설정이 먼저 이뤄져야 한다.
	//
	// bool en
	//		활성화(true)/비활성화(false)로 설정한다.
	void enable(bool en);

	// 데이터 한 바이트를 전송한다.
	// 수신 데이터는 무시한다.
	// 
	// int8_t data
	//		전송할 데이터 한 바이트를 설정한다.
	void send(int8_t data);
	
	// 여러 데이터를 전송한다.
	// 수신 데이터는 무시한다.
	// 
	// 반환
	//		에러를 반환한다.
	// void *src
	//		전송할 데이터의 포인터를 설정한다.
	// int32_t size
	//		전송할 데이터의 전체 크기를 설정한다.
	error send(void *src, int32_t  size);

	// 데이터 한 바이트를 교환한다.
	// 한 바이트를 보내고 전달하는 동안 수신된 데이터를 반환한다.
	// 
	// 반환
	//		수신된 바이트를 반환한다.
	// int8_t data
	//		전송할 데이터 한 바이트를 설정한다.
	int8_t exchange(int8_t data);

	// 여러 데이터를 교환한다.
	// 여러 바이트를 보내고 보내는 동안 수신된 데이터를 송신 버퍼에 다시 채운다.
	//
	// 반환
	//		에러를 반환한다.
	// void *des
	//		교환이 일어날 데이터의 버퍼를 설정한다. 전송한 버퍼는 다시 수신한 데이터로 채워진다.
	// int32_t size
	//		교환할 데이터의 전체 크기를 설정한다.
	error exchange(void *des, int32_t size);

	// 인터럽트 벡터에서 호출되는 함수이다.
	// 사용자 임의의 호출은 금지한다.
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

