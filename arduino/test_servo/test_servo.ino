#include "Servo.h"

Servo servo; // création de l'objet "servo"

void setup() {
   servo.attach(6); // attache le servo au pin spécifié
}

void loop() {
   servo.write(0); // demande au servo de se déplacer à cette position
   delay(1000); // attend 1000 ms entre changement de position

    servo.write(360); // demande au servo de se déplacer à cette position
   delay(1000); // attend 1000 ms entre changement de position

}
