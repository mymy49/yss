/****************************************************************************
 * @file     sys.h
 * @version  V1.10
 * @brief    M251 series SYS driver source file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright = (C), 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

 #if defined(__M251KG6AE__)
#define PA_EXIST
#define PB_EXIST
#define PC_EXIST
#define PD_EXIST
#define PE_EXIST
#define PF_EXIST
#elif defined(__M251FC2AE__) || defined(__M251ZD2AE__)
#define PA_EXIST
#define PB_EXIST
#define PF_EXIST
 #endif

 typedef enum
{	
/* PA.0 MFP */
	PA0_GPIO         = (0x00UL), /*!< GPA_MFPL PA0 setting for GPIO        */
	PA0_QSPI0_MOSI0  = (0x03UL), /*!< GPA_MFPL PA0 setting for QSPI0_MOSI0 */
	PA0_SPI0_MOSI    = (0x04UL), /*!< GPA_MFPL PA0 setting for SPI0_MOSI   */
	PA0_TK_TK6       = (0x05UL), /*!< GPA_MFPL PA0 setting for TK_TK6      */
	PA0_SC0_CLK      = (0x06UL), /*!< GPA_MFPL PA0 setting for SC0_CLK     */
	PA0_UART0_RXD    = (0x07UL), /*!< GPA_MFPL PA0 setting for UART0_RXD   */
	PA0_UART1_nRTS   = (0x08UL), /*!< GPA_MFPL PA0 setting for UART1_nRTS  */
	PA0_PSIO0_CH7    = (0x0aUL), /*!< GPA_MFPL PA0 setting for PSIO0_CH7   */
	PA0_USCI2_DAT1   = (0x0bUL), /*!< GPA_MFPL PA0 setting for USCI2_DAT1  */
	PA0_BPWM0_CH0    = (0x0cUL), /*!< GPA_MFPL PA0 setting for BPWM0_CH0   */
	PA0_PWM0_CH5     = (0x0dUL), /*!< GPA_MFPL PA0 setting for PWM0_CH5    */
	PA0_DAC0_ST      = (0x0fUL), /*!< GPA_MFPL PA0 setting for DAC0_ST     */

/* PA.1 MFP */
	PA1_GPIO         = (0x00UL), /*!< GPA_MFPL PA1 setting for GPIO        */
	PA1_QSPI0_MISO0  = (0x03UL), /*!< GPA_MFPL PA1 setting for QSPI0_MISO0 */
	PA1_SPI0_MISO    = (0x04UL), /*!< GPA_MFPL PA1 setting for SPI0_MISO   */
	PA1_TK_TK5       = (0x05UL), /*!< GPA_MFPL PA1 setting for TK_TK5      */
	PA1_SC0_DAT      = (0x06UL), /*!< GPA_MFPL PA1 setting for SC0_DAT     */
	PA1_UART0_TXD    = (0x07UL), /*!< GPA_MFPL PA1 setting for UART0_TXD   */
	PA1_UART1_nCTS   = (0x08UL), /*!< GPA_MFPL PA1 setting for UART1_nCTS  */
	PA1_PSIO0_CH6    = (0x0aUL), /*!< GPA_MFPL PA1 setting for PSIO0_CH6   */
	PA1_USCI2_DAT0   = (0x0bUL), /*!< GPA_MFPL PA1 setting for USCI2_DAT0  */
	PA1_BPWM0_CH1    = (0x0cUL), /*!< GPA_MFPL PA1 setting for BPWM0_CH1   */
	PA1_PWM0_CH4     = (0x0dUL), /*!< GPA_MFPL PA1 setting for PWM0_CH4    */
	PA1_DAC1_ST      = (0x0fUL), /*!< GPA_MFPL PA1 setting for DAC1_ST     */


/* PA.2 MFP */
	PA2_GPIO         = (0x00UL), /*!< GPA_MFPL PA2 setting for GPIO        */
	PA2_QSPI0_CLK    = (0x03UL), /*!< GPA_MFPL PA2 setting for QSPI0_CLK   */
	PA2_SPI0_CLK     = (0x04UL), /*!< GPA_MFPL PA2 setting for SPI0_CLK    */
	PA2_TK_TK4       = (0x05UL), /*!< GPA_MFPL PA2 setting for TK_TK4      */
	PA2_SC0_RST      = (0x06UL), /*!< GPA_MFPL PA2 setting for SC0_RST     */
	PA2_I2C0_SMBSUS  = (0x07UL), /*!< GPA_MFPL PA2 setting for I2C0_SMBSUS */
	PA2_UART1_RXD    = (0x08UL), /*!< GPA_MFPL PA2 setting for UART1_RXD   */
	PA2_I2C1_SDA     = (0x09UL), /*!< GPA_MFPL PA2 setting for I2C1_SDA    */
	PA2_PSIO0_CH5    = (0x0aUL), /*!< GPA_MFPL PA2 setting for PSIO0_CH5   */
	PA2_USCI2_CLK    = (0x0bUL), /*!< GPA_MFPL PA2 setting for USCI2_CLK   */
	PA2_BPWM0_CH2    = (0x0cUL), /*!< GPA_MFPL PA2 setting for BPWM0_CH2   */
	PA2_PWM0_CH3     = (0x0dUL), /*!< GPA_MFPL PA2 setting for PWM0_CH3    */

/* PA.3 MFP */
	PA3_GPIO         = (0x00UL), /*!< GPA_MFPL PA3 setting for GPIO        */
	PA3_QSPI0_SS     = (0x03UL), /*!< GPA_MFPL PA3 setting for QSPI0_SS    */
	PA3_SPI0_SS      = (0x04UL), /*!< GPA_MFPL PA3 setting for SPI0_SS     */
	PA3_TK_TK3       = (0x05UL), /*!< GPA_MFPL PA3 setting for TK_TK3      */
	PA3_SC0_PWR      = (0x06UL), /*!< GPA_MFPL PA3 setting for SC0_PWR     */
	PA3_I2C0_SMBAL   = (0x07UL), /*!< GPA_MFPL PA3 setting for I2C0_SMBAL  */
	PA3_UART1_TXD    = (0x08UL), /*!< GPA_MFPL PA3 setting for UART1_TXD   */
	PA3_I2C1_SCL     = (0x09UL), /*!< GPA_MFPL PA3 setting for I2C1_SCL    */
	PA3_PSIO0_CH4    = (0x0aUL), /*!< GPA_MFPL PA3 setting for PSIO0_CH4   */
	PA3_USCI2_CTL0   = (0x0bUL), /*!< GPA_MFPL PA3 setting for USCI2_CTL0  */
	PA3_BPWM0_CH3    = (0x0cUL), /*!< GPA_MFPL PA3 setting for BPWM0_CH3   */
	PA3_PWM0_CH2     = (0x0dUL), /*!< GPA_MFPL PA3 setting for PWM0_CH2    */
	PA3_CLKO         = (0x0eUL), /*!< GPA_MFPL PA3 setting for CLKO        */
	PA3_PWM1_BRAKE1  = (0x0fUL), /*!< GPA_MFPL PA3 setting for PWM1_BRAKE1 */

/* PA.4 MFP */
	PA4_GPIO         = (0x00UL), /*!< GPA_MFPL PA4 setting for GPIO        */
	PA4_QSPI0_MOSI1  = (0x03UL), /*!< GPA_MFPL PA4 setting for QSPI0_MOSI1 */
	PA4_SPI0_I2SMCLK = (0x04UL), /*!< GPA_MFPL PA4 setting for SPI0_I2SMCLK*/
	PA4_TK_TK2       = (0x05UL), /*!< GPA_MFPL PA4 setting for TK_TK2      */
	PA4_SC0_nCD      = (0x06UL), /*!< GPA_MFPL PA4 setting for SC0_nCD     */
	PA4_UART0_nRTS   = (0x07UL), /*!< GPA_MFPL PA4 setting for UART0_nRTS  */
	PA4_UART0_RXD    = (0x08UL), /*!< GPA_MFPL PA4 setting for UART0_RXD   */
	PA4_I2C0_SDA     = (0x09UL), /*!< GPA_MFPL PA4 setting for I2C0_SDA    */
	PA4_USCI2_CTL1   = (0x0bUL), /*!< GPA_MFPL PA4 setting for USCI2_CTL1  */
	PA4_BPWM0_CH4    = (0x0cUL), /*!< GPA_MFPL PA4 setting for BPWM0_CH4   */
	PA4_PWM0_CH1     = (0x0dUL), /*!< GPA_MFPL PA4 setting for PWM0_CH1    */

/* PA.5 MFP */
	PA5_GPIO         = (0x00UL), /*!< GPA_MFPL PA5 setting for GPIO        */
	PA5_QSPI0_MISO1  = (0x03UL), /*!< GPA_MFPL PA5 setting for QSPI0_MISO1 */
	PA5_SPI1_I2SMCLK = (0x04UL), /*!< GPA_MFPL PA5 setting for SPI1_I2SMCLK*/
	PA5_TK_TK1       = (0x05UL), /*!< GPA_MFPL PA5 setting for TK_TK1      */
	PA5_UART0_nCTS   = (0x07UL), /*!< GPA_MFPL PA5 setting for UART0_nCTS  */
	PA5_UART0_TXD    = (0x08UL), /*!< GPA_MFPL PA5 setting for UART0_TXD   */
	PA5_I2C0_SCL     = (0x09UL), /*!< GPA_MFPL PA5 setting for I2C0_SCL    */
	PA5_BPWM0_CH5    = (0x0cUL), /*!< GPA_MFPL PA5 setting for BPWM0_CH5   */
	PA5_PWM0_CH0     = (0x0dUL), /*!< GPA_MFPL PA5 setting for PWM0_CH0    */

/* PA.6 MFP */
	PA6_GPIO         = (0x00UL), /*!< GPA_MFPL PA6 setting for GPIO        */
	PA6_EBI_AD6      = (0x02UL), /*!< GPA_MFPL PA6 setting for EBI_AD6     */
	PA6_SPI1_SS      = (0x04UL), /*!< GPA_MFPL PA6 setting for SPI1_SS     */
	PA6_LCD_SEG36    = (0x05UL), /*!< GPA_MFPL PA6 setting for LCD_SEG36   */
	PA6_TK_TK20      = (0x06UL), /*!< GPA_MFPL PA6 setting for TK_TK20     */
	PA6_UART0_RXD    = (0x07UL), /*!< GPA_MFPL PA6 setting for UART0_RXD   */
	PA6_I2C1_SDA     = (0x08UL), /*!< GPA_MFPL PA6 setting for I2C1_SDA    */
	PA6_PWM1_CH5     = (0x0bUL), /*!< GPA_MFPL PA6 setting for PWM1_CH5    */
	PA6_BPWM1_CH3    = (0x0cUL), /*!< GPA_MFPL PA6 setting for BPWM1_CH3   */
	PA6_ACMP1_WLAT   = (0x0dUL), /*!< GPA_MFPL PA6 setting for ACMP1_WLAT  */
	PA6_TM3          = (0x0eUL), /*!< GPA_MFPL PA6 setting for TM3         */
	PA6_INT0         = (0x0fUL), /*!< GPA_MFPL PA6 setting for INT0        */

/* PA.7 MFP */
	PA7_GPIO         = (0x00UL), /*!< GPA_MFPL PA7 setting for GPIO        */
	PA7_EBI_AD7      = (0x02UL), /*!< GPA_MFPL PA7 setting for EBI_AD7     */
	PA7_SPI1_CLK     = (0x04UL), /*!< GPA_MFPL PA7 setting for SPI1_CLK    */
	PA7_LCD_SEG37    = (0x05UL), /*!< GPA_MFPL PA7 setting for LCD_SEG37   */
	PA7_TK_TK19      = (0x06UL), /*!< GPA_MFPL PA7 setting for TK_TK19     */
	PA7_UART0_TXD    = (0x07UL), /*!< GPA_MFPL PA7 setting for UART0_TXD   */
	PA7_I2C1_SCL     = (0x08UL), /*!< GPA_MFPL PA7 setting for I2C1_SCL    */
	PA7_PWM1_CH4     = (0x0bUL), /*!< GPA_MFPL PA7 setting for PWM1_CH4    */
	PA7_BPWM1_CH2    = (0x0cUL), /*!< GPA_MFPL PA7 setting for BPWM1_CH2   */
	PA7_ACMP0_WLAT   = (0x0dUL), /*!< GPA_MFPL PA7 setting for ACMP0_WLAT  */
	PA7_TM2          = (0x0eUL), /*!< GPA_MFPL PA7 setting for TM2         */
	PA7_INT1         = (0x0fUL), /*!< GPA_MFPL PA7 setting for INT1        */

