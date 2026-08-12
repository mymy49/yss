/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_CAPTURE__H_
#define YSS_DRV_CAPTURE__H_

#include "peripheral.h"

#if defined(STM32F7) || defined(GD32F1) || defined(STM32F1) || defined(STM32F4) 

typedef TIM_TypeDef			YSS_CAPTURE_Peri;

#else

#define YSS_DRV_CAPTURE_UNSUPPORTED
typedef volatile uint32_t	YSS_CAPTURE_Peri;

#endif

#include "Drv.h"

/**
 * @file Capture.h
 * @brief Input Capture driver class header file.
 * 
 * ### Initialization Flow
 * 1. Configure the GPIO pins related to the Capture device as alternative function pins using the `setAsAltFunc()` function.
 * 2. Supply clock to the device using the `enableClock()` function.
 * 3. Initialize the prescaler and detection edge settings using the `initialize()` function.
 * 4. Register the interrupt service routine callback using the `setIsr()` function.
 * 5. Start the timer counter using the `start()` function.
 * 6. Enable the peripheral interrupts using the `enableInterrupt()` function.
 * 
 * ### Usage
 * - The ISR callback registered through `setIsr()` is called whenever the configured edge is detected on the Capture pin.
 * - The parameter `cnt` represents the elapsed count since the previous detection.
 *   This delta value can be directly used for period or pulse-width calculations.
 * - The parameter `accCnt` represents the total accumulated count since the driver started.
 */

/**
 * @class Capture
 * @brief Driver class for Input Capture peripherals.
 * 
 * @details
 * This driver measures the time interval between edges of an input waveform.
 * If the MCU's basic timer includes an Input Capture function, this class allows managing 
 * it as a separate device. If the Input Capture hardware is independent of the basic timer, 
 * this driver serves as the device driver.
 * 
 * For example, on STM32, basic timers (TIM1 ~ TIM14) are shared with Input Capture.
 */
class Capture : public Drv
{
public:
	/**
	 * @brief Enumeration for detection edge configuration.
	 */
	typedef enum
	{
		EDGE_RISING = 0, ///< Detect rising edges
		EDGE_FALLING     ///< Detect falling edges
	}edge_t;
	
	/**
	 * @brief Initializes the Capture device.
	 * @details Configures the prescaler for the source frequency and the target edge to detect.
	 * 
	 * @param[in] psc Prescaler value for the source frequency.
	 * @param[in] option The edge to detect (RISING or FALLING).
	 */
	void initialize(uint32_t psc, edge_t option = EDGE_RISING);
	
	/**
	 * @brief Starts the capture operation.
	 */
	void start(void);

	/**
	 * @brief Stops the capture operation.
	 */
	void stop(void);
	
	/**
	 * @brief Registers the Interrupt Service Routine (ISR) callback.
	 * @details The registered ISR is called every time a configured edge is detected.
	 * 
	 * @warning Calling any function that triggers a context switch within the ISR callback is strictly prohibited.
	 *          Please refer to the `yss.h` file for details on functions that cause context switches, 
	 *          and the distinction between ISR callbacks and regular callback functions.
	 * 
	 * @param[in] isr Pointer to the ISR callback function.
	 *                - `cnt`: The count incremented since the last detected edge.
	 *                - `accCnt`: The accumulated total counter value.
	 */
	virtual void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt)) = 0;

	// The following functions are system functions and must not be called by the user application.

	/**
	 * @brief Internal handler called from the hardware timer update (overflow) ISR.
	 * @details Increments the overflow counter (`mUpdateCnt`) to extend the 16/32-bit
	 *          counter range and maintain accurate long-term accumulated counts.
	 *          Do NOT call this function from user application code.
	 */
	void isrUpdate(void);

	/**
	 * @brief Internal handler for input capture events with explicit CCR and update flag.
	 * @details Dispatches the capture event to the registered ISR callback, computing
	 *          the delta count since the last capture and the accumulated total count.
	 *          Do NOT call this function from user application code.
	 *
	 * @param[in] ccr    The Capture Compare Register (CCR) value latched at the capture event.
	 * @param[in] update True if an overflow (update) event occurred simultaneously with the capture.
	 */
	void isrCapture(int32_t ccr, bool update);

	/**
	 * @brief Gets the source clock frequency for the capture timer.
	 * @details Returns the current peripheral clock frequency driving the capture timer
	 *          after prescaler division. Used internally by channel subclasses to
	 *          calculate capture timing.
	 *
	 * @return uint32_t Timer source frequency in Hz after prescaler division.
	 */
	uint32_t getSourceFrequency(void);

	/**
	 * @brief Target-specific internal handler for raw capture events.
	 * @details Must be overridden by CaptureCh1~4 subclasses to handle the
	 *          hardware-specific CCR register read for the corresponding channel.
	 *          Do NOT call this function from user application code.
	 *
	 * @param[in] update True if an overflow (update) event occurred simultaneously with the capture.
	 */
	virtual void isrCapture(bool update) = 0;

	/**
	 * @struct setup_t
	 * @brief Hardware setup configuration structure for the Capture driver.
	 */
	typedef struct
	{
		YSS_CAPTURE_Peri *peri;   ///< Pointer to the hardware peripheral instance.
		uint64_t *updateCnt;      ///< Pointer to the update counter memory.
	}setup_t;

	/**
	 * @brief Constructor for the Capture class.
	 * 
	 * @param[in] drvSetup The base driver setup configuration.
	 * @param[in] setup The capture-specific hardware setup configuration.
	 */
	Capture(const Drv::setup_t &drvSetup, const setup_t &setup);

