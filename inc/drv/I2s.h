/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_I2S__H_
#define YSS_DRV_I2S__H_

#include "peripheral.h"

#if defined(GD32F4)

typedef volatile uint32_t	YSS_I2S_Peri;

#elif defined(STM32F4) || defined(STM32F7) || defined(STM32G4)

typedef SPI_TypeDef			YSS_I2S_Peri;

#elif defined(__M480_FAMILY)

typedef SPI_T				YSS_I2S_Peri;

#else

#define YSS_DRV_I2S_UNSUPPORTED
typedef volatile uint32_t	YSS_I2S_Peri;

#endif

#include "Drv.h"
#include "Dma.h"

class I2s : public Drv
{
public:
	typedef enum
	{
		MODE_MAIN_TX = 0,
		MODE_MAIN_RX,
		MODE_SUB_TX,
		MODE_SUB_RX
	}mode_t;

	typedef enum
	{
#if defined(STM32F0) || defined(STM32F1) || defined(STM32F4) || defined(STM32F7)
		BIT_16BIT = 0,
		BIT_24BIT,
		BIT_32BIT
#elif defined(__M480_FAMILY)
		BIT_8BIT = 0,
		BIT_16BIT,
		BIT_24BIT,
		BIT_32BIT		
#endif
	}dataBit_t;
	
	typedef enum
	{
#if defined(STM32F0) || defined(STM32F1) || defined(STM32F4) || defined(STM32F7)
		CHLEN_16BIT = 0,
		CHLEN_32BIT,
#endif
	}chlen_t;

	typedef enum
	{
#if defined(STM32F0) || defined(STM32F1) || defined(STM32F4) || defined(STM32F7)
		STD_PHILIPS = 0,
		STD_MSB_JUSTIFIED,
		STD_LSB_JUSTIFIED,
		STD_PCM
#elif defined(__M480_FAMILY)
		STD_I2S_DATA = 0,
		STD_MSB_JUSTIFIED,
		STD_PCM_MODE_A,
		STD_PCM_MODE_B
#endif
	}std_t;

	typedef struct
	{
#if defined(STM32F0) || defined(STM32F1) || defined(STM32F4) || defined(STM32F7)
		mode_t mode;
		dataBit_t dataBit;
		chlen_t chlen;
		std_t std;
#elif defined(__M480_FAMILY)
		mode_t mode;
		dataBit_t dataBit;
		std_t std;
		int32_t sampleRate;
#endif
	}specification_t;

	// I2S 장치를 specification_t에 설정된 값으로 초기화 합니다.
	// sample rate의 주파수를 보장하지 않습니다. 설정이 정상적으로 완료되면 getBclkFrequency() 함수와 getMclkFrequency() 함수를 통해
	// 실제 클럭을 확인해야 합니다.
	//
	// 반환
	//		발생한 error_t를 반환합니다.
	error_t initialize(const specification_t &spec) __attribute__((optimize("-O1")));
	
	// I2S 장치에 설정된 BCLK 클럭의 주파수를 얻습니다.
	//
	// 반환
	//		BCLK 클럭의 주파수를 반환합니다.
	uint32_t getBclkFrequency(void);

	// I2S 장치에 설정된 MCLK 클럭의 주파수를 얻습니다.
	//
	// 반환
	//		MCLK 클럭의 주파수를 반환합니다.
	uint32_t getMclkFrequency(void);

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
	void transfer(void *src, uint16_t count);

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
	typedef struct
	{
#if defined(STM32F1)  || defined(STM32F7) || defined(STM32F0) || defined(STM32F4)
		YSS_I2S_Peri *peri;
		Dma &txDma;
		const Dma::dmaInfo_t &txDmaInfo;
		Dma &rxDma;
		const Dma::dmaInfo_t &rxDmaInfo;
#elif defined(STM32G4) || defined(__M480_FAMILY) || defined(__M43x_FAMILY)
		YSS_I2S_Peri *dev;
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
#endif
	}setup_t;

	I2s(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void);

  private :
	YSS_I2S_Peri *mDev;
#if defined(GD32F1) || defined(STM32F1) || defined(GD32F4)  || defined(STM32F7) || defined(STM32F0) || defined(STM32F4)
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	Dma *mTxDma, *mRxDma;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY)
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	Dma *mDma;
#endif
	uint8_t *mDataBuffer, mDataSize;
	int32_t mLastTransferIndex, mTransferBufferSize, mLastCheckCount;
	void (*mFrameErrorIsr)(void);
	uint32_t mBclk, mMclk;
};

#endif

// 본 장치는 아직 완료되지 않음.
// 사용을 권장하지 않는다.
// 
// TX와 RX의 동작은 확인됐지만 올바른 사용 방식이 확립되지 않음.

