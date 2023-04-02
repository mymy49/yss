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

#include <drv/peripheral.h>
#include <mod/dynamixel/XL430.h>

#ifndef YSS_DRV_UART_UNSUPPORTED

XL430::XL430(void)
{
	mProtocol = 0;
	mId = 0xFF;
}

bool XL430::initialize(DynamixelV2 &protocol, uint8_t id, bool subIdEnable)
{
	uint8_t count = mProtocol->getCount(), index;

	mProtocol = &protocol;
	mId = id;
	mSubIdEnable = subIdEnable;

	if(subIdEnable)
		return true;

	for (int32_t  i = 0; i < count; i++)
	{
		if (mProtocol->getId(i) == id && mProtocol->getModelNumber(i) == 1060)
		{
			return true;
		}
	}

	return false;
}

uint8_t XL430:: getErrorCode(void)
{
	return mProtocol->getErrorCode();
}

bool XL430::setEepromReturnDelayTime(uint8_t delay)
{
	if(delay > 254)
		return false;
	else
		return mProtocol->write(mId, &delay, 9, 1, mSubIdEnable);
}

bool XL430::getEepromReturnDelayTime(uint8_t &delay)
{
	return mProtocol->read(mId, &delay, 9, 1);
}

bool XL430::setEepromDriveMode(uint8_t mode)
{
	mode &= 0x0E;
	return mProtocol->write(mId, &mode, 10, 1, mSubIdEnable);
}

bool XL430::getEepromDriveMode(uint8_t &mode)
{
	return mProtocol->read(mId, &mode, 10, 1);
}

bool XL430::setEepromOperatingMode(uint8_t mode)
{
	if(mode == 1 || mode == 3 || mode == 4 || mode == 16)
		return mProtocol->write(mId, &mode, 11, 1, mSubIdEnable);
	else
		return false;
}

bool XL430::getEepromOperatingMode(uint8_t &mode)
{
	return mProtocol->read(mId, &mode, 11, 1);
}

bool XL430::setEepromSecondaryId(uint8_t id)
{
	return mProtocol->write(mId, &id, 12, 1, mSubIdEnable);
}

bool XL430::getEepromSecondaryId(uint8_t &id)
{
	return mProtocol->read(mId, &id, 12, 1);
}

bool XL430::setEepromHomingOffset(int32_t offset)
{
	if(offset < -1044479 || offset > 1044479)
		return false;
	else
		return mProtocol->write(mId, &offset, 20, 4, mSubIdEnable);
}

bool XL430::getEepromHomingOffset(int32_t &offset)
{
	return mProtocol->read(mId, &offset, 20, 4);
}

bool XL430::setEepromMovingThreshold(int32_t threshold)
{
	if(threshold < -0 || threshold > 1023)
		return false;
	else
		return mProtocol->write(mId, &threshold, 24, 4, mSubIdEnable);
}

bool XL430::getEepromMovingThreshold(int32_t &threshold)
{
	return mProtocol->read(mId, &threshold, 24, 4);
}

bool XL430::setEepromTemperatureLimit(uint8_t temperature)
{
	if(temperature < -0 || temperature > 100)
		return false;
	else
		return mProtocol->write(mId, &temperature, 31, 4, mSubIdEnable);
}

bool XL430::getEepromTemperatureLimit(uint8_t &temperature)
{
	return mProtocol->read(mId, &temperature, 31, 1);
}

bool XL430::setEepromMaxVoltageLimit(uint16_t voltage)
{
	if(voltage < -60 || voltage > 140)
		return false;
	else
		return mProtocol->write(mId, &voltage, 32, 2, mSubIdEnable);
}

bool XL430::getEepromMaxVoltageLimit(uint16_t &voltage)
{
	return mProtocol->read(mId, &voltage, 32, 2);
}

bool XL430::setEepromMinVoltageLimit(uint16_t voltage)
{
	if(voltage < -60 || voltage > 140)
		return false;
	else
		return mProtocol->write(mId, &voltage, 34, 2, mSubIdEnable);
}

bool XL430::getEepromMinVoltageLimit(uint16_t &voltage)
{
	return mProtocol->read(mId, &voltage, 34, 2);
}

bool XL430::setEepromPwmLimit(uint16_t pwm)
{
	if(pwm > 885)
		return false;
	else
		return mProtocol->write(mId, &pwm, 36, 2, mSubIdEnable);
}

bool XL430::getEepromPwmLimit(uint16_t &pwm)
{
	return mProtocol->read(mId, &pwm, 36, 2);
}

