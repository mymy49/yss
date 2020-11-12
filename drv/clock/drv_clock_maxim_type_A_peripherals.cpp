////////////////////////////////////////////////////////////////////////////////////////
//
// 저작권 표기 License_ver_2.0
// 본 소스코드의 소유권은 yss Embedded Operating System 네이버 카페 관리자와 운영진에게 있습니다.
// 운영진이 임의로 코드의 권한을 타인에게 양도할 수 없습니다.
// 본 소스코드는 아래 사항에 동의할 경우에 사용 가능합니다.
// 아래 사항에 대해 동의하지 않거나 이해하지 못했을 경우 사용을 금합니다.
// 본 소스코드를 사용하였다면 아래 사항을 모두 동의하는 것으로 자동 간주 합니다.
// 본 소스코드의 상업적 또는 비상업적 이용이 가능합니다.
// 본 소스코드의 내용을 임의로 수정하여 재배포하는 행위를 금합니다.
// 본 소스코드의 내용을 무단 전재하는 행위를 금합니다.
// 본 소스코드의 사용으로 인해 발생하는 모든 사고에 대해서 어떤한 법적 책임을 지지 않습니다.
//
//	Home Page : http://cafe.naver.com/yssoperatingsystem
//	Copyright 2020.	yss Embedded Operating System all right reserved.
//  
//	이전 주담당자 : 아이구 (mymy49@nate.com) 2016.04.30 ~ 2020.04.26
//  주담당자 : 맨틀코어 (tttwwuu@naver.com) 2020.04.26 ~ 현재
//  부담당자 : -
//
////////////////////////////////////////////////////////////////////////////////////////

#if	defined (__SAML21E15A__) || defined (__SAML21E15B__) || defined (__SAML21E16A__) || defined (__SAML21E16B__) || \
	defined (__SAML21E17A__) || defined (__SAML21E17B__) || defined (__SAML21E18B__) || defined (__SAML21G16A__) || \
	defined (__SAML21G16B__) || defined (__SAML21G17A__) || defined (__SAML21G17B__) || defined (__SAML21G18A__) || \
	defined (__SAML21G18B__) || defined (__SAML21J16A__) || defined (__SAML21J16B__) || defined (__SAML21J17A__) || \
	defined (__SAML21J17B__) || defined (__SAML21J18A__) || defined (__SAML21J18B__)

#define GCLK_DFLL48M_REF			0
#define GCLK_DPLL					1
#define GCLK_DPLL_32K				2
#define GCLK_EIC					3
#define GCLK_USB					4
#define GCLK_EVSYS_CHANNEL_0		5
#define GCLK_EVSYS_CHANNEL_1		6
#define GCLK_EVSYS_CHANNEL_2		7
#define GCLK_EVSYS_CHANNEL_3		8
#define GCLK_EVSYS_CHANNEL_4		9
#define GCLK_EVSYS_CHANNEL_5		10
#define GCLK_EVSYS_CHANNEL_6		11
#define GCLK_EVSYS_CHANNEL_7		12
#define GCLK_EVSYS_CHANNEL_8		13
#define GCLK_EVSYS_CHANNEL_9		14
#define GCLK_EVSYS_CHANNEL_10		15
#define GCLK_EVSYS_CHANNEL_11		16
#define GCLK_SERCOM_SLOW			17
#define GCLK_SERCOM0_CORE			18
#define GCLK_SERCOM1_CORE			19
#define GCLK_SERCOM2_CORE			20
#define GCLK_SERCOM3_CORE			21
#define GCLK_SERCOM4_CORE			22
#define GCLK_SERCOM5_SLOW			23
#define GCLK_SERCOM5_CORE			24
#define GCLK_TCC0					25
#define GCLK_TCC1					25
#define GCLK_TCC2					26
#define GCLK_TC0					27
#define GCLK_TC1					27
#define GCLK_TC2					28
#define GCLK_TC3					28
#define GCLK_TC4					29
#define GCLK_ADC					30
#define GCLK_AC						31
#define GCLK_DAC					32
#define GCLK_PTC					33
#define GCLK_CCL					34


#include <__cross_studio_io.h>

