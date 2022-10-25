/**
  ******************************************************************************
  * @file    stm32f103x6.h
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer Header File. 
  *          This file contains all the peripheral register's definitions, bits 
  *          definitions and memory mapping for STM32F1xx devices.            
  *            
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripherals registers hardware
  *  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ADC_STM32_GD32F1__H_
#define __ADC_STM32_GD32F1__H_

/******************************************************************************/
/*                                                                            */
/*                      Analog to Digital Converter (ADC)                     */
/*                                                                            */
/******************************************************************************/

/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F1 family)
 */
#define ADC_MULTIMODE_SUPPORT                          /*!< ADC feature available only on specific devices: multimode available on devices with several ADC instances */

/********************  Bit definition for ADC_SR register  ********************/
#define ADC_SR_AWD_Pos                      (0U)                               
#define ADC_SR_AWD_Msk                      (0x1UL << ADC_SR_AWD_Pos)           /*!< 0x00000001 */
#define ADC_SR_AWD                          ADC_SR_AWD_Msk                     /*!< ADC analog watchdog 1 flag */
#define ADC_SR_EOS_Pos                      (1U)                               
#define ADC_SR_EOS_Msk                      (0x1UL << ADC_SR_EOS_Pos)           /*!< 0x00000002 */
#define ADC_SR_EOS                          ADC_SR_EOS_Msk                     /*!< ADC group regular end of sequence conversions flag */
#define ADC_SR_JEOS_Pos                     (2U)                               
#define ADC_SR_JEOS_Msk                     (0x1UL << ADC_SR_JEOS_Pos)          /*!< 0x00000004 */
#define ADC_SR_JEOS                         ADC_SR_JEOS_Msk                    /*!< ADC group injected end of sequence conversions flag */
#define ADC_SR_JSTRT_Pos                    (3U)                               
#define ADC_SR_JSTRT_Msk                    (0x1UL << ADC_SR_JSTRT_Pos)         /*!< 0x00000008 */
#define ADC_SR_JSTRT                        ADC_SR_JSTRT_Msk                   /*!< ADC group injected conversion start flag */
#define ADC_SR_STRT_Pos                     (4U)                               
#define ADC_SR_STRT_Msk                     (0x1UL << ADC_SR_STRT_Pos)          /*!< 0x00000010 */
#define ADC_SR_STRT                         ADC_SR_STRT_Msk                    /*!< ADC group regular conversion start flag */

/* Legacy defines */
#define  ADC_SR_EOC                          (ADC_SR_EOS)
#define  ADC_SR_JEOC                         (ADC_SR_JEOS)

/*******************  Bit definition for ADC_CR1 register  ********************/
#define ADC_CR1_AWDCH_Pos                   (0U)                               
#define ADC_CR1_AWDCH_Msk                   (0x1FUL << ADC_CR1_AWDCH_Pos)       /*!< 0x0000001F */
#define ADC_CR1_AWDCH                       ADC_CR1_AWDCH_Msk                  /*!< ADC analog watchdog 1 monitored channel selection */
#define ADC_CR1_AWDCH_0                     (0x01UL << ADC_CR1_AWDCH_Pos)       /*!< 0x00000001 */
#define ADC_CR1_AWDCH_1                     (0x02UL << ADC_CR1_AWDCH_Pos)       /*!< 0x00000002 */
#define ADC_CR1_AWDCH_2                     (0x04UL << ADC_CR1_AWDCH_Pos)       /*!< 0x00000004 */
#define ADC_CR1_AWDCH_3                     (0x08UL << ADC_CR1_AWDCH_Pos)       /*!< 0x00000008 */
#define ADC_CR1_AWDCH_4                     (0x10UL << ADC_CR1_AWDCH_Pos)       /*!< 0x00000010 */

#define ADC_CR1_EOSIE_Pos                   (5U)                               
#define ADC_CR1_EOSIE_Msk                   (0x1UL << ADC_CR1_EOSIE_Pos)        /*!< 0x00000020 */
#define ADC_CR1_EOSIE                       ADC_CR1_EOSIE_Msk                  /*!< ADC group regular end of sequence conversions interrupt */
#define ADC_CR1_AWDIE_Pos                   (6U)                               
#define ADC_CR1_AWDIE_Msk                   (0x1UL << ADC_CR1_AWDIE_Pos)        /*!< 0x00000040 */
#define ADC_CR1_AWDIE                       ADC_CR1_AWDIE_Msk                  /*!< ADC analog watchdog 1 interrupt */
#define ADC_CR1_JEOSIE_Pos                  (7U)                               
#define ADC_CR1_JEOSIE_Msk                  (0x1UL << ADC_CR1_JEOSIE_Pos)       /*!< 0x00000080 */
#define ADC_CR1_JEOSIE                      ADC_CR1_JEOSIE_Msk                 /*!< ADC group injected end of sequence conversions interrupt */
#define ADC_CR1_SCAN_Pos                    (8U)                               
#define ADC_CR1_SCAN_Msk                    (0x1UL << ADC_CR1_SCAN_Pos)         /*!< 0x00000100 */
#define ADC_CR1_SCAN                        ADC_CR1_SCAN_Msk                   /*!< ADC scan mode */
#define ADC_CR1_AWDSGL_Pos                  (9U)                               
#define ADC_CR1_AWDSGL_Msk                  (0x1UL << ADC_CR1_AWDSGL_Pos)       /*!< 0x00000200 */
#define ADC_CR1_AWDSGL                      ADC_CR1_AWDSGL_Msk                 /*!< ADC analog watchdog 1 monitoring a single channel or all channels */
#define ADC_CR1_JAUTO_Pos                   (10U)                              
#define ADC_CR1_JAUTO_Msk                   (0x1UL << ADC_CR1_JAUTO_Pos)        /*!< 0x00000400 */
#define ADC_CR1_JAUTO                       ADC_CR1_JAUTO_Msk                  /*!< ADC group injected automatic trigger mode */
#define ADC_CR1_DISCEN_Pos                  (11U)                              
#define ADC_CR1_DISCEN_Msk                  (0x1UL << ADC_CR1_DISCEN_Pos)       /*!< 0x00000800 */
#define ADC_CR1_DISCEN                      ADC_CR1_DISCEN_Msk                 /*!< ADC group regular sequencer discontinuous mode */
#define ADC_CR1_JDISCEN_Pos                 (12U)                              
#define ADC_CR1_JDISCEN_Msk                 (0x1UL << ADC_CR1_JDISCEN_Pos)      /*!< 0x00001000 */
#define ADC_CR1_JDISCEN                     ADC_CR1_JDISCEN_Msk                /*!< ADC group injected sequencer discontinuous mode */

#define ADC_CR1_DISCNUM_Pos                 (13U)                              
#define ADC_CR1_DISCNUM_Msk                 (0x7UL << ADC_CR1_DISCNUM_Pos)      /*!< 0x0000E000 */
#define ADC_CR1_DISCNUM                     ADC_CR1_DISCNUM_Msk                /*!< ADC group regular sequencer discontinuous number of ranks */
#define ADC_CR1_DISCNUM_0                   (0x1UL << ADC_CR1_DISCNUM_Pos)      /*!< 0x00002000 */
#define ADC_CR1_DISCNUM_1                   (0x2UL << ADC_CR1_DISCNUM_Pos)      /*!< 0x00004000 */
#define ADC_CR1_DISCNUM_2                   (0x4UL << ADC_CR1_DISCNUM_Pos)      /*!< 0x00008000 */

