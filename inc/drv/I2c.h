/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_I2C__H_
#define YSS_DRV_I2C__H_

#include "peripheral.h"

#if defined(STM32F0) || defined(STM32F7)

typedef I2C_TypeDef			YSS_I2C_Peri;

#elif defined(STM32F4) || defined(GD32F1) || defined(STM32F1)

typedef I2C_TypeDef			YSS_I2C_Peri;
#define I2C_NOT_USE_DMA
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
	struct setup_t
	{
		YSS_I2C_Peri *dev;
		Dma &txDma;
		Dma::dmaInfo_t txDmaInfo;
		Dma &rxDma;
		Dma::dmaInfo_t rxDmaInfo;
	};

	error_t initializeAsMain(uint8_t speed);

	error_t initializeAsSub(void *rcvBuf, uint16_t rcvBufSize, uint8_t addr1, uint8_t addr2 = 0);

	error_t send(uint8_t addr, void *src, uint32_t size, uint32_t timeout = 500);

	error_t receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout = 500);

	void stop(void);

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	I2c(const Drv::setup_t drvSetup, const setup_t setup);

	void isr(void);

private :
	YSS_I2C_Peri *mDev;

#if defined(I2C_NOT_USE_DMA)
	uint32_t mDataCount;
	uint8_t *mDataBuf, mAddr;
	bool mDir;
#else
	Dma *mTxDma, *mRxDma;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
#endif
};

#endif

