/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_UTIL__H_
#define YSS_GUI_UTIL__H_

#include <stdint.h>

typedef struct
{
	int16_t x, y;
}Position_t;

typedef struct
{
	uint16_t width, height;
}Size_t;

typedef struct
{
	uint16_t width;
	uint16_t height;
	uint8_t type; // 0 : RGB565, 1 : RGB888, 2 : ARGB1555
	uint8_t *data;
}Bitmap_t;

typedef struct __attribute__((packed))
{
	uint16_t width;
	uint16_t height;
	uint8_t type; // 0 : RGB565, 1 : RGB888, 2 : ARGB1555
	uint8_t reserved[3];
	uint8_t data;
}BitmapFile_t;

extern "C"
{
	void copyRgb888DotPattern(void *des, uint32_t pattern, uint32_t count);
}

#endif

