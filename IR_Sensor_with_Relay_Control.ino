int irSensor = 2;   // IR sensor output pin
int relayPin = 8;   // Relay module control pin
int sensorValue = 0;

void setup() {
  pinMode(irSensor, INPUT);   // IR sensor as input
  pinMode(relayPin, OUTPUT);  // Relay as output
  Serial.begin(9600);
  Serial.println("IR Sensor with Relay Ready");
}

void loop() {
  sensorValue = digitalRead(irSensor);  // Read sensor output

  if (sensorValue == LOW) {    // Object detected (usually LOW)
    digitalWrite(relayPin, HIGH);  // Turn ON relay
    Serial.println("Object Detected - Relay ON");
  } else {                     // No object
    digitalWrite(relayPin, LOW);   // Turn OFF relay
    Serial.println("No Object - Relay OFF");
  }

  delay(100);
}
