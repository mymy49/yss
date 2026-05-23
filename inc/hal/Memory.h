/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_SERIAL_MEMORY__H_
#define YSS_SAC_SERIAL_MEMORY__H_

#include <stdint.h>
#include <yss/error.h>

class Memory
{
public:
	error_t write(uint32_t addr, uint8_t src);
	error_t write(uint32_t addr, int8_t src);
	error_t write(uint32_t addr, uint16_t src);
	error_t write(uint32_t addr, int16_t src);
	error_t write(uint32_t addr, uint32_t src);
	error_t write(uint32_t addr, int32_t src);
	error_t write(uint32_t addr, float src);
	error_t write(uint32_t addr, double src);
	error_t write(uint32_t addr, uint64_t src);
	error_t write(uint32_t addr, int64_t src);

	error_t read(uint32_t addr, uint8_t &des);
	error_t read(uint32_t addr, int8_t &des);
	error_t read(uint32_t addr, uint16_t &des);
	error_t read(uint32_t addr, int16_t &des);
	error_t read(uint32_t addr, uint32_t &des);
	error_t read(uint32_t addr, int32_t &des);
	error_t read(uint32_t addr, float &des);
	error_t read(uint32_t addr, double &des);
	error_t read(uint32_t addr, uint64_t &des);
	error_t read(uint32_t addr, int64_t &des);

	virtual error_t writeBytes(uint32_t addr, void *src, uint32_t size) = 0;
	virtual error_t readBytes(uint32_t addr, void *des, uint32_t size) = 0;

protected:
	virtual uint32_t getSize(void) = 0;

};

#endif