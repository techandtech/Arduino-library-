#include <Servo.h>

#define trigPin 9
#define echoPin 10
#define buzzerPin 7

Servo myServo;
int servoPin = 6;
int pos = 0;            // Current servo position
bool forward = true;    // Sweep direction

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  myServo.attach(servoPin);
}

void loop() {
  float distance = getDistance();

  Serial.print("Distance:cm");
  Serial.println(distance);

  if (distance < 15.0) {
    digitalWrite(buzzerPin, HIGH);
    // Stop servo at current position
  } else {
    digitalWrite(buzzerPin, LOW);

    myServo.write(pos);
    delay(25);  // Slow movement

    // Update position
    if (forward) {
      pos += 1;
      if (pos >= 180) forward = false;
    } else {
      pos -= 1;
      if (pos <= 0) forward = true;
    }
  }
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;

  return distance;
}
