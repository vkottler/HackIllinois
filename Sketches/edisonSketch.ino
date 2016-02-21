#include <Wire.h>
#include <genieArduino.h>

#include "rgb_lcd.h"

Genie genie;

int LED = 4;
int fan = 11;
int speaker = 3;
int fanVal = 0;
String flight = "OFF";
String blight = "OFF";
String motor = "OFF";

rgb_lcd lcd;
String myString = "";

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(speaker, OUTPUT);
  digitalWrite(fan, LOW);
  Serial1.begin(9600);
  genie.Begin(Serial1);
  lcd.begin(16, 2);
  lcd.setRGB(255, 255, 255);
  showIntro();
}

void loop() {
  if (Serial1.available() > 0) {
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
    while (Serial1.available() > 0) { myString += char(Serial1.read()); }
  }
  if (myString.equals("FORWARD")) motor = "FOR";
  else if (myString.equals("BACKWARD")) motor = "REV";
  else if (myString.equals("LEFT")) motor = "L  ";
  else if (myString.equals("RIGHT")) motor = "R  ";
  else if (myString.equals("STOP")) motor = "OFF";
  else if (myString.equals("FON")) flight = "ON ";
  else if (myString.equals("FOFF")) flight = "OFF";
  else if (myString.equals("INTRO")) showIntro();
  else if (myString.equals("FAON")) {
    digitalWrite(fan, HIGH);
    fanVal = 1;
  }
  else if (myString.equals("FAOFF")) {
    digitalWrite(fan, LOW);
    fanVal = 0;
  }
  else if (myString.equals("BON")) blight = "ON ";
  else if (myString.equals("BOFF")) blight = "OFF";
  else if (myString.equals("HORN")) {
    tone(speaker, 262, 1500);
    lcd.clear();
    for (int i = 0; i < 10; i++) {
      lcd.setCursor(0, 0);
      lcd.print("HORN!!!");
      delay(100);
      lcd.clear();
      delay(50);
    }
  }
  //else if (myString.charAt(0) == 'X') {
  //  fanVal = myString.substring(1).toInt();
  //  analogWrite(fan, fanVal);
  //}
  myString = "";
  showStats();
  delay(3);
}

void showIntro() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("JonCooperVaughn Presents:");
  delay(1000);
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayRight();
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Presents:");
  for (int i = 0; i < 16; i++) {
    lcd.setCursor(0, 1);
    lcd.print("WiFi RC Car!");
    delay(100);
    lcd.setCursor(0, 1);
    lcd.print("             ");
    delay(50);
  }
  lcd.setCursor(0, 1);
  lcd.print("WiFi RC Car!");
  delay(2000);
}

void showStats() {
  lcd.setCursor(0, 0);
  lcd.print("HL: ");
  lcd.print(flight);
  lcd.print("  ");
  lcd.print("BL: ");
  lcd.print(blight);
  lcd.setCursor(0, 1);
  lcd.print("Motor: ");
  lcd.print(motor);
  lcd.print(" F: ");
  lcd.print(fanVal);
}

