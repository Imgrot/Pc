int lai = 3;
int lig = 5;
int lou = 6;
int x;

void setup() {

  pinMode (lai, OUTPUT);
  pinMode (lig, OUTPUT);

}

void loop() {

  for (x = 0; x < 256; x++) {
    analogWrite(lai, x);
    delay (1);
  }
  for (x = 0; x < 256; x++) {
    analogWrite(lig, x);
    delay(1);
  }
  for (x = 0; x < 256; x++) {
    analogWrite(lou, x);
    delay(1);
  }

  for (x = 255; x > -1; x--) {
    analogWrite(lai, x);
    delay(1);
  }
  for (x = 255; x > -1; x--) {
    analogWrite(lig, x);
    delay(1);
  }
  for (x = 255; x > -1; x--) {
    analogWrite(lou, x);
    delay(1);
  }
}
