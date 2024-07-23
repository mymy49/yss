/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_OBJSYS__H_
#define YSS_GUI_OBJSYS__H_

#include "util.h"

class Brush;
class Container;

class Object
{
public:
	Object(void);

	virtual ~Object(void);

	void setPosition(Position_t pos);

	void setPosition(int16_t x, int16_t y);

	void setSize(Size_t size);

	void setSize(uint16_t width, uint16_t height);

	Size_t getSize(void);

	Position_t getPosition(void);

	Position_t getAbsolutePos(void);

	virtual Object *handlerPush(Position_t pos);

	virtual Object *handlerDrag(Position_t pos);

	virtual Object *handlerUp(void);

	virtual void paint(void) = 0;

	bool isVisible(void);

	void setVisible(bool on);

	void setParent(Container *parent);

	Brush* getFrameBuffer(void);

protected:
	bool mVisibleFlag;
	bool mResizeAble;
	Position_t mPos;
	Container *mParent;
	Brush *mFrameBuffer;

	virtual void eventSizeChanged(Size_t size);

	virtual void update(Position_t pos, Size_t size);

	virtual void update(Position_t beforePos, Size_t beforeSize, Position_t currentPos, Size_t currentSize);

	virtual void update(void);
};

#endif

