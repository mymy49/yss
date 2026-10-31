#include <util/TouchEventDispatcher.h>
#include <yss/debug.h>

TouchEventDispatcher::TouchEventDispatcher(uint32_t depth, uint32_t stackSize)
{
	mDepth = depth;
	mEventMap = new eventMap_t[depth];
	mCount = 0;
	mPointerDev = nullptr;
	mSelectedIndex = -1;

	activateTrigger(stackSize);
}

TouchEventDispatcher::~TouchEventDispatcher()
{
	delete[] mEventMap;
}

error_t TouchEventDispatcher::add(Area area, void (*callback)(PointerDevice::event_t))
{
	if(mCount < mDepth)
	{
		mEventMap[mCount].area = area;
		mEventMap[mCount++].callback = callback;
		return error_t::ERROR_NONE;
	}
	else
		return error_t::INDEX_OVER;
}

void TouchEventDispatcher::setPointerDevice(PointerDevice &dev)
{
	dev.setTriggerId(getTriggerId());
	mPointerDev = &dev;
}

void TouchEventDispatcher::trigger()
{
	PointerDevice::event_t event;
	Area area;

	if(mCount == 0)
		return;

	while(1)
	{
		event = mPointerDev->getCurrentEvent();
		
		switch(event.event)
		{
		case PointerDevice::EVENT_NOTTING :
			thread::yield();
			break;

		case PointerDevice::EVENT_TOUCH_UP :
			if(mSelectedIndex >= 0)
			{
				area = mEventMap[mSelectedIndex].area;
				event.x -= area.getX();
				event.y -= area.getY();
				mEventMap[mSelectedIndex].callback(event);			
			}
			return;
		
		case PointerDevice::EVENT_TOUCH_DOWN :
			mSelectedIndex = -1;

			for(uint32_t i = 0; i < mCount; i++)
			{
				area = mEventMap[i].area;
				if(	area.getX() <= event.x && event.x <= area.getRightBound() &&
					area.getY() <= event.y && event.y <= area.getBotBound())
				{
					event.x -= area.getX();
					event.y -= area.getY();
					mEventMap[i].callback(event);
					mSelectedIndex = i;
					break;
				}
			}
			break;

		case PointerDevice::EVENT_TOUCH_DRAG :
			if(mSelectedIndex >= 0)
			{
				area = mEventMap[mSelectedIndex].area;
				event.x -= area.getX();
				event.y -= area.getY();
				mEventMap[mSelectedIndex].callback(event);
			}
			break;
		}
	}
}

void TouchEventDispatcher::clear()
{
	mCount = 0;
	mSelectedIndex = -1;
	if(mPointerDev != nullptr)
		mPointerDev->clearEvent();
}

