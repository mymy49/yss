/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

 #include <drv/Sdmmc.h>
 #include <string.h>

#define SD_IDLE 0
#define SD_READY 1
#define SD_IDENT 2
#define SD_STBY 3
#define SD_TRANS 4
#define SD_DATA 5
#define SD_RCA 6
#define SD_PRG 7
#define SD_DIS 8

#define HCS		0x40000000
#define BUSY	0x80000000

static void trigger_detect(void *obj)
{
	Sdmmc *sdmmc = (Sdmmc*)obj;
	
	// Debounce detection changes before changing connection state.
	thread::delay(500);

	if(sdmmc->isDetected() && !sdmmc->isConnected())
		sdmmc->connect();
	else if(!sdmmc->isDetected() && sdmmc->isConnected())
		sdmmc->disconnect();
}

Sdmmc::Sdmmc(const Drv::setup_t &drvConfig) : Drv(drvConfig)
{
	mConnectedFlag = false;
	mVcc = 3.3;
	mRca = 0x00000000;
	mLastResponseCmd = 0;
	mMaxBlockAddr = 0;
	mDetectPin = {0, 0};

	mTriggerId = trigger::add(trigger_detect, this, 512);
}

bool Sdmmc::isConnected(void)
{
	// Return whether the SD card state machine has successfully connected.
	return mConnectedFlag;
}

bool Sdmmc::isDetected(void)
{
	// Detect the card by reading the configured GPIO detect pin.
	if(mDetectPin.port)
		return mDetectPin.port->getInputData(mDetectPin.pin) == mDetectPolarity;
	else
		return false;
}

void Sdmmc::setDetectPin(pin_t pin, bool detectPolarity)
{
	mDetectPin = pin;
	mDetectPolarity = detectPolarity;

#if 0
	exti.add(*pin.port, pin.pin, (Exti::mode_t)(Exti::FALLING | Exti::RISING), mTriggerId);
#elif defined(__M4xx_FAMILY)
	mDetectPin.port->setGpioInterrupt(mDetectPin.pin, Gpio::EDGE_BOTH, mTriggerId);
#endif
	
	// If a card is already present at initialization, trigger the connect handler.
	if(isDetected())
		trigger::run(mTriggerId);
}


#define POWER_2_7__2_8 (1 << 15)
#define POWER_2_8__2_9 (1 << 16)
#define POWER_2_9__3_0 (1 << 17)
#define POWER_3_0__3_1 (1 << 18)
#define POWER_3_1__3_2 (1 << 19)
#define POWER_3_2__3_3 (1 << 20)
#define POWER_3_3__3_4 (1 << 21)
#define POWER_3_4__3_5 (1 << 22)
#define POWER_3_5__3_6 (1 << 23)

inline uint32_t getOcr(float vcc)
{
	uint32_t ocr = 0;

	if ((float)2.7 <= vcc && (float)2.8 <= vcc)
		ocr = POWER_2_7__2_8;
	else if ((float)2.8 <= vcc && (float)2.9 <= vcc)
		ocr = POWER_2_8__2_9;
	else if ((float)2.9 <= vcc && (float)3.0 <= vcc)
		ocr = POWER_2_9__3_0;
	else if ((float)3.0 <= vcc && (float)3.1 <= vcc)
		ocr = POWER_3_0__3_1;
	else if ((float)3.1 <= vcc && (float)3.2 <= vcc)
		ocr = POWER_3_1__3_2;
	else if ((float)3.2 <= vcc && (float)3.3 <= vcc)
		ocr = POWER_3_2__3_3;
	else if ((float)3.3 <= vcc && (float)3.4 <= vcc)
		ocr = POWER_3_3__3_4;
	else if ((float)3.4 <= vcc && (float)3.5 <= vcc)
		ocr = POWER_3_4__3_5;
	else if ((float)3.5 <= vcc && (float)3.6 <= vcc)
		ocr = POWER_3_5__3_6;

	return ocr;
}

