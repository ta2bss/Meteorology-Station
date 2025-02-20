# Meteorology Station with Arduino

## Overview
This project is a **weather monitoring station** using **Arduino Uno** with the following sensors:
- **BME280**: Temperature, Pressure, Humidity (I2C)
- **PR-3000-FSJT-N01**: Wind Speed Sensor (RS485)
- **ZTS-3000-FXJT-N01**: Wind Direction Sensor (RS485)

## Features
- Measures **temperature, humidity, and atmospheric pressure**.
- Detects **wind speed and direction** using RS485 communication.
- Data can be processed and logged for analysis.

## Hardware Components
| Component | Description |
|-----------|------------|
| **Arduino Uno** | Microcontroller Board |
| **BME280** | Temp, Humidity & Pressure Sensor |
| **PR-3000-FSJT-N01** | RS485 Wind Speed Sensor |
| **ZTS-3000-FXJT-N01** | RS485 Wind Direction Sensor |
| **MAX485** | RS485 to TTL Converter (x2)|
| **12V Power Supply** | Powering the Sensors |

## Wiring Diagram
The connection diagram is available.

### **Wind Speed & Wind Direction Sensors (RS485)**
- **VCC** → **12V DC** (10-30 V DC)
- **GND** → **Ground**
- **A** → **RS485 Converter A**
- **B** → **RS485 Converter B**

### **RS485 to TTL Converter → Arduino**
| RS485 Converter | Arduino Pin |
|-----------------|------------|
| **VCC** | 5V |
| **GND** | GND |
| **DI** | TX (3 for Speed, 5 for Direction) |
| **RO** | RX (2 for Speed, 4 for Direction) |
| **DE** | Pin 7 (Speed), Pin 9 (Direction) |
| **RE** | Pin 8 (Speed), Pin 10 (Direction) |

### **BME280 Sensor (I2C)**
| BME280 | Arduino Pin |
|--------|------------|
| **VCC** | 3.3V |
| **GND** | GND |
| **SCL** | A5 |
| **SDA** | A4 |

## Installation
1. **Install Required Libraries**:
   - `Adafruit_BME280.h`
   - `Wire.h`
   - `SoftwareSerial.h`
2. **Upload the Arduino Code** (`Arduino-Code/spd_dir_temp_hum_pres_v2.ino`).

## Usage
**Monitor the serial output** in the Arduino IDE.


## License
This project is licensed under the **MIT License**.

## Contributing
Feel free to fork this repository and submit pull requests for improvements.

## Author
- **TA2BSS**
