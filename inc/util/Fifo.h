/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_FIFO__H_
#define YSS_UTIL_FIFO__H_

#include <yss/Mutex.h>
#include <stdint.h>

class Fifo : public Mutex
{
	int32_t  mHead, mTail, mSize;
	uint8_t *mData;

  public:
	Fifo(uint32_t size);
	~Fifo(void);
	void push(void *src, uint32_t size);
	void push(int8_t src);
	int8_t pop(void);
	void pop(void *des, uint32_t size);
	uint32_t getStoredSize(void);
	uint32_t getFreeSize(void);
	void flush(void);
};

#endif
