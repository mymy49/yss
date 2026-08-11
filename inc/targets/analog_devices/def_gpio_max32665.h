/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

/**
 * @file def_gpio_max32665.h
 * @brief MAX32665/MAX32666 GPIO Alternate Function definitions.
 *
 * @details
 * Defines the `altFunc_t` enumeration used by the yss Gpio driver for the
 * MAX32665/MAX32666 MCU. Each enum value encodes the alternate function
 * selection for a specific GPIO port pin and is written directly to the
 * hardware en1/en2 register bits in `Gpio::setAltFunction()`.
 *
 * ### Alternate Function Encoding
 *
 *   Value | en2 | en1 | Mode
 *   :----:|:---:|:---:|:-----------------------------------
 *     0   |  0  |  0  | GPIO (default digital I/O)
 *     1   |  0  |  1  | Alternate Function 1 (AF1)
 *     2   |  1  |  0  | Alternate Function 2 (AF2)
 *     3   |  1  |  1  | Alternate Function 3 (AF3)
 *
 * @note AF4 (Pulse Train PT0~PT5/PT0~PT15) requires a dedicated register
 *       path beyond the 2-bit en1/en2 scheme and is therefore not enumerated.
 *       Analog input functions (AIN0~AIN7) on P0.16~P0.23 require GPIO mode
 *       (value = 0); the pin must NOT be driven to AF1/2/3.
 *
 * ### Port Layout (Table 6-1 of the User Guide)
 * - GPIO0 (MXC_GPIO0): P0.0  ~ P0.31  (32 pins)
 * - GPIO1 (MXC_GPIO1): P1.0  ~ P1.15  (16 pins)
 *
 * ### Source Reference
 * Table 6-2: MAX32665/MAX32666 GPIO and Alternate Function Matrix
 * MAX32665/MAX32666 User Guide (UG6971), Pages 129-130
 *
 * ### Usage Example
 * @code
 * // Configure P0.6 as I2C0_SCL (AF1)
 * gpio0.setAsAltFunc(6, P0_6_I2C0_SCL);
 *
 * // Configure P0.9 as UART0_TX (AF3)
 * gpio0.setAsAltFunc(9, P0_9_UART0_TX);
 *
 * // Configure P1.8 as QSPI0_SS0 (AF1)
 * gpio1.setAsAltFunc(8, P1_8_QSPI0_SS0);
 * @endcode
 */

