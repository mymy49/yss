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
#include <protocol/Dynamixel_V2.h>

namespace mod
{
namespace dynamixel
{

XL430::XL430(void)
{
	mProtocol = 0;
	mId = 0xFF;
}

bool XL430::init(DynamixelV2 &protocol, unsigned char id)
{
	unsigned char count = mProtocol->getCount(), index;

	mProtocol = &protocol;
	mId = id;

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

bool XL430::setReturnDelayTime(unsigned char delay)
{
	if(delay > 254)
		return false;
	else
		return mProtocol->write(mId, &delay, 9, 1);
}

bool XL430::getReturnDelayTime(unsigned char &delay)
{
	return mProtocol->read(mId, &delay, 9, 1);
}

bool XL430::setDriveMode(unsigned char mode)
{
	mode &= 0x0E;
	return mProtocol->write(mId, &mode, 10, 1);
}

bool XL430::getDriveMode(unsigned char &mode)
{
	return mProtocol->read(mId, &mode, 10, 1);
}

bool XL430::setOperatingMode(unsigned char mode)
{
	if(mode == 1 || mode == 3 || mode == 4 || mode == 16)
		return mProtocol->write(mId, &mode, 11, 1);
	else
		return false;
}

bool XL430::getOperatingMode(unsigned char &mode)
{
	return mProtocol->read(mId, &mode, 11, 1);
}

bool XL430::setSecondaryId(unsigned char id)
{
	return mProtocol->write(mId, &id, 12, 1);
}

bool XL430::getSecondaryId(unsigned char &id)
{
	return mProtocol->read(mId, &id, 12, 1);
}

bool XL430::setHomingOffset(signed int offset)
{
	if(offset < -1044479 || offset > 1044479)
		return false;
	else
		return mProtocol->write(mId, &offset, 20, 4);
}

bool XL430::getHomingOffset(signed int &offset)
{
	return mProtocol->read(mId, &offset, 20, 4);
}

bool XL430::setMovingThreshold(signed int threshold)
{
	if(threshold < -0 || threshold > 1023)
		return false;
	else
		return mProtocol->write(mId, &threshold, 24, 4);
}

bool XL430::getMovingThreshold(signed int &threshold)
{
	return mProtocol->read(mId, &threshold, 24, 4);
}

bool XL430::setTemperatureLimit(unsigned char temperature)
{
	if(temperature < -0 || temperature > 100)
		return false;
	else
		return mProtocol->write(mId, &temperature, 31, 4);
}

bool XL430::getTemperatureLimit(unsigned char &temperature)
{
	return mProtocol->read(mId, &temperature, 31, 1);
}

bool XL430::setMaxVoltageLimit(unsigned short voltage)
{
	if(voltage < -60 || voltage > 140)
		return false;
	else
		return mProtocol->write(mId, &voltage, 32, 2);
}

bool XL430::getMaxVoltageLimit(unsigned short &voltage)
{
	return mProtocol->read(mId, &voltage, 32, 2);
}

bool XL430::setMinVoltageLimit(unsigned short voltage)
{
	if(voltage < -60 || voltage > 140)
		return false;
	else
		return mProtocol->write(mId, &voltage, 34, 2);
}

bool XL430::getMinVoltageLimit(unsigned short &voltage)
{
	return mProtocol->read(mId, &voltage, 34, 2);
}

bool XL430::setPwmLimit(unsigned short pwm)
{
	if(pwm > 885)
		return false;
	else
		return mProtocol->write(mId, &pwm, 36, 2);
}

bool XL430::getPwmLimit(unsigned short &pwm)
{
	return mProtocol->read(mId, &pwm, 36, 2);
}

bool XL430::setVelocityLimit(unsigned short limit)
{
	if(limit > 1023)
		return false;
	else
		return mProtocol->write(mId, &limit, 44, 2);

}

bool XL430::getVelocityLimit(unsigned short &limit)
{
	return mProtocol->read(mId, &limit, 44, 2);
}

bool XL430::setMaxPositionLimit(unsigned int limit)
{
	if(limit > 4095)
		return false;
	else
		return mProtocol->write(mId, &limit, 48, 4);
}

bool XL430::getMaxPositionLimit(unsigned int &limit)
{
	return mProtocol->read(mId, &limit, 48, 4);
}

bool XL430::setMinPositionLimit(unsigned int limit)
{
	if(limit > 4095)
		return false;
	else
		return mProtocol->write(mId, &limit, 52, 4);
}

bool XL430::getMinPositionLimit(unsigned int &limit)
{
	return mProtocol->read(mId, &limit, 52, 4);
}

bool XL430::setStartupConfiguration(unsigned char config)
{
	if(config > 0x03)
		return false;
	else
		return mProtocol->write(mId, &config, 60, 1);
}

bool XL430::getStartupConfiguration(unsigned char &config)
{
	return mProtocol->read(mId, &config, 60, 1);
}

bool XL430::setShutdown(unsigned char shutdown)
{
	shutdown &= 0x3D;
	return mProtocol->write(mId, &shutdown, 63, 1);
}

bool XL430::getShutdown(unsigned char &shutdown)
{
	return mProtocol->read(mId, &shutdown, 63, 1);
}

bool XL430::setTorqueEnable(bool en)
{
	return mProtocol->write(mId, &en, 64, 1);
}

bool XL430::getTorqueEnable(bool &en)
{
	return mProtocol->read(mId, &en, 64, 1);
}

bool XL430::setLed(bool on)
{
	return mProtocol->write(mId, &on, 65, 1);
}

bool XL430::getLed(bool &on)
{
	return mProtocol->read(mId, &on, 65, 1);
}

bool XL430::setStatusReturnLevel(unsigned char level)
{
	if(level > 0x02)
		return false;
	else
		return mProtocol->write(mId, &level, 68, 1);
}

bool XL430::getStatusReturnLevel(unsigned char &level)
{
	return mProtocol->read(mId, &level, 68, 1);
}

bool XL430::getRegisteredInstruction(unsigned char &instruction)
{
	return mProtocol->read(mId, &instruction, 69, 1);
}

bool XL430::getHardwareErrorStatus(signed int &status)
{
	return mProtocol->read(mId, &status, 70, 1);
}

bool XL430::setVelocityIgain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 76, 2);
}

bool XL430::getVelocityIgain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 76, 2);
}

