/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <yss/instance.h>
#include <mod/wiznet/WizFi360.h>
#include <yss/thread.h>
#include <yss/debug.h>
#include <util/Timeout.h>
#include <std_ext/string.h>
#include <stdio.h>

static const char *gNewlineCode = "\r\n";

static void thread_process(void *var)
{
	WizFi360 *obj = (WizFi360*)var;
	obj->process();
}

WizFi360::WizFi360(void)
{
	mId = thread::add(thread_process, this, 1024);
	mDestination = 0;
	mConnectedFlag = false;
	mIpFlag = false;
	mSocketConnectedFlag = false;
	callbackConnect = 0;
	callbackError = 0;
	memset(mApInfo, 0, sizeof(mApInfo));
}

WizFi360::~WizFi360(void)
{
	clearApInformation();
	thread::remove(mId);
}

error_t WizFi360::initialize(void)
{
	Timeout timeout(1000);
	error_t rt;

	rt = test();
	if(rt != error_t::ERROR_NONE)
		return rt;

	rt = restart();
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	while(!mReadyFlag)
	{
		if(timeout.isTimeout())
		{
			return error_t::TIMEOUT;
		}

		thread::yield();
	}

	return error_t::ERROR_NONE;
}

error_t WizFi360::sendCommand(const char *data)
{
	error_t rt;
	uint8_t len = strlen(data);
	
	mResult = RESULT::WORKING;

	rt = send((void*)data, len);
	if(rt != error_t::ERROR_NONE)
		return rt;

	return send((void*)gNewlineCode, 2);
}

error_t WizFi360::sendCommand(const char *data, uint32_t value)
{
	error_t rt;
	char buf[10];
	uint8_t len = strlen(data);
	
	mResult = RESULT::WORKING;

	rt = send((void*)data, len);
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	sprintf(buf, "%d", (int)value);
	len = strlen(buf);
	rt = send((void*)buf, len);
	if(rt != error_t::ERROR_NONE)
		return rt;

	return send((void*)gNewlineCode, 2);
}

error_t WizFi360::sendCommand(const char *data, uint32_t value1, uint32_t value2)
{
	error_t rt;
	char buf[10];
	uint8_t len = strlen(data);
	
	mResult = RESULT::WORKING;

	rt = send((void*)data, len);
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	sprintf(buf, "%d,", (int)value1);
	len = strlen(buf);
	rt = send((void*)buf, len);
	if(rt != error_t::ERROR_NONE)
		return rt;

	sprintf(buf, "%d", (int)value2);
	len = strlen(buf);
	rt = send((void*)buf, len);
	if(rt != error_t::ERROR_NONE)
		return rt;

	return send((void*)gNewlineCode, 2);
}

error_t WizFi360::sendCommand(const char *data, const char *value1, const char *value2)
{
	error_t rt;
	char buf[35];
	uint8_t len = strlen(data);
	
	mResult = RESULT::WORKING;

	rt = send((void*)data, len);
	if(rt != error_t::ERROR_NONE)
		return rt;

	buf[0] = '"';
	len = strlen(value1);
	memcpy(&buf[1], value1, len);
	buf[len+1] = '"';
	buf[len+2] = ',';
	len += 3;
	rt = send((void*)buf, len);
	if(rt != error_t::ERROR_NONE)
		return rt;

	buf[0] = '"';
	len = strlen(value2);
	memcpy(&buf[1], value2, len);
	buf[len+1] = '"';
	len += 2;
	rt = send((void*)buf, len);
	if(rt != error_t::ERROR_NONE)
		return rt;

	return send((void*)gNewlineCode, 2);
}

error_t WizFi360::waitUntilComplete(uint32_t timeout)
{
	mTimeout.reset();
	while(1)
	{
		if(mTimeout.getMsec() >= timeout)
			return error_t::TIMEOUT;
		
		if(mResult != RESULT::WORKING)
		{
			switch(mResult)
			{
			case RESULT::BUSY :
				return error_t::BUSY;

			case RESULT::ERROR :
			default :
				return error_t::UNKNOWN;

			case RESULT::TIMEOUT :
				return error_t::TIMEOUT;
			
			case RESULT::SEND_OK :			
			case RESULT::COMPLETE :
				return error_t::ERROR_NONE;
			
			case RESULT::FAIL :
				return error_t::FAIL;
			}
		}
	}
}

error_t WizFi360::test(void)
{
	error_t rt;
	
	mCommand = CMD::TEST;
	rt = sendCommand("AT");
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return 	waitUntilComplete(1000);
}

