/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/ctouch/GT911.h>
#include <yss/event.h>
#include <drv/Exti.h>
#include <yss/debug.h>
#include <std_ext/string.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED) && !defined(YSS_DRV_EXTI_UNSUPPORTED)

#define ADDR			0xBA

#define REG_CHECKSUM	0xFF80
#define REG_PID			0x4081
#define REG_COORD		0x4E81
#define REG_CFG			0x4780
#define REG_FRESH		0x0081
#define REG_CMD			0x4080
#define REG_CMD_CHK		0x4680

struct Gt911config_t
{
	uint8_t version;				// 0x8047
	uint16_t xOutputMax;			// 0x8048
	uint16_t yOutputMax;			// 0x804A
	uint8_t touchNumber;			// 0x804C
	uint8_t moduleSwitch1;			// 0x804D
	uint8_t moduleSwitch2;			// 0x804E
	uint8_t shakeCount;				// 0x804F
	uint8_t filter;					// 0x8050
	uint8_t largeTouch;				// 0x8051
	uint8_t noiseReduction;			// 0x8052
	uint8_t screenTouchLevel;		// 0x8053
	uint8_t screenLeaveLevel;		// 0x8054
	uint8_t lowPowerControl;		// 0x8055
	uint8_t refreshRate;			// 0x8056
	uint8_t xThreshold;				// 0x8057
	uint8_t yThreshold;				// 0x8058
	uint8_t reserved1[2];			// 0x8059
	uint8_t space[2];				// 0x805B
	uint8_t miniFilter;				// 0x805D
	uint8_t stretchR0;				// 0x805E
	uint8_t stretchR1;				// 0x805F
	uint8_t stretchR2;				// 0x8060
	uint8_t stretchRM;				// 0x8061
	uint8_t drvGroupANum;			// 0x8062
	uint8_t drvGroupBNum;			// 0x8063
	uint8_t sensorNum;				// 0x8064
	uint8_t freqAFactor;			// 0x8065
	uint8_t freqBFactor;			// 0x8066
	uint16_t pannelBitFreq;			// 0x8067
	uint16_t pannelSensorTime;		// 0x8069
	uint8_t pannelTxGain;			// 0x806B
	uint8_t pannelRxGain;			// 0x806C
	uint8_t pannelDumpShift;		// 0x806D
	uint8_t drvFrameControl;		// 0x806E
	uint8_t chargingLevelUp;		// 0x806F
	uint8_t moduleSwitch3;			// 0x8070
	uint8_t gestureDis;				// 0x8071
	uint8_t gestureLongPressTime;	// 0x8072
	uint8_t xySlopeAdjust;			// 0x8073
	uint8_t gestureControl;			// 0x8074
	uint8_t gestureSwitch1;			// 0x8075
	uint8_t gestureSwitch2;			// 0x8076
	uint8_t gestureRefreshRate;		// 0x8077
	uint8_t gestureTouchLevel;		// 0x8078
	uint8_t newGreenWakeUpLevel;	// 0x8079
	uint8_t freqHoppingStart;		// 0x807A
	uint8_t freqHoppingEnd;			// 0x807B
	uint8_t noiseDetectTimes;		// 0x807C
	uint8_t hoppingFlag;			// 0x807D
	uint8_t hoppingThreshold;		// 0x807E
	uint8_t noiseThreshold;			// 0x807F
	uint8_t noiseMinThreshold;		// 0x8080
	uint8_t reserved2;				// 0x8081
	uint8_t hoppingSensorGroup;		// 0x8082
	uint8_t hoppingSeg1Normalize;	// 0x8083
	uint8_t hoppingSeg1Factor;		// 0x8084
	uint8_t mainClockAdjust;		// 0x8085
	uint8_t hoppingSeg2Normalize;	// 0x8086
	uint8_t hoppingSeg2Factor;		// 0x8087
	uint8_t reserved3;				// 0x8088
	uint8_t hoppingSeg3Normalize;	// 0x8089
	uint8_t hoppingSeg3Factor;		// 0x808A
	uint8_t reserved4;				// 0x808B
	uint8_t hoppingSeg4Normalize;	// 0x808C
	uint8_t hoppingSeg4Factor;		// 0x808D
	uint8_t reserved5;				// 0x808E
	uint8_t hoppingSeg5Normalize;	// 0x808F
	uint8_t hoppingSeg5Factor;		// 0x8090
	uint8_t reserved6;				// 0x8091
	uint8_t hoppingSeg6Normalize;	// 0x8092
	uint8_t key1;					// 0x8093
	uint8_t key2;					// 0x8094
	uint8_t key3;					// 0x8095
	uint8_t key4;					// 0x8096
	uint8_t keyArea;				// 0x8097
	uint8_t keyTouchLevel;			// 0x8098
	uint8_t keyLeaveLevel;			// 0x8099
	uint8_t keySens[2];				// 0x809A
	uint8_t keyRestrain;			// 0x809C
	uint8_t keyRestrainTime;		// 0x809D
	uint8_t gestureLargeTouch;		// 0x809E
	uint8_t reserved7[2];			// 0x809F
	uint8_t hotknotNoiseMap;		// 0x80A1
	uint8_t linkThreshold;			// 0x80A2
	uint8_t pXyThreshold;			// 0x80A3
	uint8_t gHotDumpShift;			// 0x80A4
	uint8_t gHotRxGain;				// 0x80A5
	uint8_t freqGain0;				// 0x80A6
	uint8_t freqGain1;				// 0x80A7
	uint8_t freqGain2;				// 0x80A8
	uint8_t freqGain3;				// 0x80A9
	uint8_t reserved8[9];			// 0x80AA
	uint8_t combineDis;				// 0x80B3
	uint8_t splitSet;				// 0x80B4
	uint8_t reserved9[2];			// 0x80B5
	uint8_t sensorCh[14];			// 0x80B7
	uint8_t reserved10[16];			// 0x80C5
	uint8_t driverCh[26];			// 0x80D5
	uint8_t reserved11[16];			// 0x80EF
	uint8_t chksum;					// 0x80FF
	uint8_t configFresh;			// 0x8100
}__attribute__((packed));

