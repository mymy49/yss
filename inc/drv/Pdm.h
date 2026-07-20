/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Pdm.h
 * @brief Pulse Density Modulation (PDM) driver class header file.
 */

#ifndef YSS_DRV_PDM__H_
#define YSS_DRV_PDM__H_

#include "peripheral.h"

#if defined(EFM32PG22)
typedef PDM_TypeDef				YSS_PDM_Peri;
#else
typedef volatile uint32_t		YSS_PDM_Peri;
#define YSS_DRV_PDM_UNSUPPORTED
typedef volatile uint32_t	YSS_PDM_Peri;
#endif

#include "Drv.h"
#include "Dma.h"
#include <yss/error.h>

/**
 * @class Pdm
 * @brief Driver class for the PDM (Pulse Density Modulation) interface.
 */
class Pdm : public Drv
{
public:
	/**
	 * @struct Configuration
	 * @brief Configuration parameters for the PDM interface initialization.
	 */
	struct Configuration
	{
		uint8_t ch0ClkPol;      ///< Channel 0 clock edge configuration.
		uint8_t ch1ClkPol;      ///< Channel 1 clock edge configuration.
		uint8_t stereoMode;     ///< Stereo mode configuration.
		uint8_t fifoLevel;      ///< FIFO usage threshold/length configuration.
		uint8_t dataFormat;     ///< Data format configuration.
		uint8_t numOfCh;        ///< Number of channels configuration.
		uint8_t filterOrder;    ///< Filter order configuration.
		uint8_t delayMuxSel;    ///< Data delay buffer multiplexer selection.
		uint32_t sampleRate;    ///< Sample rate frequency configuration.
		uint8_t downSampleRate; ///< Down-sampling rate configuration.
	};

	/**
	 * @brief Initializes the PDM peripheral with an external receive buffer.
	 * 
	 * @param[in] config The PDM setup configuration.
	 * @param[in] receiveBuffer Pointer to the buffer where received data will be stored.
	 * @param[in] receiveBufferLength The length of the receive buffer.
	 * @return error Returns ERROR_NONE on success.
	 */
	error initialize(Configuration config, uint32_t *receiveBuffer, int32_t  receiveBufferLength);

	/**
	 * @brief Initializes the PDM peripheral.
	 * 
	 * @param[in] config The PDM setup configuration.
	 * @param[in] receiveBufferLength The length of the receive buffer.
	 * @return error Returns ERROR_NONE on success.
	 */
	error initialize(Configuration config, int32_t  receiveBufferLength);

	/**
	 * @brief Starts PDM data reception.
	 */
	void start(void);

	/**
	 * @brief Stops PDM data reception.
	 */
	void stop(void);

	/**
	 * @brief Gets the number of items received in the buffer.
	 * 
	 * @return uint32_t Received data count.
	 */
	uint32_t getCount(void);

	/**
	 * @brief Releases the specified number of items from the receive buffer.
	 * 
	 * @param[in] count The number of data items to release.
	 */
	void releaseBuffer(uint32_t count);

	/**
	 * @brief Gets the pointer to the current receive buffer.
	 * 
	 * @return uint32_t* Pointer to the current buffer.
	 */
	uint32_t* getCurrentBuffer(void);

	// The following are internal functions and do not need to be called by the user application.
	struct setup_t
	{
		YSS_PDM_Peri *dev;
	};

	Pdm(const Drv::setup_t drvSetup, const Setup setup);

	void push(int32_t data);

	void isr(void);

private :
	YSS_PDM_Peri *mDev;
	uint32_t *mRcvBuf;
	int32_t  mRcvBufLen;
	int32_t  mTail, mHead, mLastCheckCount;
};

#endif

