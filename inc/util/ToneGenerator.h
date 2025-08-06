/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_TONE_GENERATOR__H_
#define YSS_UTIL_TONE_GENERATOR__H_

#include <drv/mcu.h>
#include <stdint.h>
#include <yss/Thread.h>
#include <drv/I2s.h>

/*
	I2S 장치를 활용한 Tone Generator 입니다.
	단순히 인스턴스를 생성해서 초기화를 해주는 것으로 동작이 됩니다.
	setTargetFrequency() 함수를 사용해 생성하고자 하는 주파수를 설정하여 사용합니다.
	.
	사용의 예시는 본 헤더파일의 맨 아래에 있습니다.
*/
class ToneGenerator : protected Thread
{
public:
	ToneGenerator(I2s &obj, uint32_t bufferSize = 512);

	~ToneGenerator(void);
	
	/*
		Tone Generator의 초기화를 진행합니다.
		본 함수를 호출하기 전에 I2s 장치의 초기화가 먼저 완료되야 합니다.
		초기화가 완료된 I2s 장치로부터 파라미터를 갖고 자체 설정을 진행합니다.
	*/
	void initialize(void);
	
	/*
		생성하고자 하는 주파수를 설정합니다.
		동작중에 변경이 가능합니다.
		변경된 주파수는 이전 주파수의 한 주기가 완성된 다음 다음 주기를 생성할 때 반영됩니다.
		.
		@ freq : 생성하고자 하는 주파수를 설정합니다.
	*/
	void setTargetFrequency(float freq);

private :
	I2s *mDev;
	uint8_t *mPcmBuffer;
	uint32_t mBufferDepth, mSampleRate, mMolecule, mDenominator;
	float mTargetFrequency, mLastTargetFrequency;

	void checkTargetFrequency(void);

	virtual void thread(void);
};
/*
// 아래의 코드와 같이 I2s 장치의 인스턴스를 생성자의 인자로 설정합니다.
ToneGenerator gen(i2s3);
	
	void initializeBoard(void)
	{
		// Tone Generator 초기화 함수를 호출하여 장치의 초기화가 진행되고 동작됩니다.
		// initialize() 함수를 호출하기 전에 I2s 장치의 초기화가 먼저 완료되어야 합니다.
		// 초기화가 완료된 I2s 장치로부터 파라미터를 갖고 자체 설정을 진행합니다.
		gen.initialize();
		
		// 생성하고자 하는 주파수를 설정합니다.
		gen.setTargetFrequency(500);
	}
*/

#endif

