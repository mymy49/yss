/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file Dma2d.h
 * @brief DMA2D (Chrom-Art Accelerator) driver class header file.
 */

#ifndef YSS_DRV_DMA2D__H_
#define YSS_DRV_DMA2D__H_

#include "peripheral.h"
#include <stdint.h>

#if defined(DMA2D) && (defined(STM32F7) || defined(STM32F4))

typedef DMA2D_TypeDef		YSS_DMA2D_Peri;

#else

#define YSS_DRV_DMA2D_UNSUPPORTED
typedef volatile uint32_t	YSS_DMA2D_Peri;

#endif

#include "Drv.h"
#include <yss/error.h>
#include <gui/util.h>
#include <yss/scheduler.h>

/**
 * @class Dma2d
 * @brief Driver class for the DMA2D graphic accelerator.
 * 
 * @details
 * This driver class provides interface functions to perform accelerated 2D graphics
 * operations, such as color filling, copying/transferring image buffers, color space conversion,
 * alpha blending, and character rendering.
 */
class Dma2d : public Drv
{
	YSS_DMA2D_Peri *mPeri;             ///< Pointer to the hardware DMA2D instance.
	threadId_t  mThreadId;             ///< Thread ID of the waiting thread.
	bool mCompleteFlag, mErrorFlag;    ///< Transfer complete and error status flags.

  public:
	
	/**
	 * @struct setup_t
	 * @brief Hardware setup configuration structure for DMA2D.
	 */
	struct setup_t
	{
		YSS_DMA2D_Peri *peri;      ///< Pointer to the DMA2D hardware register structure.
	};

	/**
	 * @struct FillConfig
	 * @brief Configuration structure for color filling operations.
	 */
	struct FillConfig
	{
		void *address;             ///< Destination buffer start address.
		uint32_t color;            ///< The color value to fill the buffer with.
		uint8_t colorMode;         ///< Destination color format mode.
		int16_t destinationOffset; ///< Line offset (padding) of the destination buffer.
		Size_t size;               ///< Dimensions of the target area.
	};

	/**
	 * @struct CopyConfig
	 * @brief Configuration structure for image block copying operations.
	 */
	struct CopyConfig
	{
		void *sourceAddress;          ///< Source buffer address.
		uint16_t sourceOffset;        ///< Line offset of the source buffer.
		uint8_t sourceColorMode;      ///< Source color format mode.

		void *destinationAddress;     ///< Destination buffer address.
		uint16_t destinationOffset;   ///< Line offset of the destination buffer.
		uint8_t destinationColorMode; ///< Destination color format mode.

		Size_t size;                  ///< Dimensions of the image block.
	};

	/**
	 * @struct BlendConfig
	 * @brief Configuration structure for alpha blending two image layers.
	 */
	struct BlendConfig
	{
		void *sourceAddress;          ///< Background/foreground source layer address.
		uint16_t sourceOffset;        ///< Line offset of the source layer.
		uint8_t sourceColorMode;      ///< Color format mode of the source layer.

		void *destinationAddress;     ///< Destination output/background layer address.
		uint16_t destinationOffset;   ///< Line offset of the destination layer.
		uint8_t destinationColorMode; ///< Color format mode of the destination layer.

		Size_t size;                  ///< Dimensions of the blending area.
	};

	/**
	 * @struct DrawCharConfig
	 * @brief Configuration structure for rendering glyphs/characters.
	 */
	struct DrawCharConfig
	{
		void *sourceAddress;          ///< Font glyph texture source address.
		uint16_t sourceOffset;        ///< Line offset of the glyph texture.
		uint8_t sourceColorMode;      ///< Color format mode of the glyph texture.

		void *destinationAddress;     ///< Destination framebuffer address.
		uint16_t destinationOffset;   ///< Line offset of the destination framebuffer.
		uint8_t destinationColorMode; ///< Color format mode of the destination framebuffer.

		Size_t size;                  ///< Dimensions of the character block.
		uint32_t color;               ///< Foregound color to draw the character.
	};

	/**
	 * @brief Constructor for the Dma2d class.
	 * 
	 * @param[in] drvSetup The base driver setup configuration.
	 * @param[in] config The DMA2D peripheral hardware setup.
	 */
	Dma2d(const Drv::setup_t drvSetup, const setup_t config);

	/**
	 * @brief Legacy constructor for the Dma2d class.
	 */
	Dma2d(YSS_DMA2D_Peri *peri, void (*clockFunc)(bool en), void (*nvicFunc)(bool en));

	/**
	 * @brief Initializes the DMA2D controller.
	 */
	void initialize(void);

	/**
	 * @brief Fills a rectangular area in memory with a solid color.
	 * 
	 * @param[in] config Fill configuration parameters.
	 */
	void fill(FillConfig &config);

	/**
	 * @brief Copies an image block from source to destination without blending.
	 * 
	 * @param[in] config Copy configuration parameters.
	 */
	void copy(CopyConfig &config);

	/**
	 * @brief Blends a source foreground layer onto a destination background layer.
	 * 
	 * @param[in] config Blend configuration parameters.
	 */
	void blend(BlendConfig &config);

	/**
	 * @brief Copies an image block from source to destination with blending.
	 * 
	 * @param[in] config Copy configuration parameters.
	 */
	void copyWithBlending(CopyConfig &config);

	/**
	 * @brief Draws a character/glyph on a destination surface using a glyph map source.
	 * 
	 * @param[in] config Draw character configuration parameters.
	 */
	void drawCharacter(DrawCharConfig &config);

	/**
	 * @brief Yields the calling thread until the current DMA2D operation is complete.
	 * 
	 * @return error_t Returns ERROR_NONE on success.
	 */
	error_t waitUntilComplete(void);

	/**
	 * @brief Interrupt service routine for the DMA2D controller.
	 */
	void isr(void);
};

#endif

