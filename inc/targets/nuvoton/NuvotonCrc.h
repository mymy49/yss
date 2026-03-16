/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_CRC__H_
#define YSS_NUVOTON_DRV_CRC__H_

#include <drv/Crc.h>

class NuvotonCrc : public Crc
{

public :
	NuvotonCrc(const Drv::setup_t drvSetup) __attribute__((optimize("-O1")));

	error_t initialize(config_t config) __attribute__((optimize("-O1")));

	virtual error_t configure(config_t config) __attribute__((optimize("-O1")));

	virtual uint32_t calculate(void *src, uint32_t size) __attribute__((optimize("-O1")));

	virtual void resetChecksum(void) __attribute__((optimize("-O1")));

private :
	CRC_T *mDev;
	datalen_t mDataLen;
};

#endif

