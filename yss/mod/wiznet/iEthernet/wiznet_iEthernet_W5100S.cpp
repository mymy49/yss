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
#include <mod/wiznet/W5100S.h>
#include <mod/wiznet/WiznetSocket.h>
#include <yss/reg.h>

#ifndef YSS_DRV_SPI_UNSUPPORTED

#define calculateSocketAddress(socketNum, itemAddr)		(socketNum * 0x100 + (0x400 + itemAddr))

namespace ADDR
{
enum
{
	// 공통
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

	// 소켓용
	SOCKET_MODE = 0x00,
	SOCKET_COMMAND = 0x01,
	SOCKET_INTERRUPT = 0x02,
	SOCKET_STATUS = 0x03,
	SOCKET_PORT = 0x04,
	SOCKET_DES_HW_ADDR = 0x06,
	SOCKET_DES_IP_ADDR = 0x0C,
	SOCKET_DES_PORT = 0x10,
	SOCKET_MAX_SEG_SIZE = 0x12,
	SOCKET_IP_PROTOCOL = 0x14,
	SOCKET_IP_SERVICE_TYPE = 0x15,
	SOCKET_IP_LIVE_TIME = 0x16,
	SOCKET_RX_BUF_SIZE = 0x1E,
	SOCKET_TX_BUF_SIZE = 0x1F,
	SOCKET_TX_FREE_SIZE = 0x20,
	SOCKET_TX_READ_INDEX = 0x22,
	SOCKET_TX_WRITE_INDEX = 0x24,
	SOCKET_RX_RECIEVED_SIZE = 0x26,
	SOCKET_RX_READ_INDEX = 0x28,
	SOCKET_RX_WRITE_INDEX = 0x2A,
	SOCKET_INTERRUPT_MASK = 0x2C,
	SOCKET_FRAGMENT_IP_HEADER_OFFSET = 0x2D,
	SOCKET_MODE2 = 0x2F,
	SOCKET_KEEP_ACTIVE_TIMER = 0x30,
	SOCKET_RETRANSMISSION_TIME = 0x32,
	SOCKET_RETRANSMISSION_COUNT = 0x34
};
}

enum
{
	// Protocol
	CLOSED = 0,
	TCP = 1,
	UDP = 2,
	IPRAW = 3,
	MACRAW = 4,
	
	// Command
	OPEN = 0x01,
	CONNECT = 0x04,
	SEND = 0x20,
};

inline void swap(unsigned short &data)
{
	char buf, *p = (char*)&data;
	buf = p[0];
	p[0] = p[1];
	p[1] = buf;
}

static void trigger_isr(void *var)
{
	W5100S *obj = (W5100S*)var;
	obj->isr();
}

W5100S::W5100S(void)
{
	for(int i=0;i<4;i++)
	{
		mTxBufferSize[i] = 0;
		mTxBufferBase[i] = 0;
		mRxBufferSize[i] = 0;
		mRxBufferBase[i] = 0;
		mSocket[i] = 0;
	}
}

