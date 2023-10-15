#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Motor A connections
int enA = 10;// Initialize pin 10 for Enable pin
int in1 = 8; // Initialize pin 8 for Input1
int in2 = 9;// Initialize pin 9 for Input1
int i;
void setup() {

  Serial.begin(9600);
  Serial.println(" DC Motor simulation");
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  //Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  lcd.begin(16, 2);
  // clear old screen data
  lcd.clear();
  // text to be displayed on the screen
  lcd.print(" MICRODIGISOFT ");
  delay(2000);
}

void loop() {
  //directionControl();
  //delay(1000);

  int speed = map(analogRead(A0), 0, 1024, 0, 255);
  analogWrite (enA, speed);
  lcd.begin(16, 2);
  // clear old screen data
  lcd.clear();
  // text to be displayed on the screen
  lcd.print("DC MOTOR SPEED ");
  delay(1000);
  speedControl();
  delay(1000);
}

void speedControl() {
  // Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  int speed = lcd.print("");
  // Accelerate from zero to maximum speed
  for (i = 0; i < 255; i++) {
    analogWrite(enA, i);
    lcd.clear();
    lcd.print("DC MOTOR SPEED ");
    lcd.setCursor(4, 2);
    lcd.print("Speed=");
    lcd.print(i);
    delay(200);
  }

  // Decelerate from maximum speed to zero
  for ( i = 255; i >= 0; --i) {
    analogWrite(enA, i);
    lcd.clear();
    lcd.print("DC MOTOR SPEED ");
    lcd.setCursor(4, 2);
    lcd.print("Speed=");
    lcd.print(i);
    delay(200);
  }

  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

}
