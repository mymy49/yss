/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_SAC_MASS_STORAGE__H_
#define	YSS_SAC_MASS_STORAGE__H_

#include <yss/thread.h>
#include <yss/error.h>
#include <yss/Mutex.h>

class MassStorage : public Mutex
{
public :
	virtual uint32_t getBlockSize(void) = 0;

	virtual uint32_t getNumOfBlock(void) = 0;

	virtual error_t write(uint32_t block, void *src) = 0;

	virtual error_t read(uint32_t block, void *des) = 0;

	virtual bool isConnected(void) = 0;
};

#endif

