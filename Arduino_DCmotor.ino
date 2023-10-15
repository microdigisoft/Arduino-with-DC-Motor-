#define motor_pin 3 // intialise pin3 ti drive the DC motor
#define led_pin 11 // Initialize the pin 11 for LED
void setup() { //setup function
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(" DC Motor controller");

  pinMode(motor_pin, OUTPUT);//define motor pin as output
  pinMode(led_pin, OUTPUT);//define led pin as output
}

void loop() { //loop function
  // put your main code here, to run repeatedly:
  Serial.println("Motor ON       LED ON");
  digitalWrite(motor_pin, HIGH);
  digitalWrite(led_pin, HIGH); //turn ON motor

  delay(5000); //wait 1second

  Serial.println("Motor 0FF      LED OFF");
  digitalWrite(motor_pin, LOW);
  digitalWrite(led_pin, LOW);//turn OFF motor

  delay(5000); //wait 1second
}
