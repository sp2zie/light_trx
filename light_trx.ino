// Arduino Nano firmware for light TRX
// Author: Piotr Macuk <piotr@macuk.pl>

#include <Servo.h>

Servo servo;

int servoPin = 10;      // servo signal pin
int servoRxPos = 0;     // position for RX
int servoTxPos = 95;   // position for TX
int txPin = 9;          // TX pin -- should be pulled-down to GND with 10k resistor

void setup() {
  servo.attach(servoPin);
  pinMode(txPin, INPUT);
}

void loop() {
  if (digitalRead(txPin) == HIGH) {
    servo.write(servoTxPos);
  } else {
    servo.write(servoRxPos);
  }
}
