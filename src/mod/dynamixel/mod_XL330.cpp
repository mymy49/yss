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
// Copyright 2024. 홍윤기 all right reserved.
//
////////////////////////////////////////////////////////////////////////////////////////

#include <drv/peripheral.h>
#include <mod/dynamixel/XL330.h>

#ifndef YSS_DRV_UART_UNSUPPORTED

XL330::XL330(Uart &uart) : DynamixelV2(uart)
{

}

error_t XL330::changeId(uint8_t id)
{
	error_t result;
	uint8_t id_ = id;
	uint16_t len = 1;

	result = write(EEP_ID, &id, len);
	if(result == error_t::ERROR_NONE)
		setId(id_);
	
	return result;
}

error_t XL330::setCurrentLimit(uint16_t current)
{
	uint16_t len = 2;

	return write(EEP_CURRENT_LIMIT, &current, len);
}

error_t XL330::getCurrentLimit(uint16_t &current)
{
	uint16_t len = 2;

	return read(EEP_CURRENT_LIMIT, &current, len);
}

error_t XL330::setTorqueEnable(bool en)
{
	uint16_t len = 1;

	return write(RAM_TORQUE_ENABLE, &en, len);
}

error_t XL330::getTorqueEnable(bool &en)
{
	uint16_t len = 1;

	return read(RAM_TORQUE_ENABLE, &en, len);
}

error_t XL330::setLed(bool en)
{
	uint16_t len = 1;

	return write(RAM_LED, &en, len);
}

error_t XL330::getLed(bool &en)
{
	uint16_t len = 1;

	return read(RAM_LED, &en, len);
}

error_t XL330::setProfileVelocity(uint16_t value)
{
	uint16_t len = 2;

	return write(RAM_PROFILE_VELOCITY, &value, len);
}

error_t XL330::getProfileVelocity(uint16_t &value)
{
	uint16_t len = 2;

	return read(RAM_PROFILE_VELOCITY, &value, len);
}

error_t XL330::setProfileAcceleration(uint16_t value)
{
	uint16_t len = 2;

	return write(RAM_PROFILE_ACCELERATION, &value, len);
}

error_t XL330::getProfileAcceleration(uint16_t &value)
{
	uint16_t len = 2;

	return read(RAM_PROFILE_ACCELERATION, &value, len);
}

error_t XL330::setGoalPosition(int32_t position)
{
	uint16_t len = 4;

	return write(RAM_GOAL_POSITION, &position, len);
}

error_t XL330::getGoalPosition(int32_t &position)
{
	uint16_t len = 4;

	return read(RAM_GOAL_POSITION, &position, len);
}

#endif

