#include <DHT.h>

// DHT Configuration
#define DHTPIN 2         // Pin connected to DHT sensor
#define DHTTYPE DHT11    // DHT11 or DHT22

DHT dht(DHTPIN, DHTTYPE);

const int mq2Pin = A0;   // MQ-2 analog pin

void setup() {
  Serial.begin(9600);
  dht.begin();
  delay(1000); // Give sensor time to start
}

void loop() {
  float temperature = dht.readTemperature();    // Read temperature (°C)
  float humidity = dht.readHumidity();          // Read humidity (%)
  int smokeLevel = analogRead(mq2Pin);          // Read analog smoke value (0-1023)

  // Error checking
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C  |  Humidity: ");
    Serial.print(humidity);
    Serial.print(" %  |  Smoke Level: ");
    Serial.println(smokeLevel);
  }

  delay(2000); // Wait 2 seconds before next reading
}
