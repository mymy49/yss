/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Pdm.h
 * @brief Pulse Density Modulation (PDM) driver class header file.
 *
 * @details
 * This driver provides an interface for receiving audio data from PDM
 * microphones (e.g. MEMS microphones) using the on-chip PDM interface
 * peripheral. The PDM hardware demodulates the 1-bit density-encoded
 * signal from the microphone and provides PCM audio samples via DMA
 * into a ring buffer managed by this driver.
 *
 * ### Supported Targets
 * - Silicon Labs EFM32PG22 → `PDM_TypeDef`
 *
 * On unsupported targets `YSS_DRV_PDM_UNSUPPORTED` is defined and the
 * class body is excluded from compilation.
 *
 * ### Initialization Flow
 * 1. Configure the PDM clock (CLK) and data (DATA) GPIO pins as alternative
 *    functions using `Gpio::setAsAltFunc()`.
 * 2. Supply clock to the peripheral using `enableClock()`.
 * 3. Call `initialize()` with a `Configuration` struct and either supply
 *    a pre-allocated receive buffer or specify only the buffer length to
 *    have the driver allocate the buffer from the heap.
 * 4. Call `start()` to begin PDM data reception.
 *
 * ### Initialization Example (heap-allocated buffer)
 * @code
 * Pdm::Configuration pdmConfig =
 * {
 *     0,       // ch0ClkPol    : Channel 0 normal clock polarity
 *     0,       // ch1ClkPol    : Channel 1 normal clock polarity
 *     1,       // stereoMode   : Stereo mode enabled
 *     4,       // fifoLevel    : FIFO level threshold
 *     0,       // dataFormat   : Signed integer PCM data
 *     2,       // numOfCh      : 2 channels (stereo)
 *     5,       // filterOrder  : CIC filter order
 *     0,       // delayMuxSel  : No data delay
 *     16000,   // sampleRate   : 16 kHz audio sample rate
 *     64       // downSampleRate: Decimation ratio
 * };
 *
 * pdm0.enableClock();
 * pdm0.initialize(pdmConfig, 256); // Allocate 256-word receive buffer from heap
 * pdm0.start();
 * @endcode
 *
 * ### Receiving Audio Data
 * - Call `getCount()` to check how many new audio samples are available.
 * - Call `getCurrentBuffer()` to get a pointer to the oldest valid samples.
 * - Process the samples.
 * - Call `releaseBuffer()` with the number of consumed samples to free the slots.
 */

#ifndef YSS_DRV_PDM__H_
#define YSS_DRV_PDM__H_

#include "peripheral.h" ///< Target-specific peripheral register definitions

#if defined(EFM32PG22)
typedef PDM_TypeDef			YSS_PDM_Peri; ///< Hardware PDM peripheral type for EFM32PG22
#else
typedef volatile uint32_t	YSS_PDM_Peri; ///< Dummy peripheral type for unsupported targets
#define YSS_DRV_PDM_UNSUPPORTED           ///< Defined when the target MCU does not support a PDM peripheral
typedef volatile uint32_t	YSS_PDM_Peri; ///< Duplicate typedef kept for compatibility
#endif

#include "Drv.h"       ///< Base driver class (clock, NVIC, reset management)
#include "Dma.h"       ///< DMA driver class (used for background data transfers)
#include <yss/error.h> ///< yss error code definitions

/**
 * @class Pdm
 * @brief Driver class for the PDM (Pulse Density Modulation) audio interface.
 *
 * @details
 * Manages the PDM peripheral to capture audio data from PDM microphones.
 * Internally uses DMA to transfer incoming PDM-decoded PCM samples into a
 * ring buffer, allowing the application to consume audio data asynchronously
 * without blocking the CPU during capture.
 *
 * The ring buffer is managed via head/tail pointers. `getCount()` and
 * `releaseBuffer()` must be called together: read the count, process
 * `getCurrentBuffer()` data, then release exactly that count.
 */
class Pdm : public Drv
{
public:
	/**
	 * @struct Configuration
	 * @brief Configuration parameters for the PDM interface initialization.
	 *
	 * @details
	 * All fields are hardware-specific values that depend on the MCU's PDM
	 * peripheral register definitions. Refer to the target device reference
	 * manual for valid enumeration values for each field.
	 */
	struct Configuration
	{
		uint8_t  ch0ClkPol;      ///< Channel 0 clock edge polarity (0 = falling edge, 1 = rising edge).
		uint8_t  ch1ClkPol;      ///< Channel 1 clock edge polarity (0 = falling edge, 1 = rising edge).
		uint8_t  stereoMode;     ///< Stereo/mono mode (0 = mono, 1 = stereo; actual values are hardware-dependent).
		uint8_t  fifoLevel;      ///< FIFO fill level threshold that triggers a DMA request.
		uint8_t  dataFormat;     ///< Output PCM data format (e.g. signed integer, unsigned; hardware-dependent).
		uint8_t  numOfCh;        ///< Number of active PDM channels (1 = mono, 2 = stereo).
		uint8_t  filterOrder;    ///< CIC decimation filter order (higher order = better noise rejection but more latency).
		uint8_t  delayMuxSel;    ///< Data delay multiplexer selection for multi-microphone alignment.
		uint32_t sampleRate;     ///< Target audio sample rate in Hz (e.g. 8000, 16000, 44100).
		uint8_t  downSampleRate; ///< PDM clock-to-output decimation ratio. Audio sample rate = PDM clock / downSampleRate.
	};

