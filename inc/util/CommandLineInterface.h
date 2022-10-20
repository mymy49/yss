////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.0
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2022. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef	YSS_UTIL_COMMAND_LINE_INTERFACE__H_
#define	YSS_UTIL_COMMAND_LINE_INTERFACE__H_

#include <stdint.h>
#include <yss/error.h>
#include <drv/Uart.h>

class FunctionQueue;

class CommandLineInterface
{
	enum
	{
		MAX_COMMAND_LINE_COUNT = 64,
		MAX_VARIABLE_SIZE = 32
	};

	struct CommandSet
	{
		const char *cmd;
		const uint8_t *varType;
		const char *description;
		error (*callback)(Uart *peripheral, void *var);
	};

	uint8_t mVariableBuffer[MAX_VARIABLE_SIZE];
	int32_t mThreadId, mStackSize, mCommandSetCount, mCommandCountIndex;
	char mCommandLineBuffer[MAX_COMMAND_LINE_COUNT];
	const char *mGreetings;
	CommandSet *mCommandSet;
	Uart *mPeri;
	FunctionQueue *mFq;

	int32_t findMatchingCommand(char *cmd);
	void copyOneItem(char **src, char *des, uint32_t &size);
	void clearBuffer(void);
	bool checkStringAsInteger(char *src);
	bool checkStringAsString(char *src);
	bool checkStringAsFloat(char *src);
	
public:
	enum
	{
		TERMINATE = 0,
		INT,
		FLOAT,
		STRING
	};

	CommandLineInterface(Uart &peri, FunctionQueue &fq, uint32_t stackSize = 1024, uint32_t maxCommandCount = 20);
	~CommandLineInterface(void);

	// Command Line Interface 기능을 수행한다.
	// 호출 시점에 쓰레드가 등록되고 
	error start(void);
	void stop(void);
	void process(void);
	error addCommand(const char *cmd, const uint8_t *varType, error (*callback)(Uart *, void *), const char *description = 0);
	void setGreetings(const char *msg);
};

#endif