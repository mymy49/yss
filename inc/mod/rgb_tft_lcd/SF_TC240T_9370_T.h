/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_MOD_TFT_SF_TC240T_9370_T__H_
#define	YSS_MOD_TFT_SF_TC240T_9370_T__H_

#include <yss/instance.h>
#include <mod/tft_lcd_driver/ILI9341_spi.h>

#if !defined(YSS_DRV_LTDC_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED) && !defined(YSS_DRV_SPI_UNSUPPORTED)

class SF_TC240T_9370_T : public ILI9341_spi
{
public :
	SF_TC240T_9370_T(void);
	error_t initialize(void); // virtual 0
	const Ltdc::specification_t* getSpec(void);

	// TftLcdDriver
	bool getReverseRgbOrder(void); // virtual 0
	bool getReverseEndian(void); // virtual 0
};

#endif

#endif