/* PA.8 MFP */
	PA8_GPIO         = (0x00UL), /*!< GPA_MFPH PA8 setting for GPIO        */
	PA8_DAC0_OUT     = (0x01UL), /*!< GPA_MFPH PA8 setting for DAC0_OUT    */
	PA8_EBI_ALE      = (0x02UL), /*!< GPA_MFPH PA8 setting for EBI_ALE     */
	PA8_USCI0_CTL1   = (0x06UL), /*!< GPA_MFPH PA8 setting for USCI0_CTL1  */
	PA8_UART1_RXD    = (0x07UL), /*!< GPA_MFPH PA8 setting for UART1_RXD   */
	PA8_BPWM0_CH3    = (0x09UL), /*!< GPA_MFPH PA8 setting for BPWM0_CH3   */
	PA8_TM3_EXT      = (0x0dUL), /*!< GPA_MFPH PA8 setting for TM3_EXT     */
	PA8_INT4         = (0x0fUL), /*!< GPA_MFPH PA8 setting for INT4        */

/* PA.9 MFP */
	PA9_GPIO         = (0x00UL), /*!< GPA_MFPH PA9 setting for GPIO        */
	PA9_DAC1_OUT     = (0x01UL), /*!< GPA_MFPH PA9 setting for DAC1_OUT    */
	PA9_EBI_MCLK     = (0x02UL), /*!< GPA_MFPH PA9 setting for EBI_MCLK    */
	PA9_USCI0_DAT1   = (0x06UL), /*!< GPA_MFPH PA9 setting for USCI0_DAT1  */
	PA9_UART1_TXD    = (0x07UL), /*!< GPA_MFPH PA9 setting for UART1_TXD   */
	PA9_BPWM0_CH2    = (0x09UL), /*!< GPA_MFPH PA9 setting for BPWM0_CH2   */
	PA9_TM2_EXT      = (0x0dUL), /*!< GPA_MFPH PA9 setting for TM2_EXT     */
	PA9_SWDH_DAT     = (0x0fUL), /*!< GPA_MFPH PA9 setting for SWDH_DAT    */

/* PA.10 MFP */
	PA10_GPIO        = (0x00UL),/*!< GPA_MFPH PA10 setting for GPIO       */
	PA10_ACMP1_P0    = (0x01UL),/*!< GPA_MFPH PA10 setting for ACMP1_P0   */
	PA10_EBI_nWR     = (0x02UL),/*!< GPA_MFPH PA10 setting for EBI_nWR    */
	PA10_USCI0_DAT0  = (0x06UL),/*!< GPA_MFPH PA10 setting for USCI0_DAT0 */
	PA10_BPWM0_CH1   = (0x09UL),/*!< GPA_MFPH PA10 setting for BPWM0_CH1  */
	PA10_TM1_EXT     = (0x0dUL),/*!< GPA_MFPH PA10 setting for TM1_EXT    */
	PA10_DAC0_ST     = (0x0eUL),/*!< GPA_MFPH PA10 setting for DAC0_ST    */
	PA10_SWDH_CLK    = (0x0fUL),/*!< GPA_MFPH PA10 setting for SWDH_CLK   */

/* PA.11 MFP */
	PA11_GPIO        = (0x00UL),/*!< GPA_MFPH PA11 setting for GPIO       */
	PA11_ACMP0_P0    = (0x01UL),/*!< GPA_MFPH PA11 setting for ACMP0_P0   */
	PA11_EBI_nRD     = (0x02UL),/*!< GPA_MFPH PA11 setting for EBI_nRD    */
	PA11_USCI0_CLK   = (0x06UL),/*!< GPA_MFPH PA11 setting for USCI0_CLK  */
	PA11_BPWM0_CH0   = (0x09UL),/*!< GPA_MFPH PA11 setting for BPWM0_CH0  */
	PA11_TM0_EXT     = (0x0dUL),/*!< GPA_MFPH PA11 setting for TM0_EXT    */
	PA11_DAC1_ST     = (0x0eUL),/*!< GPA_MFPH PA11 setting for DAC1_ST    */


/* PA.12 MFP */
	PA12_GPIO        = (0x00UL),/*!< GPA_MFPH PA12 setting for GPIO       */
	PA12_I2C1_SCL    = (0x04UL),/*!< GPA_MFPH PA12 setting for I2C1_SCL   */
	PA12_LCD_COM4    = (0x05UL),/*!< GPA_MFPH PA12 setting for LCD_COM4   */
	PA12_LCD_SEG20   = (0x05UL),/*!< GPA_MFPH PA12 setting for LCD_SEG20  */
	PA12_LCD_SEG47   = (0x05UL),/*!< GPA_MFPH PA12 setting for LCD_SEG47  */
	PA12_USCI2_DAT1  = (0x08UL),/*!< GPA_MFPH PA12 setting for USCI2_DAT1 */
	PA12_PSIO0_CH4   = (0x0aUL),/*!< GPA_MFPH PA12 setting for PSIO0_CH4  */
	PA12_BPWM1_CH2   = (0x0bUL),/*!< GPA_MFPH PA12 setting for BPWM1_CH2  */

/* PA.13 MFP */
	PA13_GPIO        = (0x00UL),/*!< GPA_MFPH PA13 setting for GPIO       */
	PA13_I2C1_SDA    = (0x04UL),/*!< GPA_MFPH PA13 setting for I2C1_SDA   */
	PA13_LCD_COM5    = (0x05UL),/*!< GPA_MFPH PA13 setting for LCD_COM5   */
	PA13_LCD_SEG19   = (0x05UL),/*!< GPA_MFPH PA13 setting for LCD_SEG19  */
	PA13_LCD_SEG46   = (0x05UL),/*!< GPA_MFPH PA13 setting for LCD_SEG46  */
	PA13_USCI2_DAT0  = (0x08UL),/*!< GPA_MFPH PA13 setting for USCI2_DAT0 */
	PA13_PSIO0_CH5   = (0x0aUL),/*!< GPA_MFPH PA13 setting for PSIO0_CH5  */
	PA13_BPWM1_CH3   = (0x0bUL),/*!< GPA_MFPH PA13 setting for BPWM1_CH3  */

/* PA.14 MFP */
	PA14_GPIO        = (0x00UL),/*!< GPA_MFPH PA14 setting for GPIO       */
	PA14_UART0_TXD   = (0x03UL),/*!< GPA_MFPH PA14 setting for UART0_TXD  */
	PA14_LCD_COM6    = (0x05UL),/*!< GPA_MFPH PA14 setting for LCD_COM6   */
	PA14_LCD_SEG18   = (0x05UL),/*!< GPA_MFPH PA14 setting for LCD_SEG18  */
	PA14_LCD_SEG45   = (0x05UL),/*!< GPA_MFPH PA14 setting for LCD_SEG45  */
	PA14_USCI2_CLK   = (0x08UL),/*!< GPA_MFPH PA14 setting for USCI2_CLK  */
	PA14_PSIO0_CH6   = (0x0aUL),/*!< GPA_MFPH PA14 setting for PSIO0_CH6  */
	PA14_BPWM1_CH4   = (0x0bUL),/*!< GPA_MFPH PA14 setting for BPWM1_CH4  */

/* PA.15 MFP */
	PA15_GPIO        = (0x00UL),/*!< GPA_MFPH PA15 setting for GPIO       */
	PA15_UART0_RXD   = (0x03UL),/*!< GPA_MFPH PA15 setting for UART0_RXD  */
	PA15_LCD_COM7    = (0x05UL),/*!< GPA_MFPH PA15 setting for LCD_COM7   */
	PA15_LCD_SEG17   = (0x05UL),/*!< GPA_MFPH PA15 setting for LCD_SEG17  */
	PA15_LCD_SEG44   = (0x05UL),/*!< GPA_MFPH PA15 setting for LCD_SEG44  */
	PA15_USCI2_CTL1  = (0x08UL),/*!< GPA_MFPH PA15 setting for USCI2_CTL1 */
	PA15_PSIO0_CH7   = (0x0aUL),/*!< GPA_MFPH PA15 setting for PSIO0_CH7  */
	PA15_BPWM1_CH5   = (0x0bUL),/*!< GPA_MFPH PA15 setting for BPWM1_CH5  */

/* PB.0 MFP */
	PB0_GPIO         = (0x00UL), /*!< GPB_MFPL PB0 setting for GPIO        */
	PB0_EADC0_CH0    = (0x01UL), /*!< GPB_MFPL PB0 setting for EADC0_CH0   */
	PB0_OPA0_P       = (0x01UL), /*!< GPB_MFPL PB0 setting for OPA0_P      */
	PB0_EBI_ADR9     = (0x02UL), /*!< GPB_MFPL PB0 setting for EBI_ADR9    */
	PB0_LCD_SEG0     = (0x05UL), /*!< GPB_MFPL PB0 setting for LCD_SEG0    */
	PB0_UART2_RXD    = (0x07UL), /*!< GPB_MFPL PB0 setting for UART2_RXD   */
	PB0_SPI0_I2SMCLK = (0x08UL), /*!< GPB_MFPL PB0 setting for SPI0_I2SMCLK*/
	PB0_I2C1_SDA     = (0x09UL), /*!< GPB_MFPL PB0 setting for I2C1_SDA    */
	PB0_QSPI0_MOSI1  = (0x0aUL), /*!< GPB_MFPL PB0 setting for QSPI0_MOSI1 */
	PB0_PWM0_CH5     = (0x0bUL), /*!< GPB_MFPL PB0 setting for PWM0_CH5    */
	PB0_PWM1_CH5     = (0x0cUL), /*!< GPB_MFPL PB0 setting for PWM1_CH5    */
	PB0_PWM0_BRAKE1  = (0x0dUL), /*!< GPB_MFPL PB0 setting for PWM0_BRAKE1 */

/* PB.1 MFP */
	PB1_GPIO         = (0x00UL), /*!< GPB_MFPL PB1 setting for GPIO        */
	PB1_EADC0_CH1    = (0x01UL), /*!< GPB_MFPL PB1 setting for EADC0_CH1   */
	PB1_OPA0_N       = (0x01UL), /*!< GPB_MFPL PB1 setting for OPA0_N      */
	PB1_EBI_ADR8     = (0x02UL), /*!< GPB_MFPL PB1 setting for EBI_ADR8    */
	PB1_LCD_SEG1     = (0x05UL), /*!< GPB_MFPL PB1 setting for LCD_SEG1    */
	PB1_SPI1_I2SMCLK = (0x06UL), /*!< GPB_MFPL PB1 setting for SPI1_I2SMCLK*/
	PB1_UART2_TXD    = (0x07UL), /*!< GPB_MFPL PB1 setting for UART2_TXD   */
	PB1_USCI1_CLK    = (0x08UL), /*!< GPB_MFPL PB1 setting for USCI1_CLK   */
	PB1_I2C1_SCL     = (0x09UL), /*!< GPB_MFPL PB1 setting for I2C1_SCL    */
	PB1_QSPI0_MISO1  = (0x0aUL), /*!< GPB_MFPL PB1 setting for QSPI0_MISO1 */
	PB1_PWM0_CH4     = (0x0bUL), /*!< GPB_MFPL PB1 setting for PWM0_CH4    */
	PB1_PWM1_CH4     = (0x0cUL), /*!< GPB_MFPL PB1 setting for PWM1_CH4    */
	PB1_PWM0_BRAKE0  = (0x0dUL), /*!< GPB_MFPL PB1 setting for PWM0_BRAKE0 */

