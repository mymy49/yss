#include <mod/GxWorks2/Fx1Cpu.h>
#include <yss/debug.h>
#include <string.h>

#define PLC_TYPE	0x5EF6	// 24310 FX2N ver 3.10 !!!
#define PLC_TYPE_01	0x5EF6	// 24310 FX2N ver 3.10 !!!
#define MAXSTEP		2000

static const uint16_t gMemoryPlcD8xxxInitValue[130] = 
{
	0x00C8,			// D8000 - WDT 200mc
	PLC_TYPE,		// D8001 - (26210/0x6266) FX1N / (25210/0x627A) FX2N ver 2.10 / (16310/0x3FB6) FX3U ver 3.10 / (24310/0x5EF6) FX2N ver 3.10
	MAXSTEP / 1000, // D8002 - 16000 Steps
	0x0000,			// D8003 - Internal ( 0x10 - CPURAM, 0x00 - RAM, 0x01 - EPROM, 0x02 - EEPROM )
	0x0000,			// D8004 - Error
	0x0025,			// D8005 - Batary 3.7
	0x001E,			// D8006 - Low Batary 3.0
	0x0000,			// D8007 -
	0xFFFF,			// D8008 -
	0x0000,			// D8009 -
	0x0000,			// D8010 - scan current value
	0x0000,			// D8011 - scan minimum time (0.1MS)
	0x0000,			// D8012 - maximum scan time (0.1MS)
	0x0000,			// D8013 - Time Sec
	0x0000,			// D8014 - Time Min
	0x0000,			// D8015 - Time Hour
	0x0000,			// D8016 - Time Date
	0x0000,			// D8017 - Time Mounth
	0x0000,			// D8018 - Time Year
	0x0000,			// D8019 - Time Day

	0x000A,			// D8020 -
	0x0000, 		// D8021 -
	0x0000,			// D8022 -
	0x0000,			// D8023 -
	0x0000,			// D8024 -
	0x0000,			// D8025 -
	0x0000,			// D8026 -
	0x0000,			// D8027 -
	0x0000,			// D8028 -
	0x0000,			// D8029 -

	0x0000,			// D8030 - AN1
	0x0000,			// D8031 - AN2
	0x0000,			// D8032 - AN3
	0x0000,			// D8033 - AN4
	0x0000,			// D8034 - AN5
	0x0000,			// D8035 - AN6
	0x0000,			// D8036 - AN7
	0x0000,			// D8037 - AN8
	0x0000,			// D8038 - AN9
	0x0000,			// D8039 -

	0xFFFF,			// D8040 -
	0xFFFF,			// D8041 -
	0xFFFF,			// D8042 -
	0xFFFF,			// D8043 -
	0xFFFF,			// D8044 -
	0xFFFF,			// D8045 -
	0xFFFF,			// D8046 -
	0xFFFF,			// D8047 -
	0x0000,			// D8048 -
	0xFFFF,			// D8049 -
	0x0000,			// D8050 - AN 10
	0x0000,			// D8051 - AN 11
	0x0000,			// D8052 - AN 12
	0x0000,			// D8053 - AN 13
	0x0000,			// D8054 - AN 14
	0x0000,			// D8055 - AN 15
	0x0000,			// D8056 - AN 16
	0x0000,			// D8057 -
	0x0000,			// D8058 -
	0x0000,			// D8059 -

	0x0000,			// D8060 -
	0x0000,			// D8061 -
	0x183B,			// D8062 -
	0x0000,			// D8063 -
	0x0000,			// D8064 -
	0x0000,			// D8065 -
	0x0000,			// D8066 -
	0x0000,			// D8067 -
	0x0000,			// D8068 -
	0x0000,			// D8069 -

	0x01F4,			// D8070 -
	0x0000,			// D8071 -
	0x0000,			// D8072 -
	0x0000,			// D8073 -
	0x0000,			// D8074 -
	0x0000,			// D8075 -
	0x0000,			// D8076 -
	0x0000,			// D8077 -
	0x0000,			// D8078 -
	0x0000,			// D8079 -
	0x0000,			// D8080 - Analog Output 1
	0x0000,			// D8081 - Analog Output 2
	0x0000,			// D8082 -
	0x0000,			// D8083 -
	0x0000,			// D8084 -
	0x0000,			// D8085 -
	0x0000,			// D8086 -
	0x0000,			// D8087 -
	0x0000,			// D8088 -
	0x0000,			// D8089 -
	0x0000,			// D8090 -
	0x0000,			// D8091 -
	0x0000,			// D8092 -
	0x0000,			// D8093 -
	0x0000,			// D8094 -
	0x0000,			// D8095 -
	0x0000,			// D8096 -
	0x0000,			// D8097 -
	0x0000,			// D8098 -
	0x0000,			// D8099 -

	0x0064,			// D8100 -
	PLC_TYPE_01,	// D8101 - (26210/0x6266) FX1N / (25210/0x627A) FX2N ver 2.10 / (16310/0x3FB6) FX3U ver 3.10 / (24310/0x5EF6) FX2N ver 3.10
	MAXSTEP / 1000, // D8102 - 16000 Steps
	0x0000,			// D8103 -
	0x0000,			// D8104 -
	0x0000,			// D8105 -
	0x0000,			// D8106 -
	0x0000,			// D8107 -
	0x0000,			// D8108 -
	0x0000,			// D8109 -
	0x0000,			// D8110 -
	0x0000,			// D8111 -
	0x0000,			// D8112 - DAC1
	0x0000,			// D8113 - DAC2
	0x0000,			// D8114 -
	0x0000,			// D8115 -
	0x0000,			// D8116 -
	0x0000,			// D8117 -
	0x0000,			// D8118 -
	0x0000,			// D8119 -

	0x0000,			// D8120 - Comunication format
	0x0001,			// D8121 - Slave number
	0x0000,			// D8122 - RS
	0x0000,			// D8123 - RS
	0x0002,			// D8124 - RS Header ( STX (02h) )
	0x0003,			// D8125 - RS Footer ( ETX (03h) )
	0x0000,			// D8126 -
	0x0000,			// D8127 - RS485 addr
	0x0000,			// D8128 - RS486 len
	0x0000			// D8129 - RS485 timeout
};

