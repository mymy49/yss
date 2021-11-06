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
//  주담당자 : 아이구 (mymy49@nate.com) 2020.07.01 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <__cross_studio_io.h>

#include <mod/dynamixel/XL430.h>

namespace mod
{
namespace dynamixel
{

XL430::XL430(void)
{
	mProtocol = 0;
	mId = 0xFF;
}

bool XL430::init(DynamixelV2 &protocol, unsigned char id, bool subIdEnable)
{
	unsigned char count = mProtocol->getCount(), index;

	mProtocol = &protocol;
	mId = id;
	mSubIdEnable = subIdEnable;

	if(subIdEnable)
		return true;

	for (int i = 0; i < count; i++)
	{
		if (mProtocol->getId(i) == id && mProtocol->getModelNumber(i) == 1060)
		{
			return true;
		}
	}

	return false;
}

unsigned char XL430:: getErrorCode(void)
{
	return mProtocol->getErrorCode();
}

bool XL430::setEepromReturnDelayTime(unsigned char delay)
{
	if(delay > 254)
		return false;
	else
		return mProtocol->write(mId, &delay, 9, 1, mSubIdEnable);
}

bool XL430::getEepromReturnDelayTime(unsigned char &delay)
{
	return mProtocol->read(mId, &delay, 9, 1);
}

bool XL430::setEepromDriveMode(unsigned char mode)
{
	mode &= 0x0E;
	return mProtocol->write(mId, &mode, 10, 1, mSubIdEnable);
}

bool XL430::getEepromDriveMode(unsigned char &mode)
{
	return mProtocol->read(mId, &mode, 10, 1);
}

bool XL430::setEepromOperatingMode(unsigned char mode)
{
	if(mode == 1 || mode == 3 || mode == 4 || mode == 16)
		return mProtocol->write(mId, &mode, 11, 1, mSubIdEnable);
	else
		return false;
}

bool XL430::getEepromOperatingMode(unsigned char &mode)
{
	return mProtocol->read(mId, &mode, 11, 1);
}

bool XL430::setEepromSecondaryId(unsigned char id)
{
	return mProtocol->write(mId, &id, 12, 1, mSubIdEnable);
}

bool XL430::getEepromSecondaryId(unsigned char &id)
{
	return mProtocol->read(mId, &id, 12, 1);
}

bool XL430::setEepromHomingOffset(signed int offset)
{
	if(offset < -1044479 || offset > 1044479)
		return false;
	else
		return mProtocol->write(mId, &offset, 20, 4, mSubIdEnable);
}

bool XL430::getEepromHomingOffset(signed int &offset)
{
	return mProtocol->read(mId, &offset, 20, 4);
}

bool XL430::setEepromMovingThreshold(signed int threshold)
{
	if(threshold < -0 || threshold > 1023)
		return false;
	else
		return mProtocol->write(mId, &threshold, 24, 4, mSubIdEnable);
}

bool XL430::getEepromMovingThreshold(signed int &threshold)
{
	return mProtocol->read(mId, &threshold, 24, 4);
}

bool XL430::setEepromTemperatureLimit(unsigned char temperature)
{
	if(temperature < -0 || temperature > 100)
		return false;
	else
		return mProtocol->write(mId, &temperature, 31, 4, mSubIdEnable);
}

bool XL430::getEepromTemperatureLimit(unsigned char &temperature)
{
	return mProtocol->read(mId, &temperature, 31, 1);
}

bool XL430::setEepromMaxVoltageLimit(unsigned short voltage)
{
	if(voltage < -60 || voltage > 140)
		return false;
	else
		return mProtocol->write(mId, &voltage, 32, 2, mSubIdEnable);
}

bool XL430::getEepromMaxVoltageLimit(unsigned short &voltage)
{
	return mProtocol->read(mId, &voltage, 32, 2);
}

bool XL430::setEepromMinVoltageLimit(unsigned short voltage)
{
	if(voltage < -60 || voltage > 140)
		return false;
	else
		return mProtocol->write(mId, &voltage, 34, 2, mSubIdEnable);
}

bool XL430::getEepromMinVoltageLimit(unsigned short &voltage)
{
	return mProtocol->read(mId, &voltage, 34, 2);
}

bool XL430::setEepromPwmLimit(unsigned short pwm)
{
	if(pwm > 885)
		return false;
	else
		return mProtocol->write(mId, &pwm, 36, 2, mSubIdEnable);
}

bool XL430::getEepromPwmLimit(unsigned short &pwm)
{
	return mProtocol->read(mId, &pwm, 36, 2);
}

bool XL430::setEepromVelocityLimit(unsigned short limit)
{
	if(limit > 1023)
		return false;
	else
		return mProtocol->write(mId, &limit, 44, 2, mSubIdEnable);

}

bool XL430::getEepromVelocityLimit(unsigned short &limit)
{
	return mProtocol->read(mId, &limit, 44, 2);
}

bool XL430::setEepromMaxPositionLimit(unsigned int limit)
{
	if(limit > 4095)
		return false;
	else
		return mProtocol->write(mId, &limit, 48, 4, mSubIdEnable);
}

bool XL430::getEepromMaxPositionLimit(unsigned int &limit)
{
	return mProtocol->read(mId, &limit, 48, 4);
}

bool XL430::setEepromMinPositionLimit(unsigned int limit)
{
	if(limit > 4095)
		return false;
	else
		return mProtocol->write(mId, &limit, 52, 4, mSubIdEnable);
}

bool XL430::getEepromMinPositionLimit(unsigned int &limit)
{
	return mProtocol->read(mId, &limit, 52, 4);
}

bool XL430::setEepromStartupConfiguration(unsigned char config)
{
	if(config > 0x03)
		return false;
	else
		return mProtocol->write(mId, &config, 60, 1, mSubIdEnable);
}

bool XL430::getEepromStartupConfiguration(unsigned char &config)
{
	return mProtocol->read(mId, &config, 60, 1);
}

bool XL430::setEepromShutdown(unsigned char shutdown)
{
	shutdown &= 0x3D;
	return mProtocol->write(mId, &shutdown, 63, 1, mSubIdEnable);
}

bool XL430::getEepromShutdown(unsigned char &shutdown)
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

bool XL430::setRamStatusReturnLevel(unsigned char level)
{
	if(level > 0x02)
		return false;
	else
		return mProtocol->write(mId, &level, 68, 1, mSubIdEnable);
}

bool XL430::getRamStatusReturnLevel(unsigned char &level)
{
	return mProtocol->read(mId, &level, 68, 1);
}

bool XL430::getRamRegisteredInstruction(unsigned char &instruction)
{
	return mProtocol->read(mId, &instruction, 69, 1);
}

bool XL430::getRamHardwareErrorStatus(signed int &status)
{
	return mProtocol->read(mId, &status, 70, 1);
}

bool XL430::setRamVelocityIgain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 76, 2, mSubIdEnable);
}

