//-------//Velocidad//-------//
byte ENA = A4;      //Izquierda
byte ENB = A5;      //Derecha

//-------//Control//-------//
byte IN1 = 7;      //Derecha
byte IN2 = 8;      //Derecha
byte IN3 = 9;      //Izquierda
byte IN4 = 10;     //Izquierda

//-------//Seguidor de Línea//-------//
int seguidor = A2;   //pin seguidor de linea
int valSg = 0;       //Almacenamiento del valor del seguidor

//-------//Librería receptor IR//-------//
#include <NECIRrcv.h>
#define IRPIN 11
NECIRrcv ir(IRPIN) ;

int signal = 0;      //Contador de señales IR

//-------//-------//-------//-------//-------//-------//

void setup() {
  //-------//Velocidad Servos//-------//
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  //-------//Control servos//-------//
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(seguidor, INPUT);  //Definición del seguidor de línea
  Serial.begin(9600);
  Serial.println("NEC IR code reception") ;
  ir.begin() ;      //inicializar receptor IR
}

//-------//-------//-------//-------//-------//-------//

void loop() {

  valSg = analogRead(seguidor);      //almacenamiento del valor entregado por el seguidor de línea
  Serial.println(valSg);

  unsigned long ircode ;             //definición de la variable del receptor IR

  while (ir.available()) {           //verificación de si hay un botón pulsado
    ircode = ir.read() ;
  }

  if (ircode == 0x6F905583) {        //verificación del botón pulsado
    signal++;
  }

  if (signal > 0) {

    //Avanzar

    //Giro Derecha
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    //Giro Izquierda
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    
//poner pasos de seguidores aqui    <--    
        //Velocidad
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    
    
  }
}
