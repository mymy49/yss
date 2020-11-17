////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//  주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/mcu.h>

#if defined(STM32F746xx) || defined(STM32F745xx) || \
	defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx) || \
	defined(STM32F405xx) ||	defined(STM32F415xx) ||	\
	defined(STM32F407xx) ||	defined(STM32F417xx) ||	\
	defined(STM32F427xx) ||	defined(STM32F437xx) ||	\
	defined(STM32F429xx) ||	defined(STM32F439xx)

#include <config.h>

#include <drv/peripherals.h>
#include <yss/thread.h>
#include <yss/malloc.h>
#include <util/time.h>
#include <__cross_studio_io.h>

namespace drv
{
	UsbOutData::UsbOutData(unsigned long maxSize)
	{
		mMaxSize = maxSize;
		mHead = 0;
		mTail = 0;
		mTailAbsent = 0;

#if YSS_L_HEAP_USE == true
		mData = (unsigned char*)lmalloc(maxSize);
#else
		mData = (unsigned char*)hmalloc(maxSize);
#endif
	}

	UsbOutData::~UsbOutData(void)
	{
		if(mData)
#if YSS_L_HEAP_USE == true
			lfree(mData);
#else
			hfree(mData);
#endif
	}

extern "C"
{
	void yssUsbd4ByteDataPush(unsigned long* des, unsigned long *fifo, unsigned long wordSize);
	void yssUsbd1ByteDataPush(unsigned char* des, unsigned char *fifo, unsigned long wordSize);
}
	void UsbOutData::push(unsigned long *fifo, unsigned short size)
	{
		unsigned long buf;

		buf = mMaxSize - mHead;
repeat:
		if(buf > size)
		{
			buf = size >> 2;
			size -= buf << 2;
			yssUsbd4ByteDataPush((unsigned long*)&mData[mHead], fifo, buf);
			mHead += buf << 2;
		}
		else
		{
			buf >> 2;
			size -= buf << 2;
			yssUsbd4ByteDataPush((unsigned long*)&mData[mHead], fifo, buf);
			mHead += buf << 2;
			buf = mMaxSize - mHead;
			yssUsbd1ByteDataPush((unsigned char*)&mData[mHead], (unsigned char*)fifo, buf);
			mHead += buf;
			size -= buf;
		}

		if(mHead >= mMaxSize)
			mHead = 0;

		if(size != 0)
			goto repeat;

/*
		unsigned long loop4_1, loop4_2, loop1_1, loop1_1_, loop1_2, rxSize;
		unsigned long *lDes, buf;
		unsigned char *cDes, *cSrc = (unsigned char*)&buf;

		buf = mMaxSize - mHead;
		if(buf > size)
		{
			loop4_1 = size >> 2;
			loop1_1 = size % 4;
			loop1_1_ = 0;
			loop4_2 = 0;
			loop1_2 = 0;
		}
		else
		{
			loop4_1 = buf >> 2;
			loop1_1 = buf % 4;
			if(loop1_1)
				loop1_1_ = 4 - loop1_1;
			else
				loop1_1_ = 0;
			size -= buf + loop1_1_;
			loop4_2 = size >> 2;
			loop1_2 = size % 4;
		}

		lDes = (unsigned long*)&mData[mHead];

		if(loop4_1)
		{
			mHead += loop4_1 << 2;
			while(loop4_1--)
			{
				*lDes++ = *fifo;
			}
		}

		cDes = (unsigned char*)lDes;

		if(loop1_1 || loop1_1_)
		{
			buf = *fifo;
			mHead += loop1_1;
			while(loop1_1--)
			{
				*cDes++ = *cSrc++;
			}
		}

		if(loop1_1_ || loop4_2 || loop1_2)
		{
			mHead = 0;

			cDes = (unsigned char*)&mData[mHead];

			if(loop1_1_)
			{
				mHead += loop1_1_;
				while(loop1_1_--)
				{
					*cDes++ = *cSrc++;
				}
			}

			lDes = (unsigned long*)cDes;
			if(loop4_2)
			{
				mHead += loop4_2 << 2;
				while(loop4_2--)
				{
					*lDes++ = *fifo;
				}
			}

			cDes = (unsigned char*)lDes;
			if(loop1_2)
			{
				buf = *fifo;
				mHead += loop1_2;
				while(loop1_2--)
				{
					*cDes++ = *cSrc++;
				}
			}
		}

		if(mHead >= mMaxSize)
			mHead = 0;
*/
	}

