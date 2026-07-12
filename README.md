# 🌿 Design and Development of an Intelligent Dual-Mode Solar-Wind Harvester with Rotating Solar Petals

## 📌 Project Overview

This project presents an intelligent hybrid renewable energy harvesting system that combines **solar and wind energy generation** into a single adaptive structure. Unlike conventional hybrid systems that require separate solar panels and wind turbines, this system uses **rotating solar petals** that automatically transform into wind turbine blades based on environmental conditions.

The system continuously monitors sunlight intensity and wind speed using sensors. An **ESP32 microcontroller** processes the sensor data and automatically switches between solar mode and wind mode to maximize energy generation. The generated energy is regulated, stored in a lithium-ion battery, and supplied to practical loads such as LED lighting and USB mobile charging. The project also incorporates **IoT-based monitoring** for real-time performance visualization through a web dashboard.

---

# 🚀 Features

- 🌞 Automatic Solar Mode Operation
- 🌬 Automatic Wind Mode Operation
- 🔄 Intelligent Mode Switching
- ⚡ Renewable Energy Harvesting
- 🔋 Lithium-Ion Battery Charging
- 📡 ESP32-based IoT Monitoring
- 📊 Firebase Cloud Integration
- 📱 Web Dashboard for Real-Time Monitoring
- 💡 LED Load Support
- 🔌 USB Mobile Charging

---

# ⚙️ Working Principle

### Solar Mode

- LDR sensors detect high sunlight intensity.
- Solar petals remain flat to maximize sunlight absorption.
- Solar panels generate DC power.
- Generated power is regulated through a DC-DC converter.
- Battery is charged while simultaneously powering connected loads.

### Wind Mode

- When sunlight decreases and sufficient wind is detected, the ESP32 activates servo motors.
- Solar petals transform into aerodynamic wind turbine blades.
- Wind rotates the turbine.
- Generator produces electrical energy.
- Power is rectified, regulated, stored in the battery, and supplied to loads.

---

# 🛠 Hardware Components

| Component | Purpose |
|-----------|----------|
| ESP32 | Main Controller |
| Solar Panel | Solar Energy Generation |
| Wind Generator | Wind Energy Generation |
| Servo Motors | Petal Transformation |
| LDR Sensor | Sunlight Detection |
| Anemometer | Wind Speed Measurement |
| Lithium-ion Battery | Energy Storage |
| Battery Management System (BMS) | Battery Protection |
| DC-DC Converter (MPPT) | Voltage Regulation |
| Voltage Sensors | Voltage Monitoring |
| Current Sensors | Current Monitoring |
| LED Module | Load |
| USB Charging Module | Mobile Charging |

---

# 💻 Software Used

- Arduino IDE
- Embedded C/C++
- ESP32 Libraries
- Firebase Realtime Database
- HTML
- CSS
- JavaScript
- React.js

---

# 📡 IoT Features

- Real-time Voltage Monitoring
- Current Monitoring
- Battery Percentage
- Solar/Wind Mode Status
- Firebase Cloud Synchronization
- Live Dashboard

---

# 📂 Repository Structure

```
Hybrid-Solar-Wind-Harvester
│
├── README.md
├── Project_Report.pdf
├── Presentation.pptx
├── Circuit_Diagram.pdf
├── Block_Diagram.png
├── Flowchart.png
│
├── Arduino_Code/
│   └── main.ino
│
├── Images/
│   ├── Prototype.jpg
│   ├── Working.jpg
│   └── Final_Model.jpg
│
├── CAD/
│   ├── Assembly.png
│   ├── Front_View.png
│   └── Rotor_Hub.png
│
├── PCB/
│
└── Components_List.xlsx
```

---

# 🔄 System Workflow

```
Sunlight + Wind
        │
        ▼
Environmental Sensors
(LDR + Anemometer)
        │
        ▼
ESP32 Controller
        │
        ▼
Automatic Mode Selection
        │
 ┌───────────────┐
 │               │
 ▼               ▼
Solar Mode    Wind Mode
 │               │
 ▼               ▼
Solar Panel   Wind Generator
 │               │
 └──────┬────────┘
        ▼
 DC-DC Converter (MPPT)
        ▼
 Lithium-ion Battery
        ▼
 LED Load / USB Charging
        ▼
 Firebase Cloud
        ▼
 Web Dashboard
```

---

# 📊 Expected Results

- Automatic switching between solar and wind modes.
- Continuous renewable energy generation.
- Improved energy harvesting efficiency.
- Reduced installation space.
- Lower hardware redundancy.
- Real-time cloud monitoring.
- Reliable battery charging.
- Efficient power management.

---

# 🎯 Applications

- Smart Cities
- Rural Electrification
- IoT Devices
- Off-Grid Power Systems
- Disaster Relief Systems
- Smart Agriculture
- Remote Monitoring Stations
- Sustainable Energy Solutions

---

# 🔮 Future Scope

- AI-based energy prediction.
- Machine Learning for intelligent mode switching.
- Grid-connected operation.
- Higher-capacity battery storage.
- Mobile application integration.
- Commercial-scale implementation.

---

# 👩‍💻 Team Members

- Anitha
- Chithra B
- Rakshita Gulshansing Thakur
- **Rakshitha M P**

**Guide:** Mrs. Anusha D Y  
Department of Electrical and Electronics Engineering  
SJBIT, Bengaluru

---

# 📚 References

- IEEE Research Papers on Hybrid Renewable Energy Systems
- ESP32 Documentation
- Firebase Documentation
- Texas Instruments Power Management Documentation

---

# ⭐ Acknowledgement

This project was developed as part of the Bachelor of Engineering (Electrical and Electronics Engineering) major project at **SJB Institute of Technology (SJBIT), Bengaluru**. It aims to contribute toward sustainable and intelligent renewable energy harvesting through innovative adaptive system design.

---

## 📜 License

This project is intended for educational and research purposes.

---

⭐ **If you found this project useful, consider giving it a Star on GitHub!**
