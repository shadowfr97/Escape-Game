#include "SPI.h"
#include "MFRC522.h"

#define RST_PIN  9 // Broche de réinitialisation (RST)
#define SS_PIN  10 // Broche de sélection (SS)

MFRC522 mfrc522(SS_PIN, RST_PIN);
int Solenoid = 3; // Broche de l'électroaimant

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  delay(4);
  mfrc522.PCD_DumpVersionToSerial();
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));

  pinMode(Solenoid, OUTPUT); // Configure la broche de l'électroaimant en sortie
  digitalWrite(Solenoid, HIGH); // Initialise l'électroaimant comme activé
}

void loop() {
  // Réinitialise le cycle s'il n'y a pas de carte sur le lecteur
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Affiche l'UID sur le port série
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

  // Désactive l'électroaimant lorsque la carte RFID est détectée
  digitalWrite(Solenoid, LOW);

  // Attendez un certain temps pour maintenir l'électroaimant désactivé
  delay(1000); // Par exemple, désactivez l'électroaimant pendant 5 secondes

  // Réactivez l'électroaimant
  digitalWrite(Solenoid, HIGH);
}
