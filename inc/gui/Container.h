/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_CONTAINER__H_
#define YSS_GUI_CONTAINER__H_

#include "Object.h"

class Container : public Object
{
  public:
	Container(void);

	virtual ~Container(void);

	virtual void paint(void);

	void increaseObjArr(void);

	void add(Object &obj);

	void add(Object *obj);

	void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0xFF);

	void update(Position_t pos, Size_t size);

	void update(Position_t beforePos, Size_t beforeSize, Position_t currentPos, Size_t currentSize);

	void update(void);

	Object *handlerPush(Position_t pos);

	Object *handlerDrag(Position_t pos);

	Object *handlerUp(void);

  protected:
	uint16_t mNumOfObj, mMaxObj;
	Object **mObjArr, *mLastEventObj;
	bool mValidFlag;
};

#endif

