// Copyright 2017 P. Nivatyakul kaebmoo@gmail.com 
// 7/7/2017 
// Arduino Nano

int ldrPin = A0;
int LDR = 6;
int PIR = 3;
int PIR_Disable = 9;
int ledPin = 13;
int sensorValue = 0;
int light = 0;
int detect = LOW;
int config_pir = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(PIR, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  sensorValue = analogRead(ldrPin);
  light = digitalRead(LDR);
  detect = digitalRead(PIR);
  config_pir = digitalRead(PIR_Disable);
  
  if (sensorValue > 512 || light == 1) {
    if (config_pir == 0) {
      if (detect == HIGH) {
        digitalWrite(ledPin, HIGH);
        delay(500);
      }
      else {
        digitalWrite(ledPin, LOW);
        delay(500);
      }
    }
    else {
      digitalWrite(ledPin, HIGH);
      delay(500);
    }
  }
  else {
    digitalWrite(ledPin, LOW);
    delay(500);
  }

/*
  Serial.print("Config PIR = ");
  Serial.println(config_pir);
  Serial.println(sensorValue, DEC);
  Serial.print("Light = ");
  Serial.println(light, DEC);
  Serial.print("Motion = ");
  Serial.println(detect, DEC);
*/
}
