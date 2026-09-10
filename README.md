# yss OS (Yi Sun-Sin OS)

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-ARM%20Cortex--M-orange.svg)]()
[![Language](https://img.shields.io/badge/Language-C%2B%2B11-brightgreen.svg)]()

**yss OS** (*Yi Sun-Sin OS*) is a lightweight, high-performance C++ Real-Time Operating System (RTOS) engineered specifically for **ARM Cortex-M** microcontrollers. Developed by an active embedded firmware and hardware engineer, yss OS combines modern C++ object-oriented design with low-overhead kernel scheduling to deliver a robust platform for real-world production systems.

---

## 📖 What is yss OS? (The Story & Philosophy)

The name **yss** stands for the lowercase initials of **General Yi Sun-Sin** (이순신 장군님), one of history's most celebrated naval commanders. 

> *"While watching a historical documentary about General Yi Sun-Sin, I was inspired by how he overcame overwhelming odds and harsh circumstances to achieve brilliant victories. Much like Linux took its name from a person, I decided to name this OS after General Yi Sun-Sin, driven by the vision to build a competitive, world-class RTOS despite realistic development challenges."*

Initially shared simply as "yss OS", the project earned its full name **Yi Sun-Sin OS** after proven success in practical firmware deployment, demonstrating real-world reliability and performance.

---

## ✨ Key Features at a Glance

### 🧵 Hybrid Multitasking Kernel
- Preemptive/Cooperative **Threads** (`thread::add`, `thread::yield`, `thread::delay`, `thread::delayUs`) powered by `SysTick` & `PendSV`.
- Ultra-lightweight one-shot **Triggers** (`trigger::add`, `trigger::run`) — a unique yss OS concept for ISR-deferred processing that rebuilds the execution context on every call, allowing the function to always restart from the beginning.
- **Signal/WaitForSignal** mechanism for efficient thread synchronization with automatic CPU sleep (`__WFI`) when no threads are runnable.
- **Multi-core scheduling** support (`YSS__MULTI_CORE`) with hardware semaphore-based cross-core scheduling locks.

### 🔒 Thread Safety & Synchronization
- **Ticket-Lock Mutex** with fair FIFO ordering — all peripheral drivers inherit `Mutex` automatically via the `Drv` base class.
- **Mutex Watchdog** (`THREAD_WATCHDOG_ENABLE`) that detects deadlocks and invokes a user-defined handler.
- **Thread protect/unprotect** API to guard against unsafe `thread::remove()` during critical sections.
- IRQ-associated Mutex: `setIrq()` automatically disables the linked hardware interrupt while the lock is held.

### 💾 Multi-Tiered Memory Allocators
- `malloc()` for internal SRAM (default heap).
- `cmalloc()` for fast **CCM** (Core Coupled Memory) DATA RAM.
- `hmalloc()` for high-speed SRAM — used internally for scheduler stacks.
- `lmalloc()` for multi-megabyte external **SDRAM / HyperRAM** pools (FrameBuffers & graphics).
- Stack watermark pattern (`FILL_THREAD_STACK`) for high-water analysis.

### 🔌 Object-Oriented HAL & Peripheral Drivers
Unified C++ driver classes for 36+ peripheral types:

| Category | Peripherals |
|---|---|
| Communication | UART, USART, SPI, QSPI, I2C, I2S, PDM |
| Bus | CAN, CAN-FD, USB Device |
| Storage | SDMMC, SDRAM, HBI (HyperBus) |
| Analog | ADC, DAC |
| Motion | PWM, Timer, Capture, Quadrature Encoder |
| System | GPIO, EXTI, DMA, DMA2D, NVIC, CRC, Flash, Watchdog, RTC |
| Wireless | BLE 4.0 Radio |

### 📁 Integrated Subsystems
- **FAT32 File System** abstraction layer (Read-only).
- **TurtleShip** C++ embedded GUI framework with `FrameBuffer`, `Brush`, `Font`, `Button`, `Label`, `Container`, `DisplayPageManager`, and full RGB565/BGR565/RGB888 color support.
- **BLE 4.0** support via `Ble4p0` / `BleRadio` HAL abstraction.

---

## 🏗️ Architecture

```
┌────────────────────────────────────────────────┐
│            Application / BSP Layer              │
│     thread::, trigger::, mutex::, event::       │
├─────────────────────┬──────────────────────────┤
│   System Services   │       Middleware           │
│ scheduler, malloc   │  FAT32, TurtleShip GUI    │
├─────────────────────┴──────────────────────────┤
│               HAL Layer                         │
│   hal::Ble, hal::MassStorage, hal::Memory       │
├────────────────────────────────────────────────┤
│            Driver Layer (drv)                   │
│  Uart, Spi, I2c, Gpio, Timer, Adc, Can ...     │
│       (Drv base class → Mutex inherited)        │
├────────────────────────────────────────────────┤
│          MCU Target Implementation              │
│  nordic/  nuvoton/  analog_devices/  st/  ...  │
└────────────────────────────────────────────────┘
```

All peripheral drivers inherit from `Drv`, which inherits from `Mutex`. This means **every driver is automatically thread-safe** with `lock()` / `unlock()` — no manual synchronization wrappers needed.

---

## 🚀 Quick Start Example

```cpp
#include <yss.h>
#include <bsp.h>

// Each function runs as an independent RTOS thread
void thread_led1(void)
{
    while (1)
    {
        gpioA.setOutput(0, true);
        thread::delay(500);         // yields CPU to other threads
        gpioA.setOutput(0, false);
        thread::delay(500);
    }
}

// Trigger: one-shot deferred handler (e.g., from ISR context)
triggerId_t gTriggerTxLed;

void trigger_txLed(void)
{
    led::setLed1(true);
    thread::delay(20);
    led::setLed1(false);
}

int main(void)
{
    // 1. Initialize yss RTOS kernel
    initializeYss();

    // 2. Initialize board peripherals
    initializeBoard();

    // 3. Register threads and triggers
    thread::add(thread_led1, 512);
    gTriggerTxLed = trigger::add(trigger_txLed, 512);

    // 4. Idle loop
    while (1)
    {
        thread::yield();
    }
}
```

---

## 🖥️ Verified Hardware & Example Projects

The following real-world projects have been built and verified using yss OS:

| Board / Product | MCU | Verified Features |
|---|---|---|
| **nRF52840-DK** | Nordic nRF52840 | LED, UART, Timer (1kHz~100kHz), BLE 4.0 Advertising |
| **NuMaker-M251KG** | Nuvoton M251 | SPI TFT-LCD (ST7789V), GUI, Font rendering, MutexWatchdog |
| **GM100** | Nuvoton M4xx | QSPI LCD, I2C Touch (GT911), FRAM, CAN-FD, HyperRAM, SD Card |

---

## 🆚 yss OS vs. Arduino (C++)

| Feature | yss OS | Arduino |
|---|---|---|
| Execution Model | Preemptive RTOS (PendSV context switch) | Single loop (`setup()` + `loop()`) |
| Multitasking | Built-in (`thread::add`) | Not available by default |
| Thread Safety | Ticket-Lock Mutex, auto-lock per driver | None (single-thread assumed) |
| Timing Precision | µs-accurate real-time (SysTick) | `millis()` — vulnerable to ISR delays |
| C++ Usage | Inheritance, virtual functions, namespaces, strong-typed error codes | Global objects, minimal OOP |
| Error Handling | `error_t` enum (130+ codes) | Mostly silent failures |
| ISR Handling | `trigger::` one-shot deferred context | `attachInterrupt()` simple callback |
| GUI | TurtleShip framework (OS-level integration) | Third-party (Adafruit GFX, LVGL) |
| Multi-core | Built-in (`YSS__MULTI_CORE`) | Board-specific, experimental |

> **Positioning**: yss OS is not a replacement for Arduino — it is the next step. Arduino is ideal for rapid prototyping; yss OS is designed for production firmware where real-time guarantees, thread safety, and hardware control matter.

---

## 🛠️ Development Environment & IDE

yss OS is primarily developed and tested using **Rowley Crossworks for ARM** on **Ubuntu Linux**.

* **Recommended IDE**: [Rowley Crossworks for ARM](https://www.rowley.co.uk/arm/index.htm)
* **Why Crossworks for ARM?**
  1. Full C++ standard library support optimized for embedded microcontrollers.
  2. Native cross-platform support for Linux (Ubuntu).
  3. Professional-grade debugging, flashing, and toolchain features for production firmware.

---

## 🗺️ Roadmap

### Short-term
- [ ] Remove debug artifact (`if(id == 3) __NOP();` in scheduler)
- [ ] Fix typos in `error.h` (`ERROR_INTERRUP`, `NOT_HAVE_SPECIFICATON`)
- [ ] Add stack overflow detection (MPU guard or canary pattern)
- [ ] Unit test infrastructure for host-side simulation

### Mid-term
- [ ] Priority-based scheduling (alongside existing Round-Robin)
- [ ] FAT32 write support
- [ ] STM32H7 dual-core support
- [ ] PlatformIO integration

### Long-term
- [ ] POSIX-compatible thread API wrapper
- [ ] RISC-V porting exploration
- [ ] Package manager support (vcpkg / conan)

---

## 📚 Documentation & Wiki

For comprehensive technical guides, architecture deep-dives, API references, and subsystem tutorials, visit the project wiki:

🔗 **[yss RTOS GitHub Wiki](https://github.com/mymy49/yss/wiki)**

---

## 📜 License

This project is open-source and released under the [MIT License](LICENSE).

---

## 🤖 README Update Notice

This README was reviewed and updated on **2026-09-11** based on a comprehensive static analysis of the yss OS source code, scheduler implementation, driver architecture, and verified example projects.

The analysis covered:
- Core kernel internals (`yss_scheduler.cpp`, `yss_multi_core_scheduler.cpp`)
- Mutex / synchronization primitives (`Mutex.h`, `Drv.h`)
- All 36+ peripheral driver headers
- 18 MCU-family configuration files
- Real-world example projects: nRF52840-DK, NuMaker-M251KG, GM100

> *Reviewed and updated by **Claude Sonnet 4.6 (Thinking)** (Anthropic) via **Antigravity** (Google DeepMind) — 2026-09-11*
