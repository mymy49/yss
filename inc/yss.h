/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SYSTEM__H_
#define YSS_SYSTEM__H_

#include "yss/instance.h"
#include "yss/scheduler.h"
#include "yss/scheduler.h"
#include "yss/Trigger.h"
#include <yss/hmalloc.h>
#include "drv/mcu.h"
#include <config.h>

#define YSS_VERSION		2404

/**
 * @file yss.h
 * @brief Core system initialization and helper functions for Yss OS.
 *
 * ### Context-Switching Functions
 * 1. `thread::yield()` triggers a context switch.
 * 2. Peripheral data transmission functions (SPI, I2C, I2S, etc.) call `thread::yield()` during idle wait periods.
 * 3. `Mutex::lock()` and `Mutex::unlock()` call `thread::yield()` during idle wait periods.
 * 4. Other system API functions that periodically call `thread::yield()` during internal processing.
 *
 * ### ISR (Interrupt Service Routine) vs. Callback
 * 1. **ISR**:
 *    - Called directly by the hardware interrupt vector table.
 *    - **CRITICAL**: Do NOT call any functions that trigger a context switch (such as mutex locks, delays, or blocking transfers) inside an ISR.
 *    - Executes using the Main Stack Pointer (MSP). Keep local variable allocations minimal to prevent stack overflow.
 * 2. **Callback**:
 *    - Called at the normal thread execution level when events occur.
 *    - Functions that trigger a context switch can be safely called inside callbacks.
 *    - Executes using the active thread's stack (Process Stack Pointer - PSP). Ensure local variables do not exceed the thread's allocated stack size.
 */

class TftLcdDriver;
class Dma;
class Size;
class Position;
class Area;
class PointerDevice;

/**
 * @brief Initializes and activates Yss OS scheduler, mutexes, DMA, and external interrupts.
 */
void initializeYss(void);

namespace system 
{
	/**
	 * @brief Registers the TFT LCD driver instance used in the project.
	 *
	 * @param[in] lcd Reference to the TFT LCD driver instance.
	 */
	void setSystemTftLcd(TftLcdDriver &lcd);

	/**
	 * @brief Gets the resolution size of the registered system TFT LCD.
	 *
	 * @return Size The size (width, height) of the TFT LCD screen.
	 */
	Size getSystemTftLcdSize(void);

#if USE_GUI
	/**
	 * @brief Gets a pointer to the registered system TFT LCD driver.
	 *
	 * @return TftLcdDriver* Pointer to the registered TFT LCD driver, or nullptr if none is registered.
	 */
	TftLcdDriver* getSystemTftLcd(void);

	/**
	 * @brief Draws a bitmap image onto a GUI Frame.
	 *
	 * @param[in] obj Pointer to the destination Frame.
	 * @param[in] pos The position coordinate where the bitmap will be drawn.
	 * @param[in] bitmap The bitmap graphics data.
	 */
	void drawBitmap(Frame *obj, Position pos, const bitmap_t bitmap);

	/**
	 * @brief Draws a cropped portion of a bitmap onto a GUI Frame.
	 *
	 * @param[in] obj Pointer to the destination Frame.
	 * @param[in] rect The rectangular area on the frame where the bitmap will be drawn.
	 * @param[in] bitmapPos The starting coordinate offset within the source bitmap.
	 * @param[in] bitmap The bitmap graphics data.
	 */
	void drawBitmap(Frame *obj, Rectangular rect, Position bitmapPos, const bitmap_t bitmap);

	/**
	 * @brief Sets the system's root window Frame.
	 *
	 * @param[in] obj Pointer to the main system Frame.
	 */
	void setSystemFrame(Frame *obj);

	/**
	 * @brief Sets the pointing input device (e.g. touchscreen, mouse) for the system.
	 *
	 * @param[in] obj Pointer to the PointerDevice instance.
	 */
	void setSystemPointerDevice(PointerDevice *obj);

	/**
	 * @brief Sets the pointing input device (e.g. touchscreen, mouse) for the system.
	 *
	 * @param[in] obj Reference to the PointerDevice instance.
	 */
	void setSystemPointerDevice(PointerDevice &obj);
#endif

#if defined(YSS__DMA_ALLOCATION)
	/**
	 * @brief Allocates a DMA channel for exclusive hardware driver occupancy.
	 *
	 * @details
	 * Once allocated, the channel remains occupied by the driver. No deallocation API is provided
	 * as channels are intended to be permanently owned by initialized hardware instances.
	 *
	 * @return Dma* Pointer to the allocated DMA instance, or nullptr if no channel is available.
	 */
	Dma *allocateDma(void);
#endif
}

#if defined(DMA2D) && USE_EVENT == true
/**
 * @brief Propagates a pointer event to the GUI engine.
 *
 * @param[in] pos Coordinate of the event.
 * @param[in] event Event code (e.g. push, drag, release).
 */
void setEvent(Position_t pos, uint8_t event);
#endif

#if USE_GUI == true && YSS_L_HEAP_USE == true
/**
 * @brief Sets the active focus GUI Frame in the local heap.
 *
 * @param[in] obj Pointer to the Frame to activate.
 */
void setActiveFrame(Frame *obj);

/**
 * @brief Clears the active focus GUI Frame.
 */
void clearActiveFrame(void);
#endif

#endif