error_t WizFi360::restart(void)
{
	error_t rt;
	
	mCommand = CMD::RESTART;
	rt = sendCommand("AT+RST");
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return 	waitUntilComplete(1000);
}

error_t WizFi360::getVersion(char *des)
{
	error_t rt;
	
	mCommand = CMD::GET_VERSION;
	mDestination = des;

	rt = sendCommand("AT+GMR");
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return 	waitUntilComplete(1000);
}

error_t WizFi360::updateApInformation(void)
{
	error_t rt;
	
	mCommand = CMD::UPDATE_AP_INFO;
	clearApInformation();

	rt = sendCommand("AT+CWLAP");
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return 	waitUntilComplete(30000);
}

uint8_t WizFi360::getApCount(void)
{
	return mApCount;
}

WizFi360::ApInfo* WizFi360::getApInfo(uint8_t index)
{
	if(index < mApCount)
		return mApInfo[index];
	else
		return 0;
}

void WizFi360::clearApInformation(void)
{
	for(uint8_t i=0;i<32;i++)
	{
		if(mApInfo[i])
		{
			delete mApInfo[i];
			mApInfo[i] = 0;
		}
	}

	mApCount = 0;
}

error_t WizFi360::setMode(uint8_t mode)
{
	error_t rt;
	
	mCommand = CMD::SET_MODE_CUR;
	rt = sendCommand("AT+CWMODE_CUR=", (uint32_t)mode);
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return 	waitUntilComplete(1000);
}

error_t WizFi360::enableMultipleConnection(bool en)
{
	error_t rt;
	
	mCommand = CMD::EN_MULTI_CONN;
	rt = sendCommand("AT+CIPMUX=", (uint32_t)en);
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return 	waitUntilComplete(1000);
}

error_t WizFi360::enableDhcp(uint8_t mode, bool en)
{
	error_t rt;
	
	switch(mode)
	{
	case MODE::SOFT_AP :
		mode = 0;
		break;
	
	case MODE::STATION :
		mode = 1;
		break;

	case MODE::STATION_SOFT_AP :
		mode = 2;
		break;

	default :
		return error_t::WRONG_CONFIG;
	}

	mCommand = CMD::EN_DHCP_CUR;
	rt = sendCommand("AT+CWDHCP_CUR=", (uint32_t)mode, (uint32_t)en);
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return 	waitUntilComplete(1000);
}

error_t WizFi360::connect(char *ssid, char *passwd)
{
	error_t rt;
	
	mCommand = CMD::CONNECT;
	rt = sendCommand("AT+CWJAP_CUR=", ssid, passwd);
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return 	waitUntilComplete(60000);
}

error_t WizFi360::disconnect(void)
{
	error_t rt;
	
	mCommand = CMD::DISCONNECT;
	rt = sendCommand("AT+CWQAP");
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	rt = waitUntilComplete(5000);
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return error_t::ERROR_NONE;
}

error_t WizFi360::getIp(Ip &ip)
{
	error_t rt;
	
	mCommand = CMD::GET_CUR_IP;
	mDestination = &ip;
	rt = sendCommand("AT+CIPSTA_CUR?");
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	rt = waitUntilComplete(1000);
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return error_t::ERROR_NONE;
}

error_t WizFi360::getGateway(Ip &ip)
{
	error_t rt;
	
	mCommand = CMD::GET_CUR_GATEWAY;
	mDestination = &ip;
	rt = sendCommand("AT+CIPSTA_CUR?");
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	rt = waitUntilComplete(1000);
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return error_t::ERROR_NONE;
}

error_t WizFi360::getNetmask(Ip &ip)
{
	error_t rt;
	
	mCommand = CMD::GET_CUR_NETMASK;
	mDestination = &ip;
	rt = sendCommand("AT+CIPSTA_CUR?");
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	rt = waitUntilComplete(1000);
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return error_t::ERROR_NONE;
}

error_t WizFi360::connectToTcpServer(Ip ip, uint16_t port)
{
	error_t rt;
	char str[64];
	
	sprintf(str, "AT+CIPSTART=\"TCP\",\"%d.%d.%d.%d\",%d", ip.addr1, ip.addr2, ip.addr3, ip.addr4, port);
	mCommand = CMD::CONNECT_TCP_SERVER;
	rt = sendCommand(str);
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return 	waitUntilComplete(3000);
}

