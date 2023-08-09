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

#ifndef YSS_MOD_WIZNET_IETHERNET_W5100S__H_
#define YSS_MOD_WIZNET_IETHERNET_W5100S__H_

#include "W5100.h"
#include <drv/Spi.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_EXTI_UNSUPPORTED)

class W5100S : public W5100
{
	uint16_t mTxBufferSize[4];
	uint16_t mTxBufferBase[4];
	uint16_t mRxBufferSize[4];
	uint16_t mRxBufferBase[4];

  protected:
	void writeSocketRegister(uint8_t socketNumber, uint16_t addr, void *src, int32_t  len);
	void readSocketRegister(uint8_t socketNumber, uint16_t addr, void *des, int32_t  len);
	bool commandBypass(uint8_t socketNumber, uint8_t command);

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
		
		// Status
		SOCK_INIT = 0x13,
		SOCK_SYNSENT = 0x15,
		SOCK_ESTABLISHED = 0x17,
	};

	struct Config
	{
		Spi &peri;
		Gpio::Pin RSTn;
		Gpio::Pin INTn;
		Gpio::Pin CSn;
		bool PPPoE;
		bool pingBlock;
		uint16_t retransmissionTime;
		uint8_t retransmissionCount;
		uint8_t txSocketBufferSize[4];
		uint8_t rxSocketBufferSize[4];
	};

	W5100S(void);
	bool initialize(Config config);
	void setSocketDestinationIpAddress(uint8_t socketNumber, uint8_t *ip);
	bool setSocketMode(uint8_t socketNumber, uint8_t mode, uint8_t flag);
	void setSocketPort(uint8_t socketNumber, uint16_t port);
	void setSocketDestinationPort(uint8_t socketNumber, uint16_t port);
	bool command(uint8_t socketNumber, uint8_t command);
	uint8_t getSocketCommand(uint8_t socketNumber);
	uint8_t getSocketStatus(uint8_t socketNumber);
	bool setSocketInterruptEnable(uint8_t socketNumber, bool enable);
	error sendSocketData(uint8_t socketNumber, void *src, uint16_t count);
	error receiveSocketData(uint8_t socketNumber, void *des, uint16_t count);
	uint16_t getTxFreeBufferSize(uint8_t socketNumber);
	uint16_t getRxReceivedSize(uint8_t socketNumber);
	void setSocket(uint8_t socketNumber, WiznetSocket &socket);

	void isr(void);
};

#endif

#endif

