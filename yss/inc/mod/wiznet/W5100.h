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
//  주담당자 : 아이구 (mymy49@nate.com) 2021.10.19~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef YSS_MOD_WIZNET_IETHERNET_W5100__H_
#define YSS_MOD_WIZNET_IETHERNET_W5100__H_

#include "iEhternet.h"
#include <drv/Spi.h>

class W5100 : public iEthernet
{
  protected:
	drv::Spi *mSpi;
	config::gpio::Set mRSTn, mINTn, mCSn;
	bool mInitFlag;
	signed int mThreadId;
	unsigned char mInterrupt;

	void readRegister(unsigned short addr, void *des, int len);
	void writeRegister(unsigned short addr, void *src, int len);
	void writeSocketRegister(unsigned char socketNumber, unsigned short addr, void *src, int len);
	void readSocketRegister(unsigned char socketNumber, unsigned short addr, void *des, int len);

  public:
	struct Config
	{
		drv::Spi &peri;
		config::gpio::Set RSTn;
		config::gpio::Set INTn;
		config::gpio::Set CSn;
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

	bool isWorking(void);
	unsigned char getSocketLength(void);
	void setSocketInterruptEn(bool en);
	void setMacAddress(unsigned char *mac);
	void getMacAddress(unsigned char *mac);
	void setGatewayIpAddress(unsigned char *ip);
	void getGatewayIpAddress(unsigned char *ip);
	void setSubnetMaskAddress(unsigned char *mask);
	void getSubnetMaskAddress(unsigned char *mask);
	void setIpAddress(unsigned char *ip);
	void getIpAddress(unsigned char *ip);
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
