/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_I2C__H_
#define YSS_DRV_I2C__H_

#include "peripheral.h"

#if defined(STM32F0) || defined(STM32F7) || defined(STM32F1) || defined(STM32F4)

typedef I2C_TypeDef			YSS_I2C_Peri;
#if defined(STM32F1) || defined(STM32F4)
#define I2C_NOT_USE_DMA
#endif

#elif defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

typedef I2C_T				YSS_I2C_Peri;
#define I2C_NOT_USE_DMA

#else

#define YSS_DRV_I2C_UNSUPPORTED
typedef volatile uint32_t	YSS_I2C_Peri;

#endif

#include "Drv.h"
#include <yss/error.h>

#if !defined(I2C_NOT_USE_DMA)
#include "Dma.h"
#endif

class I2c : public Drv
{
  public:
    typedef enum
	{
		SPEED_STANDARD = 0,
		SPEED_FAST,
		SPEED_FAST_PLUS
	}speed_t;

	typedef enum
	{
		MODE_MAIN = 0,
		MODE_SUB,
	}mode_t;

	typedef struct
	{
		mode_t mode;			// 통신 모드 (Main 전용)
		speed_t speed;			// 통신 속도 (Main 전용)
		uint8_t addr1;			// Sub Address1 (Sub 전용)
		uint8_t addr2;			// Sub Address2 (Sub 전용)
		void *rcvBuf;			// Sub 수신 버퍼 (Sub 전용)
		uint16_t rcvBufSize;	// Sub 수신 버퍼 크기 (Sub 전용)
	}config_t;

	error_t initialize(config_t config) __attribute__((optimize("-O1")));

	error_t send(uint8_t addr, void *src, uint32_t size, uint32_t timeout = 500) __attribute__((optimize("-O1")));

	error_t receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout = 500) __attribute__((optimize("-O1")));

	void stop(void) __attribute__((optimize("-O1")));

	// 여기부터 아래 내용들은 사용자가 호출할 필요가 없는 함수입니다.
	struct setup_t
	{
#if defined(I2C_NOT_USE_DMA)
		YSS_I2C_Peri *dev;
#elif defined(STM32F1) || defined(STM32F7) || defined(STM32F0) || defined(STM32F4)
		YSS_I2C_Peri *dev;
		Dma &txDma;
		Dma::dmaInfo_t txDmaInfo;
		Dma &rxDma;
		Dma::dmaInfo_t rxDmaInfo;
#endif
	};

	I2c(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

private :
	YSS_I2C_Peri *mDev;

#if defined(I2C_NOT_USE_DMA)
	int32_t mDataCount;
	uint8_t *mDataBuf, mAddr;
	error_t mError;
	bool mDir, mComplete;
#elif defined(STM32F7) || defined(STM32F0)
	Dma *mTxDma, *mRxDma;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
#endif
};

#endif

