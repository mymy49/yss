/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_WIZNET_IETHERNET__H_
#define YSS_MOD_WIZNET_IETHERNET__H_

#include <yss/Mutex.h>
#include <yss/error.h>

class WiznetSocket;

class iEthernet : public Mutex
{
  private:
	void (*mCallbackLinkup)(bool linkup);
	int32_t  mThreadIdLinkup;

  protected:
	WiznetSocket *mSocket[4];

	virtual void readRegister(uint16_t addr, void *des, int32_t  len) = 0;
	virtual void writeRegister(uint16_t addr, void *src, int32_t  len) = 0;

	virtual void writeSocketRegister(uint8_t socketNumber, uint16_t addr, void *src, int32_t  len) = 0;
	virtual void readSocketRegister(uint8_t socketNumber, uint16_t addr, void *des, int32_t  len) = 0;

  public:
	struct IpConfig
	{
		uint8_t macAddress[6];
		uint8_t gatewayAddress[4];
		uint8_t subnetMask[4];
		uint8_t ipAddress[4];
	};
	
	iEthernet(void);
	~iEthernet(void);
	
	void setCallbackLinkup(void (*callback)(bool), uint32_t stackSize);
	void process(void);
	
	virtual error_t setIpConfig(const IpConfig &config) = 0;
	virtual bool isLinkup(void) = 0;
	virtual bool command(uint8_t socketNumber, uint8_t command) = 0;
	virtual error_t sendSocketData(uint8_t socketNumber, void *src, uint16_t count) = 0;
	virtual error_t receiveSocketData(uint8_t socketNumber, void *des, uint16_t count) = 0;
	virtual uint16_t getTxFreeBufferSize(uint8_t socketNumber) = 0;
	virtual uint16_t getRxReceivedSize(uint8_t socketNumber) = 0;
	virtual bool setSocketInterruptEnable(uint8_t socketNumber, bool enable) = 0;
	virtual void setSocket(uint8_t socketNumber, WiznetSocket &socket) = 0;
	virtual bool isWorking(void) = 0;
	virtual uint8_t getSocketLength(void) = 0;
	virtual void setSocketDestinationIpAddress(uint8_t socketNumber, uint8_t *ip) = 0;
	virtual bool setSocketMode(uint8_t socketNumber, uint8_t protocol, uint8_t flag) = 0;
	virtual void setSocketPort(uint8_t socketNumber, uint16_t port) = 0;
	virtual void setSocketDestinationPort(uint8_t socketNumber, uint16_t port) = 0;
	virtual uint8_t getSocketCommand(uint8_t socketNumber) = 0;
	virtual uint8_t getSocketStatus(uint8_t socketNumber) = 0;
};

#endif
