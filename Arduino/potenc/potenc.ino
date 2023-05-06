int pot = A2;
int x = 0;
int y = 0;


void setup() {
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {

  x = analogRead(pot);
  Serial.println(x);

  y = map(x, 0, 1024, 0, 255);
  analogWrite(6, y);
  analogWrite(5, y);
}

