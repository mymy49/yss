/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
/**
 * @file Dma.h
 * @brief DMA (Direct Memory Access) controller driver class selector header file.
 *
 * @details
 * This file is a configuration selector that includes the target-specific DMA controller driver class definitions (e.g. Nuvoton M480/M4xx series or ST Microelectronics STM32 series).
 *
 * ### Common Methods Exposed by DMA Classes
 * Target DMA channel implementations typically provide APIs to request channel allocation, configure transfer directions (memory-to-memory, peripheral-to-memory, memory-to-peripheral), register callback handlers, set transfer parameters, and poll for transfer completion status.
 *
 * ### DMA Allocation & Transfer Flow (Background Context)
 * Direct Memory Access (DMA) is used in background transfers for high-speed peripherals like SPI, I2C, UART, and I2S. Peripherals automatically allocate DMA channels during initialization.
 *
 * ### Usage Example (Low-level DMA Setup)
 * @code
 * // Request/allocate a DMA channel from the system
 * Dma *myDma = system::allocateDma();
 * 
 * if (myDma != nullptr)
 * {
 *     Dma::dmaInfo_t dmaInfo;
 *     // Configure DMA parameters (source, destination, options)
 *     dmaInfo.src = (void *)&USART2->TX;
 *     dmaInfo.ctl = ...; // Control register flags
 *     
 *     // Ready the DMA channel with destination pointer and transfer size
 *     myDma->ready(dmaInfo, txBuffer, bufferSize);
 *     
 *     // Wait/yield thread until transfer is complete
 *     while (!myDma->isComplete())
 *     {
 *         thread::yield();
 *     }
 * }
 * @endcode
 */

#ifndef YSS_DRV_DMA__H_
#define YSS_DRV_DMA__H_

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M25x_FAMILY)
#include <targets/nuvoton/NuvotonDma.h>
#endif

#endif

