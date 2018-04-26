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

  WiFiClient client = server.available();
  if (client)
  {
    Serial.println("\n[Client connected]");
    while (client.connected())
    {
      if (client.available())
      {
        char line = client.read();
        Serial.print(line);
      }
    }
    delay(1);
    client.stop();
    Serial.println("[Client disonnected]");
  }
  
}
