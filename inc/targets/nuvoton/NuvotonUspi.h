/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NUVOTON_USCI__H_
#define YSS_DRV_NUVOTON_USCI__H_

#include <drv/peripheral.h>
#include <stdint.h>

#include <drv/Spi.h>
#include <drv/Dma.h>
#include <yss/thread.h>

#if defined(USPI0)

class NuvotonUspi : public Spi
{
  public:
	virtual error_t initialize(config_t config) __attribute__((optimize("-O1")));

	virtual error_t setSpecification(const specification_t &spec) __attribute__((optimize("-O1")));
	
	virtual void enable(bool en) __attribute__((optimize("-O1")));

	virtual void send(uint32_t data) __attribute__((optimize("-O1")));
	
	virtual error_t send(void *src, int32_t  size) __attribute__((optimize("-O1")));

	virtual uint32_t exchange(uint32_t data) __attribute__((optimize("-O1")));

	virtual error_t exchange(void *des, int32_t size) __attribute__((optimize("-O1")));

	// 인터럽트 벡터에서 호출되는 함수입니다.
	// 사용자 임의의 호출은 금지합니다.
	struct setup_t
	{
		USPI_T *dev;
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
	};

	NuvotonUspi(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

private:
	USPI_T *mDev;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	Dma *mTxDma, *mRxDma;
};

#endif

#endif