#define ADC_CR1_DUALMOD_Pos                 (16U)                              
#define ADC_CR1_DUALMOD_Msk                 (0xFUL << ADC_CR1_DUALMOD_Pos)      /*!< 0x000F0000 */
#define ADC_CR1_DUALMOD                     ADC_CR1_DUALMOD_Msk                /*!< ADC multimode mode selection */
#define ADC_CR1_DUALMOD_0                   (0x1UL << ADC_CR1_DUALMOD_Pos)      /*!< 0x00010000 */
#define ADC_CR1_DUALMOD_1                   (0x2UL << ADC_CR1_DUALMOD_Pos)      /*!< 0x00020000 */
#define ADC_CR1_DUALMOD_2                   (0x4UL << ADC_CR1_DUALMOD_Pos)      /*!< 0x00040000 */
#define ADC_CR1_DUALMOD_3                   (0x8UL << ADC_CR1_DUALMOD_Pos)      /*!< 0x00080000 */

#define ADC_CR1_JAWDEN_Pos                  (22U)                              
#define ADC_CR1_JAWDEN_Msk                  (0x1UL << ADC_CR1_JAWDEN_Pos)       /*!< 0x00400000 */
#define ADC_CR1_JAWDEN                      ADC_CR1_JAWDEN_Msk                 /*!< ADC analog watchdog 1 enable on scope ADC group injected */
#define ADC_CR1_AWDEN_Pos                   (23U)                              
#define ADC_CR1_AWDEN_Msk                   (0x1UL << ADC_CR1_AWDEN_Pos)        /*!< 0x00800000 */
#define ADC_CR1_AWDEN                       ADC_CR1_AWDEN_Msk                  /*!< ADC analog watchdog 1 enable on scope ADC group regular */

/* Legacy defines */
#define  ADC_CR1_EOCIE                       (ADC_CR1_EOSIE)
#define  ADC_CR1_JEOCIE                      (ADC_CR1_JEOSIE)

/*******************  Bit definition for ADC_CR2 register  ********************/
#define ADC_CR2_ADON_Pos                    (0U)                               
#define ADC_CR2_ADON_Msk                    (0x1UL << ADC_CR2_ADON_Pos)         /*!< 0x00000001 */
#define ADC_CR2_ADON                        ADC_CR2_ADON_Msk                   /*!< ADC enable */
#define ADC_CR2_CONT_Pos                    (1U)                               
#define ADC_CR2_CONT_Msk                    (0x1UL << ADC_CR2_CONT_Pos)         /*!< 0x00000002 */
#define ADC_CR2_CONT                        ADC_CR2_CONT_Msk                   /*!< ADC group regular continuous conversion mode */
#define ADC_CR2_CAL_Pos                     (2U)                               
#define ADC_CR2_CAL_Msk                     (0x1UL << ADC_CR2_CAL_Pos)          /*!< 0x00000004 */
#define ADC_CR2_CAL                         ADC_CR2_CAL_Msk                    /*!< ADC calibration start */
#define ADC_CR2_RSTCAL_Pos                  (3U)                               
#define ADC_CR2_RSTCAL_Msk                  (0x1UL << ADC_CR2_RSTCAL_Pos)       /*!< 0x00000008 */
#define ADC_CR2_RSTCAL                      ADC_CR2_RSTCAL_Msk                 /*!< ADC calibration reset */
#define ADC_CR2_DMA_Pos                     (8U)                               
#define ADC_CR2_DMA_Msk                     (0x1UL << ADC_CR2_DMA_Pos)          /*!< 0x00000100 */
#define ADC_CR2_DMA                         ADC_CR2_DMA_Msk                    /*!< ADC DMA transfer enable */
#define ADC_CR2_ALIGN_Pos                   (11U)                              
#define ADC_CR2_ALIGN_Msk                   (0x1UL << ADC_CR2_ALIGN_Pos)        /*!< 0x00000800 */
#define ADC_CR2_ALIGN                       ADC_CR2_ALIGN_Msk                  /*!< ADC data alignement */

#define ADC_CR2_JEXTSEL_Pos                 (12U)                              
#define ADC_CR2_JEXTSEL_Msk                 (0x7UL << ADC_CR2_JEXTSEL_Pos)      /*!< 0x00007000 */
#define ADC_CR2_JEXTSEL                     ADC_CR2_JEXTSEL_Msk                /*!< ADC group injected external trigger source */
#define ADC_CR2_JEXTSEL_0                   (0x1UL << ADC_CR2_JEXTSEL_Pos)      /*!< 0x00001000 */
#define ADC_CR2_JEXTSEL_1                   (0x2UL << ADC_CR2_JEXTSEL_Pos)      /*!< 0x00002000 */
#define ADC_CR2_JEXTSEL_2                   (0x4UL << ADC_CR2_JEXTSEL_Pos)      /*!< 0x00004000 */

#define ADC_CR2_JEXTTRIG_Pos                (15U)                              
#define ADC_CR2_JEXTTRIG_Msk                (0x1UL << ADC_CR2_JEXTTRIG_Pos)     /*!< 0x00008000 */
#define ADC_CR2_JEXTTRIG                    ADC_CR2_JEXTTRIG_Msk               /*!< ADC group injected external trigger enable */

#define ADC_CR2_EXTSEL_Pos                  (17U)                              
#define ADC_CR2_EXTSEL_Msk                  (0x7UL << ADC_CR2_EXTSEL_Pos)       /*!< 0x000E0000 */
#define ADC_CR2_EXTSEL                      ADC_CR2_EXTSEL_Msk                 /*!< ADC group regular external trigger source */
#define ADC_CR2_EXTSEL_0                    (0x1UL << ADC_CR2_EXTSEL_Pos)       /*!< 0x00020000 */
#define ADC_CR2_EXTSEL_1                    (0x2UL << ADC_CR2_EXTSEL_Pos)       /*!< 0x00040000 */
#define ADC_CR2_EXTSEL_2                    (0x4UL << ADC_CR2_EXTSEL_Pos)       /*!< 0x00080000 */

#define ADC_CR2_EXTTRIG_Pos                 (20U)                              
#define ADC_CR2_EXTTRIG_Msk                 (0x1UL << ADC_CR2_EXTTRIG_Pos)      /*!< 0x00100000 */
#define ADC_CR2_EXTTRIG                     ADC_CR2_EXTTRIG_Msk                /*!< ADC group regular external trigger enable */
#define ADC_CR2_JSWSTART_Pos                (21U)                              
#define ADC_CR2_JSWSTART_Msk                (0x1UL << ADC_CR2_JSWSTART_Pos)     /*!< 0x00200000 */
#define ADC_CR2_JSWSTART                    ADC_CR2_JSWSTART_Msk               /*!< ADC group injected conversion start */
#define ADC_CR2_SWSTART_Pos                 (22U)                              
#define ADC_CR2_SWSTART_Msk                 (0x1UL << ADC_CR2_SWSTART_Pos)      /*!< 0x00400000 */
#define ADC_CR2_SWSTART                     ADC_CR2_SWSTART_Msk                /*!< ADC group regular conversion start */
#define ADC_CR2_TSVREFE_Pos                 (23U)                              
#define ADC_CR2_TSVREFE_Msk                 (0x1UL << ADC_CR2_TSVREFE_Pos)      /*!< 0x00800000 */
#define ADC_CR2_TSVREFE                     ADC_CR2_TSVREFE_Msk                /*!< ADC internal path to VrefInt and temperature sensor enable */

