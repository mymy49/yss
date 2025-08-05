/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_THREAD_CLASS__H_
#define YSS_THREAD_CLASS__H_

#include "thread.h"

/*
	이 Class를 상속 받은 Class는 멤버 함수 하나를 thread로 실행하도록 합니다.
	생성된 thread는 자원에 대한 동시 접근에 신경써야 합니다. 경우에 따라서는 Mutex의 활용이 필요합니다.
*/
class Thread
{
public:
	Thread(void);
	
	~Thread(void);

	/*
		실제 thread로 동작할 함수입니다.
		이 Class를 상속 받은 Class는 본 함수를 재정의하여 thread로 동작할 함수를 생성합니다.
		단순히 재정의만으로 thread가 활성화 되는 것은 아닙니다. 
		runThread() 함수를 호출하여 실질적인 thread가 생성되고 동작합니다.
	*/
	virtual void thread(void) = 0;

	/*
		thread() 함수를 실제 thread에 등록하는 함수입니다.
		이미 앞서 이 함수를 호출하여 thread에 등록되었다면, 추가로 호출하는 행위는 아무 의미가 없습니다.
		.
		@ stackSize : 생성하는 thread의 stack 사이즈를 설정합니다.
	*/
	void runThread(uint32_t stackSize = 512);

	/*
		thread() 함수를 thread에서 등록 해제하는 함수입니다.
	*/
	void stopThread(void);

private:
	threadId_t mId;
};

#endif