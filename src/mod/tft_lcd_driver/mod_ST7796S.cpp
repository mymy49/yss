/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI == true

#include <mod/tft_lcd_driver/ST7796S.h>

ST7796S::ST7796S(void)
{

}

void ST7796S::setDirection(bool xMirror, bool yMirror, bool rotate)
{
	enable();
	int8_t memAccCtrl[] = {0x00};
	if(rotate)
	{
		memAccCtrl[0] |= 0x20;

		if(xMirror)
			memAccCtrl[0] |= 0x80;
		if(yMirror)
			memAccCtrl[0] |= 0x40;
	}
	else
	{
		if(xMirror)
			memAccCtrl[0] |= 0x40;
		if(yMirror)
			memAccCtrl[0] |= 0x80;
	}

	mRotateFlag = rotate;

	sendCmd(MEMORY_ACCESS_CONTROL, (int8_t *)memAccCtrl, sizeof(memAccCtrl));
	disable();
}

void ST7796S::setWindows(uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
	uint8_t data[4];
	uint16_t end;

	end = x + width - 1;
	data[0] = x >> 8;
	data[1] = x & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(COLUMN_ADDRESS_SET, data, 4);
	
	end = y + height - 1;
	data[0] = y >> 8;
	data[1] = y & 0xFF;
	data[2] = end >> 8;
	data[3] = end & 0xFF;

	sendCmd(PAGE_ADDRESS_SET, data, 4);
}

#endif
