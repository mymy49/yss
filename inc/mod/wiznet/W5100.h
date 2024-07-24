/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

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
	pin_t mRSTn, mINTn, mCSn;
	bool mInitFlag;
	int32_t mTriggerId;
	uint8_t mEnabledInteruptFlag;

	void readRegister(uint16_t addr, void *des, int32_t  len);
	void writeRegister(uint16_t addr, void *src, int32_t  len);
	void writeSocketRegister(uint8_t socketNumber, uint16_t addr, void *src, int32_t  len);
	void readSocketRegister(uint8_t socketNumber, uint16_t addr, void *des, int32_t  len);

  public:
	struct config_t
	{
		Spi &peri;
		pin_t RSTn;
		pin_t INTn;
		pin_t CSn;
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

	bool initialize(config_t config);

	error_t setIpConfig(const IpConfig &config);

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

	error_t sendSocketData(uint8_t socketNumber, void *src, uint16_t count);

	uint16_t getTxFreeBufferSize(uint8_t socketNumber);

	uint16_t getRxReceivedSize(uint8_t socketNumber);
};

#endif

#endif

