/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_BUTTON__H_
#define YSS_GUI_BUTTON__H_

#include "Object.h"

class Font;

class Button : public Object
{
public:
	Button(void);

	virtual ~Button(void);

	void setPushEventHandler(void (*handler)(void));

	void setUpEventHandler(void (*handler)(void));

	void setText(const char *text);

	void setFont(Font &font);

	void setColor(Color color);

	void setColor(uint8_t red, uint8_t green, uint8_t blue);

	virtual void paint(void);

	virtual Object *handlerPush(Position_t pos);

	virtual Object *handlerUp(void);

private :
	void (*mPushHandler)(void);
	void (*mUpHandler)(void);
	bool mState;
	const char *mText;
};

#endif

