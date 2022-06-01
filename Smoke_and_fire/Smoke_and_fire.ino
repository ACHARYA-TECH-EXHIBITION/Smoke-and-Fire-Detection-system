#include "dht.h"

#define dht_apin A1

int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A0;
//Threshold value
int sensorThres = 300;

dht DHT;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
  DHT.read11(dht_apin);

  Serial.print("temperature = ");
  Serial.print(DHT.temperature);
    
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);

  if ((analogSensor > sensorThres) && DHT.temperature > 40) {

    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);

  } else {
    if (analogSensor > sensorThres) {
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, LOW);
      //tone(buzzer, 1000, 200);
    } else {
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, HIGH);
      noTone(buzzer);
    }
  }
  delay(100);
}
