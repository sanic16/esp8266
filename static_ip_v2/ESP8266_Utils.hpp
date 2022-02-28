void ConnectWiFi_STA(bool useStaticIP=false){

  Serial.println("");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Conectando");
  
  if(useStaticIP) WiFi.config(ip, gateway, subnet);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Iniciado STA:\t");
  Serial.println(ssid);
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
}

void ConnectWiFi_AP(bool useStaticIP = false){
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