void thread_processComm(void *var)
{
	((Fx1Cpu*)var)->processComm();
}

Fx1Cpu::Fx1Cpu(void)
{
	mThreadId = thread::add(thread_processComm, this, 1024);

	memset(mMemoryS0, 0x00, sizeof(mMemoryS0));
	memset(mMemoryStep, 0x00, sizeof(mMemoryStep));
	memset(mMemoryPlcD8xxx, 0x00, sizeof(mMemoryPlcD8xxx));

	memcpy(mMemoryPlcD8xxx, gMemoryPlcD8xxxInitValue, sizeof(gMemoryPlcD8xxxInitValue));
}

Fx1Cpu::~Fx1Cpu(void)
{
	thread::remove(mThreadId);
}

void Fx1Cpu::processComm(void)
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

uint8_t Fx1Cpu::atox(uint8_t tens, uint8_t units)
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

uint8_t Fx1Cpu::xtoaTens(uint8_t hex)
{
	hex = (hex >> 4) & 0xF;
	if(hex > 0x09)
		return 'A' + hex - 10;
	else
		return '0' + hex;
}

uint8_t Fx1Cpu::xtoaUnits(uint8_t hex)
{
	hex = hex & 0xF;
	if(hex > 0x09)
		return 'A' + hex - 10;
	else
		return '0' + hex;
}

void Fx1Cpu::handleCommRxData(void)
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

void Fx1Cpu::responseRead(uint16_t addr, uint8_t size)
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
