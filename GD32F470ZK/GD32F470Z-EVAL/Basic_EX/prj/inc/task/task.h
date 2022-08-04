#ifndef TASK__H_
#define TASK__H_

#include <util/FunctionQueue.h>
#include <yss/gui.h>

extern FunctionQueue gFq;

#define THREAD_COUNT		5

namespace task
{
	extern int gThreadId[THREAD_COUNT];
	extern Mutex gMutex;
	extern Frame *gFrame;

	void clear(void);
}

#endif