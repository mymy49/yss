# yss OS
이 프로젝트는 ARM Cortex-M 계열을 사용하는 MCU에서 사용할 수 있는 RealTime OS 입니다. 저는 현재 회사에 근무하면서 실무로 펌웨어와 하드웨어 개발을 주 업무로 하고 있습니다. 개인 시간에 틈틈히 이 프로젝트를 진행하고 있습니다.

This project is a RealTime OS that can be used on MCUs using the ARM Cortex-M series. I am currently working at a company and my main job is firmware and hardware development. I am working on this project in my free time.

# yss는? (What about yss?)
yss는 이순신(Yi Sun-Sin) 장군님의 이니셜의 소문자 입니다. 

yss is the lowercase initials of General Yi Sun-Sin.

OS의 이름을 결정할 당시 이순신 장군님의 활약상을 다룬 TV 다큐멘터리를 보다가 저에게 주어진 현실적 어려움에도
멋지게 외국의 다른 멋진 OS들과 대적할 수 있는 OS를 만들고 싶다는 생각과 리눅스 OS가 사람의 이름을 사용한 OS이기 때문에
사람의 이름을 따더라도 특별히 문제가 없을 것이라고 생각해서 결정했습니다.

When deciding on the name of the OS, I watched a TV documentary about the exploits of General Yi Sun-Sin and, despite the realistic difficulties I was given, I wanted to create an OS that could compete with other great foreign OSs. Also, since the Linux OS is an OS that uses people's names, I thought that there would be no particular problem with using people's names, so I decided to do so.

처음은 yss OS라는 이름만 오픈 했습니다. OS를 실무에 적용해보고 이거 좀 뭔가 진짜 가능성이 보이고 어디 내놔도 부끄럽지 않다는
생각이 들기 시작했을 때, 이순신 OS라고 전체 이름을 밝히기 시작했습니다.

At first, I only opened the name yss OS. When I started applying the OS to practical work and started to think that it had some real potential and that I wouldn't be ashamed to show it anywhere, I started revealing the full name as Yi Sun-Sin OS.

이순신 OS의 영문 표기는 소문자 yss를 사용합니다.

The English spelling of Yi Sun-Sin OS uses lowercase yss.

# 현재 진행 상황
과거에는 생각했던 기능이 과연 내가 구현이 가능할까?의 궁금함 때문에 지저분해도 생각나는대로 기능을 덕지덕지 붙여보는데 주력해왔습니다.

In the past, I focused on adding functions as I thought about them, even if they were messy, because I was curious about whether I could actually implement the functions I had in mind.

그러나 얼마 전부터는 코드 정리에 주력하고 있습니다. 물론 필요에 의해 기능은 추가되고 있습니다. 

However, recently, I have been focusing on organizing the code. Of course, functions are being added as needed.

# IDE
사용하는 IDE는 Crossworks for ARM으로 유료 제품입니다. yss OS는 Crossworks for ARM 사용을 권장합니다. 아래 사이트에서 구매와 다운로드가 가능합니다.

The IDE used is Crossworks for ARM, a paid product. We recommend using Crossworks for ARM for yss OS. You can purchase and download it from the site below.

[https://www.rowley.co.uk/arm/index.htm](https://www.rowley.co.uk/arm/index.htm)

제가 Crossworks for ARM을 사용하는 이유는 아래와 같습니다.
The reasons I use Crossworks for ARM are as follows.

 * 이 프로젝트를 처음 시작했던 당시에 Crossworks for ARM을 제외하고 C++을 완벽히 지원하는 IDE가 없었습니다.
	* when I first started this project, there were no IDEs that fully supported C++ other than Crossworks for ARM.
 * 제 PC의 Host OS는 우분투 리눅스를 사용하고 있습니다. Crossworks for ARM은 리눅스를 완벽하게 지원합니다.
	* My PC's host OS is Ubuntu Linux. Crossworks for ARM fully supports Linux.
 * 펌웨어 개발에 완벽한 환경을 제공해주고 있습니다.
 	* It provides a perfect environment for firmware development.
