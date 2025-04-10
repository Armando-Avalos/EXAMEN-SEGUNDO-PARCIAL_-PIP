/*
  Práctica Lectura de Múltiples Sensores I2C (DHT22 y BMP280)
  Programación de Interfaces y Puertos
  2025
  Objetivo: Aprender a conectar y leer datos de múltiples sensores I2C (DHT22 y BMP280) utilizando Arduino o ESP32.
*/

#include <Wire.h>
#include "Adafruit_Sensor.h"
#include "DHT.h"
#include <Adafruit_BMP280.h> // Biblioteca del BMP280

#define DHTPIN 2       // Pin digital conectado al DHT22
#define DHTTYPE DHT22  // Tipo de sensor DHT

DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP280 bmp;   // Usar I2C

void setup() {
  Serial.begin(9600);
  Serial.println(F("Lectura de sensores I2C"));

  dht.begin();

  if (!bmp.begin()) {
    Serial.println(F("No se pudo encontrar el sensor BMP280"));
    while (1) delay(10);
  }
}

void loop() {
  delay(2000);  // Espera entre lecturas

  // Lectura del DHT22
  float h = dht.readHumidity();
  float t_dht = dht.readTemperature();

  // Lectura del BMP280
  float t_bmp = bmp.readTemperature();
  float p = bmp.readPressure() / 100.0F; // Conversión a hPa

  // Mostrar datos en el Monitor Serial
  Serial.print(F("Humedad: "));
  Serial.print(h);
  Serial.print(F("%  Temperatura (DHT22): "));
  Serial.print(t_dht);
  Serial.print(F("°C  Temperatura (BMP280): "));
  Serial.print(t_bmp);
  Serial.print(F("°C  Presión: "));
  Serial.print(p);
  Serial.println(F(" hPa"));
}
