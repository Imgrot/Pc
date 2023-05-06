#include "lib.h"
#include <stdio.h>

int empezarMision(int coordenada_X_inicio, int coordenada_Y_inicio, int direccion){

	int zona[10][10];

	int x_actual;
	int y_actual;

	x_actual = (coordenada_X_inicio - 1);
	y_actual = (coordenada_Y_inicio - 1);

	int contador_tesoros = 0;

	if (direccion == 1){

		while (x_actual >=0 && x_actual <= 9 && y_actual >= 0 && y_actual <= 0){
			contador_tesoros = contador_tesoros + zona[x_actual][y_actual];
			x_actual--;
			y_actual--;
		}
	}
	
	if (direccion == 2){

		while (x_actual >=0 && x_actual <= 9 && y_actual >= 0 && y_actual <= 0){
			contador_tesoros = contador_tesoros + zona[x_actual][y_actual];
			y_actual--;
		}
	}
	
	if (direccion == 3){

		while (x_actual >=0 && x_actual <= 9 && y_actual >= 0 && y_actual <= 0){
			contador_tesoros = contador_tesoros + zona[x_actual][y_actual];
			x_actual++;
			y_actual--;
		}
	}
	
	if (direccion == 4){

		while (x_actual >=0 && x_actual <= 9 && y_actual >= 0 && y_actual <= 0){
			contador_tesoros = contador_tesoros + zona[x_actual][y_actual];
			x_actual--;
		}
	}
	
	if (direccion == 5){

		while (x_actual >=0 && x_actual <= 9 && y_actual >= 0 && y_actual <= 0){
			contador_tesoros = contador_tesoros + zona[x_actual][y_actual];
			x_actual++;
		}
	}
	
	if (direccion == 6){

		while (x_actual >=0 && x_actual <= 9 && y_actual >= 0 && y_actual <= 0){
			contador_tesoros = contador_tesoros + zona[x_actual][y_actual];
			x_actual--;
			y_actual++;
		}
	}
	
	if (direccion == 7){

		while (x_actual >=0 && x_actual <= 9 && y_actual >= 0 && y_actual <= 0){
			contador_tesoros = contador_tesoros + zona[x_actual][y_actual];
			y_actual++;
		}
	}
	
	if (direccion == 8){

		while (x_actual >=0 && x_actual <= 9 && y_actual >= 0 && y_actual <= 0){
			contador_tesoros = contador_tesoros + zona[x_actual][y_actual];
			x_actual++;
			y_actual++;
		}
	}


	return contador_tesoros;
}

int resultadosMision(int resultado, int repeticion){
printf("Su robot en %d misiones recaudo %d tesoros\n", resultado, repeticion);
return 0;
}
