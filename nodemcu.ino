#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// Create KiwisIoT object
KiwisIoT kiwisiot(ssid, pass, topic);

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("ESP8266 IoT Connection");

  // Initialize KiwisIoT
  kiwisiot.begin();

  Serial.println("KiwisIoT Initialized");
}

void loop() {

  // Maintain KiwisIoT connection
  kiwisiot.run();

  // Test value
  int testValue = 25;

  // Send data to Channel 0
  kiwisiot.send("0", testValue);

  Serial.print("Data sent to KiwisIoT: ");
  Serial.println(testValue);

  // Wait for 3 seconds
  delay(3000);
}