/* PB.2 MFP */
	PB2_GPIO         = (0x00UL), /*!< GPB_MFPL PB2 setting for GPIO        */
	PB2_EADC0_CH2    = (0x01UL), /*!< GPB_MFPL PB2 setting for EADC0_CH2   */
	PB2_ACMP0_P1     = (0x01UL), /*!< GPB_MFPL PB2 setting for ACMP0_P1    */
	PB2_OPA0_O       = (0x01UL), /*!< GPB_MFPL PB2 setting for OPA0_O      */
	PB2_EBI_ADR3     = (0x02UL), /*!< GPB_MFPL PB2 setting for EBI_ADR3    */
	PB2_I2C1_SDA     = (0x04UL), /*!< GPB_MFPL PB2 setting for I2C1_SDA    */
	PB2_LCD_COM3     = (0x05UL), /*!< GPB_MFPL PB2 setting for LCD_COM3    */
	PB2_UART1_RXD    = (0x06UL), /*!< GPB_MFPL PB2 setting for UART1_RXD   */
	PB2_SPI1_SS      = (0x07UL), /*!< GPB_MFPL PB2 setting for SPI1_SS     */
	PB2_USCI1_DAT0   = (0x08UL), /*!< GPB_MFPL PB2 setting for USCI1_DAT0  */
	PB2_SC0_PWR      = (0x09UL), /*!< GPB_MFPL PB2 setting for SC0_PWR     */
	PB2_PWM0_CH3     = (0x0bUL), /*!< GPB_MFPL PB2 setting for PWM0_CH3    */
	PB2_PSIO0_CH7    = (0x0cUL), /*!< GPB_MFPL PB2 setting for PSIO0_CH7   */
	PB2_TM3          = (0x0eUL), /*!< GPB_MFPL PB2 setting for TM3         */
	PB2_INT3         = (0x0fUL), /*!< GPB_MFPL PB2 setting for INT3        */

/* PB.3 MFP */
	PB3_GPIO         = (0x00UL), /*!< GPB_MFPL PB3 setting for GPIO        */
	PB3_EADC0_CH3    = (0x01UL), /*!< GPB_MFPL PB3 setting for EADC0_CH3   */
	PB3_ACMP0_N      = (0x01UL), /*!< GPB_MFPL PB3 setting for ACMP0_N     */
	PB3_EBI_ADR2     = (0x02UL), /*!< GPB_MFPL PB3 setting for EBI_ADR2    */
	PB3_I2C1_SCL     = (0x04UL), /*!< GPB_MFPL PB3 setting for I2C1_SCL    */
	PB3_LCD_COM2     = (0x05UL), /*!< GPB_MFPL PB3 setting for LCD_COM2    */
	PB3_UART1_TXD    = (0x06UL), /*!< GPB_MFPL PB3 setting for UART1_TXD   */
	PB3_SPI1_CLK     = (0x07UL), /*!< GPB_MFPL PB3 setting for SPI1_CLK    */
	PB3_USCI1_DAT1   = (0x08UL), /*!< GPB_MFPL PB3 setting for USCI1_DAT1  */
	PB3_SC0_RST      = (0x09UL), /*!< GPB_MFPL PB3 setting for SC0_RST     */
	PB3_PWM0_CH2     = (0x0bUL), /*!< GPB_MFPL PB3 setting for PWM0_CH2    */
	PB3_PSIO0_CH6    = (0x0cUL), /*!< GPB_MFPL PB3 setting for PSIO0_CH6   */
	PB3_PWM0_BRAKE0  = (0x0dUL), /*!< GPB_MFPL PB2 setting for PWM0_BRAKE0 */
	PB3_TM2          = (0x0eUL), /*!< GPB_MFPL PB3 setting for TM2         */
	PB3_INT2         = (0x0fUL), /*!< GPB_MFPL PB3 setting for INT2        */

/* PB.4 MFP */
	PB4_GPIO         = (0x00UL), /*!< GPB_MFPL PB4 setting for GPIO        */
	PB4_EADC0_CH4    = (0x01UL), /*!< GPB_MFPL PB4 setting for EADC0_CH4   */
	PB4_ACMP1_P1     = (0x01UL), /*!< GPB_MFPL PB4 setting for ACMP1_P1    */
	PB4_EBI_ADR1     = (0x02UL), /*!< GPB_MFPL PB4 setting for EBI_ADR1    */
	PB4_LCD_COM1     = (0x05UL), /*!< GPB_MFPL PB4 setting for LCD_COM1    */
	PB4_I2C0_SDA     = (0x06UL), /*!< GPB_MFPL PB4 setting for I2C0_SDA    */
	PB4_SPI1_MOSI    = (0x07UL), /*!< GPB_MFPL PB4 setting for SPI1_MOSI   */
	PB4_USCI1_CTL1   = (0x08UL), /*!< GPB_MFPL PB4 setting for USCI1_CTL1  */
	PB4_SC0_DAT      = (0x09UL), /*!< GPB_MFPL PB4 setting for SC0_DAT     */
	PB4_PWM0_CH1     = (0x0bUL), /*!< GPB_MFPL PB4 setting for PWM0_CH1    */
	PB4_PSIO0_CH5    = (0x0cUL), /*!< GPB_MFPL PB4 setting for PSIO0_CH5   */
	PB4_UART2_RXD    = (0x0dUL), /*!< GPB_MFPL PB4 setting for UART2_RXD   */
	PB4_TM1          = (0x0eUL), /*!< GPB_MFPL PB4 setting for TM1         */
	PB4_INT1         = (0x0fUL), /*!< GPB_MFPL PB4 setting for INT1        */

/* PB.5 MFP */
	PB5_GPIO         = (0x00UL), /*!< GPB_MFPL PB5 setting for GPIO        */
	PB5_EADC0_CH5    = (0x01UL), /*!< GPB_MFPL PB5 setting for EADC0_CH5   */
	PB5_ACMP1_N      = (0x01UL), /*!< GPB_MFPL PB5 setting for ACMP1_N     */
	PB5_EBI_ADR0     = (0x02UL), /*!< GPB_MFPL PB5 setting for EBI_ADR0    */
	PB5_LCD_COM0     = (0x05UL), /*!< GPB_MFPL PB5 setting for LCD_COM0    */
	PB5_I2C0_SCL     = (0x06UL), /*!< GPB_MFPL PB5 setting for I2C0_SCL    */
	PB5_SPI1_MISO    = (0x07UL), /*!< GPB_MFPL PB5 setting for SPI1_MISO   */
	PB5_USCI1_CTL0   = (0x08UL), /*!< GPB_MFPL PB5 setting for USCI1_CTL0  */
	PB5_SC0_CLK      = (0x09UL), /*!< GPB_MFPL PB5 setting for SC0_CLK     */
	PB5_PWM0_CH0     = (0x0bUL), /*!< GPB_MFPL PB5 setting for PWM0_CH0    */
	PB5_PSIO0_CH4    = (0x0cUL), /*!< GPB_MFPL PB5 setting for PSIO0_CH4   */
	PB5_UART2_TXD    = (0x0dUL), /*!< GPB_MFPL PB5 setting for UART2_TXD   */
	PB5_TM0          = (0x0eUL), /*!< GPB_MFPL PB5 setting for TM0         */
	PB5_INT0         = (0x0fUL), /*!< GPB_MFPL PB5 setting for INT0        */

/* PB.6 MFP */
	PB6_GPIO         = (0x00UL), /*!< GPB_MFPL PB6 setting for GPIO        */
	PB6_EADC0_CH6    = (0x01UL), /*!< GPB_MFPL PB6 setting for EADC0_CH6   */
	PB6_EBI_nWRH     = (0x02UL), /*!< GPB_MFPL PB6 setting for EBI_nWRH    */
	PB6_USCI1_DAT1   = (0x04UL), /*!< GPB_MFPL PB6 setting for USCI1_DAT1  */
	PB6_UART1_RXD    = (0x06UL), /*!< GPB_MFPL PB6 setting for UART1_RXD   */
	PB6_EBI_nCS1     = (0x08UL), /*!< GPB_MFPL PB6 setting for EBI_nCS1    */
	PB6_LCD_SEG4     = (0x09UL), /*!< GPB_MFPL PB6 setting for LCD_SEG4    */
	PB6_BPWM1_CH5    = (0x0aUL), /*!< GPB_MFPL PB6 setting for BPWM1_CH5   */
	PB6_PWM1_BRAKE1  = (0x0bUL), /*!< GPB_MFPL PB6 setting for PWM1_BRAKE1 */
	PB6_PWM1_CH5     = (0x0cUL), /*!< GPB_MFPL PB6 setting for PWM1_CH5    */
	PB6_INT4         = (0x0dUL), /*!< GPB_MFPL PB6 setting for INT4        */
	PB6_ACMP1_O      = (0x0fUL), /*!< GPB_MFPL PB6 setting for ACMP1_O     */

/* PB.7 MFP */
	PB7_GPIO         = (0x00UL), /*!< GPB_MFPL PB7 setting for GPIO        */
	PB7_EADC0_CH7    = (0x01UL), /*!< GPB_MFPL PB7 setting for EADC0_CH7   */
	PB7_EBI_nWRL     = (0x02UL), /*!< GPB_MFPL PB7 setting for EBI_nWRL    */
	PB7_USCI1_DAT0   = (0x04UL), /*!< GPB_MFPL PB7 setting for USCI1_DAT0  */
	PB7_UART1_TXD    = (0x06UL), /*!< GPB_MFPL PB7 setting for UART1_TXD   */
	PB7_EBI_nCS0     = (0x08UL), /*!< GPB_MFPL PB7 setting for EBI_nCS0    */
	PB7_LCD_SEG5     = (0x09UL), /*!< GPB_MFPL PB7 setting for LCD_SEG5    */
	PB7_BPWM1_CH4    = (0x0aUL), /*!< GPB_MFPL PB7 setting for BPWM1_CH4   */
	PB7_PWM1_BRAKE0  = (0x0bUL), /*!< GPB_MFPL PB7 setting for PWM1_BRAKE0 */
	PB7_PWM1_CH4     = (0x0cUL), /*!< GPB_MFPL PB7 setting for PWM1_CH4    */
	PB7_INT5         = (0x0dUL), /*!< GPB_MFPL PB7 setting for INT5        */
	PB7_ACMP0_O      = (0x0fUL), /*!< GPB_MFPL PB7 setting for ACMP0_O     */

/* PB.8 MFP */
	PB8_GPIO         = (0x00UL), /*!< GPB_MFPH PB8 setting for GPIO        */
	PB8_EADC0_CH8    = (0x01UL), /*!< GPB_MFPH PB8 setting for EADC0_CH8   */
	PB8_EBI_ADR19    = (0x02UL), /*!< GPB_MFPH PB8 setting for EBI_ADR19   */
	PB8_USCI1_CLK    = (0x04UL), /*!< GPB_MFPH PB8 setting for USCI1_CLK   */
	PB8_UART0_RXD    = (0x05UL), /*!< GPB_MFPH PB8 setting for UART0_RXD   */
	PB8_UART1_nRTS   = (0x06UL), /*!< GPB_MFPH PB8 setting for UART1_nRTS  */
	PB8_I2C1_SMBSUS  = (0x07UL), /*!< GPB_MFPH PB8 setting for I2C1_SMBSUS */
	PB8_LCD_SEG6     = (0x08UL), /*!< GPB_MFPH PB8 setting for LCD_SEG6    */
	PB8_LCD_V3       = (0x08UL), /*!< GPB_MFPH PB8 setting for LCD_V3      */
	PB8_BPWM1_CH3    = (0x0aUL), /*!< GPB_MFPH PB8 setting for BPWM1_CH3   */

/* PB.9 MFP */
	PB9_GPIO         = (0x00UL), /*!< GPB_MFPH PB9 setting for GPIO        */
	PB9_EADC0_CH9    = (0x01UL), /*!< GPB_MFPH PB9 setting for EADC0_CH9   */
	PB9_EBI_ADR18    = (0x02UL), /*!< GPB_MFPH PB9 setting for EBI_ADR18   */
	PB9_USCI1_CTL1   = (0x04UL), /*!< GPB_MFPH PB9 setting for USCI1_CTL1  */
	PB9_UART0_TXD    = (0x05UL), /*!< GPB_MFPH PB9 setting for UART0_TXD   */
	PB9_UART1_nCTS   = (0x06UL), /*!< GPB_MFPH PB9 setting for UART1_nCTS  */
	PB9_I2C1_SMBAL   = (0x07UL), /*!< GPB_MFPH PB9 setting for I2C1_SMBAL  */
	PB9_LCD_SEG7     = (0x08UL), /*!< GPB_MFPH PB9 setting for LCD_SEG7    */
	PB9_LCD_V2       = (0x08UL), /*!< GPB_MFPH PB9 setting for LCD_V2      */
	PB9_BPWM1_CH2    = (0x0aUL), /*!< GPB_MFPH PB9 setting for BPWM1_CH2   */

