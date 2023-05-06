/* Universidad de La Frontera
* Ingeniería Civil Electrónica
*
* ICC-202 PROGRAMACION DE COMPUTADORES
*
* Tarea 1
*
* Autores: Oscar Millalonco Sarabia. (o.millalonco01@ufromail.cl)
* Eduardo Moraga Saez. (e.moraga03@ufromail.cl)
* Fecha:22/09/2019
*
* Programar juego conecta4, se debe inicializar una matriz de 6x7 que inicialize las casillas en O, este juego sera para 2 jugadores el jugador 1 sera R
* y el jugador 2 sera A. Se programara un menu con 3 opciones. El juego consiste en ingresar jugadas en la columna correspondiente hasta que estas se llenen
* el ganador sera aquel que conecte 4 fichas en forma vertical, horizontal o diagonal, si no se cumple esto en 42 turnos se producira un empate y se terminara el programa
*/

#include <stdio.h>
#include <stdlib.h>
//matriz
char tablero[6][7]= {{'O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O'}};

//entradas
int fila, columna;
int opcion;

//variables auxiliares
int resto;
int ganador;
int cierre=0;

int main(){
	while(cierre==0){
	printf("BIENVENIDO A CONECTA 4\n");    //desplegar menu
	printf("\n1.JUGAR");
	printf("\n2.INSTRUCCIONES");
	printf("\n3.SALIR\n");
	printf("Elija una opcion\n");
	scanf("%d", &opcion);
	while(opcion<1 || opcion>3){    //validar
	printf("Error Intente Nuevamente\n");
	printf("Elija una opcion\n");
	scanf("%d", &opcion);
	}
	switch(opcion){
	case 1:  //Jugar
	   //imprimir tablero
	for(int i=0;i<6;i++){//imprimir tablero 6x7
	for(int j=0; j<7; j++){
	printf("%c/", tablero[i][j]);
        }
    printf("\n");
    }
for(int z = 0; z<42;z++){//cuantas veces se ejecutaran las jugadas en este caso un tablero de 6x7 se haran un total de 42 veces
resto = z%2;//difenciador de turnos segun el resto en 0 y 1
if(resto==0){//jugador 1, juega cuando el resto de z es 0
fila=5;//fila vale 5 dependiendo de cada jugador es una variable que solo se aplica por cada turno
printf("Jugador 1, Ingrese la columna donde jugara\n");//pedir jugada
scanf("%d", &columna);
while(columna<1||columna>7){//validar que la jugada este dentro del rango del tablero
printf("Debe ingresar entre 1 y 7, intente nuevamente\n");
printf("Jugador 1, Ingrese la columna donde jugara\n");//pedir jugada nuevamente
scanf("%d", &columna);
}
while(tablero[fila-5][columna-1]=='R'||tablero[fila-5][columna-1]=='A'){//verificar si la columna se llena se pide la jugada nuevamente
printf("La columna ya esta llena intente con otra\n");
printf("Jugador 1, Ingrese la columna donde jugara\n");//pedir jugada nuevamente
scanf("%d", &columna);
while(columna<1||columna>7){//verificar que el valor ingresado es correcto
printf("Debe ingresar entre 1 y 7, intente nuevamente\n");
printf("Jugador 1, Ingrese la columna donde jugara\n");//pedir jugada nuevamente
scanf("%d", &columna);
}
}
while(tablero[fila][columna-1]=='R'|| tablero[fila][columna-1]=='A'){//si la casilla donde cae ya esta ocupada sube 1 espacio hacia arriba, esto se repite hasta que se llene
fila-=1;
}
tablero[fila][columna-1]='R';//fijar la jugada en la posicion
for(int i=0;i<6;i++){//imprimir tablero
	for(int j=0; j<7; j++){
	printf("%c/", tablero[i][j]);
}
printf("\n");
}
for(int d=0; d<6;d++){//verificar ganador en horizontal
for(int f=0;f<7-3;f++){
 if (tablero[d][f]=='R' && tablero[d][f+1]=='R' && tablero[d][f+2]=='R' && tablero[d][f+3]=='R')
        ganador=1;
}
}
for(int d=0;d<6-3;d++) {//verificar ganador vertical
      for(int f=0;f<7;f++) {
        if (tablero[d][f]=='R' && tablero[d+1][f]=='R' && tablero[d+2][f]=='R' && tablero[d+3][f]=='R')
          ganador=1;
    }
}
 for(int d=0;d<6;d++) {//verificar ganador diagonal1 ascendiente
      for(int f=0;f<7;f++) {
          if ((tablero[d][f]=='R' && tablero[d+1][f+1]=='R' && tablero[d+2][f+2]=='R' && tablero[d+3][f+3]=='R')){
            ganador=1;
    }
      }
    }
  for(int d=0;d<6;d++) {//verificar ganador diagonal2 descendiente
      for(int f=0;f<7;f++) {
          if ((tablero[d][f]=='R' && tablero[d+1][f-1]=='R' && tablero[d+2][f-2]=='R' && tablero[d+3][f-3]=='R')){
            ganador=1;
    }
      }
    }
if(ganador==1){
printf("El jugador 1 es el ganador\n");
return 0;
}
}//fin del jugador 1
if(resto==1){//jugador 2, juega cuando el resto de la division es 1
fila=5;//fila vale 5 dependiendo de cada jugador es una variable que solo se aplica por cada turno
printf("Jugador 2, Ingrese la columna donde jugara\n");//pedir jugada
scanf("%d", &columna);
while(columna<1||columna>7){//validar que la jugada este dentro del rango del tablero
printf("Debe ingresar entre 1 y 7, intente nuevamente\n");//pedir jugada nuevamente
printf("Jugador 2, Ingrese la columna donde jugara\n");
scanf("%d", &columna);
}
while(tablero[fila-5][columna-1]=='R'||tablero[fila-5][columna-1]=='A'){//si la columna se llena se pide la jugada nuevamente
printf("La columna ya esta llena intente con otra\n");
printf("Jugador 2, Ingrese la columna donde jugara\n");//pedir jugada nuevamente
scanf("%d", &columna);
while(columna<1||columna>7){//validar que la jugada este dentro del rango del tablero
printf("Debe ingresar entre 1 y 7, intente nuevamente\n");
printf("Jugador 2, Ingrese la columna donde jugara\n");//pedir jugada nuevamente
scanf("%d", &columna);
}
}
while(tablero[fila][columna-1]=='R'|| tablero[fila][columna-1]=='A'){//si la casilla donde cae ya esta ocupada sube 1 espacio hacia arriba, esto se repite hasta que se llene
fila-=1;
}
tablero[fila][columna-1]='A';//fijar la jugada en la posicion
	for(int i=0;i<6;i++){//imprimir tablero
	for(int j=0; j<7; j++){
	printf("%c/", tablero[i][j]);
}
printf("\n");
}
for(int d=0;d<7;d++) {//verificar ganador en horizontal
    for(int f=0;f<6-3;f++) {
      if (tablero[d][f]=='A' && tablero[d][f+1]=='A' && tablero[d][f+2]=='A' && tablero[d][f+3]=='A'){
        ganador=2;
}
	}
  }
  for(int d=0;d<6-3;d++) {//verificar ganador vertical
      for(int f=0;f<7;f++) {
        if (tablero[d][f]=='A' && tablero[d+1][f]=='A' && tablero[d+2][f]=='A' && tablero[d+3][f]=='A'){
          ganador=2;
}
	}
}
     for(int d=0;d<6;d++) {//verificar ganador diagonal1 ascendiente
      for(int f=0;f<7;f++) {
          if ((tablero[d][f]=='A' && tablero[d+1][f+1]=='A' && tablero[d+2][f+2]=='A' && tablero[d+3][f+3]=='A')){
            ganador=2;
        }
      }
    }
     for(int d=0;d<6;d++) {//verificador diagonal2 descendiete
      for(int f=0;f<7;f++) {
          if ((tablero[d][f]=='A' && tablero[d+1][f-1]=='A' && tablero[d+2][f-2]=='A' && tablero[d+3][f-3]=='A')){
            ganador=2;
        }
      }
    }
if(ganador==2){
printf("El jugador 2 es el ganador\n");
return 0;
}
}
if(z==41){//si se ejecutan los 42 turnos, empate y fin del programa
printf("Empate\n");
system("pause");
system("cls");
return 0;
}    //fin del jugador 2
}
break;
case 2://instrucciones
    printf("Instrucciones:\n El juego consiste en ingresar fichas a una columna y que esta caiga al fondo del tablero\n");
    printf("El ganador sera el jugador que logre conectar 4 fichas de forma vertical, horizontal o diagonal\n");
	break;
case 3://salir
	   cierre=1;
	   break;
}
}
return 0;
}
