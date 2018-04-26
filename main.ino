#include <ESP8266WiFi.h>

#include <WiFiClient.h>

const char *ssid = "LegoMaM18";

const char *password = "legokor12";

WiFiServer server(5045);


void setup() {

  delay(1000);
  
  Serial.begin(115200);
  
  Serial.println();
  
  Serial.print("Configuring access point...");
  
  WiFi.softAP(ssid, password);
  
  IPAddress myIP = WiFi.softAPIP();
  
  Serial.print("AP IP address: ");
  
  Serial.println(myIP);
  
  server.begin();
  
  Serial.println("HTTP server started");

}

void loop() {

  TCPServer();

}

void TCPServer () {
    WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      Serial.println("Connected to client");    
    }
    if (client.available() > 0) {
      // Read incoming message
      char inChar = client.read();
      // Send back something to the clinet
      server.write(inChar);
      // Echo input on Serial monitor
      Serial.write(inChar);
    }
  }
}
