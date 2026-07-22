/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/Timer.h>

/**
 * @file drv_Timer.cpp
 * @brief Generic Timer driver source file.
 */

Timer::Timer(const Drv::setup_t drvSetup) : Drv(drvSetup)
{
	// Initialize update interrupt handler callback to null.
	mIsrUpdate = nullptr;
}

void Timer::setIsrForUpdate(void (*isr)(void))
{
	// Register user-defined callback for timer update interrupts.
	mIsrUpdate = isr;
}

void Timer::isrUpdate(void)
{
	// Trigger the registered update callback if present.
	if (mIsrUpdate)
		mIsrUpdate();
}


