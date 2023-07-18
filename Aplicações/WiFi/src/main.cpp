#include <WiFi.h>

const char *SSID = "Nicolas";
const char *PWD = "12345678";

void setup()
{
  Serial.begin(9600);
  Serial.print("Connecting to Wi-Fi");
  Serial.print("Connecting to Wi-Fi");

  WiFi.begin(SSID, PWD);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
  }
  Serial.println("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    
  }else {    
    delay(5000);
    ESP.restart();
  }
}