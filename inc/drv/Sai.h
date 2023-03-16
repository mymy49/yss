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

#ifndef YSS_DRV_SAI__H_
#define YSS_DRV_SAI__H_

#include "mcu.h"

#if defined(STM32F4) || defined(STM32F7)

typedef volatile uint32_t	YSS_SAI_Peri;
typedef volatile uint32_t	YSS_SAI_Block_Peri;

#elif defined(STM32F4_N)

typedef SAI_TypeDef			YSS_SAI_Peri;
typedef SAI_Block_TypeDef	YSS_SAI_Block_Peri;

#else

#define YSS_DRV_SAI_UNSUPPORTED

typedef volatile uint32_t	YSS_SAI_Peri;
typedef volatile uint32_t	YSS_SAI_Block_Peri;

#endif

#include "Drv.h"
#include "Dma.h"
#include <yss/error.h>

class Sai : public Drv
{
public:
	struct Config
	{
		YSS_SAI_Peri *peri;
		YSS_SAI_Block_Peri *block;
		Dma &txDma;
		Dma::DmaInfo txDmaInfo;
		Dma &rxDma;
		Dma::DmaInfo rxDmaInfo;
	};

	struct I2sSpecification
	{
		uint8_t dataBit;
		uint8_t chlen;
		uint8_t standard;
	};

	enum I2S
	{
		DATA_BIT_16BIT = 4,
		DATA_BIT_24BIT = 6,
		DATA_BIT_32BIT = 7,

		CHLEN_16BIT = 0,
		CHLEN_32BIT = 1,

		STD_PHILIPS = 0,
	};

	Sai(const Drv::Config drvConfig, const Config config);

	error initializeI2sReceiverAsSub(const I2sSpecification &spec);

	error initializeI2sTransmitterAsMain(const I2sSpecification &spec);

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

	uint32_t getTxCount(void);

	uint32_t getRxCount(void);

	void* getCurrrentBuffer(void);

	void releaseBuffer(uint32_t count);

	void flush(void);

private :
	YSS_SAI_Peri *mPeri;
	YSS_SAI_Block_Peri *mBlock;
	Dma *mTxDma, *mRxDma, *mCurrentDma;
	Dma::DmaInfo mTxDmaInfo, mRxDmaInfo;
	uint8_t *mDataBuffer, mDataSize;
	int32_t mLastTransferIndex, mTransferBufferSize, mLastCheckCount;
};

#endif

// 본 장치는 아직 완료되지 않음.
// 사용을 권장하지 않는다.
// 
// 현재 진행 상태는 SAI1B의 I2S 설정으로 수신만 동작하도로 작성되었다.