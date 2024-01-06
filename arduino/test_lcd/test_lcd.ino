#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600); // Initialise la communication série à 9600 bauds
}

void loop() {
  // Demande à l'utilisateur ce qu'il souhaite écrire
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Entrez du texte:");
  
  while (!Serial.available()) {
    // Attendez que l'utilisateur entre quelque chose dans le moniteur série
  }
  
  // Lorsque quelque chose est disponible dans le moniteur série, lisez-le et affichez-le sur l'écran LCD
  String userInput = Serial.readString();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(userInput);

  // Attendez un moment avant de redemander
  delay(2000);

  // Effacez l'écran LCD
  lcd.clear();
  delay(1000);
}
