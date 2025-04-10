#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Adafruit_Sensor.h"
#include "DHT.h"

// Configuración de sensores y pantalla
#define DHTPIN 2
#define DHTTYPE DHT11
#define LUZ_PIN A0
#define LED_PIN 8

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección 0x27, LCD de 16x2

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Inicialmente apagado
}

void loop() {
  // Leer temperatura y humedad
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Leer sensor de luz
  int sensorValue = analogRead(LUZ_PIN);
  float lightPercent = (sensorValue / 1023.0) * 100.0;

  // Validar lecturas
  if (isnan(h) || isnan(t)) {
    Serial.println("Error al leer el sensor DHT11");
    lcd.clear();
    lcd.print("Error en sensor");
    delay(2000);
    return;
  }

  // Mostrar en Serial
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" °C, Humedad: ");
  Serial.print(h);
  Serial.print(" %, Luz: ");
  Serial.print(lightPercent);
  Serial.println(" %");

  // Mostrar en LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T ");
  lcd.print(t, 1);
  lcd.print("C I ");
  lcd.print(100 - lightPercent, 0);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("H ");
  lcd.print(h, 0);
  lcd.print("% ");

  // LED encendido si hay poca luz (<30%)
  if (lightPercent < 30) {
    digitalWrite(LED_PIN, HIGH);
    lcd.print("LED:ON ");
  } else {
    digitalWrite(LED_PIN, LOW);
    lcd.print("LED:OFF");
  }

  delay(2000); // Esperar antes de la próxima lectura
}
