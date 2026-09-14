/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_BLUETOOTH_TYPES__H_
#define YSS_BLUETOOTH_TYPES__H_

#include <stdint.h>

/**
 * @brief Bluetooth Low Energy (BLE) Link Layer Control PDU Opcodes
 * @note 블루투스 Core Specification 기반
 */
enum ble_ll_opcode_t
{
	// --- Bluetooth 4.0 기본 연결 관리 ---
	LL_CONNECTION_UPDATE_IND    = 0x00, // 연결 파라미터 업데이트 지시
	LL_CHANNEL_MAP_IND          = 0x01, // 채널 맵 업데이트 지시
	LL_TERMINATE_IND            = 0x02, // 연결 종료 지시

	// --- 암호화 (Encryption) ---
	LL_ENC_REQ                  = 0x03, // 암호화 요청
	LL_ENC_RSP                  = 0x04, // 암호화 응답
	LL_START_ENC_REQ            = 0x05, // 암호화 시작 요청
	LL_START_ENC_RSP            = 0x06, // 암호화 시작 응답

	LL_UNKNOWN_RSP              = 0x07, // 알 수 없는 OPCODE에 대한 응답

	// --- 기능(Feature) 및 버전 교환 ---
	LL_FEATURE_REQ              = 0x08, // 지원 기능(Feature) 요청 (Master -> Slave)
	LL_FEATURE_RSP              = 0x09, // 지원 기능 응답
	LL_PAUSE_ENC_REQ            = 0x0A, // 암호화 일시 정지 요청
	LL_PAUSE_ENC_RSP            = 0x0B, // 암호화 일시 정지 응답
	LL_VERSION_IND              = 0x0C, // 칩셋 및 블루투스 버전 교환
	LL_REJECT_IND               = 0x0D, // 요청 거절 (에러 코드 포함)

	// --- Bluetooth 4.1 ~ 4.2 추가 ---
	LL_SLAVE_FEATURE_REQ        = 0x0E, // 지원 기능 요청 (Slave -> Master)
	LL_CONNECTION_PARAM_REQ     = 0x0F, // 연결 파라미터 변경 요청
	LL_CONNECTION_PARAM_RSP     = 0x10, // 연결 파라미터 변경 응답
	LL_REJECT_EXT_IND           = 0x11, // 확장된 요청 거절
	LL_PING_REQ                 = 0x12, // 연결 생존 확인(Ping) 요청
	LL_PING_RSP                 = 0x13, // 연결 생존 확인 응답
	LL_LENGTH_REQ               = 0x14, // 데이터 길이 확장(DLE) 요청
	LL_LENGTH_RSP               = 0x15, // 데이터 길이 확장 응답

	// --- Bluetooth 5.0 (PHY 계층 변경) ---
	LL_PHY_REQ                  = 0x16, // PHY(통신 속도/거리) 변경 요청 (2M, Coded)
	LL_PHY_RSP                  = 0x17, // PHY 변경 응답
	LL_PHY_UPDATE_IND           = 0x18, // PHY 변경 적용 지시
	LL_MIN_USED_CHANNELS_IND    = 0x19, // 최소 사용 채널 수 지시

	// --- Bluetooth 5.1 (방향 탐지 - Direction Finding) ---
	LL_CTE_REQ                  = 0x1A, // Constant Tone Extension 요청
	LL_CTE_RSP                  = 0x1B, // Constant Tone Extension 응답
	LL_PERIODIC_SYNC_IND        = 0x1C, // 주기적 광고 동기화 지시
	LL_CLOCK_ACCURACY_REQ       = 0x1D, // 클럭 정확도(SCA) 요청
	LL_CLOCK_ACCURACY_RSP       = 0x1E, // 클럭 정확도 응답

	// --- Bluetooth 5.2 (LE Audio - ISOC / 전력 제어) ---
	LL_CIS_REQ                  = 0x1F, // Connected Isochronous Stream 요청 (오디오용)
	LL_CIS_RSP                  = 0x20, // CIS 응답
	LL_CIS_IND                  = 0x21, // CIS 지시
	LL_CIS_TERMINATE_IND        = 0x22, // CIS 연결 종료 지시
	LL_POWER_CONTROL_REQ        = 0x23, // 전송 전력 제어 요청
	LL_POWER_CONTROL_RSP        = 0x24, // 전송 전력 제어 응답
	LL_POWER_CHANGE_IND         = 0x25, // 전송 전력 변경 지시

