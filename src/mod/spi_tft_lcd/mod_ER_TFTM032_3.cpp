/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <drv/Spi.h>

#if USE_GUI && !defined(YSS_DRV_SPI_UNSUPPORTED)

#include <mod/spi_tft_lcd/ER_TFTM032_3.h>

static const Spi::specification_t gLcdSpec =
{
	Spi::MODE_MODE0,	//uint8_t mode;
	40000000,					//uint32_t maxFreq;
	Spi::BIT_BIT8		//uint8_t bit;
};

ER_TFTM032_3::ER_TFTM032_3(void)
{
	setSpiSpecification(gLcdSpec);
}

#endif



