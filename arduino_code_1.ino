#include "DHT.h"
#include <ArduinoJson.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Wait 30 seconds between measurements.
  delay(30000);

  // Reading temperature or humidity.
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and skip this iteration.
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Create a JSON object
  StaticJsonDocument<200> doc;
  doc["sensor"] = "SENG691 DHT11";
  doc["humidity"] = h;
  doc["temperature"] = t;
  doc["timestamp"] = millis();

  // Serialize JSON to serial
  serializeJson(doc, Serial);
  Serial.println(); // Print a newline to separate each output
}


