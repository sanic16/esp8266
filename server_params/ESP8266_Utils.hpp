void ConnectWiFi_STA(bool useStaticIP=false){
  IPAddress ip(192, 168, 1, 39);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);
  
  Serial.println("");
  WiFi.mode(WIFI_STA);
  // preferably channels 1, 6 and 11
  WiFi.begin(ssid, password, 11); 

  Serial.print("Conectando ");
  
  if(useStaticIP) WiFi.config(ip, gateway, subnet);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.print("Iniciado STA:\t");
  Serial.println(WiFi.SSID());
  Serial.print("hostname: \t");
  Serial.println(WiFi.hostname());
  Serial.print("localIP :\t");
  Serial.println(WiFi.localIP());
  Serial.print("subnetMask :\t");
  Serial.println(WiFi.subnetMask());
  Serial.print("gatewayIP :\t");
  Serial.println(WiFi.gatewayIP());
  Serial.print("dnsIP :\t");
  Serial.println(WiFi.dnsIP());
  Serial.print("macAddress :\t");
  Serial.println(WiFi.macAddress());
  
}

void ConnectWiFi_AP(bool useStaticIP = false){
  IPAddress ip(192, 168, 1, 39);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);
  
  Serial.println("");
  WiFi.mode(WIFI_AP);
  while(!WiFi.softAP(ssid, password)){
    Serial.print(".");
    delay(500);
  }
  
  if(useStaticIP) WiFi.softAPConfig(ip, gateway, subnet);
  Serial.println("");
  Serial.print("Iniciado AP:\t");
  Serial.println(ssid);
  Serial.print("IP address:\t");
  Serial.println(WiFi.softAPIP());
}
