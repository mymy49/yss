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

#include <drv/peripheral.h>

#if defined(STM32F7)

#include <drv/Flash.h>
#include <drv/flash/register_flash_stm32f7.h>
#include <yss/thread.h>

Flash::Flash(void) : Drv(0, 0)
{
}

void Flash::setPrefetchEn(bool en)
{
	if (en)
		FLASH->ACR |= FLASH_ACR_PRFTEN_Msk;
	else
		FLASH->ACR &= ~FLASH_ACR_PRFTEN_Msk;
}

void Flash::setArtEn(bool en)
{
	if (en)
		FLASH->ACR |= FLASH_ACR_ARTEN_Msk;
	else
		FLASH->ACR &= ~FLASH_ACR_ARTEN_Msk;
}

static const uint32_t gFlashAddrTable[8] =
	{
		0x08000000, 0x08008000, 0x08010000, 0x08018000, 0x08020000,
		0x08040000, 0x08080000, 0x080C0000};

uint32_t Flash::getAddress(uint16_t sector)
{
	return gFlashAddrTable[sector];
}

void Flash::erase(uint16_t sector)
{
	while (getFlashBusy())
		;

	if (getFlashLock())
	{
		setFlashKey(0x45670123);
		setFlashKey(0xcdef89ab);
	}

	while (getFlashLock())
		;

	setFlashSectorErase(true);
	setFlashSectorNumber(sector);
	setFlashEraseStart();

	__NOP();
	__NOP();
	while (getFlashBusy())
		;

	setFlashSectorErase(false);
	setFlashLock();
}

void *Flash::program(void *des, void *src, uint32_t size)
{
	uint32_t *cdes = (uint32_t *)des, *csrc = (uint32_t *)src;

	size += 3;
	size >>= 2;

	while (getFlashBusy())
		thread::yield();

	if (getFlashLock())
	{
		setFlashKey(0x45670123);
		setFlashKey(0xcdef89ab);
	}

	while (getFlashLock())
		thread::yield();

	setFlashProgramSize(2);
	setFlashProgramming(true);

	for (uint32_t i = 0; i < size; i++)
	{
		__NOP();
		__NOP();
		cdes[i] = csrc[i];
		thread::yield();
		while (getFlashBusy())
			;
	}

	setFlashProgramming(false);
	setFlashLock();

	return (void *)cdes;
}

void *Flash::program(uint32_t sector, void *src, uint32_t size)
{
	return program((void *)getAddress(sector), src, size);
}

#endif