#include <drv/peripherals.h>

namespace drv
{
	bool Peripheral::setPeripheralClock(unsigned char num, unsigned char gen, bool en, bool lock)
    {
		if(num >= sizeof(GCLK->PCHCTRL) / 4)
			return false;

		GCLK->PCHCTRL[num].reg = (gen << GCLK_PCHCTRL_GEN_Pos & GCLK_PCHCTRL_GEN_Msk) | (en << GCLK_PCHCTRL_CHEN_Pos & GCLK_PCHCTRL_CHEN) | (en << GCLK_PCHCTRL_WRTLOCK_Pos & GCLK_PCHCTRL_WRTLOCK);

        return true;
    }

#if defined(SERCOM0)
	void Peripheral::setSerCom0En(bool en)
	{
		GCLK->PCHCTRL[(GCLK_SERCOM0_CORE)].bit.CHEN = en;
	}
		
#endif
// ################################### AHB1ENR 시작 ########################################
#if	defined(GPIOA)
	void Peripheral::setGpioAEn(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN_Msk;
	}

	void Peripheral::resetGpioA(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOARST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOARST_Msk;
	}
#endif

#if	defined(GPIOB)
	void Peripheral::setGpioBEn(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN_Msk;
	}

	void Peripheral::resetGpioB(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOBRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOBRST_Msk;
	}
#endif

#if	defined(GPIOC)
	void Peripheral::setGpioCEn(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN_Msk;
	}

	void Peripheral::resetGpioC(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOCRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOCRST_Msk;
	}
#endif

#if	defined(GPIOD)
	void Peripheral::setGpioDEn(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN_Msk;
	}

	void Peripheral::resetGpioD(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIODRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIODRST_Msk;
	}
#endif

#if	defined(GPIOE)
	void Peripheral::setGpioEEn(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOEEN_Msk;
	}

	void Peripheral::resetGpioE(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOERST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOERST_Msk;
	}
#endif

#if	defined(GPIOF)
	void Peripheral::setGpioFEn(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOFEN_Msk;
	}

	void Peripheral::resetGpioF(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOFRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOFRST_Msk;
	}
#endif

#if	defined(GPIOG)
	void Peripheral::setGpioGEn(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOGEN_Msk;
	}

	void Peripheral::resetGpioG(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOGRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOGRST_Msk;
	}
#endif

#if	defined(GPIOH)
	void Peripheral::setGpioHEn(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOHEN_Msk;
	}

	void Peripheral::resetGpioH(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOHRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOHRST_Msk;
	}
#endif

#if	defined(GPIOI)
	void Peripheral::setGpioIEn(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOIEN_Msk;
	}

	void Peripheral::resetGpioI(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOIRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOIRST_Msk;
	}
#endif

#if	defined(GPIOJ)
	void Peripheral::setGpioJEn(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOJEN_Msk;
	}

	void Peripheral::resetGpioJ(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOJRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOJRST_Msk;
	}
#endif

#if	defined(GPIOK)
	void Peripheral::setGpioKEn(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOKEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOKEN_Msk;
	}

	void Peripheral::resetGpioK(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOKRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_GPIOKRST_Msk;
	}
#endif

#if defined(CRC)
	void Peripheral::setCrcEn(bool en)
    {
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_CRCEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_CRCEN_Msk;
    }

	void Peripheral::resetCrc(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_CRCRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_CRCRST_Msk;
	}
#endif

#if defined(BKPSRAM_BASE)
	void Peripheral::setBackupSramEn(bool en)
    {
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_BKPSRAMEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_BKPSRAMEN_Msk;
    }
#endif

#if defined(CCMDATARAM_BASE)
	void Peripheral::setCcmRamEn(bool en)
    {
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_CCMDATARAMEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_CCMDATARAMEN_Msk;
    }
#endif

#if defined(DMA1)
	void Peripheral::setDmaEn(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA1EN_Msk;
#if defined(DMA2)
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2EN_Msk;
#endif
	}

	void Peripheral::resetDma(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA1RST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_DMA1RST_Msk;
#if defined(DMA2)
		RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA2RST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_DMA2RST_Msk;
#endif
	}
#endif

#if defined(DMA2D)
	void Peripheral::setDma2d(bool en)
	{
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_DMA2DEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2DEN_Msk;
	}

