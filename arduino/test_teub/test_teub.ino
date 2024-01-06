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
  // Créer un motif de losange en bleu
  matrix.fillScreen(matrix.Color(0, 0, 0));  // Éteindre toutes les LED

  matrix.drawPixel(6, 10, matrix.Color(0, 0, 255));
  matrix.drawPixel(6, 9, matrix.Color(0, 0, 255));
  matrix.drawPixel(6, 8, matrix.Color(0, 0, 255));
  matrix.drawPixel(6, 7, matrix.Color(0, 0, 255));
  matrix.drawPixel(6, 6, matrix.Color(0, 0, 255));

  matrix.drawPixel(8, 10, matrix.Color(0, 0, 255));
  matrix.drawPixel(8, 9, matrix.Color(0, 0, 255));
  matrix.drawPixel(8, 8, matrix.Color(0, 0, 255));
  matrix.drawPixel(8, 7, matrix.Color(0, 0, 255));
  matrix.drawPixel(8, 6, matrix.Color(0, 0, 255));

  matrix.drawPixel(7, 10, matrix.Color(0, 0, 255));
  matrix.drawPixel(7, 8, matrix.Color(0, 0, 255));

  matrix.drawPixel(5, 4, matrix.Color(0, 0, 255));
  matrix.drawPixel(5, 1, matrix.Color(0, 0, 255));
  matrix.drawPixel(4, 12, matrix.Color(0, 0, 255));
  matrix.drawPixel(4, 13, matrix.Color(0, 0, 255));

  matrix.drawPixel(6, 14, matrix.Color(0, 0, 255));
  matrix.drawPixel(7, 2, matrix.Color(0, 0, 255));
  matrix.drawPixel(8, 14, matrix.Color(0, 0, 255));
  matrix.drawPixel(9, 1, matrix.Color(0, 0, 255));
  matrix.drawPixel(10, 13, matrix.Color(0, 0, 255));
  matrix.drawPixel(10, 12, matrix.Color(0, 0, 255));
  matrix.drawPixel(9, 4, matrix.Color(0, 0, 255));

  matrix.show();
}