inline int32_t extractCSizeVersion2(void *src)
{
	uint8_t *buf = (uint8_t *)src;
	return (uint32_t)buf[9] | (uint32_t)buf[8] << 8 | (uint32_t)(buf[7] & 0x3F) << 16;
}

inline int32_t extractMaxBlockLength(void *src)
{
	uint8_t *buf = (uint8_t *)src;

	switch(*buf >> 6)
	{
	case 0 : // version 1.0
	
		return 0;
	case 1 : // version 2.0
		return (extractCSizeVersion2(buf) + 1) * 1024;
	default :
		return 0;
	}
}

inline int32_t extractReadBlockLength(void *src)
{
	uint8_t *buf = (uint8_t *)src;

	switch(*buf >> 6)
	{
	case 0 : // version 1.0
		return 0;

	case 1 : // version 2.0
		return 512;

	default :
		return 0;
	}
}

error_t Sdmmc::connect(void)
{
	if(mConnectedFlag)
		return error_t::ALREADY_OPENED;

	uint32_t ocr, capacity, temp;
	cardStatus_t sts;
	error_t result;
	uint8_t cbuf[16];

	// Power on the card and initialize the SD bus at a low frequency.
	enablePower(true);
	setBusWidth(BUS_WIDTH_1BIT);
	setClockFrequency(300000);
	setSdioClockEn(true);

	mRca = 0x00000000;

	thread::delay(100);

	result = sendPowerOn74Clock();

	thread::delay(100);

	// CMD0 (SD card reset)
	result = sendCmd(CMD0_GO_IDLE_STATE, 0, RESPONSE_NO_R);

	thread::delay(100);

	// CMD8 (Check SD version 2.0 support and voltage range)
	result = sendCmd(CMD8_SEND_IF_COND, 0x000001AA, RESPONSE_R7);
	if (result != error_t::ERROR_NONE)
		goto error_handler;
	if (getShortResponse() != 0x000001AA)
		goto error_handler;

	// Create the OCR value for the configured Vcc range.
	ocr = getOcr(mVcc);

	// ACMD41: query supported voltage and initialize the card.
	result = sendAcmd(ACMD41_SD_APP_OP_COND, ocr | HCS, RESPONSE_R3);
	if (result != error_t::ERROR_NONE)
	{
		// If this fails, the card is likely not an SD card.
		goto error_handler;
	}

	// Verify the card supports the current Vcc range.
	if ((getShortResponse() & ocr) == 0)
		goto error_handler;

	// Wait for the card to complete its power-up initialization.
	do
	{
		result = sendAcmd(ACMD41_SD_APP_OP_COND, ocr | HCS, RESPONSE_R3);
		if (result != error_t::ERROR_NONE)
			goto error_handler;
	} while ((getShortResponse() & BUSY) == 0);

	// Record whether the card supports high capacity addressing.
	if (getShortResponse() & HCS)
		mHcsFlag = true;
	else
		mHcsFlag = false;

	// CMD2: request the card identification register (CID).
	result = sendCmd(CMD2_ALL_SEND_CID, 0, RESPONSE_R2);
	if (result != error_t::ERROR_NONE)
		goto error_handler;

	// CMD3: request the relative card address (RCA) for future commands.
	result = sendCmd(CMD3_SET_RELATIVE_ADDR, 0, RESPONSE_R6);
	if (result != error_t::ERROR_NONE)
		goto error_handler;
	mRca = getShortResponse() & 0xffff0000;

	sts = getCardStatus();
	if(sts.currentState != SD_STBY)
		goto error_handler;

	// Read the CID register for card identification.
	result = sendCmd(CMD10_SEND_CID, mRca, RESPONSE_R2);
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	getLongResponse(cbuf);

	// Read the CSD register to determine block size and capacity.
	result = sendCmd(CMD9_SEND_CSD, mRca, RESPONSE_R2);
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	getLongResponse(cbuf);

	mMaxBlockAddr = extractMaxBlockLength(cbuf);
	mReadBlockLen = extractReadBlockLength(cbuf);

	result = select(true);
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	setDataBlockSize(mReadBlockLen);

	// Switch to the normal operation frequency after initialization.
	setClockFrequency(25000000);

	mConnectedFlag = true;

	return error_t::ERROR_NONE;

error_handler :
	setSdioClockEn(false);
	mRca = 0;
	mMaxBlockAddr = 0;
	mConnectedFlag = false;
	enablePower(false);

	return result;
}

