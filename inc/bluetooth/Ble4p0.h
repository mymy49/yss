/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_BLUETOOTH_BLE4p0__H_
#define YSS_BLUETOOTH_BLE4p0__H_

#include <yss/error.h>
#include <yss/Thread.h>

class Ble;

class Ble4p0 : private Thread
{
public :
	enum speed_t
	{
		BLE_1MBPS,
		BLE_2MBPS
	};

	enum packetType_t
	{
	    PACKET_TYPE_ADV_IND         = 0x00, ///< 일반적인 Advertising (연결 가능, 스캔 가능) - 가장 흔함
	    PACKET_TYPE_ADV_DIRECT_IND  = 0x01, ///< 특정 기기를 지정한 Advertising (빠른 재연결용)
	    PACKET_TYPE_ADV_NONCONN_IND = 0x02, ///< 연결 불가 Advertising (온도계, iBeacon 등 단순 방송용)
	    PACKET_TYPE_SCAN_REQ        = 0x03, ///< 스캔 요청 (추가 정보를 요구할 때 스캐너가 보냄)
	    PACKET_TYPE_SCAN_RSP        = 0x04, ///< 스캔 응답 (스캔 요청을 받고 기기 이름 등을 추가로 줄 때)
	    PACKET_TYPE_CONNECT_IND     = 0x05, ///< 연결 요청 (스마트폰이 기기와 연결을 시도할 때 보냄)
	    PACKET_TYPE_ADV_SCAN_IND    = 0x06, ///< 스캔 가능 Advertising (연결은 안 되지만 추가 정보는 줄 수 있음)
	    PACKET_TYPE_ADV_EXT_IND     = 0x07  ///< 확장 Advertising (BLE 5.0 이상, 대용량 데이터 송신용)
	};

	enum adType_t
	{
	    // ==========================================
	    // 플래그 (디바이스의 기본 상태 정보)
	    // ==========================================
	    AD_TYPE_FLAGS                       = 0x01, ///< LE 제한적 발견 모드, LE 일반 발견 모드 등 1바이트 비트마스크
	    // ==========================================
	    // 서비스 UUID (이 기기가 지원하는 기능들)
	    // ==========================================
	    AD_TYPE_16BIT_SERVICE_UUID_MORE     = 0x02, ///< 불완전한 16비트 서비스 UUID 목록 (더 있음)
	    AD_TYPE_16BIT_SERVICE_UUID_COMPLETE = 0x03, ///< 완전한 16비트 서비스 UUID 목록
	    AD_TYPE_32BIT_SERVICE_UUID_MORE     = 0x04, ///< 불완전한 32비트 서비스 UUID 목록
	    AD_TYPE_32BIT_SERVICE_UUID_COMPLETE = 0x05, ///< 완전한 32비트 서비스 UUID 목록
	    AD_TYPE_128BIT_SERVICE_UUID_MORE    = 0x06, ///< 불완전한 128비트 서비스 UUID 목록
	    AD_TYPE_128BIT_SERVICE_UUID_COMPLETE= 0x07, ///< 완전한 128비트 서비스 UUID 목록
	    // ==========================================
	    // 디바이스 이름 (가장 많이 파싱하게 될 데이터!)
	    // ==========================================
	    AD_TYPE_SHORTENED_LOCAL_NAME        = 0x08, ///< 줄여진 이름 (예: "Sam..." - 용량이 부족할 때)
	    AD_TYPE_COMPLETE_LOCAL_NAME         = 0x09, ///< 완전한 디바이스 이름 (예: "Samsung TV")
	    // ==========================================
	    // 송신 파워 (거리 계산용)
	    // ==========================================
	    AD_TYPE_TX_POWER_LEVEL              = 0x0A, ///< 송신 출력 파워 레벨 (-127 ~ +127 dBm) (비콘에서 거리 계산할 때 쓰임)
	    // ==========================================
	    // 연결 관련 정보
	    // ==========================================
	    AD_TYPE_OOB_CLASS_OF_DEVICE         = 0x0D, ///< Class of Device (클래식 블루투스용, BLE에선 잘 안 씀)
	    AD_TYPE_OOB_SIMPLE_PAIRING_HASHC    = 0x0E, ///< 페어링 해시값
	    AD_TYPE_OOB_SIMPLE_PAIRING_RANDOMR  = 0x0F, ///< 페어링 랜덤값
	    AD_TYPE_DEVICE_ID                   = 0x10, ///< 디바이스 ID (Device ID Profile)
	    AD_TYPE_SECURITY_MANAGER_OOB_FLAGS  = 0x11, ///< 보안 매니저 플래그
	    AD_TYPE_SLAVE_CONNECTION_INTERVAL_RANGE = 0x12, ///< 노예(Slave) 기기가 원하는 연결 주기 (Min~Max)
	    // ==========================================
	    // 서비스 데이터 (UUID와 함께 짧은 데이터 전송)
	    // ==========================================
	    AD_TYPE_16BIT_SERVICE_DATA          = 0x16, ///< 16비트 UUID에 종속된 데이터 (예: 체온계 온도 값)
	    AD_TYPE_128BIT_SERVICE_DATA         = 0x21, ///< 128비트 UUID에 종속된 커스텀 데이터
	    // ==========================================
	    // 기타
	    // ==========================================
	    AD_TYPE_PUBLIC_TARGET_ADDRESS       = 0x17, ///< 특정 Public 주소를 가진 기기만 날 보라고 지정
	    AD_TYPE_RANDOM_TARGET_ADDRESS       = 0x18, ///< 특정 Random 주소를 가진 기기만 날 보라고 지정
	    AD_TYPE_APPEARANCE                  = 0x19, ///< 기기 외형/아이콘 (예: 시계, 마우스, 체온계 등 폰 화면에 표시될 아이콘 번호)
	    AD_TYPE_ADVERTISING_INTERVAL        = 0x1A, ///< Advertising을 쏘는 주기
	    AD_TYPE_LE_BLUETOOTH_DEVICE_ADDRESS = 0x1B, ///< BLE 장치 주소
	    // ==========================================
	    // 제조사 전용 (iBeacon 등 커스텀 데이터용)
	    // ==========================================
	    AD_TYPE_MANUFACTURER_SPECIFIC_DATA  = 0xFF  ///< 제조사 전용 데이터 (가장 중요!)
	                                                ///< (첫 2바이트는 무조건 제조사 ID(예: 0x004C=Apple), 그 뒤는 맘대로!)
	};

	struct config_t
	{
		Ble &dev;
	};

	Ble4p0();

	error_t initialize(config_t config);

protected :
	uint8_t* getRxMacAddress();
	
	uint16_t getRxCount();

	packetType_t getRxPacketType();

	uint8_t getRxAdvCount();

	uint8_t getRxAdvType();

	bool isRxAdvInfoAble();

private :
	 Ble *mDev;

	 void thread() override;
};

#endif

