////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_3.2
// 본 소스 코드의 소유권은 홍윤기에게 있습니다.
// 어떠한 형태든 기여는 기증으로 받아들입니다.
// 본 소스 코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스 코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스 코드의 상업적 또는 비 상업적 이용이 가능합니다.
// 본 소스 코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스 코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떠한 법적 책임을 지지 않습니다.
// 본 소스 코드의 어떤 형태의 기여든 기증으로 받아들입니다.
//
// Home Page : http://cafe.naver.com/yssoperatingsystem
// Copyright 2023. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef	YSS_UTIL_COMMAND_LINE_INTERFACE__H_
#define	YSS_UTIL_COMMAND_LINE_INTERFACE__H_

#include <stdint.h>
#include <yss/error.h>
#include <drv/peripheral.h>
#include <drv/Uart.h>

// CLI를 처리하는 class이다.
// 사용 순서는 아래와 같다.
// 1. instance 생성에서 사용할 UART 장치, 내장 Thread의 스택 크기, 최대 등록 명령어를 설정한다.
// 2. setGreetings() 함수를 사용해 처음 켜질 때 나오는 인사말을 등록한다.
// 3. addCommand() 함수를 사용해 명령어들을 등록한다.
// 4. start() 함수를 호출해 cli를 동작시킨다.

// CLI의 키 입력 처리는 현재 minicom 터미널의 키 입력 값에 맞춰있다.
// 다른 터미널에서는 특수 키 입력에 대해 오동작 할 수 있다.
// F1키를 누르면 현재 사용가능한 명령어 목록이 출력된다.
// F5키를 누르면 입력된 키 값을 모두 삭제한다.
// Back Space 키를 누르면 마지막 입력값을 삭제한다.

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

	int32_t findMatchingCommand(char *cmd);
	void copyOneItem(char **src, char *des, uint32_t &size);
	void clearBuffer(void);
	bool checkStringAsInteger(char *src);
	bool checkStringAsString(char *src);
	bool checkStringAsFloat(char *src);
	bool checkStringAsHexadecimal(char *src);
	
public:
	enum
	{
		TERMINATE = 0,
		INTEGER,
		FLOAT,
		STRING,
		HEXADECIMAL
	};

	// Uart &peri
	//		CLI가 사용할 UART 장치를 설정한다.
	// uint32_t stackSize = 1024
	//		내장 Thread가 사용할 스택의 크기를 설정한다.
	// uint32_t maxCommandCount = 20
	//		최대 처리가 가능한 명령어의 개수를 설정한다.
	CommandLineInterface(Uart &peri, uint32_t stackSize = 1024, uint32_t maxCommandCount = 20);
	~CommandLineInterface(void);

	// CLI에 처음 시작 할 때, 나타낼 인사말을 등록한다.
	// 
	// const char *msg
	//		인사말을 문자열로 설정한다.
	void setGreetings(const char *msg);

	// CLI에 사용자가 사용할 명령어를 등록한다.
	// 
	// const char *cmd
	//		명령어를 문자열로 설정한다.
	// const uint8_t *varType
	//		인자의 종류를 설정한다. 마지막은 반드시 TERMINATE로 종료해야 한다.
	//		사용가능한 인자는 TERMINATE, INTEGER, FLOAT, STRING, HEXADECIMAL이 있다.
	// error (*callback)(Uart *, void *)
	//		일치되는 명령어가 입력되면 호출할 callback 함수를 설정한다.
	// const char *description = 0
	//		명령어에 대한 설명을 문자열로 설정한다.
	// 반환
	//		발생한 error를 반환한다.
	error addCommand(const char *cmd, const uint8_t *varType, error (*callback)(Uart *, void *), const char *description = 0);

	// CLI의 처리를 시작한다.
	// 호출 시점에 내장된 Thread가 등록되고 실패시 관련 에러를 반환한다.
	//
	// 반환
	//		발생한 error를 반환한다.
	error start(void);

	// CLI의 처리를 중단한다.
	// 호출 시점에 내장된 Thread가 제거된다.
	void stop(void);

	// 아래 함수는 시스템 함수로 사용자 호출을 금한다.
	void process(void);
};

#endif

