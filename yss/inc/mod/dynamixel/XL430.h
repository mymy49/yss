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

#ifndef YSS_MOD_DYNAMIXEL_XL430__H_
#define YSS_MOD_DYNAMIXEL_XL430__H_

#include <protocol/Dynamixel_V2.h>

#ifndef YSS_DRV_UART_UNSUPPORTED

class XL430
{
	DynamixelV2 *mProtocol;
	unsigned char mId;
	bool mSubIdEnable;

  public:

	enum
	{
		OPERATING_MODE_SPEED_CONTROL = 1,
		OPERATING_MODE_POSITION_CONTROL = 3,
		OPERATING_MODE_MULTI_TURN = 4,
		OPERATING_MODE_PWM = 16,
	};

	XL430(void);
	bool init(DynamixelV2 &protocol, unsigned char id, bool subIdEnable = false);

	unsigned char getErrorCode(void);

	bool setEepromReturnDelayTime(unsigned char delay);
	bool getEepromReturnDelayTime(unsigned char &delay);

	bool setEepromDriveMode(unsigned char mode);
	bool getEepromDriveMode(unsigned char &mode);

	bool setEepromOperatingMode(unsigned char mode);
	bool getEepromOperatingMode(unsigned char &mode);

	bool setEepromSecondaryId(unsigned char id);
	bool getEepromSecondaryId(unsigned char &id);

	bool setEepromHomingOffset(signed int offset);
	bool getEepromHomingOffset(signed int &offset);

	bool setEepromMovingThreshold(signed int offset);
	bool getEepromMovingThreshold(signed int &offset);

	bool setEepromTemperatureLimit(unsigned char temperature);
	bool getEepromTemperatureLimit(unsigned char &temperature);

	bool setEepromMaxVoltageLimit(unsigned short voltage);
	bool getEepromMaxVoltageLimit(unsigned short &voltage);

	bool setEepromMinVoltageLimit(unsigned short voltage);
	bool getEepromMinVoltageLimit(unsigned short &voltage);

	bool setEepromPwmLimit(unsigned short pwm);
	bool getEepromPwmLimit(unsigned short &pwm);

	bool setEepromVelocityLimit(unsigned short limit);
	bool getEepromVelocityLimit(unsigned short &limit);

	bool setEepromMaxPositionLimit(unsigned int limit);
	bool getEepromMaxPositionLimit(unsigned int &limit);

	bool setEepromMinPositionLimit(unsigned int limit);
	bool getEepromMinPositionLimit(unsigned int &limit);

	bool setEepromStartupConfiguration(unsigned char config);
	bool getEepromStartupConfiguration(unsigned char &config);

	bool setEepromShutdown(unsigned char shutdown);
	bool getEepromShutdown(unsigned char &shutdown);

	bool setRamTorqueEnable(bool en);
	bool getRamTorqueEnable(bool &en);

	bool setRamLed(bool on);
	bool getRamLed(bool &on);

	bool setRamStatusReturnLevel(unsigned char level);
	bool getRamStatusReturnLevel(unsigned char &level);

	bool getRamRegisteredInstruction(unsigned char &instruction);

	bool getRamHardwareErrorStatus(signed int &status);

	bool setRamVelocityIgain(unsigned short gain);
	bool getRamVelocityIgain(unsigned short &gain);

	bool setRamVelocityPgain(unsigned short gain);
	bool getRamVelocityPgain(unsigned short &gain);

	bool setRamPositionDgain(unsigned short gain);
	bool getRamPositionDgain(unsigned short &gain);

	bool setRamPositionIgain(unsigned short gain);
	bool getRamPositionIgain(unsigned short &gain);

	bool setRamPositionPgain(unsigned short gain);
	bool getRamPositionPgain(unsigned short &gain);

	bool setRamFeedforward1stGain(unsigned short gain);
	bool getRamFeedforward1ndGain(unsigned short &gain);

	bool setRamFeedforward2ndGain(unsigned short gain);
	bool getRamFeedforward2ndGain(unsigned short &gain);

	bool setRamBusWatchdog(unsigned char time);
	bool getRamBusWatchdog(unsigned char &time);

	bool setRamGoalPwm(signed short pwm);
	bool getRamGoalPwm(signed short &pwm);

	bool setRamGoalVelocity(signed int velocity);
	bool getRamGoalVelocity(signed int &velocity);

	bool setRamProfileAcceleration(unsigned int value);
	bool getRamProfileAcceleration(unsigned int &value);

	bool setRamProfileVelocity(unsigned int value);
	bool getRamProfileVelocity(unsigned int &value);

	bool setRamGoalPosition(signed int position);
	bool getRamGoalPosition(signed int &position);

	bool getRamRealtimeTick(unsigned short &tick);

	bool getRamMoving(unsigned char &moving);

	bool getRamMovingStatus(unsigned char &status);

	bool getRamPresentPwm(unsigned short &pwm);

	bool getRamPresentLoad(unsigned short &load);

	bool getRamPresentVelocity(unsigned int &velocity);

	bool getRamPresentPosition(signed int &presentPosition);

	bool getRamVelocityTrajectory(unsigned int &value);

	bool getRamPositionTrajectory(unsigned int &value);

	bool getRamPresentInputVoltage(unsigned short &voltage);

	bool getRamPresentTemperature(unsigned char &temperature);

	bool getRamBackupReady(unsigned char &ready);

	bool setRamIndirectAddress(unsigned short index, unsigned short pointerAddr, unsigned char size);
	bool getRamIndirectAddress(unsigned short index, unsigned short &pointerAddr);
	
	template <typename IndirectData>
	bool setRamIndirectData(unsigned short index, IndirectData data)
	{
		unsigned short addr;
		unsigned char size = sizeof(data);
	
		if(index <= 28)
			addr = 224 + index - 1;
		else
			addr = 634 + index - 29;
		
		return mProtocol->write(mId, &data, addr, size);
	}
};

#endif

#endif

