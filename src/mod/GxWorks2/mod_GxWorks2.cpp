#include <mod/GxWorks2/GxWorks2.h>
#include <yss/debug.h>
#include <stdlib.h>

void thread_processComm(void *var)
{
	((GxWorks2*)var)->processComm();
}

GxWorks2::GxWorks2(void)
{
	mThreadId = thread::add(thread_processComm, this, 1024);
}

GxWorks2::~GxWorks2(void)
{
	thread::remove(mThreadId);
}

void GxWorks2::processComm(void)
{
	uint32_t count, index = 0, chksum;
	uint8_t rcvBuf[64], step = 0, data, chksum1, chksum2, calchksum1, calchksum2;

	while(true)
	{
		count = getRxCount();

		if(count)
		{
			getRxData(rcvBuf, count);

			for(uint32_t i = 0; i < count; i++)
			{
				data = rcvBuf[i];
				if(data == 0x05) // enquiry
				{
					mTxData[0] = 0x06;
					sendData(mTxData, 1);
					step = 0;
				}
				else
				{
					switch(step)
					{
					case 0 : // STX 확인
						if(data == 0x02)
						{
							step++;
							index = 0;
							chksum = 0;
						}
						break;
				
					case 1 : // 데이터 수신
						if(data == 0x03) // ETX 확인
						{
							mRxData[index++] = data;
							chksum += data;
						
							calchksum1 = xtoaTens(chksum);
							calchksum2 = xtoaUnits(chksum);
							step++;
						}
						else
						{
							mRxData[index++] = data;
							chksum += data;
						
							if(index > 144) // 오버플로우 확인
							{
								step = 0;
							}
						}
						break;

					case 2 : // 체크섬 1 수신
						chksum1 = data;
						step++;
						break;
				
					case 3 : // 체크섬 2 수신 및 데이터 유효성 검사
						chksum2 = data;
						if(calchksum1 == chksum1 && calchksum2 == chksum2)
						{
							mRxDataSize = index;
							handleCommRxData();
							debug_printf("chksum ok!!\n");
						}
						step = 0;
						break;
					}
				}
			}
		}
		thread::yield();
	}
}

uint8_t GxWorks2::atox(uint8_t tens, uint8_t units)
{
	if(tens >= '0' && tens <= '9')
		tens -= '0';
	else
		tens -= 'A' - 10;
	if(units >= '0' && units <= '9')
		units -= '0';
	else
		units -= 'A' - 10;
	return tens << 4 | units;
}

uint8_t GxWorks2::xtoaTens(uint8_t hex)
{
	hex = (hex >> 4) & 0xF;
	if(hex > 0x09)
		return 'A' + hex - 10;
	else
		return '0' + hex;
}

uint8_t GxWorks2::xtoaUnits(uint8_t hex)
{
	hex = hex & 0xF;
	if(hex > 0x09)
		return 'A' + hex - 10;
	else
		return '0' + hex;
}

void GxWorks2::handleCommRxData(void)
{
	uint16_t progAddr;
	uint8_t dataSize;
	
	progAddr = atox(mRxData[1], mRxData[2]) << 8 | atox(mRxData[3], mRxData[4]);
	dataSize = atox(mRxData[5], mRxData[6]);

	switch(mRxData[0])
	{
	case '0' : // PC Read
		mTxData[0] = 0x06;
		responseRead(progAddr, dataSize);
		break;
	}
}

void GxWorks2::responseRead(uint16_t addr, uint8_t size)
{
	uint8_t index = 0, data;
	uint8_t chksum = 0;

	mTxData[index++] = 0x02; // STX
	for(uint8_t i = 0; i < size; i++)
	{
		data = 0;
		mTxData[index] = xtoaTens(data);
		chksum += mTxData[index++];
		mTxData[index] = xtoaUnits(data);
		chksum += mTxData[index++];
	}
	mTxData[index] = 0x03; // ETX
	chksum += mTxData[index++];
	mTxData[index++] = xtoaTens(chksum); // chksum1
	mTxData[index++] = xtoaUnits(chksum); // chksum2

	sendData(mTxData, index);
}
