#include <task/display.h>

FunctionQueue gFq(16);

namespace task
{
	int gThreadId[THREAD_COUNT];
	Mutex gMutex;
	Frame *gFrame;

	void clear(void)
	{
		for(int i=0;i<THREAD_COUNT;i++)
		{
			if(gThreadId[i])
			{
				thread::remove(gThreadId[i]);
				gThreadId[i] = 0;
			}
		}

		if(gFrame)
		{
			delete gFrame;
			gFrame = 0;
		}
	}
}
