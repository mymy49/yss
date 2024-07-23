/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_WIZNET_IETHERNET_W5100S__H_
#define YSS_MOD_WIZNET_IETHERNET_W5100S__H_

#include "W5100.h"
#include <drv/Spi.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_EXTI_UNSUPPORTED)

class W5100S : public W5100
{
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

	struct config_t
	{
		Spi &peri;
		pin_t RSTn;
		pin_t INTn;
		pin_t CSn;
		bool PPPoE;
		bool pingBlock;
		uint16_t retransmissionTime;
		uint8_t retransmissionCount;
		uint8_t txSocketBufferSize[4];
		uint8_t rxSocketBufferSize[4];
	};

	W5100S(void);

	bool initialize(config_t config);

	void setSocketDestinationIpAddress(uint8_t socketNumber, uint8_t *ip);

	bool setSocketMode(uint8_t socketNumber, uint8_t mode, uint8_t flag);

	void setSocketPort(uint8_t socketNumber, uint16_t port);

	void setSocketDestinationPort(uint8_t socketNumber, uint16_t port);

	bool command(uint8_t socketNumber, uint8_t command);

	uint8_t getSocketCommand(uint8_t socketNumber);

	uint8_t getSocketStatus(uint8_t socketNumber);

	bool setSocketInterruptEnable(uint8_t socketNumber, bool enable);

	error_t sendSocketData(uint8_t socketNumber, void *src, uint16_t count);

	error_t receiveSocketData(uint8_t socketNumber, void *des, uint16_t count);

	uint16_t getTxFreeBufferSize(uint8_t socketNumber);

	uint16_t getRxReceivedSize(uint8_t socketNumber);

	void setSocket(uint8_t socketNumber, WiznetSocket &socket);

	void isr(void);

protected:
	void writeSocketRegister(uint8_t socketNumber, uint16_t addr, void *src, int32_t  len);

	void readSocketRegister(uint8_t socketNumber, uint16_t addr, void *des, int32_t  len);

	bool commandBypass(uint8_t socketNumber, uint8_t command);

private :
	uint16_t mTxBufferSize[4];
	uint16_t mTxBufferBase[4];
	uint16_t mRxBufferSize[4];
	uint16_t mRxBufferBase[4];
};

#endif

#endif

