# Physics IoT: Inclined Plane Measurement System

An IoT-based measurement system designed to measure and analyze motion, acceleration, and friction on an inclined plane using Arduino, ESP, ultrasonic sensors, and load cell technology.

## 📌 Overview

This system combines inclined-plane mechanics with Internet of Things (IoT) technology to deliver precise, real-time measurements of physical quantities for professional and educational instrumentation.
The system is designed to calculate:

* Velocity
* Acceleration
* Friction force

The measurement system uses sensors to collect real-time data from the moving object and the inclined plane.

## ⚙️ Features

* Measure the velocity of an object on an inclined plane
* Calculate the acceleration of the object
* Measure force using a load cell and HX711 module
* Calculate friction force
* Detect object distance and movement using an ultrasonic sensor
* Display measurement results using an LCD
* Use Arduino and ESP-based components for the IoT system

## 🧰 Hardware

The project may use the following hardware components:

* Arduino
* ESP module
* Ultrasonic sensor
* Load Cell
* HX711 Load Cell Amplifier
* LCD with I2C interface
* Inclined plane experiment setup
* Jumper wires and supporting electronic components

## 💻 Software and Libraries

* Arduino IDE
* Arduino C/C++
* HX711 Library
* LiquidCrystal I2C Library

## 📁 Project Structure

```text
.
├── src/
│   └── KecepatanBidangMiring1.ino
│
├── libraries/
│   ├── HX711/
│   └── LiquidCrystal_I2C/
│
└── README.md
```

## 🔬 Physics Concepts

This project applies several physics concepts, including:

* Motion and velocity
* Acceleration
* Newton's laws of motion
* Normal force
* Friction force
* Inclined-plane mechanics

For an inclined-plane experiment, the system can use measured motion and force data to analyze the physical behavior of an object moving along the plane.

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/zoerlyx/iot-based-inclined-plane-velocity-analyzer
```

### 2. Open the Arduino Project

Open the `.ino` file located in:

```text
cd iot-based-inclined-plane-velocity-analyzer/

cd src
```

using the Arduino IDE.

### 3. Install or Configure the Required Libraries

Make sure the required libraries are available in the Arduino environment, including:

* HX711
* LiquidCrystal I2C

### 4. Configure the Hardware

Connect the Arduino, ESP, ultrasonic sensor, load cell, HX711 module, and LCD according to the circuit configuration used in the project.

### 5. Upload the Program

Select the correct:

* Board
* Port
* Processor configuration, if required

Then upload the program to the microcontroller.

## 📊 Measurement Output

The system is intended to process sensor data and provide measurements related to:

* Distance
* Time
* Velocity
* Acceleration
* Force
* Friction

The exact calculation and output depend on the hardware configuration and the implementation in the Arduino program.

## 🎯 Project Goals

This project aims to demonstrate the integration of:

> Physics + Embedded Systems + IoT + Sensor Data

The system is developed as a reliable sensor-based solution for real-world physics measurement and telemetry application.

## 👥 Contributors

* Fardho Z.

## 📄 License

Proprietary / Developed for Client Project.