error_t WizFi360::enterTransparentTransmissionMode(bool en)
{
	error_t rt;

	if(en && !mTransparentTransmissionModeFlag && mSocketConnectedFlag)
	{
		mCommand = CMD::SEND_BUF;
		rt = sendCommand("AT+CIPMODE=1");
		if(rt != error_t::ERROR_NONE)
			return rt;
	
		rt = waitUntilComplete(1000);
		if(rt != error_t::ERROR_NONE)
			return rt;

		mCommand = CMD::ENTER_TRANSPARENT_TRANSMISSION_MODE;
		rt = sendCommand("AT+CIPSEND");
		if(rt != error_t::ERROR_NONE)
			return rt;

		rt = waitUntilComplete(10000);
		if(rt != error_t::ERROR_NONE)
			return rt;
	}
	else if(!en)
	{
		thread::delay(100);
		send((void*)"+++", 3);
		mTransparentTransmissionModeFlag = false;
		thread::delay(100);
	}

	return error_t::ERROR_NONE;
}

error_t WizFi360::close(void)
{
	error_t rt;
	
	mCommand = CMD::CLOSE;
	rt = sendCommand("AT+CIPCLOSE");
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	rt = waitUntilComplete(5000);
	if(rt != error_t::ERROR_NONE)
		return rt;
	
	return error_t::ERROR_NONE;
}

void WizFi360::setCallbackError(void (*func)(uint8_t))
{
	callbackError = func;
}

void WizFi360::setCallbackConnect(void (*func)(bool))
{
	callbackConnect = func;
}

bool WizFi360::isConnected(void)
{
	return mConnectedFlag;
}

bool WizFi360::isGotIp(void)
{
	return mIpFlag;
}

bool WizFi360::isSocketConnected(void)
{
	return mSocketConnectedFlag;
}

void WizFi360::process(void)
{
	volatile char *src;
	int16_t data;
	
	while(1)
	{
		mIndex = 0;

		while(1)
		{
			data = getRxByte();
			if(data >= 0)
			{
				mDataBuf[mIndex++] = data;

				if(mIndex >= 64)
					mIndex = 0;
				else if(data == 0x0A || data == '>')
				{
					mDataBuf[mIndex++] = 0;
					break;
				}
			}
			else
				thread::yield();
		}

		src = mDataBuf;
		switch(*src++)
		{
		case 'r' :
			if(	*src++ != 'e' ||
				*src++ != 'a' || 
				*src++ != 'd' || 
				*src++ != 'y' || 
				*src++ != 0x0D || 
				*src++ != 0x0A)
				break;
			mReadyFlag = true;
			break;

		case '>' :
			if(	*src++ != 0)
				break;
		 
			mResult = RESULT::COMPLETE;
			if(mCommand == CMD::ENTER_TRANSPARENT_TRANSMISSION_MODE)
			{
				mTransparentTransmissionModeFlag = true;
				while(mTransparentTransmissionModeFlag)
					thread::yield();
			}
			break;

		case 'O' :
			if(	*src++ != 'K' || 
				*src++ != 0x0D || 
				*src++ != 0x0A)
				break;

			mResult = RESULT::COMPLETE;
			break;

		case 'E' :
			if(	*src++ != 'R' ||
				*src++ != 'R' || 
				*src++ != 'O' || 
				*src++ != 'R' || 
				*src++ != 0x0D || 
				*src++ != 0x0A)
				break;
			
			mResult = RESULT::ERROR;
			if(callbackError)
				callbackError(mCommand);
			break;

		case 'S' :
			interpret_S(src);
			break;

		case '+' :
			interpret_plus(src);
			break;

		case 'W' :
			interpret_W(src);
			break;

		case 'C' :
			interpret_C(src);
			break;

		case 'b' :
			if(	*src++ != 'u' ||
				*src++ != 's' ||
				*src++ != 'y')
				break;
			
			mResult = RESULT::BUSY;
			break;
		case 'F' :
			if(	*src++ != 'A' ||
				*src++ != 'I' ||
				*src++ != 'L')
				break;
			
			mResult = RESULT::FAIL;
			break;
		}
	}
}

