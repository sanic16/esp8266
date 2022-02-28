// Conectar
#include <ESP8266WiFi.h>

// Configurar WiFi generada
const char *ssid = "dlink-FC29";
const char *password = "fuxae77754";

IPAddress ip(192, 168, 1, 39);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void setup(){
  Serial.begin(115200);
  delay(10);
 

  WiFi.mode(WIFI_STA);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
  Serial.println();
  Serial.print("Conectando a:\t");
  Serial.print(ssid);
  Serial.println();
  
  // Esperar a que nos conectemos
  while(WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.print(".");
  }
  Serial.println();
  // Mostrar mensaje de éxito y dirección IP asignada
  Serial.println("Conexión establecida");
  Serial.print("IP address: \t");
  Serial.println(WiFi.localIP());
}

void loop(){
  
}
