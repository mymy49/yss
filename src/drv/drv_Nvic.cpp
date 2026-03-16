/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/Nvic.h>

#if !defined(ERROR_MCU_NOT_ABLE)

Nvic::Nvic(void) : Drv(0, 0)
{
}

void Nvic::enableInterrupt(IRQn_Type position, bool en)
{
	__disable_irq();	
	if(en)
		NVIC_EnableIRQ(position);
	else
		NVIC_DisableIRQ(position);
	__enable_irq();
}

#endif

