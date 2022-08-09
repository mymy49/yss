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

#ifndef YSS_MOD_WIZNET_IETHERNET_W5100__H_
#define YSS_MOD_WIZNET_IETHERNET_W5100__H_

#include "iEhternet.h"
#include <drv/Spi.h>

#ifndef YSS_DRV_SPI_UNSUPPORTED

class W5100 : public iEthernet
{
  protected:
	Spi *mSpi;
	Gpio::Pin mRSTn, mINTn, mCSn;
	bool mInitFlag;
	signed int mThreadId;
	unsigned char mInterrupt;

	void readRegister(unsigned short addr, void *des, int len);
	void writeRegister(unsigned short addr, void *src, int len);
	void writeSocketRegister(unsigned char socketNumber, unsigned short addr, void *src, int len);
	void readSocketRegister(unsigned char socketNumber, unsigned short addr, void *des, int len);
	bool isLinkup(void);

  public:
	struct Config
	{
		Spi &peri;
		Gpio::Pin RSTn;
		Gpio::Pin INTn;
		Gpio::Pin CSn;
		bool PPPoE;
		bool pingResponse;
		unsigned short retransmissionTime;
		unsigned char retransmissionCount;
		unsigned int txSocketBufferSize;
		unsigned int rxSocketBufferSize;
	};

	enum
	{
		SF_BROAD_BLOCK = 0x40,
		SF_MULTI_BLOCK = 0x20,
		SF_IPv6_BLOCK = 0x10,
		SF_UNI_BLOCK = 0x10,
	};

	W5100(void);
	~W5100(void);
	bool init(Config config);

	error setIpConfig(const IpConfig &config);
	error getIpConfig(const IpConfig &config);

	bool isWorking(void);
	unsigned char getSocketLength(void);
	void setSocketInterruptEn(bool en);
	void setSocketDestinationIpAddress(unsigned char socketNumber, unsigned char *ip);
	void getSocketDestinationIpAddress(unsigned char socketNumber, unsigned char *ip);
	bool setSocketMode(unsigned char socketNumber, unsigned char protocol, unsigned char flag);
	void setSocketPort(unsigned char socketNumber, unsigned short port);
	bool setSocketCommand(unsigned char socketNumber, unsigned char command);
	unsigned char getSocketCommand(unsigned char socketNumber);
	unsigned char getSocketStatus(unsigned char socketNumber);
	bool setSocketInterruptEnable(unsigned char socketNumber, signed int triggerId, bool enable);
	void process(void);
};

#endif

#endif