	void Peripheral::resetDma2d(void)
	{
		RCC->AHB1RSTR |= RCC_AHB1RSTR_DMA2DRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_DMA2DRST_Msk;
	}
#endif

#if defined(ETH)
	void Peripheral::setEthernetMacEn(bool en)
    {
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACEN_Msk;
	}

	void Peripheral::setEthernetRxEn(bool en)
    {
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACRXEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACRXEN_Msk;
    }

	void Peripheral::setEthernetTxEn(bool en)
    {
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACTXEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACTXEN_Msk;
    }

	void Peripheral::setEthernetPtpEn(bool en)
    {
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_ETHMACPTPEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_ETHMACPTPEN_Msk;
    }

	void Peripheral::resetEthernetMac(void)
    {
		RCC->AHB1RSTR |= RCC_AHB1RSTR_ETHMACRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_ETHMACRST_Msk;
    }
#endif

#if defined(USB_OTG_HS)
	void Peripheral::setUsbdHsEn(bool en)
    {
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_OTGHSEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_OTGHSEN_Msk;
    }

	void Peripheral::setUsbdHsUlpiEn(bool en)
    {
		if(en)
			RCC->AHB1ENR |= RCC_AHB1ENR_OTGHSULPIEN_Msk;
		else
			RCC->AHB1ENR &= ~RCC_AHB1ENR_OTGHSULPIEN_Msk;
    }

	void Peripheral::resetUsbHs(void)
    {
		RCC->AHB1RSTR |= RCC_AHB1RSTR_OTGHRST_Msk;
		RCC->AHB1RSTR &= ~RCC_AHB1RSTR_OTGHRST_Msk;
    }
#endif

// ################################### AHB1ENR 끝 ########################################


// ################################### AHB2ENR 시작 ########################################

#if defined(DCMI)
	void Peripheral::setDcmiEn(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_DCMIEN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_DCMIEN_Msk;
	}

	void Peripheral::resetDcmi(void)
    {
		RCC->AHB2RSTR |= RCC_AHB2RSTR_DCMIRST_Msk;
		RCC->AHB2RSTR &= ~RCC_AHB2RSTR_DCMIRST_Msk;
    }
#endif

#if defined(CRYP)
	void Peripheral::setCrypEn(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_CRYPEN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_CRYPEN_Msk;		
	}

	void Peripheral::resetCryp(void)
    {
		RCC->AHB2RSTR |= RCC_AHB2RSTR_CRYPRST_Msk;
		RCC->AHB2RSTR &= ~RCC_AHB2RSTR_CRYPRST_Msk;
    }
#endif

#if defined(HASH)
	void Peripheral::setHashEn(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_HASHEN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_HASHEN_Msk;		
	}

	void Peripheral::resetHash(void)
    {
		RCC->AHB2RSTR |= RCC_AHB2RSTR_HASHRST_Msk;
		RCC->AHB2RSTR &= ~RCC_AHB2RSTR_HASHRST_Msk;
    }
#endif

#if defined(RNG)
	void Peripheral::setRngEn(bool en)
    {
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_RNGEN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_RNGEN_Msk;		
    }
	
	void Peripheral::resetRng(void)
    {
		RCC->AHB2RSTR |= RCC_AHB2RSTR_RNGRST_Msk;
		RCC->AHB2RSTR &= ~RCC_AHB2RSTR_RNGRST_Msk;
    }
#endif

#if defined(USB_OTG_FS)
	void Peripheral::setUsbdFsEn(bool en)
	{
		if(en)
			RCC->AHB2ENR |= RCC_AHB2ENR_OTGFSEN_Msk;
		else
			RCC->AHB2ENR &= ~RCC_AHB2ENR_OTGFSEN_Msk;		
	}
	
