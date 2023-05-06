//-------//Velocidad//-------//
byte ENA = A5;      //Izquierda
byte ENB = A6;      //Derecha

//-------//Control//-------//
byte IN1 = 7;      //Derecha
byte IN2 = 8;      //Derecha
byte IN3 = 9;      //Izquierda
byte IN4 = 10;     //Izquierda

//-------//Seguidor de Línea//-------//
int seguidor = A1;   //pin seguidor de linea
int valSg = 0;       //Almacenamiento del valor del seguidor

//-------//IR//-------//
#include <NECIRrcv.h>
#define IRPIN 11
NECIRrcv ir(IRPIN) ;

int signal = 0;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(seguidor, INPUT);
  Serial.begin(9600);
  Serial.println("NEC IR code reception") ;
  ir.begin() ;
}

void loop() {

  valSg = analogRead(seguidor);
  Serial.println(valSg);

  unsigned long ircode ;

  if (ir.available()) {
    ircode = ir.read() ;
    if (ircode == 0x6F905583) {
      signal++;
    }
  }

  while (signal > 0) {

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
  }

  if (valSg < 799) {

    //Giro Derecha

    digitalWrite(IN2, LOW);

    //Giro Izquierda
    digitalWrite(IN4, LOW);

    delay(300);
  }
}