/******************  Bit definition for ADC_SMPR1 register  *******************/
#define ADC_SMPR1_SMP10_Pos                 (0U)                               
#define ADC_SMPR1_SMP10_Msk                 (0x7UL << ADC_SMPR1_SMP10_Pos)      /*!< 0x00000007 */
#define ADC_SMPR1_SMP10                     ADC_SMPR1_SMP10_Msk                /*!< ADC channel 10 sampling time selection  */
#define ADC_SMPR1_SMP10_0                   (0x1UL << ADC_SMPR1_SMP10_Pos)      /*!< 0x00000001 */
#define ADC_SMPR1_SMP10_1                   (0x2UL << ADC_SMPR1_SMP10_Pos)      /*!< 0x00000002 */
#define ADC_SMPR1_SMP10_2                   (0x4UL << ADC_SMPR1_SMP10_Pos)      /*!< 0x00000004 */

#define ADC_SMPR1_SMP11_Pos                 (3U)                               
#define ADC_SMPR1_SMP11_Msk                 (0x7UL << ADC_SMPR1_SMP11_Pos)      /*!< 0x00000038 */
#define ADC_SMPR1_SMP11                     ADC_SMPR1_SMP11_Msk                /*!< ADC channel 11 sampling time selection  */
#define ADC_SMPR1_SMP11_0                   (0x1UL << ADC_SMPR1_SMP11_Pos)      /*!< 0x00000008 */
#define ADC_SMPR1_SMP11_1                   (0x2UL << ADC_SMPR1_SMP11_Pos)      /*!< 0x00000010 */
#define ADC_SMPR1_SMP11_2                   (0x4UL << ADC_SMPR1_SMP11_Pos)      /*!< 0x00000020 */

#define ADC_SMPR1_SMP12_Pos                 (6U)                               
#define ADC_SMPR1_SMP12_Msk                 (0x7UL << ADC_SMPR1_SMP12_Pos)      /*!< 0x000001C0 */
#define ADC_SMPR1_SMP12                     ADC_SMPR1_SMP12_Msk                /*!< ADC channel 12 sampling time selection  */
#define ADC_SMPR1_SMP12_0                   (0x1UL << ADC_SMPR1_SMP12_Pos)      /*!< 0x00000040 */
#define ADC_SMPR1_SMP12_1                   (0x2UL << ADC_SMPR1_SMP12_Pos)      /*!< 0x00000080 */
#define ADC_SMPR1_SMP12_2                   (0x4UL << ADC_SMPR1_SMP12_Pos)      /*!< 0x00000100 */

#define ADC_SMPR1_SMP13_Pos                 (9U)                               
#define ADC_SMPR1_SMP13_Msk                 (0x7UL << ADC_SMPR1_SMP13_Pos)      /*!< 0x00000E00 */
#define ADC_SMPR1_SMP13                     ADC_SMPR1_SMP13_Msk                /*!< ADC channel 13 sampling time selection  */
#define ADC_SMPR1_SMP13_0                   (0x1UL << ADC_SMPR1_SMP13_Pos)      /*!< 0x00000200 */
#define ADC_SMPR1_SMP13_1                   (0x2UL << ADC_SMPR1_SMP13_Pos)      /*!< 0x00000400 */
#define ADC_SMPR1_SMP13_2                   (0x4UL << ADC_SMPR1_SMP13_Pos)      /*!< 0x00000800 */

#define ADC_SMPR1_SMP14_Pos                 (12U)                              
#define ADC_SMPR1_SMP14_Msk                 (0x7UL << ADC_SMPR1_SMP14_Pos)      /*!< 0x00007000 */
#define ADC_SMPR1_SMP14                     ADC_SMPR1_SMP14_Msk                /*!< ADC channel 14 sampling time selection  */
#define ADC_SMPR1_SMP14_0                   (0x1UL << ADC_SMPR1_SMP14_Pos)      /*!< 0x00001000 */
#define ADC_SMPR1_SMP14_1                   (0x2UL << ADC_SMPR1_SMP14_Pos)      /*!< 0x00002000 */
#define ADC_SMPR1_SMP14_2                   (0x4UL << ADC_SMPR1_SMP14_Pos)      /*!< 0x00004000 */

#define ADC_SMPR1_SMP15_Pos                 (15U)                              
#define ADC_SMPR1_SMP15_Msk                 (0x7UL << ADC_SMPR1_SMP15_Pos)      /*!< 0x00038000 */
#define ADC_SMPR1_SMP15                     ADC_SMPR1_SMP15_Msk                /*!< ADC channel 15 sampling time selection  */
#define ADC_SMPR1_SMP15_0                   (0x1UL << ADC_SMPR1_SMP15_Pos)      /*!< 0x00008000 */
#define ADC_SMPR1_SMP15_1                   (0x2UL << ADC_SMPR1_SMP15_Pos)      /*!< 0x00010000 */
#define ADC_SMPR1_SMP15_2                   (0x4UL << ADC_SMPR1_SMP15_Pos)      /*!< 0x00020000 */

#define ADC_SMPR1_SMP16_Pos                 (18U)                              
#define ADC_SMPR1_SMP16_Msk                 (0x7UL << ADC_SMPR1_SMP16_Pos)      /*!< 0x001C0000 */
#define ADC_SMPR1_SMP16                     ADC_SMPR1_SMP16_Msk                /*!< ADC channel 16 sampling time selection  */
#define ADC_SMPR1_SMP16_0                   (0x1UL << ADC_SMPR1_SMP16_Pos)      /*!< 0x00040000 */
#define ADC_SMPR1_SMP16_1                   (0x2UL << ADC_SMPR1_SMP16_Pos)      /*!< 0x00080000 */
#define ADC_SMPR1_SMP16_2                   (0x4UL << ADC_SMPR1_SMP16_Pos)      /*!< 0x00100000 */

#define ADC_SMPR1_SMP17_Pos                 (21U)                              
#define ADC_SMPR1_SMP17_Msk                 (0x7UL << ADC_SMPR1_SMP17_Pos)      /*!< 0x00E00000 */
#define ADC_SMPR1_SMP17                     ADC_SMPR1_SMP17_Msk                /*!< ADC channel 17 sampling time selection  */
#define ADC_SMPR1_SMP17_0                   (0x1UL << ADC_SMPR1_SMP17_Pos)      /*!< 0x00200000 */
#define ADC_SMPR1_SMP17_1                   (0x2UL << ADC_SMPR1_SMP17_Pos)      /*!< 0x00400000 */
#define ADC_SMPR1_SMP17_2                   (0x4UL << ADC_SMPR1_SMP17_Pos)      /*!< 0x00800000 */

/******************  Bit definition for ADC_SMPR2 register  *******************/
#define ADC_SMPR2_SMP0_Pos                  (0U)                               
#define ADC_SMPR2_SMP0_Msk                  (0x7UL << ADC_SMPR2_SMP0_Pos)       /*!< 0x00000007 */
#define ADC_SMPR2_SMP0                      ADC_SMPR2_SMP0_Msk                 /*!< ADC channel 0 sampling time selection  */
#define ADC_SMPR2_SMP0_0                    (0x1UL << ADC_SMPR2_SMP0_Pos)       /*!< 0x00000001 */
#define ADC_SMPR2_SMP0_1                    (0x2UL << ADC_SMPR2_SMP0_Pos)       /*!< 0x00000002 */
#define ADC_SMPR2_SMP0_2                    (0x4UL << ADC_SMPR2_SMP0_Pos)       /*!< 0x00000004 */

