////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License V3.3
//
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
//
// 본 소스 코드를 :
//		- 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
//		- 상업적 또는 비 상업적 이용이 가능합니다.
//		- 본 저작권 표시 주석을 제외한 코드의 내용을 임의로 수정하여 사용하는 것은 허용합니다.
//		- 사용자가 수정한 코드를 사용자의 고객사에게 상호간 전달은 허용합니다.
//		- 그러나 수정하여 다수에게 재배포하는 행위를 금지합니다. 
//		- 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//		- 어떤 형태의 기여든지, 그것은 기증으로 받아들입니다.
//
// 본 소스 코드는 프리웨어로 앞으로도 유료로 전환하지 않을 것입니다.
// 사용자 또는 부품의 제조사가 요구하는 업데이트가 있을 경우 후원금을 받아 
// 요구하는 사항을 업데이트 할 예정입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_FQ__H_
#define YSS_FQ__H_

#include <yss/thread.h>
#include <yss/error.h>

// 등록된 함수를 순차적으로 실행하는 class이다. 순차처리에 특화된 기능이다.
// add() 함수를 통해 함수를 등록하고 등록된 함수들은 순차적으로 호출이 된다.
// 외부에서 start(), stop() 함수를 호출하면 처리를 시작하거나 처리를 멈춘다.
// 등록 함수의 리턴이 error::ERROR_NONE이 아닌 다른 값일 경우 수행을 멈추고 
// setCallbackErrorHandler()를 통해 등록된 함수를 호출한다.
class FunctionQueue : public Mutex
{
	error (**mTaskFunc)(FunctionQueue *task, void *var);
	void **mVariable;
	int32_t mThreadId;
	int32_t mStackSize;
	error mError;
	uint16_t mTaskMaxSize, mTaskHead, mTaskTail;
	bool mBusyFlag, mProcessingFlag;
	Mutex mMutex;
	void (*mCallbackErrorHandler)(FunctionQueue *fq, error errorCode);

  public:
	// uint16_t depth
	//		저장 가능한 함수 포인터의 개수를 설정한다.
	// int32_t  stackSize
	//		등록된 함수를 호출하는 쓰레드의 스텍 용량을 설정한다.
	FunctionQueue(uint16_t depth, int32_t  stackSize = 2048);
	~FunctionQueue(void);
	
	// 순차처리 함수를 등록한다.
	//
	// error (*func)(FunctionQueue *, void *)
	//		순차적으로 수행할 함수 포인터를 설정한다.
	// void *var
	//		범용으로 쓸수 있는 인자를 넘긴다. 현재 void의 포인터로 되어 있으나
	//		형변환으로 요구되는 형태로 바꿔서 사용한다.
	void add(error (*func)(FunctionQueue *, void *), void *var = 0);
	
	// 순차처리 함수를 등록한다.
	//
	// error (*func)(FunctionQueue *)
	//		순차적으로 수행할 함수 포인터를 설정한다.
	void add(error (*func)(FunctionQueue *));
	
	// 순차처리를 시작하는 함수이다.
	// add() 함수를 통해 함수가 등록되어도 본 함수를 호출하지 않으면 처리를
	// 시작하지 않는다.
	//
	// 반환
	//		발생한 error를 반환한다.
	error start(void);
	
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

	// 등록된 순차처리 함수가 error::ERROR_NONE이 아닌 값을 반환 했을 경우 수행할 callback 함수를 등록한다.
	// 
	// void (*callback)(FunctionQueue *fq, error errorCode)
	//		callback 핸들러 함수를 설정한다.
	void setCallbackErrorHandler(void (*callback)(FunctionQueue *fq, error errorCode));

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	error task(void);
	void callErrorHandler(error errorCode);
};

#endif