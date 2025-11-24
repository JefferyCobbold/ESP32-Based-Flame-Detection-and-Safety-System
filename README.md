#  ESP32-Based Flame Detection and Safety System

##  Overview
This project implements a low-cost automated fire-detection and safety-response system using an ESP32. It integrates a flame sensor, relay-controlled water pump, buzzer, and an I2C LCD display to provide real-time alerts and suppression when fire is detected.

---

##  Objectives
- Detect flame presence using an IR-based flame sensor.  
- Automatically activate a water pump via a relay.  
- Trigger an audible alarm during fire detection.  
- Display status updates on a 16×2 I2C LCD module.  

---

##  Components

| Component | Function |
|----------|----------|
| **ESP32** | Main controller |
| **Flame Sensor (IR)** | Detects flame (active LOW) |
| **Relay Module** | Switches water pump |
| **Buzzer** | Audible alarm |
| **16×2 LCD (I2C)** | System status display |
| **Wires & PSU** | Connections & power |

---

##  Circuit Connections

| Module | ESP32 Pin |
|--------|-----------|
| Flame Sensor | GPIO 23 |
| Relay Module | GPIO 22 |
| Buzzer | GPIO 18 |
| LCD SDA | GPIO 19 |
| LCD SCL | GPIO 21 |

---

![Fire_detection_suppression_system_bb](https://github.com/user-attachments/assets/c7ddc974-8fb6-404d-8d74-d93a3b099f61)

## Working Principle
1. The flame sensor continuously monitors for fire.  
2. **No flame detected** → Pump OFF, Buzzer OFF, LCD shows:  
   **"No Flame Found | Pump OFF"**  
3. **Flame detected (LOW)** →  
   - Relay ON → Water pump activated  
   - Buzzer ON  
   - LCD shows: **"Flame Detected! | Pumping Water"**  
4. System updates every 500 ms.

---

##  Code Summary
- Uses `Wire.h` and `LiquidCrystal_I2C.h`.  
- Pins:  
  - `FLAME_SENSOR_PIN = 23`  
  - `RELAY_PIN = 22`  
  - `BUZZER_PIN = 18`  
- `setup()` initializes I2C, LCD, and GPIOs.  
- `loop()` reads the sensor and activates or deactivates outputs based on whether a flame is detected.

---

##  Installation & Setup
1. Install **Arduino IDE** or **PlatformIO**.  
2. Install required library:  
   - `LiquidCrystal_I2C`  
3. Select **ESP32 Dev Module** from the board manager.  
4. Upload the code to the ESP32.  
5. Connect all components as described.

---

## Applications
- Home and office fire-safety systems  
- Industrial fire-suppression units  
- Laboratory fire prevention  
- IoT-based fire alert systems  

---

##  Advantages
- Low-cost automated fire-safety solution  
- Fast detection with visual and audible alerts  
- Easy expansion with Wi-Fi, SMS, or cloud integration  

---

##  Limitations
- IR flame sensors may produce false readings in strong sunlight  
- Pump requires a separate power source  
- Does not detect smoke without additional sensors  

---

## Demonstration Video

A short video showing the complete operation of the ESP32 flame detection and safety system has been included in this repository. It demonstrates the system detecting a flame, activating the relay-controlled water pump, sounding the buzzer, and updating the LCD display in real time.

Due to the lab setting a IR sensor was used in placed of the flame sensor

https://github.com/user-attachments/assets/b1256bce-ad25-483c-9a02-b28b90131395



##  Future Improvements
- Wi-Fi or SMS fire notifications  
- Cloud monitoring dashboard  
- Integration of smoke or temperature sensors  
- Battery backup system  

---
