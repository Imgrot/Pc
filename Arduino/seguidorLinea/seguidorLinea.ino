int seguidor = A1;   //pin seguidor de linea
int valSg = 0;       //Almacenamiento del valor del seguidor

void setup() {
  pinMode(seguidor, INPUT);
  Serial.begin(9600);
}

void loop() {

  valSg = analogRead(seguidor);
  Serial.println(valSg);
  delay(100);
}
