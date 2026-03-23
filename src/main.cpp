#include <Arduino.h>
#include "DistanceControl.h"


DistanceControl sensor; 
int buzzerPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  float distance = sensor.CalDistance();

  if (distance > 0 && distance < 20.0) { 
    tone(buzzerPin,800); 
    delay(100);            
    noTone(buzzerPin);
    

    delay(200); 
  } else {
    noTone(buzzerPin); 
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100); 
}