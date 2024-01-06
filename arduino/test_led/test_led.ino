#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 256  // 16x16 matrix
#define DATA_PIN 3     // Pin de données de la matrice LED

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(16, 16, DATA_PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB + NEO_KHZ800);

void setup() {
  matrix.begin();
  matrix.setBrightness(40);  // Réglez la luminosité à votre convenance (de 0 à 255)
}

void loop() {
  // Éteindre toutes les LED
  matrix.fillScreen(matrix.Color(0, 0, 0));

  // Incrémentez la position en Y de la LED
  static int y = 0;
   static int x = 0;
  matrix.drawPixel(0, y, matrix.Color(255, 255, 0)); 
    matrix.drawPixel(x, 0, matrix.Color(255, 255, 0));  

  // Incrémentez la position en Y
  y = (y + 1) % 16;
   x = (x+1)% 16;
  matrix.show();
  delay(1000);  // Attendre 100 millisecondes
}
