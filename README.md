# 📌 Spiromed - Open-Source Spirometer

## 📖 Overview
Spiromed is an open-source **spirometer** designed to measure lung function. It consists of a **mobile application** and **embedded hardware** for real-time data acquisition and visualization. The system is developed using **MIT App Inventor** for the mobile interface and **Arduino** for sensor integration.

## ✨ Features
- 📱 **Android App** – A user-friendly interface developed in **MIT App Inventor**.
- 📊 **Real-Time Data Visualization** – View lung function parameters instantly.
- 🔬 **Embedded Firmware** – Arduino-based code for sensor data processing.
- 🔄 **Wireless Communication** – Connects via Bluetooth for seamless data transfer.

## 🛠 Project Structure
```
📂 Spiromed
├── 📱 Espirometro.aia     # MIT App Inventor project file
├── 🤖 Espirometro1.0.2.apk # Compiled Android application
├── 🖼 blocks.png          # Diagram of App Inventor blocks
├── 🔧 espirometro.ino     # Arduino firmware
```

## 📲 Installation & Usage
### 🔹 Android App
1. Download the latest **Espirometro1.0.2.apk**.
2. Install the APK on your Android device.
3. Open the app and pair it with the spirometer via Bluetooth.

### 🔹 Hardware Setup
1. Load the **espirometro.ino** firmware onto an **Arduino**.
2. Connect the required sensors and Bluetooth module.
3. Power on the device and ensure proper communication with the app.

## 🔬 How It Works
- **Venturi tube & pressure sensors** collect airflow data.
- **Arduino processes sensor readings** and transmits values via Bluetooth.
- **Mobile app** receives, processes, and displays results in real time.

## 📜 License
This project is open-source and available under the **MIT License**.

## 🙌 Contributors
Developed by **Bruno Castanho** and contributors.

---
📌 **GitHub Repository:** [github.com/brunovmcastanho/Spiromed](https://github.com/brunovmcastanho/Spiromed)

