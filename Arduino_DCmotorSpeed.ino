int motorPin = 3;// Initialize pin3 to drive dc motor

void setup() {
  pinMode(motorPin, OUTPUT);//define motor pin as output
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
}

void loop() {
  if (Serial.available()) {
    int speed = Serial.parseInt(); // Parse the speed value to write on analog pin A0
    if (speed >= 0 && speed <= 255) {
      analogWrite(motorPin, speed);
      Serial.println(speed);
    }
  }
}
