const int sensorPin = A0; // Pin analógico donde se conecta AO

void setup() {
  Serial.begin(9600); // Inicia comunicación serial
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Valor entre 0 y 1023

  // Convertir a porcentaje (entre 0 y 100%)
  float lightPercent = (sensorValue / 1023.0) * 100.0;

  // Mostrar el valor en el monitor serial
  Serial.print("Luz detectada: ");
  Serial.print(lightPercent, 1); // Mostrar con 1 decimal
  Serial.println(" %");

  delay(500); // Pequeña pausa
}
