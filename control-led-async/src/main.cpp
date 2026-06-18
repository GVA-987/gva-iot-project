#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <LittleFS.h>

AsyncWebServer server(80);

const char *ssid = "SSID_DE_TU_WIFI";
const char *password = "CONTRASEÑA_DE_TU_WIFI";

const int LED_PIN = 2;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  // Inicializa el sistema de archivos LittleFS
  if (!LittleFS.begin(true))
  {
    Serial.println("Error al montar LittleFS");
    return;
  }

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Conectando al WiFi...");
  }
  Serial.println("Conectado Exitosamente");
  Serial.print("IP del servidor: ");
  Serial.println(WiFi.localIP());

  // Servir la página HTML principal
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/index.html", "text/html"); });

  // Servir archivos CSS
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/style.css", "text/css"); });

  // Servir archivos JavaScript
  server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/script.js", "application/javascript"); });

  // Endpoint para alternar el estado del LED
  server.on("/toggle-led", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    int estadoActual = digitalRead(LED_PIN); // Leer el estado actual del LED
    digitalWrite(LED_PIN, !estadoActual); // Alternar el estado del LED
    
    // Enviar la respuesta al cliente con el nuevo estado del LED
    request->send(200, "text/plain", !estadoActual ? "Encendido" : "Apagado"); });

  // Iniciar servidor
  server.begin();
}

void loop()
{
}