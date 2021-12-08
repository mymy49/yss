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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.12.07 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#include <yss/instance.h>
#include <mod/wiznet/W5100.h>

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
		10000000,                 //unsigned int maxFreq;
		define::spi::bit::BIT8};  //unsigned char bit;

W5100::W5100(void)
{

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
	thread::delay(100);
	
	readSpi(ADDR::MODE, &reg, SIZE::MODE);
	mInitFlag = reg == 0x03;

	return mInitFlag;
}

void W5100::readSpi(unsigned short addr, void *des, int len)
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

void W5100::writeSpi(unsigned short addr, void *src, int len)
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

unsigned char W5100::getSocketLength(void)
{
	return 4;
}

bool W5100::isWorking(void)
{
	return mInitFlag;
}
