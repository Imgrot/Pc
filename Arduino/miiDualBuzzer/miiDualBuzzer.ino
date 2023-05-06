const int buzzer1 = 3;
const int buzzer2 = 5;
int i = 0;

void setup() {
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
}

void loop() {


  tone(buzzer1, 146.83);
  tone(buzzer2, 174.61);
  delay(200);

noTone(buzzer1);
noTone(buzzer2);
  delay(350);

  tone(buzzer1, 174.61);
  tone(buzzer2, 196);
  delay(134);

noTone(buzzer1);
noTone(buzzer2);
  delay(200);

  tone(buzzer1, 196);
  tone(buzzer2, 220);
  delay(200);

noTone(buzzer1);
noTone(buzzer2);
  delay(350);

  tone(buzzer1, 174.61);
  tone(buzzer2, 196);
  delay(200);

noTone(buzzer1);
noTone(buzzer2);
  delay(350);

  tone(buzzer1, 146.83);
  tone(buzzer2, 174.61);
  delay(134);

noTone(buzzer1);
noTone(buzzer2);
  delay(134);

  tone(buzzer1, 146.83);
  tone(buzzer2, 146.83);
  delay(200);

noTone(buzzer1);
noTone(buzzer2);
  delay(134);

  tone(buzzer1, 146.83);
  tone(buzzer2, 146.83);
  delay(200);

  delay(134);

  tone(buzzer1, 146.83);
  tone(buzzer2, 146.83);
  delay(134);

noTone(buzzer1);
noTone(buzzer2);
  delay(134);

  delay(1340);

}
