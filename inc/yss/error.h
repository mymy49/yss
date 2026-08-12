/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_ERROR__H_
#define YSS_ERROR__H_

#include <stdint.h>

/**
 * @file error.h
 * @brief Error code enum definitions used across the yss OS framework.
 */

/**
 * @brief Unified error code enumeration.
 */
typedef enum
{
	ERROR_NONE = 0,                 ///< No error.

	// General/Generic Errors
	BUSY,                           ///< Device or resource is busy.
	OVERSIZE,                       ///< Requested data size exceeds capability.
	MALLOC_FAILED,                  ///< Dynamic memory allocation failed.
	OVERFLOW,                       ///< Buffer or register overflow occurred.
	BUFFER_SIZE,                    ///< Invalid buffer size configuration.
	INDEX_OVER,                     ///< Provided index is out of bounds.
	NOT_READY,                      ///< Device is not ready for operation.
	TX_UNDERRUN,                    ///< Transmitter underrun condition.
	RX_OVERRUN,                     ///< Receiver overrun condition.
	DMA_ERROR,                      ///< DMA channel transfer error.
	TIMEOUT,                        ///< Operation timed out.
	UNSUPPORTED_MODE,               ///< The specified mode is not supported.
	WRONG_CONFIG,                   ///< Configuration settings are incorrect.
	WRONG_INDEX,                    ///< Index parameter value is wrong.
	WRONG_COMMAND,                  ///< Issued instruction command is wrong.
	NOT_INITIALIZED,                ///< Peripheral is not initialized.
	OUT_OF_RANGE,                   ///< Parameter is out of range.
	UNKNOWN,                        ///< Unknown generic error occurred.
	NOT_CONNECTED,                  ///< Interface or device is disconnected.
	FAILED_THREAD_ADDING,           ///< Thread registration failed.
	FAILED_TRIGGER_ADDING,          ///< Trigger registration failed.
	WRONG_SIZE,                     ///< Data or configuration size is wrong.
	WRONG_CLOCK_FREQUENCY,          ///< Target clock frequency is wrong or cannot be generated.
	IT_ALREADY_HAVE,                ///< Item/element already exists.
	NOT_HAVE_SPECIFICATON,          ///< Specification data is missing.
	NACK,                           ///< No acknowledgment (NACK) received.
	FAIL,                           ///< General execution failure.
	CHECK_SUM,                      ///< Data checksum verification failed.
	NOT_SUPPORTED_FORMAT,           ///< Data format is not supported.
	NOT_SUPPORTED_YET,              ///< Feature is not supported yet.
	NOT_SUPPORTED_OPTION,           ///< Specified option is not supported.
	ALREADY_OPENED,                 ///< Target is already opened.
	ALREADY_CLOSED,                 ///< Target is already closed.
	WRONG_RESPONSE,                 ///< Wrong response packet/code received.
	UNKNOWN_DEVICE,                 ///< Unknown device identifier.
	DMA_ALLOCATION_FAILED,          ///< Failed to allocate a DMA channel.
	OUT_OF_CHANNEL,                 ///< Out of available channels.
	DIFFERENT_DEVICE,               ///< Device identifier mismatch.
	UNSUPPORTED_CONFIG,             ///< Configuration layout is unsupported.
	INSTRUCTION_ERROR,              ///< Instruction execution error.
	CRC_ERROR,                      ///< CRC verification error.
	DATA_RANGE_ERROR,               ///< Data is out of valid range boundaries.
	DATA_LENGTH_ERROR,              ///< Length of data is incorrect.
	DATA_LIMIT_ERROR,               ///< Data limits exceeded.
	ACCESS_ERROR,                   ///< Access denied or permission error.

	// FAT File System Errors
	SECTOR_READ,                    ///< Failed to read sector.
	SIGNATURE,                      ///< Signature mismatch.
	PARTITION_TYPE,                 ///< Unsupported partition type.
	NO_BOOT_SECTOR,                 ///< Boot sector not found.
	NO_DATA,                        ///< No data available.
	NO_FREE_DATA,                   ///< No free space/clusters.
	NO_FILE,                        ///< File not found.
	NOT_EXIST_NAME,                 ///< File/Directory name does not exist.
	WRONG_FORMAT,                   ///< Invalid format structure.
	WRONG_FILE_NAME,                ///< Invalid file name structure.
	WRONG_DIRECTORY_NAME,           ///< Invalid directory name structure.
	WRONG_DIRECTORY_PATH,           ///< Invalid directory path structure.
	FILE_NOT_OPENED,                ///< File is not opened.
	END_OF_FILE,                    ///< End of file reached.

	// SD Memory Errors
	BAD_SECTOR,                     ///< Bad sector encountered.
	NOT_DIRECTORY,                  ///< Requested item is not a directory.
	SAME_FILE_NAME_EXIST,           ///< Same file name already exists.
	NO_RESPONSE_CMD,                ///< No response to command.
	CMD_TIMEOUT,                    ///< Command execution timed out.
	DATA_TIMEOUT,                   ///< Data transmission timed out.
	CMD_CRC_FAIL,                   ///< Command CRC failed.
	DATA_CRC_FAIL,                  ///< Data CRC failed.
	SDCARD_NOT_ABLE,                ///< SD Card state not applicable or disabled.
	UNSUPPORTED_RESPONSE_TYPE,      ///< Response type is unsupported.

	// CLOCK Configuration Errors
	SYSCLK_SRC_IS_PLL,              ///< System clock source is PLL.
	HSE_NOT_READY,                  ///< External High-Speed Oscillator (HSE) not ready.
	PLL_NOT_READY,                  ///< PLL not ready.
	CLK_SRC_NOT_ABLE,               ///< Clock source not applicable.
	SYSCLK_WAS_NOT_CHANGED,         ///< System clock frequency failed to change.
	CLK_SRC_NOT_READY,

	// CAN Communication Errors
	SLEEP_ACK_INTERRUPT,            ///< Sleep mode acknowledgment interrupt occurred.
	WAKEUP_INTERRUPT,               ///< Wakeup interrupt occurred.
	ERROR_INTERRUP,                 ///< CAN error interrupt occurred.

	// GPIO Errors
	OUT_OF_PIN_INDEX_RANGE,         ///< Pin index is out of bounds.
	THIS_PIN_DO_NOT_HAVE_GPIO_OUTPUT, ///< Pin does not support GPIO output function.

	// Flash Memory Errors
	LOCK_MODE,                      ///< FMC lock mode error.
	BROWN_OUT_DETECTED,             ///< Brown-out reset condition detected.
	FAILED_FLASH_PROGRAM,           ///< Flash programming failed.
	ISPFF_FLAG,                     ///< ISP fail flag error.

	// USB Errors
	UNSUPPORTED_EP,                 ///< Endpoint is unsupported.
	UNSUPPORTED_EP_BUF,             ///< Endpoint buffer allocation size unsupported.
}error_t;

#endif