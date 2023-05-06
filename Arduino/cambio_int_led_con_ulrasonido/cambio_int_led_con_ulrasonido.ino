//---------//Sensor de Proximidad//---------//
const int TRG = 13;   //Pin digital 2 para el Trigger del sensor
const int EC = 12;    //Pin digital 3 para el echo del sensor

//---------//LED//---------//
int led_pin = 3;     //Pin del Led
int led_equiv;        //Equivalencia del valor del led en base a la distancia

//---------//Distancia de Ondas//---------//
int tiempo;           //Tiempo que tarda el ultrasonido en volver
int distancia;        //distancia recorrida por las ondas del sensor

//---------//---------//---------//---------//---------//---------//---------//

void setup() {
  Serial.begin(9600);              //inicializar comunicación
  pinMode(TRG, OUTPUT);
  pinMode(EC, INPUT);
  pinMode(led_pin, OUTPUT);
  digitalWrite(TRG, LOW);      //Inicializar pin de trigger en 0
}

//---------//---------//---------//---------//---------//---------//---------//

void loop() {

  long tiempo;                                      //tiempo de retardo del eco
  long distancia;                                   //distancia del objeto

  digitalWrite(TRG, HIGH);
  delayMicroseconds(10);                            //pulso de 10us
  digitalWrite(TRG, LOW);

  tiempo = pulseIn(EC, HIGH);                       //se mide el ancho del pulso
  distancia = tiempo / 59;                          //convcersion a cm

  led_equiv = map(distancia, 10, 30, 254, 1);       //conversion de datos a una escala distinta

  if (distancia < 10) {                             //led dencendido
    analogWrite(led_pin, 255);
  }

  if (distancia >= 10 && distancia <= 30) {         //variacion de intensidad del led
    analogWrite(led_pin, led_equiv);
  }

  if (distancia > 30) {                             //led apagado
    analogWrite(led_pin, 0);
  }

//---------//---------//Impresión de Distancia//---------//---------//

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println("cm");
  delay(50);

}
