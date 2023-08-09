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

#ifndef YSS_MOD_WIZNET_IETHERNET_W5100__H_
#define YSS_MOD_WIZNET_IETHERNET_W5100__H_

#include "iEhternet.h"
#include <drv/Spi.h>
#include <drv/Gpio.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_EXTI_UNSUPPORTED)

class W5100 : public iEthernet
{
  protected:
	Spi *mSpi;
	Gpio::Pin mRSTn, mINTn, mCSn;
	bool mInitFlag;
	int32_t mTriggerId;
	uint8_t mEnabledInteruptFlag;

	void readRegister(uint16_t addr, void *des, int32_t  len);
	void writeRegister(uint16_t addr, void *src, int32_t  len);
	void writeSocketRegister(uint8_t socketNumber, uint16_t addr, void *src, int32_t  len);
	void readSocketRegister(uint8_t socketNumber, uint16_t addr, void *des, int32_t  len);

  public:
	struct Config
	{
		Spi &peri;
		Gpio::Pin RSTn;
		Gpio::Pin INTn;
		Gpio::Pin CSn;
		bool PPPoE;
		bool pingResponse;
		uint16_t retransmissionTime;
		uint8_t retransmissionCount;
		uint32_t txSocketBufferSize;
		uint32_t rxSocketBufferSize;
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
	bool initialize(Config config);

	error setIpConfig(const IpConfig &config);

	bool isLinkup(void);
	bool isWorking(void);
	uint8_t getSocketLength(void);
	void setSocketDestinationIpAddress(uint8_t socketNumber, uint8_t *ip);
	bool setSocketMode(uint8_t socketNumber, uint8_t protocol, uint8_t flag);
	void setSocketPort(uint8_t socketNumber, uint16_t port);
	void setSocketDestinationPort(uint8_t socketNumber, uint16_t port);
	bool command(uint8_t socketNumber, uint8_t command);
	uint8_t getSocketCommand(uint8_t socketNumber);
	uint8_t getSocketStatus(uint8_t socketNumber);
	bool setSocketInterruptEnable(uint8_t socketNumber, bool enable);
	void setSocket(uint8_t socketNumber, WiznetSocket &socket);

	void process(void);
	error sendSocketData(uint8_t socketNumber, void *src, uint16_t count);
	uint16_t getTxFreeBufferSize(uint8_t socketNumber);
	uint16_t getRxReceivedSize(uint8_t socketNumber);


};

#endif

#endif

