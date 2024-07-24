/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>
#include <mod/wiznet/iEhternet.h>
#include <yss/thread.h>

iEthernet::iEthernet(void)
{
	mThreadIdLinkup = 0;
}

iEthernet::~iEthernet(void)
{
	if(mThreadIdLinkup)
	{
		thread::remove(mThreadIdLinkup);
		mThreadIdLinkup = 0;
	}
}

static void thread_process(void *var)
{
	iEthernet *obj = (iEthernet*)var;

	obj->process();
}

void iEthernet::setCallbackLinkup(void (*callback)(bool), uint32_t stackSize)
{
	mCallbackLinkup = callback;
	mThreadIdLinkup = thread::add(thread_process, this, stackSize);
}

void iEthernet::process(void)
{
	bool lastLinkup = false, buf;

	while(1)
	{
		lock();
		buf = isLinkup();
		unlock();
		if(buf != lastLinkup)
		{
			lastLinkup = buf;
			if(mCallbackLinkup)
				mCallbackLinkup(lastLinkup);
		}

		thread::delay(500);
	}
}