/* PB.10 MFP */
	PB10_GPIO        = (0x00UL),/*!< GPB_MFPH PB10 setting for GPIO       */
	PB10_EADC0_CH10  = (0x01UL),/*!< GPB_MFPH PB10 setting for EADC0_CH10 */
	PB10_EBI_ADR17   = (0x02UL),/*!< GPB_MFPH PB10 setting for EBI_ADR17  */
	PB10_USCI1_CTL0  = (0x04UL),/*!< GPB_MFPH PB10 setting for USCI1_CTL0 */
	PB10_UART0_nRTS  = (0x05UL),/*!< GPB_MFPH PB10 setting for UART0_nRTS */
	PB10_I2C1_SDA    = (0x07UL),/*!< GPB_MFPH PB10 setting for I2C1_SDA   */
	PB10_LCD_SEG8    = (0x08UL),/*!< GPB_MFPH PB10 setting for LCD_SEG8   */
	PB10_LCD_V1      = (0x08UL),/*!< GPB_MFPH PB10 setting for LCD_V1     */
	PB10_BPWM1_CH1   = (0x0aUL),/*!< GPB_MFPH PB10 setting for BPWM1_CH1  */

/* PB.11 MFP */
	PB11_GPIO        = (0x00UL),/*!< GPB_MFPH PB11 setting for GPIO       */
	PB11_EADC0_CH11  = (0x01UL),/*!< GPB_MFPH PB11 setting for EADC0_CH11 */
	PB11_EBI_ADR16   = (0x02UL),/*!< GPB_MFPH PB11 setting for EBI_ADR16  */
	PB11_UART0_nCTS  = (0x05UL),/*!< GPB_MFPH PB11 setting for UART0_nCTS */
	PB11_I2C1_SCL    = (0x07UL),/*!< GPB_MFPH PB11 setting for I2C1_SCL   */
	PB11_LCD_SEG9    = (0x08UL),/*!< GPB_MFPH PB11 setting for LCD_SEG9   */
	PB11_SPI0_I2SMCLK = (0x09UL),/*!< GPB_MFPH PB11 setting for SPI0_I2SMCLK*/
	PB11_BPWM1_CH0   = (0x0aUL),/*!< GPB_MFPH PB11 setting for BPWM1_CH0  */

/* PB.12 MFP */
	PB12_GPIO        = (0x00UL),/*!< GPB_MFPH PB12 setting for GPIO       */
	PB12_EADC0_CH12  = (0x01UL),/*!< GPB_MFPH PB12 setting for EADC0_CH12 */
	PB12_DAC0_OUT    = (0x01UL),/*!< GPB_MFPH PB12 setting for DAC0_OUT   */
	PB12_ACMP0_P2    = (0x01UL),/*!< GPB_MFPH PB12 setting for ACMP0_P2   */
	PB12_ACMP1_P2    = (0x01UL),/*!< GPB_MFPH PB12 setting for ACMP1_P2   */
	PB12_EBI_AD15    = (0x02UL),/*!< GPB_MFPH PB12 setting for EBI_AD15   */
	PB12_SPI0_MOSI   = (0x04UL),/*!< GPB_MFPH PB12 setting for SPI0_MOSI  */
	PB12_USCI0_CLK   = (0x05UL),/*!< GPB_MFPH PB12 setting for USCI0_CLK  */
	PB12_UART0_RXD   = (0x06UL),/*!< GPB_MFPH PB12 setting for UART0_RXD  */
	PB12_UART3_nCTS  = (0x07UL),/*!< GPB_MFPH PB12 setting for UART3_nCTS */
	PB12_LCD_SEG10   = (0x08UL),/*!< GPB_MFPH PB12 setting for LCD_SEG10  */
	PB12_PSIO0_CH3   = (0x0aUL),/*!< GPB_MFPH PB12 setting for PSIO0_CH3  */
	PB12_PWM1_CH3    = (0x0bUL),/*!< GPB_MFPH PB12 setting for PWM1_CH3   */
	PB12_TM3_EXT     = (0x0dUL),/*!< GPB_MFPH PB12 setting for TM3_EXT    */

/* PB.13 MFP */
	PB13_GPIO        = (0x00UL),/*!< GPB_MFPH PB13 setting for GPIO       */
	PB13_EADC0_CH13  = (0x01UL),/*!< GPB_MFPH PB13 setting for EADC0_CH13 */
	PB13_ACMP0_P3    = (0x01UL),/*!< GPB_MFPH PB13 setting for ACMP0_P3   */
	PB13_ACMP1_P3    = (0x01UL),/*!< GPB_MFPH PB13 setting for ACMP1_P3   */
	PB13_DAC1_OUT    = (0x01UL),/*!< GPB_MFPH PB13 setting for DAC1_OUT   */
	PB13_EBI_AD14    = (0x02UL),/*!< GPB_MFPH PB13 setting for EBI_AD14   */
	PB13_SPI0_MISO   = (0x04UL),/*!< GPB_MFPH PB13 setting for SPI0_MISO  */
	PB13_USCI0_DAT0  = (0x05UL),/*!< GPB_MFPH PB13 setting for USCI0_DAT0 */
	PB13_UART0_TXD   = (0x06UL),/*!< GPB_MFPH PB13 setting for UART0_TXD  */
	PB13_UART3_nRTS  = (0x07UL),/*!< GPB_MFPH PB13 setting for UART3_nRTS */
	PB13_LCD_SEG11   = (0x08UL),/*!< GPB_MFPH PB13 setting for LCD_SEG11  */
	PB13_PSIO0_CH2   = (0x0aUL),/*!< GPB_MFPH PB13 setting for PSIO0_CH2  */
	PB13_PWM1_CH2    = (0x0bUL),/*!< GPB_MFPH PB13 setting for PWM1_CH2   */
	PB13_TM2_EXT     = (0x0dUL),/*!< GPB_MFPH PB13 setting for TM2_EXT    */

/* PB.14 MFP */
	PB14_GPIO        = (0x00UL),/*!< GPB_MFPH PB14 setting for GPIO       */
	PB14_EADC0_CH14  = (0x01UL),/*!< GPB_MFPH PB14 setting for EADC0_CH14 */
	PB14_EBI_AD13    = (0x02UL),/*!< GPB_MFPH PB14 setting for EBI_AD13   */
	PB14_SPI0_CLK    = (0x04UL),/*!< GPB_MFPH PB14 setting for SPI0_CLK   */
	PB14_USCI0_DAT1  = (0x05UL),/*!< GPB_MFPH PB14 setting for USCI0_DAT1 */
	PB14_UART0_nRTS  = (0x06UL),/*!< GPB_MFPH PB14 setting for UART0_nRTS */
	PB14_UART3_RXD   = (0x07UL),/*!< GPB_MFPH PB14 setting for UART3_RXD  */
	PB14_LCD_SEG12   = (0x08UL),/*!< GPB_MFPH PB14 setting for LCD_SEG12  */
	PB14_PSIO0_CH1   = (0x0aUL),/*!< GPB_MFPH PB14 setting for PSIO0_CH1  */
	PB14_PWM1_CH1    = (0x0bUL),/*!< GPB_MFPH PB14 setting for PWM1_CH1   */
	PB14_TM1_EXT     = (0x0dUL),/*!< GPB_MFPH PB14 setting for TM1_EXT    */
	PB14_CLKO        = (0x0eUL),/*!< GPB_MFPH PB14 setting for CLKO       */
	PB14_TK_SE       = (0x0fUL),/*!< GPB_MFPH PB14 setting for TK_SE      */

/* PB.15 MFP */
	PB15_GPIO        = (0x00UL),/*!< GPB_MFPH PB15 setting for GPIO       */
	PB15_EADC0_CH15  = (0x01UL),/*!< GPB_MFPH PB15 setting for EADC0_CH15 */
	PB15_EBI_AD12    = (0x02UL),/*!< GPB_MFPH PB15 setting for EBI_AD12   */
	PB15_SPI0_SS     = (0x04UL),/*!< GPB_MFPH PB15 setting for SPI0_SS    */
	PB15_USCI0_CTL1  = (0x05UL),/*!< GPB_MFPH PB15 setting for USCI0_CTL1 */
	PB15_UART0_nCTS  = (0x06UL),/*!< GPB_MFPH PB15 setting for UART0_nCTS */
	PB15_UART3_TXD   = (0x07UL),/*!< GPB_MFPH PB15 setting for UART3_TXD  */
	PB15_LCD_SEG13   = (0x08UL),/*!< GPB_MFPH PB15 setting for LCD_SEG13  */
	PB15_LCD_COM1    = (0x08UL),/*!< GPB_MFPH PB15 setting for LCD_COM1   */
	PB15_PSIO0_CH0   = (0x0aUL),/*!< GPB_MFPH PB15 setting for PSIO0_CH0  */
	PB15_PWM1_CH0    = (0x0bUL),/*!< GPB_MFPH PB15 setting for PWM1_CH0   */
	PB15_TM0_EXT     = (0x0dUL),/*!< GPB_MFPH PB15 setting for TM0_EXT    */
	PB15_PWM0_BRAKE1 = (0x0fUL),/*!< GPB_MFPH PB15 setting for PWM0_BRAKE1*/

/* PC.0 MFP */
	PC0_GPIO         = (0x00UL), /*!< GPC_MFPL PC0 setting for GPIO        */
	PC0_EBI_AD0      = (0x02UL), /*!< GPC_MFPL PC0 setting for EBI_AD0     */
	PC0_QSPI0_MOSI0  = (0x04UL), /*!< GPC_MFPL PC0 setting for QSPI0_MOSI0 */
	PC0_LCD_SEG26    = (0x05UL), /*!< GPC_MFPL PC0 setting for LCD_SEG26   */
	PC0_LCD_COM3     = (0x05UL), /*!< GPC_MFPL PC0 setting for LCD_COM3    */
	PC0_TK_TK25      = (0x06UL), /*!< GPC_MFPL PC0 setting for TK_TK25     */
	PC0_SPI1_SS      = (0x07UL), /*!< GPC_MFPL PC0 setting for SPI1_SS     */
	PC0_UART2_RXD    = (0x08UL), /*!< GPC_MFPL PC0 setting for UART2_RXD   */
	PC0_I2C0_SDA     = (0x09UL), /*!< GPC_MFPL PC0 setting for I2C0_SDA    */
	PC0_PWM1_CH5     = (0x0cUL), /*!< GPC_MFPL PC0 setting for PWM1_CH5    */
	PC0_USCI2_DAT1   = (0x0dUL), /*!< GPC_MFPL PC0 setting for USCI2_DAT1  */
	PC0_ACMP1_O      = (0x0eUL), /*!< GPC_MFPL PC0 setting for ACMP1_O     */

/* PC.1 MFP */
	PC1_GPIO         = (0x00UL), /*!< GPC_MFPL PC1 setting for GPIO        */
	PC1_EBI_AD1      = (0x02UL), /*!< GPC_MFPL PC1 setting for EBI_AD1     */
	PC1_QSPI0_MISO0  = (0x04UL), /*!< GPC_MFPL PC1 setting for QSPI0_MISO0 */
	PC1_LCD_SEG27    = (0x05UL), /*!< GPC_MFPL PC1 setting for LCD_SEG27   */
	PC1_LCD_COM2     = (0x05UL), /*!< GPC_MFPL PC1 setting for LCD_COM2    */
	PC1_TK_TK24      = (0x06UL), /*!< GPC_MFPL PC1 setting for TK_TK24     */
	PC1_SPI1_CLK     = (0x07UL), /*!< GPC_MFPL PC1 setting for SPI1_CLK    */
	PC1_UART2_TXD    = (0x08UL), /*!< GPC_MFPL PC1 setting for UART2_TXD   */
	PC1_I2C0_SCL     = (0x09UL), /*!< GPC_MFPL PC1 setting for I2C0_SCL    */
	PC1_PWM1_CH4     = (0x0cUL), /*!< GPC_MFPL PC1 setting for PWM1_CH4    */
	PC1_USCI2_DAT0   = (0x0dUL), /*!< GPC_MFPL PC1 setting for USCI2_DAT0  */
	PC1_ACMP0_O      = (0x0eUL), /*!< GPC_MFPL PC1 setting for ACMP0_O     */

