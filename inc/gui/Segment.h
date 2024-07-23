/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_SEGMENT__H_
#define YSS_GUI_SEGMENT__H_

#include "Object.h"

class segment : public Object
{
  protected:
	uint8_t mNumOfSegment;

  public:
	segment(void);
	void paint(void);
	void setSize(Size_t size);
	void setSize(uint16_t width, uint16_t height);
	void drawOneSegment(int16_t x, int16_t y, int8_t num);
};

#endif

