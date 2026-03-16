/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_UART__H_
#define YSS_NUVOTON_DRV_UART__H_

#include <drv/Uart.h>
#include <drv/Dma.h>

class NuvotonUart : public Uart
{

public :
	struct setup_t
	{
		UART_T *dev;
		Dma::dmaInfo_t txDmaInfo;
	};

	NuvotonUart(const Drv::setup_t drvSetup, const NuvotonUart::setup_t setup) __attribute__((optimize("-O1")));

	error_t initialize(config_t config) __attribute__((optimize("-O1")));

	virtual error_t changeBaudrate(int32_t baudrate) __attribute__((optimize("-O1")));

	virtual error_t send(void *src, int32_t  size) __attribute__((optimize("-O1")));

	virtual void send(int8_t data) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

private :
	UART_T *mDev;
	Dma *mTxDma;
	Dma::dmaInfo_t mTxDmaInfo;
};

#endif

