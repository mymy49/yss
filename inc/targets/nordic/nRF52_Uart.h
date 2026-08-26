/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CLASS_UART_NRF52__H_
#define YSS_CLASS_UART_NRF52__H_

#include <drv/Uart.h>
#include <yss/scheduler.h>

class nRF52_Uart : public Uart
{
public :
	// Internal system configurations. Do not call from user application.
	struct setup_t
	{
		NRF_UARTE_Type *dev;
	};

	nRF52_Uart(const Drv::setup_t drvSetup, const nRF52_Uart::setup_t setup) __attribute__((optimize("-O1")));

	/**
	 * @brief Initializes the UART device.
	 * @details Sets up the baudrate, stop bits, parity bit depth, registers receive ring buffers, and configures DMA.
	 *
	 * @param[in] config Configuration settings for the UART (baudrate, stop bits, parity, rx buffer details, etc.).
	 * @return error_t Returns an error code (ERROR_NONE on success).
	 */
	error_t initialize(config_t config) __attribute__((optimize("-O1")));

	/**
	 * @brief Changes the UART communication baudrate dynamically.
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

	uint32_t getRxCount(void) __attribute__((optimize("-O1")));

	// Internal system interrupt routine. Do not call from user application.
	void isr(void) __attribute__((optimize("-O1")));

private :
	NRF_UARTE_Type *mDev;
	int8_t *mRxDmaBuf;
	volatile threadId_t mTxId;
};

#endif


