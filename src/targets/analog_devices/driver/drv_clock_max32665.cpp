/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__MAX32665_FAMILY)

#include <targets/analog_devices/Max32665Clock.h>
#include <yss/reg.h>
#include <util/runtime.h>
#include <yss/scheduler.h>

error_t Clock::enableHirc8m(bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();

	if(en)
	{
		MXC_GCR->clkcn |= MXC_F_GCR_CLKCN_HIRC8M_EN;
		while ((MXC_GCR->clkcn & MXC_F_GCR_CLKCN_HIRC8M_RDY) == 0);
	}
	else
		MXC_GCR->clkcn &= ~MXC_F_GCR_CLKCN_HIRC8M_EN;
	
	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

error_t Clock::enableHirc96m(bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();
	if(en)
	{
		MXC_GCR->clkcn |= MXC_F_GCR_CLKCN_HIRC96M_EN;
		while ((MXC_GCR->clkcn & MXC_F_GCR_CLKCN_HIRC96M_RDY) == 0);
	}
	else
		MXC_GCR->clkcn &= ~MXC_F_GCR_CLKCN_HIRC96M_EN;

	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

error_t Clock::setHclkClockSource(hclkSrc_t src, uint8_t hclkDiv)
{
	int32_t clk;
	error_t result = error_t::ERROR_NONE;

	semaphore::lockPeripherals();
	__disable_irq();

	if(hclkDiv > 7)
	{
		result = error_t::WRONG_CONFIG;
		goto error_handler;
	}

	switch(src)
	{
	case HCLK_SRC_HIRC :
		if(~MXC_GCR->clkcn & MXC_F_GCR_CLKCN_HIRC_RDY)
		{
			result = error_t::CLK_SRC_NOT_READY;
			goto error_handler;
		}
		clk = 60;
		break;

	//case HCLK_SRC_XTAL32M :
	//	if(~MXC_GCR->clkcn & MXC_F_GCR_CLKCN_X32M_RDY)
	//		return error_t::CLK_SRC_NOT_READY;
	//	clk = 32;
	//	break;
	
	//case HCLK_SRC_LIRC8 :
	//	if(~MXC_GCR->clkcn & MXC_F_GCR_CLKCN_LIRC8K_RDY)
	//		return error_t::CLK_SRC_NOT_READY;
	//	clk = 1;
	//	break;

	//case HCLK_SRC_HIRC8 :
	//	if(~MXC_GCR->clkcn & MXC_F_GCR_CLKCN_HIRC8M_RDY)
	//		return error_t::CLK_SRC_NOT_READY;
	//	clk = 8;
	//	break;

	case HCLK_SRC_HIRC96 :
		if(~MXC_GCR->clkcn & MXC_F_GCR_CLKCN_HIRC96M_RDY)
		{
			result = error_t::CLK_SRC_NOT_READY;
			goto error_handler;
		}
		clk = 96;
		break;
		
	//case  HCLK_SRC_XTAL32K :
	//	if(~MXC_GCR->clkcn & MXC_F_GCR_CLKCN_X32K_RDY)
	//		return error_t::CLK_SRC_NOT_READY;
	//	clk = 1;
	//	break;
	}

	clk /= 1 << hclkDiv;
	setFieldData(MXC_FLC0->clkdiv, MXC_F_FLC_CLKDIV_CLKDIV, clk, MXC_F_FLC_CLKDIV_CLKDIV_POS);
	setFieldData(MXC_GCR->clkcn, MXC_F_GCR_CLKCN_PSC, hclkDiv, MXC_F_GCR_CLKCN_PSC_POS);
	setFieldData(MXC_GCR->clkcn, MXC_F_GCR_CLKCN_CLKSEL, src, MXC_F_GCR_CLKCN_CLKSEL_POS);

error_handler :
	__enable_irq();
	semaphore::unlockPeripherals();


	return result;
}

uint32_t Clock::getHclkClockFrequency()
{
	int32_t clk;

	semaphore::lockPeripherals();
	__disable_irq();

	switch(getFieldData(MXC_GCR->clkcn, MXC_F_GCR_CLKCN_CLKSEL, MXC_F_GCR_CLKCN_CLKSEL_POS))
	{
	case HCLK_SRC_HIRC :
		clk = 60000000;
		break;

	//case HCLK_SRC_XTAL32M :
	//	clk = 32000000;
	//	break;
	
	//case HCLK_SRC_LIRC8 :
	//	clk = 8000;
	//	break;

	//case HCLK_SRC_HIRC8 :
	//	clk = 7372800;
	//	break;

	case HCLK_SRC_HIRC96 :
		clk = 96000000;
		break;
		
	//case  HCLK_SRC_XTAL32K :
	//	clk = 32768;
	//	break;
	}

	clk /= 1 << getFieldData(MXC_GCR->clkcn, MXC_F_GCR_CLKCN_PSC, MXC_F_GCR_CLKCN_PSC_POS);

	__enable_irq();
	semaphore::unlockPeripherals();

	return clk;
}

uint32_t Clock::getApbClockFrequency()
{
	return getHclkClockFrequency() / 2;
}

error_t Clock::enableCache0(bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();

	// Enable instruction cache 0 (ICC0) for the primary CPU (Core 0)
	MXC_ICC0->cache_ctrl |= MXC_F_ICC_CACHE_CTRL_CACHE_EN;
	// Execute Data Synchronization Barrier (DSB) and Instruction Synchronization Barrier (ISB)
	// to ensure all cache configuration changes take effect immediately.
	__asm volatile ("dsb \n isb");
	
	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

error_t Clock::enableCache1(bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();

	// Enable instruction cache 1 (ICC1) for the secondary CPU (Core 1 / CPU1)
	MXC_ICC1->cache_ctrl |= MXC_F_ICC_CACHE_CTRL_CACHE_EN;
	// Ensure memory instructions are synchronized and cache state is refreshed
	__asm volatile ("dsb \n isb");

	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

error_t Clock::enableCpu1(void *vtor, bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();

	// MAX32665 routes the initial VTOR of CPU1 through GCR GP0 register
	MXC_GCR->gp0 = (uint32_t)vtor;
	// Enable/disable CPU1 clock gate. (Low-active, so setting !en disables the clock)
	setBitData(MXC_GCR->perckcn1, !en, MXC_F_GCR_PERCKCN1_CPU1_POS);
		
	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

error_t Clock::enableCpu1(const void *vtor, bool en)
{
	return enableCpu1((void*)vtor, en);
}

error_t Clock::enableSemaphore(bool en)
{
	// Enable/disable hardware semaphore module clock. (Low-active)
	setBitData(MXC_GCR->perckcn1, !en, MXC_F_GCR_PERCKCN1_SMPHRD_POS);

	return error_t::ERROR_NONE;
}

error_t Clock::enableGpio0(bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();

	setBitData(MXC_GCR->perckcn0, !en, MXC_F_GCR_PERCKCN0_GPIO0D_POS);
	return error_t::ERROR_NONE;
}

error_t Clock::enableGpio1(bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();

	setBitData(MXC_GCR->perckcn0, !en, MXC_F_GCR_PERCKCN0_GPIO1D_POS);

	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

error_t Clock::enableTmr0(bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();

	setBitData(MXC_GCR->perckcn0, !en, MXC_F_GCR_PERCKCN0_T0D_POS);

	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

error_t Clock::enableTmr1(bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();

	setBitData(MXC_GCR->perckcn0, !en, MXC_F_GCR_PERCKCN0_T1D_POS);

	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

error_t Clock::enableTmr2(bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();

	setBitData(MXC_GCR->perckcn0, !en, MXC_F_GCR_PERCKCN0_T2D_POS);

	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

error_t Clock::enableTmr3(bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();

	setBitData(MXC_GCR->perckcn0, !en, MXC_F_GCR_PERCKCN0_T3D_POS);

	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

error_t Clock::enableTmr4(bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();

	setBitData(MXC_GCR->perckcn0, !en, MXC_F_GCR_PERCKCN0_T4D_POS);

	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

error_t Clock::enableTmr5(bool en)
{
	semaphore::lockPeripherals();
	__disable_irq();

	setBitData(MXC_GCR->perckcn0, !en, MXC_F_GCR_PERCKCN0_T5D_POS);

	__enable_irq();
	semaphore::unlockPeripherals();

	return error_t::ERROR_NONE;
}

#endif