protected:
	YSS_CAPTURE_Peri *mPeri;                     ///< Pointer to the hardware peripheral instance.
	void (*mIsr)(uint32_t cnt, uint64_t accCnt);  ///< Pointer to the registered ISR callback function.
	uint64_t *mUpdateCnt;                        ///< Pointer to the accumulated overflow update counter.
	uint64_t mLastUpdateCnt;                     ///< Saved update counter value from the previous capture event.
	uint32_t mLastCcr;                           ///< Captured Counter Register (CCR) value from the previous capture event.

	/**
	 * @brief Initializes the hardware channel.
	 * 
	 * @param[in] option Channel-specific initialization option (e.g. edge selection).
	 */
	virtual void initializeChannel(uint8_t option) = 0;
};

/**
 * @class CaptureCh1
 * @brief Input Capture Channel 1 driver class.
 *
 * @details
 * Represents the Channel 1 input capture resource of a shared timer peripheral.
 * Monitors the CH1 input pin and triggers the registered ISR callback each time
 * the configured edge is detected. The `cnt` parameter in the callback gives the
 * timer count elapsed since the previous capture event, enabling pulse-width
 * or period measurement with hardware precision.
 */
class CaptureCh1 : public Capture
{
public:
	CaptureCh1(const Drv::setup_t &drvSetup, const Capture::setup_t &setup);
	
	void isrCapture(bool update);

	void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt));

protected :
  	virtual void initializeChannel(uint8_t option);
};

/**
 * @class CaptureCh2
 * @brief Input Capture Channel 2 driver class.
 *
 * @details
 * Represents the Channel 2 input capture resource of a shared timer peripheral.
 * Monitors the CH2 input pin and triggers the registered ISR callback each time
 * the configured edge is detected. Shares the same timer counter and prescaler
 * with other channels on the same timer instance.
 */
class CaptureCh2 : public Capture
{
  public:
	CaptureCh2(const Drv::setup_t &drvSetup, const Capture::setup_t &setup);
	
	void isrCapture(bool update);

	void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt));

protected :
  	virtual void initializeChannel(uint8_t option);
};

/**
 * @class CaptureCh3
 * @brief Input Capture Channel 3 driver class.
 *
 * @details
 * Represents the Channel 3 input capture resource of a shared timer peripheral.
 * Monitors the CH3 input pin and triggers the registered ISR callback each time
 * the configured edge is detected. Shares the same timer counter and prescaler
 * with other channels on the same timer instance.
 */
class CaptureCh3 : public Capture
{
  public:
	CaptureCh3(const Drv::setup_t &drvSetup, const Capture::setup_t &setup);
	
	void isrCapture(bool update);

	void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt));

protected :
  	virtual void initializeChannel(uint8_t option);
};

/**
 * @class CaptureCh4
 * @brief Input Capture Channel 4 driver class.
 *
 * @details
 * Represents the Channel 4 input capture resource of a shared timer peripheral.
 * Monitors the CH4 input pin and triggers the registered ISR callback each time
 * the configured edge is detected. Shares the same timer counter and prescaler
 * with other channels on the same timer instance.
 */
class CaptureCh4 : public Capture
{
  public:
	CaptureCh4(const Drv::setup_t &drvSetup, const Capture::setup_t &setup);
	
	void isrCapture(bool update);

	void setIsr(void (*isr)(uint32_t cnt, uint64_t accCnt));

protected :
  	virtual void initializeChannel(uint8_t option);
};

#endif