	// --- Bluetooth 5.3 (Subrating) ---
	LL_SUBRATE_REQ              = 0x26, // Connection Subrating 요청 (빠른 반응속도 전환)
	LL_SUBRATE_RSP              = 0x27, // Subrating 응답
	LL_SUBRATE_IND              = 0x28, // Subrating 지시
	// 그 외 규격 업데이트에 따라 0x29 이상의 값이 추가될 수 있음
	LL_OPCODE_MAX_RESERVED      = 0xFF  
};

enum ble_gap_ad_type_t
{
	// ==========================================
	// 플래그 (디바이스의 기본 상태 정보)
	// ==========================================
	BLE_GAP_AD_TYPE_FLAGS                               = 0x01, ///< LE 제한적 발견 모드, LE 일반 발견 모드 등

	// ==========================================
	// 서비스 UUID (이 기기가 지원하는 기능들)
	// ==========================================
	BLE_GAP_AD_TYPE_16BIT_SERVICE_UUID_MORE_AVAILABLE   = 0x02, ///< 불완전한 16비트 서비스 UUID 목록
	BLE_GAP_AD_TYPE_16BIT_SERVICE_UUID_COMPLETE         = 0x03, ///< 완전한 16비트 서비스 UUID 목록
	BLE_GAP_AD_TYPE_32BIT_SERVICE_UUID_MORE_AVAILABLE   = 0x04, ///< 불완전한 32비트 서비스 UUID 목록
	BLE_GAP_AD_TYPE_32BIT_SERVICE_UUID_COMPLETE         = 0x05, ///< 완전한 32비트 서비스 UUID 목록
	BLE_GAP_AD_TYPE_128BIT_SERVICE_UUID_MORE_AVAILABLE  = 0x06, ///< 불완전한 128비트 서비스 UUID 목록
	BLE_GAP_AD_TYPE_128BIT_SERVICE_UUID_COMPLETE        = 0x07, ///< 완전한 128비트 서비스 UUID 목록

	// ==========================================
	// 디바이스 이름 (가장 많이 파싱하게 될 데이터!)
	// ==========================================
	BLE_GAP_AD_TYPE_SHORT_LOCAL_NAME                    = 0x08, ///< 줄여진 이름 (예: "Sam...")
	BLE_GAP_AD_TYPE_COMPLETE_LOCAL_NAME                 = 0x09, ///< 완전한 디바이스 이름 (예: "Samsung TV")

	// ==========================================
	// 송신 파워 (거리 계산용)
	// ==========================================
	BLE_GAP_AD_TYPE_TX_POWER_LEVEL                      = 0x0A, ///< 송신 출력 파워 레벨 (-127 ~ +127 dBm)

	// ==========================================
	// 연결 관련 정보
	// ==========================================
	BLE_GAP_AD_TYPE_CLASS_OF_DEVICE                     = 0x0D, ///< Class of Device
	BLE_GAP_AD_TYPE_SIMPLE_PAIRING_HASH_C               = 0x0E, ///< 페어링 해시값
	BLE_GAP_AD_TYPE_SIMPLE_PAIRING_RANDOM_R             = 0x0F, ///< 페어링 랜덤값
	BLE_GAP_AD_TYPE_SECURITY_MANAGER_TK_VALUE           = 0x10, ///< 보안 매니저 TK 값 (또는 Device ID)
	BLE_GAP_AD_TYPE_SECURITY_MANAGER_OOB_FLAGS          = 0x11, ///< 보안 매니저 플래그
	BLE_GAP_AD_TYPE_SLAVE_CONNECTION_INTERVAL_RANGE     = 0x12, ///< 노예(Slave) 기기가 원하는 연결 주기

	// ==========================================
	// 서비스 데이터 (UUID와 함께 짧은 데이터 전송)
	// ==========================================
	BLE_GAP_AD_TYPE_SERVICE_DATA_16BIT_UUID             = 0x16, ///< 16비트 UUID에 종속된 데이터
	BLE_GAP_AD_TYPE_SERVICE_DATA_128BIT_UUID            = 0x21, ///< 128비트 UUID에 종속된 커스텀 데이터

	// ==========================================
	// 기타
	// ==========================================
	BLE_GAP_AD_TYPE_PUBLIC_TARGET_ADDRESS               = 0x17, ///< 특정 Public 주소를 가진 기기 타겟
	BLE_GAP_AD_TYPE_RANDOM_TARGET_ADDRESS               = 0x18, ///< 특정 Random 주소를 가진 기기 타겟
	BLE_GAP_AD_TYPE_APPEARANCE                          = 0x19, ///< 기기 외형/아이콘 (Appearance)
	BLE_GAP_AD_TYPE_ADVERTISING_INTERVAL                = 0x1A, ///< Advertising 주기
	BLE_GAP_AD_TYPE_LE_BLUETOOTH_DEVICE_ADDRESS         = 0x1B, ///< BLE 장치 주소

