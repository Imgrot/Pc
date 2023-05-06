int x;
int y;

void setup() {
  Serial.begin(115200);
}

void loop() {
  x = random(0, 255);
  y = map(x, 0, 255, 0, 1024);

  Serial.print("El numero aleatorio es: ");
  Serial.println(x);

  Serial.print("El numero mapeado es: ");
  Serial.println(y);

  delay(1000);

}
