/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS_DUAL_CDC__H_
#define YSS_USB_CLASS_DUAL_CDC__H_

#include "UsbClass.h"
#include <yss/error.h>

class DualCdc : public UsbClass
{
public :
/* ignore some GCC warnings */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
	typedef struct
	{
		uint8_t bLength;
		uint8_t bDescriptorType;
		uint8_t bDescriptorSubtype;
		uint16_t bcdCDC;
	}csInterfaceDesc_t __attribute__ ((__packed__));
	
	typedef enum
	{
		STOP_1BIT = 0,
		STOP_1_5BIT,
		STOP_2BIT
	}stopBit_t;

	typedef enum
	{
		PARITY_NONE = 0,
		PARITY_ODD,
		PARITY_EVEN,
		PARITY_MARK,
		PARITY_SPACE
	}parityBit_t;

	typedef struct
	{
		uint32_t dwDTERate;
		stopBit_t bCharFormat;
		parityBit_t bParityType;
		uint8_t bDataBits;
	}lineCoding_t  __attribute__ ((__packed__));
#pragma GCC diagnostic pop

	typedef struct 
	{
		const char *manufactureString;
		const char *productString;
		const char *serialNumberString;
	}config_t;
	
	/*	
		CDC를 config_t에서 지정한 내용으로 설정합니다.
		주요 설정항목은 IN, OUT Endpoint에 관한 최대 전송 크기와 제조사, 장치명, 시리얼넘버입니다.
		.
		@ return : 에러를 반환합니다.
		.
		@ config : CDC의 구성을 설정합니다.
	*/
	virtual error_t initialize(const config_t &config) __attribute__((optimize("-O1")));

	/*	
		Host에 0번 채널을 통해 데이터를 전송합니다.
		전송 전에 반드시 isClearToSend() 함수를 호출하여 현재 Host 측에서 수신이 가능한 상태인지 확인을 하고 전송해야 합니다.
		.
		@ return : 에러를 반환합니다.
		.
		@ src : 전송할 데이터의 포인터를 설정합니다.
		@ size : 전송할 데이터의 크기를 설정합니다.
	*/
	error_t send0(void *src, uint32_t size) __attribute__((optimize("-O1")));

	/*	
		Host에 0번 채널을 통해 데이터를 전송합니다.
		전송 전에 반드시 isClearToSend() 함수를 호출하여 현재 Host 측에서 수신이 가능한 상태인지 확인을 하고 전송해야 합니다.
		.
		@ return : 에러를 반환합니다.
		.
		@ src : 전송할 데이터의 포인터를 설정합니다.
		@ size : 전송할 데이터의 크기를 설정합니다.
	*/
	error_t send0(const void *src, uint32_t size) __attribute__((optimize("-O1")));

	/*	
		Host에 1번 채널을 통해 데이터를 전송합니다.
		전송 전에 반드시 isClearToSend() 함수를 호출하여 현재 Host 측에서 수신이 가능한 상태인지 확인을 하고 전송해야 합니다.
		.
		@ return : 에러를 반환합니다.
		.
		@ src : 전송할 데이터의 포인터를 설정합니다.
		@ size : 전송할 데이터의 크기를 설정합니다.
	*/
	error_t send1(void *src, uint32_t size) __attribute__((optimize("-O1")));

	/*	
		Host에 1번 채널을 통해 데이터를 전송합니다.
		전송 전에 반드시 isClearToSend() 함수를 호출하여 현재 Host 측에서 수신이 가능한 상태인지 확인을 하고 전송해야 합니다.
		.
		@ return : 에러를 반환합니다.
		.
		@ src : 전송할 데이터의 포인터를 설정합니다.
		@ size : 전송할 데이터의 크기를 설정합니다.
	*/
	error_t send1(const void *src, uint32_t size) __attribute__((optimize("-O1")));

	/*	
		Host로부터 0번 채널로 전송받은 데이터의 크기를 얻습니다.
		전송 받은 데이터가 존재할 경우, 실제 데이터는 getRxData() 함수를 사용하여 얻습니다.
		.
		@ return : Host로부터 전송받은 데이터의 크기를 반환합니다.
	*/
	uint32_t getRxDataCount0(void) __attribute__((optimize("-O1")));

	/*	
		Host로부터 1번 채널로 전송받은 데이터의 크기를 얻습니다.
		전송 받은 데이터가 존재할 경우, 실제 데이터는 getRxData() 함수를 사용하여 얻습니다.
		.
		@ return : Host로부터 전송받은 데이터의 크기를 반환합니다.
	*/
	uint32_t getRxDataCount1(void) __attribute__((optimize("-O1")));

