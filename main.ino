#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char * ssid = "LegoMaM18";
const char * password = "legokor12";
WiFiServer server(1360);

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.println(myIP);
  server.begin();
}

void loop() {
  TCPServer();
}

void TCPServer () {
  WiFiClient client = server.available();
  if (client) {
    if (client.available() > 0) {
      char inChar = client.read();
      Serial.write(inChar);
    }
  }
}