#define ADC_SMPR2_SMP1_Pos                  (3U)                               
#define ADC_SMPR2_SMP1_Msk                  (0x7UL << ADC_SMPR2_SMP1_Pos)       /*!< 0x00000038 */
#define ADC_SMPR2_SMP1                      ADC_SMPR2_SMP1_Msk                 /*!< ADC channel 1 sampling time selection  */
#define ADC_SMPR2_SMP1_0                    (0x1UL << ADC_SMPR2_SMP1_Pos)       /*!< 0x00000008 */
#define ADC_SMPR2_SMP1_1                    (0x2UL << ADC_SMPR2_SMP1_Pos)       /*!< 0x00000010 */
#define ADC_SMPR2_SMP1_2                    (0x4UL << ADC_SMPR2_SMP1_Pos)       /*!< 0x00000020 */

#define ADC_SMPR2_SMP2_Pos                  (6U)                               
#define ADC_SMPR2_SMP2_Msk                  (0x7UL << ADC_SMPR2_SMP2_Pos)       /*!< 0x000001C0 */
#define ADC_SMPR2_SMP2                      ADC_SMPR2_SMP2_Msk                 /*!< ADC channel 2 sampling time selection  */
#define ADC_SMPR2_SMP2_0                    (0x1UL << ADC_SMPR2_SMP2_Pos)       /*!< 0x00000040 */
#define ADC_SMPR2_SMP2_1                    (0x2UL << ADC_SMPR2_SMP2_Pos)       /*!< 0x00000080 */
#define ADC_SMPR2_SMP2_2                    (0x4UL << ADC_SMPR2_SMP2_Pos)       /*!< 0x00000100 */

#define ADC_SMPR2_SMP3_Pos                  (9U)                               
#define ADC_SMPR2_SMP3_Msk                  (0x7UL << ADC_SMPR2_SMP3_Pos)       /*!< 0x00000E00 */
#define ADC_SMPR2_SMP3                      ADC_SMPR2_SMP3_Msk                 /*!< ADC channel 3 sampling time selection  */
#define ADC_SMPR2_SMP3_0                    (0x1UL << ADC_SMPR2_SMP3_Pos)       /*!< 0x00000200 */
#define ADC_SMPR2_SMP3_1                    (0x2UL << ADC_SMPR2_SMP3_Pos)       /*!< 0x00000400 */
#define ADC_SMPR2_SMP3_2                    (0x4UL << ADC_SMPR2_SMP3_Pos)       /*!< 0x00000800 */

#define ADC_SMPR2_SMP4_Pos                  (12U)                              
#define ADC_SMPR2_SMP4_Msk                  (0x7UL << ADC_SMPR2_SMP4_Pos)       /*!< 0x00007000 */
#define ADC_SMPR2_SMP4                      ADC_SMPR2_SMP4_Msk                 /*!< ADC channel 4 sampling time selection  */
#define ADC_SMPR2_SMP4_0                    (0x1UL << ADC_SMPR2_SMP4_Pos)       /*!< 0x00001000 */
#define ADC_SMPR2_SMP4_1                    (0x2UL << ADC_SMPR2_SMP4_Pos)       /*!< 0x00002000 */
#define ADC_SMPR2_SMP4_2                    (0x4UL << ADC_SMPR2_SMP4_Pos)       /*!< 0x00004000 */

#define ADC_SMPR2_SMP5_Pos                  (15U)                              
#define ADC_SMPR2_SMP5_Msk                  (0x7UL << ADC_SMPR2_SMP5_Pos)       /*!< 0x00038000 */
#define ADC_SMPR2_SMP5                      ADC_SMPR2_SMP5_Msk                 /*!< ADC channel 5 sampling time selection  */
#define ADC_SMPR2_SMP5_0                    (0x1UL << ADC_SMPR2_SMP5_Pos)       /*!< 0x00008000 */
#define ADC_SMPR2_SMP5_1                    (0x2UL << ADC_SMPR2_SMP5_Pos)       /*!< 0x00010000 */
#define ADC_SMPR2_SMP5_2                    (0x4UL << ADC_SMPR2_SMP5_Pos)       /*!< 0x00020000 */

#define ADC_SMPR2_SMP6_Pos                  (18U)                              
#define ADC_SMPR2_SMP6_Msk                  (0x7UL << ADC_SMPR2_SMP6_Pos)       /*!< 0x001C0000 */
#define ADC_SMPR2_SMP6                      ADC_SMPR2_SMP6_Msk                 /*!< ADC channel 6 sampling time selection  */
#define ADC_SMPR2_SMP6_0                    (0x1UL << ADC_SMPR2_SMP6_Pos)       /*!< 0x00040000 */
#define ADC_SMPR2_SMP6_1                    (0x2UL << ADC_SMPR2_SMP6_Pos)       /*!< 0x00080000 */
#define ADC_SMPR2_SMP6_2                    (0x4UL << ADC_SMPR2_SMP6_Pos)       /*!< 0x00100000 */

#define ADC_SMPR2_SMP7_Pos                  (21U)                              
#define ADC_SMPR2_SMP7_Msk                  (0x7UL << ADC_SMPR2_SMP7_Pos)       /*!< 0x00E00000 */
#define ADC_SMPR2_SMP7                      ADC_SMPR2_SMP7_Msk                 /*!< ADC channel 7 sampling time selection  */
#define ADC_SMPR2_SMP7_0                    (0x1UL << ADC_SMPR2_SMP7_Pos)       /*!< 0x00200000 */
#define ADC_SMPR2_SMP7_1                    (0x2UL << ADC_SMPR2_SMP7_Pos)       /*!< 0x00400000 */
#define ADC_SMPR2_SMP7_2                    (0x4UL << ADC_SMPR2_SMP7_Pos)       /*!< 0x00800000 */

#define ADC_SMPR2_SMP8_Pos                  (24U)                              
#define ADC_SMPR2_SMP8_Msk                  (0x7UL << ADC_SMPR2_SMP8_Pos)       /*!< 0x07000000 */
#define ADC_SMPR2_SMP8                      ADC_SMPR2_SMP8_Msk                 /*!< ADC channel 8 sampling time selection  */
#define ADC_SMPR2_SMP8_0                    (0x1UL << ADC_SMPR2_SMP8_Pos)       /*!< 0x01000000 */
#define ADC_SMPR2_SMP8_1                    (0x2UL << ADC_SMPR2_SMP8_Pos)       /*!< 0x02000000 */
#define ADC_SMPR2_SMP8_2                    (0x4UL << ADC_SMPR2_SMP8_Pos)       /*!< 0x04000000 */

#define ADC_SMPR2_SMP9_Pos                  (27U)                              
#define ADC_SMPR2_SMP9_Msk                  (0x7UL << ADC_SMPR2_SMP9_Pos)       /*!< 0x38000000 */
#define ADC_SMPR2_SMP9                      ADC_SMPR2_SMP9_Msk                 /*!< ADC channel 9 sampling time selection  */
#define ADC_SMPR2_SMP9_0                    (0x1UL << ADC_SMPR2_SMP9_Pos)       /*!< 0x08000000 */
#define ADC_SMPR2_SMP9_1                    (0x2UL << ADC_SMPR2_SMP9_Pos)       /*!< 0x10000000 */
#define ADC_SMPR2_SMP9_2                    (0x4UL << ADC_SMPR2_SMP9_Pos)       /*!< 0x20000000 */