static void trigger_handler(void *peri);

error_t GT911::initialize(const config_t config)
{
	error_t result;
	uint8_t data[4];
	Gt911config_t *gt911Config = new Gt911config_t;
	
	mPeri = &config.peri;
	mIsr = config.isrPin;

	if(config.resetPin.port)
	{
		config.resetPin.port->setOutput(config.resetPin.pin, false);
		
		// Address를 0xBA로 세팅 
		mIsr.port->setAsOutput(mIsr.pin);
		mIsr.port->setOutput(mIsr.pin, false);
		thread::delay(10);
		config.resetPin.port->setOutput(config.resetPin.pin, true);
		thread::delay(5);
		mIsr.port->setAsInput(mIsr.pin);
	}
	thread::delay(200);
	
	result = getMultiByte(REG_PID, data, 4);
	if(result != error_t::ERROR_NONE)
	{
		goto error_handler;
	}
	
	if(data[0] != '9' || data[1] != '1' || data[2] != '1'|| data[3] != 0)
	{
		result = error_t::UNKNOWN_DEVICE;
		goto error_handler;
	}

	result = getMultiByte(REG_CFG, gt911Config, sizeof(Gt911config_t));
	if(result != error_t::ERROR_NONE)
	{
		goto error_handler;
	}

	gt911Config->version = 0x5B;
	gt911Config->xOutputMax = 800;
	gt911Config->yOutputMax = 480;
	gt911Config->touchNumber = 5;
	gt911Config->moduleSwitch1 = 0x0D;
	gt911Config->moduleSwitch2 = 0x00;
	gt911Config->shakeCount = 0x02;
	gt911Config->filter = 0x0F;
	gt911Config->largeTouch = 0x28;
	gt911Config->noiseReduction = 0x0F;
	gt911Config->screenTouchLevel = 0x50;
	gt911Config->screenLeaveLevel = 0x32;
	gt911Config->lowPowerControl = 0x03;
	gt911Config->refreshRate = 0x05;
	gt911Config->xThreshold = 0x00;
	gt911Config->yThreshold = 0x00;
	gt911Config->reserved1[0] = 0x00;
	gt911Config->reserved1[1] = 0x00;
	gt911Config->space[0] = 0x00;
	gt911Config->space[1] = 0x00;
	gt911Config->miniFilter = 0x00;
	gt911Config->stretchR0 = 0x00;
	gt911Config->stretchR1 = 0x00;
	gt911Config->stretchR2 = 0x00;
	gt911Config->stretchRM = 0x00;
	gt911Config->drvGroupANum = 0x87;
	gt911Config->drvGroupBNum = 0x29;
	gt911Config->sensorNum = 0x0A;
	gt911Config->freqAFactor = 0x2D;
	gt911Config->freqBFactor = 0x2F;
	gt911Config->pannelBitFreq = 0x0A0F;
	gt911Config->pannelSensorTime = 0x0000;
	gt911Config->pannelTxGain = 0x00;
	gt911Config->pannelRxGain = 0x02;
	gt911Config->pannelDumpShift = 0x02;
	gt911Config->drvFrameControl = 0x1D;
	gt911Config->chargingLevelUp = 0x00;
	gt911Config->moduleSwitch3 = 0x00;
	gt911Config->gestureDis = 0x00;
	gt911Config->gestureLongPressTime = 0x00;
	gt911Config->xySlopeAdjust = 0x00;
	gt911Config->gestureControl = 0x03;
	gt911Config->gestureSwitch1 = 0x64;
	gt911Config->gestureSwitch2 = 0x32;
	gt911Config->gestureRefreshRate = 0x00;
	gt911Config->gestureTouchLevel = 0x00;
	gt911Config->freqHoppingStart = 0x1E;
	gt911Config->freqHoppingEnd = 0x50;
	gt911Config->noiseDetectTimes = 0x94;
	gt911Config->hoppingFlag = 0xC5;
	gt911Config->hoppingThreshold = 0x02;
	gt911Config->noiseThreshold = 0x07;
	gt911Config->noiseMinThreshold = 0x00;
	gt911Config->reserved2 = 0x00;
	gt911Config->hoppingSensorGroup = 0x04;
	gt911Config->hoppingSeg1Normalize = 0xA3;
	gt911Config->hoppingSeg1Factor = 0x21;
	gt911Config->mainClockAdjust = 0x00;
	gt911Config->hoppingSeg2Normalize = 0x8C;
	gt911Config->hoppingSeg2Factor = 0x28;
	gt911Config->reserved3 = 0x00;
	gt911Config->hoppingSeg3Normalize = 0x78;
	gt911Config->hoppingSeg3Factor = 0x31;
	gt911Config->reserved4 = 0x00;
	gt911Config->hoppingSeg4Normalize = 0x69;
	gt911Config->hoppingSeg4Factor = 0x3B;
	gt911Config->reserved5 = 0x00;
	gt911Config->hoppingSeg5Normalize = 0x5D;
	gt911Config->hoppingSeg5Factor = 0x48;
	gt911Config->reserved6 = 0x00;
	gt911Config->hoppingSeg6Normalize = 0x5D;
	gt911Config->key1 = 0x00;
	gt911Config->key2 = 0x00;
	gt911Config->key3 = 0x00;
	gt911Config->key4 = 0x00;
	gt911Config->keyArea = 0x00;
	gt911Config->keyTouchLevel = 0x00;
	gt911Config->keyLeaveLevel = 0x00;
	gt911Config->keySens[0] = 0x00;
	gt911Config->keySens[1] = 0x00;
	gt911Config->keyRestrain = 0x00;
	gt911Config->keyRestrainTime = 0x00;
	gt911Config->gestureLargeTouch = 0x00;
	gt911Config->reserved7[0] = 0x00;
	gt911Config->reserved7[1] = 0x00;
	gt911Config->hotknotNoiseMap = 0x00;
	gt911Config->linkThreshold = 0x00;
	gt911Config->pXyThreshold = 0x00;
	gt911Config->gHotDumpShift = 0x00;
	gt911Config->gHotRxGain = 0x00;
	gt911Config->freqGain0 = 0x00;
	gt911Config->freqGain1 = 0x00;
	gt911Config->freqGain2 = 0x00;
	gt911Config->freqGain3 = 0x00;
	memset(gt911Config->reserved8, 0x00, sizeof(gt911Config->reserved8));
	gt911Config->combineDis = 0x00;
	gt911Config->splitSet = 0x00;
	gt911Config->reserved9[0] = 0x00;
	gt911Config->reserved9[1] = 0x00;
	gt911Config->sensorCh[0] = 0x02;
	gt911Config->sensorCh[1] = 0x04;
	gt911Config->sensorCh[2] = 0x06;
	gt911Config->sensorCh[3] = 0x08;
	gt911Config->sensorCh[4] = 0x0A;
	gt911Config->sensorCh[5] = 0x0C;
	gt911Config->sensorCh[6] = 0x0E;
	gt911Config->sensorCh[7] = 0x10;
	gt911Config->sensorCh[8] = 0x12;
	gt911Config->sensorCh[9] = 0x14;
	gt911Config->sensorCh[10] = 0xFF;
	gt911Config->sensorCh[11] = 0xFF;
	gt911Config->sensorCh[12] = 0xFF;
	gt911Config->sensorCh[13] = 0xFF;
	memset(gt911Config->reserved10, 0x00, sizeof(gt911Config->reserved10));
	gt911Config->driverCh[0] = 0x00;
	gt911Config->driverCh[1] = 0x02;
	gt911Config->driverCh[2] = 0x04;
	gt911Config->driverCh[3] = 0x06;
	gt911Config->driverCh[4] = 0x08;
	gt911Config->driverCh[5] = 0x0A;
	gt911Config->driverCh[6] = 0x0C;
	gt911Config->driverCh[7] = 0x1D;
	gt911Config->driverCh[8] = 0x1E;
	gt911Config->driverCh[9] = 0x1F;
	gt911Config->driverCh[10] = 0x20;
	gt911Config->driverCh[11] = 0x21;
	gt911Config->driverCh[12] = 0x22;
	gt911Config->driverCh[13] = 0x24;
	gt911Config->driverCh[14] = 0x26;
	gt911Config->driverCh[15] = 0x28;
	gt911Config->driverCh[16] = 0xFF;
	gt911Config->driverCh[17] = 0xFF;
	gt911Config->driverCh[18] = 0xFF;
	gt911Config->driverCh[19] = 0xFF;
	gt911Config->driverCh[20] = 0xFF;
	gt911Config->driverCh[21] = 0xFF;
	gt911Config->driverCh[22] = 0xFF;
	gt911Config->driverCh[23] = 0xFF;
	gt911Config->driverCh[24] = 0xFF;
	gt911Config->driverCh[25] = 0xFF;
	memset(gt911Config->reserved11, 0x00, sizeof(gt911Config->reserved11));
	gt911Config->configFresh = 1;
	gt911Config->chksum = calculateChksum(gt911Config);
	result = setMultiByte(REG_CFG, gt911Config, sizeof(Gt911config_t));

	thread::delay(100);

	setCommand(0x00);

	mTriggerId = trigger::add(trigger_handler, this, 1024);

	if(mTriggerId == 0)
	{
		result = error_t::FAILED_THREAD_ADDING;
		goto error_handler;
	}

	result = exti.add(*mIsr.port, mIsr.pin, Exti::FALLING, mTriggerId);
	if(result == error_t::ERROR_NONE)
		exti.enable(mIsr.pin);

error_handler :

	delete gt911Config;
	return result;
}