/* PC.2 MFP */
	PC2_GPIO         = (0x00UL), /*!< GPC_MFPL PC2 setting for GPIO        */
	PC2_EBI_AD2      = (0x02UL), /*!< GPC_MFPL PC2 setting for EBI_AD2     */
	PC2_QSPI0_CLK    = (0x04UL), /*!< GPC_MFPL PC2 setting for QSPI0_CLK   */
	PC2_LCD_SEG28    = (0x05UL), /*!< GPC_MFPL PC2 setting for LCD_SEG28   */
	PC2_LCD_COM7     = (0x05UL), /*!< GPC_MFPL PC2 setting for LCD_COM7    */
	PC2_TK_TK12      = (0x06UL), /*!< GPC_MFPL PC2 setting for TK_TK12     */
	PC2_SPI1_MOSI    = (0x07UL), /*!< GPC_MFPL PC2 setting for SPI1_MOSI   */
	PC2_UART2_nCTS   = (0x08UL), /*!< GPC_MFPL PC2 setting for UART2_nCTS  */
	PC2_I2C0_SMBSUS  = (0x09UL), /*!< GPC_MFPL PC2 setting for I2C0_SMBSUS */
	PC2_UART3_RXD    = (0x0bUL), /*!< GPC_MFPL PC2 setting for UART3_RXD   */
	PC2_PWM1_CH3     = (0x0cUL), /*!< GPC_MFPL PC2 setting for PWM1_CH3    */
	PC2_USCI2_CLK    = (0x0dUL), /*!< GPC_MFPL PC2 setting for USCI2_CLK   */
	PC2_PSIO0_CH3    = (0x0fUL), /*!< GPC_MFPL PC2 setting for PSIO0_CH3   */

/* PC.3 MFP */
	PC3_GPIO         = (0x00UL), /*!< GPC_MFPL PC3 setting for GPIO        */
	PC3_EBI_AD3      = (0x02UL), /*!< GPC_MFPL PC3 setting for EBI_AD3     */
	PC3_QSPI0_SS     = (0x04UL), /*!< GPC_MFPL PC3 setting for QSPI0_SS    */
	PC3_LCD_SEG29    = (0x05UL), /*!< GPC_MFPL PC3 setting for LCD_SEG29   */
	PC3_LCD_COM6     = (0x05UL), /*!< GPC_MFPL PC3 setting for LCD_COM6    */
	PC3_TK_TK11      = (0x06UL), /*!< GPC_MFPL PC3 setting for TK_TK11     */
	PC3_SPI1_MISO    = (0x07UL), /*!< GPC_MFPL PC3 setting for SPI1_MISO   */
	PC3_UART2_nRTS   = (0x08UL), /*!< GPC_MFPL PC3 setting for UART2_nRTS  */
	PC3_I2C0_SMBAL   = (0x09UL), /*!< GPC_MFPL PC3 setting for I2C0_SMBAL  */
	PC3_UART3_TXD    = (0x0bUL), /*!< GPC_MFPL PC3 setting for UART3_TXD   */
	PC3_PWM1_CH2     = (0x0cUL), /*!< GPC_MFPL PC3 setting for PWM1_CH2    */
	PC3_USCI2_CTL0   = (0x0dUL), /*!< GPC_MFPL PC3 setting for USCI2_CTL0  */
	PC3_PSIO0_CH2    = (0x0fUL), /*!< GPC_MFPL PC3 setting for PSIO0_CH2   */

/* PC.4 MFP */
	PC4_GPIO         = (0x00UL), /*!< GPC_MFPL PC4 setting for GPIO        */
	PC4_EBI_AD4      = (0x02UL), /*!< GPC_MFPL PC4 setting for EBI_AD4     */
	PC4_QSPI0_MOSI1  = (0x04UL), /*!< GPC_MFPL PC4 setting for QSPI0_MOSI1 */
	PC4_LCD_SEG30    = (0x05UL), /*!< GPC_MFPL PC4 setting for LCD_SEG30   */
	PC4_LCD_COM5     = (0x05UL), /*!< GPC_MFPL PC4 setting for LCD_COM5    */
	PC4_TK_TK10      = (0x06UL), /*!< GPC_MFPL PC4 setting for TK_TK10     */
	PC4_SPI1_I2SMCLK = (0x07UL), /*!< GPC_MFPL PC4 setting for SPI1_I2SMCLK*/
	PC4_UART2_RXD    = (0x08UL), /*!< GPC_MFPL PC4 setting for UART2_RXD   */
	PC4_I2C1_SDA     = (0x09UL), /*!< GPC_MFPL PC4 setting for I2C1_SDA    */
	PC4_PWM1_CH1     = (0x0cUL), /*!< GPC_MFPL PC4 setting for PWM1_CH1    */
	PC4_USCI2_CTL1   = (0x0dUL), /*!< GPC_MFPL PC4 setting for USCI2_CTL1  */
	PC4_PSIO0_CH1    = (0x0fUL), /*!< GPC_MFPL PC4 setting for PSIO0_CH1   */

/* PC.5 MFP */
	PC5_GPIO         = (0x00UL), /*!< GPC_MFPL PC5 setting for GPIO        */
	PC5_EBI_AD5      = (0x02UL), /*!< GPC_MFPL PC5 setting for EBI_AD5     */
	PC5_QSPI0_MISO1  = (0x04UL), /*!< GPC_MFPL PC5 setting for QSPI0_MISO1 */
	PC5_LCD_SEG31    = (0x05UL), /*!< GPC_MFPL PC5 setting for LCD_SEG31   */
	PC5_LCD_COM4     = (0x05UL), /*!< GPC_MFPL PC5 setting for LCD_COM4    */
	PC5_TK_TK9       = (0x06UL), /*!< GPC_MFPL PC5 setting for TK_TK9      */
	PC5_UART2_TXD    = (0x08UL), /*!< GPC_MFPL PC5 setting for UART2_TXD   */
	PC5_I2C1_SCL     = (0x09UL), /*!< GPC_MFPL PC5 setting for I2C1_SCL    */
	PC5_PWM1_CH0     = (0x0cUL), /*!< GPC_MFPL PC5 setting for PWM1_CH0    */
	PC5_PSIO0_CH0    = (0x0fUL), /*!< GPC_MFPL PC5 setting for PSIO0_CH0   */

/* PC.6 MFP */
	PC6_GPIO         = (0x00UL), /*!< GPC_MFPL PC6 setting for GPIO        */
	PC6_EBI_AD8      = (0x02UL), /*!< GPC_MFPL PC6 setting for EBI_AD8     */
	PC6_SPI1_MOSI    = (0x04UL), /*!< GPC_MFPL PC6 setting for SPI1_MOSI   */
	PC6_LCD_SEG38    = (0x05UL), /*!< GPC_MFPL PC6 setting for LCD_SEG38   */
	PC6_TK_TK18      = (0x06UL), /*!< GPC_MFPL PC6 setting for TK_TK18     */
	PC6_UART0_nRTS   = (0x07UL), /*!< GPC_MFPL PC6 setting for UART0_nRTS  */
	PC6_I2C1_SMBSUS  = (0x08UL), /*!< GPC_MFPL PC6 setting for I2C1_SMBSUS */
	PC6_PWM1_CH3     = (0x0bUL), /*!< GPC_MFPL PC6 setting for PWM1_CH3    */
	PC6_BPWM1_CH1    = (0x0cUL), /*!< GPC_MFPL PC6 setting for BPWM1_CH1   */
	PC6_TM1          = (0x0eUL), /*!< GPC_MFPL PC6 setting for TM1         */
	PC6_INT2         = (0x0fUL), /*!< GPC_MFPL PC6 setting for INT2        */

/* PC.7 MFP */
	PC7_GPIO         = (0x00UL), /*!< GPC_MFPL PC7 setting for GPIO        */
	PC7_EBI_AD9      = (0x02UL), /*!< GPC_MFPL PC7 setting for EBI_AD9     */
	PC7_SPI1_MISO    = (0x04UL), /*!< GPC_MFPL PC7 setting for SPI1_MISO   */
	PC7_LCD_SEG39    = (0x05UL), /*!< GPC_MFPL PC7 setting for LCD_SEG39   */
	PC7_TK_TK17      = (0x06UL), /*!< GPC_MFPL PC7 setting for TK_TK17     */
	PC7_UART0_nCTS   = (0x07UL), /*!< GPC_MFPL PC7 setting for UART0_nCTS  */
	PC7_I2C1_SMBAL   = (0x08UL), /*!< GPC_MFPL PC7 setting for I2C1_SMBAL  */
	PC7_PWM1_CH2     = (0x0bUL), /*!< GPC_MFPL PC7 setting for PWM1_CH2    */
	PC7_BPWM1_CH0    = (0x0cUL), /*!< GPC_MFPL PC7 setting for BPWM1_CH0   */
	PC7_TM0          = (0x0eUL), /*!< GPC_MFPL PC7 setting for TM0         */
	PC7_INT3         = (0x0fUL), /*!< GPC_MFPL PC7 setting for INT3        */

/* PC.8 MFP */
	PC8_GPIO         = (0x00UL), /*!< GPC_MFPH PC8 setting for GPIO        */
	PC8_EBI_ADR16    = (0x02UL), /*!< GPC_MFPH PC8 setting for EBI_ADR16   */
	PC8_I2C0_SDA     = (0x04UL), /*!< GPC_MFPH PC8 setting for I2C0_SDA    */
	PC8_LCD_SEG40    = (0x05UL), /*!< GPC_MFPH PC8 setting for LCD_SEG40   */
	PC8_LCD_COM7     = (0x05UL), /*!< GPC_MFPH PC8 setting for LCD_COM7    */
	PC8_UART1_RXD    = (0x08UL), /*!< GPC_MFPH PC8 setting for UART1_RXD   */
	PC8_PWM1_CH1     = (0x0bUL), /*!< GPC_MFPH PC8 setting for PWM1_CH1    */
	PC8_BPWM1_CH4    = (0x0cUL), /*!< GPC_MFPH PC8 setting for BPWM1_CH4   */

/* PC.9 MFP */
	PC9_GPIO         = (0x00UL), /*!< GPC_MFPH PC9 setting for GPIO        */
	PC9_EBI_ADR7     = (0x02UL), /*!< GPC_MFPH PC9 setting for EBI_ADR7    */
	PC9_LCD_SEG2     = (0x05UL), /*!< GPC_MFPH PC9 setting for LCD_SEG2    */
	PC9_UART3_RXD    = (0x07UL), /*!< GPC_MFPH PC9 setting for UART3_RXD   */
	PC9_PWM1_CH3     = (0x0cUL), /*!< GPC_MFPH PC9 setting for PWM1_CH3    */

/* PC.10 MFP */
	PC10_GPIO        = (0x00UL),/*!< GPC_MFPH PC10 setting for GPIO       */
	PC10_EBI_ADR6    = (0x02UL),/*!< GPC_MFPH PC10 setting for EBI_ADR6   */
	PC10_LCD_SEG3    = (0x05UL),/*!< GPC_MFPH PC10 setting for LCD_SEG3   */
	PC10_UART3_TXD   = (0x07UL),/*!< GPC_MFPH PC10 setting for UART3_TXD  */
	PC10_PWM1_CH2    = (0x0cUL),/*!< GPC_MFPH PC10 setting for PWM1_CH2   */

/* PC.11 MFP */
	PC11_GPIO        = (0x00UL),/*!< GPC_MFPH PC11 setting for GPIO       */
	PC11_EBI_ADR5    = (0x02UL),/*!< GPC_MFPH PC11 setting for EBI_ADR5   */
	PC11_UART0_RXD   = (0x03UL),/*!< GPC_MFPH PC11 setting for UART0_RXD  */
	PC11_I2C0_SDA    = (0x04UL),/*!< GPC_MFPH PC11 setting for I2C0_SDA   */
	PC11_PWM1_CH1    = (0x0cUL),/*!< GPC_MFPH PC11 setting for PWM1_CH1   */
	PC11_ACMP1_O     = (0x0eUL),/*!< GPC_MFPH PC11 setting for ACMP1_O    */

/* PC.12 MFP */
	PC12_GPIO        = (0x00UL),/*!< GPC_MFPH PC12 setting for GPIO       */
	PC12_EBI_ADR4    = (0x02UL),/*!< GPC_MFPH PC12 setting for EBI_ADR4   */
	PC12_UART0_TXD   = (0x03UL),/*!< GPC_MFPH PC12 setting for UART0_TXD  */
	PC12_I2C0_SCL    = (0x04UL),/*!< GPC_MFPH PC12 setting for I2C0_SCL   */
	PC12_SC0_nCD     = (0x09UL),/*!< GPC_MFPH PC12 setting for SC0_nCD    */
	PC12_PWM1_CH0    = (0x0cUL),/*!< GPC_MFPH PC12 setting for PWM1_CH0   */
	PC12_ACMP0_O     = (0x0eUL),/*!< GPC_MFPH PC12 setting for ACMP0_O    */