/******************  Bit definition for ADC_JOFR1 register  *******************/
#define ADC_JOFR1_JOFFSET1_Pos              (0U)                               
#define ADC_JOFR1_JOFFSET1_Msk              (0xFFFUL << ADC_JOFR1_JOFFSET1_Pos) /*!< 0x00000FFF */
#define ADC_JOFR1_JOFFSET1                  ADC_JOFR1_JOFFSET1_Msk             /*!< ADC group injected sequencer rank 1 offset value */

/******************  Bit definition for ADC_JOFR2 register  *******************/
#define ADC_JOFR2_JOFFSET2_Pos              (0U)                               
#define ADC_JOFR2_JOFFSET2_Msk              (0xFFFUL << ADC_JOFR2_JOFFSET2_Pos) /*!< 0x00000FFF */
#define ADC_JOFR2_JOFFSET2                  ADC_JOFR2_JOFFSET2_Msk             /*!< ADC group injected sequencer rank 2 offset value */

/******************  Bit definition for ADC_JOFR3 register  *******************/
#define ADC_JOFR3_JOFFSET3_Pos              (0U)                               
#define ADC_JOFR3_JOFFSET3_Msk              (0xFFFUL << ADC_JOFR3_JOFFSET3_Pos) /*!< 0x00000FFF */
#define ADC_JOFR3_JOFFSET3                  ADC_JOFR3_JOFFSET3_Msk             /*!< ADC group injected sequencer rank 3 offset value */

/******************  Bit definition for ADC_JOFR4 register  *******************/
#define ADC_JOFR4_JOFFSET4_Pos              (0U)                               
#define ADC_JOFR4_JOFFSET4_Msk              (0xFFFUL << ADC_JOFR4_JOFFSET4_Pos) /*!< 0x00000FFF */
#define ADC_JOFR4_JOFFSET4                  ADC_JOFR4_JOFFSET4_Msk             /*!< ADC group injected sequencer rank 4 offset value */

/*******************  Bit definition for ADC_HTR register  ********************/
#define ADC_HTR_HT_Pos                      (0U)                               
#define ADC_HTR_HT_Msk                      (0xFFFUL << ADC_HTR_HT_Pos)         /*!< 0x00000FFF */
#define ADC_HTR_HT                          ADC_HTR_HT_Msk                     /*!< ADC analog watchdog 1 threshold high */

/*******************  Bit definition for ADC_LTR register  ********************/
#define ADC_LTR_LT_Pos                      (0U)                               
#define ADC_LTR_LT_Msk                      (0xFFFUL << ADC_LTR_LT_Pos)         /*!< 0x00000FFF */
#define ADC_LTR_LT                          ADC_LTR_LT_Msk                     /*!< ADC analog watchdog 1 threshold low */

/*******************  Bit definition for ADC_SQR1 register  *******************/
#define ADC_SQR1_SQ13_Pos                   (0U)                               
#define ADC_SQR1_SQ13_Msk                   (0x1FUL << ADC_SQR1_SQ13_Pos)       /*!< 0x0000001F */
#define ADC_SQR1_SQ13                       ADC_SQR1_SQ13_Msk                  /*!< ADC group regular sequencer rank 13 */
#define ADC_SQR1_SQ13_0                     (0x01UL << ADC_SQR1_SQ13_Pos)       /*!< 0x00000001 */
#define ADC_SQR1_SQ13_1                     (0x02UL << ADC_SQR1_SQ13_Pos)       /*!< 0x00000002 */
#define ADC_SQR1_SQ13_2                     (0x04UL << ADC_SQR1_SQ13_Pos)       /*!< 0x00000004 */
#define ADC_SQR1_SQ13_3                     (0x08UL << ADC_SQR1_SQ13_Pos)       /*!< 0x00000008 */
#define ADC_SQR1_SQ13_4                     (0x10UL << ADC_SQR1_SQ13_Pos)       /*!< 0x00000010 */

#define ADC_SQR1_SQ14_Pos                   (5U)                               
#define ADC_SQR1_SQ14_Msk                   (0x1FUL << ADC_SQR1_SQ14_Pos)       /*!< 0x000003E0 */
#define ADC_SQR1_SQ14                       ADC_SQR1_SQ14_Msk                  /*!< ADC group regular sequencer rank 14 */
#define ADC_SQR1_SQ14_0                     (0x01UL << ADC_SQR1_SQ14_Pos)       /*!< 0x00000020 */
#define ADC_SQR1_SQ14_1                     (0x02UL << ADC_SQR1_SQ14_Pos)       /*!< 0x00000040 */
#define ADC_SQR1_SQ14_2                     (0x04UL << ADC_SQR1_SQ14_Pos)       /*!< 0x00000080 */
#define ADC_SQR1_SQ14_3                     (0x08UL << ADC_SQR1_SQ14_Pos)       /*!< 0x00000100 */
#define ADC_SQR1_SQ14_4                     (0x10UL << ADC_SQR1_SQ14_Pos)       /*!< 0x00000200 */

#define ADC_SQR1_SQ15_Pos                   (10U)                              
#define ADC_SQR1_SQ15_Msk                   (0x1FUL << ADC_SQR1_SQ15_Pos)       /*!< 0x00007C00 */
#define ADC_SQR1_SQ15                       ADC_SQR1_SQ15_Msk                  /*!< ADC group regular sequencer rank 15 */
#define ADC_SQR1_SQ15_0                     (0x01UL << ADC_SQR1_SQ15_Pos)       /*!< 0x00000400 */
#define ADC_SQR1_SQ15_1                     (0x02UL << ADC_SQR1_SQ15_Pos)       /*!< 0x00000800 */
#define ADC_SQR1_SQ15_2                     (0x04UL << ADC_SQR1_SQ15_Pos)       /*!< 0x00001000 */
#define ADC_SQR1_SQ15_3                     (0x08UL << ADC_SQR1_SQ15_Pos)       /*!< 0x00002000 */
#define ADC_SQR1_SQ15_4                     (0x10UL << ADC_SQR1_SQ15_Pos)       /*!< 0x00004000 */

#define ADC_SQR1_SQ16_Pos                   (15U)                              
#define ADC_SQR1_SQ16_Msk                   (0x1FUL << ADC_SQR1_SQ16_Pos)       /*!< 0x000F8000 */
#define ADC_SQR1_SQ16                       ADC_SQR1_SQ16_Msk                  /*!< ADC group regular sequencer rank 16 */
#define ADC_SQR1_SQ16_0                     (0x01UL << ADC_SQR1_SQ16_Pos)       /*!< 0x00008000 */
#define ADC_SQR1_SQ16_1                     (0x02UL << ADC_SQR1_SQ16_Pos)       /*!< 0x00010000 */
#define ADC_SQR1_SQ16_2                     (0x04UL << ADC_SQR1_SQ16_Pos)       /*!< 0x00020000 */
#define ADC_SQR1_SQ16_3                     (0x08UL << ADC_SQR1_SQ16_Pos)       /*!< 0x00040000 */
#define ADC_SQR1_SQ16_4                     (0x10UL << ADC_SQR1_SQ16_Pos)       /*!< 0x00080000 */

