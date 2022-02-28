#include <ESP8266WiFi.h>

IPAddress ip(192, 168, 1, 39);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

#include "config.h"
#include "ESP8266_Utils.hpp"


void setup(){
  Serial.begin(115200);

  // Para modo STA
  ConnectWiFi_STA(true);

  // Para modo AP
  //ConnectWiFi_AP(true);
}
void loop(){
  
}
