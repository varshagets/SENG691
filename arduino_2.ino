#include "WiFiS3.h"
#include <ArduinoMqttClient.h>
#include "DHT.h"
#include <ArduinoJson.h>

// WiFi Credentials
char ssid[] = "kush";
char pass[] = "Sanjay2906";

// MQTT Broker Settings
char mqtt_user[] = "admin";
char mqtt_pass[] = "Varsha@123";
const char broker[] = "10.0.0.99";
int port = 1883;
const char publish_topic[] = "test-kafka";

// Sensor Settings
#define DHTPIN 2          // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11     // DHT 11
DHT dht(DHTPIN, DHTTYPE);

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Connect to WiFi
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.print(".");
    delay(5000);
  }
  Serial.println("\nYou're connected to the network");

  // MQTT Setup
  mqttClient.setUsernamePassword(mqtt_user, mqtt_pass);
  Serial.print("Attempting to connect to the MQTT broker: ");
  while (!mqttClient.connect(broker, port)) {
    Serial.print(".");
    delay(5000);
  }
  Serial.println("\nYou're connected to the MQTT broker!");
}

void loop() {
  delay(30000); // Wait 30 seconds between measurements.

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Prepare JSON document
  StaticJsonDocument<200> doc;
  doc["sensor"] = "DHT11";
  doc["humidity"] = humidity;
  doc["temperature"] = temperature;
  doc["timestamp"] = millis();

  // Serialize JSON to a string
  String output;
  serializeJson(doc, output);

  // Print to Serial for debugging
  serializeJson(doc, Serial);
  Serial.println();

  // Publish to MQTT
  mqttClient.beginMessage(publish_topic);
  mqttClient.print(output);
  mqttClient.endMessage();
}