#define ADC_SQR1_L_Pos                      (20U)                              
#define ADC_SQR1_L_Msk                      (0xFUL << ADC_SQR1_L_Pos)           /*!< 0x00F00000 */
#define ADC_SQR1_L                          ADC_SQR1_L_Msk                     /*!< ADC group regular sequencer scan length */
#define ADC_SQR1_L_0                        (0x1UL << ADC_SQR1_L_Pos)           /*!< 0x00100000 */
#define ADC_SQR1_L_1                        (0x2UL << ADC_SQR1_L_Pos)           /*!< 0x00200000 */
#define ADC_SQR1_L_2                        (0x4UL << ADC_SQR1_L_Pos)           /*!< 0x00400000 */
#define ADC_SQR1_L_3                        (0x8UL << ADC_SQR1_L_Pos)           /*!< 0x00800000 */

/*******************  Bit definition for ADC_SQR2 register  *******************/
#define ADC_SQR2_SQ7_Pos                    (0U)                               
#define ADC_SQR2_SQ7_Msk                    (0x1FUL << ADC_SQR2_SQ7_Pos)        /*!< 0x0000001F */
#define ADC_SQR2_SQ7                        ADC_SQR2_SQ7_Msk                   /*!< ADC group regular sequencer rank 7 */
#define ADC_SQR2_SQ7_0                      (0x01UL << ADC_SQR2_SQ7_Pos)        /*!< 0x00000001 */
#define ADC_SQR2_SQ7_1                      (0x02UL << ADC_SQR2_SQ7_Pos)        /*!< 0x00000002 */
#define ADC_SQR2_SQ7_2                      (0x04UL << ADC_SQR2_SQ7_Pos)        /*!< 0x00000004 */
#define ADC_SQR2_SQ7_3                      (0x08UL << ADC_SQR2_SQ7_Pos)        /*!< 0x00000008 */
#define ADC_SQR2_SQ7_4                      (0x10UL << ADC_SQR2_SQ7_Pos)        /*!< 0x00000010 */

#define ADC_SQR2_SQ8_Pos                    (5U)                               
#define ADC_SQR2_SQ8_Msk                    (0x1FUL << ADC_SQR2_SQ8_Pos)        /*!< 0x000003E0 */
#define ADC_SQR2_SQ8                        ADC_SQR2_SQ8_Msk                   /*!< ADC group regular sequencer rank 8 */
#define ADC_SQR2_SQ8_0                      (0x01UL << ADC_SQR2_SQ8_Pos)        /*!< 0x00000020 */
#define ADC_SQR2_SQ8_1                      (0x02UL << ADC_SQR2_SQ8_Pos)        /*!< 0x00000040 */
#define ADC_SQR2_SQ8_2                      (0x04UL << ADC_SQR2_SQ8_Pos)        /*!< 0x00000080 */
#define ADC_SQR2_SQ8_3                      (0x08UL << ADC_SQR2_SQ8_Pos)        /*!< 0x00000100 */
#define ADC_SQR2_SQ8_4                      (0x10UL << ADC_SQR2_SQ8_Pos)        /*!< 0x00000200 */

#define ADC_SQR2_SQ9_Pos                    (10U)                              
#define ADC_SQR2_SQ9_Msk                    (0x1FUL << ADC_SQR2_SQ9_Pos)        /*!< 0x00007C00 */
#define ADC_SQR2_SQ9                        ADC_SQR2_SQ9_Msk                   /*!< ADC group regular sequencer rank 9 */
#define ADC_SQR2_SQ9_0                      (0x01UL << ADC_SQR2_SQ9_Pos)        /*!< 0x00000400 */
#define ADC_SQR2_SQ9_1                      (0x02UL << ADC_SQR2_SQ9_Pos)        /*!< 0x00000800 */
#define ADC_SQR2_SQ9_2                      (0x04UL << ADC_SQR2_SQ9_Pos)        /*!< 0x00001000 */
#define ADC_SQR2_SQ9_3                      (0x08UL << ADC_SQR2_SQ9_Pos)        /*!< 0x00002000 */
#define ADC_SQR2_SQ9_4                      (0x10UL << ADC_SQR2_SQ9_Pos)        /*!< 0x00004000 */

#define ADC_SQR2_SQ10_Pos                   (15U)                              
#define ADC_SQR2_SQ10_Msk                   (0x1FUL << ADC_SQR2_SQ10_Pos)       /*!< 0x000F8000 */
#define ADC_SQR2_SQ10                       ADC_SQR2_SQ10_Msk                  /*!< ADC group regular sequencer rank 10 */
#define ADC_SQR2_SQ10_0                     (0x01UL << ADC_SQR2_SQ10_Pos)       /*!< 0x00008000 */
#define ADC_SQR2_SQ10_1                     (0x02UL << ADC_SQR2_SQ10_Pos)       /*!< 0x00010000 */
#define ADC_SQR2_SQ10_2                     (0x04UL << ADC_SQR2_SQ10_Pos)       /*!< 0x00020000 */
#define ADC_SQR2_SQ10_3                     (0x08UL << ADC_SQR2_SQ10_Pos)       /*!< 0x00040000 */
#define ADC_SQR2_SQ10_4                     (0x10UL << ADC_SQR2_SQ10_Pos)       /*!< 0x00080000 */

#define ADC_SQR2_SQ11_Pos                   (20U)                              
#define ADC_SQR2_SQ11_Msk                   (0x1FUL << ADC_SQR2_SQ11_Pos)       /*!< 0x01F00000 */
#define ADC_SQR2_SQ11                       ADC_SQR2_SQ11_Msk                  /*!< ADC group regular sequencer rank 1 */
#define ADC_SQR2_SQ11_0                     (0x01UL << ADC_SQR2_SQ11_Pos)       /*!< 0x00100000 */
#define ADC_SQR2_SQ11_1                     (0x02UL << ADC_SQR2_SQ11_Pos)       /*!< 0x00200000 */
#define ADC_SQR2_SQ11_2                     (0x04UL << ADC_SQR2_SQ11_Pos)       /*!< 0x00400000 */
#define ADC_SQR2_SQ11_3                     (0x08UL << ADC_SQR2_SQ11_Pos)       /*!< 0x00800000 */
#define ADC_SQR2_SQ11_4                     (0x10UL << ADC_SQR2_SQ11_Pos)       /*!< 0x01000000 */

#define ADC_SQR2_SQ12_Pos                   (25U)                              
#define ADC_SQR2_SQ12_Msk                   (0x1FUL << ADC_SQR2_SQ12_Pos)       /*!< 0x3E000000 */
#define ADC_SQR2_SQ12                       ADC_SQR2_SQ12_Msk                  /*!< ADC group regular sequencer rank 12 */
#define ADC_SQR2_SQ12_0                     (0x01UL << ADC_SQR2_SQ12_Pos)       /*!< 0x02000000 */
#define ADC_SQR2_SQ12_1                     (0x02UL << ADC_SQR2_SQ12_Pos)       /*!< 0x04000000 */
#define ADC_SQR2_SQ12_2                     (0x04UL << ADC_SQR2_SQ12_Pos)       /*!< 0x08000000 */
#define ADC_SQR2_SQ12_3                     (0x08UL << ADC_SQR2_SQ12_Pos)       /*!< 0x10000000 */
#define ADC_SQR2_SQ12_4                     (0x10UL << ADC_SQR2_SQ12_Pos)       /*!< 0x20000000 */

