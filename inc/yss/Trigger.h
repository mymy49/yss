/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_TRIGGER_CLASS__H_
#define YSS_TRIGGER_CLASS__H_

#include "thread.h"

/*
	이 Class를 상속 받은 Class는 멤버 함수 하나를 trigger로 실행하도록 합니다.
	생성된 trigger는 자원에 대한 동시 접근에 신경써야 합니다. 경우에 따라서는 Mutex의 활용이 필요합니다.
*/
class Trigger
{
public:
	Trigger(void);
	
	/*
		실제 trigger로 동작할 함수입니다.
		이 Class를 상속 받은 Class는 본 함수를 재정의하여 trigger로 동작할 함수를 생성합니다.
		단순히 재정의만으로 trigger가 활성화 되는 것은 아닙니다. 
		activateTrigger() 함수를 호출하여 실질적인 trigger가 생성되고 runTrigger() 함수를 호출 할 경우 trigger로 동작합니다.
		trigger는 runTrigger() 호출시 1회에 한하여 thread로써 동작하고 작업이 완료되면 return하여 작동을 마무리 해야 합니다.
		return으로 작업이 마무리 되면, trigger는 다음 runTrigger() 함수 호출시까지 대기하게 됩니다.
	*/
	virtual void trigger(void) = 0;

	/*
		trigger() 함수를 실제 trigger에 등록하는 함수입니다.
		이미 앞서 이 함수를 호출하여 trigger에 등록되었다면, 추가로 호출하는 행위는 아무 의미가 없습니다.
		.
		@ stackSize : 생성하는 trigger의 stack 사이즈를 설정합니다.
	*/
	void activateTrigger(uint32_t stackSize = 512);

	/*
		trigger() 함수를 trigger에서 등록 해제하는 함수입니다.
	*/
	void deactivateTriger(void);

	/*
		trigger() 함수를 1회 동작시키는 함수입니다.
	*/
	void runTrigger(void);

private:
	triggerId_t mId;
};

#endif