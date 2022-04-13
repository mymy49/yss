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

#include <yss/instance.h>
#include <mod/wiznet/W5100.h>
#include <yss/reg.h>

#ifndef YSS_DRV_SPI_UNSUPPORTED

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
	PHY_STATUS = 0x3C,
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

static config::spi::Config gSpiConfig =
	{
		define::spi::mode::MODE0, //unsigned char mode;
		75000000,                 //unsigned int maxFreq;
		define::spi::bit::BIT8};  //unsigned char bit;

W5100::W5100(void)
{
	mThreadId = -1;
	mInterrupt = 0;
}

W5100::~W5100(void)
{
	if(mThreadId)
		thread::remove(mThreadId);
}

bool W5100::init(Config config)
{
	unsigned char reg;

	mSpi = &config.peri;
	mRSTn = config.RSTn;
	mINTn = config.INTn;
	mCSn = config.CSn;

	mCSn.port->setOutput(mCSn.pin, true);
	mRSTn.port->setOutput(mRSTn.pin, false);
	thread::delay(1);
	mRSTn.port->setOutput(mRSTn.pin, true);
	thread::delay(62);
	

	iEthernet::readRegister(ADDR::MODE, reg);
	mInitFlag = reg == 0x03;

	if(mInitFlag)
	{
		reg |= config.PPPoE << 3 | config.pingResponse << 4;
		iEthernet::writeRegister(ADDR::MODE, reg);
		iEthernet::writeRegister(ADDR::RETRANSMISSION_TIME, config.retransmissionTime);
		iEthernet::writeRegister(ADDR::RETRANSMISSION_COUNT, config.retransmissionCount);
	}

	return mInitFlag;
}

void W5100::readRegister(unsigned short addr, void *des, int len)
{
	unsigned char control[3] = {0x0F, (unsigned char)(addr >> 8), (unsigned char)addr};

	mSpi->lock();
	mSpi->setConfig(gSpiConfig);
	mSpi->enable(true);
	mCSn.port->setOutput(mCSn.pin, false);
	mSpi->send(control, 3);
	mSpi->exchange(des, len);
	mCSn.port->setOutput(mCSn.pin, true);
	mSpi->enable(false);
	mSpi->unlock();
}

void W5100::writeRegister(unsigned short addr, void *src, int len)
{
	unsigned char control[3] = {0xF0, (unsigned char)(addr >> 8), (unsigned char)addr};

	mSpi->lock();
	mSpi->setConfig(gSpiConfig);
	mSpi->enable(true);
	mCSn.port->setOutput(mCSn.pin, false);
	mSpi->send(control, 3);
	mSpi->send(src, len);
	mCSn.port->setOutput(mCSn.pin, true);
	mSpi->enable(false);
	mSpi->unlock();
}

void W5100::writeSocketRegister(unsigned char socketNumber, unsigned short addr, void *src, int len)
{

}

void W5100::readSocketRegister(unsigned char socketNumber, unsigned short addr, void *des, int len)
{

}

unsigned char W5100::getSocketLength(void)
{
	return 4;
}

bool W5100::isWorking(void)
{
	return mInitFlag;
}

void W5100::setSocketInterruptEn(bool en)
{
	unsigned char reg;

	readRegister(ADDR::INTERRUPT_MASK, &reg, SIZE::INTERRUPT_MASK);
	
	if(en)
		reg |= 0x0F;
	else
		reg &= ~0x0F;
	
	writeRegister(ADDR::INTERRUPT_MASK, &reg, SIZE::INTERRUPT_MASK);
}

void W5100::setMacAddress(unsigned char *mac)
{
	writeRegister(ADDR::SRC_HW_ADDR, mac, SIZE::SRC_HW_ADDR);
}

void W5100::getMacAddress(unsigned char *mac)
{
	readRegister(ADDR::SRC_HW_ADDR, mac, SIZE::SRC_HW_ADDR);
}

void W5100::setGatewayIpAddress(unsigned char *ip)
{
	writeRegister(ADDR::GATEWAY_ADDR, ip, SIZE::GATEWAY_ADDR);
}

void W5100::getGatewayIpAddress(unsigned char *ip)
{
	readRegister(ADDR::GATEWAY_ADDR, ip, SIZE::GATEWAY_ADDR);
}

void W5100::setSubnetMaskAddress(unsigned char *mask)
{
	writeRegister(ADDR::GATEWAY_ADDR, mask, SIZE::GATEWAY_ADDR);
}

void W5100::getSubnetMaskAddress(unsigned char *mask)
{
	readRegister(ADDR::SUBNET_MASK_ADDR, mask, SIZE::SUBNET_MASK_ADDR);
}

void W5100::setIpAddress(unsigned char *ip)
{
	writeRegister(ADDR::SRC_IP_ADDR, ip, SIZE::GATEWAY_ADDR);
}

void W5100::getIpAddress(unsigned char *ip)
{
	readRegister(ADDR::SRC_IP_ADDR, ip, SIZE::GATEWAY_ADDR);
}

void W5100::setSocketDestinationIpAddress(unsigned char socketNumber, unsigned char *ip)
{
#warning "구현 필요함"
}

void W5100::getSocketDestinationIpAddress(unsigned char socketNumber, unsigned char *ip)
{
#warning "구현 필요함"
}

bool W5100::setSocketMode(unsigned char socketNumber, unsigned char protocol, unsigned char flag)
{
#warning "구현 필요함"
	return false;
}

void W5100::setSocketPort(unsigned char socketNumber, unsigned short port)
{
#warning "구현 필요함"
}

bool W5100::setSocketCommand(unsigned char socketNumber, unsigned char command)
{
#warning "구현 필요함"
}

unsigned char W5100::getSocketCommand(unsigned char socketNumber)
{
#warning "구현 필요함"
}

unsigned char W5100::getSocketStatus(unsigned char socketNumber)
{
#warning "구현 필요함"
}

bool W5100::setSocketInterruptEnable(unsigned char socketNumber, signed int triggerId, bool enable)
{
#warning "구현 필요함"
}

void W5100::process(void)
{
#warning "구현 필요함"
}

#endif

