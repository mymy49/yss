/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_GUI && YSS_L_HEAP_USE

#include <gui/Bitmap.h>
#include <gui/Brush.h>

Bitmap::Bitmap(void)
{
	
}

void Bitmap::setBmp(const Bitmap_t &obj)
{
	setSize(obj.width, obj.height);
	mFrameBuffer->drawBitmap(Position_t{0, 0}, obj);
}

void Bitmap::paint(void)
{

}

#endif

