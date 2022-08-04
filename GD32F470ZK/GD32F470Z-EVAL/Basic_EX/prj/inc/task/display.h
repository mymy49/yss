#ifndef TASK_DISPLAY__H_
#define TASK_DISPLAY__H_

#include <util/FunctionQueue.h>
#include <task/task.h>

namespace task
{
namespace display
{
	error displayAnalogItem(FunctionQueue *obj);
	error displayGauge(FunctionQueue *obj);
}
}

#endif