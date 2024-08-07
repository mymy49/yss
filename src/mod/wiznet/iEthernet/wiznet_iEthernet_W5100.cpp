/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>
#include <mod/wiznet/W5100.h>
#include <yss/reg.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_EXTI_UNSUPPORTED)

namespace ADDR
{
enum
{
	MODE = 0x00,
	GATEWAY_ADDR = 0x01,
	SUBNET_MASK_ADDR = 0x05,
	SRC_HW_ADDR = 0x09,
	SRC_IP_ADDR = 0x0F,
	INTERRUPT_PEND_TIME = 0x13,
	INTERRUPT = 0x15,
	INTERRUPT_MASK = 0x16,
	RETRANSMISSION_TIME = 0x17,
	RETRANSMISSION_COUNT = 0x19,
	RX_MEM_SIZE = 0x1A,
	TX_MEM_SIZE = 0x1B,
	INTERRUPT2 = 0x20,
	INTERRUPT2_MASK = 0x21,
	PPP_LCP_REQUEST_TIMER = 0x28,
	PPP_LCP_MAGIC_NUM = 0x29,
	UNREACHABLE_IP_ADDR = 0x2A,
	UNREACHABLE_PORT = 0x2E,
	MODE2 = 0x30,
	DES_HW_ADDR = 0x32,
	SESSION_ID_ON_PPPOE = 0x38,
	PHY_STATUS1 = 0x3C,
	PHY_STATUS2 = 0x3D,
	PHY_ADDR_VALUE = 0x3E,
	PHY_REG_ADDR = 0x3F,
	PHY_DATA_INPUT = 0x40,
	PHY_DATA_OUTPUT = 0x42,
	PHY_ACCESS = 0x44,
	PHY_DIVISION = 0x45,
	PHY_CONTROL = 0x46,
	SOCKET_LESS_CMD = 0x4C,
	SOCKET_LESS_RETRANSMISSION_TIME = 0x4D,
	SOCKET_LESS_RETRANSMISSION_COUNT = 0x4F,
	SOCKET_LESS_PEER_IP_ADDR = 0x50,
	SOCKET_LESS_PEER_HW_ADDR = 0x54,
	PING_SEQ_NUM = 0x5A,
	PING_ID = 0x5C,
	SOCKET_LESS_INTERRUPT_MASK = 0x5E,
	SOCKET_LESS_INTERRUPT = 0x5F,
	CLOCK_LOCK = 0x70,
	NETWORK_LOCK = 0x71,
	PHY_LOCK = 0x72,
	CHIP_VERSION = 0x80,
	TICK_100US_COUNTER = 0x82,
	TCNT_CLEAR = 0x88,
};
}

namespace SIZE
{
enum
{
	MODE = 1,
	GATEWAY_ADDR = 4,
	SUBNET_MASK_ADDR = 4,
	SRC_HW_ADDR = 6,
	SRC_IP_ADDR = 4,
	INT_PEND_TIME = 2,
	INTERRUPT = 1,
	INTERRUPT_MASK = 1,
	RETRANSMISSION_TIME = 2,
	RETRANSMISSION_COUNT = 1,
	RX_MEM_SIZE = 1,
	TX_MEM_SIZE = 1,
	INTERRUPT2 = 1,
	INTERRUPT2_MASK = 1,
	PPP_LCP_REQUEST_TIMER = 1,
	PPP_LCP_MAGIC_NUM = 1,
	UNREACHABLE_IP_ADDR = 4,
	UNREACHABLE_PORT = 2,
	MODE2 = 1,
	DES_HW_ADDR = 6,
	SESSION_ID_ON_PPPOE = 2,
	PHY_STATUS = 1,
	PHY_ADDR_VALUE = 1,
	PHY_REG_ADDR = 1,
	PHY_DATA_INPUT = 2,
	PHY_DATA_OUTPUT = 2,
	PHY_ACCESS = 1,
	PHY_DIVISION = 1,
	PHY_CONTROL = 2,
	SOCKET_LESS_CMD = 1,
	SOCKET_LESS_RETRANSMISSION_TIME = 2,
	SOCKET_LESS_RETRANSMISSION_COUNT = 1,
	SOCKET_LESS_PEER_IP_ADDR = 4,
	SOCKET_LESS_PEER_HW_ADDR = 6,
	PING_SEQ_NUM = 2,
	PING_ID = 2,
	SOCKET_LESS_INTERRUPT_MASK = 1,
	SOCKET_LESS_INTERRUPT = 1,
	CLOCK_LOCK = 1,
	NETWORK_LOCK = 1,
	PHY_LOCK = 1,
	CHIP_VERSION = 1,
	TICK_100US_COUNTER = 2,
	TCNT_CLEAR = 1,
};
}

static const Spi::specification_t gSpiConfig =
{
	Spi::MODE_MODE0,	//uint8_t mode;
	15000000,					//uint32_t maxFreq;
	Spi::BIT_BIT8		//uint8_t bit;
};  

W5100::W5100(void)
{
	mTriggerId = 0;
	mEnabledInteruptFlag = 0;
	mSocket[0] = 0;
}

W5100::~W5100(void)
{
	if(mTriggerId)
		thread::remove(mTriggerId);
}

