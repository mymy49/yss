/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_RADIO_PANEL__H_
#define YSS_GUI_RADIO_PANEL__H_

#include "Panel.h"
#include "RadioButton.h"

class RadioPanel : public Panel
{
	const char *mText;
	int16_t mObjectStartPos;
	uint16_t mLastNumOfObj;
	int32_t  mLastIndex;
	void (*mPushHandler)(int32_t  index);

  public:
	RadioPanel(void);
	void paint(void);

	void add(Object &obj);
	void add(Object *obj);

	void add(RadioButton &obj);
	void add(RadioButton *obj);

	void setText(const char *text);
	void setChangeEventHandler(void (*handler)(int32_t ));

	Object *handlerPush(Position_t pos);
};

#endif

