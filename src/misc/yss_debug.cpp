/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__SEGGER_LINKER)

#include <stdarg.h>
#include <stdio.h>
#include <yss/Mutex.h>
#include <drv/peripheral.h>
#include <yss/thread.h>
#include <RTT/SEGGER_RTT.h>

static Mutex gMutex;

int32_t  debug_printf(const char *fmt,...) 
{
	char buffer[128];  
	va_list args;  
	va_start (args, fmt);  
	int32_t  n = vsnprintf(buffer, sizeof(buffer), fmt, args);  
	gMutex.lock();
	SEGGER_RTT_Write(0, buffer, n);  
	gMutex.unlock();
	va_end(args);  
	return n;
}
#elif defined(ST_CUBE_IDE)
extern "C"
{

}
#elif defined(DEBUG)
#include <__cross_studio_io.h>

extern "C"
{
	void __assert(const char *__expression, const char *__filename, int __line)
	{
		debug_printf("expression = %s / file name = %s / line number = %d\n",  __expression, __filename, __line);
		while(1);
	}
}

#endif