bool W5100::initialize(config_t config)
{
	uint8_t reg;

	mSpi = &config.peri;
	mRSTn = config.RSTn;
	mINTn = config.INTn;
	mCSn = config.CSn;

	mCSn.port->setOutput(mCSn.pin, true);
	mRSTn.port->setOutput(mRSTn.pin, false);
	thread::delay(1);
	mRSTn.port->setOutput(mRSTn.pin, true);
	thread::delay(62);
	

	readRegister(ADDR::MODE, &reg, 1);
	mInitFlag = reg == 0x03;

	if(mInitFlag)
	{
		reg |= config.PPPoE << 3 | config.pingResponse << 4;
		iEthernet::writeRegister(ADDR::MODE, &reg, 1);
		iEthernet::writeRegister(ADDR::RETRANSMISSION_TIME, &config.retransmissionTime, sizeof(config.retransmissionTime));
		iEthernet::writeRegister(ADDR::RETRANSMISSION_COUNT, &config.retransmissionCount, sizeof(config.retransmissionCount));
	}

	return mInitFlag;
}

void W5100::readRegister(uint16_t addr, void *des, int32_t  len)
{
	uint8_t control[3] = {0x0F, (uint8_t)(addr >> 8), (uint8_t)addr};

	mSpi->lock();
	mSpi->setSpecification(gSpiConfig);
	mSpi->enable(true);
	mCSn.port->setOutput(mCSn.pin, false);
	mSpi->send(control, 3);
	mSpi->exchange(des, len);
	mCSn.port->setOutput(mCSn.pin, true);
	mSpi->enable(false);
	mSpi->unlock();
}

void W5100::writeRegister(uint16_t addr, void *src, int32_t  len)
{
	uint8_t control[3] = {0xF0, (uint8_t)(addr >> 8), (uint8_t)addr};

	mSpi->lock();
	mSpi->setSpecification(gSpiConfig);
	mSpi->enable(true);
	mCSn.port->setOutput(mCSn.pin, false);
	mSpi->send(control, 3);
	mSpi->send(src, len);
	mCSn.port->setOutput(mCSn.pin, true);
	mSpi->enable(false);
	mSpi->unlock();
}

error_t W5100::setIpConfig(const IpConfig &config)
{
	if(!mInitFlag)
		return error_t::NOT_INITIALIZED;

	writeRegister(ADDR::SRC_HW_ADDR, (void*)config.macAddress, sizeof(config.macAddress));
	writeRegister(ADDR::GATEWAY_ADDR, (void*)config.gatewayAddress, sizeof(config.gatewayAddress));
	writeRegister(ADDR::SUBNET_MASK_ADDR, (void*)config.subnetMask, sizeof(config.subnetMask));
	writeRegister(ADDR::SRC_IP_ADDR, (void*)config.ipAddress, sizeof(config.ipAddress));

	return error_t::ERROR_NONE;
}

void W5100::writeSocketRegister(uint8_t socketNumber, uint16_t addr, void *src, int32_t  len)
{
	(void)socketNumber;
	(void)addr;
	(void)src;
	(void)len;
//#warning "구현 필요함"
}

void W5100::readSocketRegister(uint8_t socketNumber, uint16_t addr, void *des, int32_t  len)
{
	(void)socketNumber;
	(void)addr;
	(void)des;
	(void)len;
//#warning "구현 필요함"
}

uint8_t W5100::getSocketLength(void)
{
	return 4;
}

bool W5100::isWorking(void)
{
	return mInitFlag;
}

bool W5100::isLinkup(void)
{
	if(mInitFlag)
	{
		uint8_t buf;
		readRegister(ADDR::PHY_STATUS1, (void*)&buf, sizeof(buf));
		if((buf & 0x81) == 0x01)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool W5100::setSocketInterruptEnable(uint8_t socketNumber, bool enable)
{
	(void)socketNumber;
	(void)enable;
//#warning "구현 필요함"
	return false;
}

void W5100::setSocketDestinationIpAddress(uint8_t socketNumber, uint8_t *ip)
{
	(void)socketNumber;
	(void)ip;
//#warning "구현 필요함"
}

bool W5100::setSocketMode(uint8_t socketNumber, uint8_t protocol, uint8_t flag)
{
	(void)socketNumber;
	(void)protocol;
	(void)flag;
//#warning "구현 필요함"
	return false;
}

void W5100::setSocketPort(uint8_t socketNumber, uint16_t port)
{
	(void)socketNumber;
	(void)port;
//#warning "구현 필요함"
}

void W5100::setSocketDestinationPort(uint8_t socketNumber, uint16_t port)
{
	(void)socketNumber;
	(void)port;
//#warning "구현 필요함"
}

bool W5100::command(uint8_t socketNumber, uint8_t command)
{
	(void)socketNumber;
	(void)command;
//#warning "구현 필요함"
	return false;
}

uint8_t W5100::getSocketCommand(uint8_t socketNumber)
{
	(void)socketNumber;
//#warning "구현 필요함"
	return 0;
}

uint8_t W5100::getSocketStatus(uint8_t socketNumber)
{
	(void)socketNumber;
//#warning "구현 필요함"
	return 0;
}

void W5100::process(void)
{
//#warning "구현 필요함"
}

error_t W5100::sendSocketData(uint8_t socketNumber, void *src, uint16_t count)
{
	(void)socketNumber;
	(void)src;
	(void)count;
//#warning "구현 필요함"
	return error_t::UNKNOWN;
}

uint16_t W5100::getTxFreeBufferSize(uint8_t socketNumber)
{
	(void)socketNumber;
//#warning "구현 필요함"
	return 0;
}

uint16_t W5100::getRxReceivedSize(uint8_t socketNumber)
{
	(void)socketNumber;
//#warning "구현 필요함"
	return 0;
}

void W5100::setSocket(uint8_t socketNumber, WiznetSocket &socket)
{
	(void)socketNumber;
	(void)socket;
//#warning "구현 필요함"
}


#endif

