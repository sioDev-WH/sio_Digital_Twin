# sio_Digital_Twin

The audience of this source code repository are developers of the new synaptics.io digital twin engine (*sio engine*). The current algorithms will be updated in order to support the new cloud-based synaptics.io executable model engines and new **hardware-in-the-loop (HIL)** *sio sensor and digital-twin modules*.



## Algorithms
The current source code is platform specific (Windows) and is targeting specific real-time UML and requirements tools. The algorithms do not support HIL, specifically the hybrid dynamics, real-time OS and communication networks are supported via simulation only (e.g., differential algebraic equations, graph algorithms, statecharts, real-time OS kernel, scheduler and synchronization primitives, ...). The algorithms will be extended to support HIL hardware and additional wireless communications protocols MQTT/CAN/MODBUS (e.g., *unisio*).

Specifically, the goals of algorithm migration are to:

1. Migrate the **simulation engine algorithms and tools**  to the cloud (AWS, Google and Azure) and to enable parallel processing.
2. Add support to new real-time software modeling environments (non-UML and new profiles)
3. Migrate the **automatic real-time code generation algorithms** to the cloud to support Hardware-in-the-Loop (HIL) on FPGA and MCU targets.
4. Add support for machine learning algorithms (with complexity-regularization) for monitorng and diagnosis of real-time hybrid dynamic systems and embedded software.

## Hardware

A separate repository is available for developing **hardware-in-the-loop (HIL) modules**, including:
* **Sensor and IO (Slave) modules** (e.g., *unisio* board) for generating high-precision low-noise signals (e.g., thermocouples, RTD, 4-20 mA, vibration accelerometer and proximity, mV, user-defined sensor). The repository for the current prototype, *unisio*, is available at https://github.com/VP-EngineerW/unisio_ExternalReviews and is based on Texas Instruments IOT **MCU** (Cortex-M4F-based simpleLink). The associated agile project portal is available at https://siodev.myjetbrains.com/youtrack/issues.

* **Digital-Twin Server (Master) modules** as targets of real-time digital twins with shared memory. Each digital twin hosts real-time algorithms for implementing physical models of a hybrid dynamic system and code-generated software.  example targets are **FPGA-based board**, e.g., Zynq/UltraScale which combine SoC and ARM processors).



