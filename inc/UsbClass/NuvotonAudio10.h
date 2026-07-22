/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_USB_CLASS_NUVOTON_AUDIO10__H_
#define YSS_USB_CLASS_NUVOTON_AUDIO10__H_

#include "Audio10.h"

/**
 * @file NuvotonAudio10.h
 * @brief USB Audio Class 1.0 driver class header file for Nuvoton MCUs.
 */

/**
 * @class NuvotonAudio10
 * @brief Driver class for USB Audio Class 1.0 devices on Nuvoton MCUs.
 *
 * @details
 * This class inherits from Audio10. It implements the necessary virtual descriptor handling
 * and request interfaces for Nuvoton USB Device (USBD) hardware, and registers callback functions
 * for player mute and volume control updates.
 */
class NuvotonAudio10 : public Audio10
{
public :
	/**
	 * @brief USB Audio Class configuration structure containing details and volume callbacks.
	 */
	typedef struct 
	{
		const char *manufactureString;             ///< Manufacturer name string descriptor.
		const char *productString;                 ///< Product name string descriptor.
		const char *serialNumberString;            ///< Device serial number string descriptor.

		int16_t (*callback_getPlayVolumeMax)(void);       ///< Callback function to get maximum playback volume.
		int16_t (*callback_getPlayVolumeMin)(void);       ///< Callback function to get minimum playback volume.
		int16_t (*callback_getPlayVolumeResolution)(void);///< Callback function to get playback volume resolution.
		int16_t (*callback_getPlayVolume)(void);          ///< Callback function to get current playback volume.
		bool (*callback_getPlayMute)(void);               ///< Callback function to check if playback is muted.

		void (*callback_setPlayMute)(bool mute);          ///< Callback function to mute/unmute playback.
		void (*callback_setPlayVolume)(int16_t volume);   ///< Callback function to set playback volume.
	}config_t;

	/**
	 * @brief Gets the current audio sampling rate requested by the host.
	 *
	 * @return uint32_t Sampling rate in Hz.
	 */
	uint32_t getSampleRate(void);

	// Internal system functions. Do not call from user application.
	NuvotonAudio10(void) __attribute__((optimize("-O1")));

	virtual error_t initialize(const config_t &config = {"Nuvoton", "USB Audio"}) __attribute__((optimize("-O1")));

	virtual bool getEpDescriptor(uint8_t index, epDesc_t *des) __attribute__((optimize("-O1")));

	virtual void handleGetDeviceDescriptor(void) __attribute__((optimize("-O1")));

	virtual void handleGetConfigDescriptor(uint16_t size) __attribute__((optimize("-O1")));

	virtual void handleGetDeviceQualifierDescriptor(void) __attribute__((optimize("-O1")));

	virtual void handleGetStringDescriptor(uint8_t index, uint16_t size) __attribute__((optimize("-O1")));

	virtual uint8_t getUsingEpCount(void) __attribute__((optimize("-O1")));

private :
	config_t mConfig;

	virtual void handleClassSpecificRequest(void) __attribute__((optimize("-O1")));

	virtual void handleSetConfiguration(uint16_t value) __attribute__((optimize("-O1")));
};

#endif

/**
 * @example nuvoton_audio10_init_example
 * @code
 * NuvotonAudio10 audio10;
 *
 * int main(void)
 * {
 *     NuvotonAudio10::config_t audioConfig =
 *     {
 *         "Nuvoton",             // Manufacturer string
 *         "yss OS USB Audio",    // Product string
 *         nullptr                // Serial number string (null if none)
 *     };
 *
 *     audio10.initialize(audioConfig); // Initialize USB Audio Class 1.0
 *
 *     // Initialize USBD GPIO pins:
 *     gpioA.setAsAltFunc(12, Gpio::PA12_USB_VBUS);      // VBUS
 *     gpioA.setAsAltFunc(13, Gpio::PA13_USBD_DN);        // D-
 *     gpioA.setAsAltFunc(14, Gpio::PA14_USBD_DP);        // D+
 *     gpioA.setAsAltFunc(15, Gpio::PA15_USB_OTG_ID);     // OTG ID
 *
 *     usbd.enableClock();          // Enable USBD peripheral clock
 *     usbd.initialize(audio10);    // Initialize USBD stack as Audio Class
 *     usbd.enableInterrupt();      // Enable USBD interrupts
 * }
 * @endcode
 */

