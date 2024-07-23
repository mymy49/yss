/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_FRAME__H_
#define YSS_GUI_FRAME__H_

#include "Container.h"

class OutputFrameBuffer;

class Frame : public Container
{
public :
	Frame(void);

	virtual ~Frame(void);

	void setPosition(Position_t pos);

	void setPosition(int16_t x, int16_t y);

	void setOutputFrameBuffer(OutputFrameBuffer *outputFrameBuffer);

	void add(Object &obj);

	void add(Object *obj);

	void update(Position_t pos, Size_t size);

	void update(Position_t beforePos, Size_t beforeSize, Position_t currentPos, Size_t currentSize);

	void update(void);

	Object *handlerPush(Position_t pos);

	Object *handlerDrag(Position_t pos);

	Object *handlerUp(void);

private :
	OutputFrameBuffer *mOutputFrameBuffer;
};

#endif

