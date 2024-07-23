/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_BMP565__H_
#define YSS_GUI_BMP565__H_

#include <stdint.h>

struct Bmp565
{
	uint16_t width;
	uint16_t height;
	uint8_t type; // 0 : RGB565, 1 : RGB888
	uint8_t *data;
};

#endif

