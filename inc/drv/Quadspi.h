/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_QUADSPI__H_
#define YSS_DRV_QUADSPI__H_

#include "Drv.h"
#include <yss/error.h>

class Quadspi : public Drv
{
public :
	typedef enum
	{
		MODE_MAIN = 0,
		MODE_SUB
	}mode_t;

	typedef enum
	{
		CLOCK_MODE_MODE0 = 0,
		CLOCK_MODE_MODE1,
		CLOCK_MODE_MODE2,
		CLOCK_MODE_MODE3,
	}clockMode_t;

	typedef enum
	{
		BIT_WIDTH_SINGLE = 0,
		BIT_WIDTH_DOUBLE,
		BIT_WIDTH_QUAD,
	}bitWidth_t;

	typedef enum
	{
		DATA_WIDTH_8BIT = 0,
		DATA_WIDTH_9BIT,
		DATA_WIDTH_10BIT,
		DATA_WIDTH_11BIT,
		DATA_WIDTH_12BIT,
		DATA_WIDTH_13BIT,
		DATA_WIDTH_14BIT,
		DATA_WIDTH_15BIT,
		DATA_WIDTH_16BIT,
		DATA_WIDTH_17BIT,
		DATA_WIDTH_18BIT,
		DATA_WIDTH_19BIT,
		DATA_WIDTH_20BIT,
		DATA_WIDTH_21BIT,
		DATA_WIDTH_22BIT,
		DATA_WIDTH_23BIT,
		DATA_WIDTH_24BIT,
		DATA_WIDTH_25BIT,
		DATA_WIDTH_26BIT,
		DATA_WIDTH_27BIT,
		DATA_WIDTH_28BIT,
		DATA_WIDTH_29BIT,
		DATA_WIDTH_30BIT,
		DATA_WIDTH_31BIT,
		DATA_WIDTH_32BIT
	}dataWidth_t;

	typedef enum
	{
		BIT_ORDER_MSB = 0,
		BIT_ORDER_LSB
	}bitOrder_t;

	typedef struct 
	{
		uint32_t maxFrequncy;
		uint32_t capacity;
		clockMode_t clockMode;
	}specification_t;

	typedef struct 
	{
		bitWidth_t bitWidth;
		dataWidth_t dataWidth;
		bitOrder_t bitOrder;
	}dataform_t;

	typedef struct
	{
		mode_t mode;
	}config_t;

	virtual error_t initialize(config_t config) = 0;

	virtual error_t setSpecification(const specification_t &spec) = 0;

	virtual error_t transmit(dataform_t dataform, uint32_t data) = 0;

	virtual error_t exchange(dataform_t dataform, uint32_t &data) = 0;

	virtual error_t receive(dataform_t dataform, uint32_t &data) = 0;

	virtual error_t transmit(dataform_t dataform, void *data, uint32_t size) = 0;

	virtual error_t exchange(dataform_t dataform, void *data, uint32_t size) = 0;

	uint32_t getCapacity(void);

	// 여기부터 아래 내용들은 사용자가 호출할 필요가 없는 함수입니다.
	Quadspi(const Drv::setup_t drvSetup);

protected :
	uint32_t mCapacity;
};

#endif

