/**************************************************************************//**
 * @file     SYS.h
 * @version  V3.0
 * @brief    M460 Series SYS Driver Header File
 *
 * @copyright SPDX-License-Identifier: Apache-2.0
 * @copyright Copyright (0xC) 2021 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

 #if defined(__M467KJHAN__)
#define PA_EXIST
#define PB_EXIST
#define PC_EXIST
#define PD_EXIST
#define PE_EXIST
#define PF_EXIST
#define PG_EXIST
#define PH_EXIST
#endif

typedef enum
{
	/* PA.0 MFP */
	PA0_GPIO         = (0x00), /*!< GPA_MFP0 PA0 setting for GPIO        */
	PA0_SPIM_MOSI    = (0x02), /*!< GPA_MFP0 PA0 setting for SPIM_MOSI   */
	PA0_QSPI0_MOSI0  = (0x03), /*!< GPA_MFP0 PA0 setting for QSPI0_MOSI0 */
	PA0_SPI0_MOSI    = (0x04), /*!< GPA_MFP0 PA0 setting for SPI0_MOSI   */
	PA0_SD1_DAT0     = (0x05), /*!< GPA_MFP0 PA0 setting for SD1_DAT0    */
	PA0_SC0_CLK      = (0x06), /*!< GPA_MFP0 PA0 setting for SC0_CLK     */
	PA0_UART0_RXD    = (0x07), /*!< GPA_MFP0 PA0 setting for UART0_RXD   */
	PA0_UART1_nRTS   = (0x08), /*!< GPA_MFP0 PA0 setting for UART1_nRTS  */
	PA0_I2C2_SDA     = (0x09), /*!< GPA_MFP0 PA0 setting for I2C2_SDA    */
	PA0_CCAP_DATA6   = (0x0a), /*!< GPA_MFP0 PA0 setting for CCAP_DATA6  */
	PA0_BPWM0_CH0    = (0x0c), /*!< GPA_MFP0 PA0 setting for BPWM0_CH0   */
	PA0_EPWM0_CH5    = (0x0d), /*!< GPA_MFP0 PA0 setting for EPWM0_CH5   */
	PA0_EQEI3_B      = (0x0e), /*!< GPA_MFP0 PA0 setting for EQEI3_B     */
	PA0_DAC0_ST      = (0x0f), /*!< GPA_MFP0 PA0 setting for DAC0_ST     */
	PA0_PSIO0_CH7    = (0x11), /*!< GPA_MFP0 PA0 setting for PSIO0_CH7   */
	PA0_BMC19        = (0x14), /*!< GPA_MFP0 PA0 setting for BMC19 (0xM460xGCAE only), */

	/* PA.1 MFP */
	PA1_GPIO         = (0x00), /*!< GPA_MFP0 PA1 setting for GPIO        */
	PA1_SPIM_MISO    = (0x02), /*!< GPA_MFP0 PA1 setting for SPIM_MISO   */
	PA1_QSPI0_MISO0  = (0x03), /*!< GPA_MFP0 PA1 setting for QSPI0_MISO0 */
	PA1_SPI0_MISO    = (0x04), /*!< GPA_MFP0 PA1 setting for SPI0_MISO   */
	PA1_SD1_DAT1     = (0x05), /*!< GPA_MFP0 PA1 setting for SD1_DAT1    */
	PA1_SC0_DAT      = (0x06), /*!< GPA_MFP0 PA1 setting for SC0_DAT     */
	PA1_UART0_TXD    = (0x07), /*!< GPA_MFP0 PA1 setting for UART0_TXD   */
	PA1_UART1_nCTS   = (0x08), /*!< GPA_MFP0 PA1 setting for UART1_nCTS  */
	PA1_I2C2_SCL     = (0x09), /*!< GPA_MFP0 PA1 setting for I2C2_SCL    */
	PA1_CCAP_DATA7   = (0x0a), /*!< GPA_MFP0 PA1 setting for CCAP_DATA7  */
	PA1_BPWM0_CH1    = (0x0c), /*!< GPA_MFP0 PA1 setting for BPWM0_CH1   */
	PA1_EPWM0_CH4    = (0x0d), /*!< GPA_MFP0 PA1 setting for EPWM0_CH4   */
	PA1_EQEI3_A      = (0x0e), /*!< GPA_MFP0 PA1 setting for EQEI3_A     */
	PA1_DAC1_ST      = (0x0f), /*!< GPA_MFP0 PA1 setting for DAC1_ST     */
	PA1_PSIO0_CH6    = (0x11), /*!< GPA_MFP0 PA1 setting for PSIO0_CH6   */
	PA1_BMC18        = (0x14), /*!< GPA_MFP0 PA1 setting for BMC18 (0xM460xGCAE only), */

	/* PA.2 MFP */
	PA2_GPIO         = (0x00), /*!< GPA_MFP0 PA2 setting for GPIO        */
	PA2_SPIM_CLK     = (0x02), /*!< GPA_MFP0 PA2 setting for SPIM_CLK    */
	PA2_QSPI0_CLK    = (0x03), /*!< GPA_MFP0 PA2 setting for QSPI0_CLK   */
	PA2_SPI0_CLK     = (0x04), /*!< GPA_MFP0 PA2 setting for SPI0_CLK    */
	PA2_SD1_DAT2     = (0x05), /*!< GPA_MFP0 PA2 setting for SD1_DAT2    */
	PA2_SC0_RST      = (0x06), /*!< GPA_MFP0 PA2 setting for SC0_RST     */
	PA2_UART4_RXD    = (0x07), /*!< GPA_MFP0 PA2 setting for UART4_RXD   */
	PA2_UART1_RXD    = (0x08), /*!< GPA_MFP0 PA2 setting for UART1_RXD   */
	PA2_I2C1_SDA     = (0x09), /*!< GPA_MFP0 PA2 setting for I2C1_SDA    */
	PA2_I2C0_SMBSUS  = (0x0a), /*!< GPA_MFP0 PA2 setting for I2C0_SMBSUS */
	PA2_BPWM0_CH2    = (0x0c), /*!< GPA_MFP0 PA2 setting for BPWM0_CH2   */
	PA2_EPWM0_CH3    = (0x0d), /*!< GPA_MFP0 PA2 setting for EPWM0_CH3   */
	PA2_EQEI3_INDEX  = (0x0e), /*!< GPA_MFP0 PA2 setting for EQEI3_INDEX */
	PA2_PSIO0_CH5    = (0x11), /*!< GPA_MFP0 PA2 setting for PSIO0_CH5   */
	PA2_BMC17        = (0x14), /*!< GPA_MFP0 PA2 setting for BMC17 (0xM460xGCAE only), */

	/* PA.3 MFP */
	PA3_GPIO         = (0x00), /*!< GPA_MFP0 PA3 setting for GPIO        */
	PA3_SPIM_SS      = (0x02), /*!< GPA_MFP0 PA3 setting for SPIM_SS     */
	PA3_QSPI0_SS     = (0x03), /*!< GPA_MFP0 PA3 setting for QSPI0_SS    */
	PA3_SPI0_SS      = (0x04), /*!< GPA_MFP0 PA3 setting for SPI0_SS     */
	PA3_SD1_DAT3     = (0x05), /*!< GPA_MFP0 PA3 setting for SD1_DAT3    */
	PA3_SC0_PWR      = (0x06), /*!< GPA_MFP0 PA3 setting for SC0_PWR     */
	PA3_UART4_TXD    = (0x07), /*!< GPA_MFP0 PA3 setting for UART4_TXD   */
	PA3_UART1_TXD    = (0x08), /*!< GPA_MFP0 PA3 setting for UART1_TXD   */
	PA3_I2C1_SCL     = (0x09), /*!< GPA_MFP0 PA3 setting for I2C1_SCL    */
	PA3_I2C0_SMBAL   = (0x0a), /*!< GPA_MFP0 PA3 setting for I2C0_SMBAL  */
	PA3_BPWM0_CH3    = (0x0c), /*!< GPA_MFP0 PA3 setting for BPWM0_CH3   */
	PA3_EPWM0_CH2    = (0x0d), /*!< GPA_MFP0 PA3 setting for EPWM0_CH2   */
	PA3_EQEI0_B      = (0x0e), /*!< GPA_MFP0 PA3 setting for EQEI0_B     */
	PA3_EPWM1_BRAKE1 = (0x0f), /*!< GPA_MFP0 PA3 setting for EPWM1_BRAKE1*/
	PA3_PSIO0_CH4    = (0x11), /*!< GPA_MFP0 PA3 setting for PSIO0_CH4   */
	PA3_BMC16        = (0x14), /*!< GPA_MFP0 PA3 setting for BMC16 (0xM460xGCAE only), */

	/* PA.4 MFP */
	PA4_GPIO         = (0x00), /*!< GPA_MFP1 PA4 setting for GPIO        */
	PA4_SPIM_D3      = (0x02), /*!< GPA_MFP1 PA4 setting for SPIM_D3     */
	PA4_QSPI0_MOSI1  = (0x03), /*!< GPA_MFP1 PA4 setting for QSPI0_MOSI1 */
	PA4_SPI0_I2SMCLK = (0x04), /*!< GPA_MFP1 PA4 setting for SPI0_I2SMCLK*/
	PA4_SD1_CLK      = (0x05), /*!< GPA_MFP1 PA4 setting for SD1_CLK     */
	PA4_SC0_nCD      = (0x06), /*!< GPA_MFP1 PA4 setting for SC0_nCD     */
	PA4_UART0_nRTS   = (0x07), /*!< GPA_MFP1 PA4 setting for UART0_nRTS  */
	PA4_UART5_RXD    = (0x08), /*!< GPA_MFP1 PA4 setting for UART5_RXD   */
	PA4_I2C0_SDA     = (0x09), /*!< GPA_MFP1 PA4 setting for I2C0_SDA    */
	PA4_CAN0_RXD     = (0x0a), /*!< GPA_MFP1 PA4 setting for CAN0_RXD    */
	PA4_UART0_RXD    = (0x0b), /*!< GPA_MFP1 PA4 setting for UART0_RXD   */
	PA4_BPWM0_CH4    = (0x0c), /*!< GPA_MFP1 PA4 setting for BPWM0_CH4   */
	PA4_EPWM0_CH1    = (0x0d), /*!< GPA_MFP1 PA4 setting for EPWM0_CH1   */
	PA4_EQEI0_A      = (0x0e), /*!< GPA_MFP1 PA4 setting for EQEI0_A     */

	/* PA.5 MFP */
	PA5_GPIO         = (0x00), /*!< GPA_MFP1 PA5 setting for GPIO        */
	PA5_SPIM_D2      = (0x02), /*!< GPA_MFP1 PA5 setting for SPIM_D2     */
	PA5_QSPI0_MISO1  = (0x03), /*!< GPA_MFP1 PA5 setting for QSPI0_MISO1 */
	PA5_SPI1_I2SMCLK = (0x04), /*!< GPA_MFP1 PA5 setting for SPI1_I2SMCLK*/
	PA5_SD1_CMD      = (0x05), /*!< GPA_MFP1 PA5 setting for SD1_CMD     */
	PA5_SC2_nCD      = (0x06), /*!< GPA_MFP1 PA5 setting for SC2_nCD     */
	PA5_UART0_nCTS   = (0x07), /*!< GPA_MFP1 PA5 setting for UART0_nCTS  */
	PA5_UART5_TXD    = (0x08), /*!< GPA_MFP1 PA5 setting for UART5_TXD   */
	PA5_I2C0_SCL     = (0x09), /*!< GPA_MFP1 PA5 setting for I2C0_SCL    */
	PA5_CAN0_TXD     = (0x0a), /*!< GPA_MFP1 PA5 setting for CAN0_TXD    */
	PA5_UART0_TXD    = (0x0b), /*!< GPA_MFP1 PA5 setting for UART0_TXD   */
	PA5_BPWM0_CH5    = (0x0c), /*!< GPA_MFP1 PA5 setting for BPWM0_CH5   */
	PA5_EPWM0_CH0    = (0x0d), /*!< GPA_MFP1 PA5 setting for EPWM0_CH0   */
	PA5_EQEI0_INDEX  = (0x0e), /*!< GPA_MFP1 PA5 setting for EQEI0_INDEX */

	/* PA.6 MFP */
	PA6_GPIO         = (0x00), /*!< GPA_MFP1 PA6 setting for GPIO        */
	PA6_EBI_AD6      = (0x02), /*!< GPA_MFP1 PA6 setting for EBI_AD6     */
	PA6_EMAC0_RMII_RXERR = (0x03), /*!< GPA_MFP1 PA6 setting for EMAC0_RMII_RXERR*/
	PA6_SPI1_SS      = (0x04), /*!< GPA_MFP1 PA6 setting for SPI1_SS     */
	PA6_SD1_nCD      = (0x05), /*!< GPA_MFP1 PA6 setting for SD1_nCD     */
	PA6_SC2_CLK      = (0x06), /*!< GPA_MFP1 PA6 setting for SC2_CLK     */
	PA6_UART0_RXD    = (0x07), /*!< GPA_MFP1 PA6 setting for UART0_RXD   */
	PA6_I2C1_SDA     = (0x08), /*!< GPA_MFP1 PA6 setting for I2C1_SDA    */
	PA6_QSPI1_MOSI1  = (0x09), /*!< GPA_MFP1 PA6 setting for QSPI1_MOSI1 */
	PA6_EPWM1_CH5    = (0x0b), /*!< GPA_MFP1 PA6 setting for EPWM1_CH5   */
	PA6_BPWM1_CH3    = (0x0c), /*!< GPA_MFP1 PA6 setting for BPWM1_CH3   */
	PA6_ACMP1_WLAT   = (0x0d), /*!< GPA_MFP1 PA6 setting for ACMP1_WLAT  */
	PA6_TM3          = (0x0e), /*!< GPA_MFP1 PA6 setting for TM3         */
	PA6_INT0         = (0x0f), /*!< GPA_MFP1 PA6 setting for INT0        */
	PA6_SPI5_CLK     = (0x11), /*!< GPA_MFP1 PA6 setting for SPI5_CLK (0xM460xGCAE only), */
	PA6_KPI_COL0     = (0x12), /*!< GPA_MFP1 PA6 setting for KPI_COL0    */
	PA6_SPI6_CLK     = (0x13), /*!< GPA_MFP1 PA6 setting for SPI6_CLK (0xM460xGCAE only), */
	PA6_BMC15        = (0x14), /*!< GPA_MFP1 PA6 setting for BMC15    (0xM460xGCAE only), */

	/* PA.7 MFP */
	PA7_GPIO         = (0x00), /*!< GPA_MFP1 PA7 setting for GPIO        */
	PA7_EBI_AD7      = (0x02), /*!< GPA_MFP1 PA7 setting for EBI_AD7     */
	PA7_EMAC0_RMII_CRSDV = (0x03), /*!< GPA_MFP1 PA7 setting for EMAC0_RMII_CRSDV*/
	PA7_SPI1_CLK     = (0x04), /*!< GPA_MFP1 PA7 setting for SPI1_CLK    */
	PA7_SC2_DAT      = (0x06), /*!< GPA_MFP1 PA7 setting for SC2_DAT     */
	PA7_UART0_TXD    = (0x07), /*!< GPA_MFP1 PA7 setting for UART0_TXD   */
	PA7_I2C1_SCL     = (0x08), /*!< GPA_MFP1 PA7 setting for I2C1_SCL    */
	PA7_QSPI1_MISO1  = (0x09), /*!< GPA_MFP1 PA7 setting for QSPI1_MISO1 */
	PA7_EPWM1_CH4    = (0x0b), /*!< GPA_MFP1 PA7 setting for EPWM1_CH4   */
	PA7_BPWM1_CH2    = (0x0c), /*!< GPA_MFP1 PA7 setting for BPWM1_CH2   */
	PA7_ACMP0_WLAT   = (0x0d), /*!< GPA_MFP1 PA7 setting for ACMP0_WLAT  */
	PA7_TM2          = (0x0e), /*!< GPA_MFP1 PA7 setting for TM2         */
	PA7_INT1         = (0x0f), /*!< GPA_MFP1 PA7 setting for INT1        */
	PA7_SPI5_SS      = (0x11), /*!< GPA_MFP1 PA7 setting for SPI5_SS (0xM460xGCAE only), */
	PA7_KPI_COL1     = (0x12), /*!< GPA_MFP1 PA7 setting for KPI_COL1    */
	PA7_SPI6_SS      = (0x13), /*!< GPA_MFP1 PA7 setting for SPI6_SS (0xM460xGCAE only), */
	PA7_BMC14        = (0x14), /*!< GPA_MFP1 PA7 setting for BMC14   (0xM460xGCAE only), */

	/* PA.8 MFP */
	PA8_GPIO         = (0x00), /*!< GPA_MFP2 PA8 setting for GPIO        */
	PA8_EADC1_CH4    = (0x01), /*!< GPA_MFP2 PA8 setting for EADC1_CH4   */
	PA8_EADC2_CH4    = (0x01), /*!< GPA_MFP2 PA8 setting for EADC2_CH4   */
	PA8_EBI_ALE      = (0x02), /*!< GPA_MFP2 PA8 setting for EBI_ALE     */
	PA8_SC2_CLK      = (0x03), /*!< GPA_MFP2 PA8 setting for SC2_CLK     */
	PA8_SPI2_MOSI    = (0x04), /*!< GPA_MFP2 PA8 setting for SPI2_MOSI   */
	PA8_SD1_DAT0     = (0x05), /*!< GPA_MFP2 PA8 setting for SD1_DAT0    */
	PA8_USCI0_CTL1   = (0x06), /*!< GPA_MFP2 PA8 setting for USCI0_CTL1  */
	PA8_UART1_RXD    = (0x07), /*!< GPA_MFP2 PA8 setting for UART1_RXD   */
	PA8_UART7_RXD    = (0x08), /*!< GPA_MFP2 PA8 setting for UART7_RXD   */
	PA8_BPWM0_CH3    = (0x09), /*!< GPA_MFP2 PA8 setting for BPWM0_CH3   */
	PA8_EQEI1_B      = (0x0a), /*!< GPA_MFP2 PA8 setting for EQEI1_B     */
	PA8_ECAP0_IC2    = (0x0b), /*!< GPA_MFP2 PA8 setting for ECAP0_IC2   */
	PA8_I2S1_DO      = (0x0c), /*!< GPA_MFP2 PA8 setting for I2S1_DO     */
	PA8_TM3_EXT      = (0x0d), /*!< GPA_MFP2 PA8 setting for TM3_EXT     */
	PA8_INT4         = (0x0f), /*!< GPA_MFP2 PA8 setting for INT4        */
	PA8_BMC9         = (0x14), /*!< GPA_MFP2 PA8 setting for BMC9 (0xM460xGCAE only), */

	/* PA.9 MFP */
	PA9_GPIO         = (0x00), /*!< GPA_MFP2 PA9 setting for GPIO        */
	PA9_EADC1_CH5    = (0x01), /*!< GPA_MFP2 PA9 setting for EADC1_CH5   */
	PA9_EADC2_CH5    = (0x01), /*!< GPA_MFP2 PA9 setting for EADC2_CH5   */
	PA9_EBI_MCLK     = (0x02), /*!< GPA_MFP2 PA9 setting for EBI_MCLK    */
	PA9_SC2_DAT      = (0x03), /*!< GPA_MFP2 PA9 setting for SC2_DAT     */
	PA9_SPI2_MISO    = (0x04), /*!< GPA_MFP2 PA9 setting for SPI2_MISO   */
	PA9_SD1_DAT1     = (0x05), /*!< GPA_MFP2 PA9 setting for SD1_DAT1    */
	PA9_USCI0_DAT1   = (0x06), /*!< GPA_MFP2 PA9 setting for USCI0_DAT1  */
	PA9_UART1_TXD    = (0x07), /*!< GPA_MFP2 PA9 setting for UART1_TXD   */
	PA9_UART7_TXD    = (0x08), /*!< GPA_MFP2 PA9 setting for UART7_TXD   */
	PA9_BPWM0_CH2    = (0x09), /*!< GPA_MFP2 PA9 setting for BPWM0_CH2   */
	PA9_EQEI1_A      = (0x0a), /*!< GPA_MFP2 PA9 setting for EQEI1_A     */
	PA9_ECAP0_IC1    = (0x0b), /*!< GPA_MFP2 PA9 setting for ECAP0_IC1   */
	PA9_I2S1_DI      = (0x0c), /*!< GPA_MFP2 PA9 setting for I2S1_DI     */
	PA9_TM2_EXT      = (0x0d), /*!< GPA_MFP2 PA9 setting for TM2_EXT     */
	PA9_SWDH_DAT     = (0x0f), /*!< GPA_MFP2 PA9 setting for SWDH_DAT    */
	PA9_BMC8         = (0x14), /*!< GPA_MFP2 PA9 setting for BMC8 (0xM460xGCAE only), */

	/* PA.10 MFP */
	PA10_GPIO        = (0x00),/*!< GPA_MFP2 PA10 setting for GPIO       */
	PA10_EADC1_CH6   = (0x01),/*!< GPA_MFP2 PA10 setting for EADC1_CH6  */
	PA10_EADC2_CH6   = (0x01),/*!< GPA_MFP2 PA10 setting for EADC2_CH6  */
	PA10_ACMP1_P0    = (0x01),/*!< GPA_MFP2 PA10 setting for ACMP1_P0   */
	PA10_EBI_nWR     = (0x02),/*!< GPA_MFP2 PA10 setting for EBI_nWR    */
	PA10_SC2_RST     = (0x03),/*!< GPA_MFP2 PA10 setting for SC2_RST    */
	PA10_SPI2_CLK    = (0x04),/*!< GPA_MFP2 PA10 setting for SPI2_CLK   */
	PA10_SD1_DAT2    = (0x05),/*!< GPA_MFP2 PA10 setting for SD1_DAT2   */
	PA10_USCI0_DAT0  = (0x06),/*!< GPA_MFP2 PA10 setting for USCI0_DAT0 */
	PA10_I2C2_SDA    = (0x07),/*!< GPA_MFP2 PA10 setting for I2C2_SDA   */
	PA10_UART6_RXD   = (0x08),/*!< GPA_MFP2 PA10 setting for UART6_RXD  */
	PA10_BPWM0_CH1   = (0x09),/*!< GPA_MFP2 PA10 setting for BPWM0_CH1  */
	PA10_EQEI1_INDEX = (0x0a),/*!< GPA_MFP2 PA10 setting for EQEI1_INDEX */
	PA10_ECAP0_IC0   = (0x0b),/*!< GPA_MFP2 PA10 setting for ECAP0_IC0  */
	PA10_I2S1_MCLK   = (0x0c),/*!< GPA_MFP2 PA10 setting for I2S1_MCLK  */
	PA10_TM1_EXT     = (0x0d),/*!< GPA_MFP2 PA10 setting for TM1_EXT    */
	PA10_DAC0_ST     = (0x0e),/*!< GPA_MFP2 PA10 setting for DAC0_ST    */
	PA10_SWDH_CLK    = (0x0f),/*!< GPA_MFP2 PA10 setting for SWDH_CLK   */
	PA10_KPI_ROW5    = (0x12),/*!< GPA_MFP2 PA10 setting for KPI_ROW5   */
	PA10_BMC7        = (0x14),/*!< GPA_MFP2 PA10 setting for BMC7 (0xM460xGCAE only), */

	/* PA.11 MFP */
	PA11_GPIO        = (0x00),/*!< GPA_MFP2 PA11 setting for GPIO       */
	PA11_EADC1_CH7   = (0x01),/*!< GPA_MFP2 PA11 setting for EADC1_CH7  */
	PA11_EADC2_CH7   = (0x01),/*!< GPA_MFP2 PA11 setting for EADC2_CH7  */
	PA11_ACMP0_P0    = (0x01),/*!< GPA_MFP2 PA11 setting for ACMP0_P0   */
	PA11_EBI_nRD     = (0x02),/*!< GPA_MFP2 PA11 setting for EBI_nRD    */
	PA11_SC2_PWR     = (0x03),/*!< GPA_MFP2 PA11 setting for SC2_PWR    */
	PA11_SPI2_SS     = (0x04),/*!< GPA_MFP2 PA11 setting for SPI2_SS    */
	PA11_SD1_DAT3    = (0x05),/*!< GPA_MFP2 PA11 setting for SD1_DAT3   */
	PA11_USCI0_CLK   = (0x06),/*!< GPA_MFP2 PA11 setting for USCI0_CLK  */
	PA11_I2C2_SCL    = (0x07),/*!< GPA_MFP2 PA11 setting for I2C2_SCL   */
	PA11_UART6_TXD   = (0x08),/*!< GPA_MFP2 PA11 setting for UART6_TXD  */
	PA11_BPWM0_CH0   = (0x09),/*!< GPA_MFP2 PA11 setting for BPWM0_CH0  */
	PA11_EPWM0_SYNC_OUT = (0x0a),/*!< GPA_MFP2 PA11 setting for EPWM0_SYNC_OUT*/
	PA11_I2S1_BCLK   = (0x0c),/*!< GPA_MFP2 PA11 setting for I2S1_BCLK  */
	PA11_TM0_EXT     = (0x0d),/*!< GPA_MFP2 PA11 setting for TM0_EXT    */
	PA11_DAC1_ST     = (0x0e),/*!< GPA_MFP2 PA11 setting for DAC1_ST    */
	PA11_KPI_ROW4    = (0x12),/*!< GPA_MFP2 PA11 setting for KPI_ROW4   */
	PA11_BMC6        = (0x14),/*!< GPA_MFP2 PA11 setting for BMC6 (0xM460xGCAE only), */

	/* PA.12 MFP */
	PA12_GPIO        = (0x00),/*!< GPA_MFP3 PA12 setting for GPIO       */
	PA12_I2S0_BCLK   = (0x02),/*!< GPA_MFP3 PA12 setting for I2S0_BCLK  */
	PA12_UART4_TXD   = (0x03),/*!< GPA_MFP3 PA12 setting for UART4_TXD  */
	PA12_I2C1_SCL    = (0x04),/*!< GPA_MFP3 PA12 setting for I2C1_SCL   */
	PA12_SPI2_SS     = (0x05),/*!< GPA_MFP3 PA12 setting for SPI2_SS    */
	PA12_CAN0_TXD    = (0x06),/*!< GPA_MFP3 PA12 setting for CAN0_TXD   */
	PA12_SC2_PWR     = (0x07),/*!< GPA_MFP3 PA12 setting for SC2_PWR    */
	PA12_SD1_nCD     = (0x08),/*!< GPA_MFP3 PA12 setting for SD1_nCD    */
	PA12_SPI0_SS     = (0x09),/*!< GPA_MFP3 PA12 setting for SPI0_SS    */
	PA12_QSPI1_MISO0 = (0x0a),/*!< GPA_MFP3 PA12 setting for QSPI1_MISO0*/
	PA12_BPWM1_CH2   = (0x0b),/*!< GPA_MFP3 PA12 setting for BPWM1_CH2  */
	PA12_EQEI1_INDEX = (0x0c),/*!< GPA_MFP3 PA12 setting for EQEI1_INDEX */
	PA12_ECAP3_IC0   = (0x0d),/*!< GPA_MFP3 PA12 setting for ECAP3_IC0  */
	PA12_USB_VBUS    = (0x0e),/*!< GPA_MFP3 PA12 setting for USB_VBUS   */
	PA12_PSIO0_CH4   = (0x11),/*!< GPA_MFP3 PA12 setting for PSIO0_CH4  */
	PA12_SPI10_SS    = (0x13),/*!< GPA_MFP3 PA12 setting for SPI10_SS (0xM460xGCAE only), */
	PA12_BMC12       = (0x14),/*!< GPA_MFP3 PA12 setting for BMC12    (0xM460xGCAE only), */

	/* PA.13 MFP */
	PA13_GPIO        = (0x00),/*!< GPA_MFP3 PA13 setting for GPIO       */
	PA13_I2S0_MCLK   = (0x02),/*!< GPA_MFP3 PA13 setting for I2S0_MCLK  */
	PA13_UART4_RXD   = (0x03),/*!< GPA_MFP3 PA13 setting for UART4_RXD  */
	PA13_I2C1_SDA    = (0x04),/*!< GPA_MFP3 PA13 setting for I2C1_SDA   */
	PA13_SPI2_CLK    = (0x05),/*!< GPA_MFP3 PA13 setting for SPI2_CLK   */
	PA13_CAN0_RXD    = (0x06),/*!< GPA_MFP3 PA13 setting for CAN0_RXD   */
	PA13_SC2_RST     = (0x07),/*!< GPA_MFP3 PA13 setting for SC2_RST    */
	PA13_SPI0_CLK    = (0x09),/*!< GPA_MFP3 PA13 setting for SPI0_CLK   */
	PA13_QSPI1_MOSI0 = (0x0a),/*!< GPA_MFP3 PA13 setting for QSPI1_MOSI0*/
	PA13_BPWM1_CH3   = (0x0b),/*!< GPA_MFP3 PA13 setting for BPWM1_CH3  */
	PA13_EQEI1_A     = (0x0c),/*!< GPA_MFP3 PA13 setting for EQEI1_A    */
	PA13_ECAP3_IC1   = (0x0d),/*!< GPA_MFP3 PA13 setting for ECAP3_IC1  */
	PA13_USB_D_N     = (0x0e),/*!< GPA_MFP3 PA13 setting for USB_D-     */
	PA13_PSIO0_CH5   = (0x11),/*!< GPA_MFP3 PA13 setting for PSIO0_CH5  */
	PA13_SPI10_CLK   = (0x13),/*!< GPA_MFP3 PA13 setting for SPI10_CLK (0xM460xGCAE only), */
	PA13_BMC13       = (0x14),/*!< GPA_MFP3 PA13 setting for BMC13     (0xM460xGCAE only), */

	/* PA.14 MFP */
	PA14_GPIO        = (0x00),/*!< GPA_MFP3 PA14 setting for GPIO       */
	PA14_I2S0_DI     = (0x02),/*!< GPA_MFP3 PA14 setting for I2S0_DI    */
	PA14_UART0_TXD   = (0x03),/*!< GPA_MFP3 PA14 setting for UART0_TXD  */
	PA14_EBI_AD5     = (0x04),/*!< GPA_MFP3 PA14 setting for EBI_AD5    */
	PA14_SPI2_MISO   = (0x05),/*!< GPA_MFP3 PA14 setting for SPI2_MISO  */
	PA14_I2C2_SCL    = (0x06),/*!< GPA_MFP3 PA14 setting for I2C2_SCL   */
	PA14_SC2_DAT     = (0x07),/*!< GPA_MFP3 PA14 setting for SC2_DAT    */
	PA14_SPI0_MISO   = (0x09),/*!< GPA_MFP3 PA14 setting for SPI0_MISO  */
	PA14_BPWM1_CH4   = (0x0b),/*!< GPA_MFP3 PA14 setting for BPWM1_CH4  */
	PA14_EQEI1_B     = (0x0c),/*!< GPA_MFP3 PA14 setting for EQEI1_B    */
	PA14_ECAP3_IC2   = (0x0d),/*!< GPA_MFP3 PA14 setting for ECAP3_IC2  */
	PA14_USB_D_P     = (0x0e),/*!< GPA_MFP3 PA14 setting for USB_D+     */
	PA14_I2C0_SCL    = (0x10),/*!< GPA_MFP3 PA14 setting for I2C0_SCL   */
	PA14_PSIO0_CH6   = (0x11),/*!< GPA_MFP3 PA14 setting for PSIO0_CH6  */
	PA14_SPI10_MISO  = (0x13),/*!< GPA_MFP3 PA14 setting for SPI10_MISO (0xM460xGCAE only), */
	PA14_BMC14       = (0x14),/*!< GPA_MFP3 PA14 setting for BMC14      (0xM460xGCAE only), */

	/* PA.15 MFP */
	PA15_GPIO        = (0x00),/*!< GPA_MFP3 PA15 setting for GPIO       */
	PA15_I2S0_DO     = (0x02),/*!< GPA_MFP3 PA15 setting for I2S0_DO    */
	PA15_UART0_RXD   = (0x03),/*!< GPA_MFP3 PA15 setting for UART0_RXD  */
	PA15_SPIM_MOSI   = (0x04),/*!< GPA_MFP3 PA15 setting for SPIM_MOSI  */
	PA15_SPI2_MOSI   = (0x05),/*!< GPA_MFP3 PA15 setting for SPI2_MOSI  */
	PA15_I2C2_SDA    = (0x06),/*!< GPA_MFP3 PA15 setting for I2C2_SDA   */
	PA15_SC2_CLK     = (0x07),/*!< GPA_MFP3 PA15 setting for SC2_CLK    */
	PA15_SPI0_MOSI   = (0x09),/*!< GPA_MFP3 PA15 setting for SPI0_MOSI  */
	PA15_BPWM1_CH5   = (0x0b),/*!< GPA_MFP3 PA15 setting for BPWM1_CH5  */
	PA15_EPWM0_SYNC_IN = (0x0c),/*!< GPA_MFP3 PA15 setting for EPWM0_SYNC_IN*/
	PA15_EQEI3_INDEX = (0x0d),/*!< GPA_MFP3 PA15 setting for EQEI3_INDEX */
	PA15_USB_OTG_ID  = (0x0e),/*!< GPA_MFP3 PA15 setting for USB_OTG_ID */
	PA15_I2C0_SDA    = (0x10),/*!< GPA_MFP3 PA15 setting for I2C0_SDA   */
	PA15_PSIO0_CH7   = (0x11),/*!< GPA_MFP3 PA15 setting for PSIO0_CH7  */
	PA15_SPI10_MOSI  = (0x13),/*!< GPA_MFP3 PA15 setting for SPI10_MOSI (0xM460xGCAE only), */
	PA15_BMC15       = (0x14),/*!< GPA_MFP3 PA15 setting for BMC15      (0xM460xGCAE only), */

	/* PB.0 MFP */
	PB0_GPIO         = (0x00), /*!< GPB_MFP0 PB0 setting for GPIO        */
	PB0_EADC0_CH0    = (0x01), /*!< GPB_MFP0 PB0 setting for EADC0_CH0   */
	PB0_EADC1_CH8    = (0x01), /*!< GPB_MFP0 PB0 setting for EADC1_CH8   */
	PB0_EADC2_CH8    = (0x01), /*!< GPB_MFP0 PB0 setting for EADC2_CH8   */
	PB0_ACMP3_N      = (0x01), /*!< GPB_MFP0 PB0 setting for ACMP3_N     */
	PB0_EBI_ADR9     = (0x02), /*!< GPB_MFP0 PB0 setting for EBI_ADR9    */
	PB0_SD0_CMD      = (0x03), /*!< GPB_MFP0 PB0 setting for SD0_CMD     */
	PB0_SPI2_I2SMCLK = (0x04), /*!< GPB_MFP0 PB0 setting for SPI2_I2SMCLK*/
	PB0_USCI0_CTL0   = (0x06), /*!< GPB_MFP0 PB0 setting for USCI0_CTL0  */
	PB0_UART2_RXD    = (0x07), /*!< GPB_MFP0 PB0 setting for UART2_RXD   */
	PB0_SPI0_I2SMCLK = (0x08), /*!< GPB_MFP0 PB0 setting for SPI0_I2SMCLK*/
	PB0_I2C1_SDA     = (0x09), /*!< GPB_MFP0 PB0 setting for I2C1_SDA    */
	PB0_I2S1_LRCK    = (0x0a), /*!< GPB_MFP0 PB0 setting for I2S1_LRCK   */
	PB0_EPWM0_CH5    = (0x0b), /*!< GPB_MFP0 PB0 setting for EPWM0_CH5   */
	PB0_EPWM1_CH5    = (0x0c), /*!< GPB_MFP0 PB0 setting for EPWM1_CH5   */
	PB0_EPWM0_BRAKE1 = (0x0d), /*!< GPB_MFP0 PB0 setting for EPWM0_BRAKE1*/
	PB0_ACMP3_O      = (0x0e), /*!< GPB_MFP0 PB0 setting for ACMP3_O     */
	PB0_QSPI0_MOSI1  = (0x0f), /*!< GPB_MFP0 PB0 setting for QSPI0_MOSI1 */
	PB0_KPI_ROW3     = (0x12), /*!< GPB_MFP0 PB0 setting for KPI_ROW3    */
	PB0_SPI4_MOSI    = (0x13), /*!< GPB_MFP0 PB0 setting for SPI4_MOSI (0xM460xGCAE only), */
	PB0_BMC5         = (0x14), /*!< GPB_MFP0 PB0 setting for BMC5      (0xM460xGCAE only), */

	/* PB.1 MFP */
	PB1_GPIO         = (0x00), /*!< GPB_MFP0 PB1 setting for GPIO        */
	PB1_EADC0_CH1    = (0x01), /*!< GPB_MFP0 PB1 setting for EADC0_CH1   */
	PB1_EADC1_CH9    = (0x01), /*!< GPB_MFP0 PB1 setting for EADC1_CH9   */
	PB1_EADC2_CH9    = (0x01), /*!< GPB_MFP0 PB1 setting for EADC2_CH9   */
	PB1_ACMP3_P0     = (0x01), /*!< GPB_MFP0 PB1 setting for ACMP3_P0    */
	PB1_EBI_ADR8     = (0x02), /*!< GPB_MFP0 PB1 setting for EBI_ADR8    */
	PB1_SD0_CLK      = (0x03), /*!< GPB_MFP0 PB1 setting for SD0_CLK     */
	PB1_EMAC0_RMII_RXERR = (0x04), /*!< GPB_MFP0 PB1 setting for EMAC0_RMII_RXERR*/
	PB1_SPI1_I2SMCLK = (0x05), /*!< GPB_MFP0 PB1 setting for SPI1_I2SMCLK*/
	PB1_SPI3_I2SMCLK = (0x06), /*!< GPB_MFP0 PB1 setting for SPI3_I2SMCLK*/
	PB1_UART2_TXD    = (0x07), /*!< GPB_MFP0 PB1 setting for UART2_TXD   */
	PB1_I2C1_SCL     = (0x09), /*!< GPB_MFP0 PB1 setting for I2C1_SCL    */
	PB1_I2S0_LRCK    = (0x0a), /*!< GPB_MFP0 PB1 setting for I2S0_LRCK   */
	PB1_EPWM0_CH4    = (0x0b), /*!< GPB_MFP0 PB1 setting for EPWM0_CH4   */
	PB1_EPWM1_CH4    = (0x0c), /*!< GPB_MFP0 PB1 setting for EPWM1_CH4   */
	PB1_EPWM0_BRAKE0 = (0x0d), /*!< GPB_MFP0 PB1 setting for EPWM0_BRAKE0*/
	PB1_ACMP2_O      = (0x0e), /*!< GPB_MFP0 PB1 setting for ACMP2_O     */
	PB1_QSPI0_MISO1  = (0x0f), /*!< GPB_MFP0 PB1 setting for QSPI0_MISO1 */
	PB1_KPI_ROW2     = (0x12), /*!< GPB_MFP0 PB1 setting for KPI_ROW2    */
	PB1_SPI4_MISO    = (0x13), /*!< GPB_MFP0 PB1 setting for SPI4_MISO (0xM460xGCAE only), */
	PB1_BMC4         = (0x14), /*!< GPB_MFP0 PB1 setting for BMC4      (0xM460xGCAE only),  */

	/* PB.2 MFP */
	PB2_GPIO         = (0x00), /*!< GPB_MFP0 PB2 setting for GPIO        */
	PB2_EADC0_CH2    = (0x01), /*!< GPB_MFP0 PB2 setting for EADC0_CH2   */
	PB2_EADC1_CH10   = (0x01), /*!< GPB_MFP0 PB2 setting for EADC1_CH10  */
	PB2_ACMP0_P1     = (0x01), /*!< GPB_MFP0 PB2 setting for ACMP0_P1    */
	PB2_EBI_ADR3     = (0x02), /*!< GPB_MFP0 PB2 setting for EBI_ADR3    */
	PB2_SD0_DAT0     = (0x03), /*!< GPB_MFP0 PB2 setting for SD0_DAT0    */
	PB2_EMAC0_RMII_CRSDV = (0x04), /*!< GPB_MFP0 PB2 setting for EMAC0_RMII_CRSDV*/
	PB2_SPI1_SS      = (0x05), /*!< GPB_MFP0 PB2 setting for SPI1_SS     */
	PB2_UART1_RXD    = (0x06), /*!< GPB_MFP0 PB2 setting for UART1_RXD   */
	PB2_UART5_nCTS   = (0x07), /*!< GPB_MFP0 PB2 setting for UART5_nCTS  */
	PB2_SC0_PWR      = (0x09), /*!< GPB_MFP0 PB2 setting for SC0_PWR     */
	PB2_I2S0_DO      = (0x0a), /*!< GPB_MFP0 PB2 setting for I2S0_DO     */
	PB2_EPWM0_CH3    = (0x0b), /*!< GPB_MFP0 PB2 setting for EPWM0_CH3   */
	PB2_I2C1_SDA     = (0x0c), /*!< GPB_MFP0 PB2 setting for I2C1_SDA    */
	PB2_TM3          = (0x0e), /*!< GPB_MFP0 PB2 setting for TM3         */
	PB2_INT3         = (0x0f), /*!< GPB_MFP0 PB2 setting for INT3        */
	PB2_PSIO0_CH7    = (0x11), /*!< GPB_MFP0 PB2 setting for PSIO0_CH7   */
	PB2_KPI_ROW1     = (0x12), /*!< GPB_MFP0 PB2 setting for KPI_ROW1    */
	PB2_SPI4_CLK     = (0x13), /*!< GPB_MFP0 PB2 setting for SPI4_CLK (0xM460xGCAE only), */
	PB2_BMC3         = (0x14), /*!< GPB_MFP0 PB2 setting for BMC3     (0xM460xGCAE only),   */

	/* PB.3 MFP */
	PB3_GPIO         = (0x00), /*!< GPB_MFP0 PB3 setting for GPIO        */
	PB3_EADC0_CH3    = (0x01), /*!< GPB_MFP0 PB3 setting for EADC0_CH3   */
	PB3_EADC1_CH11   = (0x01), /*!< GPB_MFP0 PB3 setting for EADC1_CH11  */
	PB3_ACMP0_N      = (0x01), /*!< GPB_MFP0 PB3 setting for ACMP0_N     */
	PB3_EBI_ADR2     = (0x02), /*!< GPB_MFP0 PB3 setting for EBI_ADR2    */
	PB3_SD0_DAT1     = (0x03), /*!< GPB_MFP0 PB3 setting for SD0_DAT1    */
	PB3_EMAC0_RMII_RXD1 = (0x04), /*!< GPB_MFP0 PB3 setting for EMAC0_RMII_RXD1*/
	PB3_SPI1_CLK     = (0x05), /*!< GPB_MFP0 PB3 setting for SPI1_CLK    */
	PB3_UART1_TXD    = (0x06), /*!< GPB_MFP0 PB3 setting for UART1_TXD   */
	PB3_UART5_nRTS   = (0x07), /*!< GPB_MFP0 PB3 setting for UART5_nRTS  */
	PB3_SC0_RST      = (0x09), /*!< GPB_MFP0 PB3 setting for SC0_RST     */
	PB3_I2S0_DI      = (0x0a), /*!< GPB_MFP0 PB3 setting for I2S0_DI     */
	PB3_EPWM0_CH2    = (0x0b), /*!< GPB_MFP0 PB3 setting for EPWM0_CH2   */
	PB3_I2C1_SCL     = (0x0c), /*!< GPB_MFP0 PB3 setting for I2C1_SCL    */
	PB3_TM2          = (0x0e), /*!< GPB_MFP0 PB3 setting for TM2         */
	PB3_INT2         = (0x0f), /*!< GPB_MFP0 PB3 setting for INT2        */
	PB3_PSIO0_CH6    = (0x11), /*!< GPB_MFP0 PB3 setting for PSIO0_CH6   */
	PB3_KPI_ROW0     = (0x12), /*!< GPB_MFP0 PB3 setting for KPI_ROW0    */
	PB3_SPI4_SS      = (0x13), /*!< GPB_MFP0 PB3 setting for SPI4_SS (0xM460xGCAE only), */
	PB3_BMC2         = (0x14), /*!< GPB_MFP0 PB3 setting for BMC2    (0xM460xGCAE only), */

	/* PB.4 MFP */
	PB4_GPIO         = (0x00), /*!< GPB_MFP1 PB4 setting for GPIO        */
	PB4_EADC0_CH4    = (0x01), /*!< GPB_MFP1 PB4 setting for EADC0_CH4   */
	PB4_ACMP1_P1     = (0x01), /*!< GPB_MFP1 PB4 setting for ACMP1_P1    */
	PB4_EBI_ADR1     = (0x02), /*!< GPB_MFP1 PB4 setting for EBI_ADR1    */
	PB4_SD0_DAT2     = (0x03), /*!< GPB_MFP1 PB4 setting for SD0_DAT2    */
	PB4_EMAC0_RMII_RXD0 = (0x04), /*!< GPB_MFP1 PB4 setting for EMAC0_RMII_RXD0*/
	PB4_SPI1_MOSI    = (0x05), /*!< GPB_MFP1 PB4 setting for SPI1_MOSI   */
	PB4_I2C0_SDA     = (0x06), /*!< GPB_MFP1 PB4 setting for I2C0_SDA    */
	PB4_UART5_RXD    = (0x07), /*!< GPB_MFP1 PB4 setting for UART5_RXD   */
	PB4_SC0_DAT      = (0x09), /*!< GPB_MFP1 PB4 setting for SC0_DAT     */
	PB4_I2S0_MCLK    = (0x0a), /*!< GPB_MFP1 PB4 setting for I2S0_MCLK   */
	PB4_EPWM0_CH1    = (0x0b), /*!< GPB_MFP1 PB4 setting for EPWM0_CH1   */
	PB4_UART2_RXD    = (0x0c), /*!< GPB_MFP1 PB4 setting for UART2_RXD   */
	PB4_TM1          = (0x0e), /*!< GPB_MFP1 PB4 setting for TM1         */
	PB4_INT1         = (0x0f), /*!< GPB_MFP1 PB4 setting for INT1        */
	PB4_PSIO0_CH5    = (0x11), /*!< GPB_MFP1 PB4 setting for PSIO0_CH5   */
	PB4_KPI_COL7     = (0x12), /*!< GPB_MFP1 PB4 setting for KPI_COL7    */
	PB4_BMC1         = (0x14), /*!< GPB_MFP1 PB4 setting for BMC1 (0xM460xGCAE only), */

	/* PB.5 MFP */
	PB5_GPIO         = (0x00), /*!< GPB_MFP1 PB5 setting for GPIO        */
	PB5_EADC0_CH5    = (0x01), /*!< GPB_MFP1 PB5 setting for EADC0_CH5   */
	PB5_ACMP1_N      = (0x01), /*!< GPB_MFP1 PB5 setting for ACMP1_N     */
	PB5_EBI_ADR0     = (0x02), /*!< GPB_MFP1 PB5 setting for EBI_ADR0    */
	PB5_SD0_DAT3     = (0x03), /*!< GPB_MFP1 PB5 setting for SD0_DAT3    */
	PB5_EMAC0_RMII_REFCLK = (0x04), /*!< GPB_MFP1 PB5 setting for EMAC0_RMII_REFCLK*/
	PB5_SPI1_MISO    = (0x05), /*!< GPB_MFP1 PB5 setting for SPI1_MISO   */
	PB5_I2C0_SCL     = (0x06), /*!< GPB_MFP1 PB5 setting for I2C0_SCL    */
	PB5_UART5_TXD    = (0x07), /*!< GPB_MFP1 PB5 setting for UART5_TXD   */
	PB5_SC0_CLK      = (0x09), /*!< GPB_MFP1 PB5 setting for SC0_CLK     */
	PB5_I2S0_BCLK    = (0x0a), /*!< GPB_MFP1 PB5 setting for I2S0_BCLK   */
	PB5_EPWM0_CH0    = (0x0b), /*!< GPB_MFP1 PB5 setting for EPWM0_CH0   */
	PB5_UART2_TXD    = (0x0c), /*!< GPB_MFP1 PB5 setting for UART2_TXD   */
	PB5_TM0          = (0x0e), /*!< GPB_MFP1 PB5 setting for TM0         */
	PB5_INT0         = (0x0f), /*!< GPB_MFP1 PB5 setting for INT0        */
	PB5_PSIO0_CH4    = (0x11), /*!< GPB_MFP1 PB5 setting for PSIO0_CH4   */
	PB5_KPI_COL6     = (0x12), /*!< GPB_MFP1 PB5 setting for KPI_COL6    */
	PB5_BMC0         = (0x14), /*!< GPB_MFP1 PB5 setting for BMC0 (0xM460xGCAE only),*/

	/* PB.6 MFP */
	PB6_GPIO         = (0x00), /*!< GPB_MFP1 PB6 setting for GPIO        */
	PB6_EADC0_CH6    = (0x01), /*!< GPB_MFP1 PB6 setting for EADC0_CH6   */
	PB6_EADC2_CH14   = (0x01), /*!< GPB_MFP1 PB6 setting for EADC2_CH14  */
	PB6_ACMP2_N      = (0x01), /*!< GPB_MFP1 PB6 setting for ACMP2_N     */
	PB6_EBI_nWRH     = (0x02), /*!< GPB_MFP1 PB6 setting for EBI_nWRH    */
	PB6_EMAC0_PPS    = (0x03), /*!< GPB_MFP1 PB6 setting for EMAC0_PPS   */
	PB6_CAN1_RXD     = (0x05), /*!< GPB_MFP1 PB6 setting for CAN1_RXD    */
	PB6_UART1_RXD    = (0x06), /*!< GPB_MFP1 PB6 setting for UART1_RXD   */
	PB6_SD1_CLK      = (0x07), /*!< GPB_MFP1 PB6 setting for SD1_CLK     */
	PB6_EBI_nCS1     = (0x08), /*!< GPB_MFP1 PB6 setting for EBI_nCS1    */
	PB6_BPWM1_CH5    = (0x0a), /*!< GPB_MFP1 PB6 setting for BPWM1_CH5   */
	PB6_EPWM1_BRAKE1 = (0x0b), /*!< GPB_MFP1 PB6 setting for EPWM1_BRAKE1*/
	PB6_EPWM1_CH5    = (0x0c), /*!< GPB_MFP1 PB6 setting for EPWM1_CH5   */
	PB6_INT4         = (0x0d), /*!< GPB_MFP1 PB6 setting for INT4        */
	PB6_USB_VBUS_EN  = (0x0e), /*!< GPB_MFP1 PB6 setting for USB_VBUS_EN */
	PB6_ACMP1_O      = (0x0f), /*!< GPB_MFP1 PB6 setting for ACMP1_O     */
	PB6_SPI3_MOSI    = (0x10), /*!< GPB_MFP1 PB6 setting for SPI3_MOSI   */
	PB6_KPI_COL5     = (0x12), /*!< GPB_MFP1 PB6 setting for KPI_COL5    */
	PB6_SPI1_SS      = (0x13), /*!< GPB_MFP1 PB6 setting for SPI1_SS     */
	PB6_BMC31        = (0x14), /*!< GPB_MFP1 PB6 setting for BMC31 (0xM460xGCAE only), */

	/* PB.7 MFP */
	PB7_GPIO         = (0x00), /*!< GPB_MFP1 PB7 setting for GPIO        */
	PB7_EADC0_CH7    = (0x01), /*!< GPB_MFP1 PB7 setting for EADC0_CH7   */
	PB7_EADC2_CH15   = (0x01), /*!< GPB_MFP1 PB7 setting for EADC2_CH15  */
	PB7_ACMP2_P0     = (0x01), /*!< GPB_MFP1 PB7 setting for ACMP2_P0    */
	PB7_EBI_nWRL     = (0x02), /*!< GPB_MFP1 PB7 setting for EBI_nWRL    */
	PB7_EMAC0_RMII_TXEN = (0x03), /*!< GPB_MFP1 PB7 setting for EMAC0_RMII_TXEN*/
	PB7_CAN1_TXD     = (0x05), /*!< GPB_MFP1 PB7 setting for CAN1_TXD    */
	PB7_UART1_TXD    = (0x06), /*!< GPB_MFP1 PB7 setting for UART1_TXD   */
	PB7_SD1_CMD      = (0x07), /*!< GPB_MFP1 PB7 setting for SD1_CMD     */
	PB7_EBI_nCS0     = (0x08), /*!< GPB_MFP1 PB7 setting for EBI_nCS0    */
	PB7_BPWM1_CH4    = (0x0a), /*!< GPB_MFP1 PB7 setting for BPWM1_CH4   */
	PB7_EPWM1_BRAKE0 = (0x0b), /*!< GPB_MFP1 PB7 setting for EPWM1_BRAKE0*/
	PB7_EPWM1_CH4    = (0x0c), /*!< GPB_MFP1 PB7 setting for EPWM1_CH4   */
	PB7_INT5         = (0x0d), /*!< GPB_MFP1 PB7 setting for INT5        */
	PB7_USB_VBUS_ST  = (0x0e), /*!< GPB_MFP1 PB7 setting for USB_VBUS_ST */
	PB7_ACMP0_O      = (0x0f), /*!< GPB_MFP1 PB7 setting for ACMP0_O     */
	PB7_SPI3_MISO    = (0x10), /*!< GPB_MFP1 PB7 setting for SPI3_MISO   */
	PB7_KPI_COL4     = (0x12), /*!< GPB_MFP1 PB7 setting for KPI_COL4    */
	PB7_SPI1_CLK     = (0x13), /*!< GPB_MFP1 PB7 setting for SPI1_CLK    */
	PB7_BMC30        = (0x14), /*!< GPB_MFP1 PB7 setting for BMC30 (0xM460xGCAE only), */

	/* PB.8 MFP */
	PB8_GPIO         = (0x00), /*!< GPB_MFP2 PB8 setting for GPIO        */
	PB8_EADC0_CH8    = (0x01), /*!< GPB_MFP2 PB8 setting for EADC0_CH8   */
	PB8_ACMP2_P1     = (0x01), /*!< GPB_MFP2 PB8 setting for ACMP2_P1    */
	PB8_EBI_ADR19    = (0x02), /*!< GPB_MFP2 PB8 setting for EBI_ADR19   */
	PB8_EMAC0_RMII_TXD1 = (0x03), /*!< GPB_MFP2 PB8 setting for EMAC0_RMII_TXD1*/
	PB8_UART0_RXD    = (0x05), /*!< GPB_MFP2 PB8 setting for UART0_RXD   */
	PB8_UART1_nRTS   = (0x06), /*!< GPB_MFP2 PB8 setting for UART1_nRTS  */
	PB8_I2C1_SMBSUS  = (0x07), /*!< GPB_MFP2 PB8 setting for I2C1_SMBSUS */
	PB8_UART7_RXD    = (0x08), /*!< GPB_MFP2 PB8 setting for UART7_RXD   */
	PB8_I2C0_SDA     = (0x09), /*!< GPB_MFP2 PB8 setting for I2C0_SDA    */
	PB8_BPWM1_CH3    = (0x0a), /*!< GPB_MFP2 PB8 setting for BPWM1_CH3   */
	PB8_SPI3_MOSI    = (0x0b), /*!< GPB_MFP2 PB8 setting for SPI3_MOSI   */
	PB8_CAN2_RXD     = (0x0c), /*!< GPB_MFP2 PB8 setting for CAN2_RXD    */
	PB8_INT6         = (0x0d), /*!< GPB_MFP2 PB8 setting for INT6        */
	PB8_EADC2_ST     = (0x0e), /*!< GPB_MFP2 PB8 setting for EADC2_ST    */
	PB8_BMC23        = (0x14), /*!< GPB_MFP2 PB8 setting for BMC23 (0xM460xGCAE only), */

	/* PB.9 MFP */
	PB9_GPIO         = (0x00), /*!< GPB_MFP2 PB9 setting for GPIO        */
	PB9_EADC0_CH9    = (0x01), /*!< GPB_MFP2 PB9 setting for EADC0_CH9   */
	PB9_ACMP2_P2     = (0x01), /*!< GPB_MFP2 PB9 setting for ACMP2_P2    */
	PB9_EBI_ADR18    = (0x02), /*!< GPB_MFP2 PB9 setting for EBI_ADR18   */
	PB9_EMAC0_RMII_TXD0 = (0x03), /*!< GPB_MFP2 PB9 setting for EMAC0_RMII_TXD0*/
	PB9_UART0_TXD    = (0x05), /*!< GPB_MFP2 PB9 setting for UART0_TXD   */
	PB9_UART1_nCTS   = (0x06), /*!< GPB_MFP2 PB9 setting for UART1_nCTS  */
	PB9_I2C1_SMBAL   = (0x07), /*!< GPB_MFP2 PB9 setting for I2C1_SMBAL  */
	PB9_UART7_TXD    = (0x08), /*!< GPB_MFP2 PB9 setting for UART7_TXD   */
	PB9_I2C0_SCL     = (0x09), /*!< GPB_MFP2 PB9 setting for I2C0_SCL    */
	PB9_BPWM1_CH2    = (0x0a), /*!< GPB_MFP2 PB9 setting for BPWM1_CH2   */
	PB9_SPI3_MISO    = (0x0b), /*!< GPB_MFP2 PB9 setting for SPI3_MISO   */
	PB9_CAN2_TXD     = (0x0c), /*!< GPB_MFP2 PB9 setting for CAN2_TXD    */
	PB9_INT7         = (0x0d), /*!< GPB_MFP2 PB9 setting for INT7        */
	PB9_CCAP_HSYNC   = (0x0e), /*!< GPB_MFP2 PB9 setting for CCAP_HSYNC  */
	PB9_BMC22        = (0x14), /*!< GPB_MFP2 PB9 setting for BMC22 (0xM460xGCAE only), */

	/* PB.10 MFP */
	PB10_GPIO        = (0x00),/*!< GPB_MFP2 PB10 setting for GPIO       */
	PB10_EADC0_CH10  = (0x01),/*!< GPB_MFP2 PB10 setting for EADC0_CH10 */
	PB10_ACMP2_P3    = (0x01),/*!< GPB_MFP2 PB10 setting for ACMP2_P3   */
	PB10_EBI_ADR17   = (0x02),/*!< GPB_MFP2 PB10 setting for EBI_ADR17  */
	PB10_EMAC0_RMII_MDIO = (0x03),/*!< GPB_MFP2 PB10 setting for EMAC0_RMII_MDIO*/
	PB10_UART0_nRTS  = (0x05),/*!< GPB_MFP2 PB10 setting for UART0_nRTS */
	PB10_UART4_RXD   = (0x06),/*!< GPB_MFP2 PB10 setting for UART4_RXD  */
	PB10_I2C1_SDA    = (0x07),/*!< GPB_MFP2 PB10 setting for I2C1_SDA   */
	PB10_CAN0_RXD    = (0x08),/*!< GPB_MFP2 PB10 setting for CAN0_RXD   */
	PB10_BPWM1_CH1   = (0x0a),/*!< GPB_MFP2 PB10 setting for BPWM1_CH1  */
	PB10_SPI3_SS     = (0x0b),/*!< GPB_MFP2 PB10 setting for SPI3_SS    */
	PB10_CCAP_VSYNC  = (0x0c),/*!< GPB_MFP2 PB10 setting for CCAP_VSYNC */
	PB10_HSUSB_VBUS_EN = (0x0e),/*!< GPB_MFP2 PB10 setting for HSUSB_VBUS_EN*/
	PB10_BMC21       = (0x14),/*!< GPB_MFP2 PB10 setting for BMC21 (0xM460xGCAE only), */

	/* PB.11 MFP */
	PB11_GPIO        = (0x00),/*!< GPB_MFP2 PB11 setting for GPIO       */
	PB11_EADC0_CH11  = (0x01),/*!< GPB_MFP2 PB11 setting for EADC0_CH11 */
	PB11_EBI_ADR16   = (0x02),/*!< GPB_MFP2 PB11 setting for EBI_ADR16  */
	PB11_EMAC0_RMII_MDC = (0x03),/*!< GPB_MFP2 PB11 setting for EMAC0_RMII_MDC*/
	PB11_UART0_nCTS  = (0x05),/*!< GPB_MFP2 PB11 setting for UART0_nCTS */
	PB11_UART4_TXD   = (0x06),/*!< GPB_MFP2 PB11 setting for UART4_TXD  */
	PB11_I2C1_SCL    = (0x07),/*!< GPB_MFP2 PB11 setting for I2C1_SCL   */
	PB11_CAN0_TXD    = (0x08),/*!< GPB_MFP2 PB11 setting for CAN0_TXD   */
	PB11_SPI0_I2SMCLK = (0x09),/*!< GPB_MFP2 PB11 setting for SPI0_I2SMCLK*/
	PB11_BPWM1_CH0   = (0x0a),/*!< GPB_MFP2 PB11 setting for BPWM1_CH0  */
	PB11_SPI3_CLK    = (0x0b),/*!< GPB_MFP2 PB11 setting for SPI3_CLK   */
	PB11_CCAP_SFIELD = (0x0c),/*!< GPB_MFP2 PB11 setting for CCAP_SFIELD*/
	PB11_HSUSB_VBUS_ST = (0x0e),/*!< GPB_MFP2 PB11 setting for HSUSB_VBUS_ST*/
	PB11_BMC20       = (0x14),/*!< GPB_MFP2 PB11 setting for BMC20 (0xM460xGCAE only), */

	/* PB.12 MFP */
	PB12_GPIO        = (0x00),/*!< GPB_MFP3 PB12 setting for GPIO       */
	PB12_EADC0_CH12  = (0x01),/*!< GPB_MFP3 PB12 setting for EADC0_CH12 */
	PB12_EADC1_CH12  = (0x01),/*!< GPB_MFP3 PB12 setting for EADC1_CH12 */
	PB12_DAC0_OUT    = (0x01),/*!< GPB_MFP3 PB12 setting for DAC0_OUT   */
	PB12_ACMP0_P2    = (0x01),/*!< GPB_MFP3 PB12 setting for ACMP0_P2   */
	PB12_ACMP1_P2    = (0x01),/*!< GPB_MFP3 PB12 setting for ACMP1_P2   */
	PB12_EBI_AD15    = (0x02),/*!< GPB_MFP3 PB12 setting for EBI_AD15   */
	PB12_SC1_CLK     = (0x03),/*!< GPB_MFP3 PB12 setting for SC1_CLK    */
	PB12_SPI0_MOSI   = (0x04),/*!< GPB_MFP3 PB12 setting for SPI0_MOSI  */
	PB12_USCI0_CLK   = (0x05),/*!< GPB_MFP3 PB12 setting for USCI0_CLK  */
	PB12_UART0_RXD   = (0x06),/*!< GPB_MFP3 PB12 setting for UART0_RXD  */
	PB12_UART3_nCTS  = (0x07),/*!< GPB_MFP3 PB12 setting for UART3_nCTS */
	PB12_I2C2_SDA    = (0x08),/*!< GPB_MFP3 PB12 setting for I2C2_SDA   */
	PB12_SD0_nCD     = (0x09),/*!< GPB_MFP3 PB12 setting for SD0_nCD    */
	PB12_CCAP_SCLK   = (0x0a),/*!< GPB_MFP3 PB12 setting for CCAP_SCLK  */
	PB12_EPWM1_CH3   = (0x0b),/*!< GPB_MFP3 PB12 setting for EPWM1_CH3  */
	PB12_ETMC_TRACE_DATA3 = (0x0c),/*!< GPB_MFP3 PB12 setting for ETMC_TRACE_DATA3*/
	PB12_TM3_EXT     = (0x0d),/*!< GPB_MFP3 PB12 setting for TM3_EXT    */
	PB12_CAN3_RXD    = (0x0e),/*!< GPB_MFP3 PB12 setting for CAN3_RXD   */
	PB12_SPI3_SS     = (0x10),/*!< GPB_MFP3 PB12 setting for SPI3_SS    */
	PB12_PSIO0_CH3   = (0x11),/*!< GPB_MFP3 PB12 setting for PSIO0_CH3  */
	PB12_KPI_COL3    = (0x12),/*!< GPB_MFP3 PB12 setting for KPI_COL3   */
	PB12_BMC29       = (0x14),/*!< GPB_MFP3 PB12 setting for BMC29 (0xM460xGCAE only), */

	/* PB.13 MFP */
	PB13_GPIO        = (0x00),/*!< GPB_MFP3 PB13 setting for GPIO       */
	PB13_EADC0_CH13  = (0x01),/*!< GPB_MFP3 PB13 setting for EADC0_CH13 */
	PB13_EADC1_CH13  = (0x01),/*!< GPB_MFP3 PB13 setting for EADC1_CH13 */
	PB13_DAC1_OUT    = (0x01),/*!< GPB_MFP3 PB13 setting for DAC1_OUT   */
	PB13_ACMP0_P3    = (0x01),/*!< GPB_MFP3 PB13 setting for ACMP0_P3   */
	PB13_ACMP1_P3    = (0x01),/*!< GPB_MFP3 PB13 setting for ACMP1_P3   */
	PB13_EBI_AD14    = (0x02),/*!< GPB_MFP3 PB13 setting for EBI_AD14   */
	PB13_SC1_DAT     = (0x03),/*!< GPB_MFP3 PB13 setting for SC1_DAT    */
	PB13_SPI0_MISO   = (0x04),/*!< GPB_MFP3 PB13 setting for SPI0_MISO  */
	PB13_USCI0_DAT0  = (0x05),/*!< GPB_MFP3 PB13 setting for USCI0_DAT0 */
	PB13_UART0_TXD   = (0x06),/*!< GPB_MFP3 PB13 setting for UART0_TXD  */
	PB13_UART3_nRTS  = (0x07),/*!< GPB_MFP3 PB13 setting for UART3_nRTS */
	PB13_I2C2_SCL    = (0x08),/*!< GPB_MFP3 PB13 setting for I2C2_SCL   */
	PB13_CCAP_PIXCLK = (0x0a),/*!< GPB_MFP3 PB13 setting for CCAP_PIXCLK*/
	PB13_EPWM1_CH2   = (0x0b),/*!< GPB_MFP3 PB13 setting for EPWM1_CH2  */
	PB13_ETMC_TRACE_DATA2 = (0x0c),/*!< GPB_MFP3 PB13 setting for ETMC_TRACE_DATA2*/
	PB13_TM2_EXT     = (0x0d),/*!< GPB_MFP3 PB13 setting for TM2_EXT    */
	PB13_CAN3_TXD    = (0x0e),/*!< GPB_MFP3 PB13 setting for CAN3_TXD   */
	PB13_SPI3_CLK    = (0x10),/*!< GPB_MFP3 PB13 setting for SPI3_CLK   */
	PB13_PSIO0_CH2   = (0x11),/*!< GPB_MFP3 PB13 setting for PSIO0_CH2  */
	PB13_KPI_COL2    = (0x12),/*!< GPB_MFP3 PB13 setting for KPI_COL2   */
	PB13_SPI9_MISO   = (0x13),/*!< GPB_MFP3 PB13 setting for SPI9_MISO (0xM460xGCAE only), */
	PB13_BMC28       = (0x14),/*!< GPB_MFP3 PB13 setting for BMC28 (0xM460xGCAE only), */

	/* PB.14 MFP */
	PB14_GPIO        = (0x00),/*!< GPB_MFP3 PB14 setting for GPIO       */
	PB14_EADC0_CH14  = (0x01),/*!< GPB_MFP3 PB14 setting for EADC0_CH14 */
	PB14_EADC1_CH14  = (0x01),/*!< GPB_MFP3 PB14 setting for EADC1_CH14 */
	PB14_EBI_AD13    = (0x02),/*!< GPB_MFP3 PB14 setting for EBI_AD13   */
	PB14_SC1_RST     = (0x03),/*!< GPB_MFP3 PB14 setting for SC1_RST    */
	PB14_SPI0_CLK    = (0x04),/*!< GPB_MFP3 PB14 setting for SPI0_CLK   */
	PB14_USCI0_DAT1  = (0x05),/*!< GPB_MFP3 PB14 setting for USCI0_DAT1 */
	PB14_UART0_nRTS  = (0x06),/*!< GPB_MFP3 PB14 setting for UART0_nRTS */
	PB14_UART3_RXD   = (0x07),/*!< GPB_MFP3 PB14 setting for UART3_RXD  */
	PB14_I2C2_SMBSUS = (0x08),/*!< GPB_MFP3 PB14 setting for I2C2_SMBSUS*/
	PB14_CCAP_DATA0  = (0x09),/*!< GPB_MFP3 PB14 setting for CCAP_DATA0 */
	PB14_EPWM1_CH1   = (0x0b),/*!< GPB_MFP3 PB14 setting for EPWM1_CH1  */
	PB14_ETMC_TRACE_DATA1 = (0x0c),/*!< GPB_MFP3 PB14 setting for ETMC_TRACE_DATA1*/
	PB14_TM1_EXT     = (0x0d),/*!< GPB_MFP3 PB14 setting for TM1_EXT    */
	PB14_CLKO        = (0x0e),/*!< GPB_MFP3 PB14 setting for CLKO       */
	PB14_USB_VBUS_ST = (0x0f),/*!< GPB_MFP3 PB14 setting for USB_VBUS_ST*/
	PB14_PSIO0_CH1   = (0x11),/*!< GPB_MFP3 PB14 setting for PSIO0_CH1  */
	PB14_KPI_COL1    = (0x12),/*!< GPB_MFP3 PB14 setting for KPI_COL1   */
	PB14_SPI9_SS     = (0x13),/*!< GPB_MFP3 PB14 setting for SPI9_SS (0xM460xGCAE only), */

	/* PB.15 MFP */
	PB15_GPIO        = (0x00),/*!< GPB_MFP3 PB15 setting for GPIO       */
	PB15_EADC0_CH15  = (0x01),/*!< GPB_MFP3 PB15 setting for EADC0_CH15 */
	PB15_EADC1_CH15  = (0x01),/*!< GPB_MFP3 PB15 setting for EADC1_CH15 */
	PB15_EBI_AD12    = (0x02),/*!< GPB_MFP3 PB15 setting for EBI_AD12   */
	PB15_SC1_PWR     = (0x03),/*!< GPB_MFP3 PB15 setting for SC1_PWR    */
	PB15_SPI0_SS     = (0x04),/*!< GPB_MFP3 PB15 setting for SPI0_SS    */
	PB15_USCI0_CTL1  = (0x05),/*!< GPB_MFP3 PB15 setting for USCI0_CTL1 */
	PB15_UART0_nCTS  = (0x06),/*!< GPB_MFP3 PB15 setting for UART0_nCTS */
	PB15_UART3_TXD   = (0x07),/*!< GPB_MFP3 PB15 setting for UART3_TXD  */
	PB15_I2C2_SMBAL  = (0x08),/*!< GPB_MFP3 PB15 setting for I2C2_SMBAL */
	PB15_CCAP_DATA1  = (0x09),/*!< GPB_MFP3 PB15 setting for CCAP_DATA1 */
	PB15_EPWM0_BRAKE1 = (0x0a),/*!< GPB_MFP3 PB15 setting for EPWM0_BRAKE1*/
	PB15_EPWM1_CH0   = (0x0b),/*!< GPB_MFP3 PB15 setting for EPWM1_CH0  */
	PB15_ETMC_TRACE_DATA0 = (0x0c),/*!< GPB_MFP3 PB15 setting for ETMC_TRACE_DATA0*/
	PB15_TM0_EXT     = (0x0d),/*!< GPB_MFP3 PB15 setting for TM0_EXT    */
	PB15_USB_VBUS_EN = (0x0e),/*!< GPB_MFP3 PB15 setting for USB_VBUS_EN*/
	PB15_HSUSB_VBUS_EN = (0x0f),/*!< GPB_MFP3 PB15 setting for HSUSB_VBUS_EN*/
	PB15_PSIO0_CH0   = (0x11),/*!< GPB_MFP3 PB15 setting for PSIO0_CH0  */
	PB15_KPI_COL0    = (0x12),/*!< GPB_MFP3 PB15 setting for KPI_COL0   */
	PB15_SPI9_CLK    = (0x13),/*!< GPB_MFP3 PB15 setting for SPI9_CLK (0xM460xGCAE only), */
	PB15_BMC27       = (0x14),/*!< GPB_MFP3 PB15 setting for BMC27    (0xM460xGCAE only), */

	/* PC.0 MFP */
	PC0_GPIO         = (0x00), /*!< GPC_MFP0 PC0 setting for GPIO        */
	PC0_EBI_AD0      = (0x02), /*!< GPC_MFP0 PC0 setting for EBI_AD0     */
	PC0_SPIM_MOSI    = (0x03), /*!< GPC_MFP0 PC0 setting for SPIM_MOSI   */
	PC0_QSPI0_MOSI0  = (0x04), /*!< GPC_MFP0 PC0 setting for QSPI0_MOSI0 */
	PC0_SC1_CLK      = (0x05), /*!< GPC_MFP0 PC0 setting for SC1_CLK     */
	PC0_I2S0_LRCK    = (0x06), /*!< GPC_MFP0 PC0 setting for I2S0_LRCK   */
	PC0_SPI1_SS      = (0x07), /*!< GPC_MFP0 PC0 setting for SPI1_SS     */
	PC0_UART2_RXD    = (0x08), /*!< GPC_MFP0 PC0 setting for UART2_RXD   */
	PC0_I2C0_SDA     = (0x09), /*!< GPC_MFP0 PC0 setting for I2C0_SDA    */
	PC0_CAN2_RXD     = (0x0a), /*!< GPC_MFP0 PC0 setting for CAN2_RXD    */
	PC0_EPWM1_CH5    = (0x0c), /*!< GPC_MFP0 PC0 setting for EPWM1_CH5   */
	PC0_CCAP_DATA0   = (0x0d), /*!< GPC_MFP0 PC0 setting for CCAP_DATA0  */
	PC0_ACMP1_O      = (0x0e), /*!< GPC_MFP0 PC0 setting for ACMP1_O     */
	PC0_EADC1_ST     = (0x0f), /*!< GPC_MFP0 PC0 setting for EADC1_ST    */
	PC0_HBI_D2       = (0x10), /*!< GPC_MFP0 PC0 setting for HBI_D2      */
	PC0_QSPI1_CLK    = (0x11), /*!< GPC_MFP0 PC0 setting for QSPI1_CLK   */
	PC0_KPI_ROW5     = (0x12), /*!< GPC_MFP0 PC0 setting for KPI_ROW5    */
	PC0_SPI7_MOSI    = (0x13), /*!< GPC_MFP0 PC0 setting for SPI7_MOSI (0xM460xGCAE only), */
	PC0_BMC25        = (0x14), /*!< GPC_MFP0 PC0 setting for BMC25     (0xM460xGCAE only),  */

	/* PC.1 MFP */
	PC1_GPIO         = (0x00), /*!< GPC_MFP0 PC1 setting for GPIO        */
	PC1_EBI_AD1      = (0x02), /*!< GPC_MFP0 PC1 setting for EBI_AD1     */
	PC1_SPIM_MISO    = (0x03), /*!< GPC_MFP0 PC1 setting for SPIM_MISO   */
	PC1_QSPI0_MISO0  = (0x04), /*!< GPC_MFP0 PC1 setting for QSPI0_MISO0 */
	PC1_SC1_DAT      = (0x05), /*!< GPC_MFP0 PC1 setting for SC1_DAT     */
	PC1_I2S0_DO      = (0x06), /*!< GPC_MFP0 PC1 setting for I2S0_DO     */
	PC1_SPI1_CLK     = (0x07), /*!< GPC_MFP0 PC1 setting for SPI1_CLK    */
	PC1_UART2_TXD    = (0x08), /*!< GPC_MFP0 PC1 setting for UART2_TXD   */
	PC1_I2C0_SCL     = (0x09), /*!< GPC_MFP0 PC1 setting for I2C0_SCL    */
	PC1_CAN2_TXD     = (0x0a), /*!< GPC_MFP0 PC1 setting for CAN2_TXD    */
	PC1_EPWM1_CH4    = (0x0c), /*!< GPC_MFP0 PC1 setting for EPWM1_CH4   */
	PC1_CCAP_DATA1   = (0x0d), /*!< GPC_MFP0 PC1 setting for CCAP_DATA1  */
	PC1_ACMP0_O      = (0x0e), /*!< GPC_MFP0 PC1 setting for ACMP0_O     */
	PC1_EADC0_ST     = (0x0f), /*!< GPC_MFP0 PC1 setting for EADC0_ST    */
	PC1_HBI_RWDS     = (0x10), /*!< GPC_MFP0 PC1 setting for HBI_RWDS    */
	PC1_QSPI1_SS     = (0x11), /*!< GPC_MFP0 PC1 setting for QSPI1_SS    */
	PC1_KPI_ROW4     = (0x12), /*!< GPC_MFP0 PC1 setting for KPI_ROW4    */
	PC1_SPI7_MISO    = (0x13), /*!< GPC_MFP0 PC1 setting for SPI7_MISO (0xM460xGCAE only), */
	PC1_BMC24        = (0x14), /*!< GPC_MFP0 PC1 setting for BMC24     (0xM460xGCAE only), */

	/* PC.2 MFP */
	PC2_GPIO         = (0x00), /*!< GPC_MFP0 PC2 setting for GPIO        */
	PC2_EBI_AD2      = (0x02), /*!< GPC_MFP0 PC2 setting for EBI_AD2     */
	PC2_SPIM_CLK     = (0x03), /*!< GPC_MFP0 PC2 setting for SPIM_CLK    */
	PC2_QSPI0_CLK    = (0x04), /*!< GPC_MFP0 PC2 setting for QSPI0_CLK   */
	PC2_SC1_RST      = (0x05), /*!< GPC_MFP0 PC2 setting for SC1_RST     */
	PC2_I2S0_DI      = (0x06), /*!< GPC_MFP0 PC2 setting for I2S0_DI     */
	PC2_SPI1_MOSI    = (0x07), /*!< GPC_MFP0 PC2 setting for SPI1_MOSI   */
	PC2_UART2_nCTS   = (0x08), /*!< GPC_MFP0 PC2 setting for UART2_nCTS  */
	PC2_I2C0_SMBSUS  = (0x09), /*!< GPC_MFP0 PC2 setting for I2C0_SMBSUS */
	PC2_CAN1_RXD     = (0x0a), /*!< GPC_MFP0 PC2 setting for CAN1_RXD    */
	PC2_UART3_RXD    = (0x0b), /*!< GPC_MFP0 PC2 setting for UART3_RXD   */
	PC2_EPWM1_CH3    = (0x0c), /*!< GPC_MFP0 PC2 setting for EPWM1_CH3   */
	PC2_CCAP_DATA2   = (0x0d), /*!< GPC_MFP0 PC2 setting for CCAP_DATA2  */
	PC2_QSPI1_MOSI0  = (0x0e), /*!< GPC_MFP0 PC2 setting for QSPI1_MOSI0 */
	PC2_I2C3_SDA     = (0x0f), /*!< GPC_MFP0 PC2 setting for I2C3_SDA    */
	PC2_HBI_nRESET   = (0x10), /*!< GPC_MFP0 PC2 setting for HBI_nRESET  */
	PC2_PSIO0_CH3    = (0x11), /*!< GPC_MFP0 PC2 setting for PSIO0_CH3   */
	PC2_KPI_ROW3     = (0x12), /*!< GPC_MFP0 PC2 setting for KPI_ROW3    */
	PC2_SPI7_CLK     = (0x13), /*!< GPC_MFP0 PC2 setting for SPI7_CLK (0xM460xGCAE only), */
	PC2_BMC23        = (0x14), /*!< GPC_MFP0 PC2 setting for BMC23    (0xM460xGCAE only), */

	/* PC.3 MFP */
	PC3_GPIO         = (0x00), /*!< GPC_MFP0 PC3 setting for GPIO        */
	PC3_EBI_AD3      = (0x02), /*!< GPC_MFP0 PC3 setting for EBI_AD3     */
	PC3_SPIM_SS      = (0x03), /*!< GPC_MFP0 PC3 setting for SPIM_SS     */
	PC3_QSPI0_SS     = (0x04), /*!< GPC_MFP0 PC3 setting for QSPI0_SS    */
	PC3_SC1_PWR      = (0x05), /*!< GPC_MFP0 PC3 setting for SC1_PWR     */
	PC3_I2S0_MCLK    = (0x06), /*!< GPC_MFP0 PC3 setting for I2S0_MCLK   */
	PC3_SPI1_MISO    = (0x07), /*!< GPC_MFP0 PC3 setting for SPI1_MISO   */
	PC3_UART2_nRTS   = (0x08), /*!< GPC_MFP0 PC3 setting for UART2_nRTS  */
	PC3_I2C0_SMBAL   = (0x09), /*!< GPC_MFP0 PC3 setting for I2C0_SMBAL  */
	PC3_CAN1_TXD     = (0x0a), /*!< GPC_MFP0 PC3 setting for CAN1_TXD    */
	PC3_UART3_TXD    = (0x0b), /*!< GPC_MFP0 PC3 setting for UART3_TXD   */
	PC3_EPWM1_CH2    = (0x0c), /*!< GPC_MFP0 PC3 setting for EPWM1_CH2   */
	PC3_CCAP_DATA3   = (0x0d), /*!< GPC_MFP0 PC3 setting for CCAP_DATA3  */
	PC3_QSPI1_MISO0  = (0x0e), /*!< GPC_MFP0 PC3 setting for QSPI1_MISO0 */
	PC3_I2C3_SCL     = (0x0f), /*!< GPC_MFP0 PC3 setting for I2C3_SCL    */
	PC3_HBI_nCS      = (0x10), /*!< GPC_MFP0 PC3 setting for HBI_nCS     */
	PC3_PSIO0_CH2    = (0x11), /*!< GPC_MFP0 PC3 setting for PSIO0_CH2   */
	PC3_KPI_ROW2     = (0x12), /*!< GPC_MFP0 PC3 setting for KPI_ROW2    */
	PC3_SPI7_SS      = (0x13), /*!< GPC_MFP0 PC3 setting for SPI7_SS (0xM460xGCAE only), */
	PC3_BMC22        = (0x14), /*!< GPC_MFP0 PC3 setting for BMC22   (0xM460xGCAE only), */

	/* PC.4 MFP */
	PC4_GPIO         = (0x00), /*!< GPC_MFP1 PC4 setting for GPIO        */
	PC4_EBI_AD4      = (0x02), /*!< GPC_MFP1 PC4 setting for EBI_AD4     */
	PC4_SPIM_D3      = (0x03), /*!< GPC_MFP1 PC4 setting for SPIM_D3     */
	PC4_QSPI0_MOSI1  = (0x04), /*!< GPC_MFP1 PC4 setting for QSPI0_MOSI1 */
	PC4_SC1_nCD      = (0x05), /*!< GPC_MFP1 PC4 setting for SC1_nCD     */
	PC4_I2S0_BCLK    = (0x06), /*!< GPC_MFP1 PC4 setting for I2S0_BCLK   */
	PC4_SPI1_I2SMCLK = (0x07), /*!< GPC_MFP1 PC4 setting for SPI1_I2SMCLK*/
	PC4_UART2_RXD    = (0x08), /*!< GPC_MFP1 PC4 setting for UART2_RXD   */
	PC4_I2C1_SDA     = (0x09), /*!< GPC_MFP1 PC4 setting for I2C1_SDA    */
	PC4_CAN0_RXD     = (0x0a), /*!< GPC_MFP1 PC4 setting for CAN0_RXD    */
	PC4_UART4_RXD    = (0x0b), /*!< GPC_MFP1 PC4 setting for UART4_RXD   */
	PC4_EPWM1_CH1    = (0x0c), /*!< GPC_MFP1 PC4 setting for EPWM1_CH1   */
	PC4_CCAP_DATA4   = (0x0d), /*!< GPC_MFP1 PC4 setting for CCAP_DATA4  */
	PC4_QSPI1_CLK    = (0x0e), /*!< GPC_MFP1 PC4 setting for QSPI1_CLK   */
	PC4_I2C3_SMBSUS  = (0x0f), /*!< GPC_MFP1 PC4 setting for I2C3_SMBSUS */
	PC4_HBI_CK       = (0x10), /*!< GPC_MFP1 PC4 setting for HBI_CK      */
	PC4_PSIO0_CH1    = (0x11), /*!< GPC_MFP1 PC4 setting for PSIO0_CH1   */
	PC4_KPI_ROW1     = (0x12), /*!< GPC_MFP1 PC4 setting for KPI_ROW1    */
	PC4_BMC21        = (0x14), /*!< GPC_MFP1 PC4 setting for BMC21 (0xM460xGCAE only), */

	/* PC.5 MFP */
	PC5_GPIO         = (0x00), /*!< GPC_MFP1 PC5 setting for GPIO        */
	PC5_EBI_AD5      = (0x02), /*!< GPC_MFP1 PC5 setting for EBI_AD5     */
	PC5_SPIM_D2      = (0x03), /*!< GPC_MFP1 PC5 setting for SPIM_D2     */
	PC5_QSPI0_MISO1  = (0x04), /*!< GPC_MFP1 PC5 setting for QSPI0_MISO1 */
	PC5_UART2_TXD    = (0x08), /*!< GPC_MFP1 PC5 setting for UART2_TXD   */
	PC5_I2C1_SCL     = (0x09), /*!< GPC_MFP1 PC5 setting for I2C1_SCL    */
	PC5_CAN0_TXD     = (0x0a), /*!< GPC_MFP1 PC5 setting for CAN0_TXD    */
	PC5_UART4_TXD    = (0x0b), /*!< GPC_MFP1 PC5 setting for UART4_TXD   */
	PC5_EPWM1_CH0    = (0x0c), /*!< GPC_MFP1 PC5 setting for EPWM1_CH0   */
	PC5_CCAP_DATA5   = (0x0d), /*!< GPC_MFP1 PC5 setting for CCAP_DATA5  */
	PC5_QSPI1_SS     = (0x0e), /*!< GPC_MFP1 PC5 setting for QSPI1_SS    */
	PC5_I2C3_SMBAL   = (0x0f), /*!< GPC_MFP1 PC5 setting for I2C3_SMBAL  */
	PC5_HBI_nCK      = (0x10), /*!< GPC_MFP1 PC5 setting for HBI_nCK     */
	PC5_PSIO0_CH0    = (0x11), /*!< GPC_MFP1 PC5 setting for PSIO0_CH0   */
	PC5_KPI_ROW0     = (0x12), /*!< GPC_MFP1 PC5 setting for KPI_ROW0    */
	PC5_BMC20        = (0x14), /*!< GPC_MFP1 PC5 setting for BMC20 (0xM460xGCAE only), */

	/* PC.6 MFP */
	PC6_GPIO         = (0x00), /*!< GPC_MFP1 PC6 setting for GPIO        */
	PC6_EBI_AD8      = (0x02), /*!< GPC_MFP1 PC6 setting for EBI_AD8     */
	PC6_EMAC0_RMII_RXD1 = (0x03), /*!< GPC_MFP1 PC6 setting for EMAC0_RMII_RXD1*/
	PC6_SPI1_MOSI    = (0x04), /*!< GPC_MFP1 PC6 setting for SPI1_MOSI   */
	PC6_UART4_RXD    = (0x05), /*!< GPC_MFP1 PC6 setting for UART4_RXD   */
	PC6_SC2_RST      = (0x06), /*!< GPC_MFP1 PC6 setting for SC2_RST     */
	PC6_UART0_nRTS   = (0x07), /*!< GPC_MFP1 PC6 setting for UART0_nRTS  */
	PC6_I2C1_SMBSUS  = (0x08), /*!< GPC_MFP1 PC6 setting for I2C1_SMBSUS */
	PC6_UART6_RXD    = (0x09), /*!< GPC_MFP1 PC6 setting for UART6_RXD   */
	PC6_ACMP3_WLAT   = (0x0a), /*!< GPC_MFP1 PC6 setting for ACMP3_WLAT  */
	PC6_EPWM1_CH3    = (0x0b), /*!< GPC_MFP1 PC6 setting for EPWM1_CH3   */
	PC6_BPWM1_CH1    = (0x0c), /*!< GPC_MFP1 PC6 setting for BPWM1_CH1   */
	PC6_CAN3_RXD     = (0x0d), /*!< GPC_MFP1 PC6 setting for CAN3_RXD    */
	PC6_TM1          = (0x0e), /*!< GPC_MFP1 PC6 setting for TM1         */
	PC6_INT2         = (0x0f), /*!< GPC_MFP1 PC6 setting for INT2        */
	PC6_KPI_COL2     = (0x12), /*!< GPC_MFP1 PC6 setting for KPI_COL2    */
	PC6_SPI6_MOSI    = (0x13), /*!< GPC_MFP1 PC6 setting for SPI6_MOSI (0xM460xGCAE only), */
	PC6_BMC25        = (0x14), /*!< GPC_MFP1 PC6 setting for BMC25     (0xM460xGCAE only), */

	/* PC.7 MFP */
	PC7_GPIO         = (0x00), /*!< GPC_MFP1 PC7 setting for GPIO        */
	PC7_EBI_AD9      = (0x02), /*!< GPC_MFP1 PC7 setting for EBI_AD9     */
	PC7_EMAC0_RMII_RXD0 = (0x03), /*!< GPC_MFP1 PC7 setting for EMAC0_RMII_RXD0*/
	PC7_SPI1_MISO    = (0x04), /*!< GPC_MFP1 PC7 setting for SPI1_MISO   */
	PC7_UART4_TXD    = (0x05), /*!< GPC_MFP1 PC7 setting for UART4_TXD   */
	PC7_SC2_PWR      = (0x06), /*!< GPC_MFP1 PC7 setting for SC2_PWR     */
	PC7_UART0_nCTS   = (0x07), /*!< GPC_MFP1 PC7 setting for UART0_nCTS  */
	PC7_I2C1_SMBAL   = (0x08), /*!< GPC_MFP1 PC7 setting for I2C1_SMBAL  */
	PC7_UART6_TXD    = (0x09), /*!< GPC_MFP1 PC7 setting for UART6_TXD   */
	PC7_ACMP2_WLAT   = (0x0a), /*!< GPC_MFP1 PC7 setting for ACMP2_WLAT  */
	PC7_EPWM1_CH2    = (0x0b), /*!< GPC_MFP1 PC7 setting for EPWM1_CH2   */
	PC7_BPWM1_CH0    = (0x0c), /*!< GPC_MFP1 PC7 setting for BPWM1_CH0   */
	PC7_CAN3_TXD     = (0x0d), /*!< GPC_MFP1 PC7 setting for CAN3_TXD    */
	PC7_TM0          = (0x0e), /*!< GPC_MFP1 PC7 setting for TM0         */
	PC7_INT3         = (0x0f), /*!< GPC_MFP1 PC7 setting for INT3        */
	PC7_KPI_COL3     = (0x12), /*!< GPC_MFP1 PC7 setting for KPI_COL3    */
	PC7_SPI6_MISO    = (0x13), /*!< GPC_MFP1 PC7 setting for SPI6_MISO (0xM460xGCAE only), */
	PC7_BMC24        = (0x14), /*!< GPC_MFP1 PC7 setting for BMC24     (0xM460xGCAE only), */

	/* PC.8 MFP */
	PC8_GPIO         = (0x00), /*!< GPC_MFP2 PC8 setting for GPIO        */
	PC8_EBI_ADR16    = (0x02), /*!< GPC_MFP2 PC8 setting for EBI_ADR16   */
	PC8_EMAC0_RMII_REFCLK = (0x03), /*!< GPC_MFP2 PC8 setting for EMAC0_RMII_REFCLK*/
	PC8_I2C0_SDA     = (0x04), /*!< GPC_MFP2 PC8 setting for I2C0_SDA    */
	PC8_UART4_nCTS   = (0x05), /*!< GPC_MFP2 PC8 setting for UART4_nCTS  */
	PC8_UART1_RXD    = (0x08), /*!< GPC_MFP2 PC8 setting for UART1_RXD   */
	PC8_EPWM1_CH1    = (0x0b), /*!< GPC_MFP2 PC8 setting for EPWM1_CH1   */
	PC8_BPWM1_CH4    = (0x0c), /*!< GPC_MFP2 PC8 setting for BPWM1_CH4   */
	PC8_KPI_COL4     = (0x12), /*!< GPC_MFP2 PC8 setting for KPI_COL4    */

	/* PC.9 MFP */
	PC9_GPIO         = (0x00), /*!< GPC_MFP2 PC9 setting for GPIO        */
	PC9_EADC2_CH10   = (0x01), /*!< GPC_MFP2 PC9 setting for EADC2_CH10  */
	PC9_ACMP3_P1     = (0x01), /*!< GPC_MFP2 PC9 setting for ACMP3_P1    */
	PC9_EBI_ADR7     = (0x02), /*!< GPC_MFP2 PC9 setting for EBI_ADR7    */
	PC9_UART6_nCTS   = (0x05), /*!< GPC_MFP2 PC9 setting for UART6_nCTS  */
	PC9_SPI3_SS      = (0x06), /*!< GPC_MFP2 PC9 setting for SPI3_SS     */
	PC9_UART3_RXD    = (0x07), /*!< GPC_MFP2 PC9 setting for UART3_RXD   */
	PC9_CAN1_RXD     = (0x09), /*!< GPC_MFP2 PC9 setting for CAN1_RXD    */
	PC9_I2C4_SMBSUS  = (0x0a), /*!< GPC_MFP2 PC9 setting for I2C4_SMBSUS */
	PC9_EPWM1_CH3    = (0x0c), /*!< GPC_MFP2 PC9 setting for EPWM1_CH3   */
	PC9_EADC1_ST     = (0x0e), /*!< GPC_MFP2 PC9 setting for EADC1_ST    */

	/* PC.10 MFP */
	PC10_GPIO        = (0x00),/*!< GPC_MFP2 PC10 setting for GPIO       */
	PC10_EADC2_CH11  = (0x01),/*!< GPC_MFP2 PC10 setting for EADC2_CH11 */
	PC10_ACMP3_P2    = (0x01),/*!< GPC_MFP2 PC10 setting for ACMP3_P2   */
	PC10_EBI_ADR6    = (0x02),/*!< GPC_MFP2 PC10 setting for EBI_ADR6   */
	PC10_UART6_nRTS  = (0x05),/*!< GPC_MFP2 PC10 setting for UART6_nRTS */
	PC10_SPI3_CLK    = (0x06),/*!< GPC_MFP2 PC10 setting for SPI3_CLK   */
	PC10_UART3_TXD   = (0x07),/*!< GPC_MFP2 PC10 setting for UART3_TXD  */
	PC10_CAN1_TXD    = (0x09),/*!< GPC_MFP2 PC10 setting for CAN1_TXD   */
	PC10_I2C4_SMBAL  = (0x0a),/*!< GPC_MFP2 PC10 setting for I2C4_SMBAL */
	PC10_ECAP1_IC0   = (0x0b),/*!< GPC_MFP2 PC10 setting for ECAP1_IC0  */
	PC10_EPWM1_CH2   = (0x0c),/*!< GPC_MFP2 PC10 setting for EPWM1_CH2  */
	PC10_EADC1_ST    = (0x0e),/*!< GPC_MFP2 PC10 setting for EADC1_ST   */

	/* PC.11 MFP */
	PC11_GPIO        = (0x00),/*!< GPC_MFP2 PC11 setting for GPIO       */
	PC11_EADC2_CH12  = (0x01),/*!< GPC_MFP2 PC11 setting for EADC2_CH12 */
	PC11_ACMP3_P3    = (0x01),/*!< GPC_MFP2 PC11 setting for ACMP3_P3   */
	PC11_EBI_ADR5    = (0x02),/*!< GPC_MFP2 PC11 setting for EBI_ADR5   */
	PC11_UART0_RXD   = (0x03),/*!< GPC_MFP2 PC11 setting for UART0_RXD  */
	PC11_I2C0_SDA    = (0x04),/*!< GPC_MFP2 PC11 setting for I2C0_SDA   */
	PC11_UART6_RXD   = (0x05),/*!< GPC_MFP2 PC11 setting for UART6_RXD  */
	PC11_SPI3_MOSI   = (0x06),/*!< GPC_MFP2 PC11 setting for SPI3_MOSI  */
	PC11_I2C4_SDA    = (0x0a),/*!< GPC_MFP2 PC11 setting for I2C4_SDA   */
	PC11_ECAP1_IC1   = (0x0b),/*!< GPC_MFP2 PC11 setting for ECAP1_IC1  */
	PC11_EPWM1_CH1   = (0x0c),/*!< GPC_MFP2 PC11 setting for EPWM1_CH1  */
	PC11_ACMP1_O     = (0x0e),/*!< GPC_MFP2 PC11 setting for ACMP1_O    */

	/* PC.12 MFP */
	PC12_GPIO        = (0x00),/*!< GPC_MFP3 PC12 setting for GPIO       */
	PC12_EADC2_CH13  = (0x01),/*!< GPC_MFP3 PC12 setting for EADC2_CH13 */
	PC12_EBI_ADR4    = (0x02),/*!< GPC_MFP3 PC12 setting for EBI_ADR4   */
	PC12_UART0_TXD   = (0x03),/*!< GPC_MFP3 PC12 setting for UART0_TXD  */
	PC12_I2C0_SCL    = (0x04),/*!< GPC_MFP3 PC12 setting for I2C0_SCL   */
	PC12_UART6_TXD   = (0x05),/*!< GPC_MFP3 PC12 setting for UART6_TXD  */
	PC12_SPI3_MISO   = (0x06),/*!< GPC_MFP3 PC12 setting for SPI3_MISO  */
	PC12_SC0_nCD     = (0x09),/*!< GPC_MFP3 PC12 setting for SC0_nCD    */
	PC12_I2C4_SCL    = (0x0a),/*!< GPC_MFP3 PC12 setting for I2C4_SCL   */
	PC12_ECAP1_IC2   = (0x0b),/*!< GPC_MFP3 PC12 setting for ECAP1_IC2  */
	PC12_EPWM1_CH0   = (0x0c),/*!< GPC_MFP3 PC12 setting for EPWM1_CH0  */
	PC12_ACMP0_O     = (0x0e),/*!< GPC_MFP3 PC12 setting for ACMP0_O    */

	/* PC.13 MFP */
	PC13_GPIO        = (0x00),/*!< GPC_MFP3 PC13 setting for GPIO       */
	PC13_EADC1_CH3   = (0x01),/*!< GPC_MFP3 PC13 setting for EADC1_CH3  */
	PC13_EADC2_CH3   = (0x01),/*!< GPC_MFP3 PC13 setting for EADC2_CH3  */
	PC13_EBI_ADR10   = (0x02),/*!< GPC_MFP3 PC13 setting for EBI_ADR10  */
	PC13_SC2_nCD     = (0x03),/*!< GPC_MFP3 PC13 setting for SC2_nCD    */
	PC13_SPI2_I2SMCLK = (0x04),/*!< GPC_MFP3 PC13 setting for SPI2_I2SMCLK*/
	PC13_CAN1_TXD    = (0x05),/*!< GPC_MFP3 PC13 setting for CAN1_TXD   */
	PC13_USCI0_CTL0  = (0x06),/*!< GPC_MFP3 PC13 setting for USCI0_CTL0 */
	PC13_UART2_TXD   = (0x07),/*!< GPC_MFP3 PC13 setting for UART2_TXD  */
	PC13_UART8_nCTS  = (0x08),/*!< GPC_MFP3 PC13 setting for UART8_nCTS */
	PC13_BPWM0_CH4   = (0x09),/*!< GPC_MFP3 PC13 setting for BPWM0_CH4  */
	PC13_CLKO        = (0x0d),/*!< GPC_MFP3 PC13 setting for CLKO       */
	PC13_EADC0_ST    = (0x0e),/*!< GPC_MFP3 PC13 setting for EADC0_ST   */
	PC13_SPI9_SS     = (0x13),/*!< GPC_MFP3 PC13 setting for SPI9_SS (0xM460xGCAE only), */

	/* PC.14 MFP */
	PC14_GPIO        = (0x00),/*!< GPC_MFP3 PC14 setting for GPIO       */
	PC14_EBI_AD11    = (0x02),/*!< GPC_MFP3 PC14 setting for EBI_AD11   */
	PC14_SC1_nCD     = (0x03),/*!< GPC_MFP3 PC14 setting for SC1_nCD    */
	PC14_SPI0_I2SMCLK = (0x04),/*!< GPC_MFP3 PC14 setting for SPI0_I2SMCLK*/
	PC14_USCI0_CTL0  = (0x05),/*!< GPC_MFP3 PC14 setting for USCI0_CTL0 */
	PC14_QSPI0_CLK   = (0x06),/*!< GPC_MFP3 PC14 setting for QSPI0_CLK  */
	PC14_TRACE_SWO   = (0x0a),/*!< GPC_MFP3 PC14 setting for TRACE_SWO  */
	PC14_EPWM0_SYNC_IN = (0x0b),/*!< GPC_MFP3 PC14 setting for EPWM0_SYNC_IN*/
	PC14_ETMC_TRACE_CLK = (0x0c),/*!< GPC_MFP3 PC14 setting for ETMC_TRACE_CLK*/
	PC14_TM1         = (0x0d),/*!< GPC_MFP3 PC14 setting for TM1        */
	PC14_USB_VBUS_ST = (0x0e),/*!< GPC_MFP3 PC14 setting for USB_VBUS_ST*/
	PC14_HSUSB_VBUS_ST = (0x0f),/*!< GPC_MFP3 PC14 setting for HSUSB_VBUS_ST*/
	PC14_SPI9_MOSI   = (0x13),/*!< GPC_MFP3 PC14 setting for SPI9_MOSI (0xM460xGCAE only), */
	PC14_BMC26       = (0x14),/*!< GPC_MFP3 PC14 setting for BMC26     (0xM460xGCAE only), */

	/* PD.0 MFP */
	PD0_GPIO         = (0x00), /*!< GPD_MFP0 PD0 setting for GPIO        */
	PD0_EBI_AD13     = (0x02), /*!< GPD_MFP0 PD0 setting for EBI_AD13    */
	PD0_USCI0_CLK    = (0x03), /*!< GPD_MFP0 PD0 setting for USCI0_CLK   */
	PD0_SPI0_MOSI    = (0x04), /*!< GPD_MFP0 PD0 setting for SPI0_MOSI   */
	PD0_UART3_RXD    = (0x05), /*!< GPD_MFP0 PD0 setting for UART3_RXD   */
	PD0_I2C2_SDA     = (0x06), /*!< GPD_MFP0 PD0 setting for I2C2_SDA    */
	PD0_SC2_CLK      = (0x07), /*!< GPD_MFP0 PD0 setting for SC2_CLK     */
	PD0_I2S1_DO      = (0x0a), /*!< GPD_MFP0 PD0 setting for I2S1_DO     */
	PD0_EQEI2_A      = (0x0c), /*!< GPD_MFP0 PD0 setting for EQEI2_A     */
	PD0_ECAP2_IC1    = (0x0d), /*!< GPD_MFP0 PD0 setting for ECAP2_IC1   */
	PD0_TM2          = (0x0e), /*!< GPD_MFP0 PD0 setting for TM2         */

	/* PD.1 MFP */
	PD1_GPIO         = (0x00), /*!< GPD_MFP0 PD1 setting for GPIO        */
	PD1_EBI_AD12     = (0x02), /*!< GPD_MFP0 PD1 setting for EBI_AD12    */
	PD1_USCI0_DAT0   = (0x03), /*!< GPD_MFP0 PD1 setting for USCI0_DAT0  */
	PD1_SPI0_MISO    = (0x04), /*!< GPD_MFP0 PD1 setting for SPI0_MISO   */
	PD1_UART3_TXD    = (0x05), /*!< GPD_MFP0 PD1 setting for UART3_TXD   */
	PD1_I2C2_SCL     = (0x06), /*!< GPD_MFP0 PD1 setting for I2C2_SCL    */
	PD1_SC2_DAT      = (0x07), /*!< GPD_MFP0 PD1 setting for SC2_DAT     */
	PD1_I2S1_DI      = (0x0a), /*!< GPD_MFP0 PD1 setting for I2S1_DI     */
	PD1_EQEI2_INDEX  = (0x0c), /*!< GPD_MFP0 PD1 setting for EQEI2_INDEX */
	PD1_ECAP2_IC0    = (0x0d), /*!< GPD_MFP0 PD1 setting for ECAP2_IC0   */

	/* PD.2 MFP */
	PD2_GPIO         = (0x00), /*!< GPD_MFP0 PD2 setting for GPIO        */
	PD2_EBI_AD11     = (0x02), /*!< GPD_MFP0 PD2 setting for EBI_AD11    */
	PD2_USCI0_DAT1   = (0x03), /*!< GPD_MFP0 PD2 setting for USCI0_DAT1  */
	PD2_SPI0_CLK     = (0x04), /*!< GPD_MFP0 PD2 setting for SPI0_CLK    */
	PD2_UART3_nCTS   = (0x05), /*!< GPD_MFP0 PD2 setting for UART3_nCTS  */
	PD2_SC2_RST      = (0x07), /*!< GPD_MFP0 PD2 setting for SC2_RST     */
	PD2_UART0_RXD    = (0x09), /*!< GPD_MFP0 PD2 setting for UART0_RXD   */
	PD2_I2S1_MCLK    = (0x0a), /*!< GPD_MFP0 PD2 setting for I2S1_MCLK   */
	PD2_EQEI3_B      = (0x0d), /*!< GPD_MFP0 PD2 setting for EQEI3_B     */

	/* PD.3 MFP */
	PD3_GPIO         = (0x00), /*!< GPD_MFP0 PD3 setting for GPIO        */
	PD3_EBI_AD10     = (0x02), /*!< GPD_MFP0 PD3 setting for EBI_AD10    */
	PD3_USCI0_CTL1   = (0x03), /*!< GPD_MFP0 PD3 setting for USCI0_CTL1  */
	PD3_SPI0_SS      = (0x04), /*!< GPD_MFP0 PD3 setting for SPI0_SS     */
	PD3_UART3_nRTS   = (0x05), /*!< GPD_MFP0 PD3 setting for UART3_nRTS  */
	PD3_SC2_PWR      = (0x07), /*!< GPD_MFP0 PD3 setting for SC2_PWR     */
	PD3_SC1_nCD      = (0x08), /*!< GPD_MFP0 PD3 setting for SC1_nCD     */
	PD3_UART0_TXD    = (0x09), /*!< GPD_MFP0 PD3 setting for UART0_TXD   */
	PD3_I2S1_BCLK    = (0x0a), /*!< GPD_MFP0 PD3 setting for I2S1_BCLK   */
	PD3_EQEI3_A      = (0x0d), /*!< GPD_MFP0 PD3 setting for EQEI3_A     */

	/* PD.4 MFP */
	PD4_GPIO         = (0x00), /*!< GPD_MFP1 PD4 setting for GPIO        */
	PD4_USCI0_CTL0   = (0x03), /*!< GPD_MFP1 PD4 setting for USCI0_CTL0  */
	PD4_I2C1_SDA     = (0x04), /*!< GPD_MFP1 PD4 setting for I2C1_SDA    */
	PD4_SPI1_SS      = (0x05), /*!< GPD_MFP1 PD4 setting for SPI1_SS     */
	PD4_SC1_CLK      = (0x08), /*!< GPD_MFP1 PD4 setting for SC1_CLK     */
	PD4_USB_VBUS_ST  = (0x0e), /*!< GPD_MFP1 PD4 setting for USB_VBUS_ST */
	PD4_PSIO0_CH7    = (0x11), /*!< GPD_MFP1 PD4 setting for PSIO0_CH7   */

	/* PD.5 MFP */
	PD5_GPIO         = (0x00), /*!< GPD_MFP1 PD5 setting for GPIO        */
	PD5_I2C1_SCL     = (0x04), /*!< GPD_MFP1 PD5 setting for I2C1_SCL    */
	PD5_SPI1_CLK     = (0x05), /*!< GPD_MFP1 PD5 setting for SPI1_CLK    */
	PD5_SC1_DAT      = (0x08), /*!< GPD_MFP1 PD5 setting for SC1_DAT     */
	PD5_ACMP1_O      = (0x0e), /*!< GPD_MFP1 PD5 setting for ACMP1_O     */
	PD5_EADC1_ST     = (0x0f), /*!< GPD_MFP1 PD5 setting for EADC1_ST    */
	PD5_HBI_D7       = (0x10), /*!< GPD_MFP1 PD5 setting for HBI_D7      */
	PD5_PSIO0_CH6    = (0x11), /*!< GPD_MFP1 PD5 setting for PSIO0_CH6   */

	/* PD.6 MFP */
	PD6_GPIO         = (0x00), /*!< GPD_MFP1 PD6 setting for GPIO        */
	PD6_EBI_AD5      = (0x02), /*!< GPD_MFP1 PD6 setting for EBI_AD5     */
	PD6_UART1_RXD    = (0x03), /*!< GPD_MFP1 PD6 setting for UART1_RXD   */
	PD6_I2C0_SDA     = (0x04), /*!< GPD_MFP1 PD6 setting for I2C0_SDA    */
	PD6_SPI1_MOSI    = (0x05), /*!< GPD_MFP1 PD6 setting for SPI1_MOSI   */
	PD6_QSPI1_MOSI0  = (0x06), /*!< GPD_MFP1 PD6 setting for QSPI1_MOSI0 */
	PD6_SC1_RST      = (0x08), /*!< GPD_MFP1 PD6 setting for SC1_RST     */
	PD6_ACMP0_O      = (0x0e), /*!< GPD_MFP1 PD6 setting for ACMP0_O     */
	PD6_EADC0_ST     = (0x0f), /*!< GPD_MFP1 PD6 setting for EADC0_ST    */
	PD6_HBI_D6       = (0x10), /*!< GPD_MFP1 PD6 setting for HBI_D6      */
	PD6_PSIO0_CH5    = (0x11), /*!< GPD_MFP1 PD6 setting for PSIO0_CH5   */

	/* PD.7 MFP */
	PD7_GPIO         = (0x00), /*!< GPD_MFP1 PD7 setting for GPIO        */
	PD7_EBI_AD4      = (0x02), /*!< GPD_MFP1 PD7 setting for EBI_AD4     */
	PD7_UART1_TXD    = (0x03), /*!< GPD_MFP1 PD7 setting for UART1_TXD   */
	PD7_I2C0_SCL     = (0x04), /*!< GPD_MFP1 PD7 setting for I2C0_SCL    */
	PD7_SPI1_MISO    = (0x05), /*!< GPD_MFP1 PD7 setting for SPI1_MISO   */
	PD7_QSPI1_MISO0  = (0x06), /*!< GPD_MFP1 PD7 setting for QSPI1_MISO0 */
	PD7_CCAP_HSYNC   = (0x07), /*!< GPD_MFP1 PD7 setting for CCAP_HSYNC  */
	PD7_SC1_PWR      = (0x08), /*!< GPD_MFP1 PD7 setting for SC1_PWR     */
	PD7_HBI_D5       = (0x10), /*!< GPD_MFP1 PD7 setting for HBI_D5      */
	PD7_PSIO0_CH4    = (0x11), /*!< GPD_MFP1 PD7 setting for PSIO0_CH4   */

	/* PD.8 MFP */
	PD8_GPIO         = (0x00), /*!< GPD_MFP2 PD8 setting for GPIO        */
	PD8_EBI_AD6      = (0x02), /*!< GPD_MFP2 PD8 setting for EBI_AD6     */
	PD8_I2C2_SDA     = (0x03), /*!< GPD_MFP2 PD8 setting for I2C2_SDA    */
	PD8_UART2_nRTS   = (0x04), /*!< GPD_MFP2 PD8 setting for UART2_nRTS  */
	PD8_UART7_RXD    = (0x05), /*!< GPD_MFP2 PD8 setting for UART7_RXD   */
	PD8_CAN2_RXD     = (0x06), /*!< GPD_MFP2 PD8 setting for CAN2_RXD    */
	PD8_PSIO0_CH3    = (0x11), /*!< GPD_MFP2 PD8 setting for PSIO0_CH3   */

	/* PD.9 MFP */
	PD9_GPIO         = (0x00), /*!< GPD_MFP2 PD9 setting for GPIO        */
	PD9_EBI_AD7      = (0x02), /*!< GPD_MFP2 PD9 setting for EBI_AD7     */
	PD9_I2C2_SCL     = (0x03), /*!< GPD_MFP2 PD9 setting for I2C2_SCL    */
	PD9_UART2_nCTS   = (0x04), /*!< GPD_MFP2 PD9 setting for UART2_nCTS  */
	PD9_UART7_TXD    = (0x05), /*!< GPD_MFP2 PD9 setting for UART7_TXD   */
	PD9_CAN2_TXD     = (0x06), /*!< GPD_MFP2 PD9 setting for CAN2_TXD    */
	PD9_PSIO0_CH2    = (0x11), /*!< GPD_MFP2 PD9 setting for PSIO0_CH2   */

	/* PD.10 MFP */
	PD10_GPIO        = (0x00),/*!< GPD_MFP2 PD10 setting for GPIO       */
	PD10_EADC1_CH0   = (0x01),/*!< GPD_MFP2 PD10 setting for EADC1_CH0  */
	PD10_EADC2_CH0   = (0x01),/*!< GPD_MFP2 PD10 setting for EADC2_CH0  */
	PD10_EBI_nCS2    = (0x02),/*!< GPD_MFP2 PD10 setting for EBI_nCS2   */
	PD10_UART1_RXD   = (0x03),/*!< GPD_MFP2 PD10 setting for UART1_RXD  */
	PD10_CAN0_RXD    = (0x04),/*!< GPD_MFP2 PD10 setting for CAN0_RXD   */
	PD10_UART8_RXD   = (0x08),/*!< GPD_MFP2 PD10 setting for UART8_RXD  */
	PD10_EQEI0_B     = (0x0a),/*!< GPD_MFP2 PD10 setting for EQEI0_B    */
	PD10_ECAP3_IC2   = (0x0b),/*!< GPD_MFP2 PD10 setting for ECAP3_IC2  */
	PD10_INT7        = (0x0f),/*!< GPD_MFP2 PD10 setting for INT7       */
	PD10_SPI9_MOSI   = (0x13),/*!< GPD_MFP2 PD10 setting for SPI9_MOSI (0xM460xGCAE only), */

	/* PD.11 MFP */
	PD11_GPIO        = (0x00),/*!< GPD_MFP2 PD11 setting for GPIO       */
	PD11_EADC1_CH1   = (0x01),/*!< GPD_MFP2 PD11 setting for EADC1_CH1  */
	PD11_EADC2_CH1   = (0x01),/*!< GPD_MFP2 PD11 setting for EADC2_CH1  */
	PD11_EBI_nCS1    = (0x02),/*!< GPD_MFP2 PD11 setting for EBI_nCS1   */
	PD11_UART1_TXD   = (0x03),/*!< GPD_MFP2 PD11 setting for UART1_TXD  */
	PD11_CAN0_TXD    = (0x04),/*!< GPD_MFP2 PD11 setting for CAN0_TXD   */
	PD11_UART8_TXD   = (0x08),/*!< GPD_MFP2 PD11 setting for UART8_TXD  */
	PD11_EQEI0_A     = (0x0a),/*!< GPD_MFP2 PD11 setting for EQEI0_A    */
	PD11_ECAP3_IC1   = (0x0b),/*!< GPD_MFP2 PD11 setting for ECAP3_IC1  */
	PD11_INT6        = (0x0f),/*!< GPD_MFP2 PD11 setting for INT6       */
	PD11_SPI9_MISO   = (0x13),/*!< GPD_MFP2 PD11 setting for SPI9_MISO (0xM460xGCAE only), */

	/* PD.12 MFP */
	PD12_GPIO        = (0x00),/*!< GPD_MFP3 PD12 setting for GPIO       */
	PD12_EADC1_CH2   = (0x01),/*!< GPD_MFP3 PD12 setting for EADC1_CH2  */
	PD12_EADC2_CH2   = (0x01),/*!< GPD_MFP3 PD12 setting for EADC2_CH2  */
	PD12_EBI_nCS0    = (0x02),/*!< GPD_MFP3 PD12 setting for EBI_nCS0   */
	PD12_CAN1_RXD    = (0x05),/*!< GPD_MFP3 PD12 setting for CAN1_RXD   */
	PD12_UART2_RXD   = (0x07),/*!< GPD_MFP3 PD12 setting for UART2_RXD  */
	PD12_UART8_nRTS  = (0x08),/*!< GPD_MFP3 PD12 setting for UART8_nRTS */
	PD12_BPWM0_CH5   = (0x09),/*!< GPD_MFP3 PD12 setting for BPWM0_CH5  */
	PD12_EQEI0_INDEX = (0x0a),/*!< GPD_MFP3 PD12 setting for EQEI0_INDEX */
	PD12_ECAP3_IC0   = (0x0b),/*!< GPD_MFP3 PD12 setting for ECAP3_IC0  */
	PD12_CLKO        = (0x0d),/*!< GPD_MFP3 PD12 setting for CLKO       */
	PD12_EADC0_ST    = (0x0e),/*!< GPD_MFP3 PD12 setting for EADC0_ST   */
	PD12_INT5        = (0x0f),/*!< GPD_MFP3 PD12 setting for INT5       */
	PD12_SPI9_CLK    = (0x13),/*!< GPD_MFP3 PD12 setting for SPI9_CLK (0xM460xGCAE only), */

	/* PD.13 MFP */
	PD13_GPIO        = (0x00),/*!< GPD_MFP3 PD13 setting for GPIO       */
	PD13_EBI_AD10    = (0x02),/*!< GPD_MFP3 PD13 setting for EBI_AD10   */
	PD13_SD0_nCD     = (0x03),/*!< GPD_MFP3 PD13 setting for SD0_nCD    */
	PD13_SPI0_I2SMCLK = (0x04),/*!< GPD_MFP3 PD13 setting for SPI0_I2SMCLK*/
	PD13_SPI1_I2SMCLK = (0x05),/*!< GPD_MFP3 PD13 setting for SPI1_I2SMCLK*/
	PD13_QSPI1_MOSI0 = (0x06),/*!< GPD_MFP3 PD13 setting for QSPI1_MOSI0*/
	PD13_SC2_nCD     = (0x07),/*!< GPD_MFP3 PD13 setting for SC2_nCD    */
	PD13_SD1_CLK     = (0x08),/*!< GPD_MFP3 PD13 setting for SD1_CLK    */
	PD13_UART6_RXD   = (0x09),/*!< GPD_MFP3 PD13 setting for UART6_RXD  */
	PD13_I2S1_LRCK   = (0x0a),/*!< GPD_MFP3 PD13 setting for I2S1_LRCK  */
	PD13_BPWM0_CH0   = (0x0b),/*!< GPD_MFP3 PD13 setting for BPWM0_CH0  */
	PD13_EQEI2_B     = (0x0c),/*!< GPD_MFP3 PD13 setting for EQEI2_B    */
	PD13_ECAP2_IC2   = (0x0d),/*!< GPD_MFP3 PD13 setting for ECAP2_IC2  */
	PD13_CLKO        = (0x0e),/*!< GPD_MFP3 PD13 setting for CLKO       */
	PD13_EADC0_ST    = (0x0f),/*!< GPD_MFP3 PD13 setting for EADC0_ST   */
	PD13_QSPI1_MOSI1 = (0x13),/*!< GPD_MFP3 PD13 setting for QSPI1_MOSI1*/

	/* PD.14 MFP */
	PD14_GPIO        = (0x00),/*!< GPD_MFP3 PD14 setting for GPIO       */
	PD14_EBI_nCS0    = (0x02),/*!< GPD_MFP3 PD14 setting for EBI_nCS0   */
	PD14_SPI3_I2SMCLK = (0x03),/*!< GPD_MFP3 PD14 setting for SPI3_I2SMCLK*/
	PD14_SC1_nCD     = (0x04),/*!< GPD_MFP3 PD14 setting for SC1_nCD    */
	PD14_SPI0_I2SMCLK = (0x05),/*!< GPD_MFP3 PD14 setting for SPI0_I2SMCLK*/
	PD14_I2S1_BCLK   = (0x0a),/*!< GPD_MFP3 PD14 setting for I2S1_BCLK  */
	PD14_EPWM0_CH4   = (0x0b),/*!< GPD_MFP3 PD14 setting for EPWM0_CH4  */

	/* PE.0 MFP */
	PE0_GPIO         = (0x00), /*!< GPE_MFP0 PE0 setting for GPIO        */
	PE0_EBI_AD11     = (0x02), /*!< GPE_MFP0 PE0 setting for EBI_AD11    */
	PE0_QSPI0_MOSI0  = (0x03), /*!< GPE_MFP0 PE0 setting for QSPI0_MOSI0 */
	PE0_SC2_CLK      = (0x04), /*!< GPE_MFP0 PE0 setting for SC2_CLK     */
	PE0_I2S0_MCLK    = (0x05), /*!< GPE_MFP0 PE0 setting for I2S0_MCLK   */
	PE0_SPI1_MOSI    = (0x06), /*!< GPE_MFP0 PE0 setting for SPI1_MOSI   */
	PE0_UART3_RXD    = (0x07), /*!< GPE_MFP0 PE0 setting for UART3_RXD   */
	PE0_I2C1_SDA     = (0x08), /*!< GPE_MFP0 PE0 setting for I2C1_SDA    */
	PE0_UART4_nRTS   = (0x09), /*!< GPE_MFP0 PE0 setting for UART4_nRTS  */
	PE0_UART8_RXD    = (0x0a), /*!< GPE_MFP0 PE0 setting for UART8_RXD   */

	/* PE.1 MFP */
	PE1_GPIO         = (0x00), /*!< GPE_MFP0 PE1 setting for GPIO        */
	PE1_EBI_AD10     = (0x02), /*!< GPE_MFP0 PE1 setting for EBI_AD10    */
	PE1_QSPI0_MISO0  = (0x03), /*!< GPE_MFP0 PE1 setting for QSPI0_MISO0 */
	PE1_SC2_DAT      = (0x04), /*!< GPE_MFP0 PE1 setting for SC2_DAT     */
	PE1_I2S0_BCLK    = (0x05), /*!< GPE_MFP0 PE1 setting for I2S0_BCLK   */
	PE1_SPI1_MISO    = (0x06), /*!< GPE_MFP0 PE1 setting for SPI1_MISO   */
	PE1_UART3_TXD    = (0x07), /*!< GPE_MFP0 PE1 setting for UART3_TXD   */
	PE1_I2C1_SCL     = (0x08), /*!< GPE_MFP0 PE1 setting for I2C1_SCL    */
	PE1_UART4_nCTS   = (0x09), /*!< GPE_MFP0 PE1 setting for UART4_nCTS  */
	PE1_UART8_TXD    = (0x0a), /*!< GPE_MFP0 PE1 setting for UART8_TXD   */

	/* PE.2 MFP */
	PE2_GPIO         = (0x00), /*!< GPE_MFP0 PE2 setting for GPIO        */
	PE2_EBI_ALE      = (0x02), /*!< GPE_MFP0 PE2 setting for EBI_ALE     */
	PE2_SD0_DAT0     = (0x03), /*!< GPE_MFP0 PE2 setting for SD0_DAT0    */
	PE2_SPIM_MOSI    = (0x04), /*!< GPE_MFP0 PE2 setting for SPIM_MOSI   */
	PE2_SPI3_MOSI    = (0x05), /*!< GPE_MFP0 PE2 setting for SPI3_MOSI   */
	PE2_SC0_CLK      = (0x06), /*!< GPE_MFP0 PE2 setting for SC0_CLK     */
	PE2_USCI0_CLK    = (0x07), /*!< GPE_MFP0 PE2 setting for USCI0_CLK   */
	PE2_UART6_nCTS   = (0x08), /*!< GPE_MFP0 PE2 setting for UART6_nCTS  */
	PE2_UART7_RXD    = (0x09), /*!< GPE_MFP0 PE2 setting for UART7_RXD   */
	PE2_UART8_nRTS   = (0x0a), /*!< GPE_MFP0 PE2 setting for UART8_nRTS  */
	PE2_EQEI0_B      = (0x0b), /*!< GPE_MFP0 PE2 setting for EQEI0_B     */
	PE2_EPWM0_CH5    = (0x0c), /*!< GPE_MFP0 PE2 setting for EPWM0_CH5   */
	PE2_BPWM0_CH0    = (0x0d), /*!< GPE_MFP0 PE2 setting for BPWM0_CH0   */

	/* PE.3 MFP */
	PE3_GPIO         = (0x00), /*!< GPE_MFP0 PE3 setting for GPIO        */
	PE3_EBI_MCLK     = (0x02), /*!< GPE_MFP0 PE3 setting for EBI_MCLK    */
	PE3_SD0_DAT1     = (0x03), /*!< GPE_MFP0 PE3 setting for SD0_DAT1    */
	PE3_SPIM_MISO    = (0x04), /*!< GPE_MFP0 PE3 setting for SPIM_MISO   */
	PE3_SPI3_MISO    = (0x05), /*!< GPE_MFP0 PE3 setting for SPI3_MISO   */
	PE3_SC0_DAT      = (0x06), /*!< GPE_MFP0 PE3 setting for SC0_DAT     */
	PE3_USCI0_DAT0   = (0x07), /*!< GPE_MFP0 PE3 setting for USCI0_DAT0  */
	PE3_UART6_nRTS   = (0x08), /*!< GPE_MFP0 PE3 setting for UART6_nRTS  */
	PE3_UART7_TXD    = (0x09), /*!< GPE_MFP0 PE3 setting for UART7_TXD   */
	PE3_UART8_nCTS   = (0x0a), /*!< GPE_MFP0 PE3 setting for UART8_nCTS  */
	PE3_EQEI0_A      = (0x0b), /*!< GPE_MFP0 PE3 setting for EQEI0_A     */
	PE3_EPWM0_CH4    = (0x0c), /*!< GPE_MFP0 PE3 setting for EPWM0_CH4   */
	PE3_BPWM0_CH1    = (0x0d), /*!< GPE_MFP0 PE3 setting for BPWM0_CH1   */

	/* PE.4 MFP */
	PE4_GPIO         = (0x00), /*!< GPE_MFP1 PE4 setting for GPIO        */
	PE4_EBI_nWR      = (0x02), /*!< GPE_MFP1 PE4 setting for EBI_nWR     */
	PE4_SD0_DAT2     = (0x03), /*!< GPE_MFP1 PE4 setting for SD0_DAT2    */
	PE4_SPIM_CLK     = (0x04), /*!< GPE_MFP1 PE4 setting for SPIM_CLK    */
	PE4_SPI3_CLK     = (0x05), /*!< GPE_MFP1 PE4 setting for SPI3_CLK    */
	PE4_SC0_RST      = (0x06), /*!< GPE_MFP1 PE4 setting for SC0_RST     */
	PE4_USCI0_DAT1   = (0x07), /*!< GPE_MFP1 PE4 setting for USCI0_DAT1  */
	PE4_UART6_RXD    = (0x08), /*!< GPE_MFP1 PE4 setting for UART6_RXD   */
	PE4_UART7_nCTS   = (0x09), /*!< GPE_MFP1 PE4 setting for UART7_nCTS  */
	PE4_UART9_RXD    = (0x0a), /*!< GPE_MFP1 PE4 setting for UART9_RXD   */
	PE4_EQEI0_INDEX  = (0x0b), /*!< GPE_MFP1 PE4 setting for EQEI0_INDEX */
	PE4_EPWM0_CH3    = (0x0c), /*!< GPE_MFP1 PE4 setting for EPWM0_CH3   */
	PE4_BPWM0_CH2    = (0x0d), /*!< GPE_MFP1 PE4 setting for BPWM0_CH2   */
	PE4_PSIO0_CH3    = (0x11), /*!< GPE_MFP1 PE4 setting for PSIO0_CH3   */

	/* PE.5 MFP */
	PE5_GPIO         = (0x00), /*!< GPE_MFP1 PE5 setting for GPIO        */
	PE5_EBI_nRD      = (0x02), /*!< GPE_MFP1 PE5 setting for EBI_nRD     */
	PE5_SD0_DAT3     = (0x03), /*!< GPE_MFP1 PE5 setting for SD0_DAT3    */
	PE5_SPIM_SS      = (0x04), /*!< GPE_MFP1 PE5 setting for SPIM_SS     */
	PE5_SPI3_SS      = (0x05), /*!< GPE_MFP1 PE5 setting for SPI3_SS     */
	PE5_SC0_PWR      = (0x06), /*!< GPE_MFP1 PE5 setting for SC0_PWR     */
	PE5_USCI0_CTL1   = (0x07), /*!< GPE_MFP1 PE5 setting for USCI0_CTL1  */
	PE5_UART6_TXD    = (0x08), /*!< GPE_MFP1 PE5 setting for UART6_TXD   */
	PE5_UART7_nRTS   = (0x09), /*!< GPE_MFP1 PE5 setting for UART7_nRTS  */
	PE5_UART9_TXD    = (0x0a), /*!< GPE_MFP1 PE5 setting for UART9_TXD   */
	PE5_EQEI1_B      = (0x0b), /*!< GPE_MFP1 PE5 setting for EQEI1_B     */
	PE5_EPWM0_CH2    = (0x0c), /*!< GPE_MFP1 PE5 setting for EPWM0_CH2   */
	PE5_BPWM0_CH3    = (0x0d), /*!< GPE_MFP1 PE5 setting for BPWM0_CH3   */
	PE5_PSIO0_CH2    = (0x11), /*!< GPE_MFP1 PE5 setting for PSIO0_CH2   */

	/* PE.6 MFP */
	PE6_GPIO         = (0x00), /*!< GPE_MFP1 PE6 setting for GPIO        */
	PE6_SD0_CLK      = (0x03), /*!< GPE_MFP1 PE6 setting for SD0_CLK     */
	PE6_SPIM_D3      = (0x04), /*!< GPE_MFP1 PE6 setting for SPIM_D3     */
	PE6_SPI3_I2SMCLK = (0x05), /*!< GPE_MFP1 PE6 setting for SPI3_I2SMCLK*/
	PE6_SC0_nCD      = (0x06), /*!< GPE_MFP1 PE6 setting for SC0_nCD     */
	PE6_USCI0_CTL0   = (0x07), /*!< GPE_MFP1 PE6 setting for USCI0_CTL0  */
	PE6_UART5_RXD    = (0x08), /*!< GPE_MFP1 PE6 setting for UART5_RXD   */
	PE6_CAN1_RXD     = (0x09), /*!< GPE_MFP1 PE6 setting for CAN1_RXD    */
	PE6_UART9_nRTS   = (0x0a), /*!< GPE_MFP1 PE6 setting for UART9_nRTS  */
	PE6_EQEI1_A      = (0x0b), /*!< GPE_MFP1 PE6 setting for EQEI1_A     */
	PE6_EPWM0_CH1    = (0x0c), /*!< GPE_MFP1 PE6 setting for EPWM0_CH1   */
	PE6_BPWM0_CH4    = (0x0d), /*!< GPE_MFP1 PE6 setting for BPWM0_CH4   */
	PE6_ACMP3_O      = (0x0e), /*!< GPE_MFP1 PE6 setting for ACMP3_O     */
	PE6_PSIO0_CH1    = (0x11), /*!< GPE_MFP1 PE6 setting for PSIO0_CH1   */

	/* PE.7 MFP */
	PE7_GPIO         = (0x00), /*!< GPE_MFP1 PE7 setting for GPIO        */
	PE7_SD0_CMD      = (0x03), /*!< GPE_MFP1 PE7 setting for SD0_CMD     */
	PE7_SPIM_D2      = (0x04), /*!< GPE_MFP1 PE7 setting for SPIM_D2     */
	PE7_UART5_TXD    = (0x08), /*!< GPE_MFP1 PE7 setting for UART5_TXD   */
	PE7_CAN1_TXD     = (0x09), /*!< GPE_MFP1 PE7 setting for CAN1_TXD    */
	PE7_UART9_nCTS   = (0x0a), /*!< GPE_MFP1 PE7 setting for UART9_nCTS  */
	PE7_EQEI1_INDEX  = (0x0b), /*!< GPE_MFP1 PE7 setting for EQEI1_INDEX */
	PE7_EPWM0_CH0    = (0x0c), /*!< GPE_MFP1 PE7 setting for EPWM0_CH0   */
	PE7_BPWM0_CH5    = (0x0d), /*!< GPE_MFP1 PE7 setting for BPWM0_CH5   */
	PE7_ACMP2_O      = (0x0e), /*!< GPE_MFP1 PE7 setting for ACMP2_O     */
	PE7_PSIO0_CH0    = (0x11), /*!< GPE_MFP1 PE7 setting for PSIO0_CH0   */

	/* PE.8 MFP */
	PE8_GPIO         = (0x00), /*!< GPE_MFP2 PE8 setting for GPIO        */
	PE8_EBI_ADR10    = (0x02), /*!< GPE_MFP2 PE8 setting for EBI_ADR10   */
	PE8_EMAC0_RMII_MDC = (0x03), /*!< GPE_MFP2 PE8 setting for EMAC0_RMII_MDC*/
	PE8_I2S0_BCLK    = (0x04), /*!< GPE_MFP2 PE8 setting for I2S0_BCLK   */
	PE8_SPI2_CLK     = (0x05), /*!< GPE_MFP2 PE8 setting for SPI2_CLK    */
	PE8_UART2_TXD    = (0x07), /*!< GPE_MFP2 PE8 setting for UART2_TXD   */
	PE8_EPWM0_CH0    = (0x0a), /*!< GPE_MFP2 PE8 setting for EPWM0_CH0   */
	PE8_EPWM0_BRAKE0 = (0x0b), /*!< GPE_MFP2 PE8 setting for EPWM0_BRAKE0*/
	PE8_ECAP0_IC0    = (0x0c), /*!< GPE_MFP2 PE8 setting for ECAP0_IC0   */
	PE8_EQEI2_INDEX  = (0x0d), /*!< GPE_MFP2 PE8 setting for EQEI2_INDEX */
	PE8_TRACE_DATA3  = (0x0e), /*!< GPE_MFP2 PE8 setting for TRACE_DATA3 */
	PE8_ECAP3_IC0    = (0x0f), /*!< GPE_MFP2 PE8 setting for ECAP3_IC0   */

	/* PE.9 MFP */
	PE9_GPIO         = (0x00), /*!< GPE_MFP2 PE9 setting for GPIO        */
	PE9_EBI_ADR11    = (0x02), /*!< GPE_MFP2 PE9 setting for EBI_ADR11   */
	PE9_EMAC0_RMII_MDIO = (0x03), /*!< GPE_MFP2 PE9 setting for EMAC0_RMII_MDIO*/
	PE9_I2S0_MCLK    = (0x04), /*!< GPE_MFP2 PE9 setting for I2S0_MCLK   */
	PE9_SPI2_MISO    = (0x05), /*!< GPE_MFP2 PE9 setting for SPI2_MISO   */
	PE9_UART2_RXD    = (0x07), /*!< GPE_MFP2 PE9 setting for UART2_RXD   */
	PE9_EPWM0_CH1    = (0x0a), /*!< GPE_MFP2 PE9 setting for EPWM0_CH1   */
	PE9_EPWM0_BRAKE1 = (0x0b), /*!< GPE_MFP2 PE9 setting for EPWM0_BRAKE1*/
	PE9_ECAP0_IC1    = (0x0c), /*!< GPE_MFP2 PE9 setting for ECAP0_IC1   */
	PE9_EQEI2_A      = (0x0d), /*!< GPE_MFP2 PE9 setting for EQEI2_A     */
	PE9_TRACE_DATA2  = (0x0e), /*!< GPE_MFP2 PE9 setting for TRACE_DATA2 */
	PE9_ECAP3_IC1    = (0x0f), /*!< GPE_MFP2 PE9 setting for ECAP3_IC1   */

	/* PE.10 MFP */
	PE10_GPIO        = (0x00),/*!< GPE_MFP2 PE10 setting for GPIO       */
	PE10_EBI_ADR12   = (0x02),/*!< GPE_MFP2 PE10 setting for EBI_ADR12  */
	PE10_EMAC0_RMII_TXD0 = (0x03),/*!< GPE_MFP2 PE10 setting for EMAC0_RMII_TXD0*/
	PE10_I2S0_DI     = (0x04),/*!< GPE_MFP2 PE10 setting for I2S0_DI    */
	PE10_SPI2_MOSI   = (0x05),/*!< GPE_MFP2 PE10 setting for SPI2_MOSI  */
	PE10_UART3_TXD   = (0x07),/*!< GPE_MFP2 PE10 setting for UART3_TXD  */
	PE10_EPWM0_CH2   = (0x0a),/*!< GPE_MFP2 PE10 setting for EPWM0_CH2  */
	PE10_EPWM1_BRAKE0 = (0x0b),/*!< GPE_MFP2 PE10 setting for EPWM1_BRAKE0*/
	PE10_ECAP0_IC2   = (0x0c),/*!< GPE_MFP2 PE10 setting for ECAP0_IC2  */
	PE10_EQEI2_B     = (0x0d),/*!< GPE_MFP2 PE10 setting for EQEI2_B    */
	PE10_TRACE_DATA1 = (0x0e),/*!< GPE_MFP2 PE10 setting for TRACE_DATA1*/
	PE10_ECAP3_IC2   = (0x0f),/*!< GPE_MFP2 PE10 setting for ECAP3_IC2  */

	/* PE.11 MFP */
	PE11_GPIO        = (0x00),/*!< GPE_MFP2 PE11 setting for GPIO       */
	PE11_EBI_ADR13   = (0x02),/*!< GPE_MFP2 PE11 setting for EBI_ADR13  */
	PE11_EMAC0_RMII_TXD1 = (0x03),/*!< GPE_MFP2 PE11 setting for EMAC0_RMII_TXD1*/
	PE11_I2S0_DO     = (0x04),/*!< GPE_MFP2 PE11 setting for I2S0_DO    */
	PE11_SPI2_SS     = (0x05),/*!< GPE_MFP2 PE11 setting for SPI2_SS    */
	PE11_UART3_RXD   = (0x07),/*!< GPE_MFP2 PE11 setting for UART3_RXD  */
	PE11_UART1_nCTS  = (0x08),/*!< GPE_MFP2 PE11 setting for UART1_nCTS */
	PE11_EPWM0_CH3   = (0x0a),/*!< GPE_MFP2 PE11 setting for EPWM0_CH3  */
	PE11_EPWM1_BRAKE1 = (0x0b),/*!< GPE_MFP2 PE11 setting for EPWM1_BRAKE1*/
	PE11_ECAP1_IC2   = (0x0d),/*!< GPE_MFP2 PE11 setting for ECAP1_IC2  */
	PE11_TRACE_DATA0 = (0x0e),/*!< GPE_MFP2 PE11 setting for TRACE_DATA0*/
	PE11_KPI_COL7    = (0x12),/*!< GPE_MFP2 PE11 setting for KPI_COL7   */

	/* PE.12 MFP */
	PE12_GPIO        = (0x00),/*!< GPE_MFP3 PE12 setting for GPIO       */
	PE12_EBI_ADR14   = (0x02),/*!< GPE_MFP3 PE12 setting for EBI_ADR14  */
	PE12_EMAC0_RMII_TXEN = (0x03),/*!< GPE_MFP3 PE12 setting for EMAC0_RMII_TXEN*/
	PE12_I2S0_LRCK   = (0x04),/*!< GPE_MFP3 PE12 setting for I2S0_LRCK  */
	PE12_SPI2_I2SMCLK = (0x05),/*!< GPE_MFP3 PE12 setting for SPI2_I2SMCLK*/
	PE12_UART1_nRTS  = (0x08),/*!< GPE_MFP3 PE12 setting for UART1_nRTS */
	PE12_EPWM0_CH4   = (0x0a),/*!< GPE_MFP3 PE12 setting for EPWM0_CH4  */
	PE12_ECAP1_IC1   = (0x0d),/*!< GPE_MFP3 PE12 setting for ECAP1_IC1  */
	PE12_TRACE_CLK   = (0x0e),/*!< GPE_MFP3 PE12 setting for TRACE_CLK  */
	PE12_KPI_COL6    = (0x12),/*!< GPE_MFP3 PE12 setting for KPI_COL6   */

	/* PE.13 MFP */
	PE13_GPIO        = (0x00),/*!< GPE_MFP3 PE13 setting for GPIO       */
	PE13_EBI_ADR15   = (0x02),/*!< GPE_MFP3 PE13 setting for EBI_ADR15  */
	PE13_EMAC0_PPS   = (0x03),/*!< GPE_MFP3 PE13 setting for EMAC0_PPS  */
	PE13_I2C0_SCL    = (0x04),/*!< GPE_MFP3 PE13 setting for I2C0_SCL   */
	PE13_UART4_nRTS  = (0x05),/*!< GPE_MFP3 PE13 setting for UART4_nRTS */
	PE13_UART1_TXD   = (0x08),/*!< GPE_MFP3 PE13 setting for UART1_TXD  */
	PE13_EPWM0_CH5   = (0x0a),/*!< GPE_MFP3 PE13 setting for EPWM0_CH5  */
	PE13_EPWM1_CH0   = (0x0b),/*!< GPE_MFP3 PE13 setting for EPWM1_CH0  */
	PE13_BPWM1_CH5   = (0x0c),/*!< GPE_MFP3 PE13 setting for BPWM1_CH5  */
	PE13_ECAP1_IC0   = (0x0d),/*!< GPE_MFP3 PE13 setting for ECAP1_IC0  */
	PE13_TRACE_SWO   = (0x0e),/*!< GPE_MFP3 PE13 setting for TRACE_SWO  */
	PE13_KPI_COL5    = (0x12),/*!< GPE_MFP3 PE13 setting for KPI_COL5   */

	/* PE.14 MFP */
	PE14_GPIO        = (0x00),/*!< GPE_MFP3 PE14 setting for GPIO       */
	PE14_EBI_AD8     = (0x02),/*!< GPE_MFP3 PE14 setting for EBI_AD8    */
	PE14_UART2_TXD   = (0x03),/*!< GPE_MFP3 PE14 setting for UART2_TXD  */
	PE14_CAN0_TXD    = (0x04),/*!< GPE_MFP3 PE14 setting for CAN0_TXD   */
	PE14_SD1_nCD     = (0x05),/*!< GPE_MFP3 PE14 setting for SD1_nCD    */
	PE14_UART6_TXD   = (0x06),/*!< GPE_MFP3 PE14 setting for UART6_TXD  */
	PE14_PSIO0_CH0   = (0x11),/*!< GPE_MFP3 PE14 setting for PSIO0_CH0  */

	/* PE.15 MFP */
	PE15_GPIO        = (0x00),/*!< GPE_MFP3 PE15 setting for GPIO       */
	PE15_EBI_AD9     = (0x02),/*!< GPE_MFP3 PE15 setting for EBI_AD9    */
	PE15_UART2_RXD   = (0x03),/*!< GPE_MFP3 PE15 setting for UART2_RXD  */
	PE15_CAN0_RXD    = (0x04),/*!< GPE_MFP3 PE15 setting for CAN0_RXD   */
	PE15_UART6_RXD   = (0x06),/*!< GPE_MFP3 PE15 setting for UART6_RXD  */
	PE15_PSIO0_CH1   = (0x11),/*!< GPE_MFP3 PE15 setting for PSIO0_CH1  */

	/* PF.0 MFP */
	PF0_GPIO         = (0x00), /*!< GPF_MFP0 PF0 setting for GPIO        */
	PF0_UART1_TXD    = (0x02), /*!< GPF_MFP0 PF0 setting for UART1_TXD   */
	PF0_I2C1_SCL     = (0x03), /*!< GPF_MFP0 PF0 setting for I2C1_SCL    */
	PF0_UART0_TXD    = (0x04), /*!< GPF_MFP0 PF0 setting for UART0_TXD   */
	PF0_SC1_DAT      = (0x05), /*!< GPF_MFP0 PF0 setting for SC1_DAT     */
	PF0_I2S0_DO      = (0x06), /*!< GPF_MFP0 PF0 setting for I2S0_DO     */
	PF0_UART2_TXD    = (0x08), /*!< GPF_MFP0 PF0 setting for UART2_TXD   */
	PF0_I2C0_SCL     = (0x09), /*!< GPF_MFP0 PF0 setting for I2C0_SCL    */
	PF0_CAN2_TXD     = (0x0a), /*!< GPF_MFP0 PF0 setting for CAN2_TXD    */
	PF0_EPWM1_CH4    = (0x0b), /*!< GPF_MFP0 PF0 setting for EPWM1_CH4   */
	PF0_BPWM1_CH0    = (0x0c), /*!< GPF_MFP0 PF0 setting for BPWM1_CH0   */
	PF0_ACMP0_O      = (0x0d), /*!< GPF_MFP0 PF0 setting for ACMP0_O     */
	PF0_ICE_DAT      = (0x0e), /*!< GPF_MFP0 PF0 setting for ICE_DAT     */
	PF0_EADC0_ST     = (0x0f), /*!< GPF_MFP0 PF0 setting for EADC0_ST    */
	PF0_QSPI1_MISO0  = (0x13), /*!< GPF_MFP0 PF0 setting for QSPI1_MISO0 */

	/* PF.1 MFP */
	PF1_GPIO         = (0x00), /*!< GPF_MFP0 PF1 setting for GPIO        */
	PF1_UART1_RXD    = (0x02), /*!< GPF_MFP0 PF1 setting for UART1_RXD   */
	PF1_I2C1_SDA     = (0x03), /*!< GPF_MFP0 PF1 setting for I2C1_SDA    */
	PF1_UART0_RXD    = (0x04), /*!< GPF_MFP0 PF1 setting for UART0_RXD   */
	PF1_SC1_CLK      = (0x05), /*!< GPF_MFP0 PF1 setting for SC1_CLK     */
	PF1_I2S0_LRCK    = (0x06), /*!< GPF_MFP0 PF1 setting for I2S0_LRCK   */
	PF1_UART2_RXD    = (0x08), /*!< GPF_MFP0 PF1 setting for UART2_RXD   */
	PF1_I2C0_SDA     = (0x09), /*!< GPF_MFP0 PF1 setting for I2C0_SDA    */
	PF1_CAN2_RXD     = (0x0a), /*!< GPF_MFP0 PF1 setting for CAN2_RXD    */
	PF1_EPWM1_CH5    = (0x0b), /*!< GPF_MFP0 PF1 setting for EPWM1_CH5   */
	PF1_BPWM1_CH1    = (0x0c), /*!< GPF_MFP0 PF1 setting for BPWM1_CH1   */
	PF1_ACMP1_O      = (0x0d), /*!< GPF_MFP0 PF1 setting for ACMP1_O     */
	PF1_ICE_CLK      = (0x0e), /*!< GPF_MFP0 PF1 setting for ICE_CLK     */
	PF1_EADC1_ST     = (0x0f), /*!< GPF_MFP0 PF1 setting for EADC1_ST    */
	PF1_QSPI1_MOSI0  = (0x13), /*!< GPF_MFP0 PF1 setting for QSPI1_MOSI0 */

	/* PF.2 MFP */
	PF2_GPIO         = (0x00), /*!< GPF_MFP0 PF2 setting for GPIO        */
	PF2_EBI_nCS1     = (0x02), /*!< GPF_MFP0 PF2 setting for EBI_nCS1    */
	PF2_UART0_RXD    = (0x03), /*!< GPF_MFP0 PF2 setting for UART0_RXD   */
	PF2_I2C0_SDA     = (0x04), /*!< GPF_MFP0 PF2 setting for I2C0_SDA    */
	PF2_QSPI0_CLK    = (0x05), /*!< GPF_MFP0 PF2 setting for QSPI0_CLK   */
	PF2_UART9_RXD    = (0x07), /*!< GPF_MFP0 PF2 setting for UART9_RXD   */
	PF2_XT1_OUT      = (0x0a), /*!< GPF_MFP0 PF2 setting for XT1_OUT     */
	PF2_BPWM1_CH1    = (0x0b), /*!< GPF_MFP0 PF2 setting for BPWM1_CH1   */
	PF2_I2C4_SMBSUS  = (0x0c), /*!< GPF_MFP0 PF2 setting for I2C4_SMBSUS */
	PF2_ACMP3_O      = (0x0d), /*!< GPF_MFP0 PF2 setting for ACMP3_O     */
	PF2_BMC13        = (0x14), /*!< GPF_MFP0 PF2 setting for BMC13 (0xM460xGCAE only), */

	/* PF.3 MFP */
	PF3_GPIO         = (0x00), /*!< GPF_MFP0 PF3 setting for GPIO        */
	PF3_EBI_nCS0     = (0x02), /*!< GPF_MFP0 PF3 setting for EBI_nCS0    */
	PF3_UART0_TXD    = (0x03), /*!< GPF_MFP0 PF3 setting for UART0_TXD   */
	PF3_I2C0_SCL     = (0x04), /*!< GPF_MFP0 PF3 setting for I2C0_SCL    */
	PF3_UART9_TXD    = (0x07), /*!< GPF_MFP0 PF3 setting for UART9_TXD   */
	PF3_XT1_IN       = (0x0a), /*!< GPF_MFP0 PF3 setting for XT1_IN      */
	PF3_BPWM1_CH0    = (0x0b), /*!< GPF_MFP0 PF3 setting for BPWM1_CH0   */
	PF3_I2C4_SMBAL   = (0x0c), /*!< GPF_MFP0 PF3 setting for I2C4_SMBAL  */
	PF3_ACMP2_O      = (0x0d), /*!< GPF_MFP0 PF3 setting for ACMP2_O     */
	PF3_EADC2_ST     = (0x0f), /*!< GPF_MFP0 PF3 setting for EADC2_ST    */
	PF3_BMC12        = (0x14), /*!< GPF_MFP0 PF3 setting for BMC12 (0xM460xGCAE only), */

	/* PF.4 MFP */
	PF4_GPIO         = (0x00), /*!< GPF_MFP1 PF4 setting for GPIO        */
	PF4_UART2_TXD    = (0x02), /*!< GPF_MFP1 PF4 setting for UART2_TXD   */
	PF4_EBI_AD0      = (0x03), /*!< GPF_MFP1 PF4 setting for EBI_AD0     */
	PF4_UART2_nRTS   = (0x04), /*!< GPF_MFP1 PF4 setting for UART2_nRTS  */
	PF4_EPWM0_CH1    = (0x07), /*!< GPF_MFP1 PF4 setting for EPWM0_CH1   */
	PF4_BPWM0_CH5    = (0x08), /*!< GPF_MFP1 PF4 setting for BPWM0_CH5   */
	PF4_X32_OUT      = (0x0a), /*!< GPF_MFP1 PF4 setting for X32_OUT     */
	PF4_EADC1_ST     = (0x0b), /*!< GPF_MFP1 PF4 setting for EADC1_ST    */
	PF4_I2C4_SDA     = (0x0c), /*!< GPF_MFP1 PF4 setting for I2C4_SDA    */
	PF4_EQEI2_B      = (0x0d), /*!< GPF_MFP1 PF4 setting for EQEI2_B     */
	PF4_SPI5_MISO    = (0x13), /*!< GPF_MFP1 PF4 setting for SPI5_MISO (0xM460xGCAE only), */
	PF4_BMC11        = (0x14), /*!< GPF_MFP1 PF4 setting for BMC11     (0xM460xGCAE only), */

	/* PF.5 MFP */
	PF5_GPIO         = (0x00), /*!< GPF_MFP1 PF5 setting for GPIO        */
	PF5_UART2_RXD    = (0x02), /*!< GPF_MFP1 PF5 setting for UART2_RXD   */
	PF5_EBI_AD1      = (0x03), /*!< GPF_MFP1 PF5 setting for EBI_AD1     */
	PF5_UART2_nCTS   = (0x04), /*!< GPF_MFP1 PF5 setting for UART2_nCTS  */
	PF5_EPWM0_CH0    = (0x07), /*!< GPF_MFP1 PF5 setting for EPWM0_CH0   */
	PF5_BPWM0_CH4    = (0x08), /*!< GPF_MFP1 PF5 setting for BPWM0_CH4   */
	PF5_EPWM0_SYNC_OUT = (0x09), /*!< GPF_MFP1 PF5 setting for EPWM0_SYNC_OUT*/
	PF5_X32_IN       = (0x0a), /*!< GPF_MFP1 PF5 setting for X32_IN      */
	PF5_EADC0_ST     = (0x0b), /*!< GPF_MFP1 PF5 setting for EADC0_ST    */
	PF5_I2C4_SCL     = (0x0c), /*!< GPF_MFP1 PF5 setting for I2C4_SCL    */
	PF5_EQEI2_A      = (0x0d), /*!< GPF_MFP1 PF5 setting for EQEI2_A     */
	PF5_SPI5_MOSI    = (0x13), /*!< GPF_MFP1 PF5 setting for SPI5_MOSI (0xM460xGCAE only), */
	PF5_BMC10        = (0x14), /*!< GPF_MFP1 PF5 setting for BMC10     (0xM460xGCAE only), */

	/* PF.6 MFP */
	PF6_GPIO         = (0x00), /*!< GPF_MFP1 PF6 setting for GPIO        */
	PF6_EBI_ADR19    = (0x02), /*!< GPF_MFP1 PF6 setting for EBI_ADR19   */
	PF6_SC0_CLK      = (0x03), /*!< GPF_MFP1 PF6 setting for SC0_CLK     */
	PF6_I2S0_LRCK    = (0x04), /*!< GPF_MFP1 PF6 setting for I2S0_LRCK   */
	PF6_SPI0_MOSI    = (0x05), /*!< GPF_MFP1 PF6 setting for SPI0_MOSI   */
	PF6_UART4_RXD    = (0x06), /*!< GPF_MFP1 PF6 setting for UART4_RXD   */
	PF6_EBI_nCS0     = (0x07), /*!< GPF_MFP1 PF6 setting for EBI_nCS0    */
	PF6_CAN2_RXD     = (0x08), /*!< GPF_MFP1 PF6 setting for CAN2_RXD    */
	PF6_SPI3_I2SMCLK = (0x09), /*!< GPF_MFP1 PF6 setting for SPI3_I2SMCLK*/
	PF6_TAMPER0      = (0x0a), /*!< GPF_MFP1 PF6 setting for TAMPER0     */
	PF6_EQEI2_INDEX  = (0x0d), /*!< GPF_MFP1 PF6 setting for EQEI2_INDEX */
	PF6_TRACE_SWO    = (0x0e), /*!< GPF_MFP1 PF6 setting for TRACE_SWO   */
	PF6_SPI5_CLK     = (0x13), /*!< GPF_MFP1 PF6 setting for SPI5_CLK (0xM460xGCAE only), */

	/* PF.7 MFP */
	PF7_GPIO         = (0x00), /*!< GPF_MFP1 PF7 setting for GPIO        */
	PF7_EBI_ADR18    = (0x02), /*!< GPF_MFP1 PF7 setting for EBI_ADR18   */
	PF7_SC0_DAT      = (0x03), /*!< GPF_MFP1 PF7 setting for SC0_DAT     */
	PF7_I2S0_DO      = (0x04), /*!< GPF_MFP1 PF7 setting for I2S0_DO     */
	PF7_SPI0_MISO    = (0x05), /*!< GPF_MFP1 PF7 setting for SPI0_MISO   */
	PF7_UART4_TXD    = (0x06), /*!< GPF_MFP1 PF7 setting for UART4_TXD   */
	PF7_CCAP_DATA0   = (0x07), /*!< GPF_MFP1 PF7 setting for CCAP_DATA0  */
	PF7_CAN2_TXD     = (0x08), /*!< GPF_MFP1 PF7 setting for CAN2_TXD    */
	PF7_TAMPER1      = (0x0a), /*!< GPF_MFP1 PF7 setting for TAMPER1     */
	PF7_SPI5_SS      = (0x13), /*!< GPF_MFP1 PF7 setting for SPI5_SS (0xM460xGCAE only), */

	/* PF.8 MFP */
	PF8_GPIO         = (0x00), /*!< GPF_MFP2 PF8 setting for GPIO        */
	PF8_EBI_ADR17    = (0x02), /*!< GPF_MFP2 PF8 setting for EBI_ADR17   */
	PF8_SC0_RST      = (0x03), /*!< GPF_MFP2 PF8 setting for SC0_RST     */
	PF8_I2S0_DI      = (0x04), /*!< GPF_MFP2 PF8 setting for I2S0_DI     */
	PF8_SPI0_CLK     = (0x05), /*!< GPF_MFP2 PF8 setting for SPI0_CLK    */
	PF8_UART5_nCTS   = (0x06), /*!< GPF_MFP2 PF8 setting for UART5_nCTS  */
	PF8_CCAP_DATA1   = (0x07), /*!< GPF_MFP2 PF8 setting for CCAP_DATA1  */
	PF8_CAN1_RXD     = (0x08), /*!< GPF_MFP2 PF8 setting for CAN1_RXD    */
	PF8_TAMPER2      = (0x0a), /*!< GPF_MFP2 PF8 setting for TAMPER2     */
	PF8_UART9_RXD    = (0x0b), /*!< GPF_MFP2 PF8 setting for UART9_RXD   */

	/* PF.9 MFP */
	PF9_GPIO         = (0x00), /*!< GPF_MFP2 PF9 setting for GPIO        */
	PF9_EBI_ADR16    = (0x02), /*!< GPF_MFP2 PF9 setting for EBI_ADR16   */
	PF9_SC0_PWR      = (0x03), /*!< GPF_MFP2 PF9 setting for SC0_PWR     */
	PF9_I2S0_MCLK    = (0x04), /*!< GPF_MFP2 PF9 setting for I2S0_MCLK   */
	PF9_SPI0_SS      = (0x05), /*!< GPF_MFP2 PF9 setting for SPI0_SS     */
	PF9_UART5_nRTS   = (0x06), /*!< GPF_MFP2 PF9 setting for UART5_nRTS  */
	PF9_CCAP_DATA2   = (0x07), /*!< GPF_MFP2 PF9 setting for CCAP_DATA2  */
	PF9_CAN1_TXD     = (0x08), /*!< GPF_MFP2 PF9 setting for CAN1_TXD    */
	PF9_TAMPER3      = (0x0a), /*!< GPF_MFP2 PF9 setting for TAMPER3     */
	PF9_UART9_TXD    = (0x0b), /*!< GPF_MFP2 PF9 setting for UART9_TXD   */

	/* PF.10 MFP */
	PF10_GPIO        = (0x00),/*!< GPF_MFP2 PF10 setting for GPIO       */
	PF10_EBI_ADR15   = (0x02),/*!< GPF_MFP2 PF10 setting for EBI_ADR15  */
	PF10_SC0_nCD     = (0x03),/*!< GPF_MFP2 PF10 setting for SC0_nCD    */
	PF10_I2S0_BCLK   = (0x04),/*!< GPF_MFP2 PF10 setting for I2S0_BCLK  */
	PF10_SPI0_I2SMCLK = (0x05),/*!< GPF_MFP2 PF10 setting for SPI0_I2SMCLK*/
	PF10_UART5_RXD   = (0x06),/*!< GPF_MFP2 PF10 setting for UART5_RXD  */
	PF10_CCAP_DATA3  = (0x07),/*!< GPF_MFP2 PF10 setting for CCAP_DATA3 */
	PF10_CAN3_RXD    = (0x08),/*!< GPF_MFP2 PF10 setting for CAN3_RXD   */
	PF10_TAMPER4     = (0x0a),/*!< GPF_MFP2 PF10 setting for TAMPER4    */
	PF10_UART9_nRTS  = (0x0b),/*!< GPF_MFP2 PF10 setting for UART9_nRTS */

	/* PF.11 MFP */
	PF11_GPIO        = (0x00),/*!< GPF_MFP2 PF11 setting for GPIO       */
	PF11_EBI_ADR14   = (0x02),/*!< GPF_MFP2 PF11 setting for EBI_ADR14  */
	PF11_SPI2_MOSI   = (0x03),/*!< GPF_MFP2 PF11 setting for SPI2_MOSI  */
	PF11_UART5_TXD   = (0x06),/*!< GPF_MFP2 PF11 setting for UART5_TXD  */
	PF11_CCAP_DATA4  = (0x07),/*!< GPF_MFP2 PF11 setting for CCAP_DATA4 */
	PF11_CAN3_TXD    = (0x08),/*!< GPF_MFP2 PF11 setting for CAN3_TXD   */
	PF11_TAMPER5     = (0x0a),/*!< GPF_MFP2 PF11 setting for TAMPER5    */
	PF11_UART9_nCTS  = (0x0b),/*!< GPF_MFP2 PF11 setting for UART9_nCTS */
	PF11_TM3         = (0x0d),/*!< GPF_MFP2 PF11 setting for TM3        */

	/* PG.0 MFP */
	PG0_GPIO         = (0x00), /*!< GPG_MFP0 PG0 setting for GPIO        */
	PG0_EBI_ADR8     = (0x02), /*!< GPG_MFP0 PG0 setting for EBI_ADR8    */
	PG0_I2C0_SCL     = (0x04), /*!< GPG_MFP0 PG0 setting for I2C0_SCL    */
	PG0_I2C1_SMBAL   = (0x05), /*!< GPG_MFP0 PG0 setting for I2C1_SMBAL  */
	PG0_UART2_RXD    = (0x06), /*!< GPG_MFP0 PG0 setting for UART2_RXD   */
	PG0_CAN1_TXD     = (0x07), /*!< GPG_MFP0 PG0 setting for CAN1_TXD    */
	PG0_UART1_TXD    = (0x08), /*!< GPG_MFP0 PG0 setting for UART1_TXD   */
	PG0_I2C3_SCL     = (0x09), /*!< GPG_MFP0 PG0 setting for I2C3_SCL    */

	/* PG.1 MFP */
	PG1_GPIO         = (0x00), /*!< GPG_MFP0 PG1 setting for GPIO        */
	PG1_EBI_ADR9     = (0x02), /*!< GPG_MFP0 PG1 setting for EBI_ADR9    */
	PG1_SPI2_I2SMCLK = (0x03), /*!< GPG_MFP0 PG1 setting for SPI2_I2SMCLK*/
	PG1_I2C0_SDA     = (0x04), /*!< GPG_MFP0 PG1 setting for I2C0_SDA    */
	PG1_I2C1_SMBSUS  = (0x05), /*!< GPG_MFP0 PG1 setting for I2C1_SMBSUS */
	PG1_UART2_TXD    = (0x06), /*!< GPG_MFP0 PG1 setting for UART2_TXD   */
	PG1_CAN1_RXD     = (0x07), /*!< GPG_MFP0 PG1 setting for CAN1_RXD    */
	PG1_UART1_RXD    = (0x08), /*!< GPG_MFP0 PG1 setting for UART1_RXD   */
	PG1_I2C3_SDA     = (0x09), /*!< GPG_MFP0 PG1 setting for I2C3_SDA    */

	/* PG.2 MFP */
	PG2_GPIO         = (0x00), /*!< GPG_MFP0 PG2 setting for GPIO        */
	PG2_EBI_ADR11    = (0x02), /*!< GPG_MFP0 PG2 setting for EBI_ADR11   */
	PG2_SPI2_SS      = (0x03), /*!< GPG_MFP0 PG2 setting for SPI2_SS     */
	PG2_I2C0_SMBAL   = (0x04), /*!< GPG_MFP0 PG2 setting for I2C0_SMBAL  */
	PG2_I2C1_SCL     = (0x05), /*!< GPG_MFP0 PG2 setting for I2C1_SCL    */
	PG2_CCAP_DATA7   = (0x07), /*!< GPG_MFP0 PG2 setting for CCAP_DATA7  */
	PG2_I2C3_SMBAL   = (0x09), /*!< GPG_MFP0 PG2 setting for I2C3_SMBAL  */
	PG2_TM0          = (0x0d), /*!< GPG_MFP0 PG2 setting for TM0         */

	/* PG.3 MFP */
	PG3_GPIO         = (0x00), /*!< GPG_MFP0 PG3 setting for GPIO        */
	PG3_EBI_ADR12    = (0x02), /*!< GPG_MFP0 PG3 setting for EBI_ADR12   */
	PG3_SPI2_CLK     = (0x03), /*!< GPG_MFP0 PG3 setting for SPI2_CLK    */
	PG3_I2C0_SMBSUS  = (0x04), /*!< GPG_MFP0 PG3 setting for I2C0_SMBSUS */
	PG3_I2C1_SDA     = (0x05), /*!< GPG_MFP0 PG3 setting for I2C1_SDA    */
	PG3_CCAP_DATA6   = (0x07), /*!< GPG_MFP0 PG3 setting for CCAP_DATA6  */
	PG3_I2C3_SMBSUS  = (0x09), /*!< GPG_MFP0 PG3 setting for I2C3_SMBSUS */
	PG3_TM1          = (0x0d), /*!< GPG_MFP0 PG3 setting for TM1         */

	/* PG.4 MFP */
	PG4_GPIO         = (0x00), /*!< GPG_MFP1 PG4 setting for GPIO        */
	PG4_EBI_ADR13    = (0x02), /*!< GPG_MFP1 PG4 setting for EBI_ADR13   */
	PG4_SPI2_MISO    = (0x03), /*!< GPG_MFP1 PG4 setting for SPI2_MISO   */
	PG4_CCAP_DATA5   = (0x07), /*!< GPG_MFP1 PG4 setting for CCAP_DATA5  */
	PG4_TM2          = (0x0d), /*!< GPG_MFP1 PG4 setting for TM2         */

	/* PG.5 MFP */
	PG5_GPIO         = (0x00), /*!< GPG_MFP1 PG5 setting for GPIO        */
	PG5_EBI_nCS1     = (0x02), /*!< GPG_MFP1 PG5 setting for EBI_nCS1    */
	PG5_SPI3_SS      = (0x03), /*!< GPG_MFP1 PG5 setting for SPI3_SS     */
	PG5_SC1_PWR      = (0x04), /*!< GPG_MFP1 PG5 setting for SC1_PWR     */
	PG5_I2C3_SMBAL   = (0x08), /*!< GPG_MFP1 PG5 setting for I2C3_SMBAL  */
	PG5_I2S1_MCLK    = (0x0a), /*!< GPG_MFP1 PG5 setting for I2S1_MCLK   */
	PG5_EPWM0_CH3    = (0x0b), /*!< GPG_MFP1 PG5 setting for EPWM0_CH3   */

	/* PG.6 MFP */
	PG6_GPIO         = (0x00), /*!< GPG_MFP1 PG6 setting for GPIO        */
	PG6_EBI_nCS2     = (0x02), /*!< GPG_MFP1 PG6 setting for EBI_nCS2    */
	PG6_SPI3_CLK     = (0x03), /*!< GPG_MFP1 PG6 setting for SPI3_CLK    */
	PG6_SC1_RST      = (0x04), /*!< GPG_MFP1 PG6 setting for SC1_RST     */
	PG6_I2C3_SMBSUS  = (0x08), /*!< GPG_MFP1 PG6 setting for I2C3_SMBSUS */
	PG6_I2S1_DI      = (0x0a), /*!< GPG_MFP1 PG6 setting for I2S1_DI     */
	PG6_EPWM0_CH2    = (0x0b), /*!< GPG_MFP1 PG6 setting for EPWM0_CH2   */

	/* PG.7 MFP */
	PG7_GPIO         = (0x00), /*!< GPG_MFP1 PG7 setting for GPIO        */
	PG7_EBI_nWRL     = (0x02), /*!< GPG_MFP1 PG7 setting for EBI_nWRL    */
	PG7_SPI3_MISO    = (0x03), /*!< GPG_MFP1 PG7 setting for SPI3_MISO   */
	PG7_SC1_DAT      = (0x04), /*!< GPG_MFP1 PG7 setting for SC1_DAT     */
	PG7_I2C3_SCL     = (0x08), /*!< GPG_MFP1 PG7 setting for I2C3_SCL    */
	PG7_I2S1_DO      = (0x0a), /*!< GPG_MFP1 PG7 setting for I2S1_DO     */
	PG7_EPWM0_CH1    = (0x0b), /*!< GPG_MFP1 PG7 setting for EPWM0_CH1   */

	/* PG.8 MFP */
	PG8_GPIO         = (0x00), /*!< GPG_MFP2 PG8 setting for GPIO        */
	PG8_EBI_nWRH     = (0x02), /*!< GPG_MFP2 PG8 setting for EBI_nWRH    */
	PG8_SPI3_MOSI    = (0x03), /*!< GPG_MFP2 PG8 setting for SPI3_MOSI   */
	PG8_SC1_CLK      = (0x04), /*!< GPG_MFP2 PG8 setting for SC1_CLK     */
	PG8_I2C3_SDA     = (0x08), /*!< GPG_MFP2 PG8 setting for I2C3_SDA    */
	PG8_I2S1_LRCK    = (0x0a), /*!< GPG_MFP2 PG8 setting for I2S1_LRCK   */
	PG8_EPWM0_CH0    = (0x0b), /*!< GPG_MFP2 PG8 setting for EPWM0_CH0   */

	/* PG.9 MFP */
	PG9_GPIO         = (0x00), /*!< GPG_MFP2 PG9 setting for GPIO        */
	PG9_EBI_AD0      = (0x02), /*!< GPG_MFP2 PG9 setting for EBI_AD0     */
	PG9_SD1_DAT3     = (0x03), /*!< GPG_MFP2 PG9 setting for SD1_DAT3    */
	PG9_SPIM_D2      = (0x04), /*!< GPG_MFP2 PG9 setting for SPIM_D2     */
	PG9_QSPI1_MISO1  = (0x05), /*!< GPG_MFP2 PG9 setting for QSPI1_MISO1 */
	PG9_CCAP_PIXCLK  = (0x07), /*!< GPG_MFP2 PG9 setting for CCAP_PIXCLK */
	PG9_I2C4_SCL     = (0x08), /*!< GPG_MFP2 PG9 setting for I2C4_SCL    */
	PG9_ECAP2_IC0    = (0x09), /*!< GPG_MFP2 PG9 setting for ECAP2_IC0   */
	PG9_BPWM0_CH5    = (0x0c), /*!< GPG_MFP2 PG9 setting for BPWM0_CH5   */
	PG9_HBI_D4       = (0x10), /*!< GPG_MFP2 PG9 setting for HBI_D4      */
	PG9_SPI8_SS      = (0x13), /*!< GPG_MFP2 PG9 setting for SPI8_SS (0xM460xGCAE only), */
	PG9_BMC16        = (0x14), /*!< GPG_MFP2 PG9 setting for BMC16   (0xM460xGCAE only), */

	/* PG.10 MFP */
	PG10_GPIO        = (0x00),/*!< GPG_MFP2 PG10 setting for GPIO       */
	PG10_EBI_AD1     = (0x02),/*!< GPG_MFP2 PG10 setting for EBI_AD1    */
	PG10_SD1_DAT2    = (0x03),/*!< GPG_MFP2 PG10 setting for SD1_DAT2   */
	PG10_SPIM_D3     = (0x04),/*!< GPG_MFP2 PG10 setting for SPIM_D3    */
	PG10_QSPI1_MOSI1 = (0x05),/*!< GPG_MFP2 PG10 setting for QSPI1_MOSI1*/
	PG10_CCAP_SCLK   = (0x07),/*!< GPG_MFP2 PG10 setting for CCAP_SCLK  */
	PG10_I2C4_SDA    = (0x08),/*!< GPG_MFP2 PG10 setting for I2C4_SDA   */
	PG10_ECAP2_IC1   = (0x09),/*!< GPG_MFP2 PG10 setting for ECAP2_IC1  */
	PG10_BPWM0_CH4   = (0x0c),/*!< GPG_MFP2 PG10 setting for BPWM0_CH4  */
	PG10_HBI_D3      = (0x10),/*!< GPG_MFP2 PG10 setting for HBI_D3     */
	PG10_SPI8_CLK    = (0x13),/*!< GPG_MFP2 PG10 setting for SPI8_CLK (0xM460xGCAE only), */
	PG10_BMC17       = (0x14),/*!< GPG_MFP2 PG10 setting for BMC17    (0xM460xGCAE only), */

	/* PG.11 MFP */
	PG11_GPIO        = (0x00),/*!< GPG_MFP2 PG11 setting for GPIO       */
	PG11_EBI_AD2     = (0x02),/*!< GPG_MFP2 PG11 setting for EBI_AD2    */
	PG11_SD1_DAT1    = (0x03),/*!< GPG_MFP2 PG11 setting for SD1_DAT1   */
	PG11_SPIM_SS     = (0x04),/*!< GPG_MFP2 PG11 setting for SPIM_SS    */
	PG11_QSPI1_SS    = (0x05),/*!< GPG_MFP2 PG11 setting for QSPI1_SS   */
	PG11_UART7_TXD   = (0x06),/*!< GPG_MFP2 PG11 setting for UART7_TXD  */
	PG11_CCAP_SFIELD = (0x07),/*!< GPG_MFP2 PG11 setting for CCAP_SFIELD*/
	PG11_I2C4_SMBAL  = (0x08),/*!< GPG_MFP2 PG11 setting for I2C4_SMBAL */
	PG11_ECAP2_IC2   = (0x09),/*!< GPG_MFP2 PG11 setting for ECAP2_IC2  */
	PG11_BPWM0_CH3   = (0x0c),/*!< GPG_MFP2 PG11 setting for BPWM0_CH3  */
	PG11_HBI_D0      = (0x10),/*!< GPG_MFP2 PG11 setting for HBI_D0     */
	PG11_SPI8_MOSI   = (0x13),/*!< GPG_MFP2 PG11 setting for SPI8_MOSI (0xM460xGCAE only), */
	PG11_BMC18       = (0x14),/*!< GPG_MFP2 PG11 setting for BMC18     (0xM460xGCAE only), */

	/* PG.12 MFP */
	PG12_GPIO        = (0x00),/*!< GPG_MFP3 PG12 setting for GPIO       */
	PG12_EBI_AD3     = (0x02),/*!< GPG_MFP3 PG12 setting for EBI_AD3    */
	PG12_SD1_DAT0    = (0x03),/*!< GPG_MFP3 PG12 setting for SD1_DAT0   */
	PG12_SPIM_CLK    = (0x04),/*!< GPG_MFP3 PG12 setting for SPIM_CLK   */
	PG12_QSPI1_CLK   = (0x05),/*!< GPG_MFP3 PG12 setting for QSPI1_CLK  */
	PG12_UART7_RXD   = (0x06),/*!< GPG_MFP3 PG12 setting for UART7_RXD  */
	PG12_CCAP_VSYNC  = (0x07),/*!< GPG_MFP3 PG12 setting for CCAP_VSYNC */
	PG12_I2C4_SMBSUS = (0x08),/*!< GPG_MFP3 PG12 setting for I2C4_SMBSUS*/
	PG12_BPWM0_CH2   = (0x0c),/*!< GPG_MFP3 PG12 setting for BPWM0_CH2  */
	PG12_HBI_D1      = (0x10),/*!< GPG_MFP3 PG12 setting for HBI_D1     */
	PG12_SPI8_MISO   = (0x13),/*!< GPG_MFP3 PG12 setting for SPI8_MISO (0xM460xGCAE only), */
	PG12_BMC19       = (0x14),/*!< GPG_MFP3 PG12 setting for BMC19     (0xM460xGCAE only), */

	/* PG.13 MFP */
	PG13_GPIO        = (0x00),/*!< GPG_MFP3 PG13 setting for GPIO       */
	PG13_EBI_AD4     = (0x02),/*!< GPG_MFP3 PG13 setting for EBI_AD4    */
	PG13_SD1_CMD     = (0x03),/*!< GPG_MFP3 PG13 setting for SD1_CMD    */
	PG13_SPIM_MISO   = (0x04),/*!< GPG_MFP3 PG13 setting for SPIM_MISO  */
	PG13_QSPI1_MISO0 = (0x05),/*!< GPG_MFP3 PG13 setting for QSPI1_MISO0*/
	PG13_UART6_TXD   = (0x06),/*!< GPG_MFP3 PG13 setting for UART6_TXD  */
	PG13_CCAP_HSYNC  = (0x07),/*!< GPG_MFP3 PG13 setting for CCAP_HSYNC */
	PG13_BPWM0_CH1   = (0x0c),/*!< GPG_MFP3 PG13 setting for BPWM0_CH1  */
	PG13_HBI_D5      = (0x10),/*!< GPG_MFP3 PG13 setting for HBI_D5     */

	/* PG.14 MFP */
	PG14_GPIO        = (0x00),/*!< GPG_MFP3 PG14 setting for GPIO       */
	PG14_EBI_AD5     = (0x02),/*!< GPG_MFP3 PG14 setting for EBI_AD5    */
	PG14_SD1_CLK     = (0x03),/*!< GPG_MFP3 PG14 setting for SD1_CLK    */
	PG14_SPIM_MOSI   = (0x04),/*!< GPG_MFP3 PG14 setting for SPIM_MOSI  */
	PG14_QSPI1_MOSI0 = (0x05),/*!< GPG_MFP3 PG14 setting for QSPI1_MOSI0*/
	PG14_UART6_RXD   = (0x06),/*!< GPG_MFP3 PG14 setting for UART6_RXD  */
	PG14_BPWM0_CH0   = (0x0c),/*!< GPG_MFP3 PG14 setting for BPWM0_CH0  */
	PG14_HBI_D6      = (0x10),/*!< GPG_MFP3 PG14 setting for HBI_D6     */

	/* PG.15 MFP */
	PG15_GPIO        = (0x00),/*!< GPG_MFP3 PG15 setting for GPIO       */
	PG15_SD1_nCD     = (0x03),/*!< GPG_MFP3 PG15 setting for SD1_nCD    */
	PG15_CLKO        = (0x0e),/*!< GPG_MFP3 PG15 setting for CLKO       */
	PG15_EADC0_ST    = (0x0f),/*!< GPG_MFP3 PG15 setting for EADC0_ST   */
	PG15_HBI_D7      = (0x10),/*!< GPG_MFP3 PG15 setting for HBI_D7     */
	PG15_QSPI1_MISO1 = (0x13),/*!< GPG_MFP3 PG15 setting for QSPI1_MISO1*/

	/* PH.0 MFP */
	PH0_GPIO         = (0x00), /*!< GPH_MFP0 PH0 setting for GPIO        */
	PH0_EBI_ADR7     = (0x02), /*!< GPH_MFP0 PH0 setting for EBI_ADR7    */
	PH0_UART5_TXD    = (0x04), /*!< GPH_MFP0 PH0 setting for UART5_TXD   */
	PH0_TM0_EXT      = (0x0d), /*!< GPH_MFP0 PH0 setting for TM0_EXT     */

	/* PH.1 MFP */
	PH1_GPIO         = (0x00), /*!< GPH_MFP0 PH1 setting for GPIO        */
	PH1_EBI_ADR6     = (0x02), /*!< GPH_MFP0 PH1 setting for EBI_ADR6    */
	PH1_UART5_RXD    = (0x04), /*!< GPH_MFP0 PH1 setting for UART5_RXD   */
	PH1_TM1_EXT      = (0x0d), /*!< GPH_MFP0 PH1 setting for TM1_EXT     */

	/* PH.2 MFP */
	PH2_GPIO         = (0x00), /*!< GPH_MFP0 PH2 setting for GPIO        */
	PH2_EBI_ADR5     = (0x02), /*!< GPH_MFP0 PH2 setting for EBI_ADR5    */
	PH2_UART5_nRTS   = (0x04), /*!< GPH_MFP0 PH2 setting for UART5_nRTS  */
	PH2_UART4_TXD    = (0x05), /*!< GPH_MFP0 PH2 setting for UART4_TXD   */
	PH2_I2C0_SCL     = (0x06), /*!< GPH_MFP0 PH2 setting for I2C0_SCL    */
	PH2_TM2_EXT      = (0x0d), /*!< GPH_MFP0 PH2 setting for TM2_EXT     */

	/* PH.3 MFP */
	PH3_GPIO         = (0x00), /*!< GPH_MFP0 PH3 setting for GPIO        */
	PH3_EBI_ADR4     = (0x02), /*!< GPH_MFP0 PH3 setting for EBI_ADR4    */
	PH3_SPI1_I2SMCLK = (0x03), /*!< GPH_MFP0 PH3 setting for SPI1_I2SMCLK*/
	PH3_UART5_nCTS   = (0x04), /*!< GPH_MFP0 PH3 setting for UART5_nCTS  */
	PH3_UART4_RXD    = (0x05), /*!< GPH_MFP0 PH3 setting for UART4_RXD   */
	PH3_I2C0_SDA     = (0x06), /*!< GPH_MFP0 PH3 setting for I2C0_SDA    */
	PH3_TM3_EXT      = (0x0d), /*!< GPH_MFP0 PH3 setting for TM3_EXT     */

	/* PH.4 MFP */
	PH4_GPIO         = (0x00), /*!< GPH_MFP1 PH4 setting for GPIO        */
	PH4_EBI_ADR3     = (0x02), /*!< GPH_MFP1 PH4 setting for EBI_ADR3    */
	PH4_SPI1_MISO    = (0x03), /*!< GPH_MFP1 PH4 setting for SPI1_MISO   */
	PH4_UART7_nRTS   = (0x04), /*!< GPH_MFP1 PH4 setting for UART7_nRTS  */
	PH4_UART6_TXD    = (0x05), /*!< GPH_MFP1 PH4 setting for UART6_TXD   */

	/* PH.5 MFP */
	PH5_GPIO         = (0x00), /*!< GPH_MFP1 PH5 setting for GPIO        */
	PH5_EBI_ADR2     = (0x02), /*!< GPH_MFP1 PH5 setting for EBI_ADR2    */
	PH5_SPI1_MOSI    = (0x03), /*!< GPH_MFP1 PH5 setting for SPI1_MOSI   */
	PH5_UART7_nCTS   = (0x04), /*!< GPH_MFP1 PH5 setting for UART7_nCTS  */
	PH5_UART6_RXD    = (0x05), /*!< GPH_MFP1 PH5 setting for UART6_RXD   */

	/* PH.6 MFP */
	PH6_GPIO         = (0x00), /*!< GPH_MFP1 PH6 setting for GPIO        */
	PH6_EBI_ADR1     = (0x02), /*!< GPH_MFP1 PH6 setting for EBI_ADR1    */
	PH6_SPI1_CLK     = (0x03), /*!< GPH_MFP1 PH6 setting for SPI1_CLK    */
	PH6_UART7_TXD    = (0x04), /*!< GPH_MFP1 PH6 setting for UART7_TXD   */
	PH6_UART9_nCTS   = (0x07), /*!< GPH_MFP1 PH6 setting for UART9_nCTS  */

	/* PH.7 MFP */
	PH7_GPIO         = (0x00), /*!< GPH_MFP1 PH7 setting for GPIO        */
	PH7_EBI_ADR0     = (0x02), /*!< GPH_MFP1 PH7 setting for EBI_ADR0    */
	PH7_SPI1_SS      = (0x03), /*!< GPH_MFP1 PH7 setting for SPI1_SS     */
	PH7_UART7_RXD    = (0x04), /*!< GPH_MFP1 PH7 setting for UART7_RXD   */
	PH7_UART9_nRTS   = (0x07), /*!< GPH_MFP1 PH7 setting for UART9_nRTS  */

	/* PH.8 MFP */
	PH8_GPIO         = (0x00), /*!< GPH_MFP2 PH8 setting for GPIO        */
	PH8_EBI_AD12     = (0x02), /*!< GPH_MFP2 PH8 setting for EBI_AD12    */
	PH8_QSPI0_CLK    = (0x03), /*!< GPH_MFP2 PH8 setting for QSPI0_CLK   */
	PH8_SC2_PWR      = (0x04), /*!< GPH_MFP2 PH8 setting for SC2_PWR     */
	PH8_I2S0_DI      = (0x05), /*!< GPH_MFP2 PH8 setting for I2S0_DI     */
	PH8_SPI1_CLK     = (0x06), /*!< GPH_MFP2 PH8 setting for SPI1_CLK    */
	PH8_UART3_nRTS   = (0x07), /*!< GPH_MFP2 PH8 setting for UART3_nRTS  */
	PH8_I2C1_SMBAL   = (0x08), /*!< GPH_MFP2 PH8 setting for I2C1_SMBAL  */
	PH8_I2C2_SCL     = (0x09), /*!< GPH_MFP2 PH8 setting for I2C2_SCL    */
	PH8_UART1_TXD    = (0x0a), /*!< GPH_MFP2 PH8 setting for UART1_TXD   */
	PH8_UART9_nCTS   = (0x0d), /*!< GPH_MFP2 PH8 setting for UART9_nCTS  */

	/* PH.9 MFP */
	PH9_GPIO         = (0x00), /*!< GPH_MFP2 PH9 setting for GPIO        */
	PH9_EBI_AD13     = (0x02), /*!< GPH_MFP2 PH9 setting for EBI_AD13    */
	PH9_QSPI0_SS     = (0x03), /*!< GPH_MFP2 PH9 setting for QSPI0_SS    */
	PH9_SC2_RST      = (0x04), /*!< GPH_MFP2 PH9 setting for SC2_RST     */
	PH9_I2S0_DO      = (0x05), /*!< GPH_MFP2 PH9 setting for I2S0_DO     */
	PH9_SPI1_SS      = (0x06), /*!< GPH_MFP2 PH9 setting for SPI1_SS     */
	PH9_UART3_nCTS   = (0x07), /*!< GPH_MFP2 PH9 setting for UART3_nCTS  */
	PH9_I2C1_SMBSUS  = (0x08), /*!< GPH_MFP2 PH9 setting for I2C1_SMBSUS */
	PH9_I2C2_SDA     = (0x09), /*!< GPH_MFP2 PH9 setting for I2C2_SDA    */
	PH9_UART1_RXD    = (0x0a), /*!< GPH_MFP2 PH9 setting for UART1_RXD   */
	PH9_UART9_nRTS   = (0x0d), /*!< GPH_MFP2 PH9 setting for UART9_nRTS  */

	/* PH.10 MFP */
	PH10_GPIO        = (0x00),/*!< GPH_MFP2 PH10 setting for GPIO       */
	PH10_EBI_AD14    = (0x02),/*!< GPH_MFP2 PH10 setting for EBI_AD14   */
	PH10_QSPI0_MISO1 = (0x03),/*!< GPH_MFP2 PH10 setting for QSPI0_MISO1*/
	PH10_SC2_nCD     = (0x04),/*!< GPH_MFP2 PH10 setting for SC2_nCD    */
	PH10_I2S0_LRCK   = (0x05),/*!< GPH_MFP2 PH10 setting for I2S0_LRCK  */
	PH10_SPI1_I2SMCLK = (0x06),/*!< GPH_MFP2 PH10 setting for SPI1_I2SMCLK*/
	PH10_UART4_TXD   = (0x07),/*!< GPH_MFP2 PH10 setting for UART4_TXD  */
	PH10_UART0_TXD   = (0x08),/*!< GPH_MFP2 PH10 setting for UART0_TXD  */
	PH10_UART9_TXD   = (0x0d),/*!< GPH_MFP2 PH10 setting for UART9_TXD  */

	/* PH.11 MFP */
	PH11_GPIO        = (0x00),/*!< GPH_MFP2 PH11 setting for GPIO       */
	PH11_EBI_AD15    = (0x02),/*!< GPH_MFP2 PH11 setting for EBI_AD15   */
	PH11_QSPI0_MOSI1 = (0x03),/*!< GPH_MFP2 PH11 setting for QSPI0_MOSI1*/
	PH11_UART4_RXD   = (0x07),/*!< GPH_MFP2 PH11 setting for UART4_RXD  */
	PH11_UART0_RXD   = (0x08),/*!< GPH_MFP2 PH11 setting for UART0_RXD  */
	PH11_EPWM0_CH5   = (0x0b),/*!< GPH_MFP2 PH11 setting for EPWM0_CH5  */
	PH11_UART9_RXD   = (0x0d),/*!< GPH_MFP2 PH11 setting for UART9_RXD  */

	/* PH.12 MFP */
	PH12_GPIO        = (0x00),/*!< GPH_MFP3 PH12 setting for GPIO       */
	PH12_EBI_AD0     = (0x02),/*!< GPH_MFP3 PH12 setting for EBI_AD0    */
	PH12_UART9_TXD   = (0x03),/*!< GPH_MFP3 PH12 setting for UART9_TXD  */
	PH12_QSPI1_MISO1 = (0x06),/*!< GPH_MFP3 PH12 setting for QSPI1_MISO1*/
	PH12_CCAP_PIXCLK = (0x07),/*!< GPH_MFP3 PH12 setting for CCAP_PIXCLK*/
	PH12_CAN3_TXD    = (0x0a),/*!< GPH_MFP3 PH12 setting for CAN3_TXD   */
	PH12_HBI_nCK     = (0x10),/*!< GPH_MFP3 PH12 setting for HBI_nCK    */

	/* PH.13 MFP */
	PH13_GPIO        = (0x00),/*!< GPH_MFP3 PH13 setting for GPIO       */
	PH13_EBI_AD1     = (0x02),/*!< GPH_MFP3 PH13 setting for EBI_AD1    */
	PH13_UART9_RXD   = (0x03),/*!< GPH_MFP3 PH13 setting for UART9_RXD  */
	PH13_QSPI1_MOSI1 = (0x06),/*!< GPH_MFP3 PH13 setting for QSPI1_MOSI1*/
	PH13_CCAP_SCLK   = (0x07),/*!< GPH_MFP3 PH13 setting for CCAP_SCLK  */
	PH13_CAN3_RXD    = (0x0a),/*!< GPH_MFP3 PH13 setting for CAN3_RXD   */
	PH13_HBI_CK      = (0x10),/*!< GPH_MFP3 PH13 setting for HBI_CK     */

	/* PH.14 MFP */
	PH14_GPIO        = (0x00),/*!< GPH_MFP3 PH14 setting for GPIO       */
	PH14_EBI_AD2     = (0x02),/*!< GPH_MFP3 PH14 setting for EBI_AD2    */
	PH14_QSPI1_SS    = (0x06),/*!< GPH_MFP3 PH14 setting for QSPI1_SS   */
	PH14_CCAP_SFIELD = (0x07),/*!< GPH_MFP3 PH14 setting for CCAP_SFIELD*/
	PH14_HBI_RWDS    = (0x10),/*!< GPH_MFP3 PH14 setting for HBI_RWDS   */

	/* PH.15 MFP */
	PH15_GPIO        = (0x00),/*!< GPH_MFP3 PH15 setting for GPIO       */
	PH15_EBI_AD3     = (0x02),/*!< GPH_MFP3 PH15 setting for EBI_AD3    */
	PH15_QSPI1_CLK   = (0x06),/*!< GPH_MFP3 PH15 setting for QSPI1_CLK  */
	PH15_CCAP_VSYNC  = (0x07),/*!< GPH_MFP3 PH15 setting for CCAP_VSYNC */
	PH15_HBI_D4      = (0x10),/*!< GPH_MFP3 PH15 setting for HBI_D4     */

	/* PI.6 MFP */
	PI6_GPIO         = (0x00), /*!< GPI_MFP1 PI6 setting for GPIO        */
	PI6_SC1_nCD      = (0x05), /*!< GPI_MFP1 PI6 setting for SC1_nCD     */
	PI6_I2S0_BCLK    = (0x06), /*!< GPI_MFP1 PI6 setting for I2S0_BCLK   */
	PI6_SPI1_I2SMCLK = (0x07), /*!< GPI_MFP1 PI6 setting for SPI1_I2SMCLK*/
	PI6_UART2_TXD    = (0x08), /*!< GPI_MFP1 PI6 setting for UART2_TXD   */
	PI6_I2C1_SCL     = (0x09), /*!< GPI_MFP1 PI6 setting for I2C1_SCL    */
	PI6_CAN3_TXD     = (0x0d), /*!< GPI_MFP1 PI6 setting for CAN3_TXD    */
	PI6_USB_VBUS_ST  = (0x0f), /*!< GPI_MFP1 PI6 setting for USB_VBUS_ST */

	/* PI.7 MFP */
	PI7_GPIO         = (0x00), /*!< GPI_MFP1 PI7 setting for GPIO        */
	PI7_SC1_PWR      = (0x05), /*!< GPI_MFP1 PI7 setting for SC1_PWR     */
	PI7_I2S0_MCLK    = (0x06), /*!< GPI_MFP1 PI7 setting for I2S0_MCLK   */
	PI7_SPI1_MISO    = (0x07), /*!< GPI_MFP1 PI7 setting for SPI1_MISO   */
	PI7_UART2_RXD    = (0x08), /*!< GPI_MFP1 PI7 setting for UART2_RXD   */
	PI7_I2C1_SDA     = (0x09), /*!< GPI_MFP1 PI7 setting for I2C1_SDA    */
	PI7_CAN3_RXD     = (0x0d), /*!< GPI_MFP1 PI7 setting for CAN3_RXD    */
	PI7_USB_VBUS_EN  = (0x0f), /*!< GPI_MFP1 PI7 setting for USB_VBUS_EN */

	/* PI.8 MFP */
	PI8_GPIO         = (0x00), /*!< GPI_MFP2 PI8 setting for GPIO        */
	PI8_SC1_RST      = (0x05), /*!< GPI_MFP2 PI8 setting for SC1_RST     */
	PI8_I2S0_DI      = (0x06), /*!< GPI_MFP2 PI8 setting for I2S0_DI     */
	PI8_SPI1_MOSI    = (0x07), /*!< GPI_MFP2 PI8 setting for SPI1_MOSI   */
	PI8_UART2_nRTS   = (0x08), /*!< GPI_MFP2 PI8 setting for UART2_nRTS  */
	PI8_I2C0_SMBAL   = (0x09), /*!< GPI_MFP2 PI8 setting for I2C0_SMBAL  */
	PI8_CAN2_TXD     = (0x0d), /*!< GPI_MFP2 PI8 setting for CAN2_TXD    */

	/* PI.9 MFP */
	PI9_GPIO         = (0x00), /*!< GPI_MFP2 PI9 setting for GPIO        */
	PI9_SC1_DAT      = (0x05), /*!< GPI_MFP2 PI9 setting for SC1_DAT     */
	PI9_I2S0_DO      = (0x06), /*!< GPI_MFP2 PI9 setting for I2S0_DO     */
	PI9_SPI1_CLK     = (0x07), /*!< GPI_MFP2 PI9 setting for SPI1_CLK    */
	PI9_UART2_nCTS   = (0x08), /*!< GPI_MFP2 PI9 setting for UART2_nCTS  */
	PI9_I2C0_SMBSUS  = (0x09), /*!< GPI_MFP2 PI9 setting for I2C0_SMBSUS */
	PI9_CAN2_RXD     = (0x0d), /*!< GPI_MFP2 PI9 setting for CAN2_RXD    */

	/* PI.10 MFP */
	PI10_GPIO        = (0x00),/*!< GPI_MFP2 PI10 setting for GPIO       */
	PI10_SC1_CLK     = (0x05),/*!< GPI_MFP2 PI10 setting for SC1_CLK    */
	PI10_I2S0_LRCK   = (0x06),/*!< GPI_MFP2 PI10 setting for I2S0_LRCK  */
	PI10_SPI1_SS     = (0x07),/*!< GPI_MFP2 PI10 setting for SPI1_SS    */
	PI10_UART2_TXD   = (0x08),/*!< GPI_MFP2 PI10 setting for UART2_TXD  */
	PI10_I2C0_SCL    = (0x09),/*!< GPI_MFP2 PI10 setting for I2C0_SCL   */
	PI10_CAN3_TXD    = (0x0d),/*!< GPI_MFP2 PI10 setting for CAN3_TXD   */

	/* PI.11 MFP */
	PI11_GPIO        = (0x00),/*!< GPI_MFP2 PI11 setting for GPIO       */
	PI11_UART2_RXD   = (0x08),/*!< GPI_MFP2 PI11 setting for UART2_RXD  */
	PI11_I2C0_SDA    = (0x09),/*!< GPI_MFP2 PI11 setting for I2C0_SDA   */
	PI11_CAN3_RXD    = (0x0d),/*!< GPI_MFP2 PI11 setting for CAN3_RXD   */

	/* PI.12 MFP */
	PI12_GPIO        = (0x00),/*!< GPI_MFP3 PI12 setting for GPIO       */
	PI12_SPIM_SS     = (0x03),/*!< GPI_MFP3 PI12 setting for SPIM_SS    */
	PI12_QSPI0_MISO1 = (0x04),/*!< GPI_MFP3 PI12 setting for QSPI0_MISO1*/
	PI12_CAN0_TXD    = (0x0a),/*!< GPI_MFP3 PI12 setting for CAN0_TXD   */
	PI12_UART4_TXD   = (0x0b),/*!< GPI_MFP3 PI12 setting for UART4_TXD  */
	PI12_EPWM1_CH0   = (0x0c),/*!< GPI_MFP3 PI12 setting for EPWM1_CH0  */
	PI12_I2C3_SMBAL  = (0x0f),/*!< GPI_MFP3 PI12 setting for I2C3_SMBAL */

	/* PI.13 MFP */
	PI13_GPIO        = (0x00),/*!< GPI_MFP3 PI13 setting for GPIO       */
	PI13_SPIM_MISO   = (0x03),/*!< GPI_MFP3 PI13 setting for SPIM_MISO  */
	PI13_QSPI0_MOSI1 = (0x04),/*!< GPI_MFP3 PI13 setting for QSPI0_MOSI1*/
	PI13_CAN0_RXD    = (0x0a),/*!< GPI_MFP3 PI13 setting for CAN0_RXD   */
	PI13_UART4_RXD   = (0x0b),/*!< GPI_MFP3 PI13 setting for UART4_RXD  */
	PI13_EPWM1_CH1   = (0x0c),/*!< GPI_MFP3 PI13 setting for EPWM1_CH1  */
	PI13_I2C3_SMBSUS = (0x0f),/*!< GPI_MFP3 PI13 setting for I2C3_SMBSUS*/

	/* PI.14 MFP */
	PI14_GPIO        = (0x00),/*!< GPI_MFP3 PI14 setting for GPIO       */
	PI14_SPIM_D2     = (0x03),/*!< GPI_MFP3 PI14 setting for SPIM_D2    */
	PI14_QSPI0_SS    = (0x04),/*!< GPI_MFP3 PI14 setting for QSPI0_SS   */
	PI14_UART8_nCTS  = (0x07),/*!< GPI_MFP3 PI14 setting for UART8_nCTS */
	PI14_CAN1_TXD    = (0x0a),/*!< GPI_MFP3 PI14 setting for CAN1_TXD   */
	PI14_UART3_TXD   = (0x0b),/*!< GPI_MFP3 PI14 setting for UART3_TXD  */
	PI14_EPWM1_CH2   = (0x0c),/*!< GPI_MFP3 PI14 setting for EPWM1_CH2  */
	PI14_I2C3_SCL    = (0x0f),/*!< GPI_MFP3 PI14 setting for I2C3_SCL   */

	/* PI.15 MFP */
	PI15_GPIO        = (0x00),/*!< GPI_MFP3 PI15 setting for GPIO       */
	PI15_SPIM_D3     = (0x03),/*!< GPI_MFP3 PI15 setting for SPIM_D3    */
	PI15_QSPI0_CLK   = (0x04),/*!< GPI_MFP3 PI15 setting for QSPI0_CLK  */
	PI15_UART8_nRTS  = (0x07),/*!< GPI_MFP3 PI15 setting for UART8_nRTS */
	PI15_CAN1_RXD    = (0x0a),/*!< GPI_MFP3 PI15 setting for CAN1_RXD   */
	PI15_UART3_RXD   = (0x0b),/*!< GPI_MFP3 PI15 setting for UART3_RXD  */
	PI15_EPWM1_CH3   = (0x0c),/*!< GPI_MFP3 PI15 setting for EPWM1_CH3  */
	PI15_I2C3_SDA    = (0x0f),/*!< GPI_MFP3 PI15 setting for I2C3_SDA   */

	/* PJ.0 MFP */
	PJ0_GPIO         = (0x00), /*!< GPJ_MFP0 PJ0 setting for GPIO        */
	PJ0_SPIM_CLK     = (0x03), /*!< GPJ_MFP0 PJ0 setting for SPIM_CLK    */
	PJ0_QSPI0_MISO0  = (0x04), /*!< GPJ_MFP0 PJ0 setting for QSPI0_MISO0 */
	PJ0_UART8_TXD    = (0x07), /*!< GPJ_MFP0 PJ0 setting for UART8_TXD   */
	PJ0_CAN2_TXD     = (0x0a), /*!< GPJ_MFP0 PJ0 setting for CAN2_TXD    */
	PJ0_EPWM1_CH4    = (0x0c), /*!< GPJ_MFP0 PJ0 setting for EPWM1_CH4   */

	/* PJ.1 MFP */
	PJ1_GPIO         = (0x00), /*!< GPJ_MFP0 PJ1 setting for GPIO        */
	PJ1_SPIM_MOSI    = (0x03), /*!< GPJ_MFP0 PJ1 setting for SPIM_MOSI   */
	PJ1_QSPI0_MOSI0  = (0x04), /*!< GPJ_MFP0 PJ1 setting for QSPI0_MOSI0 */
	PJ1_UART8_RXD    = (0x07), /*!< GPJ_MFP0 PJ1 setting for UART8_RXD   */
	PJ1_CAN2_RXD     = (0x0a), /*!< GPJ_MFP0 PJ1 setting for CAN2_RXD    */
	PJ1_EPWM1_CH5    = (0x0c), /*!< GPJ_MFP0 PJ1 setting for EPWM1_CH5   */

	/* PJ.2 MFP */
	PJ2_GPIO         = (0x00), /*!< GPJ_MFP0 PJ2 setting for GPIO        */
	PJ2_EBI_AD5      = (0x02), /*!< GPJ_MFP0 PJ2 setting for EBI_AD5     */
	PJ2_UART8_nCTS   = (0x03), /*!< GPJ_MFP0 PJ2 setting for UART8_nCTS  */
	PJ2_QSPI1_SS     = (0x06), /*!< GPJ_MFP0 PJ2 setting for QSPI1_SS    */
	PJ2_CCAP_DATA5   = (0x07), /*!< GPJ_MFP0 PJ2 setting for CCAP_DATA5  */
	PJ2_CAN0_TXD     = (0x0a), /*!< GPJ_MFP0 PJ2 setting for CAN0_TXD    */
	PJ2_HBI_nRESET   = (0x10), /*!< GPJ_MFP0 PJ2 setting for HBI_nRESET  */

	/* PJ.3 MFP */
	PJ3_GPIO         = (0x00), /*!< GPJ_MFP0 PJ3 setting for GPIO        */
	PJ3_EBI_AD4      = (0x02), /*!< GPJ_MFP0 PJ3 setting for EBI_AD4     */
	PJ3_UART8_nRTS   = (0x03), /*!< GPJ_MFP0 PJ3 setting for UART8_nRTS  */
	PJ3_QSPI1_CLK    = (0x06), /*!< GPJ_MFP0 PJ3 setting for QSPI1_CLK   */
	PJ3_CCAP_DATA4   = (0x07), /*!< GPJ_MFP0 PJ3 setting for CCAP_DATA4  */
	PJ3_CAN0_RXD     = (0x0a), /*!< GPJ_MFP0 PJ3 setting for CAN0_RXD    */
	PJ3_HBI_D3       = (0x10), /*!< GPJ_MFP0 PJ3 setting for HBI_D3      */

	/* PJ.4 MFP */
	PJ4_GPIO         = (0x00), /*!< GPJ_MFP1 PJ4 setting for GPIO        */
	PJ4_EBI_AD3      = (0x02), /*!< GPJ_MFP1 PJ4 setting for EBI_AD3     */
	PJ4_UART8_TXD    = (0x03), /*!< GPJ_MFP1 PJ4 setting for UART8_TXD   */
	PJ4_QSPI1_MISO0  = (0x06), /*!< GPJ_MFP1 PJ4 setting for QSPI1_MISO0 */
	PJ4_CCAP_DATA3   = (0x07), /*!< GPJ_MFP1 PJ4 setting for CCAP_DATA3  */
	PJ4_CAN1_TXD     = (0x0a), /*!< GPJ_MFP1 PJ4 setting for CAN1_TXD    */
	PJ4_HBI_D2       = (0x10), /*!< GPJ_MFP1 PJ4 setting for HBI_D2      */

	/* PJ.5 MFP */
	PJ5_GPIO         = (0x00), /*!< GPJ_MFP1 PJ5 setting for GPIO        */
	PJ5_EBI_AD2      = (0x02), /*!< GPJ_MFP1 PJ5 setting for EBI_AD2     */
	PJ5_UART8_RXD    = (0x03), /*!< GPJ_MFP1 PJ5 setting for UART8_RXD   */
	PJ5_QSPI1_MOSI0  = (0x06), /*!< GPJ_MFP1 PJ5 setting for QSPI1_MOSI0 */
	PJ5_CCAP_DATA2   = (0x07), /*!< GPJ_MFP1 PJ5 setting for CCAP_DATA2  */
	PJ5_CAN1_RXD     = (0x0a), /*!< GPJ_MFP1 PJ5 setting for CAN1_RXD    */
	PJ5_HBI_D1       = (0x10), /*!< GPJ_MFP1 PJ5 setting for HBI_D1      */

	/* PJ.6 MFP */
	PJ6_GPIO         = (0x00), /*!< GPJ_MFP1 PJ6 setting for GPIO        */
	PJ6_EBI_AD1      = (0x02), /*!< GPJ_MFP1 PJ6 setting for EBI_AD1     */
	PJ6_UART9_nCTS   = (0x03), /*!< GPJ_MFP1 PJ6 setting for UART9_nCTS  */
	PJ6_CCAP_DATA1   = (0x07), /*!< GPJ_MFP1 PJ6 setting for CCAP_DATA1  */
	PJ6_CAN2_TXD     = (0x0a), /*!< GPJ_MFP1 PJ6 setting for CAN2_TXD    */
	PJ6_HBI_D0       = (0x10), /*!< GPJ_MFP1 PJ6 setting for HBI_D0      */

	/* PJ.7 MFP */
	PJ7_GPIO         = (0x00), /*!< GPJ_MFP1 PJ7 setting for GPIO        */
	PJ7_EBI_AD0      = (0x02), /*!< GPJ_MFP1 PJ7 setting for EBI_AD0     */
	PJ7_UART9_nRTS   = (0x03), /*!< GPJ_MFP1 PJ7 setting for UART9_nRTS  */
	PJ7_CCAP_DATA0   = (0x07), /*!< GPJ_MFP1 PJ7 setting for CCAP_DATA0  */
	PJ7_CAN2_RXD     = (0x0a), /*!< GPJ_MFP1 PJ7 setting for CAN2_RXD    */
	PJ7_HBI_nCS      = (0x10), /*!< GPJ_MFP1 PJ7 setting for HBI_nCS     */

	/* PJ.8 MFP */
	PJ8_GPIO         = (0x00), /*!< GPJ_MFP2 PJ8 setting for GPIO        */
	PJ8_EBI_nRD      = (0x02), /*!< GPJ_MFP2 PJ8 setting for EBI_nRD     */
	PJ8_SD1_DAT3     = (0x03), /*!< GPJ_MFP2 PJ8 setting for SD1_DAT3    */
	PJ8_SPIM_SS      = (0x04), /*!< GPJ_MFP2 PJ8 setting for SPIM_SS     */
	PJ8_UART7_TXD    = (0x06), /*!< GPJ_MFP2 PJ8 setting for UART7_TXD   */
	PJ8_CAN2_TXD     = (0x0b), /*!< GPJ_MFP2 PJ8 setting for CAN2_TXD    */
	PJ8_BPWM0_CH5    = (0x0c), /*!< GPJ_MFP2 PJ8 setting for BPWM0_CH5   */

	/* PJ.9 MFP */
	PJ9_GPIO         = (0x00), /*!< GPJ_MFP2 PJ9 setting for GPIO        */
	PJ9_EBI_nWR      = (0x02), /*!< GPJ_MFP2 PJ9 setting for EBI_nWR     */
	PJ9_SD1_DAT2     = (0x03), /*!< GPJ_MFP2 PJ9 setting for SD1_DAT2    */
	PJ9_SPIM_MISO    = (0x04), /*!< GPJ_MFP2 PJ9 setting for SPIM_MISO   */
	PJ9_UART7_RXD    = (0x06), /*!< GPJ_MFP2 PJ9 setting for UART7_RXD   */
	PJ9_CAN2_RXD     = (0x0b), /*!< GPJ_MFP2 PJ9 setting for CAN2_RXD    */
	PJ9_BPWM0_CH4    = (0x0c), /*!< GPJ_MFP2 PJ9 setting for BPWM0_CH4   */

	/* PJ.10 MFP */
	PJ10_GPIO        = (0x00),/*!< GPJ_MFP2 PJ10 setting for GPIO       */
	PJ10_EBI_MCLK    = (0x02),/*!< GPJ_MFP2 PJ10 setting for EBI_MCLK   */
	PJ10_SD1_DAT1    = (0x03),/*!< GPJ_MFP2 PJ10 setting for SD1_DAT1   */
	PJ10_SPIM_D2     = (0x04),/*!< GPJ_MFP2 PJ10 setting for SPIM_D2    */
	PJ10_UART6_TXD   = (0x06),/*!< GPJ_MFP2 PJ10 setting for UART6_TXD  */
	PJ10_I2C4_SCL    = (0x08),/*!< GPJ_MFP2 PJ10 setting for I2C4_SCL   */
	PJ10_ECAP2_IC0   = (0x09),/*!< GPJ_MFP2 PJ10 setting for ECAP2_IC0  */
	PJ10_CAN0_TXD    = (0x0b),/*!< GPJ_MFP2 PJ10 setting for CAN0_TXD   */
	PJ10_BPWM0_CH3   = (0x0c),/*!< GPJ_MFP2 PJ10 setting for BPWM0_CH3  */

	/* PJ.11 MFP */
	PJ11_GPIO        = (0x00),/*!< GPJ_MFP2 PJ11 setting for GPIO       */
	PJ11_EBI_ALE     = (0x02),/*!< GPJ_MFP2 PJ11 setting for EBI_ALE    */
	PJ11_SD1_DAT0    = (0x03),/*!< GPJ_MFP2 PJ11 setting for SD1_DAT0   */
	PJ11_SPIM_D3     = (0x04),/*!< GPJ_MFP2 PJ11 setting for SPIM_D3    */
	PJ11_UART6_RXD   = (0x06),/*!< GPJ_MFP2 PJ11 setting for UART6_RXD  */
	PJ11_I2C4_SDA    = (0x08),/*!< GPJ_MFP2 PJ11 setting for I2C4_SDA   */
	PJ11_ECAP2_IC1   = (0x09),/*!< GPJ_MFP2 PJ11 setting for ECAP2_IC1  */
	PJ11_CAN0_RXD    = (0x0b),/*!< GPJ_MFP2 PJ11 setting for CAN0_RXD   */
	PJ11_BPWM0_CH2   = (0x0c),/*!< GPJ_MFP2 PJ11 setting for BPWM0_CH2  */

	/* PJ.12 MFP */
	PJ12_GPIO        = (0x00),/*!< GPJ_MFP3 PJ12 setting for GPIO       */
	PJ12_EBI_nCS0    = (0x02),/*!< GPJ_MFP3 PJ12 setting for EBI_nCS0   */
	PJ12_SD1_CMD     = (0x03),/*!< GPJ_MFP3 PJ12 setting for SD1_CMD    */
	PJ12_SPIM_CLK    = (0x04),/*!< GPJ_MFP3 PJ12 setting for SPIM_CLK   */
	PJ12_I2C4_SMBAL  = (0x08),/*!< GPJ_MFP3 PJ12 setting for I2C4_SMBAL */
	PJ12_ECAP2_IC2   = (0x09),/*!< GPJ_MFP3 PJ12 setting for ECAP2_IC2  */
	PJ12_CAN1_TXD    = (0x0b),/*!< GPJ_MFP3 PJ12 setting for CAN1_TXD   */
	PJ12_BPWM0_CH1   = (0x0c),/*!< GPJ_MFP3 PJ12 setting for BPWM0_CH1  */
	PJ12_HSUSB_VBUS_ST = (0x0f),/*!< GPJ_MFP3 PJ12 setting for HSUSB_VBUS_ST*/

	/* PJ.13 MFP */
	PJ13_GPIO        = (0x00),/*!< GPJ_MFP3 PJ13 setting for GPIO       */
	PJ13_SD1_CLK     = (0x03),/*!< GPJ_MFP3 PJ13 setting for SD1_CLK    */
	PJ13_SPIM_MOSI   = (0x04),/*!< GPJ_MFP3 PJ13 setting for SPIM_MOSI  */
	PJ13_I2C4_SMBSUS = (0x08),/*!< GPJ_MFP3 PJ13 setting for I2C4_SMBSUS*/
	PJ13_CAN1_RXD    = (0x0b),/*!< GPJ_MFP3 PJ13 setting for CAN1_RXD   */
	PJ13_BPWM0_CH0   = (0x0c),/*!< GPJ_MFP3 PJ13 setting for BPWM0_CH0  */
	PJ13_HSUSB_VBUS_EN = (0x0f),/*!< GPJ_MFP3 PJ13 setting for HSUSB_VBUS_EN*/
}altFunc_t;


