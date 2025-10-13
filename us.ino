#define trigPin 12
#define echoPin 13
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  float distance;

  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2;

  // Map distance from 0–20 cm to 10 LEDs
  int ledsToLight = map(distance, 5, 20, 10, 5);
  ledsToLight = constrain(ledsToLight, 0, 10);

  // Turn ON all previous LEDs solid
  for (int i = 0; i < ledsToLight - 1; i++) {
    digitalWrite(ledPins[i], HIGH);
  }

  // Turn OFF remaining LEDs
  for (int i = ledsToLight; i < 10; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // Blink only the last LED
  if (ledsToLight > 0) {
    digitalWrite(ledPins[ledsToLight - 1], HIGH);
    delay(150);
    digitalWrite(ledPins[ledsToLight - 1], LOW);
    delay(150);
  } else {
    delay(300); // Nothing detected, no blink
  }
}
