#ifndef YSS_MCU__H_
#define YSS_MCU__H_

#if defined(STM32F746xx) || defined(STM32F745xx) || \
    defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F768xx) || defined(STM32F769xx)

#include <stm32f7xx.h>

#elif defined(STM32F100xB) || defined(STM32F100xE) ||                                               \
    defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) ||                                                 \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) ||                                                                         \
    defined(STM32F107xC)

#include <stm32f1xx.h>

#elif defined(STM32F103xG)

#include <stm32f103xg.h>

#elif defined(STM32F405xx) || defined(STM32F415xx) || \
    defined(STM32F407xx) || defined(STM32F417xx) ||   \
    defined(STM32F427xx) || defined(STM32F437xx) ||   \
    defined(STM32F429xx) || defined(STM32F439xx)

#include <stm32f4xx.h>

#elif defined(STM32L151xB)

#include <stm32l1xx.h>

#elif defined(STM32G431xx) || defined(STM32G441xx) || \
    defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32GBK1CB)

#include <stm32g4xx.h>

#elif defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || \
    defined(STM32L011xx) || defined(STM32L021xx) ||                                                   \
    defined(STM32L031xx) || defined(STM32L041xx) ||                                                   \
    defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||                           \
    defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||                           \
    defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||                           \
    defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)

#include <stm32l0xx.h>

#elif defined(STM32L412xx) || defined(STM32L422xx) ||                                                                       \
    defined(STM32L431xx) || defined(STM32L432xx) || defined(STM32L433xx) || defined(STM32L442xx) || defined(STM32L443xx) || \
    defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) ||                                                 \
    defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) || \
    defined(STM32L496xx) || defined(STM32L4A6xx) ||                                                                         \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx) ||                                                                         \
    defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)

#include <stm32l4xx.h>

#elif defined(__SAML21E15A__) || defined(__SAML21E15B__) || defined(__SAML21E16A__) || defined(__SAML21E16B__) || \
    defined(__SAML21E17A__) || defined(__SAML21E17B__) || defined(__SAML21E18B__) || defined(__SAML21G16A__) ||   \
    defined(__SAML21G16B__) || defined(__SAML21G17A__) || defined(__SAML21G17B__) || defined(__SAML21G18A__) ||   \
    defined(__SAML21G18B__) || defined(__SAML21J16A__) || defined(__SAML21J16B__) || defined(__SAML21J17A__) ||   \
    defined(__SAML21J17B__) || defined(__SAML21J18A__) || defined(__SAML21J18B__)

#include <saml21.h>

#elif defined(XMC4300_F100x256)

#include <xmc_device.h>

#elif defined(MAX32660)

#include <max32660.h>

#else

#define ERROR_MCU_NOT_ABLE

inline void __disable_irq(void) {}
inline void __enable_irq(void) {}
inline void NVIC_SetPriority(unsigned char val1, unsigned char val2) {}

#define PendSV_IRQn 0
#define SysTick_CTRL_CLKSOURCE_Pos 0
#define SysTick_CTRL_TICKINT_Pos 0
#define SysTick_CTRL_ENABLE_Pos 0

//typedef struct
//{
//	volatile unsigned long CTRL;	// !< Offset: 0x000 (R/W)  SysTick Control and Status Register
//	volatile unsigned long LOAD;	// !< Offset: 0x004 (R/W)  SysTick Reload Value Register
//	volatile unsigned long VAL;		// !< Offset: 0x008 (R/W)  SysTick Current Value Register
//	volatile unsigned long CALIB;	// !< Offset: 0x00C (R/ )  SysTick Calibration Register
//} SysTick_Type;

#define SysTick ((SysTick_Type *)0) // !< SysTick configuration struct

#endif

#endif