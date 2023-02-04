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

#if defined(STM32L1)

#include <drv/peripheral.h>
#include <drv/Flash.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st_gigadevice/flash_stm32l1.h>
#include <targets/st_gigadevice/pwr_stm32l1.h>

Flash::Flash(void) : Drv(0, 0)
{
}

void Flash::set64bitAccess(bool en)
{
	setBitData(FLASH[FLASH_REG::ACR], en, FLASH_ACR_ACC64_Pos);
}

uint8_t Flash::getVoltageScale(void)
{
	return getFieldData(PWR[PWR_REG::CR], PWR_CR_VOS_Msk, PWR_CR_VOS_Pos);
}

void Flash::setLatency(uint32_t freq)
{
	switch(getVoltageScale())
	{
	case 1 : // RANGE1
		setBitData(FLASH[FLASH_REG::ACR], freq > 16000000, FLASH_ACR_LATENCY_Pos);
		break;
	case 2 : // RANGE2
		setBitData(FLASH[FLASH_REG::ACR], freq > 8000000, FLASH_ACR_LATENCY_Pos);
		break;
	case 3 : // RANGE3
#if defined(STM32L1XX_CAT5)
		setBitData(FLASH[FLASH_REG::ACR], freq > 4200000, FLASH_ACR_LATENCY_Pos);
#elif 
		setBitData(FLASH[FLASH_REG::ACR], freq > 2100000, FLASH_ACR_LATENCY_Pos);
#endif
		break;
	}
}

#endif

