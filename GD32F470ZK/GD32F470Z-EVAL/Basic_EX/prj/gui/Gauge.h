#ifndef GUI_SPEED_GAUGE__H_
#define GUI_SPEED_GAUGE__H_

#include <gui/Object.h>
#include <gui/Container.h>
#include <yss/gui.h>
#include <config.h>

class Gauge : public Object
{
	YSS_GUI_FRAME_BUFFER *mBg;
	void drawNeedle(float angle);
	bool mInitFlag;
	Position mCenter, mLastNeedlePos;
	unsigned short mNeedleLen;
	float mTopValue, mValue;
	const char *mTitleStr;
	Font mFont;

public:
	Gauge(void);
	~Gauge(void);
	void paint(void);
	void destroy(void);
	void makeBg(void);
	void setTopValue(float value);
	void setValue(float value);
	void setTitle(const char *str);
	void setFont(Font font);
};

#endif
