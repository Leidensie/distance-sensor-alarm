#include <Arduino.h>
#include "DistanceControl.h"


DistanceControl sensor; 
int buzzerPin = 13;

void setup() {
  Serial.begin(115200);
  Serial.println("Sistem Basladi...");
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  float distance = sensor.CalDistance();

  if (distance > 0 && distance < 20.0) { // 0'dan büyük ve 20'den küçükse
    tone(buzzerPin,800); // Daha ince ve uyarıcı bir ses (1kHz)
    delay(100);            // Kısa bir bip
    noTone(buzzerPin);
    
    // Mesafeye göre bekleme koyarsan (Opsiyonel)
    // Engel yaklaştıkça bu delay'i küçültebiliriz.
    delay(200); 
  } else {
    noTone(buzzerPin); // 20cm dışındaysa mutlaka sustur
  }

  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100); // Genel döngü hızı
}