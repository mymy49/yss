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

* **Hybrid Multitasking Kernel**: 
  * Preemptive/Cooperative **Threads** (`thread::add`, `thread::yield`, `thread::delay`) powered by `SysTick` & `PendSV`.
  * Ultra-lightweight event **Triggers** (`trigger::add`, `trigger::run`) for fast, low-overhead ISR and event handling.
* **Multi-Tiered Memory Allocators**:
  * Default `malloc()` for internal SRAM.
  * `cmalloc()` for fast CCM (Core Coupled Memory) DATA RAM.
  * `hmalloc()` for high-speed SRAM buffers.
  * `lmalloc()` for multi-megabyte external SDRAM/HyperRAM pools (FrameBuffers & graphics).
* **Object-Oriented HAL & Peripheral Drivers**:
  * Unified C++ drivers for UART, USART, SPI, QSPI, I2C, CAN, CAN-FD, SDMMC, PWM, ADC/DAC, DMA, DMA2D, and Timer peripherals.
* **Integrated Storage & Subsystems**:
  * Embedded **FAT32 File System** abstraction layer (*Read-only supported*).
  * Seamless pairing with the **TurtleShip** C++ embedded GUI framework.

---

## 🚀 Quick Start Example

```cpp
#include <yss.h>
#include <bsp.h>

void workerThread(void *param)
{
    while (1)
    {
        // Thread work logic
        thread::delay(100); // Sleep for 100ms
    }
}

int main(void)
{
    // 1. Initialize yss RTOS Kernel
    initializeYss();

    // 2. Initialize Board Peripherals
    initializeBoard();

    // 3. Create a Worker Thread (Stack size: 1024 bytes)
    thread::add(workerThread, nullptr, 1024);

    // 4. Main Thread Loop
    while (1)
    {
        thread::yield();
    }
}
```

---

## 🛠️ Development Environment & IDE

yss OS is primarily developed and tested using **Rowley Crossworks for ARM** on **Ubuntu Linux**.

* **Recommended IDE**: [Rowley Crossworks for ARM](https://www.rowley.co.uk/arm/index.htm)
* **Why Crossworks for ARM?**
  1. Full C++ standard library support optimized for embedded microcontrollers.
  2. Native cross-platform support for Linux (Ubuntu).
  3. Professional-grade debugging, flashing, and toolchain features for production firmware.

---

## 📚 Documentation & Wiki

For comprehensive technical guides, architecture deep-dives, API references, and subsystem tutorials, visit the project wiki:

🔗 **[yss RTOS GitHub Wiki](https://github.com/mymy49/yss/wiki)**

---

## 📜 License

This project is open-source and released under the [MIT License](LICENSE).
