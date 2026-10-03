/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/Nvic.h>

#if defined(YSS__CORE_CM3_CM4_CM7_H_GENERIC)

/**
 * @file drv_Nvic.cpp
 * @brief Generic NVIC (Nested Vectored Interrupt Controller) driver source file.
 */

Nvic::Nvic(void) : Drv(0, 0)
{
}

void Nvic::enableInterrupt(IRQn_Type position, bool en)
{
	// Disables interrupts globally to perform atomic NVIC state change.
	__disable_irq();	
	if(en)
		enableInterrupt(position);
	else
		disableInterrupt(position);
	__enable_irq();
}

#endif

