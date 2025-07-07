/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS_NUVOTON_CDC__H_
#define YSS_USB_CLASS_NUVOTON_CDC__H_

#include "Cdc.h"

class NuvotonCdc : public Cdc
{
public :

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	NuvotonCdc(void) __attribute__((optimize("-O1")));

	virtual error_t initialize(const config_t &config = {"Nuvoton", "USB Virtual COM"}) __attribute__((optimize("-O1")));

	virtual bool getEpDescriptor(uint8_t index, epDesc_t *des) __attribute__((optimize("-O1"))); // pure

	virtual void handleGetDeviceDescriptor(void) __attribute__((optimize("-O1"))); // pure

	virtual void handleGetConfigDescriptor(uint16_t size) __attribute__((optimize("-O1"))); // pure

	virtual void handleGetDeviceQualifierDescriptor(void) __attribute__((optimize("-O1"))); // pure

	virtual void handleGetStringDescriptor(uint8_t index, uint16_t size) __attribute__((optimize("-O1"))); // pure

private :
};

#endif

/* 설정을 직접할 경우 CDC 초기화 예제 코드
	const char *manufacture = "Nuvoton";
	const char *product= "yss OS Virtual COM Port";

	Cdc::config_t cdcConfig =
	{
		manufacture,	//const char *manufactureString;
		product,		//const char *productString;
		0				//const char *serialNumberString;
	};

	cdc.initialize(cdcConfig); // CDC를 초기화 합니다.

	// USBD 초기화
	gpioA.setAsAltFunc(12, Gpio::PA12_USB_VBUS);		// VBUS 핀을 설정합니다.
	gpioA.setAsAltFunc(13, Gpio::PA13_USBD_DN);			// D- 핀을 설정합니다.
	gpioA.setAsAltFunc(14, Gpio::PA14_USBD_DP);			// D+ 핀을 설정합니다.
	gpioA.setAsAltFunc(15, Gpio::PA15_USB_OTG_ID);		// ID 핀을 설정합니다.

	usbd.enableClock();			// USBD의 클럭을 확성화합니다.
	usbd.initialize(cdc);		// USBD를 CDC로 초기화합니다.
	usbd.enableInterrupt();		// USBD의 인터럽트를 활성화합니다.
*/
