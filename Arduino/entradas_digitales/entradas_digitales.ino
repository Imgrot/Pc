//entradas
int est_puls = 0;
int puls_pin = 7;
int eled = 0;
//salidas
int led_pin = 8;

void setup() {

  pinMode (puls_pin, INPUT_PULLUP);
  pinMode (led_pin, INPUT);  
  pinMode (led_pin, OUTPUT);

}

void loop() {

  est_puls = digitalRead(puls_pin);
  eled = digitalRead(led_pin);

digitalWrite(led_pin, eled);

  if (eled == 0 && est_puls == 1) {
    eled = HIGH;
  }

  if (eled == 1 && est_puls == 1) {
    eled = LOW;
  }
}
