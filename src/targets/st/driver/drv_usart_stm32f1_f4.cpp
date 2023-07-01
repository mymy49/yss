////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F4_N) || defined (STM32F1_N)

#include <drv/peripheral.h>
#include <drv/Usart.h>
#include <yss/thread.h>
#include <yss/reg.h>

#if defined(STM32F446xx)
#include <targets/st/bitfield_stm32f446xx.h>
#elif defined(STM32F429xx)
#include <targets/st/bitfield_stm32f429xx.h>
#elif defined(STM32F103xB) || defined(STM32F103xE)
#include <targets/st/bitfield_stm32f103xx.h>
#endif

Usart::Usart(const Drv::Setup drvSetup, const Uart::Setup setup) : Uart(drvSetup, setup)
{

}

void Usart::enableSck(bool en)
{
	bool ue = getBitData(mDev->CR1, USART_CR1_UE_Pos);

	if(ue)
		setBitData(mDev->CR1, false, USART_CR1_UE_Pos);

	mDev->CR2 = USART_CR2_CLKEN_Msk | USART_CR2_LBCL_Msk;

	if(ue)
		setBitData(mDev->CR1, true, USART_CR1_UE_Pos);
}

#endif

