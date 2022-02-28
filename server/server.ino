#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

IPAddress ip(192, 168, 1, 39);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

#include "config.h"
#include "ESP8266_Utils.hpp"
ESP8266WebServer server(80);

// Función que se ejecutará en la URI '/'
void handleRoot(){
  server.send(200, "text/plain", "Hola mundo!");
  digitalWrite(LED_BUILTIN, LOW);
}

// Función que se ejecutará en URI desconocida
void handleNotFound(){
  server.send(404, "text/plain", "Not found");
}


void setup(){
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  // Para modo STA
  ConnectWiFi_STA(true);

  // Ruteo para '/'
  server.on("/", handleRoot);

  // Ruteo para '/inline' usando función lambda
  server.on("/inline", [](){
    server.send(200, "text/plain", "Estos también funciona");
    digitalWrite(LED_BUILTIN, HIGH);
  });

  // Ruteo para URI desconocida
  server.onNotFound(handleNotFound);

  // Iniciar servidor
  server.begin();
  Serial.println("HTTP server started");
  
}
void loop(){
  server.handleClient();
}
