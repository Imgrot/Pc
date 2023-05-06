//lectura de entradas analogicas

int pot_pin = A0;
int pot_valor = 0;

void setup() {

  Serial.begin(9600);  //comunicacion serial
}

void loop() {

  pot_valor = analogRead(pot_pin);  //read the input pin
  Serial.println(pot_valor);             // debug value

}