void WizFi360::interpret_S(volatile char *src)
{
	int16_t len;

	switch(*src++)
	{
	case 'E' :
		if(	*src++ != 'N' ||
			*src++ != 'D' ||
			*src++ != ' ' ||
			*src++ != 'O' ||
			*src++ != 'K')
			break;
	
		mResult = RESULT::SEND_OK;
		break;
	
	case 'D' :
		if(	*src++ != 'K' || 
			*src++ != ' ' || 
			*src++ != 'v' || 
			*src++ != 'e' || 
			*src++ != 'r' || 
			*src++ != 's' || 
			*src++ != 'i' || 
			*src++ != 'o' || 
			*src++ != 'n' || 
			*src++ != ':')
			break;

		for(int i=0;i<64;i++)
		{
			if(src[i] == '\n')
				src[i] = 0;
		}
		len = strlen((char*)src);
		memcpy(mDestination, (char*)src, len);
		*(char*)mDestination += len;
		*(char*)mDestination = 0;
		break;
	}
}

void WizFi360::interpret_plus(volatile char *src)
{
	uint32_t len;
	char buf[8];

	switch(*src++)
	{
	case 'C' :
		switch(*src++)
		{
		case 'W' :
			if(	*src++ != 'L' || 
				*src++ != 'A' || 
				*src++ != 'P' || 
				*src++ != ':' || 
				*src++ != '(')
				break;

			if(mCommand == UPDATE_AP_INFO)
			{
				if(mApInfo[mApCount] == 0)
				{
					mApInfo[mApCount] = new ApInfo;
					mApInfo[mApCount]->ssid[32] = 0;
				}

				mApInfo[mApCount]->encryptionMethod = *src++ - '0';
				if(	*src++ != ',' ||
					*src++ != '"')
					break;

				for(int i=0;i<32;i++)
				{
					if(*src == '"')
					{
						src++;
						mApInfo[mApCount]->ssid[i] = 0;
						break;
					}
					mApInfo[mApCount]->ssid[i] = *src++;
				}

				if(*src++ != ',')
					break;

				sscanf((char*)src, "%d", (int*)buf);
				mApInfo[mApCount]->rssi = *(int32_t*)buf;
				for(int i=0;i<4;i++)
				{
					if(*src == ',')
						break;
			
					src++;
				}

				if(	*src++ != ',' ||
					*src++ != '"')
					break;

				for(int i=0;i<6;i++)
				{
					sscanf((char*)src, "%02x", (int*)buf);
					mApInfo[mApCount]->mac[i] = *(int*)buf;
					src += 3;
				}

				if(*src++ != ',')
					break;

				sscanf((char*)src, "%d", (int*)buf);
				mApInfo[mApCount]->channel = *(int*)buf;
				for(int i=0;i<3;i++)
				{
					if(*src == ',')
						break;
			
					src++;
				}

				if(*src++ != ',')
					break;

				sscanf((char*)src, "%d", (int*)buf);
				mApInfo[mApCount]->wps = *(int*)buf;

				for(int i=0;i<3;i++)
				{
					if(*src == ')')
						break;
			
					src++;
				}

				if(*src++ != ')')
					break;

				mApCount++;
			}
			break;

		case 'I' :
			if(	*src++ != 'P' || 
				*src++ != 'S' || 
				*src++ != 'T' || 
				*src++ != 'A' || 
				*src++ != '_' || 
				*src++ != 'C' || 
				*src++ != 'U' || 
				*src++ != 'R' || 
				*src++ != ':')
				break;
			switch(*src++)
			{
			case 'i' :
				if(	mCommand != CMD::GET_CUR_IP ||
					*src++ != 'p' || 
					*src++ != ':' || 
					*src++ != '"')
					break;
				sscanf((char*)src, "%d", (int*)&((Ip*)mDestination)->addr1);

				for(int i=0;i<4;i++)
				{
					if(*src == '.')
						break;
			
					src++;
				}

				if(*src++ != '.')
					break;

				sscanf((char*)src, "%d", (int*)&((Ip*)mDestination)->addr2);

				for(int i=0;i<4;i++)
				{
					if(*src == '.')
						break;
			
					src++;
				}

				if(*src++ != '.')
					break;

				sscanf((char*)src, "%d", (int*)&((Ip*)mDestination)->addr3);

				for(int i=0;i<4;i++)
				{
					if(*src == '.')
						break;
			
					src++;
				}

				if(*src++ != '.')
					break;

				sscanf((char*)src, "%d", (int*)&((Ip*)mDestination)->addr4);
				break;

			case 'g' :
				if(	mCommand != CMD::GET_CUR_GATEWAY ||
					*src++ != 'a' || 
					*src++ != 't' || 
					*src++ != 'e' || 
					*src++ != 'w' || 
					*src++ != 'a' || 
					*src++ != 'y' || 
					*src++ != ':' || 
					*src++ != '"')
					break;
				sscanf((char*)src, "%d", (int*)&((Ip*)mDestination)->addr1);

				for(int i=0;i<4;i++)
				{
					if(*src == '.')
						break;
			
					src++;
				}

				if(*src++ != '.')
					break;

				sscanf((char*)src, "%d", (int*)&((Ip*)mDestination)->addr2);

				for(int i=0;i<4;i++)
				{
					if(*src == '.')
						break;
			
					src++;
				}

				if(*src++ != '.')
					break;

				sscanf((char*)src, "%d", (int*)&((Ip*)mDestination)->addr3);

				for(int i=0;i<4;i++)
				{
					if(*src == '.')
						break;
			
					src++;
				}

				if(*src++ != '.')
					break;

				sscanf((char*)src, "%d", (int*)&((Ip*)mDestination)->addr4);
				break;

			case 'n' :
				if(	mCommand != CMD::GET_CUR_NETMASK ||
					*src++ != 'e' || 
					*src++ != 't' || 
					*src++ != 'm' || 
					*src++ != 'a' || 
					*src++ != 's' || 
					*src++ != 'k' || 
					*src++ != ':' || 
					*src++ != '"')
					break;
				sscanf((char*)src, "%d", (int*)&((Ip*)mDestination)->addr1);

				for(int i=0;i<4;i++)
				{
					if(*src == '.')
						break;
			
					src++;
				}

				if(*src++ != '.')
					break;

				sscanf((char*)src, "%d", (int*)&((Ip*)mDestination)->addr2);

				for(int i=0;i<4;i++)
				{
					if(*src == '.')
						break;
			
					src++;
				}

				if(*src++ != '.')
					break;

				sscanf((char*)src, "%d", (int*)&((Ip*)mDestination)->addr3);

				for(int i=0;i<4;i++)
				{
					if(*src == '.')
						break;
			
					src++;
				}

				if(*src++ != '.')
					break;

				sscanf((char*)src, "%d", (int*)&((Ip*)mDestination)->addr4);
				break;
			}
			break;
		}
		break;

	case 'I' :
		if(	*src++ != 'P' ||
			*src++ != 'D' ||
			*src++ != ',')
			break;
		sscanf((char*)src, "%d", (int*)&len);

		for(int i=0;i<5;i++)
		{
			if(*src++ == ':')
				break;
		}
		break;
		
	}
}

