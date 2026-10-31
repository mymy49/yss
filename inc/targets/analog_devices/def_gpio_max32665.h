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
 * Based on Table 6-3 of the MAX32665/MAX32666 User Guide:
 *
 *   Value | en2 | en1 | Mode
 *   :----:|:---:|:---:|:-----------------------------------
 *     0   |  0  |  0  | Alternate Function 1 (AF1)
 *     1   |  1  |  0  | Alternate Function 2 (AF2)
 *     2   |  0  |  1  | Alternate Function 3 (AF3)
 *     3   |  1  |  1  | Alternate Function 4 (AF4, Pulse Train PT0~PT15)
 *
 * @note GPIO mode is selected by setting GPIOn_EN=1 separately (not encoded here).
 *       Analog input functions (AIN0~AIN7) on P0.16~P0.23 are mapped as AF1
 *       (value = 0) per Table 6-2. AF4 = Pulse Train (PT0~PT15) for GPIO1 pins.
 *
 * ### Port Layout (Table 6-1 of the User Guide)
 * - GPIO0 (MXC_GPIO0): P0.0  ~ P0.31  (32 pins)
 * - GPIO1 (MXC_GPIO1): P1.0  ~ P1.15  (16 pins)
 *
 * ### Source Reference
 * Table 6-2: MAX32665/MAX32666 GPIO and Alternate Function Matrix
 * Table 6-3: MAX32665/MAX32666 GPIO Pin Configuration
 * MAX32665/MAX32666 User Guide (UG6971), Pages 129-132
 *
 * ### Usage Example
 * @code
 * // Configure P0.6 as I2C0_SCL (AF1, value=0)
 * gpio0.setAsAltFunc(6, P0_6_I2C0_SCL);
 *
 * // Configure P0.9 as UART0_TX (AF3, value=2)
 * gpio0.setAsAltFunc(9, P0_9_UART0_TX);
 *
 * // Configure P1.8 as QSPI0_SS0 (AF1, value=0)
 * gpio1.setAsAltFunc(8, P1_8_QSPI0_SS0);
 * @endcode
 */

