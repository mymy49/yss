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

#include <yss/instance.h>
#include <mod/wiznet/W5100S.h>
#include <mod/wiznet/WiznetSocket.h>
#include <yss/reg.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_EXTI_UNSUPPORTED)

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
	RECV = 0x40,
};

inline void swap(uint16_t &data)
{
	int8_t buf, *p = (int8_t*)&data;
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
	for(int32_t  i=0;i<4;i++)
	{
		mTxBufferSize[i] = 0;
		mTxBufferBase[i] = 0;
		mRxBufferSize[i] = 0;
		mRxBufferBase[i] = 0;
		mSocket[i] = 0;
	}
}

bool W5100S::initialize(Config config)
{
	uint8_t reg;
	uint32_t buf;

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
		
		uint8_t test;
		for(int32_t  i=0;i<4;i++)
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
	exti.add(*config.INTn.port, config.INTn.pin, Exti::FALLING, mTriggerId);
	exti.enable(config.INTn.pin);
	
	return mInitFlag;

error :
	mInitFlag = false;
	return false;
}

void W5100S::writeSocketRegister(uint8_t socketNumber, uint16_t addr, void *src, int32_t  len)
{
	writeRegister(calculateSocketAddress(socketNumber, addr), src, len);
}

void W5100S::readSocketRegister(uint8_t socketNumber, uint16_t addr, void *des, int32_t  len)
{
	readRegister(calculateSocketAddress(socketNumber, addr), des, len);
}

void W5100S::setSocketDestinationIpAddress(uint8_t socketNumber, uint8_t *ip)
{
	writeRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_DES_IP_ADDR), ip, 4);
}

void W5100S::setSocketPort(uint8_t socketNumber, uint16_t port)
{
	uint8_t data[2] = {(uint8_t)(port >> 8), (uint8_t)port};
	writeRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_PORT), data, sizeof(data));
}

void W5100S::setSocketDestinationPort(uint8_t socketNumber, uint16_t port)
{
	uint8_t data[2] = {(uint8_t)(port >> 8), (uint8_t)port};
	writeRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_DES_PORT), &data, sizeof(data));
}

bool W5100S::setSocketMode(uint8_t socketNumber, uint8_t protocol, uint8_t flag)
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

bool W5100S::command(uint8_t socketNumber, uint8_t command)
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

bool W5100S::commandBypass(uint8_t socketNumber, uint8_t command)
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


uint8_t W5100S::getSocketCommand(uint8_t socketNumber)
{
	uint8_t command;

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

uint8_t W5100S::getSocketStatus(uint8_t socketNumber)
{
	uint8_t status;

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

bool W5100S::setSocketInterruptEnable(uint8_t socketNumber, bool enable)
{
	uint8_t reg;

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

error W5100S::sendSocketData(uint8_t socketNumber, void *src, uint16_t count)
{
	if(socketNumber > 3)
		return error::OUT_OF_RANGE;

	uint8_t *csrc = (uint8_t*)src;
	uint16_t ptr, dstMask, dstPtr, size;

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
	return error::ERROR_NONE;
}

error W5100S::receiveSocketData(uint8_t socketNumber, void *des, uint16_t count)
{
	if(socketNumber > 3)
		return error::OUT_OF_RANGE;

	uint8_t *cdes = (uint8_t*)des;
	uint16_t ptr, dstMask, dstPtr, size;

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

	commandBypass(socketNumber, RECV);
	return error::ERROR_NONE;
}

uint16_t W5100S::getTxFreeBufferSize(uint8_t socketNumber)
{
	uint16_t data;

	readRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_TX_FREE_SIZE), &data, sizeof(data));
	swap(data);

	return data;
}

uint16_t W5100S::getRxReceivedSize(uint8_t socketNumber)
{
	uint16_t data;

	readRegister(calculateSocketAddress(socketNumber, ADDR::SOCKET_RX_RECIEVED_SIZE), &data, sizeof(data));
	swap(data);

	return data;
}

void W5100S::isr(void)
{
	uint8_t shift, data, status;
	uint16_t addr;

	while(!mINTn.port->getInputData(mINTn.pin))
	{
		lock();
		readRegister(ADDR::INTERRUPT, &data, sizeof(data));
		unlock();

		shift = 1;
		for(uint8_t i=0;i<4;i++)
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

void W5100S::setSocket(uint8_t socketNumber, WiznetSocket &socket)
{
	if(socketNumber > 3)
		return;

	mSocket[socketNumber] = &socket;
}

#endif


