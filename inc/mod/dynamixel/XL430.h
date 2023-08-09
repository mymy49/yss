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

#ifndef YSS_MOD_DYNAMIXEL_XL430__H_
#define YSS_MOD_DYNAMIXEL_XL430__H_

#include <protocol/Dynamixel_V2.h>

#ifndef YSS_DRV_UART_UNSUPPORTED

class XL430
{
	DynamixelV2 *mProtocol;
	uint8_t mId;
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
	bool initialize(DynamixelV2 &protocol, uint8_t id, bool subIdEnable = false);

	uint8_t getErrorCode(void);

	bool setEepromReturnDelayTime(uint8_t delay);
	bool getEepromReturnDelayTime(uint8_t &delay);

	bool setEepromDriveMode(uint8_t mode);
	bool getEepromDriveMode(uint8_t &mode);

	bool setEepromOperatingMode(uint8_t mode);
	bool getEepromOperatingMode(uint8_t &mode);

	bool setEepromSecondaryId(uint8_t id);
	bool getEepromSecondaryId(uint8_t &id);

	bool setEepromHomingOffset(int32_t offset);
	bool getEepromHomingOffset(int32_t &offset);

	bool setEepromMovingThreshold(int32_t offset);
	bool getEepromMovingThreshold(int32_t &offset);

	bool setEepromTemperatureLimit(uint8_t temperature);
	bool getEepromTemperatureLimit(uint8_t &temperature);

	bool setEepromMaxVoltageLimit(uint16_t voltage);
	bool getEepromMaxVoltageLimit(uint16_t &voltage);

	bool setEepromMinVoltageLimit(uint16_t voltage);
	bool getEepromMinVoltageLimit(uint16_t &voltage);

	bool setEepromPwmLimit(uint16_t pwm);
	bool getEepromPwmLimit(uint16_t &pwm);

	bool setEepromVelocityLimit(uint16_t limit);
	bool getEepromVelocityLimit(uint16_t &limit);

	bool setEepromMaxPositionLimit(uint32_t limit);
	bool getEepromMaxPositionLimit(uint32_t &limit);

	bool setEepromMinPositionLimit(uint32_t limit);
	bool getEepromMinPositionLimit(uint32_t &limit);

	bool setEepromStartupConfiguration(uint8_t config);
	bool getEepromStartupConfiguration(uint8_t &config);

	bool setEepromShutdown(uint8_t shutdown);
	bool getEepromShutdown(uint8_t &shutdown);

	bool setRamTorqueEnable(bool en);
	bool getRamTorqueEnable(bool &en);

	bool setRamLed(bool on);
	bool getRamLed(bool &on);

	bool setRamStatusReturnLevel(uint8_t level);
	bool getRamStatusReturnLevel(uint8_t &level);

	bool getRamRegisteredInstruction(uint8_t &instruction);

	bool getRamHardwareErrorStatus(int32_t &status);

	bool setRamVelocityIgain(uint16_t gain);
	bool getRamVelocityIgain(uint16_t &gain);

	bool setRamVelocityPgain(uint16_t gain);
	bool getRamVelocityPgain(uint16_t &gain);

	bool setRamPositionDgain(uint16_t gain);
	bool getRamPositionDgain(uint16_t &gain);

	bool setRamPositionIgain(uint16_t gain);
	bool getRamPositionIgain(uint16_t &gain);

	bool setRamPositionPgain(uint16_t gain);
	bool getRamPositionPgain(uint16_t &gain);

	bool setRamFeedforward1stGain(uint16_t gain);
	bool getRamFeedforward1ndGain(uint16_t &gain);

	bool setRamFeedforward2ndGain(uint16_t gain);
	bool getRamFeedforward2ndGain(uint16_t &gain);

	bool setRamBusWatchdog(uint8_t time);
	bool getRamBusWatchdog(uint8_t &time);

	bool setRamGoalPwm(int16_t pwm);
	bool getRamGoalPwm(int16_t &pwm);

	bool setRamGoalVelocity(int32_t velocity);
	bool getRamGoalVelocity(int32_t &velocity);

	bool setRamProfileAcceleration(uint32_t value);
	bool getRamProfileAcceleration(uint32_t &value);

	bool setRamProfileVelocity(uint32_t value);
	bool getRamProfileVelocity(uint32_t &value);

	bool setRamGoalPosition(int32_t position);
	bool getRamGoalPosition(int32_t &position);

	bool getRamRealtimeTick(uint16_t &tick);

	bool getRamMoving(uint8_t &moving);

	bool getRamMovingStatus(uint8_t &status);

	bool getRamPresentPwm(uint16_t &pwm);

	bool getRamPresentLoad(uint16_t &load);

	bool getRamPresentVelocity(uint32_t &velocity);

	bool getRamPresentPosition(int32_t &presentPosition);

	bool getRamVelocityTrajectory(uint32_t &value);

	bool getRamPositionTrajectory(uint32_t &value);

	bool getRamPresentInputVoltage(uint16_t &voltage);

	bool getRamPresentTemperature(uint8_t &temperature);

	bool getRamBackupReady(uint8_t &ready);

	bool setRamIndirectAddress(uint16_t index, uint16_t pointerAddr, uint8_t size);
	bool getRamIndirectAddress(uint16_t index, uint16_t &pointerAddr);
	
	template <typename IndirectData>
	bool setRamIndirectData(uint16_t index, IndirectData data)
	{
		uint16_t addr;
		uint8_t size = sizeof(data);
	
		if(index <= 28)
			addr = 224 + index - 1;
		else
			addr = 634 + index - 29;
		
		return mProtocol->write(mId, &data, addr, size);
	}
};

#endif

#endif

