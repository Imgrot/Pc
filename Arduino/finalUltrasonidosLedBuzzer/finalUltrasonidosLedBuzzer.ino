//---------//Sensor de Proximidad//---------//
const int TRG = 13;        //Pin digital 2 para el Trigger del sensor
const int EC = 12;         //Pin digital 3 para el echo del sensor

//---------//LED//---------//
const int led_pin = 3;     //Pin del Led

//---------//Distancia de Ondas//---------//
int tiempo;                //Tiempo que tarda el ultrasonido en volver
int distancia;             //distancia recorrida por las ondas del sensor

//---------//Buzzer//---------//
const int pinBuzzer = A3;  //Pin del Buzzer
int esperaBuzzer;          //Tiempo de espera entre sonidos del buzzer

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

  long tiempo;                          //tiempo de retardo del eco
  long distancia;                          //distancia del objeto

  digitalWrite(TRG, HIGH);
  delayMicroseconds(10);           //pulso de 10us
  digitalWrite(TRG, LOW);

  tiempo = pulseIn(EC, HIGH);           //se mide el ancho del pulso
  distancia = tiempo / 59;                      //convcersion a cm

  if (distancia >= 10 && distancia <= 30) {
    esperaBuzzer = map(distancia, 10, 30, 50, 200);
  }
  
  else {
    esperaBuzzer = 0;
  }

//---------//---------//Tiempos del Buzzer//---------//---------//

  if (distancia < 10) {
    digitalWrite(led_pin, HIGH);
    tone(pinBuzzer, 2500);
  }

  if (distancia >= 10 && distancia <= 30) {
    digitalWrite(led_pin, LOW);
    tone(pinBuzzer, 2000);
    delay(esperaBuzzer);
    noTone(pinBuzzer);
  }

  if (distancia > 30) {
    digitalWrite(led_pin, LOW);
    noTone(pinBuzzer);
  }

  //---------//---------//Impresión de Distancia//---------//---------//

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println("cm");
  delay(50);

}