uint8_t GT911::calculateChksum(void *src)
{
	uint8_t chksum = 0, *data = (uint8_t*)src;
	
	for(uint32_t i = 0; i < sizeof(Gt911config_t) - 2; i++)
	{
		chksum += data[i];
	}

	return (~chksum) + 1;
}

int8_t GT911::getByte(uint16_t addr)
{
	mPeri->lock();
	mPeri->send(ADDR, (int8_t*)&addr, 2, 100);
	thread::delay(1);
	mPeri->receive(ADDR, (int8_t*)&addr, 1, 100);
	mPeri->stop();
	mPeri->unlock();

	return addr;
}

error_t GT911::setCommand(uint8_t cmd)
{
	uint8_t data[3] = {0x80, 0x40, cmd};
	error_t result;

	mPeri->lock();
	result = mPeri->send(ADDR, data, 3, 100);
	mPeri->stop();
	mPeri->unlock();

	return result;
}

uint8_t GT911::getCommand(void)
{
	uint8_t data[2] = {0x80, 0x46};

	if(mPeri->send(ADDR, data, 2, 100) == error_t::ERROR_NONE)
	{
		thread::delay(1);
		mPeri->receive(ADDR, data, 1, 100);
		return data[0];
	}
	else
		return 0;
}

error_t GT911::getMultiByte(uint16_t addr, void *des, uint8_t size)
{
	error_t rt = error_t::UNKNOWN;

	mPeri->lock();
	if(mPeri->send(ADDR, &addr, 2, 100) == error_t::ERROR_NONE)
	{
		thread::delay(1);
		rt = mPeri->receive(ADDR, des, size, 100);
	}
	mPeri->stop();
	mPeri->unlock();

	return rt;
}

