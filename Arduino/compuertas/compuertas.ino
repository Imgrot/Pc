//--------------// PINES //--------------//

//Pulsadores
int puls_pin_1 = 12; //mustra el estado/valor del pin del pulsador 1
int puls_pin_2 = 11; //mustra el estado/valor del pin del pulsador 2

//Entradas RGB
int RGB_ROJO = 7;
int RGB_VERDE = 6;
int RGB_AZUL = 5;

//Potenciometro
int pot_pin = A2;   //mustra el estado/valor del pin del potenciometro

//--------------// ALMACENAMIENTO //--------------//

//Potenciometro
int pot_valor = 0;  //almacena el valor del potenciometro

//Pulsadores
int puls_valor_1 = 0; //almacena el valor del pulsador 1
int puls_valor_2 = 0; //almacena el valor del pulsador 2


//--------------//--------------//--------------//--------------//--------------//

void setup() {

  //CONFIG. Pulsadores
  pinMode (puls_pin_1, INPUT_PULLUP);
  pinMode (puls_pin_2, INPUT_PULLUP);

  //CONFIG. RGB
  pinMode (RGB_ROJO, OUTPUT);
  pinMode (RGB_ROJO, OUTPUT);
  pinMode (RGB_ROJO, OUTPUT);

  //CONFIG. Potenciometro
  pinMode (pot_pin, INPUT);

  Serial.begin(9600);

}

//--------------//--------------//--------------//--------------//--------------//

void loop() {

  pot_valor = analogRead(pot_pin);

  puls_valor_1 = analogRead(puls_pin_1);
  puls_valor_2 = analogRead(puls_pin_2);


  //--------------// AND  //--------------//
  if (pot_valor >= 0 && pot_valor <= 204) {
   Serial.println("Estado pulsadores = " + String(puls_valor_1) + "," + String(puls_valor_2) + "/Estado Pot. = " + String(pot_valor) + "/Compuerta AND");
    if (puls_valor_1 == 0 && puls_valor_2 == 0) {
      digitalWrite(RGB_ROJO, 0);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 == 0 && puls_valor_2 == 1) {
      digitalWrite(RGB_ROJO, 0);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 == 1 && puls_valor_2 == 0) {
      digitalWrite(RGB_ROJO, 0);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 == 1 && puls_valor_2 == 1) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }
  }

  //--------------// OR //--------------//
  if (pot_valor > 204 && pot_valor <= 408) {
   Serial.println("Estado pulsadores = "puls_valor 1"," puls_valor_2"/Estado Pot. = "pot_valor"/Compuerta OR");
    if (puls_valor_1 == 0 && puls_valor_2 == 0) {
      digitalWrite(RGB_ROJO, 0);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 0);
    }

    else if (puls_valor_1 == 0 && puls_valor_2 == 1) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 = 1 && puls_valor_2 == 0) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 == 1 && puls_valor_2 == 1) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }
  }

  //--------------// NAND //--------------//
  if (pot_valor > 408 && pot_valor <= 612) {
   Serial.println("Estado pulsadores = "puls_valor 1"," puls_valor_2"/Estado Pot. = "pot_valor"/Compuerta NAND");
    if (puls_valor_1 == 0 && puls_valor_2 == 0) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 == 0 && puls_valor_2 == 1) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 == 1 && puls_valor_2 == 0) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 == 1 && puls_valor_2 == 1) {
      digitalWrite(RGB_ROJO, 12);
      digitalWrite(RGB_VERDE, 0);
      digitalWrite(RGB_AZUL, 255);
    }
  }

  //--------------// NOR //--------------//
  if (pot_valor > 612 && pot_valor <= 816) {
   Serial.println("Estado pulsadores = "puls_valor 1"," puls_valor_2"/Estado Pot. = "pot_valor"/Compuerta NOR");
    if (puls_valor_1 == 0 && puls_valor_2 == 0) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 == 0 && puls_valor_2 == 1) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 0);
    }

    else if (puls_valor_1 == 1 && puls_valor_2 == 0) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 == 1 && puls_valor_2 == 1) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }
  }

  //--------------// XOR //--------------//
  if (pot_valor > 816 && pot_valor <= 1024) {
   Serial.println("Estado pulsadores = "puls_valor_1"," puls_valor_2"/Estado Pot. = "pot_valor"/Compuerta XOR");
    if (puls_valor_1 == 0 && puls_valor_2 == 0) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 0);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 == 0 && puls_valor_2 == 1) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 == 1 && puls_valor_2 == 0) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 255);
      digitalWrite(RGB_AZUL, 255);
    }

    else if (puls_valor_1 == 1 && puls_valor_2 == 1) {
      digitalWrite(RGB_ROJO, 255);
      digitalWrite(RGB_VERDE, 0);
      digitalWrite(RGB_AZUL, 255);
    }
  }
}
