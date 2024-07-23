/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>

#if defined(STM32F0) || defined(STM32F7) || defined(STM32G4)

#include <drv/peripheral.h>
#include <drv/Usart.h>
#include <yss/reg.h>
#include <yss/thread.h>
#include <targets/st/bitfield.h>

Usart::Usart(const Drv::setup_t drvSetup, const Uart::setup_t setup) : Uart(drvSetup, setup)
{

}

void Usart::enableSck(bool en)
{
	bool ue = getBitData(mDev->CR1, USART_CR1_UE_Pos);

	if(ue)
	{
		setBitData(mDev->CR1, false, USART_CR1_UE_Pos);
	}
	
	if(en)
		mDev->CR2 |= USART_CR2_CLKEN_Msk | USART_CR2_LBCL_Msk;
	else
		mDev->CR2 &= ~(USART_CR2_CLKEN_Msk | USART_CR2_LBCL_Msk);

	if(ue)
	{
		setBitData(mDev->CR1, true, USART_CR1_UE_Pos);
	}
}

#endif

