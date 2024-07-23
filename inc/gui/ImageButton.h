/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_IMAGE_BUTTON__H_
#define YSS_GUI_IMAGE_BUTTON__H_

#include "Button.h"
#include "util.h"

class ImageButton : public Object
{
public:
	ImageButton(const Bitmap_t *normal = 0, const Bitmap_t *push = 0);

	virtual ~ImageButton(void);

	virtual void paint(void);

	void setPushEventHandler(void (*handler)(void));

	void setUpEventHandler(void (*handler)(void));

	virtual Object *handlerPush(Position_t pos);

	virtual Object *handlerUp(void);

private :
	const Bitmap_t *mNormalImage, *mPushImage;
	bool mState;
	void (*mPushHandler)(void);
	void (*mUpHandler)(void);
};

#endif

