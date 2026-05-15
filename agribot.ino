#include <ESP32Servo.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

Servo soilServo;
Servo seedServo;

// Pins
const int soilServoPin = 19;
const int seedServoPin = 22;
const int moisturePin = 23;
const int irrigateRelayPin = 21;
const int weedRelayPin = 5;

const int moistureThreshold = 500;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Agribot");

  soilServo.attach(soilServoPin);
  seedServo.attach(seedServoPin);

  pinMode(irrigateRelayPin, OUTPUT);
  pinMode(weedRelayPin, OUTPUT);

  digitalWrite(irrigateRelayPin, HIGH);
  digitalWrite(weedRelayPin, HIGH);

  Serial.println("Agribot Bluetooth Ready...");
}

void loop() {

  if (SerialBT.available()) {
    char cmd = SerialBT.read();
    Serial.println(cmd);

    switch (cmd) {

      case 'D':
        soilServo.write(90);
        break;

      case 'U':
        soilServo.write(0);
        break;

      case 'I':
        digitalWrite(irrigateRelayPin, LOW);
        break;

      case 'S':
        digitalWrite(irrigateRelayPin, HIGH);
        break;

      case 'W':
        digitalWrite(weedRelayPin, LOW);
        break;

      case 'Q':
        digitalWrite(weedRelayPin, HIGH);
        break;

      case 'X':
        for (int i = 0; i < 3; i++) {
          seedServo.write(60);
          delay(500);
          seedServo.write(0);
          delay(500);
        }
        break;

      case 'Y':
        seedServo.write(0);
        break;
    }
  }
}
