/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(NRF52840_XXAA)

#include <drv/peripheral.h>
#include <drv/Gpio.h>
#include <yss/reg.h>
#include <nrf52840_bitfields.h>

#pragma GCC optimize("O1")

/**
 * @file drv_gpio_nuvoton.cpp
 * @brief GPIO target-specific driver source file for Nuvoton.
 */

Gpio::Gpio(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
}


error_t Gpio::setAsOutput(uint8_t pin, otype_t otype)
{
	if(pin > 31)
		return error_t::OUT_OF_PIN_INDEX_RANGE;

	mDev->DIRSET = 1 << pin;

	setFieldData(mDev->PIN_CNF[pin], GPIO_PIN_CNF_DRIVE_Msk, otype, GPIO_PIN_CNF_DRIVE_Pos);

	return error_t::ERROR_NONE;
}

error_t Gpio::setAsInput(uint8_t pin)
{
	return error_t::ERROR_NONE;
}


void Gpio::setOutput(uint8_t pin, bool data)
{
	if(data)
		mDev->OUTSET = 1 << pin;
	else
		mDev->OUTCLR = 1 << pin;
}

error_t Gpio::setAsAltFunc(uint8_t pin, altFunc_t altfunc)
{
	uint8_t port;

	switch((uint32_t)mDev)
	{
	case NRF_P0_BASE :
		port = 0;
		break;

	case NRF_P1_BASE :
		port = 1;
		break;

	default :
		return error_t::UNSUPPORTED_GPIO_PORT;
	}

	switch(altfunc)
	{
	case UART0_RTS :
		setThreeFieldsData(NRF_UARTE0->PSEL.RTS,	UARTE_PSEL_RTS_PORT_Msk, port, UARTE_PSEL_RTS_PORT_Pos,
													UARTE_PSEL_RTS_PIN_Msk, pin, UARTE_PSEL_RTS_PIN_Pos,
													UARTE_PSEL_RTS_CONNECT_Msk, UARTE_PSEL_RTS_CONNECT_Connected, UARTE_PSEL_RTS_CONNECT_Pos);
		break;

	case UART0_TXD :
		setThreeFieldsData(NRF_UARTE0->PSEL.TXD,	UARTE_PSEL_TXD_PORT_Msk, port, UARTE_PSEL_TXD_PORT_Pos,
													UARTE_PSEL_TXD_PIN_Msk, pin, UARTE_PSEL_TXD_PIN_Pos,
													UARTE_PSEL_TXD_CONNECT_Msk, UARTE_PSEL_TXD_CONNECT_Connected, UARTE_PSEL_RTS_CONNECT_Pos);
		break;

	case UART0_CTS :
		setThreeFieldsData(NRF_UARTE0->PSEL.CTS,	UARTE_PSEL_CTS_PORT_Msk, port, UARTE_PSEL_CTS_PORT_Pos,
													UARTE_PSEL_CTS_PIN_Msk, pin, UARTE_PSEL_CTS_PIN_Pos,
													UARTE_PSEL_CTS_CONNECT_Msk, UARTE_PSEL_CTS_CONNECT_Connected, UARTE_PSEL_RTS_CONNECT_Pos);
		break;

	case UART0_RXD :
		setThreeFieldsData(NRF_UARTE0->PSEL.RXD,	UARTE_PSEL_RXD_PORT_Msk, port, UARTE_PSEL_RXD_PORT_Pos,
													UARTE_PSEL_RXD_PIN_Msk, pin, UARTE_PSEL_RXD_PIN_Pos,
													UARTE_PSEL_RXD_CONNECT_Msk, UARTE_PSEL_RXD_CONNECT_Connected, UARTE_PSEL_RTS_CONNECT_Pos);
		break;
	}

	switch(altfunc)
	{
	case UART0_RTS :
	case UART0_TXD :
		mDev->OUTSET = (1UL << pin);

		setFourFieldsData(mDev->PIN_CNF[pin], GPIO_PIN_CNF_DIR_Msk, GPIO_PIN_CNF_DIR_Output, GPIO_PIN_CNF_DIR_Pos
											, GPIO_PIN_CNF_INPUT_Msk, GPIO_PIN_CNF_INPUT_Disconnect, GPIO_PIN_CNF_INPUT_Pos
											, GPIO_PIN_CNF_PULL_Msk, GPIO_PIN_CNF_PULL_Disabled, GPIO_PIN_CNF_PULL_Pos
											, GPIO_PIN_CNF_DRIVE_Msk, S0S1, GPIO_PIN_CNF_DRIVE_Pos);
		break;

	case UART0_CTS :
	case UART0_RXD :
		setThreeFieldsData(mDev->PIN_CNF[pin], GPIO_PIN_CNF_DIR_Msk, GPIO_PIN_CNF_DIR_Input, GPIO_PIN_CNF_DIR_Pos
											, GPIO_PIN_CNF_INPUT_Msk, GPIO_PIN_CNF_INPUT_Connect, GPIO_PIN_CNF_INPUT_Pos
											, GPIO_PIN_CNF_PULL_Msk, GPIO_PIN_CNF_PULL_Pullup, GPIO_PIN_CNF_PULL_Pos);
		break;
	}

	return error_t::ERROR_NONE;
}

//error_t Gpio::setPackageAsAltFunc(altFuncPackage_t *package, uint8_t count, atype_t atype, outputDriveStrength_t strength)
//{
//	return error_t::ERROR_NONE;
//}

error_t Gpio::setPullUpDown(uint8_t pin, pupd_t pupd)
{
	return error_t::ERROR_NONE;
}

error_t Gpio::setGpioInterrupt(uint8_t pin, source_t src, void (*isr)(void))
{
	return error_t::ERROR_NONE;
}

error_t Gpio::setGpioInterrupt(uint8_t pin, source_t src, triggerId_t trigger)
{
	return error_t::ERROR_NONE;
}

void Gpio::isr(void)
{
}

bool Gpio::getInputData(uint8_t pin)
{
	return false;
}

#endif

