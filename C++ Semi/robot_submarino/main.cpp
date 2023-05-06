#include <stdio.h>
#include "lib.h"

int dir;
void coord();
int x, y;
int recoleccion=0;
int misiones=0;

int main(){

printf("cuantas misiones de robots desea enviar?\n");
scanf("%d", &misiones);


for(int i=0; i<misiones; i++){

printf("Elija las siguentes coordenadas en la que desea: (fila, columna)  1-10 \n");
scanf("%d,%d", &x,&y);

printf ("Ahora elija una direccion: \n \n");
printf("1		2		3 \n");
printf("    	     \n");
printf("		|  \n");
printf("		   \n");
printf("4	-	X	-	5 \n");
printf("    	  \n");
printf("		|  \n");
printf("    	    \n");
printf("6		7		8 \n \n");
scanf("%d", &dir);

recoleccion = recoleccion + empezarMision(x, y, dir);
}

resultadosMision(recoleccion, misiones);


return 0;
}