error_t GT911::setMultiByte(uint16_t addr, void *src, uint8_t size)
{
	error_t result = error_t::UNKNOWN;
	uint8_t *data = new uint8_t[size + 2];

	if(data != nullptr)
	{
		memcpy(&data[0], &addr, 2);
		memcpy(&data[2], src, size);
		mPeri->lock();
		result = mPeri->send(ADDR, data, size + 2, 500);
		mPeri->stop();
		mPeri->unlock();

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmismatched-new-delete"
		delete data;
#pragma GCC diagnostic pop	

		return result;
	}
	else
		return error_t::MALLOC_FAILED;
}

error_t GT911::setByte(uint16_t addr, uint8_t data)
{
	error_t result = error_t::UNKNOWN;
	uint8_t buf[3] = {(uint8_t)(addr >> 8), (uint8_t)addr, data};

	mPeri->lock();
	result = mPeri->send(ADDR, buf, 3, 100);
	mPeri->stop();
	mPeri->unlock();

	return result;
}


void GT911::isr(void)
{
	//static bool penDown = false;
	//uint16_t x, y;
	//uint8_t data[8*5], event, status, count;
	uint8_t data[8*5], status;

	status = getByte(REG_COORD);
	if(status & 0x80)
	{
		getMultiByte(REG_COORD + 0x100, data, 8*5);
//		debug_printf("0x%02X, 0x%02X, 0x%02X, 0x%02X\n", data[0], data[1], data[2], data[3]);
	}

	//if(data[0] <= 1)
	//{
	//	event = data[1] >> 6;
		
	//	data[1] &= 0x0F;
	//	y = (uint16_t)data[1] << 8;
	//	y |= data[2];
	//	x = (uint16_t)data[3] << 8;
	//	x |= data[4];

	//	if((event == 0x00) && (penDown == false))
	//	{
	//		penDown = true;
	//		push(x, y, event::TOUCH_DOWN);
	//	}
	//	else if((event == 0x02) && penDown == true)
	//	{
	//		push(x, y, event::TOUCH_DRAG);
	//	}
	//	else if((event == 0x01) && penDown == true)
	//	{
	//		penDown = false;
	//		push(x, y, event::TOUCH_UP);
	//	}
	//}
}

static void trigger_handler(void *var)
{
	((GT911*)var)->isr();
}

#endif

