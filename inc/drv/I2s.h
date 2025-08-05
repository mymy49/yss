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

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

typedef SPI_T				YSS_I2S_Peri;

#else

#define YSS_DRV_I2S_UNSUPPORTED
typedef volatile uint32_t	YSS_I2S_Peri;

#endif

#include "Drv.h"
#include "Dma.h"

/*
	I2S 장치 드라이버 입니다.
	STM32에서는 SPI 장치와 I2S는 같은 장치로 동일한 번호의 SPI와 I2S는 동시 사용이 불가능합니다.
	사용의 예시는 본 헤더파일의 맨 아래에 있습니다.
*/
class I2s : public Drv
{
public:
	typedef enum
	{
		MODE_NOT_INITIALIZED = 0,
		MODE_MAIN_TX,
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
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
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
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
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
		int32_t sampleRate;
		bool mckoe;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		mode_t mode;
		dataBit_t dataBit;
		std_t std;
		int32_t sampleRate;
#endif
	}config_t;
	
	/*
		I2S 장치를 config_t에 설정된 값으로 초기화 합니다.
		sample rate의 주파수를 보장하지 않습니다.
		설정이 정상적으로 완료되면 getLrckFrequency() 함수와 getMclkFrequency() 함수를 통해 실제 클럭을 확인해야 합니다.
		.
		@ return : 발생한 error를 반환합니다.
		.
		@ &config : I2S의 설정을 지정합니다.
	*/
	error_t initialize(const config_t &config) __attribute__((optimize("-O1")));
	
	/*
		I2S 장치에 설정된 LRCLK 클럭의 주파수를 얻습니다.
		.
		@ return : LRCLK 클럭의 주파수를 반환합니다.
	*/
	uint32_t getLrclkFrequency(void) __attribute__((optimize("-O1")));
	
	/*
		I2S 장치에 설정된 MCLK 클럭의 주파수를 얻습니다.
		.
		@ return : MCLK 클럭의 주파수를 반환합니다.
	*/
	uint32_t getMclkFrequency(void) __attribute__((optimize("-O1")));
	
	/*
		설정된 전송 버퍼를 DMA로 시작부터 끝까지 전송합니다. 버퍼는 링 버퍼로 구조로 운영됩니다.
		전송이 완료되면 버퍼의 처음으로 되돌아가 버퍼의 데이터를 다시 전송합니다. stop() 함수를 통해 중단 할 때까지 전송은 계속 진행됩니다.
		getRxCount() 또는 getTxCount() 함수를 사용해 설정된 버퍼에서 전송이 완료된 개수를 구하하고 버퍼를 다시 채웁니다.
		.
		@ return : 발생한 error를 반환합니다.
		.
		@ *src : 전송할 순환 데이터 버퍼입니다.
		@ count : 설정된 기본 데이터 단위에 따르는 전송 가능 회수입니다. 최대 회수는 0xFFFF입니다.
	*/
	error_t transfer(void *src, uint16_t count) __attribute__((optimize("-O1")));
	
	/*
		데이터 전송을 중단합니다.
	*/
	void stop(void) __attribute__((optimize("-O1")));
	
	/*
		transfer() 함수를 통해 설정된 링 버퍼의 전송이 완료된 데이터의 카운트를 얻습니다.
		I2S의 모드가 MODE_MAIN_TX 또는 MODE_SUB_TX 일 때 유효합니다.
		.
		@ return : 링 버퍼의 송신이 완료된 데이터의 카운트를 반환합니다.
	*/
	uint32_t getTxCount(void) __attribute__((optimize("-O1")));
	
	/*
		transfer() 함수를 통해 설정된 링 버퍼의 전송이 완료된 데이터의 카운트를 얻습니다.
		I2S의 모드가 MODE_MAIN_RX 또는 MODE_SUB_RX 일 때 유효합니다.
		.
		@ return : 링 버퍼의 수신이 완료된 데이터의 카운트를 반환합니다.
	*/
	uint32_t getRxCount(void) __attribute__((optimize("-O1")));
	
	/*
		새로 채울 링버퍼의 현재 포인터를 얻습니다.
		getRxCount() 또는 getTxCount() 함수를 통해 얻은 카운트에 유효한 링 버퍼의 주소를 얻습니다.
		얻은 포인터로부터 증가하는 방향으로 데이터의 카운트의 수만큼 다음 데이터를 채워 넣는 방식으로 운영합니다.
		.
		@ return : 새로 채울 링 버퍼의 현재 포인터를 반환합니다.
	*/
	void* getCurrrentBuffer(void) __attribute__((optimize("-O1")));
	
	/*
		데이터를 채워 넣은 수를 인자로 넘겨 링 버퍼의 현재 포인터를 이동시킵니다.
		.
		@ count : 데이터를 채워 넣은 수를 설정합니다.
	*/
	void releaseBuffer(int32_t count) __attribute__((optimize("-O1")));
	
	// 아래 함수들은 시스템 함수로 사용자 호출을 금지합니다.
	typedef struct
	{
#if defined(STM32F1)  || defined(STM32F7) || defined(STM32F0) || defined(STM32F4)
		YSS_I2S_Peri *peri;
		Dma &txDma;
		const Dma::dmaInfo_t &txDmaInfo;
		Dma &rxDma;
		const Dma::dmaInfo_t &rxDmaInfo;
#elif defined(STM32G4) || defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
		YSS_I2S_Peri *dev;
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
#endif
	}setup_t;

	I2s(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

private :
	YSS_I2S_Peri *mDev;
	Dma *mCurrentDma;

#if defined(GD32F1) || defined(STM32F1) || defined(GD32F4)  || defined(STM32F7) || defined(STM32F0) || defined(STM32F4)
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	Dma *mTxDma, *mRxDma;
#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	uint32_t mReleasedSentCount;
#endif

	uint8_t *mDataBuffer, mDataSize;
	int32_t mLastTransferIndex, mTransferBufferSize, mLastCheckCount;
	uint32_t mLrclk, mMclk;
	mode_t mMode;
};

/*
	아래는 STM32F407 MCU에서 설정의 예입니다.

	gpioC.setAsAltFunc(7, Gpio::PC7_I2S3_MCK);
	gpioC.setAsAltFunc(10, Gpio::PC10_I2S3_CK);
	gpioC.setAsAltFunc(12, Gpio::PC12_I2S3_SD);
	gpioA.setAsAltFunc(4, Gpio::PA4_I2S3_WS);

	I2s::config_t i2s3Config = 
	{
		I2s::MODE_MAIN_TX,	//mode_t mode;
		I2s::BIT_16BIT,		//dataBit_t dataBit;
		I2s::CHLEN_16BIT,	//chlen_t chlen;
		I2s::STD_PHILIPS,	//std_t std;
		48000,				//int32_t sampleRate;
		true				//bool mckoe;
	};

	i2s3.enableClock();
	i2s3.initialize(i2s3Config);
	i2s3.enableInterrupt();
*/

#endif