typedef enum
{
    /* =========================================================================
     * GPIO0 — MXC_GPIO0  (P0.0 ~ P0.31)
     * Source: Table 6-2, MAX32665/MAX32666 User Guide
     * Columns: AF1(0) | AF2(1) | AF3(2) | AF4(3, TMR0~TMR5)
     * ========================================================================= */

    /* P0.0 */
    P0_0_SPIXF_SS0   = (0), /*!< P0.0  — AF1: SPIXF_SS0         */
    /* AF2: (none) */
    P0_0_UART2_CTS   = (2), /*!< P0.0  — AF3: UART2_CTS         */
    P0_0_TMR0        = (3), /*!< P0.0  — AF4: TMR0              */

    /* P0.1 */
    P0_1_SPIXF_MOSI  = (0), /*!< P0.1  — AF1: SPIXF_MOSI/SDIO0  */
    /* AF2: (none) */
    P0_1_UART2_TX    = (2), /*!< P0.1  — AF3: UART2_TX          */
    P0_1_TMR1        = (3), /*!< P0.1  — AF4: TMR1              */

    /* P0.2 */
    P0_2_SPIXF_MISO  = (0), /*!< P0.2  — AF1: SPIXF_MISO/SDIO1  */
    /* AF2: (none) */
    P0_2_UART2_RX    = (2), /*!< P0.2  — AF3: UART2_RX          */
    P0_2_TMR2        = (3), /*!< P0.2  — AF4: TMR2              */

    /* P0.3 */
    P0_3_SPIXF_SCK   = (0), /*!< P0.3  — AF1: SPIXF_SCK         */
    /* AF2: (none) */
    P0_3_UART2_RTS   = (2), /*!< P0.3  — AF3: UART2_RTS         */
    P0_3_TMR3        = (3), /*!< P0.3  — AF4: TMR3              */

    /* P0.4 */
    P0_4_SPIXF_SDIO2 = (0), /*!< P0.4  — AF1: SPIXF_SDIO2       */
    /* AF2: (none) */
    P0_4_OWM_IO      = (2), /*!< P0.4  — AF3: OWM_IO            */
    P0_4_TMR4        = (3), /*!< P0.4  — AF4: TMR4              */

    /* P0.5 */
    P0_5_SPIXF_SDIO3 = (0), /*!< P0.5  — AF1: SPIXF_SDIO3       */
    /* AF2: (none) */
    P0_5_OWM_PE      = (2), /*!< P0.5  — AF3: OWM_PE            */
    P0_5_TMR5        = (3), /*!< P0.5  — AF4: TMR5              */

    /* P0.6 */
    P0_6_I2C0_SCL    = (0), /*!< P0.6  — AF1: I2C0_SCL          */
    /* AF2: (none) */
    P0_6_SWDIO2      = (2), /*!< P0.6  — AF3: SWDIO2            */
    P0_6_TMR0        = (3), /*!< P0.6  — AF4: TMR0              */

    /* P0.7 */
    P0_7_I2C0_SDA    = (0), /*!< P0.7  — AF1: I2C0_SDA          */
    /* AF2: (none) */
    P0_7_SWCLK2      = (2), /*!< P0.7  — AF3: SWCLK2            */
    P0_7_TMR1        = (3), /*!< P0.7  — AF4: TMR1              */

    /* P0.8 */
    P0_8_SPIXR_SS0   = (0), /*!< P0.8  — AF1: SPIXR_SS0         */
    P0_8_QSPI0_SS0   = (1), /*!< P0.8  — AF2: QSPI0_SS0         */
    P0_8_UART0_CTS   = (2), /*!< P0.8  — AF3: UART0_CTS         */
    P0_8_TMR2        = (3), /*!< P0.8  — AF4: TMR2              */

    /* P0.9 */
    P0_9_SPIXR_MOSI  = (0), /*!< P0.9  — AF1: SPIXR_MOSI/SDIO0  */
    P0_9_QSPI0_MOSI  = (1), /*!< P0.9  — AF2: QSPI0_MOSI/SDIO0  */
    P0_9_UART0_TX    = (2), /*!< P0.9  — AF3: UART0_TX          */
    P0_9_TMR3        = (3), /*!< P0.9  — AF4: TMR3              */

    /* P0.10 */
    P0_10_SPIXR_MISO = (0), /*!< P0.10 — AF1: SPIXR_MISO/SDIO1  */
    P0_10_QSPI0_MISO = (1), /*!< P0.10 — AF2: QSPI0_MISO/SDIO1  */
    P0_10_UART0_RX   = (2), /*!< P0.10 — AF3: UART0_RX          */
    P0_10_TMR4       = (3), /*!< P0.10 — AF4: TMR4              */

    /* P0.11 */
    P0_11_SPIXR_SCK  = (0), /*!< P0.11 — AF1: SPIXR_SCK         */
    P0_11_QSPI0_SCK  = (1), /*!< P0.11 — AF2: QSPI0_SCK         */
    P0_11_UART0_RTS  = (2), /*!< P0.11 — AF3: UART0_RTS         */
    P0_11_TMR5       = (3), /*!< P0.11 — AF4: TMR5              */

    /* P0.12 */
    P0_12_SPIXR_SDIO2  = (0), /*!< P0.12 — AF1: SPIXR_SDIO2       */
    P0_12_QSPI0_SDIO2  = (1), /*!< P0.12 — AF2: QSPI0_SDIO2       */
    P0_12_OWM_IO       = (2), /*!< P0.12 — AF3: OWM_IO            */
    P0_12_TMR0         = (3), /*!< P0.12 — AF4: TMR0              */

    /* P0.13 */
    P0_13_SPIXR_SDIO3  = (0), /*!< P0.13 — AF1: SPIXR_SDIO3       */
    P0_13_QSPI0_SDIO3  = (1), /*!< P0.13 — AF2: QSPI0_SDIO3       */
    P0_13_OWM_PE       = (2), /*!< P0.13 — AF3: OWM_PE            */
    P0_13_TMR1         = (3), /*!< P0.13 — AF4: TMR1              */

    /* P0.14 */
    P0_14_I2C1_SCL   = (0), /*!< P0.14 — AF1: I2C1_SCL          */
    P0_14_QSPI0_SS1  = (1), /*!< P0.14 — AF2: QSPI0_SS1         */
    /* AF3: (none) */
    P0_14_TMR2       = (3), /*!< P0.14 — AF4: TMR2              */

    /* P0.15 */
    P0_15_I2C1_SDA   = (0), /*!< P0.15 — AF1: I2C1_SDA          */
    P0_15_QSPI0_SS2  = (1), /*!< P0.15 — AF2: QSPI0_SS2         */
    /* AF3: (none) */
    P0_15_TMR3       = (3), /*!< P0.15 — AF4: TMR3              */

    /* P0.16  (AF1 = AIN0/AIN0N — use AF1 mode for analog input) */
    P0_16_AIN0       = (0), /*!< P0.16 — AF1: AIN0/AIN0N (analog)*/
    P0_16_QSPI1_SS0  = (1), /*!< P0.16 — AF2: QSPI1_SS0         */
    P0_16_OWM_IO     = (2), /*!< P0.16 — AF3: OWM_IO            */
    P0_16_TMR4       = (3), /*!< P0.16 — AF4: TMR4              */

    /* P0.17  (AF1 = AIN1/AIN0P — use AF1 mode for analog input) */
    P0_17_AIN1       = (0), /*!< P0.17 — AF1: AIN1/AIN0P (analog)*/
    P0_17_QSPI1_MOSI = (1), /*!< P0.17 — AF2: QSPI1_MOSI/SDIO0  */
    P0_17_OWM_PE     = (2), /*!< P0.17 — AF3: OWM_PE            */
    P0_17_TMR5       = (3), /*!< P0.17 — AF4: TMR5              */

    /* P0.18  (AF1 = AIN2/AIN1N — use AF1 mode for analog input) */
    P0_18_AIN2       = (0), /*!< P0.18 — AF1: AIN2/AIN1N (analog)*/
    P0_18_QSPI1_MISO = (1), /*!< P0.18 — AF2: QSPI1_MISO/SDIO1  */
    /* AF3: (none) */
    P0_18_TMR0       = (3), /*!< P0.18 — AF4: TMR0              */

    /* P0.19  (AF1 = AIN3/AIN1P — use AF1 mode for analog input) */
    P0_19_AIN3       = (0), /*!< P0.19 — AF1: AIN3/AIN1P (analog)*/
    P0_19_QSPI1_SCK  = (1), /*!< P0.19 — AF2: QSPI1_SCK         */
    /* AF3: (none) */
    P0_19_TMR1       = (3), /*!< P0.19 — AF4: TMR1              */

    /* P0.20  (AF1 = AIN4/AIN2N — use AF1 mode for analog input) */
    P0_20_AIN4         = (0), /*!< P0.20 — AF1: AIN4/AIN2N (analog)*/
    P0_20_QSPI1_SDIO2  = (1), /*!< P0.20 — AF2: QSPI1_SDIO2       */
    P0_20_UART1_RX     = (2), /*!< P0.20 — AF3: UART1_RX          */
    P0_20_TMR2         = (3), /*!< P0.20 — AF4: TMR2              */

    /* P0.21  (AF1 = AIN5/AIN2P — use AF1 mode for analog input) */
    P0_21_AIN5         = (0), /*!< P0.21 — AF1: AIN5/AIN2P (analog)*/
    P0_21_QSPI1_SDIO3  = (1), /*!< P0.21 — AF2: QSPI1_SDIO3       */
    P0_21_UART1_TX     = (2), /*!< P0.21 — AF3: UART1_TX          */
    P0_21_TMR3         = (3), /*!< P0.21 — AF4: TMR3              */

    /* P0.22  (AF1 = AIN6/AIN3N — use AF1 mode for analog input) */
    P0_22_AIN6       = (0), /*!< P0.22 — AF1: AIN6/AIN3N (analog)*/
    P0_22_QSPI1_SS1  = (1), /*!< P0.22 — AF2: QSPI1_SS1         */
    P0_22_UART1_CTS  = (2), /*!< P0.22 — AF3: UART1_CTS         */
    P0_22_TMR4       = (3), /*!< P0.22 — AF4: TMR4              */

    /* P0.23  (AF1 = AIN7/AIN3P — use AF1 mode for analog input) */
    P0_23_AIN7       = (0), /*!< P0.23 — AF1: AIN7/AIN3P (analog)*/
    P0_23_QSPI1_SS2  = (1), /*!< P0.23 — AF2: QSPI1_SS2         */
    P0_23_UART1_RTS  = (2), /*!< P0.23 — AF3: UART1_RTS         */
    P0_23_TMR5       = (3), /*!< P0.23 — AF4: TMR5              */

    /* P0.24 */
    P0_24_PCM_LRCLK    = (0), /*!< P0.24 — AF1: PCM_LRCLK         */
    P0_24_QSPI2_SS0    = (1), /*!< P0.24 — AF2: QSPI2_SS0         */
    P0_24_OWM_IO       = (2), /*!< P0.24 — AF3: OWM_IO            */
    P0_24_TMR0         = (3), /*!< P0.24 — AF4: TMR0              */

    /* P0.25 */
    P0_25_PCM_DOUT     = (0), /*!< P0.25 — AF1: PCM_DOUT          */
    P0_25_QSPI2_MOSI   = (1), /*!< P0.25 — AF2: QSPI2_MOSI/SDIO0  */
    P0_25_OWM_PE       = (2), /*!< P0.25 — AF3: OWM_PE            */
    P0_25_TMR1         = (3), /*!< P0.25 — AF4: TMR1              */

    /* P0.26 */
    P0_26_PCM_DIN      = (0), /*!< P0.26 — AF1: PCM_DIN           */
    P0_26_QSPI2_MISO   = (1), /*!< P0.26 — AF2: QSPI2_MISO/SDIO1  */
    /* AF3: (none) */
    P0_26_TMR2         = (3), /*!< P0.26 — AF4: TMR2              */

    /* P0.27 */
    P0_27_PCM_BCLK     = (0), /*!< P0.27 — AF1: PCM_BCLK          */
    P0_27_QSPI2_SCK    = (1), /*!< P0.27 — AF2: QSPI2_SCK         */
    /* AF3: (none) */
    P0_27_TMR3         = (3), /*!< P0.27 — AF4: TMR3              */

    /* P0.28 */
    P0_28_PDM_DATA2     = (0), /*!< P0.28 — AF1: PDM_DATA2         */
    P0_28_QSPI2_SDIO2   = (1), /*!< P0.28 — AF2: QSPI2_SDIO2       */
    P0_28_UART2_RX      = (2), /*!< P0.28 — AF3: UART2_RX          */
    P0_28_TMR4          = (3), /*!< P0.28 — AF4: TMR4              */

    /* P0.29 */
    P0_29_PDM_DATA3     = (0), /*!< P0.29 — AF1: PDM_DATA3         */
    P0_29_QSPI2_SDIO3   = (1), /*!< P0.29 — AF2: QSPI2_SDIO3       */
    P0_29_UART2_TX      = (2), /*!< P0.29 — AF3: UART2_TX          */
    P0_29_TMR5          = (3), /*!< P0.29 — AF4: TMR5              */

    /* P0.30 */
    P0_30_PDM_RX_CLK    = (0), /*!< P0.30 — AF1: PDM_RX_CLK        */
    P0_30_QSPI2_SS1     = (1), /*!< P0.30 — AF2: QSPI2_SS1         */
    P0_30_UART2_CTS     = (2), /*!< P0.30 — AF3: UART2_CTS         */
    P0_30_TMR0          = (3), /*!< P0.30 — AF4: TMR0              */

    /* P0.31 */
    P0_31_PDM_MCLK      = (0), /*!< P0.31 — AF1: PDM_MCLK          */
    P0_31_QSPI2_SS2     = (1), /*!< P0.31 — AF2: QSPI2_SS2         */
    P0_31_UART2_RTS     = (2), /*!< P0.31 — AF3: UART2_RTS         */
    P0_31_TMR1          = (3), /*!< P0.31 — AF4: TMR1              */

    /* =========================================================================
     * GPIO1 — MXC_GPIO1  (P1.0 ~ P1.15)
     * Source: Table 6-2, MAX32665/MAX32666 User Guide
     * Note: AF4 = Pulse Train (PT0~PT15).
     * ========================================================================= */

    /* P1.0 */
    P1_0_SDHC_DAT3   = (0), /*!< P1.0  — AF1: SDHC_DAT3         */
    /* AF2: (none) */
    P1_0_SDMA_TMS    = (2), /*!< P1.0  — AF3: SDMA_TMS          */
    P1_0_PT0         = (3), /*!< P1.0  — AF4: PT0 (Pulse Train)  */

    /* P1.1 */
    P1_1_SDHC_CMD    = (0), /*!< P1.1  — AF1: SDHC_CMD          */
    /* AF2: (none) */
    P1_1_SDMA_TDO    = (2), /*!< P1.1  — AF3: SDMA_TDO          */
    P1_1_PT1         = (3), /*!< P1.1  — AF4: PT1 (Pulse Train)  */

    /* P1.2 */
    P1_2_SDHC_DAT0   = (0), /*!< P1.2  — AF1: SDHC_DAT0         */
    /* AF2: (none) */
    P1_2_SDMA_TDI    = (2), /*!< P1.2  — AF3: SDMA_TDI          */
    P1_2_PT2         = (3), /*!< P1.2  — AF4: PT2 (Pulse Train)  */

    /* P1.3 */
    P1_3_SDHC_CLK    = (0), /*!< P1.3  — AF1: SDHC_CLK          */
    /* AF2: (none) */
    P1_3_SDMA_TCK    = (2), /*!< P1.3  — AF3: SDMA_TCK          */
    P1_3_PT3         = (3), /*!< P1.3  — AF4: PT3 (Pulse Train)  */

    /* P1.4 */
    P1_4_SDHC_DAT1   = (0), /*!< P1.4  — AF1: SDHC_DAT1         */
    /* AF2: (none) */
    P1_4_UART0_RX    = (2), /*!< P1.4  — AF3: UART0_RX          */
    P1_4_PT4         = (3), /*!< P1.4  — AF4: PT4 (Pulse Train)  */

    /* P1.5 */
    P1_5_SDHC_DAT2   = (0), /*!< P1.5  — AF1: SDHC_DAT2         */
    /* AF2: (none) */
    P1_5_UART0_TX    = (2), /*!< P1.5  — AF3: UART0_TX          */
    P1_5_PT5         = (3), /*!< P1.5  — AF4: PT5 (Pulse Train)  */

    /* P1.6 */
    P1_6_SDHC_WP     = (0), /*!< P1.6  — AF1: SDHC_WP  (Write Protect)   */
    /* AF2: (none) */
    P1_6_UART0_CTS   = (2), /*!< P1.6  — AF3: UART0_CTS                  */
    P1_6_PT6         = (3), /*!< P1.6  — AF4: PT6 (Pulse Train)           */

    /* P1.7 */
    P1_7_SDHC_CDN    = (0), /*!< P1.7  — AF1: SDHC_CDN (Card Detect N)   */
    /* AF2: (none) */
    P1_7_UART0_RTS   = (2), /*!< P1.7  — AF3: UART0_RTS                  */
    P1_7_PT7         = (3), /*!< P1.7  — AF4: PT7 (Pulse Train)           */

    /* P1.8 */
    P1_8_QSPI0_SS0   = (0), /*!< P1.8  — AF1: QSPI0_SS0         */
    /* AF2: (none) */
    /* AF3: (none) */
    P1_8_PT8         = (3), /*!< P1.8  — AF4: PT8 (Pulse Train)  */

    /* P1.9 */
    P1_9_QSPI0_MOSI  = (0), /*!< P1.9  — AF1: QSPI0_MOSI/SDIO0  */
    /* AF2: (none) */
    /* AF3: (none) */
    P1_9_PT9         = (3), /*!< P1.9  — AF4: PT9 (Pulse Train)  */

    /* P1.10 */
    P1_10_QSPI0_MISO = (0), /*!< P1.10 — AF1: QSPI0_MISO/SDIO1  */
    /* AF2: (none) */
    /* AF3: (none) */
    P1_10_PT10       = (3), /*!< P1.10 — AF4: PT10 (Pulse Train) */

    /* P1.11 */
    P1_11_QSPI0_SCK  = (0), /*!< P1.11 — AF1: QSPI0_SCK         */
    /* AF2: (none) */
    /* AF3: (none) */
    P1_11_PT11       = (3), /*!< P1.11 — AF4: PT11 (Pulse Train) */

    /* P1.12 */
    P1_12_QSPI0_SDIO2  = (0), /*!< P1.12 — AF1: QSPI0_SDIO2       */
    /* AF2: (none) */
    P1_12_UART1_RX     = (2), /*!< P1.12 — AF3: UART1_RX          */
    P1_12_PT12         = (3), /*!< P1.12 — AF4: PT12 (Pulse Train) */

    /* P1.13 */
    P1_13_QSPI0_SDIO3  = (0), /*!< P1.13 — AF1: QSPI0_SDIO3       */
    /* AF2: (none) */
    P1_13_UART1_TX     = (2), /*!< P1.13 — AF3: UART1_TX          */
    P1_13_PT13         = (3), /*!< P1.13 — AF4: PT13 (Pulse Train) */

    /* P1.14 */
    P1_14_I2C2_SCL   = (0), /*!< P1.14 — AF1: I2C2_SCL          */
    /* AF2: (none) */
    P1_14_UART1_CTS  = (2), /*!< P1.14 — AF3: UART1_CTS         */
    P1_14_PT14       = (3), /*!< P1.14 — AF4: PT14 (Pulse Train) */

    /* P1.15 */
    P1_15_I2C2_SDA   = (0), /*!< P1.15 — AF1: I2C2_SDA          */
    /* AF2: (none) */
    P1_15_UART1_RTS  = (2), /*!< P1.15 — AF3: UART1_RTS         */
    P1_15_PT15       = (3), /*!< P1.15 — AF4: PT15 (Pulse Train) */

} altFunc_t;