bool XL430::setEepromVelocityLimit(uint16_t limit)
{
	if(limit > 1023)
		return false;
	else
		return mProtocol->write(mId, &limit, 44, 2, mSubIdEnable);

}

bool XL430::getEepromVelocityLimit(uint16_t &limit)
{
	return mProtocol->read(mId, &limit, 44, 2);
}

bool XL430::setEepromMaxPositionLimit(uint32_t limit)
{
	if(limit > 4095)
		return false;
	else
		return mProtocol->write(mId, &limit, 48, 4, mSubIdEnable);
}

bool XL430::getEepromMaxPositionLimit(uint32_t &limit)
{
	return mProtocol->read(mId, &limit, 48, 4);
}

bool XL430::setEepromMinPositionLimit(uint32_t limit)
{
	if(limit > 4095)
		return false;
	else
		return mProtocol->write(mId, &limit, 52, 4, mSubIdEnable);
}

bool XL430::getEepromMinPositionLimit(uint32_t &limit)
{
	return mProtocol->read(mId, &limit, 52, 4);
}

bool XL430::setEepromStartupConfiguration(uint8_t config)
{
	if(config > 0x03)
		return false;
	else
		return mProtocol->write(mId, &config, 60, 1, mSubIdEnable);
}

bool XL430::getEepromStartupConfiguration(uint8_t &config)
{
	return mProtocol->read(mId, &config, 60, 1);
}

bool XL430::setEepromShutdown(uint8_t shutdown)
{
	shutdown &= 0x3D;
	return mProtocol->write(mId, &shutdown, 63, 1, mSubIdEnable);
}

bool XL430::getEepromShutdown(uint8_t &shutdown)
{
	return mProtocol->read(mId, &shutdown, 63, 1);
}

bool XL430::setRamTorqueEnable(bool en)
{
	return mProtocol->write(mId, &en, 64, 1, mSubIdEnable);
}

bool XL430::getRamTorqueEnable(bool &en)
{
	return mProtocol->read(mId, &en, 64, 1);
}

bool XL430::setRamLed(bool on)
{
	return mProtocol->write(mId, &on, 65, 1, mSubIdEnable);
}

bool XL430::getRamLed(bool &on)
{
	return mProtocol->read(mId, &on, 65, 1);
}

bool XL430::setRamStatusReturnLevel(uint8_t level)
{
	if(level > 0x02)
		return false;
	else
		return mProtocol->write(mId, &level, 68, 1, mSubIdEnable);
}

bool XL430::getRamStatusReturnLevel(uint8_t &level)
{
	return mProtocol->read(mId, &level, 68, 1);
}

bool XL430::getRamRegisteredInstruction(uint8_t &instruction)
{
	return mProtocol->read(mId, &instruction, 69, 1);
}

bool XL430::getRamHardwareErrorStatus(int32_t &status)
{
	return mProtocol->read(mId, &status, 70, 1);
}

bool XL430::setRamVelocityIgain(uint16_t gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 76, 2, mSubIdEnable);
}

bool XL430::getRamVelocityIgain(uint16_t &gain)
{
	return mProtocol->read(mId, &gain, 76, 2);
}

bool XL430::setRamVelocityPgain(uint16_t gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 78, 2, mSubIdEnable);
}

bool XL430::getRamVelocityPgain(uint16_t &gain)
{
	return mProtocol->read(mId, &gain, 78, 2);
}

bool XL430::setRamPositionDgain(uint16_t gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 80, 2, mSubIdEnable);
}

bool XL430::getRamPositionDgain(uint16_t &gain)
{
	return mProtocol->read(mId, &gain, 80, 2);
}

bool XL430::setRamPositionIgain(uint16_t gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 82, 2, mSubIdEnable);
}

bool XL430::getRamPositionIgain(uint16_t &gain)
{
	return mProtocol->read(mId, &gain, 82, 2);
}

bool XL430::setRamPositionPgain(uint16_t gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 84, 2, mSubIdEnable);
}

bool XL430::getRamPositionPgain(uint16_t &gain)
{
	return mProtocol->read(mId, &gain, 84, 2);
}

bool XL430::setRamFeedforward1stGain(uint16_t gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 88, 2, mSubIdEnable);
}

bool XL430::getRamFeedforward1ndGain(uint16_t &gain)
{
	return mProtocol->read(mId, &gain, 88, 2);
}

bool XL430::setRamFeedforward2ndGain(uint16_t gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 90, 2, mSubIdEnable);
}

bool XL430::getRamFeedforward2ndGain(uint16_t &gain)
{
	return mProtocol->read(mId, &gain, 90, 2);
}

