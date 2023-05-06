const int TRG = 13;             //Pin del Trigger del sensor
const int EC = 12;              //Pin del echo del sensor

void setup() {
  Serial.begin(9600);              //inicializar comunicación
  pinMode(TRG, OUTPUT);
  pinMode(EC, INPUT);
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
}