error_t Sdmmc::disconnect(void)
{
	if(!mConnectedFlag)
		return error_t::ALREADY_CLOSED;

	setSdioClockEn(false);
	mRca = 0;
	mMaxBlockAddr = 0;
	mConnectedFlag = false;
	enablePower(false);

	return error_t::ERROR_NONE;
}

void Sdmmc::setVcc(float vcc)
{
	mVcc = vcc;
}

error_t Sdmmc::sendAcmd(acmd_t cmd, uint32_t arg, response_t responseType)
{
	error_t result;

	cardStatus_t status;

	// CMD55: prefix the next command to be interpreted as an ACMD.
	result = sendCmd(CMD55_APP_CMD, mRca, RESPONSE_R1);
	if (result != error_t::ERROR_NONE) 
		return result;

	*(uint32_t*)(&status) = getShortResponse();
	if (status.appCmd == 0 || status.readyForData == 0)
		return error_t::NOT_READY;

	// Send the actual application-specific command.
	result = sendCmd((cmd_t)cmd, arg, responseType);

	return result;
}

uint32_t Sdmmc::getNumOfBlock(void)
{
	return mMaxBlockAddr;
}

error_t Sdmmc::select(bool en)
{
	error_t result;
	if(en)
		result = sendCmd(CMD7_SELECT_DESELECT_CARD, mRca, RESPONSE_R1b);
	else
		result = sendCmd(CMD7_SELECT_DESELECT_CARD, 0, RESPONSE_R1b);

	return result;
}

Sdmmc::cardStatus_t Sdmmc::getCardStatus(void)
{
	cardStatus_t sts;
	uint32_t *buf = (uint32_t*)&sts;

	// Query the card status register and return it as a structured value.
	if (sendCmd(CMD13_SEND_STATUS, mRca, RESPONSE_R1) == error_t::ERROR_NONE)
		*buf = getShortResponse();
	else
		*buf = 0xFFFFFFFF;

	return sts;
}

uint32_t Sdmmc::getBlockSize(void)
{
	return mReadBlockLen;
}

error_t Sdmmc::read(uint32_t block, void *des)
{
	if(!mConnectedFlag)
		return error_t::NOT_CONNECTED;

	error_t result;

	// Avoid overlapping read and write timings by waiting for previous operations to settle.
	while(mLastWriteTime.getMsec() <= 15 || mLastReadTime.getUsec() <= 500)
		thread::yield();

	readyRead(des, 512);
	if(!mHcsFlag)
		block *= mReadBlockLen;
	result = sendCmd(CMD17_READ_SINGLE_BLOCK, block, RESPONSE_R1);
	if(result != error_t::ERROR_NONE)
	{
		stopReadyRead();
		goto error_handle;
	}
	result = waitUntilReadComplete();
	mLastReadTime.reset();
	return result;

error_handle:
	return result;
}

error_t Sdmmc::write(uint32_t block, void *src)
{
	if(!mConnectedFlag)
		return error_t::NOT_CONNECTED;

	error_t result;
	// Wait until the previous write/read operation has matured enough to avoid timing conflicts.
	while(mLastWriteTime.getMsec() <= 15 || mLastReadTime.getUsec() <= 500)
		thread::yield();

	readyWrite(src, 512);
	if(!mHcsFlag)
		block *= mReadBlockLen;
	result = sendCmd(CMD24_WRITE_BLOCK, block, RESPONSE_R1);
	if(result != error_t::ERROR_NONE)
		goto error_handle;

	result = waitUntilWriteComplete();
	mLastWriteTime.reset();

	return result;

error_handle:
	mLastWriteTime.reset();
	return result;
}