	// ==========================================
	// 제조사 전용 (iBeacon 등 커스텀 데이터용)
	// ==========================================
	BLE_GAP_AD_TYPE_MANUFACTURER_SPECIFIC_DATA          = 0xFF  ///< 제조사 전용 커스텀 데이터
};

enum ble_gap_adv_flag_t
{
	// ==========================================
	// 개별 플래그 비트 (Standard Bluetooth Flags)
	// ==========================================
	BLE_GAP_ADV_FLAG_LE_LIMITED_DISC_MODE = (1 << 0), ///< 0x01: 제한적 발견 모드 (일정 시간만 스캔됨)
	BLE_GAP_ADV_FLAG_LE_GENERAL_DISC_MODE = (1 << 1), ///< 0x02: 일반 발견 모드 (계속 스캔됨)
	BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED = (1 << 2), ///< 0x04: 클래식 블루투스(BR/EDR) 미지원 (BLE 전용 기기)
	BLE_GAP_ADV_FLAG_LE_BR_EDR_CONTROLLER = (1 << 3), ///< 0x08: Controller에서 BLE와 클래식 동시 지원
	BLE_GAP_ADV_FLAG_LE_BR_EDR_HOST       = (1 << 4), ///< 0x10: Host에서 BLE와 클래식 동시 지원
	// ==========================================
	// 자주 쓰이는 조합 (Convenience Combos)
	// ==========================================
	///< 0x05: BLE 전용 기기 + 제한적 발견 모드
	BLE_GAP_ADV_FLAGS_LE_ONLY_LIMITED_DISC_MODE = (BLE_GAP_ADV_FLAG_LE_LIMITED_DISC_MODE | BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED),

	///< 0x06: BLE 전용 기기 + 일반 발견 모드 (스마트폰과 연결하는 대부분의 BLE 기기가 0x06 값을 사용!)
	BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE = (BLE_GAP_ADV_FLAG_LE_GENERAL_DISC_MODE | BLE_GAP_ADV_FLAG_BR_EDR_NOT_SUPPORTED)
};

enum ble_adv_pdu_type_t
{
	BLE_ADV_PDU_TYPE_ADV_IND         = 0x00, ///< 일반적인 Advertising (연결 가능, 스캔 가능) - 가장 흔함
	BLE_ADV_PDU_TYPE_ADV_DIRECT_IND  = 0x01, ///< 특정 기기를 지정한 Advertising (빠른 재연결용)
	BLE_ADV_PDU_TYPE_ADV_NONCONN_IND = 0x02, ///< 연결 불가 Advertising (온도계, iBeacon 등 단순 방송용)
	BLE_ADV_PDU_TYPE_SCAN_REQ        = 0x03, ///< 스캔 요청 (추가 정보를 요구할 때 스캐너가 보냄)
	BLE_ADV_PDU_TYPE_SCAN_RSP        = 0x04, ///< 스캔 응답 (스캔 요청을 받고 기기 이름 등을 추가로 줄 때)
	BLE_ADV_PDU_TYPE_CONNECT_IND     = 0x05, ///< 연결 요청 (스마트폰이 기기와 연결을 시도할 때 보냄)
	BLE_ADV_PDU_TYPE_ADV_SCAN_IND    = 0x06, ///< 스캔 가능 Advertising (연결은 안 되지만 추가 정보는 줄 수 있음)
	BLE_ADV_PDU_TYPE_ADV_EXT_IND     = 0x07, ///< 확장 Advertising (BLE 5.0 이상, 대용량 데이터 송신용)

	// 소프트웨어 내부 상태/예외 처리용
	BLE_ADV_PDU_TYPE_INVALID         = 0xFF  ///< 유효하지 않은 패킷 (수신된 데이터 없음 등)	
};

/**
 * @brief Bluetooth Core Specification Link Layer Version Numbers
 */
