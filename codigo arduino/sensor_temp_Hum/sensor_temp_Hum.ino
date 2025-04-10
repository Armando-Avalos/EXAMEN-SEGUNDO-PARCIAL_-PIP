/*
Práctica Lectura del Sensor (DHT11)
Programación de Interfaces y Puertos
2025
Objetivo: Aprender a conectar y leer datos del sensor (DHT11) utilizando Arduino.
*/

#include "Adafruit_Sensor.h"
#include "DHT.h"

#define DHTPIN 2       // Pin digital conectado al DHT11
#define DHTTYPE DHT11  // Tipo de sensor DHT

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Lectura de sensor DHT11"));
  dht.begin(); // Inicializar sensor
}

void loop() {
  delay(2000);  // Espera entre lecturas

  // Lectura del DHT22
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Error al leer del sensor DHT11"));
    return;
  }

  // Mostrar datos en el Monitor Serial
  Serial.print(F("Humedad: "));
  Serial.print(h);
  Serial.print(F("%  Temperatura: "));
  Serial.print(t);
  Serial.println(F("°C"));
}
