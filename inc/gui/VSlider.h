/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_VSLIDER__H_
#define YSS_GUI_VSLIDER__H_

#include "Object.h"

class VSlider : public Object
{
	void (*mChangeHandler)(int32_t  pos);
	int16_t mLastPos, mThisPos, mMax;

  protected:
  public:
	void setChangeEventHandler(void (*handler)(int32_t ));
	VSlider(void);
	void paint(void);
	void setMaxValue(uint16_t max);
	void setSize(uint16_t width, uint16_t height);
	void setSize(Size_t size);

	Object *handlerPush(Position_t pos);
	Object *handlerDrag(Position_t pos);
};

#endif