	/*	
		Host로부터 0번 채널로 전송받은 데이터를 얻습니다.
		.
		@ return : 에러를 반환합니다.
		.
		@ des : 전송받은 데이터를 얻을 포인터를 설정합니다.
		@ size : 전송받은 데이터의 크기를 설정합니다. 반드시 getRxDataCount() 함수에서 받은 값을 그대로 사용합니다.
	*/
	error_t getRxData0(void *des, uint32_t size) __attribute__((optimize("-O1")));

	/*	
		Host로부터 1번 채널로 전송받은 데이터를 얻습니다.
		.
		@ return : 에러를 반환합니다.
		.
		@ des : 전송받은 데이터를 얻을 포인터를 설정합니다.
		@ size : 전송받은 데이터의 크기를 설정합니다. 반드시 getRxDataCount() 함수에서 받은 값을 그대로 사용합니다.
	*/
	error_t getRxData1(void *des, uint32_t size) __attribute__((optimize("-O1")));

	/*	
		Host로부터 받은 Uart의 설정 값을 처리할 Callback 함수를 설정합니다.
		.
		@ func : Callback 함수를 설정합니다.
	*/
	void setCallbackLineCodeHandler0(void (*func)(lineCoding_t lineCode)) __attribute__((optimize("-O1")));

	/*	
		Host로부터 받은 Uart의 설정 값을 처리할 Callback 함수를 설정합니다.
		.
		@ func : Callback 함수를 설정합니다.
	*/
	void setCallbackLineCodeHandler1(void (*func)(lineCoding_t lineCode)) __attribute__((optimize("-O1")));

	/*	
		Host가 현재 데이터를 받을 준비가 되어있는지 확인하는 함수 입니다.
		send() 함수로 데이터를 전송하기 전에 반드시 확인해야 합니다.
		.
		@ return : Host로 데이터 전송이 가능한 경우 true를 반환합니다.
	*/
	bool isClearToSend0(void) __attribute__((optimize("-O1")));

	/*	
		Host가 현재 데이터를 받을 준비가 되어있는지 확인하는 함수 입니다.
		send() 함수로 데이터를 전송하기 전에 반드시 확인해야 합니다.
		.
		@ return : Host로 데이터 전송이 가능한 경우 true를 반환합니다.
	*/
	bool isClearToSend1(void) __attribute__((optimize("-O1")));

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	DualCdc(void) __attribute__((optimize("-O1")));

	virtual void handleWakeup(void) __attribute__((optimize("-O1"))); // pure

	virtual uint8_t getUsingEpCount(void) __attribute__((optimize("-O1"))); // pure

protected :
	config_t mConfig;
	lineCoding_t mLineCoding0;
	lineCoding_t mLineCoding1;
	void (*mCallback_handleLineCode0)(lineCoding_t lineCode);
	void (*mCallback_handleLineCode1)(lineCoding_t lineCode);
	uint8_t mIntInEpNum0, mBulkInEpNum0, mBulkOutEpNum0;
	uint8_t mIntInEpNum1, mBulkInEpNum1, mBulkOutEpNum1;
	bool mDte0, mRts0;
	bool mDte1, mRts1;

	void getEmptyCsInterfaceDescriptor(csInterfaceDesc_t *des) __attribute__((optimize("-O1")));

private :

	virtual void handleSetConfiguration(uint16_t value) __attribute__((optimize("-O1"))); // pure

	virtual void handleClassSpecificRequest(void) __attribute__((optimize("-O1"))); // pure
};

#endif

/* CDC 초기화 예제 코드
	같은 폴더에 있는 NuvotonCdc.h 파일을 참고하세요.
*/

/* CDC 데이터 전송 예제코드
	if(cdc.isClearToSend())						// Host가 현재 데이터를 수신받을 수 있는 상태인지 확인합니다.
	{
		cdc.send(sendBuf, len);					// Host에게 sendBuf 포인터에 담긴 데이터를 len의 크기만큼 전송합니다.
	}
*/

/* CDC 데이터 수신 예제코드

	len = cdc.getRxDataCount();					// Host로부터 전송받은 데이터의 크기를 얻습니다.
	if(len > 0)
	{
		cdc.getRxData(rcvBuf, len);				// Host로부터 전송받은 데이터를 rcvBuf로 복사해옵니다.
		for(uint32_t i = 0; i < len; i++)
			debug_printf("%c", rcvBuf[i]);		// Debug Terminal에 수신받은 문자를 출력합니다.
	}
*/