/*******************  Bit definition for ADC_SQR3 register  *******************/
#define ADC_SQR3_SQ1_Pos                    (0U)                               
#define ADC_SQR3_SQ1_Msk                    (0x1FUL << ADC_SQR3_SQ1_Pos)        /*!< 0x0000001F */
#define ADC_SQR3_SQ1                        ADC_SQR3_SQ1_Msk                   /*!< ADC group regular sequencer rank 1 */
#define ADC_SQR3_SQ1_0                      (0x01UL << ADC_SQR3_SQ1_Pos)        /*!< 0x00000001 */
#define ADC_SQR3_SQ1_1                      (0x02UL << ADC_SQR3_SQ1_Pos)        /*!< 0x00000002 */
#define ADC_SQR3_SQ1_2                      (0x04UL << ADC_SQR3_SQ1_Pos)        /*!< 0x00000004 */
#define ADC_SQR3_SQ1_3                      (0x08UL << ADC_SQR3_SQ1_Pos)        /*!< 0x00000008 */
#define ADC_SQR3_SQ1_4                      (0x10UL << ADC_SQR3_SQ1_Pos)        /*!< 0x00000010 */

#define ADC_SQR3_SQ2_Pos                    (5U)                               
#define ADC_SQR3_SQ2_Msk                    (0x1FUL << ADC_SQR3_SQ2_Pos)        /*!< 0x000003E0 */
#define ADC_SQR3_SQ2                        ADC_SQR3_SQ2_Msk                   /*!< ADC group regular sequencer rank 2 */
#define ADC_SQR3_SQ2_0                      (0x01UL << ADC_SQR3_SQ2_Pos)        /*!< 0x00000020 */
#define ADC_SQR3_SQ2_1                      (0x02UL << ADC_SQR3_SQ2_Pos)        /*!< 0x00000040 */
#define ADC_SQR3_SQ2_2                      (0x04UL << ADC_SQR3_SQ2_Pos)        /*!< 0x00000080 */
#define ADC_SQR3_SQ2_3                      (0x08UL << ADC_SQR3_SQ2_Pos)        /*!< 0x00000100 */
#define ADC_SQR3_SQ2_4                      (0x10UL << ADC_SQR3_SQ2_Pos)        /*!< 0x00000200 */

#define ADC_SQR3_SQ3_Pos                    (10U)                              
#define ADC_SQR3_SQ3_Msk                    (0x1FUL << ADC_SQR3_SQ3_Pos)        /*!< 0x00007C00 */
#define ADC_SQR3_SQ3                        ADC_SQR3_SQ3_Msk                   /*!< ADC group regular sequencer rank 3 */
#define ADC_SQR3_SQ3_0                      (0x01UL << ADC_SQR3_SQ3_Pos)        /*!< 0x00000400 */
#define ADC_SQR3_SQ3_1                      (0x02UL << ADC_SQR3_SQ3_Pos)        /*!< 0x00000800 */
#define ADC_SQR3_SQ3_2                      (0x04UL << ADC_SQR3_SQ3_Pos)        /*!< 0x00001000 */
#define ADC_SQR3_SQ3_3                      (0x08UL << ADC_SQR3_SQ3_Pos)        /*!< 0x00002000 */
#define ADC_SQR3_SQ3_4                      (0x10UL << ADC_SQR3_SQ3_Pos)        /*!< 0x00004000 */

#define ADC_SQR3_SQ4_Pos                    (15U)                              
#define ADC_SQR3_SQ4_Msk                    (0x1FUL << ADC_SQR3_SQ4_Pos)        /*!< 0x000F8000 */
#define ADC_SQR3_SQ4                        ADC_SQR3_SQ4_Msk                   /*!< ADC group regular sequencer rank 4 */
#define ADC_SQR3_SQ4_0                      (0x01UL << ADC_SQR3_SQ4_Pos)        /*!< 0x00008000 */
#define ADC_SQR3_SQ4_1                      (0x02UL << ADC_SQR3_SQ4_Pos)        /*!< 0x00010000 */
#define ADC_SQR3_SQ4_2                      (0x04UL << ADC_SQR3_SQ4_Pos)        /*!< 0x00020000 */
#define ADC_SQR3_SQ4_3                      (0x08UL << ADC_SQR3_SQ4_Pos)        /*!< 0x00040000 */
#define ADC_SQR3_SQ4_4                      (0x10UL << ADC_SQR3_SQ4_Pos)        /*!< 0x00080000 */

#define ADC_SQR3_SQ5_Pos                    (20U)                              
#define ADC_SQR3_SQ5_Msk                    (0x1FUL << ADC_SQR3_SQ5_Pos)        /*!< 0x01F00000 */
#define ADC_SQR3_SQ5                        ADC_SQR3_SQ5_Msk                   /*!< ADC group regular sequencer rank 5 */
#define ADC_SQR3_SQ5_0                      (0x01UL << ADC_SQR3_SQ5_Pos)        /*!< 0x00100000 */
#define ADC_SQR3_SQ5_1                      (0x02UL << ADC_SQR3_SQ5_Pos)        /*!< 0x00200000 */
#define ADC_SQR3_SQ5_2                      (0x04UL << ADC_SQR3_SQ5_Pos)        /*!< 0x00400000 */
#define ADC_SQR3_SQ5_3                      (0x08UL << ADC_SQR3_SQ5_Pos)        /*!< 0x00800000 */
#define ADC_SQR3_SQ5_4                      (0x10UL << ADC_SQR3_SQ5_Pos)        /*!< 0x01000000 */

#define ADC_SQR3_SQ6_Pos                    (25U)                              
#define ADC_SQR3_SQ6_Msk                    (0x1FUL << ADC_SQR3_SQ6_Pos)        /*!< 0x3E000000 */
#define ADC_SQR3_SQ6                        ADC_SQR3_SQ6_Msk                   /*!< ADC group regular sequencer rank 6 */
#define ADC_SQR3_SQ6_0                      (0x01UL << ADC_SQR3_SQ6_Pos)        /*!< 0x02000000 */
#define ADC_SQR3_SQ6_1                      (0x02UL << ADC_SQR3_SQ6_Pos)        /*!< 0x04000000 */
#define ADC_SQR3_SQ6_2                      (0x04UL << ADC_SQR3_SQ6_Pos)        /*!< 0x08000000 */
#define ADC_SQR3_SQ6_3                      (0x08UL << ADC_SQR3_SQ6_Pos)        /*!< 0x10000000 */
#define ADC_SQR3_SQ6_4                      (0x10UL << ADC_SQR3_SQ6_Pos)        /*!< 0x20000000 */

/*******************  Bit definition for ADC_JSQR register  *******************/
#define ADC_JSQR_JSQ1_Pos                   (0U)                               
#define ADC_JSQR_JSQ1_Msk                   (0x1FUL << ADC_JSQR_JSQ1_Pos)       /*!< 0x0000001F */
#define ADC_JSQR_JSQ1                       ADC_JSQR_JSQ1_Msk                  /*!< ADC group injected sequencer rank 1 */
#define ADC_JSQR_JSQ1_0                     (0x01UL << ADC_JSQR_JSQ1_Pos)       /*!< 0x00000001 */
#define ADC_JSQR_JSQ1_1                     (0x02UL << ADC_JSQR_JSQ1_Pos)       /*!< 0x00000002 */
#define ADC_JSQR_JSQ1_2                     (0x04UL << ADC_JSQR_JSQ1_Pos)       /*!< 0x00000004 */
#define ADC_JSQR_JSQ1_3                     (0x08UL << ADC_JSQR_JSQ1_Pos)       /*!< 0x00000008 */
#define ADC_JSQR_JSQ1_4                     (0x10UL << ADC_JSQR_JSQ1_Pos)       /*!< 0x00000010 */

