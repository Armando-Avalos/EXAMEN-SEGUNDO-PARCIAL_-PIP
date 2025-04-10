#include "DHT.h"

#define DHTPIN 2       // Pin digital conectado al DHT22
#define DHTTYPE DHT11  // Tipo de sensor DHT

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Lectura del sensor DHT22"));

  dht.begin();
}

void loop() {
  delay(2000);  // Espera entre lecturasimage.png

  // Lectura del DHT22
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Verificar si la lectura fue exitosa
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Error al leer del sensor DHT22"));
    return;
  }

  // Mostrar datos en el Monitor Serial
  Serial.print(F("Humedad: "));
  Serial.print(h);
  Serial.print(F("%  Temperatura: "));
  Serial.print(t);
  Serial.println(F("°C"));
}
