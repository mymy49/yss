/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV__H_
#define YSS_DRV__H_

#include <yss/Mutex.h>
#include <drv/mcu.h>

class Dma;

/**
 * @file Drv.h
 * @brief Base driver class header file.
 */

/**
 * @class Drv
 * @brief Base class for all peripheral drivers.
 * 
 * @details
 * This class inherits from `Mutex` to provide thread synchronization mechanisms (locking/unlocking) 
 * for derived drivers. It defines standard methods for peripheral clock gating, interrupt enabling, 
 * peripheral resetting, and retrieving operating frequencies.
 */
class Drv : public Mutex
{
  public:
	/**
	 * @struct setup_t
	 * @brief Hardware setup configuration structure for driver initialization.
	 * @details This structure replaces the legacy Config structure design.
	 */
	struct setup_t
	{
		void (*clockFunc)(bool en);        ///< Function pointer to enable or disable the peripheral clock.
		void (*nvicFunc)(bool en);         ///< Function pointer to enable or disable the NVIC interrupt.
		void (*resetFunc)(void);           ///< Function pointer to reset the peripheral hardware.
		uint32_t (*getClockFunc)(void);    ///< Function pointer to retrieve the current clock frequency.
	};

	/**
	 * @brief Enables or disables the clock of the peripheral.
	 * 
	 * @param[in] en True to enable the clock, false to disable.
	 */
	void enableClock(bool en = true);

	/**
	 * @brief Enables or disables the interrupt of the peripheral in NVIC.
	 * 
	 * @param[in] en True to enable the interrupt, false to disable.
	 */
	void enableInterrupt(bool en = true);

	/**
	 * @brief Resets the peripheral hardware.
	 */
	void reset(void);

	/**
	 * @brief Gets the current operating clock frequency of the peripheral.
	 * 
	 * @return uint32_t The clock frequency in Hz.
	 */
	uint32_t getClockFrequency(void);

#if defined(YSS__UART_RX_DMA)
	/**
	 * @brief Gets the DMA channel currently occupied by this driver.
	 * 
	 * @return Dma* Pointer to the occupied DMA channel instance.
	 */
	Dma* getOccupancyDma(void);

	/**
	 * @brief Gets the idle DMA channel associated with this driver.
	 * 
	 * @return Dma* Pointer to the idle DMA channel instance.
	 */
	Dma* getIdleDma(void);
#endif
	
	// The following functions are system functions and must not be called by the user application.
	
	/**
	 * @brief Constructor for Drv using individual function pointers.
	 */
	Drv(void (*clockFunc)(bool en), void (*nvicFunc)(bool en), void (*resetFunc)(void) = 0);

	/**
	 * @brief Constructor for Drv using a setup_t configuration structure.
	 */
	Drv(const setup_t &setup);

	/**
	 * @brief Default constructor for Drv.
	 */
	Drv(void);

private :
	void (*mClockFunc)(bool en);     ///< Function pointer to control peripheral clock.
	void (*mNvicFunc)(bool en);      ///< Function pointer to control NVIC interrupts.
	void (*mResetFunc)(void);        ///< Function pointer to reset peripheral.
	uint32_t (*mGetClockFunc)(void); ///< Function pointer to retrieve peripheral clock frequency.
};

#endif