	void Peripheral::resetUsbFs(void)
    {
		RCC->AHB2RSTR |= RCC_AHB2RSTR_OTGFSRST_Msk;
		RCC->AHB2RSTR &= ~RCC_AHB2RSTR_OTGFSRST_Msk;
    }
#endif

// ################################### AHB2ENR 끝 ########################################



// ################################### AHB3ENR 시작 ########################################

#if defined(FMC_Bank1)
	void Peripheral::setFmcEn(bool en)
	{
		if(en)
			RCC->AHB3ENR |= RCC_AHB3ENR_FMCEN_Msk;
		else
			RCC->AHB3ENR &= ~RCC_AHB3ENR_FMCEN_Msk;		
	}

	void Peripheral::resetFmc(void)
    {
		RCC->AHB3RSTR |= RCC_AHB3RSTR_FMCRST_Msk;
		RCC->AHB3RSTR &= ~RCC_AHB3RSTR_FMCRST_Msk;
    }
#endif

// ################################### AHB3ENR 끝 ########################################



// ################################### APB1ENR 시작 ########################################

#if defined(TIM2)
	void Peripheral::setTimer2En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_TIM2EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN_Msk;		
	}

	void Peripheral::resetTimer2(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_TIM2RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM2RST_Msk;
    }
#endif

#if defined(TIM3)
	void Peripheral::setTimer3En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_TIM3EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_TIM3EN_Msk;		
	}

	void Peripheral::resetTimer3(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_TIM3RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM3RST_Msk;
    }
#endif

#if defined(TIM4)
	void Peripheral::setTimer4En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_TIM4EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_TIM4EN_Msk;		
	}

	void Peripheral::resetTimer4(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_TIM4RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM4RST_Msk;
    }
#endif

#if defined(TIM5)
	void Peripheral::setTimer5En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_TIM5EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_TIM5EN_Msk;		
	}

	void Peripheral::resetTimer5(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_TIM5RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM5RST_Msk;
    }
#endif

#if defined(TIM6)
	void Peripheral::setTimer6En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_TIM6EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_TIM6EN_Msk;		
	}

	void Peripheral::resetTimer6(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_TIM6RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM6RST_Msk;
    }
#endif

#if defined(TIM7)
	void Peripheral::setTimer7En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_TIM7EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_TIM7EN_Msk;		
	}

	void Peripheral::resetTimer7(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_TIM7RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM7RST_Msk;
    }
#endif

#if defined(TIM12)
	void Peripheral::setTimer12En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_TIM12EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_TIM12EN_Msk;		
	}

	void Peripheral::resetTimer12(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_TIM12RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM12RST_Msk;
    }
#endif

#if defined(TIM13)
	void Peripheral::setTimer13En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_TIM13EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_TIM13EN_Msk;		
	}

	void Peripheral::resetTimer13(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_TIM13RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM13RST_Msk;
    }
#endif

#if defined(TIM14)
	void Peripheral::setTimer14En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_TIM14EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_TIM14EN_Msk;		
	}

	void Peripheral::resetTimer14(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_TIM14RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM14RST_Msk;
    }
#endif

#if defined(WWDG)
	void Peripheral::setWindowWatchdogEn(bool en)
    {
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_WWDGEN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_WWDGEN_Msk;		
    }

	void Peripheral::resetWindowWatchdog(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_WWDGRST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_WWDGRST_Msk;
    }
#endif

#if defined(SPI2)
	void Peripheral::setSpi2En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_SPI2EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_SPI2EN_Msk;		
	}

	void Peripheral::resetSpi2(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_SPI2RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_SPI2RST_Msk;
    }
#endif

#if defined(SPI3)
	void Peripheral::setSpi3En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_SPI3EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_SPI3EN_Msk;		
	}

	void Peripheral::resetSpi3(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_SPI3RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_SPI3RST_Msk;
    }
#endif

#if defined(USART2)
	void Peripheral::setUart2En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_USART2EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_USART2EN_Msk;		
	}

	void Peripheral::resetUart2(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_USART2RST_Msk;
    }
#endif

#if defined(USART3)
	void Peripheral::setUart3En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_USART3EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_USART3EN_Msk;		
	}

	void Peripheral::resetUart3(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_USART3RST_Msk;
    }
#endif

