// Función al recibir petición GET
void getLED(){
  // devolver respuesta
  server.send(200, "text/plain", String("GET ") + server.arg(String("Id")));
}

// Función al recibir petición POST
void setLED(){
  // mostrar por puerto serie
  Serial.println(server.argName(0));
  // devolver respuesta
  server.send(200, "text/plain", String("POST ") + server.arg(String("id")) + " " + server.arg(String("status")));
}

// Función que se ejecutará en la URI '/'
void handleRoot(){
  server.send(200, "text/plain", "Hola mundo1");
}

void handleNotFound(){
  server.send(404, "text/plain", "Not found");  
}

void InitServer(){
  // Ruteo para '/'
  server.on("/", handleRoot);

  // Ruteo para URI desconocida
  server.onNotFound(handleNotFound);

  // Definimos dos ruteos
  server.on("/led", HTTP_GET, getLED);
  server.on("/led", HTTP_POST, setLED);

  // Iniciar servidor
  server.begin();
  Serial.println("HTTP server started");
}
