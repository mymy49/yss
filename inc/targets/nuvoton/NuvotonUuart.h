/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_UUART__H_
#define YSS_NUVOTON_DRV_UUART__H_

#include <drv/peripheral.h>
#include <stdint.h>
#include <drv/Uart.h>
#include <drv/Dma.h>
#include <yss/scheduler.h>

#if defined(UUART0)

/**
 * @file NuvotonUuart.h
 * @brief UUART (USCI-UART) driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonUuart
 * @brief Driver class for the USCI UART (UUART) peripheral on Nuvoton MCUs.
 *
 * @details
 * This class inherits from the base Uart class. It configures Nuvoton's Universal Serial Control
 * Interface (USCI) to operate as a UART. It provides functions to configure the communication baudrate,
 * stop bits, enable receive interrupts, and transmit data either synchronously or asynchronously via DMA.
 */
class NuvotonUuart : public Uart
{
public :
	// Internal system configurations. Do not call from user application.
	struct setup_t
	{
		UUART_T *dev;
		Dma::dmaInfo_t txDmaInfo;
	};

	NuvotonUuart(const Drv::setup_t drvSetup, const NuvotonUuart::setup_t setup) __attribute__((optimize("-O1")));

	/**
	 * @brief Initializes the USCI UART device.
	 * @details Configures data bit length (8-bit), LSB First, stop bits, receive ring buffers, and DMA.
	 *
	 * @param[in] config Configuration settings for the UUART (baudrate, stop bits, parity, rx buffer details, etc.).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t initialize(config_t config) __attribute__((optimize("-O1")));

	/**
	 * @brief Changes the UUART communication baudrate dynamically.
	 *
	 * @param[in] baudrate Desired baudrate in bps.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t changeBaudrate(int32_t baudrate) __attribute__((optimize("-O1")));

	/**
	 * @brief Sends a data block using DMA.
	 * @details Initiates an asynchronous transmission and yields the thread until completion.
	 *
	 * @param[in] src Pointer to the data transmit buffer.
	 * @param[in] size Size of the data block in bytes.
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	virtual error_t send(void *src, int32_t  size) __attribute__((optimize("-O1")));

	/**
	 * @brief Sends a single byte synchronously (blocking poll).
	 *
	 * @param[in] data Byte to transmit.
	 */
	virtual void send(int8_t data) __attribute__((optimize("-O1")));

	// Internal system interrupt routine. Do not call from user application.
	void isr(void) __attribute__((optimize("-O1")));

private :
	UUART_T *mDev;
	Dma *mTxDma;
	Dma::dmaInfo_t mTxDmaInfo;
};

#endif

#endif


