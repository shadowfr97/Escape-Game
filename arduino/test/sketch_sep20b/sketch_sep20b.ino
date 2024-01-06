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
  // Créer un motif de losange en rose
  matrix.fillScreen(matrix.Color(0, 0, 0));  // Éteindre toutes les LED
  
  matrix.drawPixel(5, 4, matrix.Color(255, 0, 255)); // Rose
  matrix.drawPixel(5, 1, matrix.Color(255, 0, 255)); // Rose
  matrix.drawPixel(4, 12, matrix.Color(255, 0, 255)); // Rose
  matrix.drawPixel(4, 13, matrix.Color(255, 0, 255)); // Rose

  matrix.drawPixel(6, 14, matrix.Color(255, 0, 255)); // Rose
  matrix.drawPixel(7, 2, matrix.Color(255, 0, 255)); // Rose
  matrix.drawPixel(8, 14, matrix.Color(255, 0, 255)); // Rose
  matrix.drawPixel(9, 1, matrix.Color(255, 0, 255)); // Rose
  matrix.drawPixel(10, 13, matrix.Color(255, 0, 255)); // Rose
  matrix.drawPixel(10, 12, matrix.Color(255, 0, 255)); // Rose
  matrix.drawPixel(9, 4, matrix.Color(255, 0, 255)); // Rose
  matrix.drawPixel(8, 10, matrix.Color(255, 0, 255)); // Rose
  matrix.drawPixel(6, 10, matrix.Color(255, 0, 255)); // Rose
  matrix.drawPixel(7, 6, matrix.Color(255, 0, 255)); // Rose

  matrix.show();
}
