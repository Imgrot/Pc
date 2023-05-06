//-------//Velocidad Motor//-------//
byte ENA = A5;                  //Izquierda
byte ENB = A6;                  //Derecha

//-------//Control Motor//-------//
byte IN1 = 7;                   //Derecha
byte IN2 = 8;                   //Derecha
byte IN3 = 9;                   //Izquierda
byte IN4 = 10;                  //Izquierda

//-------//Seguidor de Línea//-------//
int seguidor = A1;              //pin seguidor de linea
int valSg = 0;                  //Almacenamiento del valor del seguidor

//-------//Ultrasonido//-------//
const int TRG = 13;             //Pin del Trigger del sensor
const int EC = 12;              //Pin del echo del sensor

//-------//IR//-------//
#include <NECIRrcv.h>
#define IRPIN 4    // pin that IR detector is connected to
NECIRrcv ir(IRPIN);

int a = 0;

//----------------------------------------------------------------------------//
void setup() {

  //-------//Velocidad Motor//-------//
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  //-------//Control Motor//-------//
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //-------//Seguidor de Línea//-------//
  pinMode(TRG, OUTPUT);
  pinMode(EC, INPUT);

  //-------//IR//-------//
  ir.begin();

  digitalWrite(TRG, LOW);
  pinMode(seguidor, INPUT);
  Serial.begin(9600);
  Serial.println("NEC IR code reception");
}

//----------------------------------------------------------------------------//
void loop() {

  //Inicialización de la velocidad del motor
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  long t;                          //tiempo de retardo del eco
  long d;                          //distancia del objeto
  unsigned long ircode;

  digitalWrite(TRG, HIGH);
  delayMicroseconds(10);           //pulso de 10us
  digitalWrite(TRG, LOW);

  t = pulseIn(EC, HIGH);           //se mide el ancho del pulso
  d = t / 59;                      //convcersion a cm

  valSg = analogRead(seguidor);

  if (ir.available()) {

    ircode = ir.read() ;

    Serial.print("got code: 0x") ;
    Serial.println(ircode, HEX) ;

    while (a < 1) {


      while (valSg > 800) {              //En color blanco
        Serial.print("Color Blanco/");
        Serial.print(d);
        Serial.println("cm");

        while (d <= 40) {                 //Avanzar
          //Giro Derecha
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);

          //Giro Izquierda
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
        }

        while (d > 40) {            //Giro lado derecho

          //Girar en Circulos
          //Giro Derecha
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);

          //Giro Izquierda
          digitalWrite(IN4, LOW);
        }
      }

      if (valSg <= 800) {         //En color negro
        Serial.print("Color Negro/");
        Serial.print(d);
        Serial.println("cm");

        //Retroceder
        //Giro lado derecho
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);

        //Giro lado izquierdo
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);

        delay(200);
        //Girar
        //Giro Derecha
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);

        //Giro Izquierda
        digitalWrite(IN3, LOW);

        delay(150);
      }
    }
  }
}
