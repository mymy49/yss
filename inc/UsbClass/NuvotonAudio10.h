/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS_NUVOTON_AUDIO10__H_
#define YSS_USB_CLASS_NUVOTON_AUDIO10__H_

#include "Audio10.h"

class NuvotonAudio10 : public Audio10
{
public :
	typedef struct 
	{
		const char *manufactureString;
		const char *productString;
		const char *serialNumberString;

		int16_t (*callback_getPlayVolumeMax)(void);
		int16_t (*callback_getPlayVolumeMin)(void);
		int16_t (*callback_getPlayVolumeResolution)(void);
		int16_t (*callback_getPlayVolume)(void);
		bool (*callback_getPlayMute)(void);

		void (*callback_setPlayMute)(bool mute);
		void (*callback_setPlayVolume)(int16_t volume);
	}config_t;

	/*	
	 *	샘플레이트를 얻습니다.
	 *	.
	 *	@ return : 샘플레이트를 반환합니다.
	 */
	uint32_t getSampleRate(void);

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	NuvotonAudio10(void) __attribute__((optimize("-O1")));

	virtual error_t initialize(const config_t &config = {"Nuvoton", "USB Audio"}) __attribute__((optimize("-O1")));

	virtual bool getEpDescriptor(uint8_t index, epDesc_t *des) __attribute__((optimize("-O1"))); // pure

	virtual void handleGetDeviceDescriptor(void) __attribute__((optimize("-O1"))); // pure

	virtual void handleGetConfigDescriptor(uint16_t size) __attribute__((optimize("-O1"))); // pure

	virtual void handleGetDeviceQualifierDescriptor(void) __attribute__((optimize("-O1"))); // pure

	virtual void handleGetStringDescriptor(uint8_t index, uint16_t size) __attribute__((optimize("-O1"))); // pure

	virtual uint8_t getUsingEpCount(void) __attribute__((optimize("-O1"))); // pure

private :
	config_t mConfig;

	virtual void handleClassSpecificRequest(void) __attribute__((optimize("-O1"))); // pure

	virtual void handleSetConfiguration(uint16_t value) __attribute__((optimize("-O1"))); // pure
};

#endif

/* 설정을 직접할 경우 AUDIO 초기화 예제 코드
	
NuvotonAudio10 audio10;

int main(void)
{
	NuvotonAudio10::config_t audioConfig =
	{
		"Nuvoton",				//const char *manufactureString;
		"yss OS USB Audio",		//const char *productString;
		0						//const char *serialNumberString;
	};

	audio10.initialize(audioConfig); // Audio Class 1.0을 초기화 합니다.

	// USBD 초기화
	gpioA.setAsAltFunc(12, Gpio::PA12_USB_VBUS);		// VBUS 핀을 설정합니다.
	gpioA.setAsAltFunc(13, Gpio::PA13_USBD_DN);			// D- 핀을 설정합니다.
	gpioA.setAsAltFunc(14, Gpio::PA14_USBD_DP);			// D+ 핀을 설정합니다.
	gpioA.setAsAltFunc(15, Gpio::PA15_USB_OTG_ID);		// ID 핀을 설정합니다.

	usbd.enableClock();			// USBD의 클럭을 확성화합니다.
	usbd.initialize(audio10);	// USBD를 Audio Class로 초기화합니다.
	usbd.enableInterrupt();		// USBD의 인터럽트를 활성화합니다.
}
*/
