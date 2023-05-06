int led_azul = 3;
int led_verde = 5;
int led_rojo = 6;
int pot = A2;
int pulsador = 12;
int x = 0;
int y = 0;
int z = 0;


void setup() {
  pinMode(pot, INPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(pulsador, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(led_rojo, HIGH);
  digitalWrite(led_verde, HIGH);
  digitalWrite(led_azul, HIGH);

  z = digitalRead(pulsador);
  Serial.println(z);

  x = analogRead(pot);
  Serial.println(x);

  y = map(x, 0, 1023, 0, 2000);

  if (z == 0) {

    //VERDE
    digitalWrite(led_rojo, HIGH);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_azul, HIGH);
    delay (5000 + y);

    //AMARILLO
    analogWrite(led_rojo, 26);
    digitalWrite(led_verde, LOW);
    digitalWrite(led_azul, HIGH);
    delay(3000 + y);

    //ROJO
    digitalWrite(led_rojo, LOW);
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_azul, HIGH);
    delay(2000 + y);
  }
}
