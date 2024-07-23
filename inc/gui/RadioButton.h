/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_RADIO_BUTTON__H_
#define YSS_GUI_RADIO_BUTTON__H_

#include "Object.h"

class RadioButton : public Object
{
	bool mState;
	const int8_t *mText;

  protected:
  public:
	RadioButton(void);
	void paint(void);
	void setText(const int8_t *text);
	void select(bool en);
};

#endif

