int irSensor = 2;   // IR sensor output connected to digital pin 2
int led = 13;       // LED connected to digital pin 13
int sensorValue = 0;

void setup() {
  pinMode(irSensor, INPUT);   // IR sensor as input
  pinMode(led, OUTPUT);       // LED as output
  Serial.begin(9600);         // For debugging (optional)
}

void loop() {
  sensorValue = digitalRead(irSensor);  // Read the sensor output

  if (sensorValue == LOW) {  // Object detected
    digitalWrite(led, HIGH); // Turn LED ON
    Serial.println("Object Detected");
  } else {                   // No object
    digitalWrite(led, LOW);  // Turn LED OFF
    Serial.println("No Object");
  }

  delay(100); // Small delay to stabilize readings
}
