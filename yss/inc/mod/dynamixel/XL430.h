////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//  Home Page : http://cafe.naver.com/yssoperatingsystem
//  Copyright 2021. yss Embedded Operating System all right reserved.
//
//  주담당자 : 아이구 (mymy49@nate.com) 2021.10.23 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_MOD_DYNAMIXEL_XL430__H_
#define YSS_MOD_DYNAMIXEL_XL430__H_

class DynamixelV2;

namespace mod
{
namespace dynamixel
{
class XL430
{
	DynamixelV2 *mProtocol;
	unsigned char mId;

  public:

	enum
	{
		OPERATING_MODE_SPEED_CONTROL = 1,
		OPERATING_MODE_POSITION_CONTROL = 3,
		OPERATING_MODE_MULTI_TURN = 4,
		OPERATING_MODE_PWM = 16,
	};

	XL430(void);
	bool init(DynamixelV2 &protocol, unsigned char id);

	unsigned char getErrorCode(void);

	bool setReturnDelayTime(unsigned char delay);
	bool getReturnDelayTime(unsigned char &delay);

	bool setDriveMode(unsigned char mode);
	bool getDriveMode(unsigned char &mode);

	bool setOperatingMode(unsigned char mode);
	bool getOperatingMode(unsigned char &mode);

	bool setSecondaryId(unsigned char id);
	bool getSecondaryId(unsigned char &id);

	bool setHomingOffset(signed int offset);
	bool getHomingOffset(signed int &offset);

	bool setMovingThreshold(signed int offset);
	bool getMovingThreshold(signed int &offset);

	bool setTemperatureLimit(unsigned char temperature);
	bool getTemperatureLimit(unsigned char &temperature);

	bool setMaxVoltageLimit(unsigned short voltage);
	bool getMaxVoltageLimit(unsigned short &voltage);

	bool setMinVoltageLimit(unsigned short voltage);
	bool getMinVoltageLimit(unsigned short &voltage);

	bool setPwmLimit(unsigned short pwm);
	bool getPwmLimit(unsigned short &pwm);

	bool setVelocityLimit(unsigned short limit);
	bool getVelocityLimit(unsigned short &limit);

	bool setMaxPositionLimit(unsigned int limit);
	bool getMaxPositionLimit(unsigned int &limit);

	bool setMinPositionLimit(unsigned int limit);
	bool getMinPositionLimit(unsigned int &limit);

	bool setStartupConfiguration(unsigned char config);
	bool getStartupConfiguration(unsigned char &config);

	bool setShutdown(unsigned char shutdown);
	bool getShutdown(unsigned char &shutdown);

	bool setTorqueEnable(bool en);
	bool getTorqueEnable(bool &en);

	bool setLed(bool on);
	bool getLed(bool &on);

	bool setStatusReturnLevel(unsigned char level);
	bool getStatusReturnLevel(unsigned char &level);

	bool getRegisteredInstruction(unsigned char &instruction);

	bool getHardwareErrorStatus(signed int &status);

	bool setVelocityIgain(unsigned short gain);
	bool getVelocityIgain(unsigned short &gain);

	bool setVelocityPgain(unsigned short gain);
	bool getVelocityPgain(unsigned short &gain);

	bool setPositionDgain(unsigned short gain);
	bool getPositionDgain(unsigned short &gain);

	bool setPositionIgain(unsigned short gain);
	bool getPositionIgain(unsigned short &gain);

	bool setPositionPgain(unsigned short gain);
	bool getPositionPgain(unsigned short &gain);

	bool setFeedforward1stGain(unsigned short gain);
	bool getFeedforward1ndGain(unsigned short &gain);

	bool setFeedforward2ndGain(unsigned short gain);
	bool getFeedforward2ndGain(unsigned short &gain);

	bool setBusWatchdog(unsigned char time);
	bool getBusWatchdog(unsigned char &time);

	bool setGoalPwm(signed short pwm);
	bool getGoalPwm(signed short &pwm);

	bool setGoalVelocity(signed int velocity);
	bool getGoalVelocity(signed int &velocity);

	bool setProfileAcceleration(unsigned int value);
	bool getProfileAcceleration(unsigned int &value);

	bool setProfileVelocity(unsigned int value);
	bool getProfileVelocity(unsigned int &value);

	bool setGoalPosition(signed int position);
	bool getGoalPosition(signed int &position);

	bool getRealtimeTick(unsigned short &tick);

	bool getMoving(unsigned char &moving);

	bool getMovingStatus(unsigned char &status);

	bool getPresentPwm(unsigned short &pwm);

	bool getPresentLoad(unsigned short &load);

	bool getPresentVelocity(unsigned int &velocity);

	bool getPresentPosition(signed int &presentPosition);

	bool getVelocityTrajectory(unsigned int &value);

	bool getPositionTrajectory(unsigned int &value);

	bool getPresentInputVoltage(unsigned short &voltage);

	bool getPresentTemperature(unsigned char &temperature);

	bool getBackupReady(unsigned char &ready);

	bool setIndirectAddress(unsigned short index, unsigned short pointerAddr, unsigned char size);
	
	template <typename IndirectData>
	bool setIndirectData(unsigned short index, IndirectData data);
};
}
}

#endif