bool W5100S::init(Config config)
{
	unsigned char reg;
	unsigned int buf;

	mSpi = &config.peri;
	mRSTn = config.RSTn;
	mINTn = config.INTn;
	mCSn = config.CSn;

	mCSn.port->setOutput(mCSn.pin, true);
	mRSTn.port->setOutput(mRSTn.pin, false);
	thread::delay(1);
	mRSTn.port->setOutput(mRSTn.pin, true);
	thread::delay(62);
	
	readRegister(ADDR::MODE, &reg, sizeof(reg));
	mInitFlag = reg == 0x03;

	if(mInitFlag)
	{
		// 기본 네트워크 정보 설정
		reg |= config.PPPoE << 3 | config.pingBlock << 4;
		writeRegister(ADDR::MODE, &reg, sizeof(reg));
		writeRegister(ADDR::RETRANSMISSION_TIME, &config.retransmissionTime, sizeof(config.retransmissionTime));
		writeRegister(ADDR::RETRANSMISSION_COUNT, &config.retransmissionCount, sizeof(config.retransmissionCount));

		// 소켓 버퍼 설정
		buf = config.rxSocketBufferSize[0] + config.rxSocketBufferSize[1] + config.rxSocketBufferSize[2] + config.rxSocketBufferSize[3];
		if(buf > 8)
			goto error;
		buf = config.txSocketBufferSize[0] + config.txSocketBufferSize[1] + config.txSocketBufferSize[2] + config.txSocketBufferSize[3];
		if(buf > 8)
			goto error;
		
		unsigned char test;
		for(int i=0;i<4;i++)
		{
			writeSocketRegister(i, ADDR::SOCKET_TX_BUF_SIZE, &config.txSocketBufferSize[i], sizeof(config.txSocketBufferSize[i]));
			mTxBufferSize[i] = config.txSocketBufferSize[i] * 1024;
			writeSocketRegister(i, ADDR::SOCKET_RX_BUF_SIZE, &config.rxSocketBufferSize[i], sizeof(config.rxSocketBufferSize[i]));
			mRxBufferSize[i] = config.rxSocketBufferSize[i] * 1024;
		}
		
		buf = 0x4000;
		mTxBufferBase[0] = buf;
		buf += mTxBufferSize[0];
		mTxBufferBase[1] = buf;
		buf += mTxBufferSize[1];
		mTxBufferBase[2] = buf;
		buf += mTxBufferSize[2];
		mTxBufferBase[3] = buf;

		buf = 0x6000;
		mRxBufferBase[0] = buf;
		buf += mRxBufferSize[0];
		mRxBufferBase[1] = buf;
		buf += mRxBufferSize[1];
		mRxBufferBase[2] = buf;
		buf += mRxBufferSize[2];
		mRxBufferBase[3] = buf;
	}

	mTriggerId = trigger::add(trigger_isr, this, 512);
	exti.add(*config.INTn.port, config.INTn.pin, define::exti::mode::FALLING, mTriggerId);
	
	return mInitFlag;

error :
	mInitFlag = false;
	return false;
}

void W5100S::writeSocketRegister(unsigned char socketNumber, unsigned short addr, void *src, int len)
{
	writeRegister(calculateSocketAddress(socketNumber, addr), src, len);
}

void W5100S::readSocketRegister(unsigned char socketNumber, unsigned short addr, void *des, int len)
{
	readRegister(calculateSocketAddress(socketNumber, addr), des, len);
}

void W5100S::setSocketDestinationIpAddress(unsigned char socketNumber, unsigned char *ip)
{
	writeRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_DES_IP_ADDR), ip, 4);
}

void W5100S::setSocketPort(unsigned char socketNumber, unsigned short port)
{
	unsigned char data[2] = {(unsigned char)(port >> 8), (unsigned char)port};
	writeRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_PORT), data, sizeof(data));
}

void W5100S::setSocketDestinationPort(unsigned char socketNumber, unsigned short port)
{
	unsigned char data[2] = {(unsigned char)(port >> 8), (unsigned char)port};
	writeRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_DES_PORT), &data, sizeof(data));
}

bool W5100S::setSocketMode(unsigned char socketNumber, unsigned char protocol, unsigned char flag)
{
	switch(protocol)
	{
	case WiznetSocket::TCP :
		protocol = TCP;
		if(flag & ~SF_TCP_NODELAY)
			return false;
		break;

	default :
		return false;
	}

	protocol |= flag & 0xF0;
	writeRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_MODE), &protocol, sizeof(protocol));

	return true;
}

bool W5100S::command(unsigned char socketNumber, unsigned char command)
{
	switch(command)
	{
	case WiznetSocket::CONNECT :
		command = CONNECT;
		break;
	case WiznetSocket::OPEN :
		command = OPEN;
		break;
	default :
		return false;
	}

	writeRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_COMMAND), &command, sizeof(command));
	while(command)
	{
		readRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_COMMAND), &command, sizeof(command));
		if(command)
			thread::yield();
	}

	return true;
}

bool W5100S::commandBypass(unsigned char socketNumber, unsigned char command)
{
	writeRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_COMMAND), &command, sizeof(command));
	while(command)
	{
		readRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_COMMAND), &command, sizeof(command));
		if(command)
			thread::yield();
	}

	return true;
}


unsigned char W5100S::getSocketCommand(unsigned char socketNumber)
{
	unsigned char command;

	readRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_COMMAND), &command, sizeof(command));

	switch(command)
	{
	case OPEN :
		command = WiznetSocket::OPEN;
		break;
	case CONNECT :
		command = WiznetSocket::CONNECT;
		break;
	}

	return command;
}

unsigned char W5100S::getSocketStatus(unsigned char socketNumber)
{
	unsigned char status;

	readRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_STATUS), &status, sizeof(status));

	switch(status)
	{
	case SOCK_INIT :
		return WiznetSocket::TCP_SOCKET_OPEN_OK;
	case SOCK_SYNSENT :
		return WiznetSocket::SOCKET_CONNECT_REQUEST_SENT;
	case SOCK_ESTABLISHED :
		return WiznetSocket::SOCKET_ESTABLISHED;
	default :
		return status;
	}

	return status;
}

