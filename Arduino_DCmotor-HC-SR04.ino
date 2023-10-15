// controlling dc motor with ultrasonic sensor
int trig = D5;// Initialize pin D5 as HC-SR04 trigger pin
int echo = D4;// Initialize pin D5 as HC-SR04 Echo pin
int motorPin1 = D10; //Initialize pin D10 to drive motor1
int motorPin2 = D11;//Initialize pin D11 to drive motor1
int led1 = D3;//green led
int led2 = D12;// red led
int duration = 0;
int distance = 0;
void setup()
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2 , OUTPUT);
  pinMode(motorPin1 , OUTPUT);
  pinMode(motorPin2 , OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);

  duration = pulseIn(echo , HIGH);
  distance = (duration / 2) / 28.5 ;// calculate distance in CM
  //Serial.println(distance);

  if ( distance < 20 ) {
    Serial.print(distance);

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2 , LOW);
    digitalWrite(led1 , HIGH);
    digitalWrite(led2 , LOW);
    Serial.println("cm   MOTOR STOP");
    delay(1000);
  }
  else {
    Serial.print(distance);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2 , LOW);
    digitalWrite(led1 , LOW);
    digitalWrite(led2 , HIGH);
    Serial.println("cm   MOTOR START");
    delay(1000);
  }
}
}
