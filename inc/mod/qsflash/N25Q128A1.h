/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_QSFLASH_N25QXXX__H_
#define YSS_MOD_QSFLASH_N25QXXX__H_

#include <drv/Quadspi.h>

#if !defined(YSS_DRV_QUADSPI_UNSUPPORTED)

#include <sac/MassStorage.h>
#include <sac/QuadspiFlash.h>

class N25Q128A1 : public MassStorage
{
public:
	struct config_t
	{
		Quadspi &dev;
		uint8_t bank;
	};

	N25Q128A1(void);

	virtual uint32_t getBlockSize(void);	// pure

	virtual uint32_t getNumOfBlock(void);	// pure

	virtual error_t write(uint32_t block, void *src);	// pure

	virtual error_t read(uint32_t block, void *des);	// pure

	virtual bool isConnected(void);	// pure

	void setConfig(const config_t &config);

	error_t initialize(void);

private :
	Quadspi *mDev;
	uint8_t mBank;
};

#endif
#endif