bool W5100S::setSocketInterruptEnable(unsigned char socketNumber, bool enable)
{
	unsigned char reg;

	if(socketNumber > 3)
		return false;

	readRegister(ADDR::INTERRUPT_MASK, &reg, sizeof(reg));
	setBitData(reg, enable, socketNumber);
	mEnabledInteruptFlag = reg & 0x0F;
	writeRegister(ADDR::INTERRUPT_MASK, &reg, sizeof(reg));
	
	reg = 0x1F;
	writeRegister(ADDR::SOCKET_INTERRUPT_MASK, &reg, sizeof(reg));

	return true;
}

error W5100S::sendSocketData(unsigned char socketNumber, void *src, unsigned short count)
{
	if(socketNumber > 3)
		return Error::OUT_OF_RANGE;

	unsigned char *csrc = (unsigned char*)src;
	unsigned short ptr, dstMask, dstPtr, size;

	readRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_TX_WRITE_INDEX), &ptr, sizeof(ptr));
	swap(ptr);

	dstMask = ptr & mTxBufferSize[socketNumber]-1;
	dstPtr = mTxBufferBase[socketNumber] + dstMask;

	if(dstMask + count > mTxBufferSize[socketNumber])
	{
		size = mTxBufferSize[socketNumber] - dstMask;
		writeRegister(dstPtr, csrc, size);
		csrc += size;
		size = count - size;
		writeRegister(mTxBufferBase[socketNumber], csrc, size);
	}
	else
	{
		writeRegister(dstPtr, csrc, count);
	}
	
	ptr += count;
	swap(ptr);
	writeRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_TX_WRITE_INDEX), &ptr, sizeof(ptr));

	commandBypass(socketNumber, SEND);
	return Error::NONE;
}

error W5100S::receiveSocketData(unsigned char socketNumber, void *des, unsigned short count)
{
	if(socketNumber > 3)
		return Error::OUT_OF_RANGE;

	unsigned char *cdes = (unsigned char*)des;
	unsigned short ptr, dstMask, dstPtr, size;

	readRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_RX_READ_INDEX), &ptr, sizeof(ptr));
	swap(ptr);

	dstMask = ptr & mRxBufferSize[socketNumber]-1;
	dstPtr = mRxBufferBase[socketNumber] + dstMask;

	if(dstMask + count > mRxBufferSize[socketNumber])
	{
		size = mRxBufferSize[socketNumber] - dstMask;
		readRegister(dstPtr, cdes, size);
		cdes += size;
		size = count - size;
		readRegister(mRxBufferBase[socketNumber], cdes, size);
	}
	else
	{
		readRegister(dstPtr, cdes, count);
	}
	
	ptr += count;
	swap(ptr);
	writeRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_RX_READ_INDEX), &ptr, sizeof(ptr));

	commandBypass(socketNumber, SEND);
	return Error::NONE;
}

unsigned short W5100S::getTxFreeBufferSize(unsigned char socketNumber)
{
	unsigned short data;

	readRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_TX_FREE_SIZE), &data, sizeof(data));
	swap(data);

	return data;
}

unsigned short W5100S::getRxReceivedSize(unsigned char socketNumber)
{
	unsigned short data;

	readRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_RX_RECIEVED_SIZE), &data, sizeof(data));
	swap(data);

	return data;
}

void W5100S::isr(void)
{
	unsigned char shift, data, status;
	unsigned short addr;

	while(!mINTn.port->getData(mINTn.pin))
	{
		lock();
		readRegister(ADDR::INTERRUPT, &data, sizeof(data));
		unlock();

		shift = 1;
		for(unsigned char i=0;i<4;i++)
		{
			if(mEnabledInteruptFlag & shift & data)
			{
				lock();
				addr = calculateSocketAddress(i, ADDR::SOCKET_INTERRUPT);
				readRegister(addr, &data, sizeof(data));
				writeRegister(addr, &data, sizeof(data));
				unlock();

				if(mSocket[i])
				{
					mSocket[i]->lock();
					mSocket[i]->isr(data);
					mSocket[i]->unlock();
				}
			}
			shift <<= 1;
		}
	}
}

void W5100S::setSocket(unsigned char socketNumber, WiznetSocket &socket)
{
	if(socketNumber > 3)
		return;

	mSocket[socketNumber] = &socket;
}

#endif


