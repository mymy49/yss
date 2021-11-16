# yss os

이순신 OS 프로젝트 입니다.

이 프로젝트는 ARM Cortex-M 계열을 사용하는 MCU에서 사용하는 OS를 개발하고 있습니다. 주로 출퇴근하는 지하철과 주말에 틈틈히 작업을 하는 관계로 코딩하는 시간도 부족하여 아직 문서가 없습니다. 사용 방법에 관해서는 등록된 예제 코드를 참고해주시기 바랍니다.

현재 STM32 제품을 이용한 상용 제품 개발이 진행되었고, ATSAM 시리즈에 포팅을 진행하고 있습니다. 그외에 많은 제품에 적용할 계획입니다.

사용자 설명서는 아래 주소를 참고해주시기 바랍니다.
https://cafe.naver.com/yssoperatingsystem/433

현재 포팅된 MCU의 정보는 아래 사이트를 참고해주시기 바랍니다.
https://cafe.naver.com/yssoperatingsystem/384

사용하는 IDE는 Crossworks for ARM으로 아래 사이트에서 다운 받으실 수 있습니다.
https://www.rowley.co.uk/arm/index.htm

Crossworks for ARM의 한달 체험판 신청은 아래 영상을 참고해주시기 바립니다.
https://cafe.naver.com/yssoperatingsystem/48

홈페이지는 아래와 같습니다.
https://cafe.naver.com/yssoperatingsystem

# 폴더 구성
- yss : yss os의 소스 코드가 들어 있는 폴더 입니다.
- 그외 폴더들 : 해당 폴더 명의 MCU를 사용한 예제 프로젝트 입니다. 해당 폴더에 들어가면 해당 MCU를 사용한 보드 이름의 폴더가 나오고 그 안에 예제 프로젝트가 있습니다.
