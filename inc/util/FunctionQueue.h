/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_FQ__H_
#define YSS_FQ__H_

#include <yss/thread.h>
#include <yss/error.h>

// 등록된 함수를 순차적으로 실행하는 class이다. 순차처리에 특화된 기능이다.
// add() 함수를 통해 함수를 등록하고 등록된 함수들은 순차적으로 호출이 된다.
// 외부에서 start(), stop() 함수를 호출하면 처리를 시작하거나 처리를 멈춘다.
// 등록 함수의 리턴이 error_t::ERROR_NONE이 아닌 다른 값일 경우 수행을 멈추고 
// setCallbackErrorHandler()를 통해 등록된 함수를 호출한다.
class FunctionQueue : public Mutex
{
  public:
	// uint16_t depth
	//		축적 가능한 함수 포인터의 개수를 설정한다.
	// int32_t  stackSize
	//		등록된 함수를 호출하는 쓰레드의 스텍 용량을 설정한다.
	FunctionQueue(uint16_t depth, int32_t  stackSize = 2048);
	
	~FunctionQueue(void);
	
	// 순차처리 함수를 등록한다.
	//
	// error_t (*func)(FunctionQueue *, void *)
	//		순차적으로 수행할 함수 포인터를 설정한다.
	// void *var
	//		범용으로 쓸수 있는 인자를 넘긴다. 현재 void의 포인터로 되어 있으나
	//		형변환으로 요구되는 형태로 바꿔서 사용한다.
	void add(error_t (*func)(FunctionQueue *, void *), void *var = 0);
	
	// 순차처리 함수를 등록한다.
	//
	// error_t (*func)(FunctionQueue *)
	//		순차적으로 수행할 함수 포인터를 설정한다.
	void add(error_t (*func)(FunctionQueue *));
	
	// 순차처리를 시작하는 함수이다.
	// add() 함수를 통해 함수가 등록되어도 본 함수를 호출하지 않으면 처리를
	// 시작하지 않는다.
	//
	// 반환
	//		발생한 error_t를 반환한다.
	error_t start(void);
	
	// 순차처리를 중단시키는 함수이다.
	// 현재 실행중인 함수를 강제 종료시키고, 등록된 함수들을 모두 비운다.
	void stop(void);

	// 등록된 모든 함수를 모두 비운다.
	// 단, 현재 실행중인 함수는 완료한다.
	void clear(void);

	// 현재 등록된 함수가 있고, 그 함수들을 수행중인지 확인한다.
	//
	// 반환
	//		현재 수행중인 함수가 있다면 false, 처리가 완료되었다면 true를 반환한다.
	bool isComplete(void);

	// 등록된 순차처리 함수가 error_t::ERROR_NONE이 아닌 값을 반환 했을 경우 수행할 callback 함수를 등록한다.
	// 
	// void (*callback)(FunctionQueue *fq, error_t errorCode)
	//		callback 핸들러 함수를 설정한다.
	void setCallbackErrorHandler(void (*callback)(FunctionQueue *fq, error_t errorCode));

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	error_t task(void);
	void callErrorHandler(error_t errorCode);

private :
	error_t (**mTaskFunc)(FunctionQueue *task, void *var);
	void **mVariable;
	int32_t mThreadId;
	int32_t mStackSize;
	error_t mError;
	uint16_t mTaskMaxSize, mTaskHead, mTaskTail;
	bool mBusyFlag, mProcessingFlag;
	Mutex mMutex;
	void (*mCallbackErrorHandler)(FunctionQueue *fq, error_t errorCode);
};

#endif