	/**
	 * @brief Initializes the PDM peripheral with an externally provided receive buffer.
	 *
	 * @details
	 * Configures the PDM hardware and DMA channel using the supplied
	 * configuration and pre-allocated receive buffer. Use this overload
	 * when buffer placement (e.g. in SRAM or DTCM) must be controlled
	 * by the application.
	 *
	 * @param[in] config               The PDM hardware configuration.
	 * @param[in] receiveBuffer        Pointer to the caller-allocated receive buffer.
	 * @param[in] receiveBufferLength  Number of 32-bit words in the receive buffer.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t initialize(Configuration config, uint32_t *receiveBuffer, int32_t receiveBufferLength);

	/**
	 * @brief Initializes the PDM peripheral with a heap-allocated receive buffer.
	 *
	 * @details
	 * Configures the PDM hardware and DMA channel using the supplied
	 * configuration, and dynamically allocates a receive buffer of the
	 * specified length from the system heap.
	 *
	 * @param[in] config               The PDM hardware configuration.
	 * @param[in] receiveBufferLength  Number of 32-bit words to allocate for the receive buffer.
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t initialize(Configuration config, int32_t receiveBufferLength);

	/**
	 * @brief Starts PDM data reception.
	 *
	 * @details
	 * Enables the PDM peripheral and the DMA channel, beginning continuous
	 * audio sample capture into the ring buffer.
	 */
	void start(void);

	/**
	 * @brief Stops PDM data reception.
	 *
	 * @details
	 * Disables the PDM peripheral and the DMA channel. Samples already
	 * captured in the ring buffer remain accessible.
	 */
	void stop(void);

	/**
	 * @brief Gets the number of newly received audio samples in the ring buffer.
	 *
	 * @details
	 * Returns the count of 32-bit PCM words currently stored in the ring
	 * buffer that have not yet been consumed by the application.
	 * Use this count to determine how many items to process before calling
	 * `releaseBuffer()`.
	 *
	 * @return uint32_t Number of unprocessed 32-bit audio samples available.
	 */
	uint32_t getCount(void);

	/**
	 * @brief Releases the specified number of consumed samples from the receive buffer.
	 *
	 * @details
	 * Advances the ring buffer's tail pointer by `count` positions, freeing
	 * those slots for new incoming PDM data. Must be called after processing
	 * the data obtained from `getCurrentBuffer()`.
	 * The `count` value should equal the value previously returned by `getCount()`.
	 *
	 * @param[in] count Number of 32-bit audio samples to release from the buffer.
	 */
	void releaseBuffer(uint32_t count);

	/**
	 * @brief Gets a pointer to the oldest unconsumed audio data in the receive buffer.
	 *
	 * @details
	 * Returns a pointer to the current tail of the ring buffer, pointing to
	 * the oldest available audio sample. The valid range is from index 0 to
	 * `getCount() - 1` from this pointer. After processing, call
	 * `releaseBuffer()` to free the consumed slots.
	 *
	 * @return uint32_t* Pointer to the oldest unprocessed audio sample in the ring buffer.
	 */
	uint32_t* getCurrentBuffer(void);

	// The following are internal functions and do not need to be called by the user application.

	/**
	 * @struct setup_t
	 * @brief Hardware setup configuration for the PDM driver.
	 */
	struct setup_t
	{
		YSS_PDM_Peri *dev; ///< Pointer to the hardware PDM peripheral register block.
	};

	/**
	 * @brief Constructor for the Pdm class.
	 *
	 * @param[in] drvSetup Base driver setup configuration (clock, NVIC function pointers).
	 * @param[in] Setup    PDM-specific hardware setup (pointer to the PDM peripheral).
	 */
	Pdm(const Drv::setup_t drvSetup, const Setup setup);

	/**
	 * @brief Internal function: pushes a single decoded PDM sample into the ring buffer.
	 *
	 * @details This function is called from the DMA interrupt service routine.
	 *          Do NOT call this function from user application code.
	 *
	 * @param[in] data The decoded 32-bit PCM audio sample to push into the buffer.
	 */
	void push(int32_t data);

	/**
	 * @brief Interrupt service routine handler for the PDM peripheral.
	 *
	 * @details Called by the hardware ISR vector. Do NOT call this function
	 *          from user application code.
	 */
	void isr(void);

private :
	YSS_PDM_Peri *mDev;       ///< Pointer to the hardware PDM peripheral register block.
	uint32_t *mRcvBuf;         ///< Pointer to the receive ring buffer.
	int32_t  mRcvBufLen;       ///< Length of the receive ring buffer in 32-bit words.
	int32_t  mTail;            ///< Ring buffer consumer (tail) index.
	int32_t  mHead;            ///< Ring buffer producer (head) index.
	int32_t  mLastCheckCount;  ///< Snapshot of head at the time of the last `getCount()` call.
};

#endif

