//
// main.cpp : Defines entry point for an SAM L C/C++ application.
//

#include <sam.h>
#include <yss/yss.h>

int main(int argc, char *argv[])
{
	yss::init();

	while(1)
	{
		thread::yield();
	}
  return 0;
}