/* PC.13 MFP */
	PC13_GPIO        = (0x00UL),/*!< GPC_MFPH PC13 setting for GPIO       */

/* PC.14 MFP */
	PC14_GPIO         = (0x00UL),/*!< GPC_MFPH PC14 setting for GPIO       */
	PC14_EBI_AD11     = (0x02UL),/*!< GPC_MFPH PC14 setting for EBI_AD11   */
	PC14_SPI0_I2SMCLK = (0x04UL),/*!< GPC_MFPH PC14 setting for SPI0_I2SMCLK*/
	PC14_USCI0_CTL0   = (0x05UL),/*!< GPC_MFPH PC14 setting for USCI0_CTL0 */
	PC14_QSPI0_CLK    = (0x06UL),/*!< GPC_MFPH PC14 setting for QSPI0_CLK  */
	PC14_USCI2_CLK    = (0x07UL),/*!< GPC_MFPH PC14 setting for USCI2_CLK  */
	PC14_LCD_SEG14    = (0x08UL),/*!< GPC_MFPH PC14 setting for LCD_SEG14  */
	PC14_LCD_COM0     = (0x08UL),/*!< GPC_MFPH PC14 setting for LCD_COM0   */
	PC14_TM1          = (0x0dUL),/*!< GPC_MFPH PC14 setting for TM1        */

/* PD.0 MFP */
	PD0_GPIO         = (0x00UL), /*!< GPD_MFPL PD0 setting for GPIO        */
	PD0_EBI_AD13     = (0x02UL), /*!< GPD_MFPL PD0 setting for EBI_AD13    */
	PD0_USCI0_CLK    = (0x03UL), /*!< GPD_MFPL PD0 setting for USCI0_CLK   */
	PD0_SPI0_MOSI    = (0x04UL), /*!< GPD_MFPL PD0 setting for SPI0_MOSI   */
	PD0_LCD_SEG22    = (0x05UL), /*!< GPD_MFPL PD0 setting for LCD_SEG22   */
	PD0_TK_TK16      = (0x07UL), /*!< GPD_MFPL PD0 setting for TK_TK16     */
	PD0_UART3_RXD    = (0x09UL), /*!< GPD_MFPL PD0 setting for UART3_RXD   */
	PD0_TM2          = (0x0eUL), /*!< GPD_MFPL PD0 setting for TM2         */

/* PD.1 MFP */
	PD1_GPIO         = (0x00UL), /*!< GPD_MFPL PD1 setting for GPIO        */
	PD1_EBI_AD12     = (0x02UL), /*!< GPD_MFPL PD1 setting for EBI_AD12    */
	PD1_USCI0_DAT0   = (0x03UL), /*!< GPD_MFPL PD1 setting for USCI0_DAT0  */
	PD1_SPI0_MISO    = (0x04UL), /*!< GPD_MFPL PD1 setting for SPI0_MISO   */
	PD1_LCD_SEG23    = (0x05UL), /*!< GPD_MFPL PD1 setting for LCD_SEG23   */
	PD1_TK_TK15      = (0x07UL), /*!< GPD_MFPL PD1 setting for TK_TK15     */
	PD1_UART3_TXD    = (0x09UL), /*!< GPD_MFPL PD1 setting for UART3_TXD   */

/* PD.2 MFP */
	PD2_GPIO         = (0x00UL), /*!< GPD_MFPL PD2 setting for GPIO        */
	PD2_EBI_AD11     = (0x02UL), /*!< GPD_MFPL PD2 setting for EBI_AD11    */
	PD2_USCI0_DAT1   = (0x03UL), /*!< GPD_MFPL PD2 setting for USCI0_DAT1  */
	PD2_SPI0_CLK     = (0x04UL), /*!< GPD_MFPL PD2 setting for SPI0_CLK    */
	PD2_LCD_SEG24    = (0x05UL), /*!< GPD_MFPL PD2 setting for LCD_SEG24   */
	PD2_TK_TK14      = (0x07UL), /*!< GPD_MFPL PD2 setting for TK_TK14     */
	PD2_UART0_RXD    = (0x09UL), /*!< GPD_MFPL PD2 setting for UART0_RXD   */
	PD2_UART3_nCTS   = (0x0aUL), /*!< GPD_MFPL PD2 setting for UART3_nCTS  */

/* PD.3 MFP */
	PD3_GPIO         = (0x00UL), /*!< GPD_MFPL PD3 setting for GPIO        */
	PD3_EBI_AD10     = (0x02UL), /*!< GPD_MFPL PD3 setting for EBI_AD10    */
	PD3_USCI0_CTL1   = (0x03UL), /*!< GPD_MFPL PD3 setting for USCI0_CTL1  */
	PD3_SPI0_SS      = (0x04UL), /*!< GPD_MFPL PD3 setting for SPI0_SS     */
	PD3_LCD_SEG25    = (0x05UL), /*!< GPD_MFPL PD3 setting for LCD_SEG25   */
	PD3_USCI1_CTL0   = (0x06UL), /*!< GPD_MFPL PD3 setting for USCI1_CTL0  */
	PD3_TK_TK13      = (0x07UL), /*!< GPD_MFPL PD3 setting for TK_TK13     */
	PD3_UART0_TXD    = (0x09UL), /*!< GPD_MFPL PD3 setting for UART0_TXD   */
	PD3_UART3_nRTS   = (0x0aUL), /*!< GPD_MFPL PD3 setting for UART3_nRTS  */

/* PD.4 MFP */
	PD4_GPIO         = (0x00UL), /*!< GPD_MFPL PD4 setting for GPIO        */
	PD4_USCI0_CTL0   = (0x03UL), /*!< GPD_MFPL PD4 setting for USCI0_CTL0  */
	PD4_I2C1_SDA     = (0x04UL), /*!< GPD_MFPL PD4 setting for I2C1_SDA    */
	PD4_USCI1_CTL1   = (0x06UL), /*!< GPD_MFPL PD4 setting for USCI1_CTL1  */
	PD4_TK_TK16      = (0x07UL), /*!< GPD_MFPL PD4 setting for TK_TK16     */
	PD4_SPI1_SS      = (0x09UL),  /*!< GPD_MFPL PD4 setting for SPI1_SS    */
	PD4_PSIO0_CH7    = (0x0aUL), /*!< GPD_MFPL PD4 setting for PSIO0_CH7   */

/* PD.5 MFP */
	PD5_GPIO         = (0x00UL), /*!< GPD_MFPL PD5 setting for GPIO        */
	PD5_I2C1_SCL     = (0x04UL), /*!< GPD_MFPL PD5 setting for I2C1_SCL    */
	PD5_USCI1_DAT0   = (0x06UL), /*!< GPD_MFPL PD5 setting for USCI1_DAT0  */
	PD5_TK_TK15      = (0x07UL), /*!< GPD_MFPL PD5 setting for TK_TK15     */
	PD5_SPI1_CLK     = (0x09UL), /*!< GPD_MFPL PD5 setting for SPI1_CLK    */
	PD5_PSIO0_CH6    = (0x0aUL), /*!< GPD_MFPL PD5 setting for PSIO0_CH6   */

/* PD.6 MFP */
	PD6_GPIO         = (0x00UL), /*!< GPD_MFPL PD6 setting for GPIO        */
	PD6_UART1_RXD    = (0x03UL), /*!< GPD_MFPL PD6 setting for UART1_RXD   */
	PD6_I2C0_SDA     = (0x04UL), /*!< GPD_MFPL PD6 setting for I2C0_SDA    */
	PD6_USCI1_DAT1   = (0x06UL), /*!< GPD_MFPL PD6 setting for USCI1_DAT1  */
	PD6_TK_TK14      = (0x07UL), /*!< GPD_MFPL PD6 setting for TK_TK14     */
	PD6_SPI1_MOSI    = (0x09UL), /*!< GPD_MFPL PD6 setting for SPI1_MOSI   */
	PD6_PSIO0_CH5    = (0x0aUL), /*!< GPD_MFPL PD6 setting for PSIO0_CH5   */

/* PD.7 MFP */
	PD7_GPIO         = (0x00UL), /*!< GPD_MFPL PD7 setting for GPIO        */
	PD7_UART1_TXD    = (0x03UL), /*!< GPD_MFPL PD7 setting for UART1_TXD   */
	PD7_I2C0_SCL     = (0x04UL), /*!< GPD_MFPL PD7 setting for I2C0_SCL    */
	PD7_USCI1_CLK    = (0x06UL), /*!< GPD_MFPL PD7 setting for USCI1_CLK   */
	PD7_TK_TK13      = (0x07UL), /*!< GPD_MFPL PD7 setting for TK_TK13     */
	PD7_SPI1_MISO    = (0x09UL), /*!< GPD_MFPL PD7 setting for SPI1_MISO   */
	PD7_PSIO0_CH4    = (0x0aUL), /*!< GPD_MFPL PD7 setting for PSIO0_CH4   */

/* PD.8 MFP */
	PD8_GPIO         = (0x00UL), /*!< GPD_MFPH PD8 setting for GPIO        */
	PD8_EBI_AD6      = (0x02UL), /*!< GPD_MFPH PD8 setting for EBI_AD6     */
	PD8_UART2_nRTS   = (0x04UL), /*!< GPD_MFPH PD8 setting for UART2_nRTS  */
	PD8_LCD_SEG32    = (0x05UL), /*!< GPD_MFPH PD8 setting for LCD_SEG32   */
	PD8_TK_TK23      = (0x06UL), /*!< GPD_MFPH PD8 setting for TK_TK23     */
	PD8_PSIO0_CH3    = (0x0aUL), /*!< GPD_MFPH PD8 setting for PSIO0_CH3   */

/* PD.9 MFP */
	PD9_GPIO         = (0x00UL), /*!< GPD_MFPH PD9 setting for GPIO        */
	PD9_EBI_AD7      = (0x02UL), /*!< GPD_MFPH PD9 setting for EBI_AD7     */
	PD9_UART2_nCTS   = (0x04UL), /*!< GPD_MFPH PD9 setting for UART2_nCTS  */
	PD9_LCD_SEG33    = (0x05UL), /*!< GPD_MFPH PD9 setting for LCD_SEG33   */
	PD9_TK_TK22      = (0x06UL), /*!< GPD_MFPH PD9 setting for TK_TK22     */
	PD9_PSIO0_CH2    = (0x0aUL), /*!< GPD_MFPH PD9 setting for PSIO0_CH2   */

/* PD.10 MFP */
	PD10_GPIO        = (0x00UL),/*!< GPD_MFPH PD10 setting for GPIO       */
	PD10_EBI_nCS2    = (0x02UL),/*!< GPD_MFPH PD10 setting for EBI_nCS2   */
	PD10_UART1_RXD   = (0x03UL),/*!< GPD_MFPH PD10 setting for UART1_RXD  */
	PD10_LCD_SEG42   = (0x05UL),/*!< GPD_MFPH PD10 setting for LCD_SEG42  */
	PD10_LCD_COM5    = (0x05UL),/*!< GPD_MFPH PD10 setting for LCD_COM5   */

/* PD.11 MFP */
	PD11_GPIO        = (0x00UL),/*!< GPD_MFPH PD11 setting for GPIO       */
	PD11_EBI_nCS1    = (0x02UL),/*!< GPD_MFPH PD11 setting for EBI_nCS1   */
	PD11_UART1_TXD   = (0x03UL),/*!< GPD_MFPH PD11 setting for UART1_TXD  */
	PD11_LCD_SEG43   = (0x05UL),/*!< GPD_MFPH PD11 setting for LCD_SEG43  */
	PD11_LCD_COM4    = (0x05UL),/*!< GPD_MFPH PD11 setting for LCD_COM4   */

