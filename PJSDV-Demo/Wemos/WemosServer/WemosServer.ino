/*
 * Wemos I/O Server
 * 
 * Wemos module connecting to a wifi network and creating a TCP server.
 * 
 * Can receive TCP server commands to set or get data.
 */

#include <ESP8266WiFi.h>
#include <ArduinoWiFiServer.h>

#ifndef STASSID
#define STASSID "3.1415"
#define STAPSK  "YouShallNotPassword"
#endif

IPAddress local_IP(172, 16, 99, 101);
IPAddress gateway(172, 16, 99, 1);
IPAddress subnet(255, 255, 255, 0);

const char* ssid     = STASSID;
const char* password = STAPSK;

ArduinoWiFiServer server(8080);

void setup() {
  // Start up Serial debug
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Configure static IP.
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }

  // Start connecting to the WiFi
  WiFi.begin(ssid, password);

  // Wait until we are connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Get IP Address of this device
  IPAddress ip = WiFi.localIP();

  Serial.println();
  Serial.print("Connected to WiFi network: IP: ");  
  Serial.println(ip);

  // Start TCP Server
  server.begin();
  Serial.println("TCP Server started listening...");

  // Set the I/O

  // Buttons
  pinMode(D6, INPUT_PULLUP);
  pinMode(D7, INPUT_PULLUP);

  // Leds
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
}

void handleConnections();

void loop() {
  // Handle clients sending request to the TCP server.
  handleConnections();
}

void handleConnections() {
  // Gets a client that is connected to the server and has data available for reading.
  WiFiClient client = server.available();
  
  if (client) { // Check if client has send a message, otherwise this is false.
    Serial.println("Got something");
    String s = client.readStringUntil('\n'); // Read the incoming message. Delimited by a new line char.
    s.trim(); // trim eventual \r
    Serial.print("Incoming message from client; ");
    Serial.println(s); // print the message to Serial Monitor

    // Split incoming message into a command and argument.
    char commandBuffer[4];
    char argumentBuffer[4];

    boolean passedSpecialChar = false;
    int i, argumentBufferLength = 0;

    // Loop through the whole string in search of the special char. (Default: ':'). Everything before this char gets added to the commandBuffer, everything after to the argumentBuffer.
    for (i=0; i < s.length(); i++) {
      if (s[i] == ':') {
        passedSpecialChar = true;
        commandBuffer[i] = '\0';
      } else {
        if (passedSpecialChar) {
          argumentBuffer[argumentBufferLength] = s[i];
          argumentBufferLength ++;
        } else {
          commandBuffer[i] = s[i];
        }
      }      
    }
    argumentBuffer[argumentBufferLength] = '\0';
    argumentBufferLength++;

    switch(String(commandBuffer).toInt()) {
      case 0:
        digitalWrite(D1, argumentBuffer[0] == '1');
        client.println("200");
        break;
      case 1:
        digitalWrite(D2, argumentBuffer[0] == '1');
        client.println("200");
        break;
      case 2:
        client.println(analogRead(A0));
        break;
      case 3:
        client.println(digitalRead(D6));
        break;
      case 4:
        client.println(digitalRead(D7));
        break;
      default:
        client.println("Not Implemented");
    	client.stop();
        break;
    }
  }
}
