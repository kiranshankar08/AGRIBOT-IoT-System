# Agribot Bluetooth System

##  Overview
Agribot is an ESP32-based smart agriculture robot controlled via Bluetooth. It performs basic farming automation tasks like irrigation, seed dispensing, soil sensing, and weed cutting.

## Features
-  Bluetooth control via mobile app
-  Soil sensor movement
-  Smart irrigation control
-  Seed dispensing mechanism
-  Weed cutting motor control


##  Hardware Used
- ESP32
- Servo motors
- Relay module
- Soil moisture sensor
- DC water pump
- Weed cutting motor


##  Bluetooth Commands

| Command | Function |
|--------|----------|
| D | Soil sensor down |
| U | Soil sensor up |
| I | Irrigation ON |
| S | Irrigation OFF |
| X | Seed dispensing |
| Y | Reset seed system |
| W | Weed cutting ON |
| Q | Weed cutting OFF |


##  How It Works
Mobile Bluetooth app sends commands → ESP32 receives → actuators respond.


##  Future Improvements
- WiFi / WhatsApp control version
- Automatic irrigation using soil data
- Mobile app UI


##  Author
Kiran – GitHub: https://github.com/kiranshankar08
