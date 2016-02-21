#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *rearLeft = AFMS.getMotor(1);
Adafruit_DCMotor *rearRight = AFMS.getMotor(2);
Adafruit_DCMotor *frontLeft = AFMS.getMotor(3);
Adafruit_DCMotor *frontRight = AFMS.getMotor(4);
int currF = 0;
int currB = 0;
int voltage = 200;
String myString = "";

void setup() {
  AFMS.begin();
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  rearLeft->setSpeed(voltage);
  rearLeft->run(RELEASE);
  rearRight->setSpeed(voltage);
  rearRight->run(RELEASE);
  frontLeft->setSpeed(voltage);
  frontLeft->run(RELEASE);
  frontRight->setSpeed(voltage);
  frontRight->run(RELEASE);
}

void loop() {
  
  if (Serial.available() > 0) {
    delay(100);
    while (Serial.available() > 0) { myString += char(Serial.read()); }
  }

  if (myString.equals("FORWARD")) forward();
  else if (myString.equals("BACKWARD")) backward();
  else if (myString.equals("LEFT")) left();
  else if (myString.equals("RIGHT")) right();
  else if (myString.equals("STOP")) off();
  else if (myString.equals("FON")) {
    digitalWrite(2, HIGH);
    currF = 1;
  }
  else if (myString.equals("FOFF")) {
    digitalWrite(2, LOW);
    currF = 0;
  }
  else if (myString.equals("BON")) {
    digitalWrite(13, HIGH);
    currB = 1;
  }
  else if (myString.equals("BOFF")) {
    digitalWrite(13, LOW);
    currB = 0;
  }
  else if (myString.equals("HORN")) horn();
  myString = "";
  delay(3);
}

void forward() {
  rearLeft->setSpeed(voltage);
  rearLeft->run(BACKWARD);
  rearRight->setSpeed(voltage);
  rearRight->run(BACKWARD);
  frontLeft->setSpeed(voltage);
  frontLeft->run(FORWARD);
  frontRight->setSpeed(voltage);
  frontRight->run(FORWARD);
}

void backward() {
  rearLeft->setSpeed(voltage);
  rearLeft->run(FORWARD);
  rearRight->setSpeed(voltage);
  rearRight->run(FORWARD);
  frontLeft->setSpeed(voltage);
  frontLeft->run(BACKWARD);
  frontRight->setSpeed(voltage);
  frontRight->run(BACKWARD);
}

void left() {
  rearLeft->setSpeed(voltage);
  rearLeft->run(FORWARD);
  rearRight->setSpeed(voltage);
  rearRight->run(BACKWARD);
  frontLeft->setSpeed(voltage);
  frontLeft->run(BACKWARD);
  frontRight->setSpeed(voltage);
  frontRight->run(FORWARD);
}

void right() {
  rearLeft->setSpeed(voltage);
  rearLeft->run(BACKWARD);
  rearRight->setSpeed(voltage);
  rearRight->run(FORWARD);
  frontLeft->setSpeed(voltage);
  frontLeft->run(FORWARD);
  frontRight->setSpeed(voltage);
  frontRight->run(BACKWARD);
}

void off() {
  rearLeft->setSpeed(0);
  rearRight->setSpeed(0);
  frontLeft->setSpeed(0);
  frontRight->setSpeed(0);
  rearLeft->run(BACKWARD);
  rearRight->run(BACKWARD);
  frontLeft->run(FORWARD);
  frontRight->run(FORWARD);
}

void horn() {
  digitalWrite(2, 1 - currF);
  digitalWrite(13, 1 - currB);
  delay(125);
  digitalWrite(2, currF);
  digitalWrite(13, currB);
  delay(125);
  digitalWrite(2, 1 - currF);
  digitalWrite(13, 1 - currB);
  delay(125);
  digitalWrite(2, currF);
  digitalWrite(13, currB);
  delay(125);
  digitalWrite(2, 1 - currF);
  digitalWrite(13, 1 - currB);
  delay(125);
  digitalWrite(2, currF);
  digitalWrite(13, currB);
}

