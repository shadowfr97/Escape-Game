#define PIR 2
#define LED 13

void setup() {
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600); // Initialiser la communication série à 9600 bauds
}

void loop() {
   int pirVal = digitalRead(PIR);

   if (pirVal == HIGH) {
      digitalWrite(LED, HIGH);
      Serial.println("Mouvement détecté!"); // Envoyer un message dans le moniteur série
      delay(500);
   }

   else {
      digitalWrite(LED, LOW);
      delay(500);
   }
}
