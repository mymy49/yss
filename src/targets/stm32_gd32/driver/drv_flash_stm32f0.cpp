////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/mcu.h>

#if defined(STM32F0)

#include <drv/peripheral.h>
#include <drv/Flash.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/flash_stm32f0.h>

Flash::Flash(void) : Drv(0, 0)
{
}

void Flash::setLatency(uint32_t freq)
{
	volatile uint32_t* peri = (volatile uint32_t*)FLASH;

	if (freq <= 24000000)
		setFieldData(peri[FLASH_REG::ACR], FLASH_ACR_LATENCY_Msk, 0, FLASH_ACR_LATENCY_Pos);
	else
		setFieldData(peri[FLASH_REG::ACR], FLASH_ACR_LATENCY_Msk, 1, FLASH_ACR_LATENCY_Pos);
}

void Flash::setPrefetchEn(bool en)
{
	volatile uint32_t* peri = (volatile uint32_t*)FLASH;
	setBitData(peri[FLASH_REG::ACR], FLASH_ACR_PRFTBE_Pos, en);
}

void Flash::setHalfCycleAccessEn(bool en)
{
	volatile uint32_t* peri = (volatile uint32_t*)FLASH;
	setBitData(peri[FLASH_REG::ACR], FLASH_ACR_HLFCYA_Pos, en);
}
#endif

