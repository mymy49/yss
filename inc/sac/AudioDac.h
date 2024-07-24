/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_SAC_AUDIO_DAC__H_
#define YSS_SAC_AUDIO_DAC__H_

#include <stdint.h>
#include <drv/I2s.h>

class AudioDac
{
  public:
	struct Config
	{
		uint32_t lrck;
	};

	enum
	{
	};

	virtual bool isSupported() = 0;
};

#endif