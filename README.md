This project demonstrates the implementation of a scalable IoT Time Series architecture. It involves collecting and streaming environmental data from an Arduino Uno R4 Wi-Fi IoT device equipped with a DHT11 humidity and temperature sensor. The data is streamed via MQTT to an EMQX broker and then routed to a Kafka broker. From Kafka, the data is stored in an InfluxDB database for real-time event detection, aggregation, and offline analytics.

Key Components
Arduino Uno R4 Wi-Fi IoT Device:
Equipped with a DHT11 sensor for humidity and temperature measurements.
Streams JSON data containing the sensor readings to an MQTT broker.
MQTT Broker (EMQX):
Receives time-series data from the Arduino and routes it to a Kafka broker.
Kafka Broker:
Manages streaming data for aggregation and analytics.
InfluxDB Database:
Stores the data for real-time aggregation and event detection.
Provides the capability for offline exploration and analytics.
Features
Data Streaming:
Streams temperature and humidity data to the broker for real-time and batch processing.
Real-Time Aggregation:
Calculates the average temperature every 5 minutes using continuous queries.
Event Detection:
Alerts users when temperature or humidity exceeds predefined thresholds.
Offline Analytics:
Enables data analysis using rolling averages and daily statistical queries.
Setup and Configuration
IoT Device:
Acquire the Arduino and sensor.
Install the latest Arduino IDE.
Connect the sensor and upload the Arduino sketch to stream data.
MQTT Broker (EMQX):
Install and configure the EMQX broker.
Enable connections from the Arduino.
Kafka Broker:
Deploy Kafka on a local machine or cloud platform.
Ensure proper integration between EMQX and Kafka.
InfluxDB:
Deploy InfluxDB for storing time-series data.
Configure it to read from Kafka and write data to the database.
Create continuous queries for aggregation and event detectio
