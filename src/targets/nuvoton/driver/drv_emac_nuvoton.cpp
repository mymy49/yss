#include <targets/nuvoton/NuvotonEmac.h>
#include <drv/peripheral.h>
#include <util/Timeout.h>

NuvotonEmac::NuvotonEmac(const Drv::setup_t drvSetup, const setup_t setup) : Drv(drvSetup)
{
	mDev = setup.dev;
	mMallocBuffer = nullptr;
}

error_t NuvotonEmac::initialize(config_t config)
{
	error_t result;
	Timeout timeout(1000);
	uint32_t csr = getClockFrequency();

	if(csr < 20000000)
		return error_t::WRONG_CLOCK_FREQUENCY;
	else if(csr < 35000000)
		csr = 2;
	else if(csr < 60000000)
		csr = 3;
	else if(csr < 100000000)
		csr = 0;
	else if(csr < 150000000)
		csr = 1;
	else if(csr < 250000000)
		csr = 4;
	else if(csr < 300000000)
		csr = 5;
	else
		return error_t::WRONG_CLOCK_FREQUENCY;

	if (mDev == EMAC0)
		SYS->EMAC0MISCR |= SYS_EMAC0MISCR_RMIIEN_Msk;
	else if (mDev == EMAC1)
        SYS->EMAC1MISCR |= SYS_EMAC1MISCR_RMIIEN_Msk;

	reset();
	mDev->DmaBusMode |= EMAC_DmaBusMode_SWR_Msk;

	// SWR 비트가 0으로 자동 클리어될 때까지 타임아웃 대기
	// (REFCLK 50MHz 클럭이 들어오고 있다면 보통 수십 사이클 내에 완료됨)
	while (mDev->DmaBusMode & EMAC_DmaBusMode_SWR_Msk)
	{
		if(timeout.isTimeout())
			return error_t::TIMEOUT;
	}

	// DMA 버스 파라미터 설정
	// - AAL = 1 (주소 정렬 버스트)
	// - PBL = 32 (최대 32 beat 버스트)
	// - ATDS = 0 (16바이트 기본 디스크립터 사용)
	// - DSL = 0 (디스크립터 간격 0)
	setTwoFieldsData(mDev->DmaBusMode,	EMAC_DmaBusMode_AAL_Msk, 1, EMAC_DmaBusMode_AAL_Pos, 
										EMAC_DmaBusMode_PBL_Msk, 32, EMAC_DmaBusMode_PBL_Pos);
	
	// (선택 사항) AXI 버스 모드 최적화 (Register 1010)
	// BLEN4, BLEN8, BLEN16 활성화
	mDev->DmaAxiBusMode |= (EMAC_DmaAxiBusMode_BLEN16_Msk | 
							EMAC_DmaAxiBusMode_BLEN8_Msk  | 
							EMAC_DmaAxiBusMode_BLEN4_Msk);

	// DMA Operation Mode 설정 (Store-and-Forward) [추가]
	mDev->DmaOpMode = (EMAC_DmaOpMode_TSF_Msk | EMAC_DmaOpMode_RSF_Msk | EMAC_DmaOpMode_OSF_Msk);

	setFieldData(mDev->GmiiAddr, EMAC_GmiiAddr_CR_Msk, csr, EMAC_GmiiAddr_CR_Pos);
	
	mRxDescCount = config.rxDescriptorCount;
	mTxDescCount = config.txDescriptorCount;

	result = malloc();
	if (result != error_t::ERROR_NONE)
	    return result;

	// DMA 엔진에 디스크립터 시작 주소 등록
	mDev->DmaRxDesc = (uintptr_t)mRxDesc;
	mDev->DmaTxDesc = (uintptr_t)mTxDesc;

	updateConfig();

	mDev->Config |= (EMAC_Config_RE_Msk | // Receiver Enable (수신 켜기)
                     EMAC_Config_TE_Msk | // Transmitter Enable (송신 켜기)
                     EMAC_Config_DM_Msk | // Duplex Mode (1: Full Duplex)
                     EMAC_Config_FES_Msk);// Speed (1: 100Mbps)

	// 패킷 필터링 개방 (FrameFilter 레지스터)
    // 개발/테스트 초기에는 모든 패킷(브로드캐스트/유니캐스트)을 다 수락하도록 설정
    mDev->FrameFilter = EMAC_FrameFilter_RA_Msk; // Receive All (Promiscuous mode)

	// DMA 수신 엔진 구동 (DmaOpMode 레지스터)
    // 기존 TSF, RSF, OSF에 'SR(Start Receive)' 비트를 추가해야 DMA가 버퍼로 복사를 시작합니다.
    mDev->DmaOpMode |= (EMAC_DmaOpMode_SR_Msk | EMAC_DmaOpMode_ST_Msk);

	// DMA 수신 폴링 트리거 (DmaRxPollDemand 레지스터)
    // 아무 값이나 쓰면 DMA가 즉시 0번 Rx 디스크립터를 읽어 대기 상태에 들어갑니다.
    mDev->DmaRxPollDemand = 0;

	return error_t::ERROR_NONE;
}

void NuvotonEmac::updateConfig()
{
	setFieldData(mDev->GmiiAddr, EMAC_GmiiAddr_PA_Msk, mPhysicalLayerAddr, EMAC_GmiiAddr_PA_Pos);  
}