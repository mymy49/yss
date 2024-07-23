/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_OUTPUT_FRAME_BUFFER__H_
#define YSS_GUI_OUTPUT_FRAME_BUFFER__H_

#include <config.h>

#ifdef YSS_OUTPUT_FRAME_BUFFER

class Frame;

class OutputFrameBuffer
{
public :
	OutputFrameBuffer(void);

	~OutputFrameBuffer(void);

	void update(Position_t pos, Size_t size);

	void update(Position_t beforePos, Size_t beforeSize, Position_t currentPos, Size_t currentSize);

	void update(void);

	void setFrame(Frame *frame);

	uint8_t* getFrameBuffer(void);

	void setLcdSize(Size_t size);

private :
	Frame *mFrame;
	YSS_OUTPUT_FRAME_BUFFER *mFrameBuffer;
};

#endif

#endif

