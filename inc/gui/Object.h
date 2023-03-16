////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_GUI_OBJSYS__H_
#define YSS_GUI_OBJSYS__H_

#include "Rgb565.h"
#include "Rgb888.h"
#include "util.h"
#include <yss/Mutex.h>

#if !defined(YSS_GUI_FRAME_BUFFER)
#define YSS_GUI_FRAME_BUFFER Rgb565
#endif

typedef YSS_GUI_FRAME_BUFFER YssSysFrameBuffer;

class Container;
class Frame;

class Object
{
  protected:
	bool mVisibleFlag;
	bool mResizeAble;
	Position mPos;
	Container *mParent;
	Frame *mFrame;
	YssSysFrameBuffer *mFrameBuffer;
	Mutex mMutex;

	virtual void eventSizeChanged(Size size);

	virtual void update(Position pos, Size size);
	virtual void update(Position beforePos, Size beforeSize, Position currentPos, Size currentSize);
	virtual void update(void);

  public:
	Object(void);
	~Object(void);

	virtual void destroy(void);

	void setPosition(Position pos);
	void setPosition(int16_t x, int16_t y);

	void setSize(Size size);
	void setSize(uint16_t width, uint16_t height);

	Size getSize(void);

	Position getPos(void);

	Position getAbsolutePos(void);

	virtual Object *handlerPush(Position pos);
	virtual Object *handlerDrag(Position pos);
	virtual Object *handlerUp(void);

	virtual void paint(void) = 0;

	bool isVisible(void);
	void setVisible(bool on);

	void setParent(Container *parent);
	void setFrame(Frame *frame);

	YssSysFrameBuffer* getFrameBuffer(void);
};

#endif