/* PD.12 MFP */
	PD12_GPIO        = (0x00UL),/*!< GPD_MFPH PD12 setting for GPIO       */
	PD12_EBI_nCS0    = (0x02UL),/*!< GPD_MFPH PD12 setting for EBI_nCS0   */
	PD12_UART2_RXD   = (0x07UL),/*!< GPD_MFPH PD12 setting for UART2_RXD  */
	PD12_BPWM0_CH5   = (0x09UL),/*!< GPD_MFPH PD12 setting for BPWM0_CH5  */
	PD12_TK_SE       = (0x0cUL),/*!< GPD_MFPH PD12 setting for TK_SE      */
	PD12_CLKO        = (0x0dUL),/*!< GPD_MFPH PD12 setting for CLKO       */
	PD12_EADC0_ST    = (0x0eUL),/*!< GPD_MFPH PD12 setting for EADC0_ST   */
	PD12_INT5        = (0x0fUL),/*!< GPD_MFPH PD12 setting for INT5       */

/* PD.13 MFP */
	PD13_GPIO         = (0x00UL),/*!< GPD_MFPH PD13 setting for GPIO       */
	PD13_EBI_AD10     = (0x02UL),/*!< GPD_MFPH PD13 setting for EBI_AD10   */
	PD13_SPI1_I2SMCLK = (0x03UL),/*!< GPD_MFPH PD13 setting for SPI1_I2SMCLK*/
	PD13_SPI0_I2SMCLK = (0x04UL),/*!< GPD_MFPH PD13 setting for SPI0_I2SMCLK*/
	PD13_LCD_SEG21    = (0x05UL),/*!< GPD_MFPH PD13 setting for LCD_SEG21  */
	PD13_USCI2_CTL0   = (0x08UL),/*!< GPD_MFPH PD13 setting for USCI2_CTL0 */

/* PD.14 MFP */
	PD14_GPIO        = (0x00UL),/*!< GPD_MFPH PD14 setting for GPIO       */

/* PD.15 MFP */
	PD15_GPIO        = (0x00UL),/*!< GPD_MFPH PD15 setting for GPIO       */
	PD15_TK_TK0      = (0x05UL),/*!< GPD_MFPH PD15 setting for TK_TK0     */
	PD15_PSIO0_CH7   = (0x0bUL),/*!< GPD_MFPH PD15 setting for PSIO0_CH7  */
	PD15_PWM0_CH5    = (0x0cUL),/*!< GPD_MFPH PD15 setting for PWM0_CH5   */
	PD15_TM3         = (0x0eUL),/*!< GPD_MFPH PD15 setting for TM3        */
	PD15_INT1        = (0x0fUL),/*!< GPD_MFPH PD15 setting for INT1       */

/* PE.0 MFP */
	PE0_GPIO         = (0x00UL), /*!< GPE_MFPL PE0 setting for GPIO        */
	PE0_EBI_AD11     = (0x02UL), /*!< GPE_MFPL PE0 setting for EBI_AD11    */
	PE0_QSPI0_MOSI0  = (0x03UL), /*!< GPE_MFPL PE0 setting for QSPI0_MOSI0 */
	PE0_SPI1_MOSI    = (0x06UL), /*!< GPE_MFPL PE0 setting for SPI1_MOSI   */
	PE0_UART3_RXD    = (0x07UL), /*!< GPE_MFPL PE0 setting for UART3_RXD   */
	PE0_I2C1_SDA     = (0x08UL), /*!< GPE_MFPL PE0 setting for I2C1_SDA    */
	PE0_USCI2_DAT0   = (0x0aUL), /*!< GPE_MFPL PE0 setting for USCI2_DAT0  */

/* PE.1 MFP */
	PE1_GPIO         = (0x00UL), /*!< GPE_MFPL PE1 setting for GPIO        */
	PE1_EBI_AD10     = (0x02UL), /*!< GPE_MFPL PE1 setting for EBI_AD10    */
	PE1_QSPI0_MISO0  = (0x03UL), /*!< GPE_MFPL PE1 setting for QSPI0_MISO0 */
	PE1_SPI1_MISO    = (0x06UL), /*!< GPE_MFPL PE1 setting for SPI1_MISO   */
	PE1_UART3_TXD    = (0x07UL), /*!< GPE_MFPL PE1 setting for UART3_TXD   */
	PE1_I2C1_SCL     = (0x08UL), /*!< GPE_MFPL PE1 setting for I2C1_SCL    */
	PE1_USCI2_DAT1   = (0x0aUL), /*!< GPE_MFPL PE1 setting for USCI2_DAT1  */

/* PE.2 MFP */
	PE2_GPIO         = (0x00UL), /*!< GPE_MFPL PE2 setting for GPIO        */
	PE2_EBI_ALE      = (0x02UL), /*!< GPE_MFPL PE2 setting for EBI_ALE     */
	PE2_SC0_CLK      = (0x06UL), /*!< GPE_MFPL PE2 setting for SC0_CLK     */
	PE2_USCI0_CLK    = (0x07UL), /*!< GPE_MFPL PE2 setting for USCI0_CLK   */
	PE2_USCI2_CTL0   = (0x0aUL), /*!< GPE_MFPL PE2 setting for USCI2_CTL0  */
	PE2_PWM0_CH5     = (0x0cUL), /*!< GPE_MFPL PE2 setting for PWM0_CH5    */
	PE2_BPWM0_CH0    = (0x0dUL), /*!< GPE_MFPL PE2 setting for BPWM0_CH0   */

/* PE.3 MFP */
	PE3_GPIO         = (0x00UL), /*!< GPE_MFPL PE3 setting for GPIO        */
	PE3_EBI_MCLK     = (0x02UL), /*!< GPE_MFPL PE3 setting for EBI_MCLK    */
	PE3_SC0_DAT      = (0x06UL), /*!< GPE_MFPL PE3 setting for SC0_DAT     */
	PE3_USCI0_DAT0   = (0x07UL), /*!< GPE_MFPL PE3 setting for USCI0_DAT0  */
	PE3_PWM0_CH4     = (0x0cUL), /*!< GPE_MFPL PE3 setting for PWM0_CH4    */
	PE3_BPWM0_CH1    = (0x0dUL), /*!< GPE_MFPL PE3 setting for BPWM0_CH1   */

/* PE.4 MFP */
	PE4_GPIO         = (0x00UL), /*!< GPE_MFPL PE4 setting for GPIO        */
	PE4_EBI_nWR      = (0x02UL), /*!< GPE_MFPL PE4 setting for EBI_nWR     */
	PE4_SC0_RST      = (0x06UL), /*!< GPE_MFPL PE4 setting for SC0_RST     */
	PE4_USCI0_DAT1   = (0x07UL), /*!< GPE_MFPL PE4 setting for USCI0_DAT1  */
	PE4_PSIO0_CH3    = (0x0aUL), /*!< GPE_MFPL PE4 setting for PSIO0_CH3   */
	PE4_PWM0_CH3     = (0x0cUL), /*!< GPE_MFPL PE4 setting for PWM0_CH3    */
	PE4_BPWM0_CH2    = (0x0dUL), /*!< GPE_MFPL PE4 setting for BPWM0_CH2   */

/* PE.5 MFP */
	PE5_GPIO         = (0x00UL), /*!< GPE_MFPL PE5 setting for GPIO        */
	PE5_EBI_nRD      = (0x02UL), /*!< GPE_MFPL PE5 setting for EBI_nRD     */
	PE5_SC0_PWR      = (0x06UL), /*!< GPE_MFPL PE5 setting for SC0_PWR     */
	PE5_USCI0_CTL1   = (0x07UL), /*!< GPE_MFPL PE5 setting for USCI0_CTL1  */
	PE5_PSIO0_CH2    = (0x0aUL), /*!< GPE_MFPL PE5 setting for PSIO0_CH2   */
	PE5_PWM0_CH2     = (0x0cUL), /*!< GPE_MFPL PE5 setting for PWM0_CH2    */
	PE5_BPWM0_CH3    = (0x0dUL), /*!< GPE_MFPL PE5 setting for BPWM0_CH3   */

/* PE.6 MFP */
	PE6_GPIO         = (0x00UL), /*!< GPE_MFPL PE6 setting for GPIO        */
	PE6_LCD_SEG15    = (0x05UL), /*!< GPE_MFPL PE6 setting for LCD_SEG15   */
	PE6_SC0_nCD      = (0x06UL), /*!< GPE_MFPL PE6 setting for SC0_nCD     */
	PE6_USCI0_CTL0   = (0x07UL), /*!< GPE_MFPL PE6 setting for USCI0_CTL0  */
	PE6_PSIO0_CH1    = (0x0aUL), /*!< GPE_MFPL PE6 setting for PSIO0_CH1   */
	PE6_PWM0_CH1     = (0x0cUL), /*!< GPE_MFPL PE6 setting for PWM0_CH1    */
	PE6_BPWM0_CH4    = (0x0dUL), /*!< GPE_MFPL PE6 setting for BPWM0_CH4   */

/* PE.7 MFP */
	PE7_GPIO         = (0x00UL), /*!< GPE_MFPL PE7 setting for GPIO        */
	PE7_LCD_SEG16    = (0x05UL), /*!< GPE_MFPL PE7 setting for LCD_SEG16   */
	PE7_PSIO0_CH0    = (0x0aUL), /*!< GPE_MFPL PE7 setting for PSIO0_CH0   */
	PE7_PWM0_CH0     = (0x0cUL), /*!< GPE_MFPL PE7 setting for PWM0_CH0    */
	PE7_BPWM0_CH5    = (0x0dUL), /*!< GPE_MFPL PE7 setting for BPWM0_CH5   */

/* PE.8 MFP */
	PE8_GPIO         = (0x00UL), /*!< GPE_MFPH PE8 setting for GPIO        */
	PE8_EBI_ADR10    = (0x02UL), /*!< GPE_MFPH PE8 setting for EBI_ADR10   */
	PE8_LCD_SEG20    = (0x05UL), /*!< GPE_MFPH PE8 setting for LCD_SEG20   */
	PE8_LCD_COM0     = (0x05UL), /*!< GPE_MFPH PE8 setting for LCD_COM0    */
	PE8_USCI1_CTL1   = (0x06UL), /*!< GPE_MFPH PE8 setting for USCI1_CTL1  */
	PE8_UART2_TXD    = (0x07UL), /*!< GPE_MFPH PE8 setting for UART2_TXD   */
	PE8_PWM0_CH0     = (0x0aUL), /*!< GPE_MFPH PE8 setting for PWM0_CH0    */
	PE8_PWM0_BRAKE0  = (0x0bUL), /*!< GPE_MFPH PE8 setting for PWM0_BRAKE0 */

/* PE.9 MFP */
	PE9_GPIO         = (0x00UL), /*!< GPE_MFPH PE9 setting for GPIO        */
	PE9_EBI_ADR11    = (0x02UL), /*!< GPE_MFPH PE9 setting for EBI_ADR11   */
	PE9_LCD_SEG19    = (0x05UL), /*!< GPE_MFPH PE9 setting for LCD_SEG19   */
	PE9_LCD_COM1     = (0x05UL), /*!< GPE_MFPH PE9 setting for LCD_COM1    */
	PE9_USCI1_CTL0   = (0x06UL), /*!< GPE_MFPH PE9 setting for USCI1_CTL0  */
	PE9_UART2_RXD    = (0x07UL), /*!< GPE_MFPH PE9 setting for UART2_RXD   */
	PE9_PWM0_CH1     = (0x0aUL), /*!< GPE_MFPH PE9 setting for PWM0_CH1    */
	PE9_PWM0_BRAKE1  = (0x0bUL), /*!< GPE_MFPH PE9 setting for PWM0_BRAKE1 */

/* PE.10 MFP */
	PE10_GPIO        = (0x00UL),/*!< GPE_MFPH PE10 setting for GPIO       */
	PE10_EBI_ADR12   = (0x02UL),/*!< GPE_MFPH PE10 setting for EBI_ADR12  */
	PE10_LCD_SEG18   = (0x05UL),/*!< GPE_MFPH PE10 setting for LCD_SEG18  */
	PE10_LCD_COM2    = (0x05UL),/*!< GPE_MFPH PE10 setting for LCD_COM2   */
	PE10_USCI1_DAT0  = (0x06UL),/*!< GPE_MFPH PE10 setting for USCI1_DAT0 */
	PE10_UART3_TXD   = (0x07UL),/*!< GPE_MFPH PE10 setting for UART3_TXD  */
	PE10_PWM0_CH2    = (0x0aUL),/*!< GPE_MFPH PE10 setting for PWM0_CH2   */
	PE10_PWM1_BRAKE0 = (0x0bUL),/*!< GPE_MFPH PE10 setting for PWM1_BRAKE0*/

