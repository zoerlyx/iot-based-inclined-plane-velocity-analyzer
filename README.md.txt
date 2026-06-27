# Physics IoT: Inclined Plane Experiment

An IoT-based physics experiment system designed to measure and analyze motion and friction on an inclined plane using Arduino, ESP, ultrasonic sensors, and load cell technology.

## 📌 Overview

This project combines physics experiments with Internet of Things (IoT) technology to measure physical quantities in an inclined-plane experiment.

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
├── kecepatan-bidang-miring/
│   └── kecepatan-bidang-miring.ino
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

The project is developed as an experimental system for applying physics concepts to a real-world sensor-based measurement system.

## 👥 Contributors

* Fardho Z.

## 📄 License

This project is developed for educational and experimental purposes.
