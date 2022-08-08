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

#ifndef YSS_MOD_WIZNET_IETHERNET_W5100S__H_
#define YSS_MOD_WIZNET_IETHERNET_W5100S__H_

#include "W5100.h"
#include <drv/Spi.h>

#ifndef YSS_DRV_SPI_UNSUPPORTED

class W5100S : public W5100
{
	signed int mTriggerIdTable[4];
  protected:
	void writeSocketRegister(unsigned char socketNumber, unsigned short addr, void *src, int len);
	void readSocketRegister(unsigned char socketNumber, unsigned short addr, void *des, int len);

  public:
	enum
	{
		BUF_SIZE_0KB = 0,
		BUF_SIZE_1KB = 1,
		BUF_SIZE_2KB = 2,
		BUF_SIZE_4KB = 4,
		BUF_SIZE_8KB = 8,
		
		// Flag
		SF_ETHER_OWN = 0x80,
		SF_IGMP_VER2 = 0x20,
		SF_TCP_NODELAY = 0x20,
		SF_MULTI_ENABLE = 0x80,
		
		// Protocol
		CLOSED = 0,
		TCP = 1,
		UDP = 2,
		IPRAW = 3,
		MACRAW = 4,
		
		// Command
		OPEN = 0x01,
		CONNECT = 0x04,

		// Status
		SOCK_INIT = 0x13,
		SOCK_SYNSENT = 0x15,
	};

	struct Config
	{
		Spi &peri;
		Gpio::Pin RSTn;
		Gpio::Pin INTn;
		Gpio::Pin CSn;
		bool PPPoE;
		bool pingBlock;
		unsigned short retransmissionTime;
		unsigned char retransmissionCount;
		unsigned char txSocketBufferSize[4];
		unsigned char rxSocketBufferSize[4];
	};

	W5100S(void);
	bool init(Config config);
	void setSocketDestinationIpAddress(unsigned char socketNumber, unsigned char *ip);
	void getSocketDestinationIpAddress(unsigned char socketNumber, unsigned char *ip);
	bool setSocketMode(unsigned char socketNumber, unsigned char mode, unsigned char flag);
	void setSocketPort(unsigned char socketNumber, unsigned short port);
	bool setSocketCommand(unsigned char socketNumber, unsigned char command);
	unsigned char getSocketCommand(unsigned char socketNumber);
	unsigned char getSocketStatus(unsigned char socketNumber);
	bool setSocketInterruptEnable(unsigned char socketNumber, signed int triggerId, bool enable);
	void process(void);
};

#endif

#endif

