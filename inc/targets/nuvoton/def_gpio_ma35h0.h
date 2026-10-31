/**************************************************************************//**
 * @file     SYS.h
 * @brief    MA35H0 Series SYS Driver Header File
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright(C) 2023 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#if defined(__MA35H04F764C__)
#define PA_EXIST
#define PB_EXIST
#define PC_EXIST
#define PD_EXIST
#define PE_EXIST
#define PF_EXIST
#define PG_EXIST
#define PH_EXIST
#define PI_EXIST
#define PJ_EXIST
#define PK_EXIST
#define PL_EXIST
#define PM_EXIST
#define PN_EXIST
#endif

typedef enum
{
	/* PA.0 MFP */
	PA0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PA0_UART1_nCTS           = (0x02), /*!< Clear to Send input pin for UART1. */
	PA0_UART16_RXD           = (0x03), /*!< Data receiver input pin for UART16. */
	PA0_NAND_DATA0           = (0x06), /*!< NAND Flash date bus bit 0. */
	PA0_EBI_AD0              = (0x07), /*!< EBI address/data bus bit0. */
	PA0_EBI_ADR0             = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.1 MFP */
	PA1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PA1_UART1_nRTS           = (0x02), /*!< Request to Send output pin for UART1. */
	PA1_UART16_TXD           = (0x03), /*!< Data transmitter output pin for UART16. */
	PA1_NAND_DATA1           = (0x06), /*!< NAND Flash date bus bit 1. */
	PA1_EBI_AD1              = (0x07), /*!< EBI address/data bus bit1. */
	PA1_EBI_ADR1             = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.2 MFP */
	PA2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PA2_UART1_RXD            = (0x02), /*!< Data receiver input pin for UART1. */
	PA2_NAND_DATA2           = (0x06), /*!< NAND Flash date bus bit 2. */
	PA2_EBI_AD2              = (0x07), /*!< EBI address/data bus bit2. */
	PA2_EBI_ADR2             = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.3 MFP */
	PA3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PA3_UART1_TXD            = (0x02), /*!< Data transmitter output pin for UART1. */
	PA3_NAND_DATA3           = (0x06), /*!< NAND Flash date bus bit 3. */
	PA3_EBI_AD3              = (0x07), /*!< EBI address/data bus bit3. */
	PA3_EBI_ADR3             = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.4 MFP */
	PA4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PA4_UART3_nCTS           = (0x02), /*!< Clear to Send input pin for UART3. */
	PA4_UART2_RXD            = (0x03), /*!< Data receiver input pin for UART2. */
	PA4_NAND_DATA4           = (0x06), /*!< NAND Flash date bus bit 4. */
	PA4_EBI_AD4              = (0x07), /*!< EBI address/data bus bit4. */
	PA4_EBI_ADR4             = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.5 MFP */
	PA5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PA5_UART3_nRTS           = (0x02), /*!< Request to Send output pin for UART3. */
	PA5_UART2_TXD            = (0x03), /*!< Data transmitter output pin for UART2. */
	PA5_NAND_DATA5           = (0x06), /*!< NAND Flash date bus bit 5. */
	PA5_EBI_AD5              = (0x07), /*!< EBI address/data bus bit5. */
	PA5_EBI_ADR5             = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.6 MFP */
	PA6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PA6_UART3_RXD            = (0x02), /*!< Data receiver input pin for UART3. */
	PA6_NAND_DATA6           = (0x06), /*!< NAND Flash date bus bit 6. */
	PA6_EBI_AD6              = (0x07), /*!< EBI address/data bus bit6. */
	PA6_EBI_ADR6             = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.7 MFP */
	PA7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PA7_UART3_TXD            = (0x02), /*!< Data transmitter output pin for UART3. */
	PA7_NAND_DATA7           = (0x06), /*!< NAND Flash date bus bit 7. */
	PA7_EBI_AD7              = (0x07), /*!< EBI address/data bus bit7. */
	PA7_EBI_ADR7             = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.8 MFP */
	PA8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PA8_UART5_nCTS           = (0x02), /*!< Clear to Send input pin for UART5. */
	PA8_UART4_RXD            = (0x03), /*!< Data receiver input pin for UART4. */
	PA8_NAND_RDY             = (0x06), /*!< NAND Flash ready/busy input pin. */
	PA8_EBI_AD8              = (0x07), /*!< EBI address/data bus bit8. */
	PA8_EBI_ADR8             = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.9 MFP */
	PA9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PA9_UART5_nRTS           = (0x02), /*!< Request to Send output pin for UART5. */
	PA9_UART4_TXD            = (0x03), /*!< Data transmitter output pin for UART4. */
	PA9_NAND_nRE             = (0x06), /*!< NAND Flash read enable output pin. */
	PA9_EBI_AD9              = (0x07), /*!< EBI address/data bus bit9. */
	PA9_EBI_ADR9             = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.10 MFP */
	PA10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PA10_UART5_RXD           = (0x02), /*!< Data receiver input pin for UART5. */
	PA10_NAND_nWE            = (0x06), /*!< NAND Flash write enable output pin. */
	PA10_EBI_AD10            = (0x07), /*!< EBI address/data bus bit1. */
	PA10_EBI_ADR10           = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.11 MFP */
	PA11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PA11_UART5_TXD           = (0x02), /*!< Data transmitter output pin for UART5. */
	PA11_NAND_CLE            = (0x06), /*!< NAND Flash command latch enable output pin. */
	PA11_EBI_AD11            = (0x07), /*!< EBI address/data bus bit1. */
	PA11_EBI_ADR11           = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.12 MFP */
	PA12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PA12_UART7_nCTS          = (0x02), /*!< Clear to Send input pin for UART7. */
	PA12_UART8_RXD           = (0x03), /*!< Data receiver input pin for UART8. */
	PA12_NAND_ALE            = (0x06), /*!< NAND Flash address latch enable output pin. */
	PA12_EBI_AD12            = (0x07), /*!< EBI address/data bus bit1. */
	PA12_EBI_ADR12           = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.13 MFP */
	PA13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PA13_UART7_nRTS          = (0x02), /*!< Request to Send output pin for UART7. */
	PA13_UART8_TXD           = (0x03), /*!< Data transmitter output pin for UART8. */
	PA13_NAND_nCS            = (0x06), /*!< NAND Flash chip select pin. */
	PA13_EBI_AD13            = (0x07), /*!< EBI address/data bus bit1. */
	PA13_EBI_ADR13           = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.14 MFP */
	PA14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PA14_UART7_RXD           = (0x02), /*!< Data receiver input pin for UART7. */
	PA14_CAN3_RXD            = (0x03), /*!< CAN3 bus receiver input. */
	PA14_USBHL3_DM           = (0x04), /*!< USB 1.1 host-lite 3 differential signal D-. */
	PA14_NAND_nWP            = (0x06), /*!< NAND Flash write protect input pin. */
	PA14_EBI_AD14            = (0x07), /*!< EBI address/data bus bit1. */
	PA14_EBI_ADR14           = (0x09), /*!< EBI address/data bus bit*. */

	/* PA.15 MFP */
	PA15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PA15_EPWM0_CH2           = (0x01), /*!< EPWM0 channel2 output/capture input. */
	PA15_UART9_nCTS          = (0x02), /*!< Clear to Send input pin for UART*. */
	PA15_UART6_RXD           = (0x03), /*!< Data receiver input pin for UART6. */
	PA15_I2C4_SDA            = (0x04), /*!< I2C4 data input/output pin. */
	PA15_CAN2_RXD            = (0x05), /*!< CAN2 bus receiver input. */
	PA15_USBHL0_DM           = (0x06), /*!< USB 1.1 host-lite 0 differential signal D-. */
	PA15_EBI_ALE             = (0x07), /*!< EBI address latch enable output pin. */
	PA15_TM1                 = (0x0b), /*!< Timer1 event counter input / toggle output */
	PA15_RGMII0_PPS          = (0x0e), /*!< RGMII0 Pulse Per Second output pin. */
	PA15_RMII0_PPS           = (0x0f), /*!< RMII0 Pulse Per Second output pin. */

	/* PB.0 MFP */
	PB0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */

	/* PB.1 MFP */
	PB1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */

	/* PB.2 MFP */
	PB2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */

	/* PB.3 MFP */
	PB3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */

	/* PB.4 MFP */
	PB4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */

	/* PB.5 MFP */
	PB5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */

	/* PB.6 MFP */
	PB6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */

	/* PB.7 MFP */
	PB7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */

	/* PB.8 MFP */
	PB8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PB8_EPWM2_BRAKE0         = (0x01), /*!< Brake input pin 0 of EPWM2. */
	PB8_UART2_nCTS           = (0x02), /*!< Clear to Send input pin for UART2. */
	PB8_UART1_RXD            = (0x03), /*!< Data receiver input pin for UART1. */
	PB8_I2C2_SDA             = (0x04), /*!< I2C2 data input/output pin. */
	PB8_SPI0_SS1             = (0x05), /*!< 1st SPI0 slave select pin. */
	PB8_SPI0_I2SMCLK         = (0x06), /*!< SPI0 I2S master clock output pin. */
	PB8_ADC0_CH0             = (0x08), /*!< ADC0 channel 0 analog input. */
	PB8_EBI_nCS0             = (0x09), /*!< EBI chip select enable output pin. */
	PB8_TM4                  = (0x0b), /*!< Timer4 event counter input / toggle output */

	/* PB.9 MFP */
	PB9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PB9_EPWM2_CH4            = (0x01), /*!< EPWM2 channel4 output/capture input. */
	PB9_UART2_nRTS           = (0x02), /*!< Request to Send output pin for UART2. */
	PB9_UART1_TXD            = (0x03), /*!< Data transmitter output pin for UART1. */
	PB9_I2C2_SCL             = (0x04), /*!< I2C2 clock pin. */
	PB9_SPI0_CLK             = (0x05), /*!< SPI0 serial clock pin. */
	PB9_I2S0_MCLK            = (0x06), /*!< I2S0 master clock output pin. */
	PB9_VCAP1_HSYNC          = (0x07), /*!< Camera capture 1 interface hsync input pin. */
	PB9_ADC0_CH1             = (0x08), /*!< ADC0 channel 1 analog input. */
	PB9_EBI_ALE              = (0x09), /*!< EBI address latch enable output pin. */
	PB9_EBI_AD13             = (0x0a), /*!< EBI address/data bus bit1. */
	PB9_TM0_EXT              = (0x0b), /*!< Timer0 event counter input / toggle output */
	PB9_I2S1_MCLK            = (0x0c), /*!< I2S1 master clock output pin. */
	PB9_SC0_nCD              = (0x0d), /*!< SmartCard0 card detect pin. */

	/* PB.10 MFP */
	PB10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PB10_EPWM2_CH5           = (0x01), /*!< EPWM2 channel5 output/capture input. */
	PB10_UART2_RXD           = (0x02), /*!< Data receiver input pin for UART2. */
	PB10_CAN0_RXD            = (0x03), /*!< CAN0 bus receiver input. */
	PB10_USBHL2_DM           = (0x04), /*!< USB 1.1 host-lite 2 differential signal D-. */
	PB10_SPI0_MOSI           = (0x05), /*!< 1st SPI0 MOSI (Master Out, Slave In) pin. */
	PB10_EBI_MCLK            = (0x06), /*!< EBI external clock output pin. */
	PB10_VCAP1_VSYNC         = (0x07), /*!< Camera capture 1 interface vsync input pin. */
	PB10_ADC0_CH2            = (0x08), /*!< ADC0 channel 2 analog input. */
	PB10_EBI_ADR15           = (0x09), /*!< EBI address/data bus bit*. */
	PB10_EBI_AD14            = (0x0a), /*!< EBI address/data bus bit1. */
	PB10_TM5                 = (0x0b), /*!< Timer5 event counter input / toggle output */
	PB10_I2C1_SDA            = (0x0c), /*!< I2C1 data input/output pin. */
	PB10_INT1                = (0x0d), /*!< External interrupt1 input pin. */

	/* PB.11 MFP */
	PB11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PB11_EPWM2_BRAKE1        = (0x01), /*!< Brake input pin 1 of EPWM2. */
	PB11_UART2_TXD           = (0x02), /*!< Data transmitter output pin for UART2. */
	PB11_CAN0_TXD            = (0x03), /*!< CAN0 bus transmitter output. */
	PB11_USBHL2_DP           = (0x04), /*!< USB 1.1 host-lite 2 differential signal D+. */
	PB11_SPI0_MISO           = (0x05), /*!< 1st SPI0 MISO (Master In, Slave Out) pin. */
	PB11_I2S1_MCLK           = (0x06), /*!< I2S1 master clock output pin. */
	PB11_VCAP1_SFIELD        = (0x07), /*!< Camera capture 1 interface SFIELD input pin. */
	PB11_ADC0_CH3            = (0x08), /*!< ADC0 channel 3 analog input. */
	PB11_EBI_nCS2            = (0x09), /*!< EBI chip select enable output pin. */
	PB11_EBI_ALE             = (0x0a), /*!< EBI address latch enable output pin. */
	PB11_TM5_EXT             = (0x0b), /*!< Timer5 event counter input / toggle output */
	PB11_I2C1_SCL            = (0x0c), /*!< I2C1 clock pin. */
	PB11_INT2                = (0x0d), /*!< External interrupt2 input pin. */

	/* PB.12 MFP */
	PB12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PB12_EPWM2_CH0           = (0x01), /*!< EPWM2 channel0 output/capture input. */
	PB12_UART4_nCTS          = (0x02), /*!< Clear to Send input pin for UART4. */
	PB12_UART3_RXD           = (0x03), /*!< Data receiver input pin for UART3. */
	PB12_I2C3_SDA            = (0x04), /*!< I2C3 data input/output pin. */
	PB12_CAN2_RXD            = (0x05), /*!< CAN2 bus receiver input. */
	PB12_I2S1_LRCK           = (0x06), /*!< I2S1 left right channel clock. */
	PB12_USBHL1_DM           = (0x07), /*!< USB 1.1 host-lite 1 differential signal D-. */
	PB12_ADC0_CH4            = (0x08), /*!< ADC0 channel 4 analog input. */
	PB12_EBI_ADR16           = (0x09), /*!< EBI address/data bus bit*. */

	/* PB.13 MFP */
	PB13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PB13_EPWM2_CH1           = (0x01), /*!< EPWM2 channel1 output/capture input. */
	PB13_UART4_nRTS          = (0x02), /*!< Request to Send output pin for UART4. */
	PB13_UART3_TXD           = (0x03), /*!< Data transmitter output pin for UART3. */
	PB13_I2C3_SCL            = (0x04), /*!< I2C3 clock pin. */
	PB13_CAN2_TXD            = (0x05), /*!< CAN2 bus transmitter output. */
	PB13_I2S1_BCLK           = (0x06), /*!< I2S1 bit clock pin. */
	PB13_USBHL1_DP           = (0x07), /*!< USB 1.1 host-lite 1 differential signal D+. */
	PB13_ADC0_CH5            = (0x08), /*!< ADC0 channel 5 analog input. */
	PB13_EBI_ADR17           = (0x09), /*!< EBI address/data bus bit*. */

	/* PB.14 MFP */
	PB14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PB14_EPWM2_CH2           = (0x01), /*!< EPWM2 channel2 output/capture input. */
	PB14_UART4_RXD           = (0x02), /*!< Data receiver input pin for UART4. */
	PB14_CAN1_RXD            = (0x03), /*!< CAN1 bus receiver input. */
	PB14_USBHL3_DM           = (0x04), /*!< USB 1.1 host-lite 3 differential signal D-. */
	PB14_I2C4_SDA            = (0x05), /*!< I2C4 data input/output pin. */
	PB14_I2S1_DI             = (0x06), /*!< I2S1 data input. */
	PB14_ADC0_CH6            = (0x08), /*!< ADC0 channel 6 analog input. */
	PB14_EBI_ADR18           = (0x09), /*!< EBI address/data bus bit*. */

	/* PB.15 MFP */
	PB15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PB15_EPWM2_CH3           = (0x01), /*!< EPWM2 channel3 output/capture input. */
	PB15_UART4_TXD           = (0x02), /*!< Data transmitter output pin for UART4. */
	PB15_CAN1_TXD            = (0x03), /*!< CAN1 bus transmitter output. */
	PB15_USBHL3_DP           = (0x04), /*!< USB 1.1 host-lite 3 differential signal D+. */
	PB15_I2C4_SCL            = (0x05), /*!< I2C4 clock pin. */
	PB15_I2S1_DO             = (0x06), /*!< I2S1 data output. */
	PB15_ADC0_CH7            = (0x08), /*!< ADC0 channel 7 analog input. */
	PB15_EBI_ADR19           = (0x09), /*!< EBI address/data bus bit*. */

	/* PC.0 MFP */
	PC0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PC0_I2C4_SDA             = (0x04), /*!< I2C4 data input/output pin. */
	PC0_eMMC0_CMD            = (0x06), /*!< eMMC0 command/response. */
	PC0_SD0_CMD              = (0x06), /*!< SD/SDIO0 command/response. */

	/* PC.1 MFP */
	PC1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PC1_I2C4_SCL             = (0x04), /*!< I2C4 clock pin. */
	PC1_eMMC0_CLK            = (0x06), /*!< eMMC0 clock. */
	PC1_SD0_CLK              = (0x06), /*!< SD/SDIO0 clock. */

	/* PC.2 MFP */
	PC2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PC2_CAN0_RXD             = (0x03), /*!< CAN0 bus receiver input. */
	PC2_USBHL4_DM            = (0x04), /*!< USB 1.1 host-lite 4 differential signal D-. */
	PC2_eMMC0_DAT0           = (0x06), /*!< eMMC0 data line bit 0. */
	PC2_SD0_DAT0             = (0x06), /*!< SD/SDIO0 data line bit 0. */

	/* PC.3 MFP */
	PC3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PC3_CAN0_TXD             = (0x03), /*!< CAN0 bus transmitter output. */
	PC3_USBHL4_DP            = (0x04), /*!< USB 1.1 host-lite 4 differential signal D+. */
	PC3_eMMC0_DAT1           = (0x06), /*!< eMMC0 data line bit 1. */
	PC3_SD0_DAT1             = (0x06), /*!< SD/SDIO0 data line bit 1. */

	/* PC.4 MFP */
	PC4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PC4_I2C5_SDA             = (0x04), /*!< I2C5 data input/output pin. */
	PC4_eMMC0_DAT2           = (0x06), /*!< eMMC0 data line bit 2. */
	PC4_SD0_DAT2             = (0x06), /*!< SD/SDIO0 data line bit 2. */

	/* PC.5 MFP */
	PC5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PC5_I2C5_SCL             = (0x04), /*!< I2C5 clock pin. */
	PC5_eMMC0_DAT3           = (0x06), /*!< eMMC0 data line bit 3. */
	PC5_SD0_DAT3             = (0x06), /*!< SD/SDIO0 data line bit 3. */

	/* PC.6 MFP */
	PC6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PC6_CAN1_RXD             = (0x03), /*!< CAN1 bus receiver input. */
	PC6_USBHL5_DM            = (0x04), /*!< USB 1.1 host-lite 5 differential signal D-. */
	PC6_SD0_nCD              = (0x06), /*!< SD/SDIO0 card detect */

	/* PC.7 MFP */
	PC7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PC7_CAN1_TXD             = (0x03), /*!< CAN1 bus transmitter output. */
	PC7_USBHL5_DP            = (0x04), /*!< USB 1.1 host-lite 5 differential signal D+. */
	PC7_SD0_WP               = (0x06), /*!< SD/SDIO0 write protect input. */

	/* PC.8 MFP */
	PC8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PC8_EPWM2_CH0            = (0x01), /*!< EPWM2 channel0 output/capture input. */
	PC8_UART10_nCTS          = (0x02), /*!< Clear to Send input pin for UART10. */
	PC8_UART9_RXD            = (0x03), /*!< Data receiver input pin for UART*. */
	PC8_I2C0_SDA             = (0x04), /*!< I2C0 data input/output pin. */
	PC8_SPI1_SS0             = (0x05), /*!< 1st SPI1 slave select pin. */
	PC8_eMMC0_DAT4           = (0x06), /*!< eMMC0 data line bit 4. */

	/* PC.9 MFP */
	PC9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PC9_EPWM2_CH1            = (0x01), /*!< EPWM2 channel1 output/capture input. */
	PC9_UART10_nRTS          = (0x02), /*!< Request to Send output pin for UART10. */
	PC9_UART9_TXD            = (0x03), /*!< Data transmitter output pin for UART*. */
	PC9_I2C0_SCL             = (0x04), /*!< I2C0 clock pin. */
	PC9_SPI1_CLK             = (0x05), /*!< SPI1 serial clock pin. */
	PC9_eMMC0_DAT5           = (0x06), /*!< eMMC0 data line bit 5. */

	/* PC.10 MFP */
	PC10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PC10_EPWM2_CH2           = (0x01), /*!< EPWM2 channel2 output/capture input. */
	PC10_UART10_RXD          = (0x02), /*!< Data receiver input pin for UART10. */
	PC10_CAN2_RXD            = (0x03), /*!< CAN2 bus receiver input. */
	PC10_USBHL0_DM           = (0x04), /*!< USB 1.1 host-lite 0 differential signal D-. */
	PC10_SPI1_MOSI           = (0x05), /*!< 1st SPI1 MOSI (Master Out, Slave In) pin. */
	PC10_eMMC0_DAT6          = (0x06), /*!< eMMC0 data line bit 6. */

	/* PC.11 MFP */
	PC11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PC11_EPWM2_CH3           = (0x01), /*!< EPWM2 channel3 output/capture input. */
	PC11_UART10_TXD          = (0x02), /*!< Data transmitter output pin for UART10. */
	PC11_CAN2_TXD            = (0x03), /*!< CAN2 bus transmitter output. */
	PC11_USBHL0_DP           = (0x04), /*!< USB 1.1 host-lite 0 differential signal D+. */
	PC11_SPI1_MISO           = (0x05), /*!< 1st SPI1 MISO (Master In, Slave Out) pin. */
	PC11_eMMC0_DAT7          = (0x06), /*!< eMMC0 data line bit 7. */

	/* PC.12 MFP */
	PC12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PC12_UART12_nCTS         = (0x02), /*!< Clear to Send input pin for UART12. */
	PC12_UART11_RXD          = (0x03), /*!< Data receiver input pin for UART11. */
	PC12_LCM_DATA16          = (0x06), /*!< TFT LCD Module Pixel Data output bit 1 in Sync-type mode. */

	/* PC.13 MFP */
	PC13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PC13_UART12_nRTS         = (0x02), /*!< Request to Send output pin for UART12. */
	PC13_UART11_TXD          = (0x03), /*!< Data transmitter output pin for UART11. */
	PC13_LCM_DATA17          = (0x06), /*!< TFT LCD Module Pixel Data output bit 1 in Sync-type mode. */
	PC13_LCM_MPU_DATA17      = (0x06), /*!< TFT LCD Module Command/Data input/output bit 1 in MPU-type mode. */

	/* PC.14 MFP */
	PC14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PC14_UART12_RXD          = (0x02), /*!< Data receiver input pin for UART12. */
	PC14_LCM_DATA18          = (0x06), /*!< TFT LCD Module Pixel Data output bit 1 in Sync-type mode. */
	PC14_LCM_MPU_CSX         = (0x06), /*!< TFT LCD Module Chip Selection output pin in MPU-type 80/68 mode. */

	/* PC.15 MFP */
	PC15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PC15_UART12_TXD          = (0x02), /*!< Data transmitter output pin for UART12. */
	PC15_LCM_DATA19          = (0x06), /*!< TFT LCD Module Pixel Data output bit 1 in Sync-type mode. */
	PC15_LCM_MPU_TE          = (0x07), /*!< TFT LCD Module TE input pin in MPU-type mode. */
	PC15_LCM_MPU_VSYNC       = (0x08), /*!< TFT LCD Module VSYNC output pin in MPU-type mode. */

	/* PD.0 MFP */
	PD0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PD0_UART3_nCTS           = (0x02), /*!< Clear to Send input pin for UART3. */
	PD0_UART4_RXD            = (0x03), /*!< Data receiver input pin for UART4. */
	PD0_QSPI0_SS0            = (0x05), /*!< Quad SPI0 slave select pin. */

	/* PD.1 MFP */
	PD1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PD1_UART3_nRTS           = (0x02), /*!< Request to Send output pin for UART3. */
	PD1_UART4_TXD            = (0x03), /*!< Data transmitter output pin for UART4. */
	PD1_QSPI0_CLK            = (0x05), /*!< Quad SPI0 serial clock pin. */

	/* PD.2 MFP */
	PD2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PD2_UART3_RXD            = (0x02), /*!< Data receiver input pin for UART3. */
	PD2_QSPI0_MOSI0          = (0x05), /*!< Quad SPI0 MOSI0 (Master Out, Slave In) pin. */

	/* PD.3 MFP */
	PD3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PD3_UART3_TXD            = (0x02), /*!< Data transmitter output pin for UART3. */
	PD3_QSPI0_MISO0          = (0x05), /*!< Quad SPI0 MISO0 (Master In, Slave Out) pin. */

	/* PD.4 MFP */
	PD4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PD4_UART1_nCTS           = (0x02), /*!< Clear to Send input pin for UART1. */
	PD4_UART2_RXD            = (0x03), /*!< Data receiver input pin for UART2. */
	PD4_I2C2_SDA             = (0x04), /*!< I2C2 data input/output pin. */
	PD4_QSPI0_MOSI1          = (0x05), /*!< Quad SPI0 MOSI1 (Master Out, Slave In) pin. */

	/* PD.5 MFP */
	PD5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PD5_UART1_nRTS           = (0x02), /*!< Request to Send output pin for UART1. */
	PD5_UART2_TXD            = (0x03), /*!< Data transmitter output pin for UART2. */
	PD5_I2C2_SCL             = (0x04), /*!< I2C2 clock pin. */
	PD5_QSPI0_MISO1          = (0x05), /*!< Quad SPI0 MISO1 (Master In, Slave Out) pin. */

	/* PD.6 MFP */
	PD6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PD6_EPWM0_SYNC_IN        = (0x01), /*!< EPWM0 counter synchronous trigger input pin. */
	PD6_UART1_RXD            = (0x02), /*!< Data receiver input pin for UART1. */
	PD6_USBHL3_DM            = (0x04), /*!< USB 1.1 host-lite 3 differential signal D-. */
	PD6_QSPI1_MOSI1          = (0x05), /*!< Quad SPI1 MOSI1 (Master Out, Slave In) pin. */
	PD6_I2C0_SDA             = (0x06), /*!< I2C0 data input/output pin. */
	PD6_I2S0_MCLK            = (0x07), /*!< I2S0 master clock output pin. */
	PD6_EPWM0_CH0            = (0x08), /*!< EPWM0 channel0 output/capture input. */
	PD6_EBI_AD5              = (0x09), /*!< EBI address/data bus bit5. */
	PD6_SPI3_SS1             = (0x0a), /*!< 1st SPI3 slave select pin. */
	PD6_TRACE_CLK            = (0x0b), /*!< ETM Rx clock input pin. */

	/* PD.7 MFP */
	PD7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PD7_EPWM0_SYNC_OUT       = (0x01), /*!< EPWM0 counter synchronous trigger output pin. */
	PD7_UART1_TXD            = (0x02), /*!< Data transmitter output pin for UART1. */
	PD7_USBHL3_DP            = (0x04), /*!< USB 1.1 host-lite 3 differential signal D+. */
	PD7_QSPI1_MISO1          = (0x05), /*!< Quad SPI1 MISO1 (Master In, Slave Out) pin. */
	PD7_I2C0_SCL             = (0x06), /*!< I2C0 clock pin. */
	PD7_I2S1_MCLK            = (0x07), /*!< I2S1 master clock output pin. */
	PD7_EPWM0_CH1            = (0x08), /*!< EPWM0 channel1 output/capture input. */
	PD7_EBI_AD6              = (0x09), /*!< EBI address/data bus bit6. */
	PD7_SC1_nCD              = (0x0a), /*!< SmartCard1 card detect pin. */

	/* PD.8 MFP */
	PD8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PD8_EPWM0_BRAKE0         = (0x01), /*!< Brake input pin 0 of EPWM0. */
	PD8_UART16_nCTS          = (0x02), /*!< Clear to Send input pin for UART16. */
	PD8_UART15_RXD           = (0x03), /*!< Data receiver input pin for UART15. */
	PD8_QSPI1_SS0            = (0x05), /*!< Quad SPI1 slave select pin. */
	PD8_I2S1_LRCK            = (0x07), /*!< I2S1 left right channel clock. */
	PD8_EPWM0_CH2            = (0x08), /*!< EPWM0 channel2 output/capture input. */
	PD8_EBI_AD7              = (0x09), /*!< EBI address/data bus bit7. */
	PD8_SC1_CLK              = (0x0a), /*!< SmartCard1 clock pin. */
	PD8_TM0                  = (0x0b), /*!< Timer0 event counter input / toggle output */

	/* PD.9 MFP */
	PD9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PD9_EPWM0_BRAKE1         = (0x01), /*!< Brake input pin 1 of EPWM0. */
	PD9_UART16_nRTS          = (0x02), /*!< Request to Send output pin for UART16. */
	PD9_UART15_TXD           = (0x03), /*!< Data transmitter output pin for UART15. */
	PD9_QSPI1_CLK            = (0x05), /*!< Quad SPI1 serial clock pin. */
	PD9_I2S1_BCLK            = (0x07), /*!< I2S1 bit clock pin. */
	PD9_EPWM0_CH3            = (0x08), /*!< EPWM0 channel3 output/capture input. */
	PD9_EBI_AD8              = (0x09), /*!< EBI address/data bus bit8. */
	PD9_SC1_DAT              = (0x0a), /*!< SmartCard1 data pin. */
	PD9_TM0_EXT              = (0x0b), /*!< Timer0 event counter input / toggle output */

	/* PD.10 MFP */
	PD10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PD10_EPWM1_BRAKE0        = (0x01), /*!< Brake input pin 0 of EPWM1. */
	PD10_UART16_RXD          = (0x02), /*!< Data receiver input pin for UART16. */
	PD10_QSPI1_MOSI0         = (0x05), /*!< Quad SPI1 MOSI0 (Master Out, Slave In) pin. */
	PD10_I2S1_DI             = (0x07), /*!< I2S1 data input. */
	PD10_EPWM0_CH4           = (0x08), /*!< EPWM0 channel4 output/capture input. */
	PD10_EBI_AD9             = (0x09), /*!< EBI address/data bus bit9. */
	PD10_SC1_RST             = (0x0a), /*!< SmartCard1 reset pin. */
	PD10_TM2                 = (0x0b), /*!< Timer2 event counter input / toggle output */

	/* PD.11 MFP */
	PD11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PD11_EPWM1_BRAKE1        = (0x01), /*!< Brake input pin 1 of EPWM1. */
	PD11_UART16_TXD          = (0x02), /*!< Data transmitter output pin for UART16. */
	PD11_QSPI1_MISO0         = (0x05), /*!< Quad SPI1 MISO0 (Master In, Slave Out) pin. */
	PD11_I2S1_DO             = (0x07), /*!< I2S1 data output. */
	PD11_EPWM0_CH5           = (0x08), /*!< EPWM0 channel5 output/capture input. */
	PD11_EBI_AD10            = (0x09), /*!< EBI address/data bus bit1. */
	PD11_SC1_PWR             = (0x0a), /*!< SmartCard1 power pin. */
	PD11_TM2_EXT             = (0x0b), /*!< Timer2 event counter input / toggle output */

	/* PD.12 MFP */
	PD12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PD12_EPWM0_BRAKE0        = (0x01), /*!< Brake input pin 0 of EPWM0. */
	PD12_UART11_TXD          = (0x02), /*!< Data transmitter output pin for UART11. */
	PD12_UART10_RXD          = (0x03), /*!< Data receiver input pin for UART10. */
	PD12_I2C4_SDA            = (0x04), /*!< I2C4 data input/output pin. */
	PD12_TRACE_DATA0         = (0x06), /*!< ETM Rx input bus bit0. */
	PD12_EBI_nCS1            = (0x07), /*!< EBI chip select enable output pin. */
	PD12_EBI_AD4             = (0x08), /*!< EBI address/data bus bit4. */
	PD12_TM5                 = (0x0b), /*!< Timer5 event counter input / toggle output */
	PD12_I2S1_LRCK           = (0x0c), /*!< I2S1 left right channel clock. */
	PD12_INT1                = (0x0d), /*!< External interrupt1 input pin. */

	/* PD.13 MFP */
	PD13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PD13_EPWM0_BRAKE1        = (0x01), /*!< Brake input pin 1 of EPWM0. */
	PD13_UART11_RXD          = (0x02), /*!< Data receiver input pin for UART11. */
	PD13_UART10_TXD          = (0x03), /*!< Data transmitter output pin for UART10. */
	PD13_I2C4_SCL            = (0x04), /*!< I2C4 clock pin. */
	PD13_TRACE_DATA1         = (0x06), /*!< ETM Rx input bus bit1. */
	PD13_EBI_nCS2            = (0x07), /*!< EBI chip select enable output pin. */
	PD13_EBI_AD5             = (0x08), /*!< EBI address/data bus bit5. */
	PD13_TM5_EXT             = (0x0b), /*!< Timer5 event counter input / toggle output */
	PD13_I2S1_BCLK           = (0x0c), /*!< I2S1 bit clock pin. */

	/* PD.14 MFP */
	PD14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PD14_EPWM0_SYNC_IN       = (0x01), /*!< EPWM0 counter synchronous trigger input pin. */
	PD14_UART11_nCTS         = (0x02), /*!< Clear to Send input pin for UART11. */
	PD14_CAN3_RXD            = (0x03), /*!< CAN3 bus receiver input. */
	PD14_USBHL5_DM           = (0x04), /*!< USB 1.1 host-lite 5 differential signal D-. */
	PD14_TRACE_DATA2         = (0x06), /*!< ETM Rx input bus bit2. */
	PD14_EBI_MCLK            = (0x07), /*!< EBI external clock output pin. */
	PD14_EBI_AD6             = (0x08), /*!< EBI address/data bus bit6. */
	PD14_TM6                 = (0x0b), /*!< Timer6 event counter input / toggle output */
	PD14_I2S1_DI             = (0x0c), /*!< I2S1 data input. */
	PD14_INT3                = (0x0d), /*!< External interrupt3 input pin. */

	/* PD.15 MFP */
	PD15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PD15_EPWM0_SYNC_OUT      = (0x01), /*!< EPWM0 counter synchronous trigger output pin. */
	PD15_UART11_nRTS         = (0x02), /*!< Request to Send output pin for UART11. */
	PD15_CAN3_TXD            = (0x03), /*!< CAN3 bus transmitter output. */
	PD15_USBHL5_DP           = (0x04), /*!< USB 1.1 host-lite 5 differential signal D+. */
	PD15_TRACE_DATA3         = (0x06), /*!< ETM Rx input bus bit3. */
	PD15_EBI_ALE             = (0x07), /*!< EBI address latch enable output pin. */
	PD15_EBI_AD7             = (0x08), /*!< EBI address/data bus bit7. */
	PD15_TM6_EXT             = (0x0b), /*!< Timer6 event counter input / toggle output */
	PD15_I2S1_DO             = (0x0c), /*!< I2S1 data output. */

	/* PE.0 MFP */
	PE0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PE0_UART9_nCTS           = (0x02), /*!< Clear to Send input pin for UART*. */
	PE0_UART8_RXD            = (0x03), /*!< Data receiver input pin for UART8. */
	PE0_VCAP1_DATA0          = (0x07), /*!< Camera capture 1 data input bus bit 0. */
	PE0_RGMII0_MDC           = (0x08), /*!< RGMII0 Management Data Clock. */
	PE0_RMII0_MDC            = (0x09), /*!< RMII0 PHY Management Clock output pin. */

	/* PE.1 MFP */
	PE1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PE1_UART9_nRTS           = (0x02), /*!< Request to Send output pin for UART*. */
	PE1_UART8_TXD            = (0x03), /*!< Data transmitter output pin for UART8. */
	PE1_VCAP1_DATA1          = (0x07), /*!< Camera capture 1 data input bus bit 1. */
	PE1_RGMII0_MDIO          = (0x08), /*!< RGMII0 PHY Management Data pin. */
	PE1_RMII0_MDIO           = (0x09), /*!< RMII0 PHY Management Data pin. */

	/* PE.2 MFP */
	PE2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PE2_UART9_RXD            = (0x02), /*!< Data receiver input pin for UART*. */
	PE2_VCAP1_DATA2          = (0x07), /*!< Camera capture 1 data input bus bit 2. */
	PE2_RGMII0_TXCTL         = (0x08), /*!< RGMII0 Transmit Control output pin. */
	PE2_RMII0_TXEN           = (0x09), /*!< RMII0 Transmit Enable output pin. */

	/* PE.3 MFP */
	PE3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PE3_UART9_TXD            = (0x02), /*!< Data transmitter output pin for UART*. */
	PE3_VCAP1_DATA3          = (0x07), /*!< Camera capture 1 data input bus bit 3. */
	PE3_RGMII0_TXD0          = (0x08), /*!< MII/RMII Transmit Data bus bit 0. */
	PE3_RMII0_TXD0           = (0x09), /*!< RMII0 Transmit Data bus bit 0. */

	/* PE.4 MFP */
	PE4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PE4_UART4_nCTS           = (0x02), /*!< Clear to Send input pin for UART4. */
	PE4_UART3_RXD            = (0x03), /*!< Data receiver input pin for UART3. */
	PE4_VCAP1_DATA4          = (0x07), /*!< Camera capture 1 data input bus bit 4. */
	PE4_RGMII0_TXD1          = (0x08), /*!< MII/RMII Transmit Data bus bit 1. */
	PE4_RMII0_TXD1           = (0x09), /*!< RMII0 Transmit Data bus bit 1. */

	/* PE.5 MFP */
	PE5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PE5_UART4_nRTS           = (0x02), /*!< Request to Send output pin for UART4. */
	PE5_UART3_TXD            = (0x03), /*!< Data transmitter output pin for UART3. */
	PE5_VCAP1_DATA5          = (0x07), /*!< Camera capture 1 data input bus bit 5. */
	PE5_RGMII0_RXCLK         = (0x08), /*!< RGMII0 Mode RX Clock input pin. */
	PE5_RMII0_REFCLK         = (0x09), /*!< RMII0 Reference Clock input pin. */

	/* PE.6 MFP */
	PE6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PE6_UART4_RXD            = (0x02), /*!< Data receiver input pin for UART4. */
	PE6_VCAP1_DATA6          = (0x07), /*!< Camera capture 1 data input bus bit 6. */
	PE6_RGMII0_RXCTL         = (0x08), /*!< RGMII0 Receive Control input pin. */
	PE6_RMII0_CRSDV          = (0x09), /*!< RMII0 Carrier Sense/Receive Data input pin. */

	/* PE.7 MFP */
	PE7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PE7_UART4_TXD            = (0x02), /*!< Data transmitter output pin for UART4. */
	PE7_VCAP1_DATA7          = (0x07), /*!< Camera capture 1 data input bus bit 7. */
	PE7_RGMII0_RXD0          = (0x08), /*!< RGMII0 Receive Data bus bit 0. */
	PE7_RMII0_RXD0           = (0x09), /*!< RMII0 Receive Data bus bit 0. */

	/* PE.8 MFP */
	PE8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PE8_UART13_nCTS          = (0x02), /*!< Clear to Send input pin for UART13. */
	PE8_UART12_RXD           = (0x03), /*!< Data receiver input pin for UART12. */
	PE8_VCAP1_SCLK           = (0x07), /*!< Camera capture 1 interface sensor clock output pin. */
	PE8_RGMII0_RXD1          = (0x08), /*!< RGMII0 Receive Data bus bit 1. */
	PE8_RMII0_RXD1           = (0x09), /*!< RMII0 Receive Data bus bit 1. */

	/* PE.9 MFP */
	PE9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PE9_UART13_nRTS          = (0x02), /*!< Request to Send output pin for UART13. */
	PE9_UART12_TXD           = (0x03), /*!< Data transmitter output pin for UART12. */
	PE9_VCAP1_PIXCLK         = (0x07), /*!< Camera capture 1 interface pixel clock input pin. */
	PE9_RGMII0_RXD2          = (0x08), /*!< RGMII0 Receive Data bus bit 2. */
	PE9_RMII0_RXERR          = (0x09), /*!< RMII0 Receive Data Error input pin. */

	/* PE.10 MFP */
	PE10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PE10_UART15_nCTS         = (0x02), /*!< Clear to Send input pin for UART15. */
	PE10_UART14_RXD          = (0x03), /*!< Data receiver input pin for UART14. */
	PE10_SPI1_SS0            = (0x05), /*!< 1st SPI1 slave select pin. */
	PE10_VCAP1_HSYNC         = (0x07), /*!< Camera capture 1 interface hsync input pin. */
	PE10_RGMII0_RXD3         = (0x08), /*!< RGMII0 Receive Data bus bit 3. */

	/* PE.11 MFP */
	PE11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PE11_UART15_nRTS         = (0x02), /*!< Request to Send output pin for UART15. */
	PE11_UART14_TXD          = (0x03), /*!< Data transmitter output pin for UART14. */
	PE11_SPI1_CLK            = (0x05), /*!< SPI1 serial clock pin. */
	PE11_VCAP1_VSYNC         = (0x07), /*!< Camera capture 1 interface vsync input pin. */
	PE11_RGMII0_TXCLK        = (0x08), /*!< RGMII0 Mode TX Clock output pin. */

	/* PE.12 MFP */
	PE12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PE12_UART15_RXD          = (0x02), /*!< Data receiver input pin for UART15. */
	PE12_SPI1_MOSI           = (0x05), /*!< 1st SPI1 MOSI (Master Out, Slave In) pin. */
	PE12_VCAP1_DATA8         = (0x07), /*!< Camera capture 1 data input bus bit 8. */
	PE12_RGMII0_TXD2         = (0x08), /*!< MII/RMII Transmit Data bus bit 2. */

	/* PE.13 MFP */
	PE13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PE13_UART15_TXD          = (0x02), /*!< Data transmitter output pin for UART15. */
	PE13_SPI1_MISO           = (0x05), /*!< 1st SPI1 MISO (Master In, Slave Out) pin. */
	PE13_VCAP1_DATA9         = (0x07), /*!< Camera capture 1 data input bus bit 9. */
	PE13_RGMII0_TXD3         = (0x08), /*!< MII/RMII Transmit Data bus bit 3. */

	/* PE.14 MFP */
	PE14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PE14_UART0_TXD           = (0x01), /*!< Data transmitter output pin for UART0. */

	/* PE.15 MFP */
	PE15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PE15_UART0_RXD           = (0x01), /*!< Data receiver input pin for UART0. */

	/* PF.0 MFP */
	PF0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PF0_UART2_nCTS           = (0x02), /*!< Clear to Send input pin for UART2. */
	PF0_UART1_RXD            = (0x03), /*!< Data receiver input pin for UART1. */
	PF0_RGMII0_RXD3          = (0x06), /*!< RGMII0 Receive Data bus bit 3. */
	PF0_RGMII1_MDC           = (0x08), /*!< RGMII1 Management Data Clock. */
	PF0_RMII1_MDC            = (0x09), /*!< RMII1 PHY Management Clock output pin. */
	PF0_KPI_COL0             = (0x0e), /*!< Keypad Interface Column 0 output pin. */

	/* PF.1 MFP */
	PF1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PF1_UART2_nRTS           = (0x02), /*!< Request to Send output pin for UART2. */
	PF1_UART1_TXD            = (0x03), /*!< Data transmitter output pin for UART1. */
	PF1_RGMII0_TXCLK         = (0x06), /*!< RGMII0 Mode TX Clock output pin. */
	PF1_RGMII1_MDIO          = (0x08), /*!< RGMII1 PHY Management Data pin. */
	PF1_RMII1_MDIO           = (0x09), /*!< RMII1 PHY Management Data pin. */
	PF1_KPI_COL1             = (0x0e), /*!< Keypad Interface Column 1 output pin. */

	/* PF.2 MFP */
	PF2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PF2_UART2_RXD            = (0x02), /*!< Data receiver input pin for UART2. */
	PF2_RGMII0_TXD2          = (0x06), /*!< MII/RMII Transmit Data bus bit 2. */
	PF2_RGMII1_TXCTL         = (0x08), /*!< RGMII1 Transmit Control output pin. */
	PF2_RMII1_TXEN           = (0x09), /*!< RMII1 Transmit Enable output pin. */
	PF2_KPI_COL2             = (0x0e), /*!< Keypad Interface Column 2 output pin. */

	/* PF.3 MFP */
	PF3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PF3_UART2_TXD            = (0x02), /*!< Data transmitter output pin for UART2. */
	PF3_RGMII0_TXD3          = (0x06), /*!< MII/RMII Transmit Data bus bit 3. */
	PF3_RGMII1_TXD0          = (0x08), /*!< MII/RMII Transmit Data bus bit 0. */
	PF3_RMII1_TXD0           = (0x09), /*!< RMII1 Transmit Data bus bit 0. */
	PF3_KPI_COL3             = (0x0e), /*!< Keypad Interface Column 3 output pin. */

	/* PF.4 MFP */
	PF4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PF4_UART11_nCTS          = (0x02), /*!< Clear to Send input pin for UART11. */
	PF4_UART10_RXD           = (0x03), /*!< Data receiver input pin for UART10. */
	PF4_I2S0_LRCK            = (0x04), /*!< I2S0 left right channel clock. */
	PF4_SPI1_SS0             = (0x05), /*!< 1st SPI1 slave select pin. */
	PF4_RGMII1_TXD1          = (0x08), /*!< MII/RMII Transmit Data bus bit 1. */
	PF4_RMII1_TXD1           = (0x09), /*!< RMII1 Transmit Data bus bit 1. */
	PF4_USBHL0_DM            = (0x0c), /*!< USB 1.1 host-lite 0 differential signal D-. */
	PF4_CAN2_RXD             = (0x0d), /*!< CAN2 bus receiver input. */
	PF4_KPI_ROW0             = (0x0e), /*!< Keypad Interface Row 0 input pin. */

	/* PF.5 MFP */
	PF5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PF5_UART11_nRTS          = (0x02), /*!< Request to Send output pin for UART11. */
	PF5_UART10_TXD           = (0x03), /*!< Data transmitter output pin for UART10. */
	PF5_I2S0_BCLK            = (0x04), /*!< I2S0 bit clock pin. */
	PF5_SPI1_CLK             = (0x05), /*!< SPI1 serial clock pin. */
	PF5_RGMII1_RXCLK         = (0x08), /*!< RGMII1 Mode RX Clock input pin. */
	PF5_RMII1_REFCLK         = (0x09), /*!< RMII1 Reference Clock input pin. */
	PF5_USBHL0_DP            = (0x0c), /*!< USB 1.1 host-lite 0 differential signal D+. */
	PF5_CAN2_TXD             = (0x0d), /*!< CAN2 bus transmitter output. */
	PF5_KPI_ROW1             = (0x0e), /*!< Keypad Interface Row 1 input pin. */

	/* PF.6 MFP */
	PF6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PF6_UART11_RXD           = (0x02), /*!< Data receiver input pin for UART11. */
	PF6_I2S0_DI              = (0x04), /*!< I2S0 data input. */
	PF6_SPI1_MOSI            = (0x05), /*!< 1st SPI1 MOSI (Master Out, Slave In) pin. */
	PF6_RGMII1_RXCTL         = (0x08), /*!< RGMII1 Receive Control input pin. */
	PF6_RMII1_CRSDV          = (0x09), /*!< RMII1 Carrier Sense/Receive Data input pin. */
	PF6_I2C4_SDA             = (0x0a), /*!< I2C4 data input/output pin. */
	PF6_SC0_CLK              = (0x0d), /*!< SmartCard0 clock pin. */
	PF6_KPI_ROW2             = (0x0e), /*!< Keypad Interface Row 2 input pin. */

	/* PF.7 MFP */
	PF7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PF7_UART11_TXD           = (0x02), /*!< Data transmitter output pin for UART11. */
	PF7_I2S0_DO              = (0x04), /*!< I2S0 data output. */
	PF7_SPI1_MISO            = (0x05), /*!< 1st SPI1 MISO (Master In, Slave Out) pin. */
	PF7_RGMII1_RXD0          = (0x08), /*!< RGMII1 Receive Data bus bit 0. */
	PF7_RMII1_RXD0           = (0x09), /*!< RMII1 Receive Data bus bit 0. */
	PF7_I2C4_SCL             = (0x0a), /*!< I2C4 clock pin. */
	PF7_SC0_DAT              = (0x0d), /*!< SmartCard0 data pin. */
	PF7_KPI_ROW3             = (0x0e), /*!< Keypad Interface Row 3 input pin. */

	/* PF.8 MFP */
	PF8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PF8_UART13_RXD           = (0x02), /*!< Data receiver input pin for UART13. */
	PF8_I2C5_SDA             = (0x04), /*!< I2C5 data input/output pin. */
	PF8_SPI0_SS0             = (0x05), /*!< 1st SPI0 slave select pin. */
	PF8_RGMII1_RXD1          = (0x08), /*!< RGMII1 Receive Data bus bit 1. */
	PF8_RMII1_RXD1           = (0x09), /*!< RMII1 Receive Data bus bit 1. */
	PF8_SC0_RST              = (0x0d), /*!< SmartCard0 reset pin. */
	PF8_KPI_COL4             = (0x0e), /*!< Keypad Interface Column 4 output pin. */

	/* PF.9 MFP */
	PF9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PF9_UART13_TXD           = (0x02), /*!< Data transmitter output pin for UART13. */
	PF9_I2C5_SCL             = (0x04), /*!< I2C5 clock pin. */
	PF9_SPI0_SS1             = (0x05), /*!< 1st SPI0 slave select pin. */
	PF9_RGMII1_RXD2          = (0x08), /*!< RGMII1 Receive Data bus bit 2. */
	PF9_RMII1_RXERR          = (0x09), /*!< RMII1 Receive Data Error input pin. */
	PF9_SC0_PWR              = (0x0d), /*!< SmartCard0 power pin. */
	PF9_KPI_COL5             = (0x0e), /*!< Keypad Interface Column 5 output pin. */

	/* PF.10 MFP */
	PF10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PF10_UART13_nCTS         = (0x02), /*!< Clear to Send input pin for UART13. */
	PF10_I2S0_LRCK           = (0x05), /*!< I2S0 left right channel clock. */
	PF10_SPI1_SS0            = (0x06), /*!< 1st SPI1 slave select pin. */
	PF10_RGMII1_RXD3         = (0x08), /*!< RGMII1 Receive Data bus bit 3. */
	PF10_SC0_CLK             = (0x09), /*!< SmartCard0 clock pin. */
	PF10_KPI_COL6            = (0x0e), /*!< Keypad Interface Column 6 output pin. */

	/* PF.11 MFP */
	PF11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PF11_UART13_nRTS         = (0x02), /*!< Request to Send output pin for UART13. */
	PF11_I2S0_BCLK           = (0x05), /*!< I2S0 bit clock pin. */
	PF11_SPI1_CLK            = (0x06), /*!< SPI1 serial clock pin. */
	PF11_RGMII1_TXCLK        = (0x08), /*!< RGMII1 Mode TX Clock output pin. */
	PF11_SC0_DAT             = (0x09), /*!< SmartCard0 data pin. */
	PF11_KPI_COL7            = (0x0e), /*!< Keypad Interface Column 7 output pin. */

	/* PF.12 MFP */
	PF12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PF12_I2S0_DI             = (0x05), /*!< I2S0 data input. */
	PF12_SPI1_MOSI           = (0x06), /*!< 1st SPI1 MOSI (Master Out, Slave In) pin. */
	PF12_RGMII1_TXD2         = (0x08), /*!< MII/RMII Transmit Data bus bit 2. */
	PF12_SC0_RST             = (0x09), /*!< SmartCard0 reset pin. */
	PF12_KPI_ROW4            = (0x0e), /*!< Keypad Interface Row 4 input pin. */

	/* PF.13 MFP */
	PF13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PF13_I2S0_DO             = (0x05), /*!< I2S0 data output. */
	PF13_SPI1_MISO           = (0x06), /*!< 1st SPI1 MISO (Master In, Slave Out) pin. */
	PF13_RGMII1_TXD3         = (0x08), /*!< MII/RMII Transmit Data bus bit 3. */
	PF13_SC0_PWR             = (0x09), /*!< SmartCard0 power pin. */
	PF13_KPI_ROW5            = (0x0e), /*!< Keypad Interface Row 5 input pin. */

	/* PF.14 MFP */
	PF14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PF14_EPWM2_BRAKE0        = (0x01), /*!< Brake input pin 0 of EPWM2. */
	PF14_RGMII1_PPS          = (0x03), /*!< RGMII1 Pulse Per Second output pin. */
	PF14_RMII1_PPS           = (0x04), /*!< RMII1 Pulse Per Second output pin. */
	PF14_SPI0_I2SMCLK        = (0x05), /*!< SPI0 I2S master clock output pin. */
	PF14_SPI1_I2SMCLK        = (0x06), /*!< SPI1 I2S master clock output pin. */
	PF14_VCAP1_SFIELD        = (0x07), /*!< Camera capture 1 interface SFIELD input pin. */
	PF14_RGMII0_PPS          = (0x08), /*!< RGMII0 Pulse Per Second output pin. */
	PF14_RMII0_PPS           = (0x09), /*!< RMII0 Pulse Per Second output pin. */
	PF14_TM0                 = (0x0b), /*!< Timer0 event counter input / toggle output */
	PF14_INT0                = (0x0c), /*!< External interrupt0 input pin. */
	PF14_SPI1_SS1            = (0x0d), /*!< 1st SPI1 slave select pin. */
	PF14_I2S0_MCLK           = (0x0f), /*!< I2S0 master clock output pin. */

	/* PF.15 MFP */
	PF15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PF15_HSUSB0_VBUSVLD      = (0x01), /*!< HSUSB0 external VBUS regulator status pin. */

	/* PG.0 MFP */
	PG0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PG0_EPWM0_CH0            = (0x01), /*!< EPWM0 channel0 output/capture input. */
	PG0_UART7_TXD            = (0x02), /*!< Data transmitter output pin for UART7. */
	PG0_CAN3_TXD             = (0x03), /*!< CAN3 bus transmitter output. */
	PG0_SPI0_SS0             = (0x05), /*!< 1st SPI0 slave select pin. */
	PG0_EBI_AD15             = (0x07), /*!< EBI address/data bus bit1. */
	PG0_I2S1_MCLK            = (0x09), /*!< I2S1 master clock output pin. */
	PG0_TM1                  = (0x0b), /*!< Timer1 event counter input / toggle output */
	PG0_CLKO                 = (0x0c), /*!< Clock Output pin. */
	PG0_INT0                 = (0x0d), /*!< External interrupt0 input pin. */
	PG0_EBI_ADR15            = (0x0f), /*!< EBI address/data bus bit*. */

	/* PG.1 MFP */
	PG1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PG1_EPWM0_CH3            = (0x01), /*!< EPWM0 channel3 output/capture input. */
	PG1_UART9_nRTS           = (0x02), /*!< Request to Send output pin for UART*. */
	PG1_UART6_TXD            = (0x03), /*!< Data transmitter output pin for UART6. */
	PG1_I2C4_SCL             = (0x04), /*!< I2C4 clock pin. */
	PG1_CAN2_TXD             = (0x05), /*!< CAN2 bus transmitter output. */
	PG1_USBHL0_DP            = (0x06), /*!< USB 1.1 host-lite 0 differential signal D+. */
	PG1_EBI_nCS0             = (0x07), /*!< EBI chip select enable output pin. */
	PG1_TM1_EXT              = (0x0b), /*!< Timer1 event counter input / toggle output */
	PG1_RGMII1_PPS           = (0x0e), /*!< RGMII1 Pulse Per Second output pin. */
	PG1_RMII1_PPS            = (0x0f), /*!< RMII1 Pulse Per Second output pin. */

	/* PG.2 MFP */
	PG2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PG2_EPWM0_CH4            = (0x01), /*!< EPWM0 channel4 output/capture input. */
	PG2_UART9_RXD            = (0x02), /*!< Data receiver input pin for UART*. */
	PG2_CAN0_RXD             = (0x03), /*!< CAN0 bus receiver input. */
	PG2_SPI0_SS1             = (0x05), /*!< 1st SPI0 slave select pin. */
	PG2_TSI_SWD_DAT          = (0x06), /*!< Serial wire debug data pin for TSI. */
	PG2_EBI_ADR16            = (0x07), /*!< EBI address/data bus bit*. */
	PG2_EBI_nCS2             = (0x08), /*!< EBI chip select enable output pin. */
	PG2_TM3                  = (0x0b), /*!< Timer3 event counter input / toggle output */
	PG2_INT1                 = (0x0d), /*!< External interrupt1 input pin. */

	/* PG.3 MFP */
	PG3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PG3_EPWM0_CH5            = (0x01), /*!< EPWM0 channel5 output/capture input. */
	PG3_UART9_TXD            = (0x02), /*!< Data transmitter output pin for UART*. */
	PG3_CAN0_TXD             = (0x03), /*!< CAN0 bus transmitter output. */
	PG3_SPI0_I2SMCLK         = (0x05), /*!< SPI0 I2S master clock output pin. */
	PG3_TSI_SWD_CLK          = (0x06), /*!< Serial wire debug clock pin for TSI. */
	PG3_EBI_ADR17            = (0x07), /*!< EBI address/data bus bit*. */
	PG3_EBI_nCS1             = (0x08), /*!< EBI chip select enable output pin. */
	PG3_EBI_MCLK             = (0x09), /*!< EBI external clock output pin. */
	PG3_TM3_EXT              = (0x0b), /*!< Timer3 event counter input / toggle output */
	PG3_I2S1_MCLK            = (0x0c), /*!< I2S1 master clock output pin. */

	/* PG.4 MFP */
	PG4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PG4_EPWM1_CH0            = (0x01), /*!< EPWM1 channel0 output/capture input. */
	PG4_UART5_nCTS           = (0x02), /*!< Clear to Send input pin for UART5. */
	PG4_UART6_RXD            = (0x03), /*!< Data receiver input pin for UART6. */
	PG4_SPI3_SS0             = (0x05), /*!< 1st SPI3 slave select pin. */
	PG4_EBI_ADR18            = (0x07), /*!< EBI address/data bus bit*. */
	PG4_EBI_nCS0             = (0x08), /*!< EBI chip select enable output pin. */
	PG4_I2S1_DO              = (0x09), /*!< I2S1 data output. */
	PG4_SC1_CLK              = (0x0a), /*!< SmartCard1 clock pin. */
	PG4_TM4                  = (0x0b), /*!< Timer4 event counter input / toggle output */
	PG4_TSI_UART_RXD         = (0x0c), /*!< UART data receiver input pin for TSI. */
	PG4_INT2                 = (0x0d), /*!< External interrupt2 input pin. */

	/* PG.5 MFP */
	PG5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PG5_EPWM1_CH1            = (0x01), /*!< EPWM1 channel1 output/capture input. */
	PG5_UART5_nRTS           = (0x02), /*!< Request to Send output pin for UART5. */
	PG5_UART6_TXD            = (0x03), /*!< Data transmitter output pin for UART6. */
	PG5_SPI3_CLK             = (0x05), /*!< SPI3 serial clock pin. */
	PG5_EBI_ADR19            = (0x07), /*!< EBI address/data bus bit*. */
	PG5_EBI_ALE              = (0x08), /*!< EBI address latch enable output pin. */
	PG5_I2S1_DI              = (0x09), /*!< I2S1 data input. */
	PG5_SC1_DAT              = (0x0a), /*!< SmartCard1 data pin. */
	PG5_TM4_EXT              = (0x0b), /*!< Timer4 event counter input / toggle output */
	PG5_TSI_UART_TXD         = (0x0c), /*!< UART data transmitter output pin for TSI. */

	/* PG.6 MFP */
	PG6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PG6_EPWM1_CH2            = (0x01), /*!< EPWM1 channel2 output/capture input. */
	PG6_UART5_RXD            = (0x02), /*!< Data receiver input pin for UART5. */
	PG6_CAN1_RXD             = (0x03), /*!< CAN1 bus receiver input. */
	PG6_SPI3_MOSI            = (0x05), /*!< 1st SPI3 MOSI (Master Out, Slave In) pin. */
	PG6_EBI_nRD              = (0x07), /*!< EBI read enable output pin. */
	PG6_I2S1_BCLK            = (0x09), /*!< I2S1 bit clock pin. */
	PG6_SC1_RST              = (0x0a), /*!< SmartCard1 reset pin. */
	PG6_TM7                  = (0x0b), /*!< Timer7 event counter input / toggle output */
	PG6_INT3                 = (0x0d), /*!< External interrupt3 input pin. */

	/* PG.7 MFP */
	PG7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PG7_EPWM1_CH3            = (0x01), /*!< EPWM1 channel3 output/capture input. */
	PG7_UART5_TXD            = (0x02), /*!< Data transmitter output pin for UART5. */
	PG7_CAN1_TXD             = (0x03), /*!< CAN1 bus transmitter output. */
	PG7_SPI3_MISO            = (0x05), /*!< 1st SPI3 MISO (Master In, Slave Out) pin. */
	PG7_EBI_nWR              = (0x07), /*!< EBI write enable output pin. */
	PG7_I2S1_LRCK            = (0x09), /*!< I2S1 left right channel clock. */
	PG7_SC1_PWR              = (0x0a), /*!< SmartCard1 power pin. */
	PG7_TM7_EXT              = (0x0b), /*!< Timer7 event counter input / toggle output */

	/* PG.8 MFP */
	PG8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PG8_EPWM1_CH4            = (0x01), /*!< EPWM1 channel4 output/capture input. */
	PG8_UART12_RXD           = (0x02), /*!< Data receiver input pin for UART12. */
	PG8_CAN3_RXD             = (0x03), /*!< CAN3 bus receiver input. */
	PG8_USBHL4_DM            = (0x04), /*!< USB 1.1 host-lite 4 differential signal D-. */
	PG8_SPI2_SS0             = (0x05), /*!< 1st SPI2 slave select pin. */
	PG8_LCM_MPU_RDEN         = (0x06), /*!< TFT LCD Module Read(RD)/Enable(EN) output pin in MPU-type 80/68 mode. */
	PG8_LCM_VSYNC            = (0x06), /*!< TFT LCD Module Vertical/Frame sync. output pin in Sync-type mode. */
	PG8_I2C3_SDA             = (0x07), /*!< I2C3 data input/output pin. */
	PG8_EBI_AD7              = (0x0c), /*!< EBI address/data bus bit7. */
	PG8_EBI_nCS0             = (0x0d), /*!< EBI chip select enable output pin. */

	/* PG.9 MFP */
	PG9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PG9_EPWM1_CH5            = (0x01), /*!< EPWM1 channel5 output/capture input. */
	PG9_UART12_TXD           = (0x02), /*!< Data transmitter output pin for UART12. */
	PG9_CAN3_TXD             = (0x03), /*!< CAN3 bus transmitter output. */
	PG9_USBHL4_DP            = (0x04), /*!< USB 1.1 host-lite 4 differential signal D+. */
	PG9_SPI2_CLK             = (0x05), /*!< SPI2 serial clock pin. */
	PG9_LCM_HSYNC            = (0x06), /*!< TFT LCD Module Horizontal/Line sync. output in Sync-type mode. */
	PG9_LCM_MPU_WRX          = (0x06), /*!< TFT LCD Module Write(WR)/ReadWrite(RW) output pin in MPU-type 80/68 mode. */
	PG9_I2C3_SCL             = (0x07), /*!< I2C3 clock pin. */
	PG9_EBI_AD8              = (0x0c), /*!< EBI address/data bus bit8. */
	PG9_EBI_nCS1             = (0x0d), /*!< EBI chip select enable output pin. */

	/* PG.10 MFP */
	PG10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PG10_UART12_nRTS         = (0x02), /*!< Request to Send output pin for UART12. */
	PG10_UART13_TXD          = (0x03), /*!< Data transmitter output pin for UART13. */
	PG10_SPI2_MOSI           = (0x05), /*!< 1st SPI2 MOSI (Master Out, Slave In) pin. */
	PG10_LCM_CLK             = (0x06), /*!< TFT LCD Module Pixel Clock output pin in Sync-type mode. */
	PG10_EBI_AD9             = (0x0c), /*!< EBI address/data bus bit9. */
	PG10_EBI_nWRH            = (0x0d), /*!< EBI write enable output pin. */

	/* PG.11 MFP */
	PG11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PG11_JTAG_TDO            = (0x03), /*!< JTAG data output pin. */
	PG11_I2S0_MCLK           = (0x05), /*!< I2S0 master clock output pin. */
	PG11_EBI_nWRH            = (0x07), /*!< EBI write enable output pin. */
	PG11_EBI_nCS1            = (0x08), /*!< EBI chip select enable output pin. */
	PG11_EBI_AD0             = (0x0a), /*!< EBI address/data bus bit0. */

	/* PG.12 MFP */
	PG12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PG12_JTAG_TCK            = (0x03), /*!< JTAG clock input pin. */
	PG12_SW_CLK              = (0x03), /*!< Serial wire clock input pin. */
	PG12_I2S0_LRCK           = (0x05), /*!< I2S0 left right channel clock. */
	PG12_EBI_nWRL            = (0x07), /*!< EBI write enable output pin. */
	PG12_EBI_AD1             = (0x0a), /*!< EBI address/data bus bit1. */

	/* PG.13 MFP */
	PG13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PG13_JTAG_TMS            = (0x03), /*!< JTAG test mode selection input pin. */
	PG13_SW_DIO              = (0x03), /*!< Serial wire data pin. */
	PG13_I2S0_BCLK           = (0x05), /*!< I2S0 bit clock pin. */
	PG13_EBI_MCLK            = (0x07), /*!< EBI external clock output pin. */
	PG13_EBI_AD2             = (0x0a), /*!< EBI address/data bus bit2. */

	/* PG.14 MFP */
	PG14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PG14_JTAG_TDI            = (0x03), /*!< JTAG data input pin. */
	PG14_I2S0_DI             = (0x05), /*!< I2S0 data input. */
	PG14_EBI_ALE             = (0x07), /*!< EBI address latch enable output pin. */
	PG14_EBI_AD3             = (0x0a), /*!< EBI address/data bus bit3. */

	/* PG.15 MFP */
	PG15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PG15_JTAG_nTRST          = (0x03), /*!< JTAG reset pin. */
	PG15_I2S0_DO             = (0x05), /*!< I2S0 data output. */
	PG15_EBI_nCS0            = (0x07), /*!< EBI chip select enable output pin. */
	PG15_EBI_AD4             = (0x0a), /*!< EBI address/data bus bit4. */

	/* PH.0 MFP */
	PH0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PH0_UART8_nCTS           = (0x02), /*!< Clear to Send input pin for UART8. */
	PH0_UART7_RXD            = (0x03), /*!< Data receiver input pin for UART7. */
	PH0_LCM_DATA8            = (0x06), /*!< TFT LCD Module Pixel Data output bit 8 in Sync-type mode. */
	PH0_LCM_MPU_DATA8        = (0x06), /*!< TFT LCD Module Command/Data input/output bit 8 in MPU-type mode. */

	/* PH.1 MFP */
	PH1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PH1_UART8_nRTS           = (0x02), /*!< Request to Send output pin for UART8. */
	PH1_UART7_TXD            = (0x03), /*!< Data transmitter output pin for UART7. */
	PH1_LCM_DATA9            = (0x06), /*!< TFT LCD Module Pixel Data output bit 9 in Sync-type mode. */
	PH1_LCM_MPU_DATA9        = (0x06), /*!< TFT LCD Module Command/Data input/output bit 9 in MPU-type mode. */

	/* PH.2 MFP */
	PH2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PH2_UART8_RXD            = (0x02), /*!< Data receiver input pin for UART8. */
	PH2_LCM_DATA10           = (0x06), /*!< TFT LCD Module Pixel Data output bit 1 in Sync-type mode. */
	PH2_LCM_MPU_DATA10       = (0x06), /*!< TFT LCD Module Command/Data input/output bit 1 in MPU-type mode. */

	/* PH.3 MFP */
	PH3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PH3_UART8_TXD            = (0x02), /*!< Data transmitter output pin for UART8. */
	PH3_LCM_DATA11           = (0x06), /*!< TFT LCD Module Pixel Data output bit 1 in Sync-type mode. */
	PH3_LCM_MPU_DATA11       = (0x06), /*!< TFT LCD Module Command/Data input/output bit 1 in MPU-type mode. */

	/* PH.4 MFP */
	PH4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PH4_UART10_nCTS          = (0x02), /*!< Clear to Send input pin for UART10. */
	PH4_UART9_RXD            = (0x03), /*!< Data receiver input pin for UART*. */
	PH4_LCM_DATA12           = (0x06), /*!< TFT LCD Module Pixel Data output bit 1 in Sync-type mode. */
	PH4_LCM_MPU_DATA12       = (0x06), /*!< TFT LCD Module Command/Data input/output bit 1 in MPU-type mode. */

	/* PH.5 MFP */
	PH5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PH5_UART10_nRTS          = (0x02), /*!< Request to Send output pin for UART10. */
	PH5_UART9_TXD            = (0x03), /*!< Data transmitter output pin for UART*. */
	PH5_LCM_DATA13           = (0x06), /*!< TFT LCD Module Pixel Data output bit 1 in Sync-type mode. */
	PH5_LCM_MPU_DATA13       = (0x06), /*!< TFT LCD Module Command/Data input/output bit 1 in MPU-type mode. */

	/* PH.6 MFP */
	PH6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PH6_UART10_RXD           = (0x02), /*!< Data receiver input pin for UART10. */
	PH6_LCM_DATA14           = (0x06), /*!< TFT LCD Module Pixel Data output bit 1 in Sync-type mode. */
	PH6_LCM_MPU_DATA14       = (0x06), /*!< TFT LCD Module Command/Data input/output bit 1 in MPU-type mode. */

	/* PH.7 MFP */
	PH7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PH7_UART10_TXD           = (0x02), /*!< Data transmitter output pin for UART10. */
	PH7_LCM_DATA15           = (0x06), /*!< TFT LCD Module Pixel Data output bit 1 in Sync-type mode. */
	PH7_LCM_MPU_DATA15       = (0x06), /*!< TFT LCD Module Command/Data input/output bit 1 in MPU-type mode. */

	/* PH.8 MFP */
	PH8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PH8_TAMPER0              = (0x06), /*!< TAMPER detector loop pin0. */

	/* PH.9 MFP */
	PH9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PH9_CLK_32KOUT           = (0x04), /*!< 32kHz clock output pin. */
	PH9_TAMPER1              = (0x06), /*!< TAMPER detector loop pin1. */

	/* PH.12 MFP */
	PH12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PH12_UART14_nCTS         = (0x02), /*!< Clear to Send input pin for UART14. */
	PH12_UART13_RXD          = (0x03), /*!< Data receiver input pin for UART13. */
	PH12_LCM_DATA20          = (0x06), /*!< TFT LCD Module Pixel Data output bit 2 in Sync-type mode. */

	/* PH.13 MFP */
	PH13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PH13_UART14_nRTS         = (0x02), /*!< Request to Send output pin for UART14. */
	PH13_UART13_TXD          = (0x03), /*!< Data transmitter output pin for UART13. */
	PH13_LCM_DATA21          = (0x06), /*!< TFT LCD Module Pixel Data output bit 2 in Sync-type mode. */

	/* PH.14 MFP */
	PH14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PH14_UART14_RXD          = (0x02), /*!< Data receiver input pin for UART14. */
	PH14_LCM_DATA22          = (0x06), /*!< TFT LCD Module Pixel Data output bit 2 in Sync-type mode. */

	/* PH.15 MFP */
	PH15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PH15_UART14_TXD          = (0x02), /*!< Data transmitter output pin for UART14. */
	PH15_LCM_DATA23          = (0x06), /*!< TFT LCD Module Pixel Data output bit 2 in Sync-type mode. */

	/* PI.0 MFP */
	PI0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PI0_EPWM0_CH0            = (0x01), /*!< EPWM0 channel0 output/capture input. */
	PI0_UART12_nCTS          = (0x02), /*!< Clear to Send input pin for UART12. */
	PI0_UART11_RXD           = (0x03), /*!< Data receiver input pin for UART11. */
	PI0_I2C2_SDA             = (0x04), /*!< I2C2 data input/output pin. */
	PI0_SPI3_SS0             = (0x05), /*!< 1st SPI3 slave select pin. */
	PI0_SC0_nCD              = (0x07), /*!< SmartCard0 card detect pin. */
	PI0_EBI_ADR0             = (0x08), /*!< EBI address/data bus bit*. */
	PI0_TM0                  = (0x0b), /*!< Timer0 event counter input / toggle output */

	/* PI.1 MFP */
	PI1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PI1_EPWM0_CH1            = (0x01), /*!< EPWM0 channel1 output/capture input. */
	PI1_UART12_nRTS          = (0x02), /*!< Request to Send output pin for UART12. */
	PI1_UART11_TXD           = (0x03), /*!< Data transmitter output pin for UART11. */
	PI1_I2C2_SCL             = (0x04), /*!< I2C2 clock pin. */
	PI1_SPI3_CLK             = (0x05), /*!< SPI3 serial clock pin. */
	PI1_SC0_CLK              = (0x07), /*!< SmartCard0 clock pin. */
	PI1_EBI_ADR1             = (0x08), /*!< EBI address/data bus bit*. */
	PI1_TM0_EXT              = (0x0b), /*!< Timer0 event counter input / toggle output */

	/* PI.2 MFP */
	PI2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PI2_EPWM0_CH2            = (0x01), /*!< EPWM0 channel2 output/capture input. */
	PI2_UART12_RXD           = (0x02), /*!< Data receiver input pin for UART12. */
	PI2_CAN0_RXD             = (0x03), /*!< CAN0 bus receiver input. */
	PI2_USBHL2_DM            = (0x04), /*!< USB 1.1 host-lite 2 differential signal D-. */
	PI2_SPI3_MOSI            = (0x05), /*!< 1st SPI3 MOSI (Master Out, Slave In) pin. */
	PI2_SC0_DAT              = (0x07), /*!< SmartCard0 data pin. */
	PI2_EBI_ADR2             = (0x08), /*!< EBI address/data bus bit*. */
	PI2_TM1                  = (0x0b), /*!< Timer1 event counter input / toggle output */

	/* PI.3 MFP */
	PI3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PI3_EPWM0_CH3            = (0x01), /*!< EPWM0 channel3 output/capture input. */
	PI3_UART12_TXD           = (0x02), /*!< Data transmitter output pin for UART12. */
	PI3_CAN0_TXD             = (0x03), /*!< CAN0 bus transmitter output. */
	PI3_USBHL2_DP            = (0x04), /*!< USB 1.1 host-lite 2 differential signal D+. */
	PI3_SPI3_MISO            = (0x05), /*!< 1st SPI3 MISO (Master In, Slave Out) pin. */
	PI3_SC0_RST              = (0x07), /*!< SmartCard0 reset pin. */
	PI3_EBI_ADR3             = (0x08), /*!< EBI address/data bus bit*. */
	PI3_TM1_EXT              = (0x0b), /*!< Timer1 event counter input / toggle output */

	/* PI.4 MFP */
	PI4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PI4_EPWM0_CH4            = (0x01), /*!< EPWM0 channel4 output/capture input. */
	PI4_UART14_nCTS          = (0x02), /*!< Clear to Send input pin for UART14. */
	PI4_UART13_RXD           = (0x03), /*!< Data receiver input pin for UART13. */
	PI4_I2C3_SDA             = (0x04), /*!< I2C3 data input/output pin. */
	PI4_SPI2_SS1             = (0x05), /*!< 1st SPI2 slave select pin. */
	PI4_I2S1_LRCK            = (0x06), /*!< I2S1 left right channel clock. */
	PI4_EBI_ADR4             = (0x08), /*!< EBI address/data bus bit*. */
	PI4_INT0                 = (0x0d), /*!< External interrupt0 input pin. */

	/* PI.5 MFP */
	PI5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PI5_EPWM0_CH5            = (0x01), /*!< EPWM0 channel5 output/capture input. */
	PI5_UART14_nRTS          = (0x02), /*!< Request to Send output pin for UART14. */
	PI5_UART13_TXD           = (0x03), /*!< Data transmitter output pin for UART13. */
	PI5_I2C3_SCL             = (0x04), /*!< I2C3 clock pin. */
	PI5_I2S1_BCLK            = (0x06), /*!< I2S1 bit clock pin. */
	PI5_EBI_ADR5             = (0x08), /*!< EBI address/data bus bit*. */
	PI5_INT1                 = (0x0d), /*!< External interrupt1 input pin. */

	/* PI.6 MFP */
	PI6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PI6_EPWM0_BRAKE0         = (0x01), /*!< Brake input pin 0 of EPWM0. */
	PI6_UART14_RXD           = (0x02), /*!< Data receiver input pin for UART14. */
	PI6_CAN1_RXD             = (0x03), /*!< CAN1 bus receiver input. */
	PI6_USBHL3_DM            = (0x04), /*!< USB 1.1 host-lite 3 differential signal D-. */
	PI6_I2S1_DI              = (0x06), /*!< I2S1 data input. */
	PI6_EBI_ADR6             = (0x08), /*!< EBI address/data bus bit*. */
	PI6_INT2                 = (0x0d), /*!< External interrupt2 input pin. */

	/* PI.7 MFP */
	PI7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PI7_EPWM0_BRAKE1         = (0x01), /*!< Brake input pin 1 of EPWM0. */
	PI7_UART14_TXD           = (0x02), /*!< Data transmitter output pin for UART14. */
	PI7_CAN1_TXD             = (0x03), /*!< CAN1 bus transmitter output. */
	PI7_USBHL3_DP            = (0x04), /*!< USB 1.1 host-lite 3 differential signal D+. */
	PI7_I2S1_DO              = (0x06), /*!< I2S1 data output. */
	PI7_EBI_ADR7             = (0x08), /*!< EBI address/data bus bit*. */
	PI7_INT3                 = (0x0d), /*!< External interrupt3 input pin. */

	/* PI.8 MFP */
	PI8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PI8_UART4_nCTS           = (0x02), /*!< Clear to Send input pin for UART4. */
	PI8_UART3_RXD            = (0x03), /*!< Data receiver input pin for UART3. */
	PI8_LCM_DATA0            = (0x06), /*!< TFT LCD Module Pixel Data output bit 0 in Sync-type mode. */
	PI8_LCM_MPU_DATA0        = (0x06), /*!< TFT LCD Module Command/Data input/output bit 0 in MPU-type mode. */
	PI8_EBI_AD11             = (0x0c), /*!< EBI address/data bus bit1. */

	/* PI.9 MFP */
	PI9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PI9_UART4_nRTS           = (0x02), /*!< Request to Send output pin for UART4. */
	PI9_UART3_TXD            = (0x03), /*!< Data transmitter output pin for UART3. */
	PI9_LCM_DATA1            = (0x06), /*!< TFT LCD Module Pixel Data output bit 1 in Sync-type mode. */
	PI9_LCM_MPU_DATA1        = (0x06), /*!< TFT LCD Module Command/Data input/output bit 1 in MPU-type mode. */
	PI9_EBI_AD12             = (0x0c), /*!< EBI address/data bus bit1. */

	/* PI.10 MFP */
	PI10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PI10_UART4_RXD           = (0x02), /*!< Data receiver input pin for UART4. */
	PI10_LCM_DATA2           = (0x06), /*!< TFT LCD Module Pixel Data output bit 2 in Sync-type mode. */
	PI10_LCM_MPU_DATA2       = (0x06), /*!< TFT LCD Module Command/Data input/output bit 2 in MPU-type mode. */
	PI10_EBI_AD13            = (0x0c), /*!< EBI address/data bus bit1. */

	/* PI.11 MFP */
	PI11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PI11_UART4_TXD           = (0x02), /*!< Data transmitter output pin for UART4. */
	PI11_LCM_DATA3           = (0x06), /*!< TFT LCD Module Pixel Data output bit 3 in Sync-type mode. */
	PI11_LCM_MPU_DATA3       = (0x06), /*!< TFT LCD Module Command/Data input/output bit 3 in MPU-type mode. */
	PI11_EBI_AD14            = (0x0c), /*!< EBI address/data bus bit1. */

	/* PI.12 MFP */
	PI12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PI12_UART6_nCTS          = (0x02), /*!< Clear to Send input pin for UART6. */
	PI12_UART5_RXD           = (0x03), /*!< Data receiver input pin for UART5. */
	PI12_LCM_DATA4           = (0x06), /*!< TFT LCD Module Pixel Data output bit 4 in Sync-type mode. */
	PI12_LCM_MPU_DATA4       = (0x06), /*!< TFT LCD Module Command/Data input/output bit 4 in MPU-type mode. */

	/* PI.13 MFP */
	PI13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PI13_UART6_nRTS          = (0x02), /*!< Request to Send output pin for UART6. */
	PI13_UART5_TXD           = (0x03), /*!< Data transmitter output pin for UART5. */
	PI13_LCM_DATA5           = (0x06), /*!< TFT LCD Module Pixel Data output bit 5 in Sync-type mode. */
	PI13_LCM_MPU_DATA5       = (0x06), /*!< TFT LCD Module Command/Data input/output bit 5 in MPU-type mode. */

	/* PI.14 MFP */
	PI14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PI14_UART6_RXD           = (0x02), /*!< Data receiver input pin for UART6. */
	PI14_LCM_DATA6           = (0x06), /*!< TFT LCD Module Pixel Data output bit 6 in Sync-type mode. */
	PI14_LCM_MPU_DATA6       = (0x06), /*!< TFT LCD Module Command/Data input/output bit 6 in MPU-type mode. */

	/* PI.15 MFP */
	PI15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PI15_UART6_TXD           = (0x02), /*!< Data transmitter output pin for UART6. */
	PI15_LCM_DATA7           = (0x06), /*!< TFT LCD Module Pixel Data output bit 7 in Sync-type mode. */
	PI15_LCM_MPU_DATA7       = (0x06), /*!< TFT LCD Module Command/Data input/output bit 7 in MPU-type mode. */

	/* PJ.0 MFP */
	PJ0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PJ0_EPWM1_BRAKE0         = (0x01), /*!< Brake input pin 0 of EPWM1. */
	PJ0_UART8_nCTS           = (0x02), /*!< Clear to Send input pin for UART8. */
	PJ0_UART7_RXD            = (0x03), /*!< Data receiver input pin for UART7. */
	PJ0_I2C2_SDA             = (0x04), /*!< I2C2 data input/output pin. */
	PJ0_SPI2_SS0             = (0x05), /*!< 1st SPI2 slave select pin. */
	PJ0_eMMC1_DAT4           = (0x06), /*!< eMMC1 data line bit 4. */
	PJ0_I2S0_LRCK            = (0x07), /*!< I2S0 left right channel clock. */
	PJ0_SC0_CLK              = (0x08), /*!< SmartCard0 clock pin. */
	PJ0_EBI_AD11             = (0x09), /*!< EBI address/data bus bit1. */
	PJ0_EBI_ADR16            = (0x0a), /*!< EBI address/data bus bit*. */
	PJ0_EBI_nCS0             = (0x0b), /*!< EBI chip select enable output pin. */
	PJ0_EBI_AD7              = (0x0c), /*!< EBI address/data bus bit7. */

	/* PJ.1 MFP */
	PJ1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PJ1_EPWM1_BRAKE1         = (0x01), /*!< Brake input pin 1 of EPWM1. */
	PJ1_UART8_nRTS           = (0x02), /*!< Request to Send output pin for UART8. */
	PJ1_UART7_TXD            = (0x03), /*!< Data transmitter output pin for UART7. */
	PJ1_I2C2_SCL             = (0x04), /*!< I2C2 clock pin. */
	PJ1_SPI2_CLK             = (0x05), /*!< SPI2 serial clock pin. */
	PJ1_eMMC1_DAT5           = (0x06), /*!< eMMC1 data line bit 5. */
	PJ1_I2S0_BCLK            = (0x07), /*!< I2S0 bit clock pin. */
	PJ1_SC0_DAT              = (0x08), /*!< SmartCard0 data pin. */
	PJ1_EBI_AD12             = (0x09), /*!< EBI address/data bus bit1. */
	PJ1_EBI_ADR17            = (0x0a), /*!< EBI address/data bus bit*. */
	PJ1_EBI_nCS1             = (0x0b), /*!< EBI chip select enable output pin. */
	PJ1_EBI_AD8              = (0x0c), /*!< EBI address/data bus bit8. */

	/* PJ.2 MFP */
	PJ2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PJ2_EPWM1_CH4            = (0x01), /*!< EPWM1 channel4 output/capture input. */
	PJ2_UART8_RXD            = (0x02), /*!< Data receiver input pin for UART8. */
	PJ2_CAN1_RXD             = (0x03), /*!< CAN1 bus receiver input. */
	PJ2_USBHL5_DM            = (0x04), /*!< USB 1.1 host-lite 5 differential signal D-. */
	PJ2_SPI2_MOSI            = (0x05), /*!< 1st SPI2 MOSI (Master Out, Slave In) pin. */
	PJ2_eMMC1_DAT6           = (0x06), /*!< eMMC1 data line bit 6. */
	PJ2_I2S0_DI              = (0x07), /*!< I2S0 data input. */
	PJ2_SC0_RST              = (0x08), /*!< SmartCard0 reset pin. */
	PJ2_EBI_AD13             = (0x09), /*!< EBI address/data bus bit1. */
	PJ2_EBI_ADR18            = (0x0a), /*!< EBI address/data bus bit*. */
	PJ2_EBI_nWRH             = (0x0b), /*!< EBI write enable output pin. */
	PJ2_EBI_AD9              = (0x0c), /*!< EBI address/data bus bit9. */

	/* PJ.3 MFP */
	PJ3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PJ3_EPWM1_CH5            = (0x01), /*!< EPWM1 channel5 output/capture input. */
	PJ3_UART8_TXD            = (0x02), /*!< Data transmitter output pin for UART8. */
	PJ3_CAN1_TXD             = (0x03), /*!< CAN1 bus transmitter output. */
	PJ3_USBHL5_DP            = (0x04), /*!< USB 1.1 host-lite 5 differential signal D+. */
	PJ3_SPI2_MISO            = (0x05), /*!< 1st SPI2 MISO (Master In, Slave Out) pin. */
	PJ3_eMMC1_DAT7           = (0x06), /*!< eMMC1 data line bit 7. */
	PJ3_I2S0_DO              = (0x07), /*!< I2S0 data output. */
	PJ3_SC0_PWR              = (0x08), /*!< SmartCard0 power pin. */
	PJ3_EBI_AD14             = (0x09), /*!< EBI address/data bus bit1. */
	PJ3_EBI_ADR19            = (0x0a), /*!< EBI address/data bus bit*. */
	PJ3_EBI_nWRL             = (0x0b), /*!< EBI write enable output pin. */
	PJ3_EBI_AD10             = (0x0c), /*!< EBI address/data bus bit1. */

	/* PJ.4 MFP */
	PJ4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PJ4_I2C3_SDA             = (0x04), /*!< I2C3 data input/output pin. */
	PJ4_SD1_WP               = (0x06), /*!< SD/SDIO1 write protect input. */

	/* PJ.5 MFP */
	PJ5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PJ5_I2C3_SCL             = (0x04), /*!< I2C3 clock pin. */
	PJ5_SD1_nCD              = (0x06), /*!< SD/SDIO1 card detect */

	/* PJ.6 MFP */
	PJ6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PJ6_CAN3_RXD             = (0x03), /*!< CAN3 bus receiver input. */
	PJ6_USBHL0_DM            = (0x04), /*!< USB 1.1 host-lite 0 differential signal D-. */
	PJ6_eMMC1_CMD            = (0x06), /*!< eMMC1 command/response. */
	PJ6_SD1_CMD              = (0x06), /*!< SD/SDIO1 command/response. */

	/* PJ.7 MFP */
	PJ7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PJ7_CAN3_TXD             = (0x03), /*!< CAN3 bus transmitter output. */
	PJ7_USBHL0_DP            = (0x04), /*!< USB 1.1 host-lite 0 differential signal D+. */
	PJ7_eMMC1_CLK            = (0x06), /*!< eMMC1 clock. */
	PJ7_SD1_CLK              = (0x06), /*!< SD/SDIO1 clock. */

	/* PJ.8 MFP */
	PJ8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PJ8_I2C4_SDA             = (0x04), /*!< I2C4 data input/output pin. */
	PJ8_eMMC1_DAT0           = (0x06), /*!< eMMC1 data line bit 0. */
	PJ8_SD1_DAT0             = (0x06), /*!< SD/SDIO1 data line bit 0. */

	/* PJ.9 MFP */
	PJ9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PJ9_I2C4_SCL             = (0x04), /*!< I2C4 clock pin. */
	PJ9_eMMC1_DAT1           = (0x06), /*!< eMMC1 data line bit 1. */
	PJ9_SD1_DAT1             = (0x06), /*!< SD/SDIO1 data line bit 1. */

	/* PJ.10 MFP */
	PJ10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PJ10_CAN0_RXD            = (0x03), /*!< CAN0 bus receiver input. */
	PJ10_USBHL1_DM           = (0x04), /*!< USB 1.1 host-lite 1 differential signal D-. */
	PJ10_eMMC1_DAT2          = (0x06), /*!< eMMC1 data line bit 2. */
	PJ10_SD1_DAT2            = (0x06), /*!< SD/SDIO1 data line bit 2. */

	/* PJ.11 MFP */
	PJ11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PJ11_CAN0_TXD            = (0x03), /*!< CAN0 bus transmitter output. */
	PJ11_USBHL1_DP           = (0x04), /*!< USB 1.1 host-lite 1 differential signal D+. */
	PJ11_eMMC1_DAT3          = (0x06), /*!< eMMC1 data line bit 3. */
	PJ11_SD1_DAT3            = (0x06), /*!< SD/SDIO1 data line bit 3. */

	/* PJ.12 MFP */
	PJ12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PJ12_EPWM1_CH2           = (0x01), /*!< EPWM1 channel2 output/capture input. */
	PJ12_UART2_nCTS          = (0x02), /*!< Clear to Send input pin for UART2. */
	PJ12_UART1_RXD           = (0x03), /*!< Data receiver input pin for UART1. */
	PJ12_I2C5_SDA            = (0x04), /*!< I2C5 data input/output pin. */
	PJ12_SPI3_SS0            = (0x05), /*!< 1st SPI3 slave select pin. */
	PJ12_SC1_CLK             = (0x07), /*!< SmartCard1 clock pin. */
	PJ12_EBI_ADR12           = (0x08), /*!< EBI address/data bus bit*. */
	PJ12_TM2                 = (0x0b), /*!< Timer2 event counter input / toggle output */

	/* PJ.13 MFP */
	PJ13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PJ13_EPWM1_CH3           = (0x01), /*!< EPWM1 channel3 output/capture input. */
	PJ13_UART2_nRTS          = (0x02), /*!< Request to Send output pin for UART2. */
	PJ13_UART1_TXD           = (0x03), /*!< Data transmitter output pin for UART1. */
	PJ13_I2C5_SCL            = (0x04), /*!< I2C5 clock pin. */
	PJ13_SPI3_MOSI           = (0x05), /*!< 1st SPI3 MOSI (Master Out, Slave In) pin. */
	PJ13_SC1_DAT             = (0x07), /*!< SmartCard1 data pin. */
	PJ13_EBI_ADR13           = (0x08), /*!< EBI address/data bus bit*. */
	PJ13_TM2_EXT             = (0x0b), /*!< Timer2 event counter input / toggle output */

	/* PJ.14 MFP */
	PJ14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PJ14_EPWM1_CH4           = (0x01), /*!< EPWM1 channel4 output/capture input. */
	PJ14_UART2_RXD           = (0x02), /*!< Data receiver input pin for UART2. */
	PJ14_CAN3_RXD            = (0x03), /*!< CAN3 bus receiver input. */
	PJ14_USBHL5_DM           = (0x04), /*!< USB 1.1 host-lite 5 differential signal D-. */
	PJ14_SPI3_MISO           = (0x05), /*!< 1st SPI3 MISO (Master In, Slave Out) pin. */
	PJ14_SC1_RST             = (0x07), /*!< SmartCard1 reset pin. */
	PJ14_EBI_ADR14           = (0x08), /*!< EBI address/data bus bit*. */
	PJ14_TM3                 = (0x0b), /*!< Timer3 event counter input / toggle output */

	/* PJ.15 MFP */
	PJ15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PJ15_EPWM1_CH5           = (0x01), /*!< EPWM1 channel5 output/capture input. */
	PJ15_UART2_TXD           = (0x02), /*!< Data transmitter output pin for UART2. */
	PJ15_CAN3_TXD            = (0x03), /*!< CAN3 bus transmitter output. */
	PJ15_USBHL5_DP           = (0x04), /*!< USB 1.1 host-lite 5 differential signal D+. */
	PJ15_SPI3_CLK            = (0x05), /*!< SPI3 serial clock pin. */
	PJ15_SC1_PWR             = (0x07), /*!< SmartCard1 power pin. */
	PJ15_EBI_ADR15           = (0x08), /*!< EBI address/data bus bit*. */
	PJ15_TM3_EXT             = (0x0b), /*!< Timer3 event counter input / toggle output */
	PJ15_INT1                = (0x0d), /*!< External interrupt1 input pin. */

	/* PK.0 MFP */
	PK0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PK0_EPWM0_SYNC_IN        = (0x01), /*!< EPWM0 counter synchronous trigger input pin. */
	PK0_UART16_nCTS          = (0x02), /*!< Clear to Send input pin for UART16. */
	PK0_UART15_RXD           = (0x03), /*!< Data receiver input pin for UART15. */
	PK0_I2C4_SDA             = (0x04), /*!< I2C4 data input/output pin. */
	PK0_I2S1_MCLK            = (0x06), /*!< I2S1 master clock output pin. */
	PK0_EBI_ADR8             = (0x08), /*!< EBI address/data bus bit*. */
	PK0_TM7                  = (0x0b), /*!< Timer7 event counter input / toggle output */

	/* PK.1 MFP */
	PK1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PK1_EPWM0_SYNC_OUT       = (0x01), /*!< EPWM0 counter synchronous trigger output pin. */
	PK1_UART16_nRTS          = (0x02), /*!< Request to Send output pin for UART16. */
	PK1_UART15_TXD           = (0x03), /*!< Data transmitter output pin for UART15. */
	PK1_I2C4_SCL             = (0x04), /*!< I2C4 clock pin. */
	PK1_EBI_ADR9             = (0x08), /*!< EBI address/data bus bit*. */
	PK1_TM7_EXT              = (0x0b), /*!< Timer7 event counter input / toggle output */

	/* PK.2 MFP */
	PK2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PK2_EPWM1_CH0            = (0x01), /*!< EPWM1 channel0 output/capture input. */
	PK2_UART16_RXD           = (0x02), /*!< Data receiver input pin for UART16. */
	PK2_CAN2_RXD             = (0x03), /*!< CAN2 bus receiver input. */
	PK2_USBHL4_DM            = (0x04), /*!< USB 1.1 host-lite 4 differential signal D-. */
	PK2_SPI3_I2SMCLK         = (0x05), /*!< SPI3 I2S master clock output pin. */
	PK2_SC0_PWR              = (0x07), /*!< SmartCard0 power pin. */
	PK2_EBI_ADR10            = (0x08), /*!< EBI address/data bus bit*. */

	/* PK.3 MFP */
	PK3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PK3_EPWM1_CH1            = (0x01), /*!< EPWM1 channel1 output/capture input. */
	PK3_UART16_TXD           = (0x02), /*!< Data transmitter output pin for UART16. */
	PK3_CAN2_TXD             = (0x03), /*!< CAN2 bus transmitter output. */
	PK3_USBHL4_DP            = (0x04), /*!< USB 1.1 host-lite 4 differential signal D+. */
	PK3_SPI3_SS1             = (0x05), /*!< 1st SPI3 slave select pin. */
	PK3_SC1_nCD              = (0x07), /*!< SmartCard1 card detect pin. */
	PK3_EBI_ADR11            = (0x08), /*!< EBI address/data bus bit*. */

	/* PK.4 MFP */
	PK4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PK4_UART12_nCTS          = (0x02), /*!< Clear to Send input pin for UART12. */
	PK4_UART13_RXD           = (0x03), /*!< Data receiver input pin for UART13. */
	PK4_SPI2_MISO            = (0x05), /*!< 1st SPI2 MISO (Master In, Slave Out) pin. */
	PK4_LCM_DEN              = (0x06), /*!< TFT LCD Module Data Enable/Display Control Signal output pin in Sync-type mode. */
	PK4_LCM_MPU_DCX          = (0x06), /*!< TFT LCD Module Register Select (RS) output pin in MPU-type mode. */
	PK4_EBI_AD10             = (0x0c), /*!< EBI address/data bus bit1. */
	PK4_EBI_nWRL             = (0x0d), /*!< EBI write enable output pin. */

	/* PK.5 MFP */
	PK5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PK5_EPWM1_CH1            = (0x01), /*!< EPWM1 channel1 output/capture input. */
	PK5_UART12_nRTS          = (0x02), /*!< Request to Send output pin for UART12. */
	PK5_UART13_TXD           = (0x03), /*!< Data transmitter output pin for UART13. */
	PK5_I2C4_SCL             = (0x04), /*!< I2C4 clock pin. */
	PK5_SPI2_CLK             = (0x05), /*!< SPI2 serial clock pin. */
	PK5_I2S1_DI              = (0x07), /*!< I2S1 data input. */
	PK5_SC0_DAT              = (0x08), /*!< SmartCard0 data pin. */
	PK5_TM8_EXT              = (0x0b), /*!< Timer8 event counter input / toggle output */
	PK5_INT1                 = (0x0d), /*!< External interrupt1 input pin. */

	/* PK.6 MFP */
	PK6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PK6_EPWM1_CH2            = (0x01), /*!< EPWM1 channel2 output/capture input. */
	PK6_UART12_RXD           = (0x02), /*!< Data receiver input pin for UART12. */
	PK6_CAN0_RXD             = (0x03), /*!< CAN0 bus receiver input. */
	PK6_USBHL4_DM            = (0x04), /*!< USB 1.1 host-lite 4 differential signal D-. */
	PK6_SPI2_MOSI            = (0x05), /*!< 1st SPI2 MOSI (Master Out, Slave In) pin. */
	PK6_I2S1_BCLK            = (0x07), /*!< I2S1 bit clock pin. */
	PK6_SC0_RST              = (0x08), /*!< SmartCard0 reset pin. */
	PK6_TM6                  = (0x0b), /*!< Timer6 event counter input / toggle output */
	PK6_INT2                 = (0x0d), /*!< External interrupt2 input pin. */

	/* PK.7 MFP */
	PK7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PK7_EPWM1_CH3            = (0x01), /*!< EPWM1 channel3 output/capture input. */
	PK7_UART12_TXD           = (0x02), /*!< Data transmitter output pin for UART12. */
	PK7_CAN0_TXD             = (0x03), /*!< CAN0 bus transmitter output. */
	PK7_USBHL4_DP            = (0x04), /*!< USB 1.1 host-lite 4 differential signal D+. */
	PK7_SPI2_MISO            = (0x05), /*!< 1st SPI2 MISO (Master In, Slave Out) pin. */
	PK7_I2S1_LRCK            = (0x07), /*!< I2S1 left right channel clock. */
	PK7_SC0_PWR              = (0x08), /*!< SmartCard0 power pin. */
	PK7_CLKO                 = (0x09), /*!< Clock Output pin. */
	PK7_TM6_EXT              = (0x0b), /*!< Timer6 event counter input / toggle output */
	PK7_INT3                 = (0x0d), /*!< External interrupt3 input pin. */

	/* PK.8 MFP */
	PK8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PK8_EPWM1_CH0            = (0x01), /*!< EPWM1 channel0 output/capture input. */
	PK8_I2C3_SDA             = (0x04), /*!< I2C3 data input/output pin. */
	PK8_SPI3_CLK             = (0x05), /*!< SPI3 serial clock pin. */
	PK8_EBI_AD15             = (0x08), /*!< EBI address/data bus bit1. */
	PK8_EBI_MCLK             = (0x09), /*!< EBI external clock output pin. */
	PK8_EBI_ADR15            = (0x0a), /*!< EBI address/data bus bit*. */
	PK8_TM8                  = (0x0b), /*!< Timer8 event counter input / toggle output */

	/* PK.9 MFP */
	PK9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PK9_I2C3_SCL             = (0x04), /*!< I2C3 clock pin. */
	PK9_VCAP0_SCLK           = (0x06), /*!< Camera capture 0 interface sensor clock output pin. */
	PK9_EBI_AD0              = (0x08), /*!< EBI address/data bus bit0. */
	PK9_EBI_ADR0             = (0x0a), /*!< EBI address/data bus bit*. */

	/* PK.10 MFP */
	PK10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PK10_CAN1_RXD            = (0x03), /*!< CAN1 bus receiver input. */
	PK10_USBHL3_DM           = (0x04), /*!< USB 1.1 host-lite 3 differential signal D-. */
	PK10_VCAP0_PIXCLK        = (0x06), /*!< Camera capture 0 interface pixel clock input pin. */
	PK10_EBI_AD1             = (0x08), /*!< EBI address/data bus bit1. */
	PK10_EBI_ADR1            = (0x0a), /*!< EBI address/data bus bit*. */

	/* PK.11 MFP */
	PK11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PK11_CAN1_TXD            = (0x03), /*!< CAN1 bus transmitter output. */
	PK11_USBHL3_DP           = (0x04), /*!< USB 1.1 host-lite 3 differential signal D+. */
	PK11_VCAP0_HSYNC         = (0x06), /*!< Camera capture 0 interface hsync input pin. */
	PK11_EBI_AD2             = (0x08), /*!< EBI address/data bus bit2. */
	PK11_EBI_ADR2            = (0x0a), /*!< EBI address/data bus bit*. */

	/* PK.12 MFP */
	PK12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PK12_EPWM2_CH0           = (0x01), /*!< EPWM2 channel0 output/capture input. */
	PK12_UART1_nCTS          = (0x02), /*!< Clear to Send input pin for UART1. */
	PK12_UART13_RXD          = (0x03), /*!< Data receiver input pin for UART13. */
	PK12_I2C4_SDA            = (0x04), /*!< I2C4 data input/output pin. */
	PK12_I2S0_LRCK           = (0x05), /*!< I2S0 left right channel clock. */
	PK12_SPI1_SS0            = (0x06), /*!< 1st SPI1 slave select pin. */
	PK12_SC0_CLK             = (0x08), /*!< SmartCard0 clock pin. */
	PK12_TM10                = (0x0b), /*!< Timer1 event counter input / toggle output */
	PK12_INT2                = (0x0d), /*!< External interrupt2 input pin. */

	/* PK.13 MFP */
	PK13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PK13_EPWM2_CH1           = (0x01), /*!< EPWM2 channel1 output/capture input. */
	PK13_UART1_nRTS          = (0x02), /*!< Request to Send output pin for UART1. */
	PK13_UART13_TXD          = (0x03), /*!< Data transmitter output pin for UART13. */
	PK13_I2C4_SCL            = (0x04), /*!< I2C4 clock pin. */
	PK13_I2S0_BCLK           = (0x05), /*!< I2S0 bit clock pin. */
	PK13_SPI1_CLK            = (0x06), /*!< SPI1 serial clock pin. */
	PK13_SC0_DAT             = (0x08), /*!< SmartCard0 data pin. */
	PK13_TM10_EXT            = (0x0b), /*!< Timer1 event counter input / toggle output */

	/* PK.14 MFP */
	PK14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PK14_EPWM2_CH2           = (0x01), /*!< EPWM2 channel2 output/capture input. */
	PK14_UART1_RXD           = (0x02), /*!< Data receiver input pin for UART1. */
	PK14_CAN3_RXD            = (0x03), /*!< CAN3 bus receiver input. */
	PK14_USBHL4_DM           = (0x04), /*!< USB 1.1 host-lite 4 differential signal D-. */
	PK14_I2S0_DI             = (0x05), /*!< I2S0 data input. */
	PK14_SPI1_MOSI           = (0x06), /*!< 1st SPI1 MOSI (Master Out, Slave In) pin. */
	PK14_SC0_RST             = (0x08), /*!< SmartCard0 reset pin. */
	PK14_I2C5_SDA            = (0x0a), /*!< I2C5 data input/output pin. */
	PK14_TM11                = (0x0b), /*!< Timer1 event counter input / toggle output */
	PK14_INT3                = (0x0d), /*!< External interrupt3 input pin. */

	/* PK.15 MFP */
	PK15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PK15_EPWM2_CH3           = (0x01), /*!< EPWM2 channel3 output/capture input. */
	PK15_UART1_TXD           = (0x02), /*!< Data transmitter output pin for UART1. */
	PK15_CAN3_TXD            = (0x03), /*!< CAN3 bus transmitter output. */
	PK15_USBHL4_DP           = (0x04), /*!< USB 1.1 host-lite 4 differential signal D+. */
	PK15_I2S0_DO             = (0x05), /*!< I2S0 data output. */
	PK15_SPI1_MISO           = (0x06), /*!< 1st SPI1 MISO (Master In, Slave Out) pin. */
	PK15_SC0_PWR             = (0x08), /*!< SmartCard0 power pin. */
	PK15_I2C5_SCL            = (0x0a), /*!< I2C5 clock pin. */
	PK15_TM11_EXT            = (0x0b), /*!< Timer1 event counter input / toggle output */

	/* PL.0 MFP */
	PL0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PL0_EPWM1_CH0            = (0x01), /*!< EPWM1 channel0 output/capture input. */
	PL0_UART11_nCTS          = (0x02), /*!< Clear to Send input pin for UART11. */
	PL0_UART10_RXD           = (0x03), /*!< Data receiver input pin for UART10. */
	PL0_I2C3_SDA             = (0x04), /*!< I2C3 data input/output pin. */
	PL0_SPI2_MOSI            = (0x05), /*!< 1st SPI2 MOSI (Master Out, Slave In) pin. */
	PL0_QSPI1_MOSI1          = (0x06), /*!< Quad SPI1 MOSI1 (Master Out, Slave In) pin. */
	PL0_I2S0_LRCK            = (0x07), /*!< I2S0 left right channel clock. */
	PL0_EBI_AD11             = (0x08), /*!< EBI address/data bus bit1. */
	PL0_SC1_CLK              = (0x09), /*!< SmartCard1 clock pin. */
	PL0_TM5                  = (0x0b), /*!< Timer5 event counter input / toggle output */

	/* PL.1 MFP */
	PL1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PL1_EPWM1_CH1            = (0x01), /*!< EPWM1 channel1 output/capture input. */
	PL1_UART11_nRTS          = (0x02), /*!< Request to Send output pin for UART11. */
	PL1_UART10_TXD           = (0x03), /*!< Data transmitter output pin for UART10. */
	PL1_I2C3_SCL             = (0x04), /*!< I2C3 clock pin. */
	PL1_SPI2_MISO            = (0x05), /*!< 1st SPI2 MISO (Master In, Slave Out) pin. */
	PL1_QSPI1_MISO1          = (0x06), /*!< Quad SPI1 MISO1 (Master In, Slave Out) pin. */
	PL1_I2S0_BCLK            = (0x07), /*!< I2S0 bit clock pin. */
	PL1_EBI_AD12             = (0x08), /*!< EBI address/data bus bit1. */
	PL1_SC1_DAT              = (0x09), /*!< SmartCard1 data pin. */
	PL1_TM5_EXT              = (0x0b), /*!< Timer5 event counter input / toggle output */

	/* PL.2 MFP */
	PL2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PL2_EPWM1_CH2            = (0x01), /*!< EPWM1 channel2 output/capture input. */
	PL2_UART11_RXD           = (0x02), /*!< Data receiver input pin for UART11. */
	PL2_CAN3_RXD             = (0x03), /*!< CAN3 bus receiver input. */
	PL2_USBHL4_DM            = (0x04), /*!< USB 1.1 host-lite 4 differential signal D-. */
	PL2_SPI2_SS0             = (0x05), /*!< 1st SPI2 slave select pin. */
	PL2_QSPI1_SS1            = (0x06), /*!< Quad SPI1 slave select pin. */
	PL2_I2S0_DI              = (0x07), /*!< I2S0 data input. */
	PL2_EBI_AD13             = (0x08), /*!< EBI address/data bus bit1. */
	PL2_SC1_RST              = (0x09), /*!< SmartCard1 reset pin. */
	PL2_TM7                  = (0x0b), /*!< Timer7 event counter input / toggle output */

	/* PL.3 MFP */
	PL3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PL3_EPWM1_CH3            = (0x01), /*!< EPWM1 channel3 output/capture input. */
	PL3_UART11_TXD           = (0x02), /*!< Data transmitter output pin for UART11. */
	PL3_CAN3_TXD             = (0x03), /*!< CAN3 bus transmitter output. */
	PL3_USBHL4_DP            = (0x04), /*!< USB 1.1 host-lite 4 differential signal D+. */
	PL3_SPI2_CLK             = (0x05), /*!< SPI2 serial clock pin. */
	PL3_QSPI1_CLK            = (0x06), /*!< Quad SPI1 serial clock pin. */
	PL3_I2S0_DO              = (0x07), /*!< I2S0 data output. */
	PL3_EBI_AD14             = (0x08), /*!< EBI address/data bus bit1. */
	PL3_SC1_PWR              = (0x09), /*!< SmartCard1 power pin. */
	PL3_TM7_EXT              = (0x0b), /*!< Timer7 event counter input / toggle output */

	/* PL.4 MFP */
	PL4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PL4_EPWM1_CH4            = (0x01), /*!< EPWM1 channel4 output/capture input. */
	PL4_UART2_nCTS           = (0x02), /*!< Clear to Send input pin for UART2. */
	PL4_UART1_RXD            = (0x03), /*!< Data receiver input pin for UART1. */
	PL4_I2C4_SDA             = (0x04), /*!< I2C4 data input/output pin. */
	PL4_SPI3_MOSI            = (0x05), /*!< 1st SPI3 MOSI (Master Out, Slave In) pin. */
	PL4_QSPI1_MOSI0          = (0x06), /*!< Quad SPI1 MOSI0 (Master Out, Slave In) pin. */
	PL4_I2S0_MCLK            = (0x07), /*!< I2S0 master clock output pin. */
	PL4_EBI_nRD              = (0x08), /*!< EBI read enable output pin. */
	PL4_SC1_nCD              = (0x09), /*!< SmartCard1 card detect pin. */
	PL4_TM9                  = (0x0b), /*!< Timer9 event counter input / toggle output */

	/* PL.5 MFP */
	PL5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PL5_EPWM1_CH5            = (0x01), /*!< EPWM1 channel5 output/capture input. */
	PL5_UART2_nRTS           = (0x02), /*!< Request to Send output pin for UART2. */
	PL5_UART1_TXD            = (0x03), /*!< Data transmitter output pin for UART1. */
	PL5_I2C4_SCL             = (0x04), /*!< I2C4 clock pin. */
	PL5_SPI3_MISO            = (0x05), /*!< 1st SPI3 MISO (Master In, Slave Out) pin. */
	PL5_QSPI1_MISO0          = (0x06), /*!< Quad SPI1 MISO0 (Master In, Slave Out) pin. */
	PL5_I2S1_MCLK            = (0x07), /*!< I2S1 master clock output pin. */
	PL5_EBI_nWR              = (0x08), /*!< EBI write enable output pin. */
	PL5_SC0_nCD              = (0x09), /*!< SmartCard0 card detect pin. */
	PL5_TM9_EXT              = (0x0b), /*!< Timer* event counter input / toggle output */

	/* PL.6 MFP */
	PL6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PL6_EPWM0_CH0            = (0x01), /*!< EPWM0 channel0 output/capture input. */
	PL6_UART2_RXD            = (0x02), /*!< Data receiver input pin for UART2. */
	PL6_CAN0_RXD             = (0x03), /*!< CAN0 bus receiver input. */
	PL6_USBHL5_DM            = (0x04), /*!< USB 1.1 host-lite 5 differential signal D-. */
	PL6_QSPI1_MOSI1          = (0x06), /*!< Quad SPI1 MOSI1 (Master Out, Slave In) pin. */
	PL6_TRACE_CLK            = (0x07), /*!< ETM Rx clock input pin. */
	PL6_EBI_AD5              = (0x08), /*!< EBI address/data bus bit5. */
	PL6_TM3                  = (0x0b), /*!< Timer3 event counter input / toggle output */
	PL6_INT0                 = (0x0d), /*!< External interrupt0 input pin. */

	/* PL.7 MFP */
	PL7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PL7_EPWM0_CH1            = (0x01), /*!< EPWM0 channel1 output/capture input. */
	PL7_UART2_TXD            = (0x02), /*!< Data transmitter output pin for UART2. */
	PL7_CAN0_TXD             = (0x03), /*!< CAN0 bus transmitter output. */
	PL7_USBHL5_DP            = (0x04), /*!< USB 1.1 host-lite 5 differential signal D+. */
	PL7_QSPI1_MISO1          = (0x06), /*!< Quad SPI1 MISO1 (Master In, Slave Out) pin. */
	PL7_EBI_AD6              = (0x08), /*!< EBI address/data bus bit6. */
	PL7_TM3_EXT              = (0x0b), /*!< Timer3 event counter input / toggle output */
	PL7_INT1                 = (0x0d), /*!< External interrupt1 input pin. */

	/* PL.8 MFP */
	PL8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PL8_EPWM0_CH2            = (0x01), /*!< EPWM0 channel2 output/capture input. */
	PL8_UART14_nCTS          = (0x02), /*!< Clear to Send input pin for UART14. */
	PL8_UART13_RXD           = (0x03), /*!< Data receiver input pin for UART13. */
	PL8_I2C5_SDA             = (0x04), /*!< I2C5 data input/output pin. */
	PL8_SPI3_SS0             = (0x05), /*!< 1st SPI3 slave select pin. */
	PL8_EPWM0_CH4            = (0x06), /*!< EPWM0 channel4 output/capture input. */
	PL8_I2S1_LRCK            = (0x07), /*!< I2S1 left right channel clock. */
	PL8_EBI_AD7              = (0x08), /*!< EBI address/data bus bit7. */
	PL8_SC0_CLK              = (0x09), /*!< SmartCard0 clock pin. */
	PL8_TM4                  = (0x0b), /*!< Timer4 event counter input / toggle output */
	PL8_INT2                 = (0x0d), /*!< External interrupt2 input pin. */

	/* PL.9 MFP */
	PL9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PL9_EPWM0_CH3            = (0x01), /*!< EPWM0 channel3 output/capture input. */
	PL9_UART14_nRTS          = (0x02), /*!< Request to Send output pin for UART14. */
	PL9_UART13_TXD           = (0x03), /*!< Data transmitter output pin for UART13. */
	PL9_I2C5_SCL             = (0x04), /*!< I2C5 clock pin. */
	PL9_SPI3_CLK             = (0x05), /*!< SPI3 serial clock pin. */
	PL9_EPWM1_CH4            = (0x06), /*!< EPWM1 channel4 output/capture input. */
	PL9_I2S1_BCLK            = (0x07), /*!< I2S1 bit clock pin. */
	PL9_EBI_AD8              = (0x08), /*!< EBI address/data bus bit8. */
	PL9_SC0_DAT              = (0x09), /*!< SmartCard0 data pin. */
	PL9_TM4_EXT              = (0x0b), /*!< Timer4 event counter input / toggle output */
	PL9_INT3                 = (0x0d), /*!< External interrupt3 input pin. */

	/* PL.10 MFP */
	PL10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PL10_EPWM0_CH4           = (0x01), /*!< EPWM0 channel4 output/capture input. */
	PL10_UART14_RXD          = (0x02), /*!< Data receiver input pin for UART14. */
	PL10_CAN3_RXD            = (0x03), /*!< CAN3 bus receiver input. */
	PL10_USBHL2_DM           = (0x04), /*!< USB 1.1 host-lite 2 differential signal D-. */
	PL10_SPI3_MOSI           = (0x05), /*!< 1st SPI3 MOSI (Master Out, Slave In) pin. */
	PL10_EPWM0_CH5           = (0x06), /*!< EPWM0 channel5 output/capture input. */
	PL10_I2S1_DI             = (0x07), /*!< I2S1 data input. */
	PL10_EBI_AD9             = (0x08), /*!< EBI address/data bus bit9. */
	PL10_SC0_RST             = (0x09), /*!< SmartCard0 reset pin. */
	PL10_EBI_nWRH            = (0x0b), /*!< EBI write enable output pin. */

	/* PL.11 MFP */
	PL11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PL11_EPWM0_CH5           = (0x01), /*!< EPWM0 channel5 output/capture input. */
	PL11_UART14_TXD          = (0x02), /*!< Data transmitter output pin for UART14. */
	PL11_CAN3_TXD            = (0x03), /*!< CAN3 bus transmitter output. */
	PL11_USBHL2_DP           = (0x04), /*!< USB 1.1 host-lite 2 differential signal D+. */
	PL11_SPI3_MISO           = (0x05), /*!< 1st SPI3 MISO (Master In, Slave Out) pin. */
	PL11_EPWM1_CH5           = (0x06), /*!< EPWM1 channel5 output/capture input. */
	PL11_I2S1_DO             = (0x07), /*!< I2S1 data output. */
	PL11_EBI_AD10            = (0x08), /*!< EBI address/data bus bit1. */
	PL11_SC0_PWR             = (0x09), /*!< SmartCard0 power pin. */
	PL11_EBI_nWRL            = (0x0b), /*!< EBI write enable output pin. */

	/* PL.12 MFP */
	PL12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PL12_EPWM0_SYNC_IN       = (0x01), /*!< EPWM0 counter synchronous trigger input pin. */
	PL12_UART7_nCTS          = (0x02), /*!< Clear to Send input pin for UART7. */
	PL12_UART14_RXD          = (0x04), /*!< Data receiver input pin for UART14. */
	PL12_SPI0_SS0            = (0x05), /*!< 1st SPI0 slave select pin. */
	PL12_I2S1_LRCK           = (0x06), /*!< I2S1 left right channel clock. */
	PL12_SC1_CLK             = (0x07), /*!< SmartCard1 clock pin. */
	PL12_EBI_AD0             = (0x08), /*!< EBI address/data bus bit0. */
	PL12_HSUSBH_PWREN        = (0x09), /*!< HSUSB host external VBUS regulator enable pin. */
	PL12_I2C2_SDA            = (0x0a), /*!< I2C2 data input/output pin. */
	PL12_TM0                 = (0x0b), /*!< Timer0 event counter input / toggle output */
	PL12_EPWM0_CH2           = (0x0c), /*!< EPWM0 channel2 output/capture input. */
	PL12_EBI_AD11            = (0x0d), /*!< EBI address/data bus bit1. */
	PL12_RGMII0_PPS          = (0x0e), /*!< RGMII0 Pulse Per Second output pin. */
	PL12_RMII0_PPS           = (0x0f), /*!< RMII0 Pulse Per Second output pin. */

	/* PL.13 MFP */
	PL13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PL13_EPWM0_SYNC_OUT      = (0x01), /*!< EPWM0 counter synchronous trigger output pin. */
	PL13_UART7_nRTS          = (0x02), /*!< Request to Send output pin for UART7. */
	PL13_UART14_TXD          = (0x04), /*!< Data transmitter output pin for UART14. */
	PL13_SPI0_CLK            = (0x05), /*!< SPI0 serial clock pin. */
	PL13_I2S1_BCLK           = (0x06), /*!< I2S1 bit clock pin. */
	PL13_SC1_DAT             = (0x07), /*!< SmartCard1 data pin. */
	PL13_EBI_AD1             = (0x08), /*!< EBI address/data bus bit1. */
	PL13_HSUSBH_OVC          = (0x09), /*!< HSUSB host bus power over current detector pin. */
	PL13_I2C2_SCL            = (0x0a), /*!< I2C2 clock pin. */
	PL13_TM0_EXT             = (0x0b), /*!< Timer0 event counter input / toggle output */
	PL13_EPWM0_CH3           = (0x0c), /*!< EPWM0 channel3 output/capture input. */
	PL13_EBI_AD12            = (0x0d), /*!< EBI address/data bus bit1. */
	PL13_RGMII1_PPS          = (0x0e), /*!< RGMII1 Pulse Per Second output pin. */
	PL13_RMII1_PPS           = (0x0f), /*!< RMII1 Pulse Per Second output pin. */

	/* PL.14 MFP */
	PL14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PL14_EPWM0_CH2           = (0x01), /*!< EPWM0 channel2 output/capture input. */
	PL14_UART7_RXD           = (0x02), /*!< Data receiver input pin for UART7. */
	PL14_CAN1_RXD            = (0x04), /*!< CAN1 bus receiver input. */
	PL14_SPI0_MOSI           = (0x05), /*!< 1st SPI0 MOSI (Master Out, Slave In) pin. */
	PL14_I2S1_DI             = (0x06), /*!< I2S1 data input. */
	PL14_SC1_RST             = (0x07), /*!< SmartCard1 reset pin. */
	PL14_EBI_AD2             = (0x08), /*!< EBI address/data bus bit2. */
	PL14_TM2                 = (0x0b), /*!< Timer2 event counter input / toggle output */
	PL14_INT0                = (0x0c), /*!< External interrupt0 input pin. */
	PL14_EBI_AD13            = (0x0d), /*!< EBI address/data bus bit1. */

	/* PL.15 MFP */
	PL15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PL15_EPWM0_CH1           = (0x01), /*!< EPWM0 channel1 output/capture input. */
	PL15_UART7_TXD           = (0x02), /*!< Data transmitter output pin for UART7. */
	PL15_TRACE_CLK           = (0x03), /*!< ETM Rx clock input pin. */
	PL15_CAN1_TXD            = (0x04), /*!< CAN1 bus transmitter output. */
	PL15_SPI0_MISO           = (0x05), /*!< 1st SPI0 MISO (Master In, Slave Out) pin. */
	PL15_I2S1_DO             = (0x06), /*!< I2S1 data output. */
	PL15_SC1_PWR             = (0x07), /*!< SmartCard1 power pin. */
	PL15_EBI_AD3             = (0x08), /*!< EBI address/data bus bit3. */
	PL15_TM2_EXT             = (0x0b), /*!< Timer2 event counter input / toggle output */
	PL15_INT2                = (0x0c), /*!< External interrupt2 input pin. */
	PL15_EBI_AD14            = (0x0d), /*!< EBI address/data bus bit1. */

	/* PM.0 MFP */
	PM0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PM0_I2C4_SDA             = (0x04), /*!< I2C4 data input/output pin. */
	PM0_VCAP0_VSYNC          = (0x06), /*!< Camera capture 0 interface vsync input pin. */
	PM0_EBI_AD3              = (0x08), /*!< EBI address/data bus bit3. */
	PM0_EBI_ADR3             = (0x0a), /*!< EBI address/data bus bit*. */

	/* PM.1 MFP */
	PM1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PM1_I2C4_SCL             = (0x04), /*!< I2C4 clock pin. */
	PM1_SPI3_I2SMCLK         = (0x05), /*!< SPI3 I2S master clock output pin. */
	PM1_VCAP0_SFIELD         = (0x06), /*!< Camera capture 0 interface SFIELD input pin. */
	PM1_EBI_AD4              = (0x08), /*!< EBI address/data bus bit4. */
	PM1_EBI_ADR4             = (0x0a), /*!< EBI address/data bus bit*. */

	/* PM.2 MFP */
	PM2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PM2_CAN3_RXD             = (0x03), /*!< CAN3 bus receiver input. */
	PM2_USBHL0_DM            = (0x04), /*!< USB 1.1 host-lite 0 differential signal D-. */
	PM2_VCAP0_DATA0          = (0x06), /*!< Camera capture 0 data input bus bit 0. */
	PM2_EBI_AD5              = (0x08), /*!< EBI address/data bus bit5. */
	PM2_EBI_ADR5             = (0x0a), /*!< EBI address/data bus bit*. */

	/* PM.3 MFP */
	PM3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PM3_CAN3_TXD             = (0x03), /*!< CAN3 bus transmitter output. */
	PM3_USBHL0_DP            = (0x04), /*!< USB 1.1 host-lite 0 differential signal D+. */
	PM3_VCAP0_DATA1          = (0x06), /*!< Camera capture 0 data input bus bit 1. */
	PM3_EBI_AD6              = (0x08), /*!< EBI address/data bus bit6. */
	PM3_EBI_ADR6             = (0x0a), /*!< EBI address/data bus bit*. */

	/* PM.4 MFP */
	PM4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PM4_I2C5_SDA             = (0x04), /*!< I2C5 data input/output pin. */
	PM4_VCAP0_DATA2          = (0x06), /*!< Camera capture 0 data input bus bit 2. */
	PM4_EBI_AD7              = (0x08), /*!< EBI address/data bus bit7. */
	PM4_EBI_ADR7             = (0x0a), /*!< EBI address/data bus bit*. */

	/* PM.5 MFP */
	PM5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PM5_I2C5_SCL             = (0x04), /*!< I2C5 clock pin. */
	PM5_VCAP0_DATA3          = (0x06), /*!< Camera capture 0 data input bus bit 3. */
	PM5_EBI_AD8              = (0x08), /*!< EBI address/data bus bit8. */
	PM5_EBI_ADR8             = (0x0a), /*!< EBI address/data bus bit*. */

	/* PM.6 MFP */
	PM6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PM6_CAN0_RXD             = (0x03), /*!< CAN0 bus receiver input. */
	PM6_USBHL1_DM            = (0x04), /*!< USB 1.1 host-lite 1 differential signal D-. */
	PM6_VCAP0_DATA4          = (0x06), /*!< Camera capture 0 data input bus bit 4. */
	PM6_EBI_AD9              = (0x08), /*!< EBI address/data bus bit9. */
	PM6_EBI_ADR9             = (0x0a), /*!< EBI address/data bus bit*. */

	/* PM.7 MFP */
	PM7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PM7_CAN0_TXD             = (0x03), /*!< CAN0 bus transmitter output. */
	PM7_USBHL1_DP            = (0x04), /*!< USB 1.1 host-lite 1 differential signal D+. */
	PM7_VCAP0_DATA5          = (0x06), /*!< Camera capture 0 data input bus bit 5. */
	PM7_EBI_AD10             = (0x08), /*!< EBI address/data bus bit1. */
	PM7_EBI_ADR10            = (0x0a), /*!< EBI address/data bus bit*. */

	/* PM.8 MFP */
	PM8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PM8_I2C0_SDA             = (0x04), /*!< I2C0 data input/output pin. */
	PM8_VCAP0_DATA6          = (0x06), /*!< Camera capture 0 data input bus bit 6. */
	PM8_EBI_AD11             = (0x08), /*!< EBI address/data bus bit1. */
	PM8_EBI_ADR11            = (0x0a), /*!< EBI address/data bus bit*. */

	/* PM.9 MFP */
	PM9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PM9_I2C0_SCL             = (0x04), /*!< I2C0 clock pin. */
	PM9_VCAP0_DATA7          = (0x06), /*!< Camera capture 0 data input bus bit 7. */
	PM9_EBI_AD12             = (0x08), /*!< EBI address/data bus bit1. */
	PM9_EBI_ADR12            = (0x0a), /*!< EBI address/data bus bit*. */

	/* PM.10 MFP */
	PM10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PM10_EPWM1_CH2           = (0x01), /*!< EPWM1 channel2 output/capture input. */
	PM10_CAN2_RXD            = (0x03), /*!< CAN2 bus receiver input. */
	PM10_USBHL4_DM           = (0x04), /*!< USB 1.1 host-lite 4 differential signal D-. */
	PM10_SPI3_SS0            = (0x05), /*!< 1st SPI3 slave select pin. */
	PM10_VCAP0_DATA8         = (0x06), /*!< Camera capture 0 data input bus bit 8. */
	PM10_SPI2_I2SMCLK        = (0x07), /*!< SPI2 I2S master clock output pin. */
	PM10_EBI_AD13            = (0x08), /*!< EBI address/data bus bit1. */
	PM10_EBI_ADR13           = (0x0a), /*!< EBI address/data bus bit*. */

	/* PM.11 MFP */
	PM11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PM11_EPWM1_CH3           = (0x01), /*!< EPWM1 channel3 output/capture input. */
	PM11_CAN2_TXD            = (0x03), /*!< CAN2 bus transmitter output. */
	PM11_USBHL4_DP           = (0x04), /*!< USB 1.1 host-lite 4 differential signal D+. */
	PM11_SPI3_SS1            = (0x05), /*!< 1st SPI3 slave select pin. */
	PM11_VCAP0_DATA9         = (0x06), /*!< Camera capture 0 data input bus bit 9. */
	PM11_SPI2_SS1            = (0x07), /*!< 1st SPI2 slave select pin. */
	PM11_EBI_AD14            = (0x08), /*!< EBI address/data bus bit1. */
	PM11_EBI_ADR14           = (0x0a), /*!< EBI address/data bus bit*. */

	/* PM.12 MFP */
	PM12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PM12_EPWM1_CH4           = (0x01), /*!< EPWM1 channel4 output/capture input. */
	PM12_UART10_nCTS         = (0x02), /*!< Clear to Send input pin for UART10. */
	PM12_TRACE_DATA0         = (0x03), /*!< ETM Rx input bus bit0. */
	PM12_UART11_RXD          = (0x04), /*!< Data receiver input pin for UART11. */
	PM12_I2C2_SDA            = (0x05), /*!< I2C2 data input/output pin. */
	PM12_SC1_nCD             = (0x07), /*!< SmartCard1 card detect pin. */
	PM12_EBI_AD8             = (0x08), /*!< EBI address/data bus bit8. */
	PM12_I2S1_MCLK           = (0x09), /*!< I2S1 master clock output pin. */
	PM12_TM8                 = (0x0b), /*!< Timer8 event counter input / toggle output */

	/* PM.13 MFP */
	PM13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PM13_EPWM1_CH5           = (0x01), /*!< EPWM1 channel5 output/capture input. */
	PM13_UART10_nRTS         = (0x02), /*!< Request to Send output pin for UART10. */
	PM13_TRACE_DATA1         = (0x03), /*!< ETM Rx input bus bit1. */
	PM13_UART11_TXD          = (0x04), /*!< Data transmitter output pin for UART11. */
	PM13_I2C2_SCL            = (0x05), /*!< I2C2 clock pin. */
	PM13_EBI_AD9             = (0x08), /*!< EBI address/data bus bit9. */
	PM13_TM8_EXT             = (0x0b), /*!< Timer8 event counter input / toggle output */

	/* PM.14 MFP */
	PM14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PM14_EPWM1_BRAKE0        = (0x01), /*!< Brake input pin 0 of EPWM1. */
	PM14_UART10_RXD          = (0x02), /*!< Data receiver input pin for UART10. */
	PM14_TRACE_DATA2         = (0x03), /*!< ETM Rx input bus bit2. */
	PM14_CAN2_RXD            = (0x04), /*!< CAN2 bus receiver input. */
	PM14_USBHL3_DM           = (0x05), /*!< USB 1.1 host-lite 3 differential signal D-. */
	PM14_I2C3_SDA            = (0x06), /*!< I2C3 data input/output pin. */
	PM14_EBI_AD10            = (0x08), /*!< EBI address/data bus bit1. */
	PM14_TM10                = (0x0b), /*!< Timer1 event counter input / toggle output */
	PM14_INT1                = (0x0d), /*!< External interrupt1 input pin. */

	/* PM.15 MFP */
	PM15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PM15_EPWM1_BRAKE1        = (0x01), /*!< Brake input pin 1 of EPWM1. */
	PM15_UART10_TXD          = (0x02), /*!< Data transmitter output pin for UART10. */
	PM15_TRACE_DATA3         = (0x03), /*!< ETM Rx input bus bit3. */
	PM15_CAN2_TXD            = (0x04), /*!< CAN2 bus transmitter output. */
	PM15_USBHL3_DP           = (0x05), /*!< USB 1.1 host-lite 3 differential signal D+. */
	PM15_I2C3_SCL            = (0x06), /*!< I2C3 clock pin. */
	PM15_EBI_AD11            = (0x08), /*!< EBI address/data bus bit1. */
	PM15_TM10_EXT            = (0x0b), /*!< Timer1 event counter input / toggle output */
	PM15_INT2                = (0x0d), /*!< External interrupt2 input pin. */

	/* PN.0 MFP */
	PN0_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PN0_I2C2_SDA             = (0x04), /*!< I2C2 data input/output pin. */
	PN0_VCAP1_DATA0          = (0x06), /*!< Camera capture 1 data input bus bit 0. */

	/* PN.1 MFP */
	PN1_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PN1_I2C2_SCL             = (0x04), /*!< I2C2 clock pin. */
	PN1_VCAP1_DATA1          = (0x06), /*!< Camera capture 1 data input bus bit 1. */

	/* PN.2 MFP */
	PN2_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PN2_CAN0_RXD             = (0x03), /*!< CAN0 bus receiver input. */
	PN2_USBHL0_DM            = (0x04), /*!< USB 1.1 host-lite 0 differential signal D-. */
	PN2_VCAP1_DATA2          = (0x06), /*!< Camera capture 1 data input bus bit 2. */

	/* PN.3 MFP */
	PN3_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PN3_CAN0_TXD             = (0x03), /*!< CAN0 bus transmitter output. */
	PN3_USBHL0_DP            = (0x04), /*!< USB 1.1 host-lite 0 differential signal D+. */
	PN3_VCAP1_DATA3          = (0x06), /*!< Camera capture 1 data input bus bit 3. */

	/* PN.4 MFP */
	PN4_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PN4_I2C1_SDA             = (0x04), /*!< I2C1 data input/output pin. */
	PN4_VCAP1_DATA4          = (0x06), /*!< Camera capture 1 data input bus bit 4. */

	/* PN.5 MFP */
	PN5_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PN5_I2C1_SCL             = (0x04), /*!< I2C1 clock pin. */
	PN5_VCAP1_DATA5          = (0x06), /*!< Camera capture 1 data input bus bit 5. */

	/* PN.6 MFP */
	PN6_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PN6_CAN1_RXD             = (0x03), /*!< CAN1 bus receiver input. */
	PN6_USBHL1_DM            = (0x04), /*!< USB 1.1 host-lite 1 differential signal D-. */
	PN6_VCAP1_DATA6          = (0x06), /*!< Camera capture 1 data input bus bit 6. */

	/* PN.7 MFP */
	PN7_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PN7_CAN1_TXD             = (0x03), /*!< CAN1 bus transmitter output. */
	PN7_USBHL1_DP            = (0x04), /*!< USB 1.1 host-lite 1 differential signal D+. */
	PN7_VCAP1_DATA7          = (0x06), /*!< Camera capture 1 data input bus bit 7. */

	/* PN.8 MFP */
	PN8_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PN8_EPWM2_CH4            = (0x01), /*!< EPWM2 channel4 output/capture input. */
	PN8_I2C0_SDA             = (0x04), /*!< I2C0 data input/output pin. */
	PN8_SPI2_I2SMCLK         = (0x05), /*!< SPI2 I2S master clock output pin. */
	PN8_VCAP1_DATA8          = (0x06), /*!< Camera capture 1 data input bus bit 8. */

	/* PN.9 MFP */
	PN9_GPIO                 = (0x00), /*!< General purpose digital I/O pin. */
	PN9_EPWM2_CH5            = (0x01), /*!< EPWM2 channel5 output/capture input. */
	PN9_I2C0_SCL             = (0x04), /*!< I2C0 clock pin. */
	PN9_SPI1_I2SMCLK         = (0x05), /*!< SPI1 I2S master clock output pin. */
	PN9_VCAP1_DATA9          = (0x06), /*!< Camera capture 1 data input bus bit 9. */

	/* PN.10 MFP */
	PN10_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PN10_CAN2_RXD            = (0x03), /*!< CAN2 bus receiver input. */
	PN10_USBHL2_DM           = (0x04), /*!< USB 1.1 host-lite 2 differential signal D-. */
	PN10_VCAP1_SCLK          = (0x06), /*!< Camera capture 1 interface sensor clock output pin. */

	/* PN.11 MFP */
	PN11_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PN11_CAN2_TXD            = (0x03), /*!< CAN2 bus transmitter output. */
	PN11_USBHL2_DP           = (0x04), /*!< USB 1.1 host-lite 2 differential signal D+. */
	PN11_VCAP1_PIXCLK        = (0x06), /*!< Camera capture 1 interface pixel clock input pin. */

	/* PN.12 MFP */
	PN12_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PN12_UART6_nCTS          = (0x02), /*!< Clear to Send input pin for UART6. */
	PN12_UART12_RXD          = (0x03), /*!< Data receiver input pin for UART12. */
	PN12_I2C5_SDA            = (0x04), /*!< I2C5 data input/output pin. */
	PN12_VCAP1_HSYNC         = (0x06), /*!< Camera capture 1 interface hsync input pin. */

	/* PN.13 MFP */
	PN13_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PN13_UART6_nRTS          = (0x02), /*!< Request to Send output pin for UART6. */
	PN13_UART12_TXD          = (0x03), /*!< Data transmitter output pin for UART12. */
	PN13_I2C5_SCL            = (0x04), /*!< I2C5 clock pin. */
	PN13_VCAP1_VSYNC         = (0x06), /*!< Camera capture 1 interface vsync input pin. */

	/* PN.14 MFP */
	PN14_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PN14_UART6_RXD           = (0x02), /*!< Data receiver input pin for UART6. */
	PN14_CAN3_RXD            = (0x03), /*!< CAN3 bus receiver input. */
	PN14_USBHL3_DM           = (0x04), /*!< USB 1.1 host-lite 3 differential signal D-. */
	PN14_SPI1_SS1            = (0x05), /*!< 1st SPI1 slave select pin. */
	PN14_VCAP1_SFIELD        = (0x06), /*!< Camera capture 1 interface SFIELD input pin. */
	PN14_SPI1_I2SMCLK        = (0x07), /*!< SPI1 I2S master clock output pin. */

	/* PN.15 MFP */
	PN15_GPIO                = (0x00), /*!< General purpose digital I/O pin. */
	PN15_EPWM2_CH4           = (0x01), /*!< EPWM2 channel4 output/capture input. */
	PN15_UART6_TXD           = (0x02), /*!< Data transmitter output pin for UART6. */
	PN15_CAN3_TXD            = (0x03), /*!< CAN3 bus transmitter output. */
	PN15_USBHL3_DP           = (0x04), /*!< USB 1.1 host-lite 3 differential signal D+. */
	PN15_I2S0_MCLK           = (0x05), /*!< I2S0 master clock output pin. */
	PN15_SPI1_SS1            = (0x06), /*!< 1st SPI1 slave select pin. */
	PN15_SPI1_I2SMCLK        = (0x07), /*!< SPI1 I2S master clock output pin. */
	PN15_SC0_nCD             = (0x08), /*!< SmartCard0 card detect pin. */
	PN15_CLKO                = (0x0a), /*!< Clock Output pin. */
	PN15_TM6                 = (0x0b), /*!< Timer6 event counter input / toggle output */
}altFunc_t;