#if defined(UART4)
	void Peripheral::setUart4En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_UART4EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_UART4EN_Msk;		
	}

	void Peripheral::resetUart4(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_UART4RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_UART4RST_Msk;
    }
#endif

#if defined(UART5)
	void Peripheral::setUart5En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_UART5EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_UART5EN_Msk;		
	}

	void Peripheral::resetUart5(void)
    {
		RCC->APB1RSTR |= RCC_APB1RSTR_UART5RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_UART5RST_Msk;
    }
#endif

#if	defined(I2C1)
	void Peripheral::setI2c1En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_I2C1EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_I2C1EN_Msk;
	}

	void Peripheral::resetI2c1(void)
	{
		RCC->APB1RSTR |= RCC_APB1RSTR_I2C1RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C1RST_Msk;
	}
#endif

#if	defined(I2C2)
	void Peripheral::setI2c2En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_I2C2EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_I2C2EN_Msk;
	}

	void Peripheral::resetI2c2(void)
	{
		RCC->APB1RSTR |= RCC_APB1RSTR_I2C2RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C2RST_Msk;
	}
#endif

#if	defined(I2C3)
	void Peripheral::setI2c3En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_I2C3EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_I2C3EN_Msk;
	}

	void Peripheral::resetI2c3(void)
	{
		RCC->APB1RSTR |= RCC_APB1RSTR_I2C3RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_I2C3RST_Msk;
	}
#endif

#if defined(CAN1)
	void Peripheral::setCan1En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_CAN1EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_CAN1EN_Msk;
	}

	void Peripheral::resetCan1(void)
	{
		RCC->APB1RSTR |= RCC_APB1RSTR_CAN1RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN1RST_Msk;
	}
#endif

#if defined(CAN2)
	void Peripheral::setCan2En(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_CAN2EN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_CAN2EN_Msk;
	}

	void Peripheral::resetCan2(void)
	{
		RCC->APB1RSTR |= RCC_APB1RSTR_CAN2RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN2RST_Msk;
	}
#endif

#if defined(PWR)
	void Peripheral::setPwrEn(bool en)
	{
		if(en)
			RCC->APB1ENR |= RCC_APB1ENR_PWREN_Msk;
		else
			RCC->APB1ENR &= ~RCC_APB1ENR_PWREN_Msk;
	}

	void Peripheral::resetPwr(void)
	{
		RCC->APB1RSTR |= RCC_APB1RSTR_PWRRST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_PWRRST_Msk;
	}
#endif

#if defined(DAC1)
	void Peripheral::setDacEn(bool en)
	{
		if(en)
			RCC->APB1ENR |=	RCC_APB1ENR_DACEN_Msk;
		else
			RCC->APB1ENR &=	~RCC_APB1ENR_DACEN_Msk;
	}

	void Peripheral::resetDac(void)
	{
		RCC->APB1RSTR |= RCC_APB1RSTR_DACRST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_DACRST_Msk;
	}
#endif

#if defined(UART7)
	void Peripheral::setUart7En(bool en)
	{
		if(en)
			RCC->APB1ENR |=	RCC_APB1ENR_UART7EN_Msk;
		else
			RCC->APB1ENR &=	~RCC_APB1ENR_UART7EN_Msk;
	}

	void Peripheral::resetUart7(void)
	{
		RCC->APB1RSTR |= RCC_APB1RSTR_UART7RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_UART7RST_Msk;
	}
#endif

#if defined(UART8)
	void Peripheral::setUart8En(bool en)
	{
		if(en)
			RCC->APB1ENR |=	RCC_APB1ENR_UART8EN_Msk;
		else
			RCC->APB1ENR &=	~RCC_APB1ENR_UART8EN_Msk;
	}

	void Peripheral::resetUart8(void)
	{
		RCC->APB1RSTR |= RCC_APB1RSTR_UART8RST_Msk;
		RCC->APB1RSTR &= ~RCC_APB1RSTR_UART8RST_Msk;
	}
#endif

// ################################### APB1ENR 끝 ########################################



// ################################### APB2ENR 시작 ########################################

#if defined(TIM1)
	void Peripheral::setTimer1En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_TIM1EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_TIM1EN_Msk;
	}

	void Peripheral::resetTimer1(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_TIM1RST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM1RST_Msk;
	}
