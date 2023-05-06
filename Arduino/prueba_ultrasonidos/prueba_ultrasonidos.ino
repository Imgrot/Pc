const int TRG = 13;   //Pin digital 2 para el Trigger del sensor
const int EC = 12;   //Pin digital 3 para el echo del sensor
int t;
int d;

void setup() {
  Serial.begin(9600);              //inicializar comunicación
  pinMode(TRG, OUTPUT);
  pinMode(EC, INPUT);
  digitalWrite(TRG, LOW);      //Inicializar pin de trigger en 0
}

void loop() {

  long t;                          //tiempo de retardo del eco
  long d;                          //distancia del objeto

  digitalWrite(TRG, HIGH);
  delayMicroseconds(10);           //pulso de 10us
  digitalWrite(TRG, LOW);

  t = pulseIn(EC, HIGH);           //se mide el ancho del pulso
  d = t / 59;                      //convcersion a cm


  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.print("cm");
  Serial.println();
  delay(100);
  
}
