/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NVUTON_QUADSPI__H_
#define YSS_DRV_NVUTON_QUADSPI__H_

#include <drv/Quadspi.h>
#include <drv/Dma.h>

class NuvotonQuadspi : public Quadspi
{
public :
	virtual error_t initialize(config_t config);

	virtual error_t setSpecification(const specification_t &spec);

	virtual error_t transmit(dataform_t dataform, uint32_t data);

	virtual error_t exchange(dataform_t dataform, uint32_t &data);

	virtual error_t receive(dataform_t dataform, uint32_t &data);

	virtual error_t transmit(dataform_t dataform, void *data, uint32_t size);

	virtual error_t exchange(dataform_t dataform, void *data, uint32_t size);


	void isr(void);

	// 여기부터 아래 내용들은 사용자가 호출할 필요가 없는 함수입니다.
	struct setup_t
	{
		QSPI_T *dev;
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
	};

	NuvotonQuadspi(const Drv::setup_t drvSetup, const setup_t setup);

private :
	QSPI_T *mDev;
	Dma *mDma;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	uint32_t mClockMode;
};

#endif

