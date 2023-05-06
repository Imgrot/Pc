const int TRG = 13;             //Pin del Trigger del sensor
const int EC = 12;              //Pin del echo del sensor
const int led_pin = 3;          //Pin del led
const int buzzer = 17;          //Pin del buzzer

void setup() {
  Serial.begin(9600);              //inicializar comunicación
  pinMode(TRG, OUTPUT);
  pinMode(EC, INPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(TRG, LOW);      //Inicializar pin de trigger en 0
}

void loop() {

  delay(50);

  long t;                          //tiempo de retardo del eco
  long d;                          //distancia del objeto

  digitalWrite(TRG, HIGH);
  delayMicroseconds(10);           //pulso de 10us
  digitalWrite(TRG, LOW);

  t = pulseIn(EC, HIGH);           //se mide el ancho del pulso
  d = t / 59;                      //convcersion a cm

  Serial.print(d);
  Serial.println("cm");

  if (d < 10) {
    analogWrite(led_pin, 255);
    tone(buzzer, 600);          //activa la frecuencia del buzzer
  }

  else if (d >= 10 && d <= 30) {
    analogWrite(led_pin, 100);
    tone(buzzer, 300);          //activa la frecuencia del buzzer
  }

  else {
    analogWrite(led_pin, 0);
    noTone(buzzer);
  }
}
