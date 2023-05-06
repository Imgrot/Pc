int led_rojo = 3;
int led_verde = 5;
int led_azul = 6;
int pulsador = 12;
int x = 0;

void setup() {
  pinMode(led_rojo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(pulsador, INPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(pulsador, LOW);
  x = digitalRead(pulsador);
  Serial.println(x);

  if (x == 1) {
    analogWrite(led_rojo, 255);
    analogWrite(led_verde, 255);
    analogWrite(led_azul, 255);
  }
  if (x == 0) {
    analogWrite(led_rojo, 186);
    analogWrite(led_verde, 0);
    analogWrite(led_azul, 6);
  }
}