bool XL430::getRamVelocityIgain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 76, 2);
}

bool XL430::setRamVelocityPgain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 78, 2, mSubIdEnable);
}

bool XL430::getRamVelocityPgain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 78, 2);
}

bool XL430::setRamPositionDgain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 80, 2, mSubIdEnable);
}

bool XL430::getRamPositionDgain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 80, 2);
}

bool XL430::setRamPositionIgain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 82, 2, mSubIdEnable);
}

bool XL430::getRamPositionIgain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 82, 2);
}

bool XL430::setRamPositionPgain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 84, 2, mSubIdEnable);
}

bool XL430::getRamPositionPgain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 84, 2);
}

bool XL430::setRamFeedforward1stGain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 88, 2, mSubIdEnable);
}

bool XL430::getRamFeedforward1ndGain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 88, 2);
}

bool XL430::setRamFeedforward2ndGain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 90, 2, mSubIdEnable);
}

bool XL430::getRamFeedforward2ndGain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 90, 2);
}

bool XL430::setRamBusWatchdog(unsigned char time)
{
	if(time < 1 || time > 127)
		return false;
	else
		return mProtocol->write(mId, &time, 98, 1, mSubIdEnable);
}

bool XL430::getRamBusWatchdog(unsigned char &time)
{
	return mProtocol->read(mId, &time, 98, 1);
}