void WizFi360::interpret_W(volatile char *src)
{
	if(	*src++ != 'I' ||
		*src++ != 'F' || 
		*src++ != 'I' || 
		*src++ != ' ')
		return;

	switch(*src++)
	{
	case 'C' :
		if(	*src++ != 'O' ||
			*src++ != 'N' ||
			*src++ != 'N' ||
			*src++ != 'E' ||
			*src++ != 'C' ||
			*src++ != 'T' ||
			*src++ != 'E' ||
			*src++ != 'D' ||
			*src++ != 0x0D ||
			*src++ != 0x0A)
			break;

		mConnectedFlag = true;
		if(callbackConnect)
			callbackConnect(true);
		break;

	case 'G' :
		if(	*src++ != 'O' ||
			*src++ != 'T' ||
			*src++ != ' ' ||
			*src++ != 'I' ||
			*src++ != 'P' ||
			*src++ != 0x0D ||
			*src++ != 0x0A)
			break;
	
		thread::delay(500);
		flush();
		mResult = RESULT::COMPLETE;
		mIpFlag = true;
		break;

	case 'D' :
		if(	*src++ != 'I' ||
			*src++ != 'S' ||
			*src++ != 'C' ||
			*src++ != 'O' ||
			*src++ != 'N' ||
			*src++ != 'N' ||
			*src++ != 'E' ||
			*src++ != 'C' ||
			*src++ != 'T' ||
			*src++ != 0x0D ||
			*src++ != 0x0A)
			break;

		mConnectedFlag = false;
		mIpFlag = false;
		if(callbackConnect)
			callbackConnect(false);
	}
}

void WizFi360::interpret_C(volatile char *src)
{
	switch(*src++)
	{
	case 'O' :
		if(	*src++ != 'N' ||
			*src++ != 'N' ||
			*src++ != 'E' ||
			*src++ != 'C' ||
			*src++ != 'T')
			break;

		mSocketConnectedFlag = true;
		break;

	case 'L' :
		if(	*src++ != 'O' ||
			*src++ != 'S' ||
			*src++ != 'E' ||
			*src++ != 'D')
			break;

		mSocketConnectedFlag = false;
		break;
	}
}