#endif

#if defined(TIM8)
	void Peripheral::setTimer8En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_TIM8EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_TIM8EN_Msk;
	}

	void Peripheral::resetTimer8(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_TIM8RST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM8RST_Msk;
	}
#endif

#if defined(USART1)
	void Peripheral::setUart1En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_USART1EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_USART1EN_Msk;
	}

	void Peripheral::resetUart1(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_USART1RST_Msk;
	}
#endif

#if defined(USART6)
	void Peripheral::setUart6En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_USART6EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_USART6EN_Msk;
	}

	void Peripheral::resetUart6(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_USART6RST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_USART6RST_Msk;
	}
#endif

#if defined(ADC1)
	void Peripheral::setAdc1En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_ADC1EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_ADC1EN_Msk;
	}

	void Peripheral::resetAdc(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_ADCRST_Msk;
	}
#endif

#if defined(ADC2)
	void Peripheral::setAdc2En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_ADC2EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_ADC2EN_Msk;
	}
#endif

#if defined(ADC3)
	void Peripheral::setAdc3En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_ADC3EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_ADC3EN_Msk;
	}
#endif

#if defined(SDIO)
	void Peripheral::setSdioEn(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_SDIOEN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_SDIOEN_Msk;
	}

	void Peripheral::resetSdio(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_SDIORST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_SDIORST_Msk;
	}
#endif

#if defined(SPI1)
	void Peripheral::setSpi1En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_SPI1EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_SPI1EN_Msk;
	}

	void Peripheral::resetSpi1(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_SPI1RST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI1RST_Msk;
	}
#endif

#if defined(SPI4)
	void Peripheral::setSpi4En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_SPI4EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_SPI4EN_Msk;
	}

	void Peripheral::resetSpi4(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_SPI4RST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI4RST_Msk;
	}
#endif

#if defined(SYSCFG)
	void Peripheral::setSyscfgEn(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_SYSCFGEN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_SYSCFGEN_Msk;
	}

	void Peripheral::resetSyscfg(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_SYSCFGRST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_SYSCFGRST_Msk;
	}
#endif

#if defined(TIM9)
	void Peripheral::setTimer9En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_TIM9EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_TIM9EN_Msk;
	}

	void Peripheral::resetTimer9(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_TIM9RST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM9RST_Msk;
	}
#endif

#if defined(TIM10)
	void Peripheral::setTimer10En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_TIM10EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_TIM10EN_Msk;
	}

	void Peripheral::resetTimer10(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_TIM10RST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM10RST_Msk;
	}
#endif

#if defined(TIM11)
	void Peripheral::setTimer11En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_TIM11EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_TIM11EN_Msk;
	}

	void Peripheral::resetTimer11(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_TIM11RST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM11RST_Msk;
	}
#endif

#if defined(SPI5)
	void Peripheral::setSpi5En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_SPI5EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_SPI5EN_Msk;
	}

	void Peripheral::resetSpi5(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_SPI5RST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI5RST_Msk;
	}
#endif

#if defined(SPI6)
	void Peripheral::setSpi6En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_SPI6EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_SPI6EN_Msk;
	}

	void Peripheral::resetSpi6(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_SPI6RST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI6RST_Msk;
	}
#endif

#if defined(SAI1)
	void setSai1En(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_SAI1EN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_SAI1EN_Msk;
	}

	void Peripheral::resetSai1(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_SAI1RST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_SAI1RST_Msk;
	}
#endif

#if defined(LTDC)
	void Peripheral::setLtdcEn(bool en)
	{
		if(en)
			RCC->APB2ENR |=	RCC_APB2ENR_LTDCEN_Msk;
		else
			RCC->APB2ENR &=	~RCC_APB2ENR_LTDCEN_Msk;
	}

	void Peripheral::resetLtdc(void)
	{
		RCC->APB2RSTR |= RCC_APB2RSTR_LTDCRST_Msk;
		RCC->APB2RSTR &= ~RCC_APB2RSTR_LTDCRST_Msk;
	}
#endif

// ################################### APB2ENR 끝 ########################################
}

#endif
