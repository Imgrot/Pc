int led = 12;
int lai = 11;
int lig = 10;

void setup() {
  pinMode (led, OUTPUT);
  pinMode (lai, OUTPUT);
  pinMode (lig, OUTPUT);

}

void loop() {
  digitalWrite (led, HIGH);
  digitalWrite (lai, LOW);
  delay (300);
  digitalWrite (lai, HIGH);
  digitalWrite (lig, LOW);
  delay (300);
  digitalWrite (led, LOW);
  digitalWrite (lig, HIGH);
  delay (300);

}
