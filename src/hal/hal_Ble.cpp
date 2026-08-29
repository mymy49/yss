/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <hal/Ble.h>

#pragma GCC optimize("O1")

static const uint16_t gFrequencyTable[40] =
{
    // ==========================================
    // Data Channels (0 ~ 36)
    // ==========================================
    2404, 2406, 2408, 2410, 2412,  // Ch 0 ~ 4
    2414, 2416, 2418, 2420, 2422,  // Ch 5 ~ 9
    2424,                          // Ch 10
    
    2428, 2430, 2432, 2434, 2436,  // Ch 11 ~ 15
    2438, 2440, 2442, 2444, 2446,  // Ch 16 ~ 20
    2448, 2450, 2452, 2454, 2456,  // Ch 21 ~ 25
    2458, 2460, 2462, 2464, 2466,  // Ch 26 ~ 30
    2468, 2470, 2472, 2474, 2476,  // Ch 31 ~ 35
    2478,                          // Ch 36
    // ==========================================
    // Advertising Channels (37, 38, 39)
    // ==========================================
    2402,                          // Ch 37
    2426,                          // Ch 38
    2480                           // Ch 39
};

Ble::Ble(void)
{
}

uint32_t Ble::getFrequency(uint8_t channel)
{
	if(channel < 40)
		return gFrequencyTable[channel];
	else
		return 0;
}
