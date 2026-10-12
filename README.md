# 🩺 Non-Invasive Blood Parameter Monitoring

## 📌 Project Overview
This project explores non-invasive monitoring of selected health parameters using Arduino and sensors, without extracting blood from the body.

The prototype uses a MAX30102-compatible pulse oximeter sensor to read optical signals and an analog pressure sensor to collect pressure-related readings.

## 🎯 Objectives
- Explore non-invasive health monitoring.
- Read infrared (IR) and red-light sensor values.
- Demonstrate heart rate and SpO₂ monitoring concepts.
- Collect analog pressure sensor readings.
- Display readings through the Arduino Serial Monitor.

## 🛠️ Components Required
- Arduino board
- MAX30102 pulse oximeter sensor module
- Analog pressure sensor
- Jumper wires
- Breadboard
- USB cable

## 💻 Technologies Used
- Arduino C/C++
- Arduino IDE
- I²C communication
- MAX30105 sensor library
- Wire library

## ⚙️ Working Principle
1. The MAX30102-compatible sensor reads red and infrared optical signals.
2. The Arduino retrieves the sensor readings through I²C communication.
3. An analog pressure sensor provides a reading through analog pin A0.
4. The Arduino displays the collected values in the Serial Monitor.

## ⚠️ Current Limitations
- The heart rate and SpO₂ functions currently return placeholder values, not calculated measurements.
- The blood pressure values are also placeholders and are not derived from a validated blood pressure measurement method.
- The pressure conversion shown in the code is an example mapping and requires sensor-specific calibration.
- The prototype is for educational and research purposes only, not for medical diagnosis or treatment.

## 🚀 Future Improvements
- Implement a validated heart rate calculation algorithm.
- Add an appropriate SpO₂ estimation algorithm and calibration.
- Develop and validate a suitable non-invasive blood pressure measurement method.
- Improve sensor calibration, signal processing, and measurement reliability.
- Add a display or data-logging feature.

## 📂 How to Run
1. Install the Arduino IDE.
2. Install a compatible MAX30105 library through Library Manager.
3. Connect the sensors according to their module specifications.
4. Open the Arduino sketch.
5. Select the correct board and COM port.
6. Upload the program and open Serial Monitor at **9600 baud**.

## 📄 Disclaimer
This project is an educational prototype. Its current output is not clinically validated and must not be used to make medical decisions.

## 👨‍💻 Project Type
Arduino | Embedded Systems | Non-Invasive Health Monitoring
