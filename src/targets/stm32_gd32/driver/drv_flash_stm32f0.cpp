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

uint32_t Flash::getAddress(uint16_t sector)
{
	uint32_t max, size;
#if defined(STM32F030xC)
	max = *(uint16_t *)FLASHSIZE_BASE;
	size = 2048;
#else
	max = *(uint16_t *)FLASHSIZE_BASE;
	size = 1024;
#endif

	if (sector > max)
		sector = max;

	return 0x08000000 + (uint32_t)sector * size;
}

void Flash::erase(uint16_t sector)
{
	uint32_t addr = getAddress(sector);

	while (getBitData(FLASH[FLASH_REG::SR], 0))
		thread::yield();

	if (sector < 256)
	{
		if (getRegBit(FLASH[FLASH_REG::CR], 7))	// Flash가 잠겼는지 확인
		{
			// Flash Unlock
			FLASH[FLASH_REG::KEYR] = 0x45670123;
			FLASH[FLASH_REG::KEYR] = 0xCDEF89AB;
		}
		
		// Unlock이 될때까지 대기
		while (getRegBit(FLASH[FLASH_REG::CR], 7))
			thread::yield();
		
		// 지우기
		setBitData(FLASH[FLASH_REG::CR], true, 1);
		FLASH[FLASH_REG::AR] = addr;
		setBitData(FLASH[FLASH_REG::CR], true, 6);

		__NOP();
		__NOP();
		while (getBitData(FLASH[FLASH_REG::SR], 0))
			;

		__NOP();
		__NOP();
		setBitData(FLASH[FLASH_REG::CR], false, 1);	// 지우기 해제
		setBitData(FLASH[FLASH_REG::CR], false, 7);	// 잠금
	}
}

void *Flash::program(void *des, void *src, uint32_t size)
{
	volatile uint32_t* peri = (volatile uint32_t*)FLASH;
	uint16_t *addr = (uint16_t *)des;

	size += 1;
	size >>= 1;

	while (getBitData(peri[FLASH_REG::SR], 0))
		thread::yield();

	if ((int32_t )des < 0x08080000)
	{
		if (getRegBit(peri[FLASH_REG::CR], 7))	// Flash가 잠겼는지 확인
		{
			// Flash Unlock
			peri[FLASH_REG::KEYR] = 0x45670123;
			peri[FLASH_REG::KEYR] = 0xCDEF89AB;
		}

		// Unlock이 될때까지 대기
		while (getRegBit(peri[FLASH_REG::CR], 7))
			thread::yield();

		setBitData(peri[FLASH_REG::CR], true, 0);	// 쓰기 설정

		__NOP();
		__NOP();
		for (uint32_t i = 0; i < size; i++)
		{
			addr[i] = ((uint16_t *)src)[i];
			__NOP();
			__NOP();
			while (getBitData(peri[FLASH_REG::SR], 0))
				;
		}

		__NOP();
		__NOP();
		setBitData(peri[FLASH_REG::CR], false, 0);	// 쓰기 해제
		setBitData(peri[FLASH_REG::CR], false, 7);	// 잠금
	}

	return &addr[size];
}

void *Flash::program(uint32_t sector, void *src, uint32_t size)
{
	uint16_t *addr = (uint16_t*)getAddress(sector);

	return program((void*)getAddress(sector), src, size);
}

#endif


