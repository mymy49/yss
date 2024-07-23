/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <drv/peripheral.h>
#include <drv/Clock.h>

bool Clock::enableHse(uint32_t, bool)
{
	NRF_CLOCK->TASKS_HFCLKSTART = 1;

	for (uint32_t i = 0; i < 1000000; i++)
	{
		if (NRF_CLOCK->EVENTS_HFCLKSTARTED)
			return true;
	}

	return false;
}

uint32_t Clock::getSystemClockFrequency(void)
{
	return 64000000;
}

uint32_t Clock::getCoreClockFrequency(void)
{
	return 64000000;
}

uint32_t Clock::getAhbClockFrequency(void)
{
	return 64000000;
}

uint32_t Clock::getApb1ClockFrequency(void)
{
	return 64000000;
}

uint32_t Clock::getApb2ClockFrequency(void)
{
	return 64000000;
}

/*
int32_t  Clock::getSysClkFreq(void)
{
	return 60000000;
}
*/
/*
uint32_t Clock::getApb1ClkFreq(void)
{
	return getSysClkFreq() / gPpreDiv[getFieldData(RCC->GCFGR, 0x7 << 8, 8)];
} 

uint32_t Clock::getApb2ClkFreq(void)
{
	return getSysClkFreq() / gPpreDiv[getFieldData(RCC->GCFGR, 0x7 << 11, 11)];
}

uint32_t Clock::getTimerApb1ClkFreq(void)
{
	uint8_t pre = getFieldData(RCC->GCFGR, 0x7 << 8, 8);
	uint32_t clk = getSysClkFreq() / gPpreDiv[pre];
	if (gPpreDiv[pre] > 1)
		clk <<= 1;
	return clk;
}

uint32_t Clock::getTimerApb2ClkFreq(void)
{
	uint8_t pre = getFieldData(RCC->GCFGR, 0x7 << 11, 11);
	uint32_t clk = getSysClkFreq() / gPpreDiv[pre];
	if (gPpreDiv[pre] > 1)
		clk <<= 1;
	return clk;
}

void Clock::setLatency(uint32_t freq, uint8_t vcc)
{
	//if (freq < 24000000)
	//	FLASH->ACR &= ~FLASH_ACR_LATENCY_Msk;
	//else if (freq < 48000000)
	//{
	//	reg = FLASH->ACR;
	//	reg = (reg & ~FLASH_ACR_LATENCY_Msk) | (1 << FLASH_ACR_LATENCY_Pos);
	//	FLASH->ACR = reg;
	//}
	//else
	//{
	//	reg = FLASH->ACR;
	//	reg = (reg & ~FLASH_ACR_LATENCY_Msk) | (2 << FLASH_ACR_LATENCY_Pos);
	//	FLASH->ACR = reg;
	//}
}
*/

#endif