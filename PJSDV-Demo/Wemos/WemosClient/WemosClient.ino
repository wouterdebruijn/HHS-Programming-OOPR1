/*
    This sketch establishes a TCP connection to a "quote of the day" service.
    It sends a "hello" message, and then prints received data.
*/

#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "3.1415"
#define STAPSK  "YouShallNotPassword"
#endif

IPAddress local_IP(172, 16, 99, 101);
IPAddress gateway(172, 16, 99, 1);
IPAddress subnet(255, 255, 255, 0);

const char* ssid     = STASSID;
const char* password = STAPSK;

const char* host = "172.16.99.1";
const uint16_t port = 8080;

// (TCP) client
WiFiClient client;

void setup() {
  // Init Serial
  Serial.begin(115200);

  // Connect to the Wifi Network
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Set a static ip instead of DHCP
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }

  // Set ESP mode to client, default is both.
  WiFi.mode(WIFI_STA);

  // Start connecting...
  WiFi.begin(ssid, password);

  // Wait until we are connected to the WIFI.
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.print("\nWiFi connected - ");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check the received buffer
  if (client.available()) {
    // If we have data, we read until the limiter
    char ch = static_cast<char>(client.read());
    Serial.print(ch);
  }

  if (!client.connected()) {
    // Disconnect from the server.
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
        
    // Connect to (TCP) server.
    if (client.connect(host, port)) {
      Serial.println("Connected to TCP Server!");
      
      client.println("Hello from ESP!");
    }
  }
}
