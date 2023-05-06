int led_rojo = 3;
int led_verde = 5;
int led_azul = 6;


void setup() {
  pinMode(led_rojo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_azul, OUTPUT);
}

void loop() {

  digitalWrite(led_rojo, HIGH);
  digitalWrite(led_verde, HIGH);
  digitalWrite(led_azul, LOW);

}
