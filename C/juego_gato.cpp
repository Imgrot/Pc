#include <stdio.h>
#include <stdlib.h>
int turno=9, resto, fila, columna, victoria, opcion, p1=0, p2=0;

int main(){

char gato[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};

printf("Bienvenido al juego del\n");
printf("            /       /\n");
printf("           /       /\n");
printf("      / / / / / / / / /\n");
printf("         /       /\n");
printf("        /       /\n");
printf("   / / / / / / / / /\n");
printf("      /       /\n");
printf("     /       /\n");
printf("(gato)\n");
printf("Tipico Chileno\n");

system("pause");
system("cls");

printf("\n1.Jugar");
printf("\n2.Instrucciones");
printf("\n3.Salir\n");
printf("Elija una opcion\n");
scanf("%d", &opcion);

while(opcion<1 || opcion>3){
printf("Opcion invalida\n");
printf("Elija una opcion\n");
scanf("%d", &opcion);
}
system("cls");

if(opcion==1){

for(int turn=1;turn<=turno;turn++){
resto=turn%2;

printf("| 1 | 2 | 3 |\n\n");
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
printf("/ %c ", gato[i][j]);
}
printf("/  | %d |\n", i+1);
}
printf("\n");

if(resto==1){
printf("-------------------------\n");
printf("Turno del Jugador 1 (X)\n");
printf("Ingrese su jugada en forma Fila,Columna:\n");
scanf("%d,%d", &fila, &columna);


while(gato[(fila-1)][(columna-1)]!='-' || fila<1 || fila>3 || columna<1 || columna>3){
printf("Casilla Invalida o ya ocupada\n");
printf("Ingrese su jugada en forma Fila,Columna:\n");
scanf("%d,%d", &fila, &columna);
}
gato[(fila-1)][(columna-1)]='X';
}

if(resto==0){
printf("-------------------------\n");
printf("Turno del Jugador 2 (O)\n");
printf("-------------------------\n");
printf("Ingrese su jugada en forma Fila,Columna:\n");
scanf("%d,%d", &fila, &columna);

while(gato[(fila-1)][(columna-1)]!='-' || fila<1 || fila>3 || columna<1 || columna>3){
printf("Casilla Invalida o ya ocupada\n");
printf("Ingrese su jugada en forma Fila,Columna:\n");
scanf("%d,%d", &fila, &columna);
}
gato[(fila-1)][(columna-1)]='O';
}
printf("--------------------------\n");
 //comienzo de verificacion de ganador
for(int i=0;i<3;i++){  //victoria horizontal
if(gato[i][0]==gato[i][1] && gato[i][1]==gato[i][2] && gato[i][0]!='-'){
victoria++;
break;
}
}
for(int j=0;j<3;j++){  //victoria vertical
if(gato[0][j]==gato[1][j] && gato[1][j]==gato[2][j] && gato[0][j]!='-'){
victoria++;
break;
}
}
//victoria vertical ascendente
if(gato[0][0]==gato[1][1] && gato[1][1]==gato[2][2] && gato[0][0]!='-'){
victoria++;
}
 //victoria verical descencente
if(gato[1][3]==gato[2][2] && gato[2][2]==gato[3][1] && gato[1][3]!='-'){
victoria++;
}
if(victoria!=0){
break;
}
system("cls");
}    //fin for
system("cls");

printf("| 1 | 2 | 3 |\n\n");
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
printf("/ %c ", gato[i][j]);
}
printf("/  | %d |\n", i+1);
}
if(resto==1){
printf("Victoria del Jugador 1 :D\n");
}
if(resto==0){
printf("Victoria del Jugador 2 :D\n");
}
}    //fin jugar

if(opcion==2){
printf("Cada jugador consta de cuatro o 5 movidas, dependiendo de quien haya empezado.\n");
printf("El objetivo final del juego es intentar juntar 3 de tus fichas en linea\n");
printf("mientras intentas que tu rival no lo haga. EL primero en juntar 3 fichas\n");
printf("en linea, gana\n");
}

if(opcion==3){
printf("Gracias por preferir nuestro programa\n");
exit(-1);
}

return 0;
}

