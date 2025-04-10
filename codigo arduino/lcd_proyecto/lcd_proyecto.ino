    #include <Wire.h>
    #include <LiquidCrystal_I2C.h>
    LiquidCrystal_I2C lcd(0x27, 16, 2); // Inicializa la pantalla LCD I2C
    void setup() {
      lcd.init(); // Inicializa la pantalla LCD
      lcd.backlight(); // Enciende la retroiluminación
      lcd.print("T 34.5C  I 67%"); // Muestra un mensaje en la pantalla
      lcd.setCursor(0, 1); // Coloca el cursor en la segunda fila
      lcd.print("H 85%    LED:OFF");
      //lcd.print("H 85%    19:55");
    }
    void loop() {
      // No se hace nada en el bucle principal
    }