typedef enum
{
    /* =========================================================================
     * GPIO0 — MXC_GPIO0  (P0.0 ~ P0.31)
     * Source: Table 6-2, MAX32665/MAX32666 User Guide
     * Columns: GPIO | AF1 | AF2 | AF3 | AF4(TMR, omitted)
     * ========================================================================= */

    /* P0.0 */
    P0_0_GPIO        = (0), /*!< P0.0  — GPIO (default)         */
    P0_0_SPIXF_SS0   = (1), /*!< P0.0  — AF1: SPIXF_SS0         */
    /* AF2: (none) */
    P0_0_UART2_CTS   = (3), /*!< P0.0  — AF3: UART2_CTS         */

    /* P0.1 */
    P0_1_GPIO        = (0), /*!< P0.1  — GPIO (default)         */
    P0_1_SPIXF_MOSI  = (1), /*!< P0.1  — AF1: SPIXF_MOSI/SDIO0  */
    /* AF2: (none) */
    P0_1_UART2_TX    = (3), /*!< P0.1  — AF3: UART2_TX          */

    /* P0.2 */
    P0_2_GPIO        = (0), /*!< P0.2  — GPIO (default)         */
    P0_2_SPIXF_MISO  = (1), /*!< P0.2  — AF1: SPIXF_MISO/SDIO1  */
    /* AF2: (none) */
    P0_2_UART2_RX    = (3), /*!< P0.2  — AF3: UART2_RX          */

    /* P0.3 */
    P0_3_GPIO        = (0), /*!< P0.3  — GPIO (default)         */
    P0_3_SPIXF_SCK   = (1), /*!< P0.3  — AF1: SPIXF_SCK         */
    /* AF2: (none) */
    P0_3_UART2_RTS   = (3), /*!< P0.3  — AF3: UART2_RTS         */

    /* P0.4 */
    P0_4_GPIO        = (0), /*!< P0.4  — GPIO (default)         */
    P0_4_SPIXF_SDIO2 = (1), /*!< P0.4  — AF1: SPIXF_SDIO2       */
    /* AF2: (none) */
    P0_4_OWM_IO      = (3), /*!< P0.4  — AF3: OWM_IO            */

    /* P0.5 */
    P0_5_GPIO        = (0), /*!< P0.5  — GPIO (default)         */
    P0_5_SPIXF_SDIO3 = (1), /*!< P0.5  — AF1: SPIXF_SDIO3       */
    /* AF2: (none) */
    P0_5_OWM_PE      = (3), /*!< P0.5  — AF3: OWM_PE            */

    /* P0.6 */
    P0_6_GPIO        = (0), /*!< P0.6  — GPIO (default)         */
    P0_6_I2C0_SCL    = (1), /*!< P0.6  — AF1: I2C0_SCL          */
    /* AF2: (none) */
    P0_6_SWDIO2      = (3), /*!< P0.6  — AF3: SWDIO2            */

    /* P0.7 */
    P0_7_GPIO        = (0), /*!< P0.7  — GPIO (default)         */
    P0_7_I2C0_SDA    = (1), /*!< P0.7  — AF1: I2C0_SDA          */
    /* AF2: (none) */
    P0_7_SWCLK2      = (3), /*!< P0.7  — AF3: SWCLK2            */

    /* P0.8 */
    P0_8_GPIO        = (0), /*!< P0.8  — GPIO (default)         */
    P0_8_SPIXR_SS0   = (1), /*!< P0.8  — AF1: SPIXR_SS0         */
    P0_8_QSPI0_SS0   = (2), /*!< P0.8  — AF2: QSPI0_SS0         */
    P0_8_UART0_CTS   = (3), /*!< P0.8  — AF3: UART0_CTS         */

    /* P0.9 */
    P0_9_GPIO        = (0), /*!< P0.9  — GPIO (default)         */
    P0_9_SPIXR_MOSI  = (1), /*!< P0.9  — AF1: SPIXR_MOSI/SDIO0  */
    P0_9_QSPI0_MOSI  = (2), /*!< P0.9  — AF2: QSPI0_MOSI/SDIO0  */
    P0_9_UART0_TX    = (3), /*!< P0.9  — AF3: UART0_TX          */

    /* P0.10 */
    P0_10_GPIO       = (0), /*!< P0.10 — GPIO (default)         */
    P0_10_SPIXR_MISO = (1), /*!< P0.10 — AF1: SPIXR_MISO/SDIO1  */
    P0_10_QSPI0_MISO = (2), /*!< P0.10 — AF2: QSPI0_MISO/SDIO1  */
    P0_10_UART0_RX   = (3), /*!< P0.10 — AF3: UART0_RX          */

    /* P0.11 */
    P0_11_GPIO       = (0), /*!< P0.11 — GPIO (default)         */
    P0_11_SPIXR_SCK  = (1), /*!< P0.11 — AF1: SPIXR_SCK         */
    P0_11_QSPI0_SCK  = (2), /*!< P0.11 — AF2: QSPI0_SCK         */
    P0_11_UART0_RTS  = (3), /*!< P0.11 — AF3: UART0_RTS         */

    /* P0.12 */
    P0_12_GPIO         = (0), /*!< P0.12 — GPIO (default)         */
    P0_12_SPIXR_SDIO2  = (1), /*!< P0.12 — AF1: SPIXR_SDIO2       */
    P0_12_QSPI0_SDIO2  = (2), /*!< P0.12 — AF2: QSPI0_SDIO2       */
    P0_12_OWM_IO       = (3), /*!< P0.12 — AF3: OWM_IO            */

    /* P0.13 */
    P0_13_GPIO         = (0), /*!< P0.13 — GPIO (default)         */
    P0_13_SPIXR_SDIO3  = (1), /*!< P0.13 — AF1: SPIXR_SDIO3       */
    P0_13_QSPI0_SDIO3  = (2), /*!< P0.13 — AF2: QSPI0_SDIO3       */
    P0_13_OWM_PE       = (3), /*!< P0.13 — AF3: OWM_PE            */

    /* P0.14 */
    P0_14_GPIO       = (0), /*!< P0.14 — GPIO (default)         */
    P0_14_I2C1_SCL   = (1), /*!< P0.14 — AF1: I2C1_SCL          */
    P0_14_QSPI0_SS1  = (2), /*!< P0.14 — AF2: QSPI0_SS1         */
    /* AF3: (none) */

    /* P0.15 */
    P0_15_GPIO       = (0), /*!< P0.15 — GPIO (default)         */
    P0_15_I2C1_SDA   = (1), /*!< P0.15 — AF1: I2C1_SDA          */
    P0_15_QSPI0_SS2  = (2), /*!< P0.15 — AF2: QSPI0_SS2         */
    /* AF3: (none) */

    /* P0.16  (also AIN0/AIN0N — use GPIO mode for analog input) */
    P0_16_GPIO       = (0), /*!< P0.16 — GPIO / AIN0 (default)  */
    P0_16_QSPI1_SS0  = (2), /*!< P0.16 — AF2: QSPI1_SS0         */
    P0_16_OWM_IO     = (3), /*!< P0.16 — AF3: OWM_IO            */

    /* P0.17  (also AIN1/AIN0P — use GPIO mode for analog input) */
    P0_17_GPIO       = (0), /*!< P0.17 — GPIO / AIN1 (default)  */
    P0_17_QSPI1_MOSI = (2), /*!< P0.17 — AF2: QSPI1_MOSI/SDIO0  */
    P0_17_OWM_PE     = (3), /*!< P0.17 — AF3: OWM_PE            */

    /* P0.18  (also AIN2/AIN1N — use GPIO mode for analog input) */
    P0_18_GPIO       = (0), /*!< P0.18 — GPIO / AIN2 (default)  */
    P0_18_QSPI1_MISO = (2), /*!< P0.18 — AF2: QSPI1_MISO/SDIO1  */
    /* AF3: (none) */

    /* P0.19  (also AIN3/AIN1P — use GPIO mode for analog input) */
    P0_19_GPIO       = (0), /*!< P0.19 — GPIO / AIN3 (default)  */
    P0_19_QSPI1_SCK  = (2), /*!< P0.19 — AF2: QSPI1_SCK         */
    /* AF3: (none) */

    /* P0.20  (also AIN4/AIN2N — use GPIO mode for analog input) */
    P0_20_GPIO         = (0), /*!< P0.20 — GPIO / AIN4 (default)  */
    P0_20_QSPI1_SDIO2  = (2), /*!< P0.20 — AF2: QSPI1_SDIO2       */
    P0_20_UART1_RX     = (3), /*!< P0.20 — AF3: UART1_RX          */

    /* P0.21  (also AIN5/AIN2P — use GPIO mode for analog input) */
    P0_21_GPIO         = (0), /*!< P0.21 — GPIO / AIN5 (default)  */
    P0_21_QSPI1_SDIO3  = (2), /*!< P0.21 — AF2: QSPI1_SDIO3       */
    P0_21_UART1_TX     = (3), /*!< P0.21 — AF3: UART1_TX          */

    /* P0.22  (also AIN6/AIN3N — use GPIO mode for analog input) */
    P0_22_GPIO       = (0), /*!< P0.22 — GPIO / AIN6 (default)  */
    P0_22_QSPI1_SS1  = (2), /*!< P0.22 — AF2: QSPI1_SS1         */
    P0_22_UART1_CTS  = (3), /*!< P0.22 — AF3: UART1_CTS         */

    /* P0.23  (also AIN7/AIN3P — use GPIO mode for analog input) */
    P0_23_GPIO       = (0), /*!< P0.23 — GPIO / AIN7 (default)  */
    P0_23_QSPI1_SS2  = (2), /*!< P0.23 — AF2: QSPI1_SS2         */
    P0_23_UART1_RTS  = (3), /*!< P0.23 — AF3: UART1_RTS         */

    /* P0.24 */
    P0_24_GPIO         = (0), /*!< P0.24 — GPIO (default)         */
    P0_24_PCM_LRCLK    = (1), /*!< P0.24 — AF1: PCM_LRCLK         */
    P0_24_QSPI2_SS0    = (2), /*!< P0.24 — AF2: QSPI2_SS0         */
    P0_24_OWM_IO       = (3), /*!< P0.24 — AF3: OWM_IO            */

    /* P0.25 */
    P0_25_GPIO         = (0), /*!< P0.25 — GPIO (default)         */
    P0_25_PCM_DOUT     = (1), /*!< P0.25 — AF1: PCM_DOUT          */
    P0_25_QSPI2_MOSI   = (2), /*!< P0.25 — AF2: QSPI2_MOSI/SDIO0  */
    P0_25_OWM_PE       = (3), /*!< P0.25 — AF3: OWM_PE            */

    /* P0.26 */
    P0_26_GPIO         = (0), /*!< P0.26 — GPIO (default)         */
    P0_26_PCM_DIN      = (1), /*!< P0.26 — AF1: PCM_DIN           */
    P0_26_QSPI2_MISO   = (2), /*!< P0.26 — AF2: QSPI2_MISO/SDIO1  */
    /* AF3: (none) */

    /* P0.27 */
    P0_27_GPIO         = (0), /*!< P0.27 — GPIO (default)         */
    P0_27_PCM_BCLK     = (1), /*!< P0.27 — AF1: PCM_BCLK          */
    P0_27_QSPI2_SCK    = (2), /*!< P0.27 — AF2: QSPI2_SCK         */
    /* AF3: (none) */

    /* P0.28 */
    P0_28_GPIO          = (0), /*!< P0.28 — GPIO (default)         */
    P0_28_PDM_DATA2     = (1), /*!< P0.28 — AF1: PDM_DATA2         */
    P0_28_QSPI2_SDIO2   = (2), /*!< P0.28 — AF2: QSPI2_SDIO2       */
    P0_28_UART2_RX      = (3), /*!< P0.28 — AF3: UART2_RX          */

    /* P0.29 */
    P0_29_GPIO          = (0), /*!< P0.29 — GPIO (default)         */
    P0_29_PDM_DATA3     = (1), /*!< P0.29 — AF1: PDM_DATA3         */
    P0_29_QSPI2_SDIO3   = (2), /*!< P0.29 — AF2: QSPI2_SDIO3       */
    P0_29_UART2_TX      = (3), /*!< P0.29 — AF3: UART2_TX          */

    /* P0.30 */
    P0_30_GPIO          = (0), /*!< P0.30 — GPIO (default)         */
    P0_30_PDM_RX_CLK    = (1), /*!< P0.30 — AF1: PDM_RX_CLK        */
    P0_30_QSPI2_SS1     = (2), /*!< P0.30 — AF2: QSPI2_SS1         */
    P0_30_UART2_CTS     = (3), /*!< P0.30 — AF3: UART2_CTS         */

    /* P0.31 */
    P0_31_GPIO          = (0), /*!< P0.31 — GPIO (default)         */
    P0_31_PDM_MCLK      = (1), /*!< P0.31 — AF1: PDM_MCLK          */
    P0_31_QSPI2_SS2     = (2), /*!< P0.31 — AF2: QSPI2_SS2         */
    P0_31_UART2_RTS     = (3), /*!< P0.31 — AF3: UART2_RTS         */

    /* =========================================================================
     * GPIO1 — MXC_GPIO1  (P1.0 ~ P1.15)
     * Source: Table 6-2, MAX32665/MAX32666 User Guide
     * Note: AF4 = Pulse Train (PT0~PT15), not representable in 2-bit encoding.
     * ========================================================================= */

    /* P1.0 */
    P1_0_GPIO        = (0), /*!< P1.0  — GPIO (default)         */
    P1_0_SDHC_DAT3   = (1), /*!< P1.0  — AF1: SDHC_DAT3         */
    /* AF2: (none) */
    P1_0_SDMA_TMS    = (3), /*!< P1.0  — AF3: SDMA_TMS          */

    /* P1.1 */
    P1_1_GPIO        = (0), /*!< P1.1  — GPIO (default)         */
    P1_1_SDHC_CMD    = (1), /*!< P1.1  — AF1: SDHC_CMD          */
    /* AF2: (none) */
    P1_1_SDMA_TDO    = (3), /*!< P1.1  — AF3: SDMA_TDO          */

    /* P1.2 */
    P1_2_GPIO        = (0), /*!< P1.2  — GPIO (default)         */
    P1_2_SDHC_DAT0   = (1), /*!< P1.2  — AF1: SDHC_DAT0         */
    /* AF2: (none) */
    P1_2_SDMA_TDI    = (3), /*!< P1.2  — AF3: SDMA_TDI          */

    /* P1.3 */
    P1_3_GPIO        = (0), /*!< P1.3  — GPIO (default)         */
    P1_3_SDHC_CLK    = (1), /*!< P1.3  — AF1: SDHC_CLK          */
    /* AF2: (none) */
    P1_3_SDMA_TCK    = (3), /*!< P1.3  — AF3: SDMA_TCK          */

    /* P1.4 */
    P1_4_GPIO        = (0), /*!< P1.4  — GPIO (default)         */
    P1_4_SDHC_DAT1   = (1), /*!< P1.4  — AF1: SDHC_DAT1         */
    /* AF2: (none) */
    P1_4_UART0_RX    = (3), /*!< P1.4  — AF3: UART0_RX          */

    /* P1.5 */
    P1_5_GPIO        = (0), /*!< P1.5  — GPIO (default)         */
    P1_5_SDHC_DAT2   = (1), /*!< P1.5  — AF1: SDHC_DAT2         */
    /* AF2: (none) */
    P1_5_UART0_TX    = (3), /*!< P1.5  — AF3: UART0_TX          */

    /* P1.6 */
    P1_6_GPIO        = (0), /*!< P1.6  — GPIO (default)                  */
    P1_6_SDHC_WP     = (1), /*!< P1.6  — AF1: SDHC_WP  (Write Protect)   */
    /* AF2: (none) */
    P1_6_UART0_CTS   = (3), /*!< P1.6  — AF3: UART0_CTS                  */

    /* P1.7 */
    P1_7_GPIO        = (0), /*!< P1.7  — GPIO (default)                  */
    P1_7_SDHC_CDN    = (1), /*!< P1.7  — AF1: SDHC_CDN (Card Detect N)   */
    /* AF2: (none) */
    P1_7_UART0_RTS   = (3), /*!< P1.7  — AF3: UART0_RTS                  */

    /* P1.8 */
    P1_8_GPIO        = (0), /*!< P1.8  — GPIO (default)         */
    P1_8_QSPI0_SS0   = (1), /*!< P1.8  — AF1: QSPI0_SS0         */
    /* AF2: (none) */
    /* AF3: (none) */

    /* P1.9 */
    P1_9_GPIO        = (0), /*!< P1.9  — GPIO (default)         */
    P1_9_QSPI0_MOSI  = (1), /*!< P1.9  — AF1: QSPI0_MOSI/SDIO0  */
    /* AF2: (none) */
    /* AF3: (none) */

    /* P1.10 */
    P1_10_GPIO       = (0), /*!< P1.10 — GPIO (default)         */
    P1_10_QSPI0_MISO = (1), /*!< P1.10 — AF1: QSPI0_MISO/SDIO1  */
    /* AF2: (none) */
    /* AF3: (none) */

    /* P1.11 */
    P1_11_GPIO       = (0), /*!< P1.11 — GPIO (default)         */
    P1_11_QSPI0_SCK  = (1), /*!< P1.11 — AF1: QSPI0_SCK         */
    /* AF2: (none) */
    /* AF3: (none) */

    /* P1.12 */
    P1_12_GPIO         = (0), /*!< P1.12 — GPIO (default)         */
    P1_12_QSPI0_SDIO2  = (1), /*!< P1.12 — AF1: QSPI0_SDIO2       */
    /* AF2: (none) */
    P1_12_UART1_RX     = (3), /*!< P1.12 — AF3: UART1_RX          */

    /* P1.13 */
    P1_13_GPIO         = (0), /*!< P1.13 — GPIO (default)         */
    P1_13_QSPI0_SDIO3  = (1), /*!< P1.13 — AF1: QSPI0_SDIO3       */
    /* AF2: (none) */
    P1_13_UART1_TX     = (3), /*!< P1.13 — AF3: UART1_TX          */

    /* P1.14 */
    P1_14_GPIO       = (0), /*!< P1.14 — GPIO (default)         */
    P1_14_I2C2_SCL   = (1), /*!< P1.14 — AF1: I2C2_SCL          */
    /* AF2: (none) */
    P1_14_UART1_CTS  = (3), /*!< P1.14 — AF3: UART1_CTS         */

    /* P1.15 */
    P1_15_GPIO       = (0), /*!< P1.15 — GPIO (default)         */
    P1_15_I2C2_SDA   = (1), /*!< P1.15 — AF1: I2C2_SDA          */
    /* AF2: (none) */
    P1_15_UART1_RTS  = (3), /*!< P1.15 — AF3: UART1_RTS         */

} altFunc_t;
