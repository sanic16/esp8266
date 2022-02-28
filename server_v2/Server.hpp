// Función que se ejecutará en la UNI '/'
void handleRoot(){
  server.send(200, "text/plain", "Hola mundo!");
}

// Función que se ejecutará en URI desconocida
void handleNotFound(){
  server.send(404, "text/plain", "Not found");
}

void InitServer(){
  // Ruteo para '/'
  server.on("/", handleRoot);

  // Ruteo para '/inline' usando función lambda
  server.on("/inline", [](){
    server.send(200, "text/plain", "Esto también funciona");
  });

  // Ruteo para URI desconocida
  server.onNotFound(handleNotFound);

  // Iniciar servidor
  server.begin();
  Serial.println("HTTP server started");
}