bool XL430::setVelocityPgain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 78, 2);
}

bool XL430::getVelocityPgain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 78, 2);
}

bool XL430::setPositionDgain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 80, 2);
}

bool XL430::getPositionDgain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 80, 2);
}

bool XL430::setPositionIgain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 82, 2);
}

bool XL430::getPositionIgain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 82, 2);
}

bool XL430::setPositionPgain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 84, 2);
}

bool XL430::getPositionPgain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 84, 2);
}

bool XL430::setFeedforward1stGain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 88, 2);
}

bool XL430::getFeedforward1ndGain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 88, 2);
}

bool XL430::setFeedforward2ndGain(unsigned short gain)
{
	if(gain > 16383)
		return false;
	else
		return mProtocol->write(mId, &gain, 90, 2);
}

bool XL430::getFeedforward2ndGain(unsigned short &gain)
{
	return mProtocol->read(mId, &gain, 90, 2);
}

bool XL430::setBusWatchdog(unsigned char time)
{
	if(time < 1 || time > 127)
		return false;
	else
		return mProtocol->write(mId, &time, 98, 1);
}

bool XL430::getBusWatchdog(unsigned char &time)
{
	return mProtocol->read(mId, &time, 98, 1);
}

bool XL430::setGoalPwm(signed short pwm)
{
	if(pwm < -36 || pwm > 36)
		return false;
	else
		return mProtocol->write(mId, &pwm, 100, 2);
}

