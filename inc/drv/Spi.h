/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_SPI__H_
#define YSS_DRV_SPI__H_

#include "peripheral.h"
#include <stdint.h>

#if defined(STM32F4) || defined(STM32F0) || defined(STM32F7) || defined(GD32F1) || defined(STM32F1) || defined(STM32G4)

typedef SPI_TypeDef			YSS_SPI_Peri;

#elif defined(EFM32PG22)

typedef USART_TypeDef		YSS_SPI_Peri;

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

typedef SPI_T				YSS_SPI_Peri;

#else

typedef volatile uint32_t	YSS_SPI_Peri;

#define YSS_DRV_SPI_UNSUPPORTED

#endif

#include "Drv.h"
#include "Dma.h"
#include <yss/thread.h>

class Spi : public Drv
{
  public:
	typedef struct
	{
		int8_t mode;
		int32_t maxFreq;
		int8_t bit;
	}specification_t;

	typedef enum
	{
		MODE_MODE0 = 0,
		MODE_MODE1,
		MODE_MODE2,
		MODE_MODE3,
	}mode_t;

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	typedef enum
	{
		BIT_BIT8 = 8,
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
#elif defined(STM32F1) || defined(STM32F4)
	typedef enum
	{
		BIT_BIT8 = 0,
		BIT_BIT16
	}bit_t;
#elif defined(STM32F7) || defined(STM32F0)
	typedef enum
	{
		BIT_BIT4 = 3,
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
	}bit_t;
#endif

	// SPI 장치를 메인으로 초기화 한다. 초기화만 했을 뿐, 장치는 활성화 되어 있지 않다.
	// 
	// 반환
	//		에러를 반환한다.
	error_t initializeAsMain(void) __attribute__((optimize("-O1")));

	// SPI 장치를 서브로 초기화 한다. 초기화만 했을 뿐, 장치는 활성화 되어 있지 않다.
	// 현재는 테스트 중인 기능으로 사용을 권장하지 않는다.
	// 
	// 반환
	//		에러를 반환한다.
	error_t initializeAsSub(void) __attribute__((optimize("-O1")));

	// SPI 장치의 전송 세부 사항을 설정한다. 
	// 설정 전에 반드시 enable(false) 를 호출하여 장치를 먼저 비활성화 시키는게 필요하다.
	// 세부 설정 사항은 구조체 specification_t를 사용한다.
	// 
	// 반환
	//		에러를 반환한다.
	error_t setSpecification(const specification_t &spec) __attribute__((optimize("-O1")));
	
	// SPI 장치를 활성화/비활성화 시킨다.
	// 정상적인 전송을 위해 enable(true)를 하기 전에 setSpecification()를 사용하여 타겟 장치에 맞는 
	// 올바른 전송 사양 설정이 먼저 이뤄져야 한다.
	//
	// bool en
	//		활성화(true)/비활성화(false)로 설정한다.
	void enable(bool en) __attribute__((optimize("-O1")));

	// 데이터 한 바이트를 전송한다.
	// 수신 데이터는 무시한다.
	// 
	// int8_t data
	//		전송할 데이터 한 바이트를 설정한다.
	void send(uint8_t data) __attribute__((optimize("-O1")));
	
	// 여러 데이터를 전송한다.
	// 수신 데이터는 무시한다.
	// 
	// 반환
	//		에러를 반환한다.
	// void *src
	//		전송할 데이터의 포인터를 설정한다.
	// int32_t size
	//		전송할 데이터의 전체 크기를 설정한다.
	error_t send(void *src, int32_t  size) __attribute__((optimize("-O1")));

	// 데이터 한 바이트를 교환한다.
	// 한 바이트를 보내고 전달하는 동안 수신된 데이터를 반환한다.
	// 
	// 반환
	//		수신된 바이트를 반환한다.
	// int8_t data
	//		전송할 데이터 한 바이트를 설정한다.
	uint8_t exchange(uint8_t data) __attribute__((optimize("-O1")));

	// 여러 데이터를 교환한다.
	// 여러 바이트를 보내고 보내는 동안 수신된 데이터를 송신 버퍼에 다시 채운다.
	//
	// 반환
	//		에러를 반환한다.
	// void *des
	//		교환이 일어날 데이터의 버퍼를 설정한다. 전송한 버퍼는 다시 수신한 데이터로 채워진다.
	// int32_t size
	//		교환할 데이터의 전체 크기를 설정한다.
	error_t exchange(void *des, int32_t size) __attribute__((optimize("-O1")));

	// 설정된 전송 버퍼를 DMA로 시작부터 끝까지 전송한다. 버퍼를 순환 구조로 운영한다.
	// 전송이 완료되면 처음으로 되돌아가 버퍼의 데이터를 다시 전송한다. stop() 함수를 통해 중단 할 때까지 계속 전송한다.
	// setTransferCircularDataHandlerThreadId() 함수를 사용하여 데이터 핸들러의 Thread ID를 설정하면
	// 전송이 절반 또는 전체 전송이 완료 됐을 때, 해당 쓰레드로 자동 진입 한다. 기본적으로 해당 쓰레드가 돌고 있지만 추가적인 호출 기회를 갖게 된다.
	//
	// 반환
	//		발생한 error를 반환한다.
	// void *des
	//		수신할 순환 데이터 버퍼이다.
	// uint16_t count
	//		설정된 기본 데이터 단위의 전송 가능 횟수이다. (Byte 단위가 아님)
	void receiveAsCircularMode(void *src, uint16_t count) __attribute__((optimize("-O1")));

	uint32_t getTxCount(void) __attribute__((optimize("-O1")));

	uint32_t getRxCount(void) __attribute__((optimize("-O1")));

	void* getCurrentBuffer(void) __attribute__((optimize("-O1")));

	void releaseBuffer(int32_t count) __attribute__((optimize("-O1")));

	void flush(void) __attribute__((optimize("-O1")));

	// 인터럽트 벡터에서 호출되는 함수입니다.
	// 사용자 임의의 호출은 금지합니다.
	struct setup_t
	{
#if defined(GD32F1) || defined(STM32F1) || defined(GD32F4)  || defined(STM32F7) || defined(STM32F0) || defined(STM32F4)
		YSS_SPI_Peri *dev;
		Dma &txDma;
		Dma::dmaInfo_t txDmaInfo;
		Dma &rxDma;
		Dma::dmaInfo_t rxDmaInfo;
#elif defined(EFM32PG22)
		YSS_SPI_Peri *dev;
		Dma **dmaChannelList;
		Dma::dmaInfo_t *txDmaInfo;
		Dma::dmaInfo_t *rxDmaInfo;
#elif defined(STM32G4) || defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
		YSS_SPI_Peri *dev;
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
#endif
	};

	Spi(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

private:
	YSS_SPI_Peri *mDev;
#if defined(GD32F1) || defined(STM32F1) || defined(GD32F4)  || defined(STM32F7) || defined(STM32F0) || defined(STM32F4) || defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	Dma *mTxDma, *mRxDma;
#elif defined(STM32G4)
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	Dma *mRxDma;
#elif defined(EFM32PG22)
	Dma **mDmaChannelList;
	const Dma::dmaInfo_t *mTxDmaInfo;
	const Dma::dmaInfo_t *mRxDmaInfo;
#endif
	const specification_t *mLastSpec;
	uint8_t mRxData;
	threadId_t  mThreadId;
	bool mCompleteFlag;
	uint8_t *mDataBuffer, mDataSize;
	int32_t mTransferBufferSize, mTail;
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

