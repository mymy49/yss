/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_I2S__H_
#define YSS_DRV_I2S__H_

#include "mcu.h"

#if defined(GD32F4)

typedef volatile uint32_t	YSS_I2S_Peri;

#elif defined(STM32F4) || defined(STM32F7) || defined(STM32G4)

typedef SPI_TypeDef			YSS_I2S_Peri;

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
		const Dma::dmaInfo_t &txDmaInfo;
		Dma &rxDma;
		const Dma::dmaInfo_t &rxDmaInfo;
	};

	struct specification_t
	{
		uint8_t dataBit;
		uint8_t chlen;
		uint8_t standard;
	};

	enum
	{
		BIT_16BIT = 0,
		BIT_24BIT,
		BIT_32BIT,

		CHLEN_16BIT = 0,
		CHLEN_32BIT = 1,

		STD_PHILIPS = 0,
		STD_MSB_JUSTIFIED,
		STD_LSB_JUSTIFIED,
		STD_PCM
	};

	I2s(const Drv::setup_t drvSetup, const Config config);
	
	// I2S 장치를 Main으로 초기화 한다.
	//
	// 반환
	//		발생한 error_t를 반환한다.
	error_t initializeTransmitterAsMain(const specification_t &spec);

	// I2S 장치를 Sub로 초기화 한다.
	//
	// 반환
	//		발생한 error_t를 반환한다.
	error_t initializeReceiverAsSub(const specification_t &spec);

	error_t initializeTransmitterAsSub(const specification_t &spec);

	void enable(bool en = true);

	// 설정된 전송 버퍼를 DMA로 시작부터 끝까지 전송한다. 버퍼를 순환 구조로 운영한다.
	// 전송이 완료되면 처음으로 되돌아가 버퍼의 데이터를 다시 전송한다. stop() 함수를 통해 중단 할 때까지 계속 전송한다.
	// setTransferCircularDataHandlerThreadId() 함수를 사용하여 데이터 핸들러의 Thread ID를 설정하면
	// 전송이 절반 또는 전체 전송이 완료 됐을 때, 해당 쓰레드로 자동 진입 한다. 기본적으로 해당 쓰레드가 돌고 있지만 추가적인 호출 기회를 갖게 된다.
	//
	// 반환
	//		발생한 error를 반환한다.
	// void *des
	//		전송할 순환 데이터 버퍼이다.
	// uint16_t count
	//		설정된 기본 데이터 단위에 따르는 전송 가능 회수이다. 최대 회수는 0xFFFF이다.
	void transferAsCircularMode(void *src, uint16_t count);

	// 현재 전송 중이거나 전송할 transferAsCircularMode() 함수의 버퍼 데이터를 처리해줄 
	// 쓰레드에서 한 차례 호출해주면 자동으로 해당 쓰레드의 ID가 등록된다.
	void setThreadIdOfTransferCircularDataHandler(void);
	
	// 현재 전송 카운트 숫자를 반환한다. transferAsCircularMode() 함수를 통해 데이터 전송을
	// 할 때에, 현재 채워야 하는 버퍼 카운트를 확인하기 위해 사용한다.
	uint32_t getCurrentTransferBufferCount(void);
	
	// transferAsCircularMode() 함수를 통해 전송중인 데이터를 중단한다.
	void stop(void);

	uint32_t getTxCount(void);

	uint32_t getRxCount(void);

	void* getCurrrentBuffer(void);

	void releaseBuffer(int32_t count);

	void flush(void);

	void setFrameErrorIsr(void (*isr)(void));

	// 아래 함수들은 시스템 함수로 사용자 호출을 금한다.
	void isr(void);

  private :
	YSS_I2S_Peri *mPeri;
	Dma *mTxDma, *mRxDma, *mCurrentDma;
	uint8_t *mDataBuffer, mDataSize;
	int32_t mLastTransferIndex, mTransferBufferSize, mLastCheckCount;
	const Dma::dmaInfo_t *mTxDmaInfo, *mRxDmaInfo;
	void (*mFrameErrorIsr)(void);
};

#endif

// 본 장치는 아직 완료되지 않음.
// 사용을 권장하지 않는다.
// 
// TX와 RX의 동작은 확인됐지만 올바른 사용 방식이 확립되지 않음.