bool XL430::getGoalPwm(signed short &pwm)
{
	return mProtocol->read(mId, &pwm, 100, 2);
}

bool XL430::setGoalVelocity(signed int velocity)
{
	if(velocity < -44 || velocity > 44)
		return false;
	else
		return mProtocol->write(mId, &velocity, 104, 4);
}

bool XL430::getGoalVelocity(signed int &velocity)
{
	return mProtocol->read(mId, &velocity, 104, 4);
}

bool XL430::setProfileAcceleration(unsigned int value)
{
	if(value > 32767)
		return false;
	else
		return mProtocol->write(mId, &value, 108, 4);

}

bool XL430::getProfileAcceleration(unsigned int &value)
{
	return mProtocol->read(mId, &value, 108, 4);
}

bool XL430::setProfileVelocity(unsigned int value)
{
	if(value > 32767)
		return false;
	else
		return mProtocol->write(mId, &value, 112, 4);
}

bool XL430::getProfileVelocity(unsigned int &value)
{
	return mProtocol->read(mId, &value, 112, 4);
}

bool XL430::setGoalPosition(signed int position)
{
	return mProtocol->write(mId, &position, 116, 4);
}

bool XL430::getGoalPosition(signed int &position)
{
	return mProtocol->read(mId, &position, 116, 4);
}

bool XL430::getRealtimeTick(unsigned short &tick)
{
	return mProtocol->read(mId, &tick, 120, 2);
}

bool XL430::getMoving(unsigned char &moving)
{
	return mProtocol->read(mId, &moving, 122, 1);
}

bool XL430::getMovingStatus(unsigned char &status)
{
	return mProtocol->read(mId, &status, 123, 1);
}

bool XL430::getPresentPwm(unsigned short &pwm)
{
	return mProtocol->read(mId, &pwm, 124, 2);
}

bool XL430::getPresentLoad(unsigned short &load)
{
	return mProtocol->read(mId, &load, 126, 2);
}

bool XL430::getPresentVelocity(unsigned int &velocity)
{
	return mProtocol->read(mId, &velocity, 128, 4);
}

bool XL430::getPresentPosition(signed int &presentPosition)
{
	return mProtocol->read(mId, &presentPosition, 132, 4);
}

bool XL430::getVelocityTrajectory(unsigned int &value)
{
	return mProtocol->read(mId, &value, 136, 4);
}

bool XL430::getPositionTrajectory(unsigned int &value)
{
	return mProtocol->read(mId, &value, 140, 4);
}

bool XL430::getPresentInputVoltage(unsigned short &voltage)
{
	return mProtocol->read(mId, &voltage, 144, 2);
}

bool XL430::getPresentTemperature(unsigned char &temperature)
{
	return mProtocol->read(mId, &temperature, 146, 1);
}

bool XL430::getBackupReady(unsigned char &ready)
{
	return mProtocol->read(mId, &ready, 147, 1);
}

bool XL430::setIndirectAddress(unsigned short index, unsigned short pointerAddr, unsigned char size)
{
	unsigned short addr;

	if(index < 1 || index > 56 || addr < -64 || addr > 661)
		return false;
	else
	{
		for(int i=0;i<size;i++)
		{
			if(index <= 28)
				addr = 168 + (index - 1) * 2;
			else
				addr = 578 + (index - 29) * 2;

			if(mProtocol->write(mId, &addr, index, 2) == false)
				return false;
			
			addr++;
			index++;
		}

		return true;
	}
}

template <typename IndirectData>
bool XL430::setIndirectData(unsigned short index, IndirectData data)
{
	unsigned short addr;
	unsigned char size = sizeof(data);
	
	if(size > 4)
		return false;

	if(index <= 28)
		addr = 224 + index - 1;
	else
		addr = 634 + index - 29;

	return mProtocol->write(mId, &data, addr, size);
}

}
}