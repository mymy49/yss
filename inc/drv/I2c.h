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

#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY)

typedef I2C_T				YSS_I2C_Peri;

#else

#define YSS_DRV_I2C_UNSUPPORTED
typedef volatile uint32_t	YSS_I2C_Peri;

#endif

#include "Drv.h"
#include "Dma.h"
#include <yss/error.h>

class I2c : public Drv
{
  public:
	typedef enum
	{
		SPEED_STANDARD = 0,
		SPEED_FAST,
	}speed_t;

	typedef enum
	{
		MODE_MAIN = 0,
		MODE_SUB,
	}mode_t;

	typedef struct
	{
		mode_t mode;	// 통신 모드
		speed_t speed;	// 통신 속도
	}config_t;

	error_t initialize(config_t config);

	error_t send(uint8_t addr, void *src, uint32_t size, uint32_t timeout = 500);

	error_t receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout = 500);

	void stop(void);

	// 여기부터 아래 내용들은 사용자가 호출할 필요가 없는 함수입니다.
	struct setup_t
	{
#if defined(STM32F1) || defined(STM32F7) || defined(STM32F0) || defined(STM32F4)
		YSS_I2C_Peri *dev;
		Dma &txDma;
		Dma::dmaInfo_t txDmaInfo;
		Dma &rxDma;
		Dma::dmaInfo_t rxDmaInfo;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY)
		YSS_I2C_Peri *dev;
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
#endif
	};

	I2c(const Drv::setup_t drvSetup, const setup_t setup);

	void isr(void);

private :
	YSS_I2C_Peri *mDev;

#if defined(I2C_NOT_USE_DMA)
	uint32_t mDataCount;
	uint8_t *mDataBuf, mAddr;
	bool mDir;
#else

#if defined(STM32F1) || defined(STM32F7) || defined(STM32F0) || defined(STM32F4)
	Dma *mTxDma, *mRxDma;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
#elif defined(__M480_FAMILY) || defined(__M43x_FAMILY)
	Dma *mDma;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
#endif

#endif
};

#endif

