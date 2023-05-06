#include<Servo.h>

int pos = 0;
int ServoPin = 3;

Servo Puntero;

void setup() {
  Serial.begin(9600);
  Puntero.attach(ServoPin);
}

void loop() {
  Serial.print("a que posicion muevo: ")
  while (Serial.available() == 0) {}
  pos = Serial.parseInt();
  Puntero.write(pos);
  delay(25);
}