/* PE.11 MFP */
	PE11_GPIO        = (0x00UL),/*!< GPE_MFPH PE11 setting for GPIO       */
	PE11_EBI_ADR13   = (0x02UL),/*!< GPE_MFPH PE11 setting for EBI_ADR13  */
	PE11_LCD_SEG17   = (0x05UL),/*!< GPE_MFPH PE11 setting for LCD_SEG17  */
	PE11_LCD_COM3    = (0x05UL),/*!< GPE_MFPH PE11 setting for LCD_COM3   */
	PE11_USCI1_DAT1  = (0x06UL),/*!< GPE_MFPH PE11 setting for USCI1_DAT1 */
	PE11_UART3_RXD   = (0x07UL),/*!< GPE_MFPH PE11 setting for UART3_RXD  */
	PE11_UART1_nCTS  = (0x08UL),/*!< GPE_MFPH PE11 setting for UART1_nCTS */
	PE11_PWM0_CH3    = (0x0aUL),/*!< GPE_MFPH PE11 setting for PWM0_CH3   */
	PE11_PWM1_BRAKE1 = (0x0bUL),/*!< GPE_MFPH PE11 setting for PWM1_BRAKE1*/

/* PE.12 MFP */
	PE12_GPIO        = (0x00UL),/*!< GPE_MFPH PE12 setting for GPIO       */
	PE12_EBI_ADR14   = (0x02UL),/*!< GPE_MFPH PE12 setting for EBI_ADR14  */
	PE12_USCI1_CLK   = (0x06UL),/*!< GPE_MFPH PE12 setting for USCI1_CLK  */
	PE12_UART1_nRTS  = (0x08UL),/*!< GPE_MFPH PE12 setting for UART1_nRTS */
	PE12_PWM0_CH4    = (0x0aUL),/*!< GPE_MFPH PE12 setting for PWM0_CH4   */

/* PE.13 MFP */
	PE13_GPIO        = (0x00UL),/*!< GPE_MFPH PE13 setting for GPIO       */
	PE13_EBI_ADR15   = (0x02UL),/*!< GPE_MFPH PE13 setting for EBI_ADR15  */
	PE13_I2C0_SCL    = (0x04UL),/*!< GPE_MFPH PE13 setting for I2C0_SCL   */
	PE13_LCD_SEG41   = (0x05UL),/*!< GPE_MFPH PE13 setting for LCD_SEG41  */
	PE13_LCD_COM6    = (0x05UL),/*!< GPE_MFPH PE13 setting for LCD_COM6   */
	PE13_UART1_TXD   = (0x08UL),/*!< GPE_MFPH PE13 setting for UART1_TXD  */
	PE13_PWM0_CH5    = (0x0aUL),/*!< GPE_MFPH PE13 setting for PWM0_CH5   */
	PE13_PWM1_CH0    = (0x0bUL),/*!< GPE_MFPH PE13 setting for PWM1_CH0   */
	PE13_BPWM1_CH5   = (0x0cUL),/*!< GPE_MFPH PE13 setting for BPWM1_CH5  */

/* PE.14 MFP */
	PE14_GPIO        = (0x00UL),/*!< GPE_MFPH PE14 setting for GPIO       */
	PE14_EBI_AD8     = (0x02UL),/*!< GPE_MFPH PE14 setting for EBI_AD8    */
	PE14_UART2_TXD   = (0x03UL),/*!< GPE_MFPH PE14 setting for UART2_TXD  */
	PE14_LCD_SEG34   = (0x05UL),/*!< GPF_MFPH PE14 setting for LCD_SEG34  */
	PE14_TK_TK8      = (0x06UL),/*!< GPF_MFPH PE14 setting for TK_TK8     */
	PE14_PSIO0_CH0   = (0x0aUL),/*!< GPE_MFPH PE14 setting for PSIO0_CH0  */

/* PE.15 MFP */
	PE15_GPIO        = (0x00UL),/*!< GPE_MFPH PE15 setting for GPIO       */
	PE15_EBI_AD9     = (0x02UL),/*!< GPE_MFPH PE15 setting for EBI_AD9    */
	PE15_UART2_RXD   = (0x03UL),/*!< GPE_MFPH PE15 setting for UART2_RXD  */
	PE15_TK_TK21     = (0x06UL),/*!< GPE_MFPH PE15 setting for TK_TK21    */
	PE15_PSIO0_CH1   = (0x0aUL),/*!< GPE_MFPH PE15 setting for PSIO0_CH1  */

/* PF.0 MFP */
	PF0_GPIO         = (0x00UL), /*!< GPF_MFPL PF0 setting for GPIO        */
	PF0_UART1_TXD    = (0x02UL), /*!< GPF_MFPL PF0 setting for UART1_TXD   */
	PF0_I2C1_SCL     = (0x03UL), /*!< GPF_MFPL PF0 setting for I2C1_SCL    */
	PF0_UART0_TXD    = (0x04UL), /*!< GPF_MFPL PF0 setting for UART0_TXD   */
	PF0_BPWM1_CH0    = (0x0cUL), /*!< GPF_MFPL PF0 setting for BPWM1_CH0   */
	PF0_ICE_DAT      = (0x0eUL), /*!< GPF_MFPL PF0 setting for ICE_DAT     */

/* PF.1 MFP */
	PF1_GPIO         = (0x00UL), /*!< GPF_MFPL PF1 setting for GPIO        */
	PF1_UART1_RXD    = (0x02UL), /*!< GPF_MFPL PF1 setting for UART1_RXD   */
	PF1_I2C1_SDA     = (0x03UL), /*!< GPF_MFPL PF1 setting for I2C1_SDA    */
	PF1_UART0_RXD    = (0x04UL), /*!< GPF_MFPL PF1 setting for UART0_RXD   */
	PF1_BPWM1_CH1    = (0x0cUL), /*!< GPF_MFPL PF1 setting for BPWM1_CH1   */
	PF1_ICE_CLK      = (0x0eUL), /*!< GPF_MFPL PF1 setting for ICE_CLK     */

/* PF.2 MFP */
	PF2_GPIO         = (0x00UL), /*!< GPF_MFPL PF2 setting for GPIO        */
	PF2_EBI_nCS1     = (0x02UL), /*!< GPF_MFPL PF2 setting for EBI_nCS1    */
	PF2_UART0_RXD    = (0x03UL), /*!< GPF_MFPL PF2 setting for UART0_RXD   */
	PF2_I2C0_SDA     = (0x04UL), /*!< GPF_MFPL PF2 setting for I2C0_SDA    */
	PF2_QSPI0_CLK    = (0x05UL), /*!< GPF_MFPL PF2 setting for QSPI0_CLK   */
	PF2_XT1_OUT      = (0x0aUL), /*!< GPF_MFPL PF2 setting for XT1_OUT     */
	PF2_BPWM1_CH1    = (0x0bUL), /*!< GPF_MFPL PF2 setting for BPWM1_CH1   */

/* PF.3 MFP */
	PF3_GPIO         = (0x00UL), /*!< GPF_MFPL PF3 setting for GPIO        */
	PF3_EBI_nCS0     = (0x02UL), /*!< GPF_MFPL PF3 setting for EBI_nCS0    */
	PF3_UART0_TXD    = (0x03UL), /*!< GPF_MFPL PF3 setting for UART0_TXD   */
	PF3_I2C0_SCL     = (0x04UL), /*!< GPF_MFPL PF3 setting for I2C0_SCL    */
	PF3_XT1_IN       = (0x0aUL), /*!< GPF_MFPL PF3 setting for XT1_IN      */
	PF3_BPWM1_CH0    = (0x0bUL), /*!< GPF_MFPL PF3 setting for BPWM1_CH0   */

/* PF.4 MFP */
	PF4_GPIO         = (0x00UL), /*!< GPF_MFPL PF4 setting for GPIO        */
	PF4_UART2_TXD    = (0x02UL), /*!< GPF_MFPL PF4 setting for UART2_TXD   */
	PF4_UART2_nRTS   = (0x04UL), /*!< GPF_MFPL PF4 setting for UART2_nRTS  */
	PF4_BPWM0_CH5    = (0x08UL), /*!< GPF_MFPL PF4 setting for BPWM0_CH5   */
	PF4_X32_OUT      = (0x0aUL), /*!< GPF_MFPL PF4 setting for X32_OUT     */
	PF4_PWM0_CH1     = (0x07UL), /*!< GPF_MFPL PF4 setting for PWM0_CH1   */

/* PF.5 MFP */
	PF5_GPIO         = (0x00UL), /*!< GPF_MFPL PF5 setting for GPIO        */
	PF5_UART2_RXD    = (0x02UL), /*!< GPF_MFPL PF5 setting for UART2_RXD   */
	PF5_UART2_nCTS   = (0x04UL), /*!< GPF_MFPL PF5 setting for UART2_nCTS  */
	PF5_BPWM0_CH4    = (0x08UL), /*!< GPF_MFPL PF5 setting for BPWM0_CH4   */
	PF5_X32_IN       = (0x0aUL), /*!< GPF_MFPL PF5 setting for X32_IN      */
	PF5_EADC0_ST     = (0x0bUL), /*!< GPF_MFPL PF5 setting for EADC0_ST    */
	PF5_PWM0_CH0     = (0x07UL), /*!< GPF_MFPL PF5 setting for PWM0_CH0    */

/* PF.6 MFP */
	PF6_GPIO         = (0x00UL), /*!< GPF_MFPL PF6 setting for GPIO        */
	PF6_EBI_ADR19    = (0x02UL), /*!< GPF_MFPL PF6 setting for EBI_ADR19   */
	PF6_SC0_CLK      = (0x03UL), /*!< GPF_MFPL PF6 setting for SC0_CLK     */
	PF6_SPI0_MOSI    = (0x05UL), /*!< GPF_MFPL PF6 setting for SPI0_MOSI   */
	PF6_EBI_nCS0     = (0x07UL), /*!< GPF_MFPL PF6 setting for EBI_nCS0    */
	PF6_TAMPER0      = (0x0aUL), /*!< GPF_MFPL PF6 setting for TAMPER0     */

/* PF.7 MFP */
	PF7_GPIO         = (0x00UL), /*!< GPF_MFPL PF7 setting for GPIO        */
	PF7_EBI_ADR18    = (0x02UL), /*!< GPF_MFPL PF7 setting for EBI_ADR18   */
	PF7_SC0_DAT      = (0x03UL), /*!< GPF_MFPL PF7 setting for SC0_DAT     */
	PF7_SPI0_MISO    = (0x05UL), /*!< GPF_MFPL PF7 setting for SPI0_MISO   */

/* PF.14 MFP */
	PF14_GPIO        = (0x00UL),/*!< GPF_MFPH PF14 setting for GPIO        */
	PF14_PWM1_BRAKE0 = (0x09UL),/*!< GPF_MFPH PF14 setting for PWM1_BRAKE0 */
	PF14_PWM0_BRAKE0 = (0x0aUL),/*!< GPF_MFPH PF14 setting for PWM0_BRAKE0 */
	PF14_PSIO0_CH3   = (0x0bUL),/*!< GPF_MFPH PF14 setting for PSIO0_CH3   */
	PF14_PWM0_CH4    = (0x0cUL),/*!< GPF_MFPH PF14 setting for PWM0_CH4    */
	PF14_CLKO        = (0x0dUL),/*!< GPF_MFPH PF14 setting for CLKO        */
	PF14_TM3         = (0x0eUL),/*!< GPF_MFPH PF14 setting for TM3         */
	PF14_INT5        = (0x0fUL),/*!< GPF_MFPH PF14 setting for INT5        */

/* PF.15 MFP */
	PF15_GPIO        = (0x00UL),/*!< GPF_MFPH PF15 setting for GPIO       */
	PF15_LCD_SEG35   = (0x05UL),/*!< GPF_MFPH PF15 setting for LCD_SEG35  */
	PF15_TK_TK7      = (0x06UL),/*!< GPF_MFPH PF15 setting for TK_TK7     */
	PF15_TM2         = (0x0dUL),/*!< GPF_MFPH PF15 setting for TM2        */
	PF15_CLKO        = (0x0eUL),/*!< GPF_MFPH PF15 setting for CLKO       */
	PF15_INT4        = (0x0fUL)/*!< GPF_MFPH PF15 setting for INT4       */
}altFunc_t;