bool XL430::setRamBusWatchdog(uint8_t time)
{
	if(time < 1 || time > 127)
		return false;
	else
		return mProtocol->write(mId, &time, 98, 1, mSubIdEnable);
}

bool XL430::getRamBusWatchdog(uint8_t &time)
{
	return mProtocol->read(mId, &time, 98, 1);
}

bool XL430::setRamGoalPwm(int16_t pwm)
{
	if(pwm < -36 || pwm > 36)
		return false;
	else
		return mProtocol->write(mId, &pwm, 100, 2, mSubIdEnable);
}

bool XL430::getRamGoalPwm(int16_t &pwm)
{
	return mProtocol->read(mId, &pwm, 100, 2);
}

bool XL430::setRamGoalVelocity(int32_t velocity)
{
	if(velocity < -44 || velocity > 44)
		return false;
	else
		return mProtocol->write(mId, &velocity, 104, 4, mSubIdEnable);
}

bool XL430::getRamGoalVelocity(int32_t &velocity)
{
	return mProtocol->read(mId, &velocity, 104, 4);
}

bool XL430::setRamProfileAcceleration(uint32_t value)
{
	if(value > 32767)
		return false;
	else
		return mProtocol->write(mId, &value, 108, 4, mSubIdEnable);
}

bool XL430::getRamProfileAcceleration(uint32_t &value)
{
	return mProtocol->read(mId, &value, 108, 4);
}

bool XL430::setRamProfileVelocity(uint32_t value)
{
	if(value > 32767)
		return false;
	else
		return mProtocol->write(mId, &value, 112, 4, mSubIdEnable);
}

bool XL430::getRamProfileVelocity(uint32_t &value)
{
	return mProtocol->read(mId, &value, 112, 4);
}

bool XL430::setRamGoalPosition(int32_t position)
{
	return mProtocol->write(mId, &position, 116, 4, mSubIdEnable);
}

bool XL430::getRamGoalPosition(int32_t &position)
{
	return mProtocol->read(mId, &position, 116, 4);
}

bool XL430::getRamRealtimeTick(uint16_t &tick)
{
	return mProtocol->read(mId, &tick, 120, 2);
}

bool XL430::getRamMoving(uint8_t &moving)
{
	return mProtocol->read(mId, &moving, 122, 1);
}

bool XL430::getRamMovingStatus(uint8_t &status)
{
	return mProtocol->read(mId, &status, 123, 1);
}

bool XL430::getRamPresentPwm(uint16_t &pwm)
{
	return mProtocol->read(mId, &pwm, 124, 2);
}

bool XL430::getRamPresentLoad(uint16_t &load)
{
	return mProtocol->read(mId, &load, 126, 2);
}

bool XL430::getRamPresentVelocity(uint32_t &velocity)
{
	return mProtocol->read(mId, &velocity, 128, 4);
}

bool XL430::getRamPresentPosition(int32_t &presentPosition)
{
	return mProtocol->read(mId, &presentPosition, 132, 4);
}

bool XL430::getRamVelocityTrajectory(uint32_t &value)
{
	return mProtocol->read(mId, &value, 136, 4);
}

bool XL430::getRamPositionTrajectory(uint32_t &value)
{
	return mProtocol->read(mId, &value, 140, 4);
}

bool XL430::getRamPresentInputVoltage(uint16_t &voltage)
{
	return mProtocol->read(mId, &voltage, 144, 2);
}

bool XL430::getRamPresentTemperature(uint8_t &temperature)
{
	return mProtocol->read(mId, &temperature, 146, 1);
}

bool XL430::getRamBackupReady(uint8_t &ready)
{
	return mProtocol->read(mId, &ready, 147, 1);
}

bool XL430::setRamIndirectAddress(uint16_t index, uint16_t pointerAddr, uint8_t size)
{
	uint16_t addr;

	for(int32_t  i=0;i<size;i++)
	{
		if(index < 1 || index > 56)
			return false;

		if(index <= 28)
			addr = 168 + (index - 1) * 2;
		else
			addr = 578 + (index - 29) * 2;

		if(mProtocol->write(mId, &pointerAddr, addr, 2) == false)
			return false;
		
		addr++;
		index++;
		pointerAddr++;
	}

	return true;
}

bool XL430::getRamIndirectAddress(uint16_t index, uint16_t &pointerAddr)
{
	uint16_t addr;

	if(index < 1 || index > 56)
		return false;

	if(index <= 28)
		addr = 168 + (index - 1) * 2;
	else
		addr = 578 + (index - 29) * 2;

	return mProtocol->read(mId, &pointerAddr, addr, 2);
}

#endif