enum ble_ll_version_t
{
	BLE_LL_VERSION_1_0B = 0x00, ///< Bluetooth Core Specification 1.0b
	BLE_LL_VERSION_1_1  = 0x01, ///< Bluetooth Core Specification 1.1
	BLE_LL_VERSION_1_2  = 0x02, ///< Bluetooth Core Specification 1.2
	BLE_LL_VERSION_2_0  = 0x03, ///< Bluetooth Core Specification 2.0 + EDR
	BLE_LL_VERSION_2_1  = 0x04, ///< Bluetooth Core Specification 2.1 + EDR
	BLE_LL_VERSION_3_0  = 0x05, ///< Bluetooth Core Specification 3.0 + HS
	BLE_LL_VERSION_4_0  = 0x06, ///< Bluetooth Core Specification 4.0
	BLE_LL_VERSION_4_1  = 0x07, ///< Bluetooth Core Specification 4.1
	BLE_LL_VERSION_4_2  = 0x08, ///< Bluetooth Core Specification 4.2
	BLE_LL_VERSION_5_0  = 0x09, ///< Bluetooth Core Specification 5.0
	BLE_LL_VERSION_5_1  = 0x0A, ///< Bluetooth Core Specification 5.1
	BLE_LL_VERSION_5_2  = 0x0B, ///< Bluetooth Core Specification 5.2
	BLE_LL_VERSION_5_3  = 0x0C, ///< Bluetooth Core Specification 5.3
	BLE_LL_VERSION_5_4  = 0x0D  ///< Bluetooth Core Specification 5.4
};

/**
 * @brief Bluetooth SIG Registered Company Identifiers (Common examples)
 * @note 너무 많은(3000개 이상) ID가 존재하므로 주요 제조사만 나열
 */
enum ble_company_id_t
{
	BLE_COMP_ID_ERICSSON    = 0x0000,
	BLE_COMP_ID_INTEL       = 0x0002,
	BLE_COMP_ID_MICROSOFT   = 0x0006,
	BLE_COMP_ID_TI          = 0x000D, // Texas Instruments
	BLE_COMP_ID_BROADCOM    = 0x000F,
	BLE_COMP_ID_QUALCOMM    = 0x001D,
	BLE_COMP_ID_ST          = 0x0030, // STMicroelectronics
	BLE_COMP_ID_APPLE       = 0x004C,
	BLE_COMP_ID_NORDIC      = 0x0059, // Nordic Semiconductor
	BLE_COMP_ID_REALTEK     = 0x005D,
	BLE_COMP_ID_SAMSUNG     = 0x0075,
	BLE_COMP_ID_GOOGLE      = 0x00E0,
	BLE_COMP_ID_SONY        = 0x012D
};

#pragma pack(push, 1)
// LL_VERSION_IND (Opcode: 0x0C) 패킷 구조체
struct ll_version_ind_t
{
    uint8_t  versNr;       // 블루투스 코어 규격 버전 (예: 0x09 = BLE 5.0)
    uint16_t compId;       // 제조사 고유 ID (예: 0x0059 = Nordic Semiconductor)
    uint16_t subVersNr;    // 펌웨어 세부 버전 (제조사 자유)
};

// LL_FEATURE_REQ (0x08) 및 LL_FEATURE_RSP (0x09) 패킷 구조체 (비트필드 적용)
struct ble_ll_feature_pdu_t
{
    // FeatureSet (8 Bytes = 64 bits)
    // --- Byte 0 ---
    uint8_t leEncryption : 1;        ///< Bit 0: LE Encryption
    uint8_t connParamReq : 1;        ///< Bit 1: Connection Parameters Request Procedure
    uint8_t extRejectInd : 1;        ///< Bit 2: Extended Reject Indication
    uint8_t slaveInitFeatExch : 1;   ///< Bit 3: Slave-initiated Features Exchange
    uint8_t lePing : 1;              ///< Bit 4: LE Ping
    uint8_t leDataLenExt : 1;        ///< Bit 5: LE Data Packet Length Extension (DLE)
    uint8_t llPrivacy : 1;           ///< Bit 6: LL Privacy
    uint8_t extScanFilter : 1;       ///< Bit 7: Extended Scanner Filter Policies

    // --- Byte 1 ---
    uint8_t le2mPhy : 1;             ///< Bit 8: LE 2M PHY
    uint8_t stableModTx : 1;         ///< Bit 9: Stable Modulation Index - Transmitter
    uint8_t stableModRx : 1;         ///< Bit 10: Stable Modulation Index - Receiver
    uint8_t leCodedPhy : 1;          ///< Bit 11: LE Coded PHY (Long Range)
    uint8_t leExtAdv : 1;            ///< Bit 12: LE Extended Advertising
    uint8_t lePeriodicAdv : 1;       ///< Bit 13: LE Periodic Advertising
    uint8_t chanSelAlgo2 : 1;        ///< Bit 14: Channel Selection Algorithm #2
    uint8_t lePowerClass1 : 1;       ///< Bit 15: LE Power Class 1

