//-------//Velocidad//-------//
byte ENA = A4;      //Izquierda
byte ENB = A5;      //Derecha

//-------//Control//-------//
byte IN1 = 7;      //Derecha
byte IN2 = 8;      //Derecha
byte IN3 = 9;      //Izquierda
byte IN4 = 10;     //Izquierda

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  //Velocidad
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  //Avanzar

  //Giro Derecha
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  //Giro Izquierda
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(800);      //Por 2 segundos

  //Girar

  //Velocidad
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  //Giro Derecha
  digitalWrite(IN2, LOW);

  //Giro Izquierda
  digitalWrite(IN4, LOW);

  delay(650);      //Por 0.5 segundos
}