#define ADC_JSQR_JSQ2_Pos                   (5U)                               
#define ADC_JSQR_JSQ2_Msk                   (0x1FUL << ADC_JSQR_JSQ2_Pos)       /*!< 0x000003E0 */
#define ADC_JSQR_JSQ2                       ADC_JSQR_JSQ2_Msk                  /*!< ADC group injected sequencer rank 2 */
#define ADC_JSQR_JSQ2_0                     (0x01UL << ADC_JSQR_JSQ2_Pos)       /*!< 0x00000020 */
#define ADC_JSQR_JSQ2_1                     (0x02UL << ADC_JSQR_JSQ2_Pos)       /*!< 0x00000040 */
#define ADC_JSQR_JSQ2_2                     (0x04UL << ADC_JSQR_JSQ2_Pos)       /*!< 0x00000080 */
#define ADC_JSQR_JSQ2_3                     (0x08UL << ADC_JSQR_JSQ2_Pos)       /*!< 0x00000100 */
#define ADC_JSQR_JSQ2_4                     (0x10UL << ADC_JSQR_JSQ2_Pos)       /*!< 0x00000200 */

#define ADC_JSQR_JSQ3_Pos                   (10U)                              
#define ADC_JSQR_JSQ3_Msk                   (0x1FUL << ADC_JSQR_JSQ3_Pos)       /*!< 0x00007C00 */
#define ADC_JSQR_JSQ3                       ADC_JSQR_JSQ3_Msk                  /*!< ADC group injected sequencer rank 3 */
#define ADC_JSQR_JSQ3_0                     (0x01UL << ADC_JSQR_JSQ3_Pos)       /*!< 0x00000400 */
#define ADC_JSQR_JSQ3_1                     (0x02UL << ADC_JSQR_JSQ3_Pos)       /*!< 0x00000800 */
#define ADC_JSQR_JSQ3_2                     (0x04UL << ADC_JSQR_JSQ3_Pos)       /*!< 0x00001000 */
#define ADC_JSQR_JSQ3_3                     (0x08UL << ADC_JSQR_JSQ3_Pos)       /*!< 0x00002000 */
#define ADC_JSQR_JSQ3_4                     (0x10UL << ADC_JSQR_JSQ3_Pos)       /*!< 0x00004000 */

#define ADC_JSQR_JSQ4_Pos                   (15U)                              
#define ADC_JSQR_JSQ4_Msk                   (0x1FUL << ADC_JSQR_JSQ4_Pos)       /*!< 0x000F8000 */
#define ADC_JSQR_JSQ4                       ADC_JSQR_JSQ4_Msk                  /*!< ADC group injected sequencer rank 4 */
#define ADC_JSQR_JSQ4_0                     (0x01UL << ADC_JSQR_JSQ4_Pos)       /*!< 0x00008000 */
#define ADC_JSQR_JSQ4_1                     (0x02UL << ADC_JSQR_JSQ4_Pos)       /*!< 0x00010000 */
#define ADC_JSQR_JSQ4_2                     (0x04UL << ADC_JSQR_JSQ4_Pos)       /*!< 0x00020000 */
#define ADC_JSQR_JSQ4_3                     (0x08UL << ADC_JSQR_JSQ4_Pos)       /*!< 0x00040000 */
#define ADC_JSQR_JSQ4_4                     (0x10UL << ADC_JSQR_JSQ4_Pos)       /*!< 0x00080000 */

#define ADC_JSQR_JL_Pos                     (20U)                              
#define ADC_JSQR_JL_Msk                     (0x3UL << ADC_JSQR_JL_Pos)          /*!< 0x00300000 */
#define ADC_JSQR_JL                         ADC_JSQR_JL_Msk                    /*!< ADC group injected sequencer scan length */
#define ADC_JSQR_JL_0                       (0x1UL << ADC_JSQR_JL_Pos)          /*!< 0x00100000 */
#define ADC_JSQR_JL_1                       (0x2UL << ADC_JSQR_JL_Pos)          /*!< 0x00200000 */

/*******************  Bit definition for ADC_JDR1 register  *******************/
#define ADC_JDR1_JDATA_Pos                  (0U)                               
#define ADC_JDR1_JDATA_Msk                  (0xFFFFUL << ADC_JDR1_JDATA_Pos)    /*!< 0x0000FFFF */
#define ADC_JDR1_JDATA                      ADC_JDR1_JDATA_Msk                 /*!< ADC group injected sequencer rank 1 conversion data */

/*******************  Bit definition for ADC_JDR2 register  *******************/
#define ADC_JDR2_JDATA_Pos                  (0U)                               
#define ADC_JDR2_JDATA_Msk                  (0xFFFFUL << ADC_JDR2_JDATA_Pos)    /*!< 0x0000FFFF */
#define ADC_JDR2_JDATA                      ADC_JDR2_JDATA_Msk                 /*!< ADC group injected sequencer rank 2 conversion data */

/*******************  Bit definition for ADC_JDR3 register  *******************/
#define ADC_JDR3_JDATA_Pos                  (0U)                               
#define ADC_JDR3_JDATA_Msk                  (0xFFFFUL << ADC_JDR3_JDATA_Pos)    /*!< 0x0000FFFF */
#define ADC_JDR3_JDATA                      ADC_JDR3_JDATA_Msk                 /*!< ADC group injected sequencer rank 3 conversion data */

/*******************  Bit definition for ADC_JDR4 register  *******************/
#define ADC_JDR4_JDATA_Pos                  (0U)                               
#define ADC_JDR4_JDATA_Msk                  (0xFFFFUL << ADC_JDR4_JDATA_Pos)    /*!< 0x0000FFFF */
#define ADC_JDR4_JDATA                      ADC_JDR4_JDATA_Msk                 /*!< ADC group injected sequencer rank 4 conversion data */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_DATA_Pos                     (0U)                               
#define ADC_DR_DATA_Msk                     (0xFFFFUL << ADC_DR_DATA_Pos)       /*!< 0x0000FFFF */
#define ADC_DR_DATA                         ADC_DR_DATA_Msk                    /*!< ADC group regular conversion data */
#define ADC_DR_ADC2DATA_Pos                 (16U)                              
#define ADC_DR_ADC2DATA_Msk                 (0xFFFFUL << ADC_DR_ADC2DATA_Pos)   /*!< 0xFFFF0000 */
#define ADC_DR_ADC2DATA                     ADC_DR_ADC2DATA_Msk                /*!< ADC group regular conversion data for ADC slave, in multimode */

// 레지스터 목록
namespace ADC_REG
{
enum
{
	SR = 0, CR1, CR2, SMPR1, SMPR2, JOFR1, JOFR2, JOFR3, JOFR4, HTR, LTR, SQR1, 
	SQR2, SQR3, JSQR, JDR1, JDR2, JDR3, JDR4, DR
};
}
#endif

