/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS_AUDIO10__H_
#define YSS_USB_CLASS_AUDIO10__H_

#include "UsbClass.h"
#include <yss/error.h>

class Audio10 : public UsbClass
{
public :
/* ignore some GCC warnings */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"

#pragma GCC diagnostic pop

	typedef struct 
	{
		const char *manufactureString;
		const char *productString;
		const char *serialNumberString;
	}config_t;
	
	/*	
	 *	USB Audio Class를 config_t에서 지정한 내용으로 설정합니다.
	 *	주요 설정항목은 IN, OUT Endpoint에 관한 최대 전송 크기와 제조사, 장치명, 시리얼넘버입니다.
	 *	.
	 *	@ return : 에러를 반환합니다.
	 *	.
	 *	@ config : CDC의 구성을 설정합니다.
	 */
	virtual error_t initialize(const config_t &config) __attribute__((optimize("-O1")));

	/*	
	 *	Host로부터 전송받은 데이터의 크기를 얻습니다.
	 *	전송 받은 데이터가 존재할 경우, 실제 데이터는 getRxData() 함수를 사용하여 얻습니다.
	 *	.
	 *	@ return : Host로부터 전송받은 데이터의 크기를 반환합니다.
	 */
	uint32_t getRxDataCount(void) __attribute__((optimize("-O1")));

	/*	
	 *	Host로부터 전송받은 데이터를 얻습니다.
	 *	.
	 *	@ return : 에러를 반환합니다.
	 *	.
	 *	@ des : 전송받은 데이터를 얻을 포인터를 설정합니다.
	 *	@ size : 전송받은 데이터의 크기를 설정합니다. 반드시 getRxDataCount() 함수에서 받은 값을 그대로 사용합니다.
	 */
	error_t getRxData(void *des, uint32_t size) __attribute__((optimize("-O1")));

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	Audio10(void) __attribute__((optimize("-O1")));

	virtual void handleWakeup(void) __attribute__((optimize("-O1"))); // pure

	virtual uint8_t getUsingEpCount(void) __attribute__((optimize("-O1"))); // pure

protected :
	config_t mConfig;
	uint8_t mOutEpNum, mInEpNum;
	int32_t mVolumeLeft, mVolumeRight;

private :
};

#endif

/* Audio Class 초기화 예제 코드
	같은 폴더에 있는 NuvotonAudio10.h 파일을 참고하세요.
*/

/* Audio Class 데이터 수신 예제코드

	len = audio.getRxDataCount();				// Host로부터 전송받은 데이터의 크기를 얻습니다.
	if(len > 0)
	{
		audio.getRxData(rcvBuf, len);			// Host로부터 전송받은 데이터를 rcvBuf로 복사해옵니다.
		// 수신 받은 rcvBuf에 대해 적당한 처리를 해줍니다.
	}
*/
