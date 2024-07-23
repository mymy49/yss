/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_CHECK_BOX__H_
#define YSS_GUI_CHECK_BOX__H_

#include "Object.h"

class CheckBox : public Object
{
	void (*mPushHandler)(bool);
	bool mState;
	const int8_t *mText;

  protected:
  public:
	void setPushEventHandler(void (*handler)(bool));
	CheckBox(void);
	void paint(void);
	void setText(const int8_t *text);

	Object *handlerPush(Position_t pos);
};

#endif