    // --- Byte 2 ---
    uint8_t minUsedChan : 1;         ///< Bit 16: Minimum Number of Used Channels Procedure
    uint8_t connCteReq : 1;          ///< Bit 17: Connection CTE Request
    uint8_t connCteRsp : 1;          ///< Bit 18: Connection CTE Response
    uint8_t connlessCteTx : 1;       ///< Bit 19: Connectionless CTE Transmitter
    uint8_t connlessCteRx : 1;       ///< Bit 20: Connectionless CTE Receiver
    uint8_t antSwitchTxAod : 1;      ///< Bit 21: Antenna Switching During CTE Tx (AoD)
    uint8_t antSwitchRxAoa : 1;      ///< Bit 22: Antenna Switching During CTE Rx (AoA)
    uint8_t rxCte : 1;               ///< Bit 23: Receiving Constant Tone Extensions

    // --- Byte 3 ---
    uint8_t periodicSyncTransTx : 1; ///< Bit 24: Periodic Advertising Sync Transfer - Sender
    uint8_t periodicSyncTransRx : 1; ///< Bit 25: Periodic Advertising Sync Transfer - Recipient
    uint8_t sleepClockAccUpd : 1;    ///< Bit 26: Sleep Clock Accuracy Updates
    uint8_t remotePubKeyValid : 1;   ///< Bit 27: Remote Public Key Validation
    uint8_t connectedIsoStreamTx : 1;///< Bit 28: Connected Isochronous Stream Tx
    uint8_t connectedIsoStreamRx : 1;///< Bit 29: Connected Isochronous Stream Rx
    uint8_t connlessIsoStreamTx : 1; ///< Bit 30: Connectionless Isochronous Stream Tx
    uint8_t connlessIsoStreamRx : 1; ///< Bit 31: Connectionless Isochronous Stream Rx

    // --- Byte 4 ---
    uint8_t isochronousBroadcaster : 1; ///< Bit 32: Isochronous Broadcaster
    uint8_t synchronizedReceiver : 1;   ///< Bit 33: Synchronized Receiver
    uint8_t isochronousChannelsTx : 1;  ///< Bit 34: Isochronous Channels Tx
    uint8_t isochronousChannelsRx : 1;  ///< Bit 35: Isochronous Channels Rx
    uint8_t lePowerControlReq : 1;      ///< Bit 36: LE Power Control Request
    uint8_t lePowerChangeInd : 1;       ///< Bit 37: LE Power Change Indication
    uint8_t lePathLossMonitoring : 1;   ///< Bit 38: LE Path Loss Monitoring
    uint8_t periodicAdvAdi : 1;         ///< Bit 39: Periodic Advertising ADI

    // --- Byte 5 ---
    uint8_t connSubrating : 1;          ///< Bit 40: Connection Subrating
    uint8_t connSubratingHostSync : 1;  ///< Bit 41: Connection Subrating Host Support
    uint8_t channelClassification : 1;  ///< Bit 42: Channel Classification
    uint8_t advCodingSelection : 1;     ///< Bit 43: Advertising Coding Selection
    uint8_t advCodingSelHostSync : 1;   ///< Bit 44: Advertising Coding Selection Host Support
    uint8_t reserved5_5 : 1;
    uint8_t reserved5_6 : 1;
    uint8_t reserved5_7 : 1;

    // --- Byte 6 ~ 7 ---
    uint8_t reserved6;
    uint8_t reserved7;
};

// LL_CONNECTION_UPDATE_IND (Opcode: 0x00) 패킷 구조체
struct ble_ll_conn_update_ind_t
{
    uint8_t  opcode;      // 명령어 식별자 (무조건 0x00)
    uint8_t  winSize;     // Transmit Window Size (값 * 1.25ms)
    uint16_t winOffset;   // Transmit Window Offset (값 * 1.25ms)
    uint16_t interval;    // 새로운 Connection Interval (값 * 1.25ms)
    uint16_t latency;     // Slave Latency (Slave가 무시해도 되는 이벤트 횟수)
    uint16_t timeout;     // Supervision Timeout (값 * 10ms)
    uint16_t instant;     // ★ 핵심: 이 변경사항이 적용되는 '이벤트 카운터(Event Counter)' 시점
};

#pragma pack(pop)

#endif

