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

#ifndef YSS_DRV_I2S__H_
#define YSS_DRV_I2S__H_

#include "mcu.h"

#if defined(GD32F4)

typedef volatile uint32_t	YSS_I2S_Peri;

#else

#define YSS_DRV_I2S_UNSUPPORTED
typedef volatile uint32_t	YSS_I2S_Peri;

#endif

#include "Drv.h"
#include "Dma.h"

class I2s : public Drv
{
  public:
	struct Config
	{
		YSS_I2S_Peri *peri;
		Dma &txDma;
		const Dma::DmaInfo &txDmaInfo;
		Dma &rxDma;
		const Dma::DmaInfo &rxDmaInfo;
	};

	struct Specification
	{
	};

	enum
	{
		
	};

	I2s(const Drv::Config drvConfig, const Config config);
	
	// I2S 장치를 Main으로 초기화 한다.
	//
	// 반환
	//		발생한 error를 반환한다.
	error initAsMain(void);

	error setSpecification(const Specification &spec);
	void enable(bool en = true);

	// 설정된 전송 버퍼를 DMA로 시작부터 끝까지 전송하면 자동으로 전송 버퍼의 시작으로
	// 되돌아가 버퍼의 데이터를 다시 전송한다. stop() 함수를 통해 중단 할 때까지 계속 전송한다.
	// setTransferCircularDataHandlerThreadId() 함수를 사용하여 데이터 핸들러의 Thread ID를 설정하면
	// 전송이 절반 또는 전체 전송이 완료 됐을 때, 해당 쓰레드로 자동 진입 한다.
	//
	// 반환
	//		발생한 error를 반환한다.
	// void *des
	//		전송할 순환 데이터 버퍼이다.
	// uint16_t size
	//		순환 데이터 버퍼의 전체 크기이다. 최대 크기는 0xFFFF이다.
	void transferAsCircularMode(void *src, uint16_t size);

	// 현재 전송 중이거나 전송할 transferAsCircularMode() 함수의 버퍼 데이터를 처리해줄 
	// 쓰레드에서 한 차례 호출해주면 자동으로 해당 쓰레드의 ID가 등록된다.
	void setThreadIdOfTransferCircularDataHandler(void);
	
	// 현재 전송 카운트 숫자를 반환한다. transferAsCircularMode() 함수를 통해 데이터 전송을
	// 할 때에, 현재 채워야 하는 버퍼 카운트를 확인하기 위해 사용한다.
	uint16_t getCurrentTransferBufferCount(void);
	
	// transferAsCircularMode() 함수를 통해 전송중인 데이터를 중단한다.
	void stop(void);

	// 인터럽트 벡터에서 호출하는 함수이다.
	void isr(void);

  private :
	YSS_I2S_Peri *mPeri;
	Dma *mTxDma, *mRxDma;
	const Dma::DmaInfo *mTxDmaInfo, *mRxDmaInfo;
	const Specification *mLastSpec;
	uint8_t mRxData;
	int32_t  mThreadId, mDelayTime;
	bool mCompleteFlag;

};

#endif

