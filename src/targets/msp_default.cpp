/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <yss.h>

void initializeSystem(void);
void initializeSdram(void);

void initializeLheap(void);
void initializeCheap(void);

extern "C"
{
#if defined(CPU_MIMXRT1011DAE5A)
	void SystemInitHook(void)
#else
	void SystemInit(void)
#endif
	{
		// Initializes the system clock and external memory.
		// The initializeSystem() function is defined for each MCU.
#if !defined(__MCU_SMALL_SRAM_NO_SCHEDULE) && !defined(ERROR_MCU_NOT_ABLE)
		initializeSystem();
#endif

#if YSS_L_HEAP_USE == true
		// Calling a user-defined SDRAM configuration function
		initializeSdram();

		// Initialization of memory management variables in the SDRAM Heap area
		initializeLheap();
#endif
#if YSS_C_HEAP_USE == true
		// Initialization of memory management variables in the Heap area of ​​Core Coupled Memory
		yss::initializeCheap();
#endif
	}

	void __WEAK SystemCoreClockUpdate(void)
	{

	}
}

#if YSS_L_HEAP_USE == true
void __WEAK initializeSdram(void)
{
}
#endif

void __WEAK initDma(void)
{
}
