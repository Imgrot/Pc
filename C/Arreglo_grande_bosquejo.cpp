#include <stdio.h>
#include <stdlib.h>

int n = 0;       		    //almacenamiento del tamaño del arreglo (nombre de acuerdo a el enunciado de la tarea)
int num_deseado;        	//número que se desea buscar
int valor = 0;              //almacenamiento de datos extra
int contador_num = 0;       //contador de valores encontrados

/* A continuación, las X se reemplazarán por el arreglo y las Y por el tamaño del arreglo*/

void iniciar_arreglo();
void llenarArreglo(int* x, int y);
void imprimirArreglo(int* x, int y);
void leerValor();
void buscarValor();

int main(){
	iniciar_arreglo();
	int arreglo[n];

	llenarArreglo(&arreglo[0], n);
	imprimirArreglo(&arreglo[0], n);
	leerValor();
	buscarValor(&arreglo[0], n);

	return 0;
}

void iniciar_arreglo(){
	printf("Defina la cantidad de datos que desea ingresar en el arreglo: (>1)\n");
	scanf("%d", &n);
	system("cls");

	while (n<1 || n>100){
		printf("Dato ingresado invalido, porfavor ingrese uno valido  (>1)\n");
		scanf("%d", &n);
		system("cls");
	}
}

void llenarArreglo(int* x, int y){
	for(int i=1;i<=y;i++){
		printf("Ingrese el dato numero %d: \n", i);
		scanf("%d", &valor);
		system("cls");

		while(valor<1 || valor>100){
			printf("Dato ingresado invalido, porfavor ingrese uno valido  (>1)\n");
			scanf("%d", &valor);
			system("cls");
		}
		x[(i-1)] = valor;
	}
}

void imprimirArreglo(int* x, int y){
	int casilla;
	printf("Los numeros elegidos para su arreglo son:\n");
	for(int i=0; i<y;i++){
		casilla = x[i];
		printf("/ %d /", casilla);
	}
	printf("\n");
	system("pause");
	system("cls");
}

void leerValor(){
	printf("Que valor desea buscar entre los que dicto en su arreglo?  :  \n");
	scanf("%d", &num_deseado);
	system("cls");
	printf("El valor que desea buscar es el numero %d\n", num_deseado);
	system("pause");
}

void buscarValor(int* x, int y){
	printf("---Escaneando los valores---\n");
	system("pause");
	for(int i=0;i<n;i++){
		if(*x[i] == num_deseado){
			contador_num++;
		}
	}
}
