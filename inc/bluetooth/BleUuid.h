/*
 * Copyright (c) 2026 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_BLUETOOTH_BLE_UUID__H_
#define YSS_BLUETOOTH_BLE_UUID__H_

#include <stdint.h>

// ==========================================
// 1. GATT Declarations (선언형 UUID)
// ==========================================
enum ble_uuid_declaration_t : uint16_t
{
	BLE_UUID_DECLARATION_PRIMARY_SERVICE   = 0x2800, ///< 프라이머리 서비스 선언
	BLE_UUID_DECLARATION_SECONDARY_SERVICE = 0x2801, ///< 세컨더리 서비스 선언
	BLE_UUID_DECLARATION_INCLUDE           = 0x2802, ///< 다른 서비스 포함 선언
	BLE_UUID_DECLARATION_CHARACTERISTIC    = 0x2803  ///< 캐릭터리스틱 선언
};

// ==========================================
// 2. GATT Descriptors (설명자 UUID)
// ==========================================
enum ble_uuid_descriptor_t : uint16_t
{
	BLE_UUID_DESCRIPTOR_EXTENDED_PROPERTIES = 0x2900, ///< 확장 속성
	BLE_UUID_DESCRIPTOR_USER_DESCRIPTION    = 0x2901, ///< 사용자 설명 (문자열)
	BLE_UUID_DESCRIPTOR_CLIENT_CHAR_CONFIG  = 0x2902, ///< CCCD (Notify/Indicate 활성화 설정용, 매우 중요!)
	BLE_UUID_DESCRIPTOR_SERVER_CHAR_CONFIG  = 0x2903, ///< SCCD
	BLE_UUID_DESCRIPTOR_PRESENTATION_FORMAT = 0x2904, ///< 표시 포맷 (단위 등)
	BLE_UUID_DESCRIPTOR_AGGREGATE_FORMAT    = 0x2905  ///< 복합 포맷
};

// ==========================================
// 3. Standard Services (표준 서비스 UUID)
// ==========================================
enum ble_uuid_service_t : uint16_t
{
	BLE_UUID_SERVICE_GENERIC_ACCESS         = 0x1800, ///< GAP (Generic Access Profile)
	BLE_UUID_SERVICE_GENERIC_ATTRIBUTE      = 0x1801, ///< GATT (Generic Attribute Profile)
	BLE_UUID_SERVICE_IMMEDIATE_ALERT        = 0x1802, ///< 즉각 알림
	BLE_UUID_SERVICE_LINK_LOSS              = 0x1803, ///< 링크 손실
	BLE_UUID_SERVICE_TX_POWER               = 0x1804, ///< 송신 전력
	BLE_UUID_SERVICE_HEALTH_THERMOMETER     = 0x1809, ///< 온도계
	BLE_UUID_SERVICE_DEVICE_INFORMATION     = 0x180A, ///< 기기 정보 (제조사, 버전 등)
	BLE_UUID_SERVICE_HEART_RATE             = 0x180D, ///< 심박수
	BLE_UUID_SERVICE_BATTERY                = 0x180F, ///< 배터리 서비스
	BLE_UUID_SERVICE_BLOOD_PRESSURE         = 0x1810, ///< 혈압
	BLE_UUID_SERVICE_HID                    = 0x1812, ///< 휴먼 인터페이스 디바이스 (키보드, 마우스)
	BLE_UUID_SERVICE_ENVIRONMENTAL_SENSING  = 0x181A  ///< 환경 센서 (온도, 습도, 기압 등)
};

// ==========================================
// 4. Standard Characteristics (표준 캐릭터리스틱 UUID)
// ==========================================
enum ble_uuid_characteristic_t : uint16_t
{
	BLE_UUID_CHAR_DEVICE_NAME                     = 0x2A00, ///< 기기 이름 (필수)
	BLE_UUID_CHAR_APPEARANCE                      = 0x2A01, ///< 기기 외형(아이콘 번호)
	BLE_UUID_CHAR_PERIPHERAL_PRIVACY_FLAG         = 0x2A02, ///< 프라이버시 플래그
	BLE_UUID_CHAR_RECONNECTION_ADDRESS            = 0x2A03, ///< 재연결 주소
	BLE_UUID_CHAR_PERIPHERAL_PREF_CONN_PARAMS     = 0x2A04, ///< 페리페럴 선호 연결 파라미터 (PPCP)
	BLE_UUID_CHAR_SERVICE_CHANGED                 = 0x2A05, ///< 서비스 변경 알림
	BLE_UUID_CHAR_ALERT_LEVEL                     = 0x2A06, ///< 알림 레벨
	BLE_UUID_CHAR_TX_POWER_LEVEL                  = 0x2A07, ///< 송신 전력 레벨
	BLE_UUID_CHAR_DATE_TIME                       = 0x2A08, ///< 날짜 및 시간
	BLE_UUID_CHAR_DAY_OF_WEEK                     = 0x2A09, ///< 요일
	BLE_UUID_CHAR_DAY_DATE_TIME                   = 0x2A0A, ///< 날짜, 시간, 요일
	BLE_UUID_CHAR_EXACT_TIME_256                  = 0x2A0C, ///< 정밀 시간
	BLE_UUID_CHAR_BATTERY_LEVEL                   = 0x2A19, ///< 배터리 잔량 (0~100%)
	BLE_UUID_CHAR_TEMPERATURE_MEASUREMENT         = 0x2A1C, ///< 온도 측정값
	BLE_UUID_CHAR_SYSTEM_ID                       = 0x2A23, ///< 시스템 ID (MAC 주소 등)
	BLE_UUID_CHAR_MODEL_NUMBER_STRING             = 0x2A24, ///< 모델 번호 (문자열)
	BLE_UUID_CHAR_SERIAL_NUMBER_STRING            = 0x2A25, ///< 시리얼 번호 (문자열)
	BLE_UUID_CHAR_FIRMWARE_REVISION_STRING        = 0x2A26, ///< 펌웨어 버전 (문자열)
	BLE_UUID_CHAR_HARDWARE_REVISION_STRING        = 0x2A27, ///< 하드웨어 버전 (문자열)
	BLE_UUID_CHAR_SOFTWARE_REVISION_STRING        = 0x2A28, ///< 소프트웨어 버전 (문자열)
	BLE_UUID_CHAR_MANUFACTURER_NAME_STRING        = 0x2A29, ///< 제조사 이름 (문자열)
	BLE_UUID_CHAR_HEART_RATE_MEASUREMENT          = 0x2A37, ///< 심박수 측정값
	BLE_UUID_CHAR_BODY_SENSOR_LOCATION            = 0x2A38, ///< 심박 센서 위치
	BLE_UUID_CHAR_HEART_RATE_CONTROL_POINT        = 0x2A39, ///< 심박수 제어 포인트
	BLE_UUID_CHAR_TEMPERATURE                     = 0x2A6E, ///< 일반 온도
	BLE_UUID_CHAR_HUMIDITY                        = 0x2A6F  ///< 습도
};

#endif
