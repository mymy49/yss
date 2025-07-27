/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_EULER_ANGLE_2AXIS__H_
#define YSS_UTIL_EULER_ANGLE_2AXIS__H_

#include <stdint.h>
#include <yss/Thread.h>
#include <yss/error.h>
#include <util/Lpf.h>

class Accelerometer3Axis;

/*
	3축 가속도 센서를 사용한 각도 측정 유틸리티입니다.
	Z축이 중력 가속도를 받는 축으로 고정하고 roll과 pitch를 계산합니다.
	3축 가속도 센서를 사용하기 때문에 회전과 이동을 구분하지 못하는 문제로 scalar 값에 큰 변화가 있을 경우 측정을 일시 중단합니다.
	scalar가 안정되면 다시 측정을 재개하여 가벼운 움직임에서 현재 각도를 구하는데 유용합니다.
	저렴하게 간단히 구현하는데 유용한 솔루션입니다.
	.
	아래는 설정의 예입니다.
	.
	EulerAngle2Axis angle;
	.
	EulerAngle2Axis::config_t angleConfig = 
	{
		&accelerometer,					//Accelerometer3Axis *obj;
		EulerAngle2Axis::UNIT_DEGREE,	//unit_t unit;
		0.10,							//float threshold;
		4,								//float ratio;
		100								//uint32_t stableTime;
	};
	.
	angle.initialize(angleConfig);
	angle.run();
*/
class EulerAngle2Axis : public Thread
{
public :
	typedef enum
	{
		UNIT_RADIAN = 0,
		UNIT_DEGREE,
	}unit_t;

	typedef struct
	{
		Accelerometer3Axis *obj;	// 가속도 센서 객체 설정
		unit_t unit;				// 측정 단위 설정
		float threshold;			// 측정 중단 scalar 값 설정
		float ratio;				// 측정 중단 임계 scalar 값의 계산용 LPF 설정
		uint32_t stableTime;		// 측정 안정 구간에서 측정으로 진행할 임계 시간 (ms)
	}config_t;

	typedef struct
	{
		float roll;
		float pitch;
	}angle_t;
	
	EulerAngle2Axis(void);

	/*
		EulerAngle2Axis의 동작을 설정하고 초기화 합니다.
		.
		@ return : 발생한 에러를 반환합니다.
		.
		@ config : 동작 환경을 설정합니다.
	*/
	error_t initialize(config_t config);
	
	/*
		측정 결과가 업데이트 됐는지 알려주는 함수입니다.
		.
		@ return : 측정 결과가 업데이트 되었을 경우 true를 반환합니다.
	*/
	bool isUpdated(void);

	/*
		측정을 시작합니다.
		만약 이 함수가 호출되지 않을 경우 아무 동작도 일어나지 않습니다.
	*/
	void run(void);

	/*
		측정을 중단합니다.
	*/
	void stop(void);

	/*
		측정된 결과를 반환합니다.
		.
		@ return : 측정된 roll과 pitch를 반환합니다.
	*/
	angle_t getAngle(void);

private :
	Accelerometer3Axis *mObj;
	angle_t mAngle;
	uint32_t mStableTime;
	Lpf mScalar;
	float mThreshold;
	unit_t mUnit;
	bool mUpdateFlag;

	virtual void thread(void);
};

#endif