	unsigned long UsbOutData::getFreeSize(void)
	{
		if(mHead >= mTail)
			return mMaxSize - (mHead - mTail);
		else
			return mTail - mHead;
	}

	signed short UsbOutData::pop(void)
	{
		signed short buf = -1;

		if(mHead != mTail)
		{
			buf = (unsigned char)mData[mTail++];
			if(mTail >= mMaxSize)
				mTail = 0;
		}

		return buf;
	}

	void UsbOutData::flushAbsent(void)
	{
		mTailAbsent = mHead;
	}

	signed short UsbOutData::popAbsent(void)
	{
		signed short buf = -1;

		if(mHead != mTailAbsent)
		{
			buf = (unsigned char)mData[mTailAbsent++];
			if(mTailAbsent >= mMaxSize)
				mTailAbsent = 0;
		}

		return buf;
	}

	bool UsbOutData::pop(void *des, unsigned long size, unsigned long timeOut)
	{
		unsigned long loop4_1, loop4_2, loop1_1, loop1_2, rxSize;
		unsigned long *lDes, *lSrc, buf;
		unsigned char *cDes, *cSrc;
		unsigned long endTime = time::getRunningMsec() + timeOut;

		buf = mMaxSize - mTail;
		if(buf > size)
		{
			loop4_1 = size >> 2;
			loop1_1 = size % 4;
			loop4_2 = 0;
			loop1_2 = 0;
		}
		else
		{
			loop4_1 = buf >> 2;
			loop1_1 = buf % 4;
			size -= buf;
			loop4_2 = size >> 2;
			loop1_2 = size % 4;
		}

		lDes = (unsigned long*)des;
		lSrc = (unsigned long*)&mData[mTail];
		rxSize = 0;
		for(unsigned long i=0;i<loop4_1;)
		{
			if(rxSize >= 4)
			{
				*lDes++ = *lSrc++;
				rxSize -= 4;
				mTail += 4;
				i++;
			}
			else
			{
				thread::switchContext();
				rxSize = getRxSize();
				if(time::getRunningMsec() > endTime)
				{
					return false;
				}
			}
		}

		cDes = (unsigned char*)lDes;
		cSrc = (unsigned char*)lSrc;
		rxSize = 0;
		for(unsigned long i=0;i<loop1_1;)
		{
			if(rxSize >= 1)
			{
				*cDes++ = *cSrc++;
				rxSize--;
				mTail++;
				i++;
			}
			else
			{
				thread::switchContext();
				rxSize = getRxSize();
				if(time::getRunningMsec() > endTime)
				{
					return false;
				}
			}
		}

		if(loop4_2 || loop1_2)
		{
			mTail = 0;

			lDes = (unsigned long*)cDes;
			lSrc = (unsigned long*)&mData[mTail];
			rxSize = 0;
			for(unsigned long i=0;i<loop4_2;)
			{
				if(rxSize >= 4)
				{
					*lDes++ = *lSrc++;
					rxSize -= 4;
					mTail += 4;
					i++;
				}
				else
				{
					thread::switchContext();
					rxSize = getRxSize();
					if(time::getRunningMsec() > endTime)
					{
						return false;
					}
				}
			}

			cDes = (unsigned char*)lDes;
			cSrc = (unsigned char*)lSrc;
			rxSize = 0;
			for(unsigned long i=0;i<loop1_2;)
			{
				if(rxSize >= 1)
				{
					*cDes++ = *cSrc++;
					rxSize--;
					mTail++;
					i++;
				}
				else
				{
					thread::switchContext();
					rxSize = getRxSize();
					if(time::getRunningMsec() > endTime)
					{
						return false;
					}
				}
			}
		}

		return true;
	}

	unsigned long UsbOutData::getRxSize(void)
	{
		if(mTail <= mHead)
			return mHead - mTail;
		else
			return mHead + mMaxSize - mTail;
	}

	unsigned char* UsbOutData::getRxBuffer(void)
	{
		return (unsigned char*)&mData[mTail];
	}

	void UsbOutData::flush(void)
	{
		mTail = 0;
		mHead = 0;
	}
}

/*

bool UsbOutData::isReceived(void)
{
	if(mHead != mTail)
		return true;
	else
		return false;
}

unsigned char* UsbOutData::pop(unsigned char &epNum, unsigned short &size)
{
	epNum = mEpNum[mTail];
	size = mSize[mTail];
	return mData[mTail];
}

void UsbOutData::next(void)
{
	if(mHead == mDepth)
		return;

	mTail++;
	if(mTail >= mDepth)
		mTail = 0;
}

*/

#endif