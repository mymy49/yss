/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>
#include <util/CommandLineInterface.h>
#include <util/FunctionQueue.h>
#include <util/ElapsedTime.h>
#include <yss/thread.h>
#include <string.h>
#include <stdio.h>
#include <std_ext/stdlib.h>

#include <yss/debug.h>

// 일시적으로 지원을 중단합니다.
/*
#if !defined(YSS_DRV_UART_UNSUPPORTED)

static void thread_processCli(void *var)
{
	((CommandLineInterface*)var)->process();
}

CommandLineInterface::CommandLineInterface(Uart &peri, uint32_t stackSize, uint32_t maxCommandCount)
{
	static const uint8_t varType[1] = {CommandLineInterface::TERMINATE};

	mThreadId = 0;
	mCommandSetCount = 0;
	mCommandCountIndex = 0;
	mGreetings = 0;
	mStackSize = stackSize;
	mCommandSet = new CommandSet[maxCommandCount];
	mPeri = &peri;
	memset(mCommandLineBuffer, ' ', MAX_COMMAND_LINE_COUNT-1);
	mCommandLineBuffer[MAX_COMMAND_LINE_COUNT-1] = 0;

	addCommand("help", varType, 0, "It displays Lists of Command. ex)help");
}

CommandLineInterface::~CommandLineInterface(void)
{
	stop();
	delete mCommandSet;
}

error_t CommandLineInterface::start(void)
{
	if(mThreadId)
		stop();

	mThreadId = thread::add(thread_processCli, this, mStackSize);
	if(mThreadId < 0)
	{
		mThreadId = 0;
		return error_t::FAILED_THREAD_ADDING;
	}

	return error_t::ERROR_NONE;
}

void CommandLineInterface::stop(void)
{
	if(mThreadId)
	{
		thread::remove(mThreadId);
		mThreadId = 0;
	}
}

error_t CommandLineInterface::addCommand(const char *cmd, const uint8_t *varType, error_t (*callback)(Uart *, void *), const char *description)
{
	if(mCommandSetCount >= MAX_COMMAND_LINE_COUNT)
		return error_t::INDEX_OVER;

	mCommandSet[mCommandSetCount].cmd = cmd;
	mCommandSet[mCommandSetCount].callback = callback;
	mCommandSet[mCommandSetCount].varType = varType;
	mCommandSet[mCommandSetCount++].description = description;

	return error_t::ERROR_NONE;
}

void CommandLineInterface::setGreetings(const char *msg)
{
	mGreetings = msg;
}

void CommandLineInterface::process(void)
{
	ElapsedTime lastReceivedTime;
	bool sendFlag = true, specialKeyFlag = false;
	uint32_t len, index;
	int32_t cmd;
	int8_t data, specialKeyCount;
	const char *cmdList = "\n\n\r< Command List >\n";
	char str[256], *userInput;
	uint8_t *varType, *variable;

	if(mGreetings)
	{
		mPeri->lock();
		len = strlen(mGreetings);
		mPeri->send(mGreetings, len);
		mPeri->unlock();
	}

	while(1)
	{
		if(sendFlag)
		{
			sendFlag = false;
			mPeri->lock();
			mPeri->send("\rCMD > ", 7);
			mPeri->send(mCommandLineBuffer, mCommandCountIndex+1);
			mPeri->unlock();
		}

		data = mPeri->getWaitUntilReceive();
//		debug_printf("0x%02X\n", data);
		
		if(specialKeyFlag && lastReceivedTime.getMsec() > 20)
			specialKeyFlag = false;
		lastReceivedTime.reset();
			
		if(specialKeyFlag == false)
		{
			// 일반키 수신 처리
			switch(data)
			{
			case 0x0D : // Enter Key
				mCommandLineBuffer[mCommandCountIndex] = 0;
				userInput = mCommandLineBuffer;
				index = mCommandCountIndex;
				variable = mVariableBuffer;

				copyOneItem(&userInput, str, index);
				cmd = findMatchingCommand(str);
				if(cmd < 0)
					goto enterKey_error_handler;
				
				varType = (uint8_t*)mCommandSet[cmd].varType;

				while(*varType)
				{
					while(*userInput == ' ')
					{
						index--;
						userInput++;
					}

					copyOneItem(&userInput, str, index);
					switch(*varType)
					{
					case INTEGER :
						if(!checkStringAsInteger(str))
							goto enterKey_error_handler;
						*(uint32_t*)variable = atoi(str);
						variable += sizeof(uint32_t);
						break;

					case STRING :
						if(!checkStringAsString(str))
							goto enterKey_error_handler;
						len = strlen(str);
						memcpy(variable, str, len);
						variable += len;
						*variable++ = 0;
						break;

					case FLOAT :
						if(!checkStringAsFloat(str))
							goto enterKey_error_handler;
						*(float*)variable = atof(str);
						variable += sizeof(float);
						break;

					case HEXADECIMAL :
						if(!checkStringAsHexadecimal(str))
							goto enterKey_error_handler;
						if(str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
							*(uint32_t*)variable = atox(&str[2]);
						else
							*(uint32_t*)variable = atox(&str[0]);
						variable += sizeof(uint32_t);
						break;
					}
					varType++;
				}
				if(cmd > 0)
				{
					if(mCommandSet[cmd].callback(mPeri, mVariableBuffer) == error_t::ERROR_NONE)
					{
						mPeri->lock();
						mPeri->send("\r\nDone!!\n\r", 10);
						mPeri->unlock();
					}
					else
					{
						mPeri->lock();
						mPeri->send("\r\nFailed!!\n\r", 12);
						mPeri->unlock();
					}
				}
				else
				{
					mPeri->lock();

					len = strlen(cmdList);
					mPeri->send(cmdList, len);

					for(int32_t i=0;i<mCommandSetCount;i++)
					{
						sprintf(str, "\r%-20s : %s\n", mCommandSet[i].cmd, mCommandSet[i].description);
						len = strlen(str);
						mPeri->send(str, len);
					}

					mPeri->unlock();
				}

enterKey_error_handler :
				clearBuffer();
				sendFlag = true; // 커서 제자리 이동 위해
				break;

			case 0x08 : // Back Space Key
				// 마지막 키 입력 제거
				if(mCommandCountIndex > 0)
				{
					mCommandCountIndex--;
					mCommandLineBuffer[mCommandCountIndex] = ' ';
					sendFlag = true;
				}
				break;

			case 0x09 : // Tab key
				break;
			
			case 0x1B : // Special Key
				specialKeyFlag = true;
				specialKeyCount = 0;
				break;

			default :
				if(mCommandCountIndex < MAX_COMMAND_LINE_COUNT)
				{
					mCommandLineBuffer[mCommandCountIndex++] = (char)data;
					sendFlag = true;
				}
				break;
			}
		}
		else
		{
			// Minicom 기준 특수키 수신 처리
			str[specialKeyCount++] = data;

			if(specialKeyCount == 2)
			{
				if(str[0] == 0x5B)
				{
					switch(str[1])
					{
					case 0x41 : // Up Key
					case 0x42 : // Down Key
					case 0x43 : // Right Key
					case 0x44 : // Left Key
						specialKeyFlag = false;
						break;
					}
				}
				else if(str[0] == 0x4F)
				{
					switch(str[1])
					{
					case 0x50 : // F1 Key
						mPeri->lock();

						len = strlen(cmdList);
						mPeri->send(cmdList, len);

						for(int32_t i=0;i<mCommandSetCount;i++)
						{
							sprintf(str, "\r%-20s : %s\n", mCommandSet[i].cmd, mCommandSet[i].description);
							len = strlen(str);
							mPeri->send(str, len);
						}

						mPeri->unlock();
						sendFlag = true;
						specialKeyFlag = false;
						break;

					case 0x46 : // End Key
					case 0x51 : // F2 Key
					case 0x52 : // F3 Key
					case 0x53 : // F4 Key
						specialKeyFlag = false;
						break;
					}
				}
			}
			else if(specialKeyCount == 3 && str[0] == 0x5B && str[2] == 0x7E)
			{
				switch(str[1])
				{
				case 0x31 : // Home Key
				case 0x32 : // Insert Key
				case 0x33 : // Delete Key
				case 0x35 : // Page Up Key
				case 0x36 : // Page Down Key
					specialKeyFlag = false;
					break;
				}
			}
			else if(specialKeyCount == 4 && str[0] == 0x5B && str[3] == 0x7E)
			{
				if(str[1] == 0x31)
				{
					switch(str[2])
					{
					case 0x36 : // F5 Key
						clearBuffer();
						sendFlag = true; // 커서 제자리 이동 위해
						break;

					case 0x37 : // F6 Key
					case 0x38 : // F7 Key
					case 0x39 : // F8 Key
						specialKeyFlag = false;
						break;
					}
				}
				else if(str[1] == 0x32)
				{
					switch(str[2])
					{
					case 0x30 : // F9 Key
						specialKeyFlag = false;
						break;
					}
				}
			}
		}

		thread::yield();
	}
}

void CommandLineInterface::copyOneItem(char **src, char *des, uint32_t &size)
{
	char buf;
	uint32_t i;

	for(i=0;i<size;i++)
	{
		buf = *(*src)++;
		if(('a' <= buf && buf <= 'z') || ('A' <= buf && buf <= 'Z') || ('0' <= buf && buf <= '9') || buf == '_' || buf == '.')
			des[i] = buf;
		else
		{
			des[i] = 0;
			break;
		}
	}

	size -= i;
	des[mCommandCountIndex] = 0;
}

int32_t CommandLineInterface::findMatchingCommand(char *cmd)
{
	for(int32_t i=0;i<mCommandSetCount;i++)
	{
		if(!strcmp(cmd, mCommandSet[i].cmd))
			return i;
	}

	return -1;
}

void CommandLineInterface::clearBuffer(void)
{
	memset(mCommandLineBuffer, ' ', MAX_COMMAND_LINE_COUNT-1);
	mCommandLineBuffer[MAX_COMMAND_LINE_COUNT-1] = 0;

	mPeri->lock();
	mPeri->send("\rCMD > ", 7);
	mPeri->send(mCommandLineBuffer, mCommandCountIndex+1);
	mPeri->unlock();

	mCommandCountIndex = 0;
}

bool CommandLineInterface::checkStringAsInteger(char *src)
{
	while(*src)
	{
		if(!('0' <= *src && *src <= '9'))
			return false;

		src++;
	}

	return true;
}

bool CommandLineInterface::checkStringAsString(char *src)
{
	while(*src)
	{
		if(!(('a' <= *src && *src <= 'z') || ('A' <= *src && *src <= 'Z') || ('0' <= *src && *src <= '9') || *src == '_'))
			return false;

		src++;
	}

	return true;
}

bool CommandLineInterface::checkStringAsFloat(char *src)
{
	while(*src)
	{
		if(!(('0' <= *src && *src <= '9') || *src == '_'))
			return false;

		src++;
	}

	return true;
}

bool CommandLineInterface::checkStringAsHexadecimal(char *src)
{
	while(*src)
	{
		if(!(('0' <= *src && *src <= '9') || *src == 'x' || *src == 'X' || ('a' <= *src && *src <= 'f') || ('A' <= *src && *src <= 'F')))
			return false;

		src++;
	}

	return true;
}

#endif

*/

