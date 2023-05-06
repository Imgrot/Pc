#include<Servo.h>

int pos = 0;
int ServoPin = 3;
int i;
Servo Puntero;

void setup() {
  Puntero.attach(ServoPin);
}

void loop() {

  for (i = 1, i <= 10, i++) {
    Puntero.write(180);
    delay(25);
   
    for (i = 1, i <= 10, i++) {
      Puntero.write(0);
      delay(25);
    }
  }
}