bool XL430::setRamGoalPwm(signed short pwm)
{
	if(pwm < -36 || pwm > 36)
		return false;
	else
		return mProtocol->write(mId, &pwm, 100, 2, mSubIdEnable);
}

bool XL430::getRamGoalPwm(signed short &pwm)
{
	return mProtocol->read(mId, &pwm, 100, 2);
}

bool XL430::setRamGoalVelocity(signed int velocity)
{
	if(velocity < -44 || velocity > 44)
		return false;
	else
		return mProtocol->write(mId, &velocity, 104, 4, mSubIdEnable);
}

bool XL430::getRamGoalVelocity(signed int &velocity)
{
	return mProtocol->read(mId, &velocity, 104, 4);
}

bool XL430::setRamProfileAcceleration(unsigned int value)
{
	if(value > 32767)
		return false;
	else
		return mProtocol->write(mId, &value, 108, 4, mSubIdEnable);
}

bool XL430::getRamProfileAcceleration(unsigned int &value)
{
	return mProtocol->read(mId, &value, 108, 4);
}

bool XL430::setRamProfileVelocity(unsigned int value)
{
	if(value > 32767)
		return false;
	else
		return mProtocol->write(mId, &value, 112, 4, mSubIdEnable);
}

bool XL430::getRamProfileVelocity(unsigned int &value)
{
	return mProtocol->read(mId, &value, 112, 4);
}

bool XL430::setRamGoalPosition(signed int position)
{
	return mProtocol->write(mId, &position, 116, 4, mSubIdEnable);
}

bool XL430::getRamGoalPosition(signed int &position)
{
	return mProtocol->read(mId, &position, 116, 4);
}

bool XL430::getRamRealtimeTick(unsigned short &tick)
{
	return mProtocol->read(mId, &tick, 120, 2);
}

bool XL430::getRamMoving(unsigned char &moving)
{
	return mProtocol->read(mId, &moving, 122, 1);
}

bool XL430::getRamMovingStatus(unsigned char &status)
{
	return mProtocol->read(mId, &status, 123, 1);
}

bool XL430::getRamPresentPwm(unsigned short &pwm)
{
	return mProtocol->read(mId, &pwm, 124, 2);
}

bool XL430::getRamPresentLoad(unsigned short &load)
{
	return mProtocol->read(mId, &load, 126, 2);
}

bool XL430::getRamPresentVelocity(unsigned int &velocity)
{
	return mProtocol->read(mId, &velocity, 128, 4);
}

bool XL430::getRamPresentPosition(signed int &presentPosition)
{
	return mProtocol->read(mId, &presentPosition, 132, 4);
}

bool XL430::getRamVelocityTrajectory(unsigned int &value)
{
	return mProtocol->read(mId, &value, 136, 4);
}

bool XL430::getRamPositionTrajectory(unsigned int &value)
{
	return mProtocol->read(mId, &value, 140, 4);
}

bool XL430::getRamPresentInputVoltage(unsigned short &voltage)
{
	return mProtocol->read(mId, &voltage, 144, 2);
}

bool XL430::getRamPresentTemperature(unsigned char &temperature)
{
	return mProtocol->read(mId, &temperature, 146, 1);
}

bool XL430::getRamBackupReady(unsigned char &ready)
{
	return mProtocol->read(mId, &ready, 147, 1);
}

bool XL430::setRamIndirectAddress(unsigned short index, unsigned short pointerAddr, unsigned char size)
{
	unsigned short addr;

	for(int i=0;i<size;i++)
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

bool XL430::getRamIndirectAddress(unsigned short index, unsigned short &pointerAddr)
{
	unsigned short addr;

	if(index < 1 || index > 56)
		return false;

	if(index <= 28)
		addr = 168 + (index - 1) * 2;
	else
		addr = 578 + (index - 29) * 2;

	return mProtocol->read(mId, &pointerAddr, addr, 2);
}

}
}