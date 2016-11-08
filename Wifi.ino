#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>

void setupWifi()
{
  Serial.begin(115200);
  Serial.println("");

  WiFi.begin();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("WifiLed")) {
    Serial.println("MDNS responder started");
  }
}

void loopWifi()
{
  
}

