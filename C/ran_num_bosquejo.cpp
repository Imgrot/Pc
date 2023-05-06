#include <stdio.h>
#include <stdlib.h>
#include<time.h>


int nivel;
int contador = 0;

//Tus Numeros
int num1_1;
int num2_1;
int num3_1;
int num4_1;
int num5_1;

//Numeros PC
int num1_2;
int num2_2;
int num3_2;
int num4_2;
int num5_2;

void dificultad();
void pedirNumeroUser();
void generarNumeroPC();


int main (){
dificultad();
generarNumeroPC();
pedirNumeroUser();
return 0;
}


void dificultad(){
printf("Elija una dificultad /2-5/\n");
scanf("%d", &nivel);

while(nivel<2 || nivel>5){
system("cls");
printf("Dificultad invalida, por favor elija una dificultad existente /2-5/\n");
scanf("%d", &nivel);
}
system("cls");
if(nivel==2){
printf("Nivel de Dificultad 2 elegido\n");
}
if(nivel==3){
printf("Nivel de Dificultad 3 elegido\n");
}
if(nivel==4){
printf("Nivel de Dificultad 4 elegido\n");
}
if(nivel==5){
printf("Nivel de Dificultad 5 elegido\n");
}
}
void generarNumeroPC(){
srand(time(NULL));

if(nivel == 2){

num1_2=1+rand()%(10-1);
num2_2=1+rand()%(10-1);

while(num1_2 == num2_2){
num1_2=1+rand()%(10-1);
num2_2=1+rand()%(10-1);
}
}

if(nivel == 3){
num1_2=1+rand()%(10-1);
num2_2=1+rand()%(10-1);
num3_2=1+rand()%(10-1);

while((num1_2 == num2_2) || (num1_2 == num3_2) || (num2_2 == num3_2)){
num1_2=1+rand()%(10-1);
num2_2=1+rand()%(10-1);
num3_2=1+rand()%(10-1);
}
}

if(nivel == 4){
num1_2=1+rand()%(10-1);
num2_2=1+rand()%(10-1);
num3_2=1+rand()%(10-1);
num4_2=1+rand()%(10-1);

while((num1_2 == num2_2) || (num1_2 == num3_2) || (num1_2 == num4_2) || (num2_2 == num3_2) || (num2_2 == num4_2) || (num3_2 == num4_2)){
num1_2=1+rand()%(10-1);
num2_2=1+rand()%(10-1);
num3_2=1+rand()%(10-1);
num4_2=1+rand()%(10-1);
}
}

if(nivel == 5){

num1_2=1+rand()%(10-1);
num2_2=1+rand()%(10-1);
num3_2=1+rand()%(10-1);
num4_2=1+rand()%(10-1);
num5_2=1+rand()%(10-1);

while((num1_2 == num2_2) || (num1_2 == num3_2) || (num1_2 == num4_2) || (num2_2 == num3_2) || (num2_2 == num4_2) || (num3_2 == num4_2) || (num5_2 == num4_2) || (num5_2 == num3_2) || (num5_2 == num2_2) || (num5_2 == num1_2)){
num1_2=1+rand()%(10-1);
num2_2=1+rand()%(10-1);
num3_2=1+rand()%(10-1);
num4_2=1+rand()%(10-1);
num5_2=1+rand()%(10-1);
}
}

}


void pedirNumeroUser(){

if(nivel == 2){
	while(nivel == 2){
		printf("Ingrese la primera cifra de su numero\n");	//1a cifra
		scanf("%d", &num1_1);
		system("cls");
		while(num1_1>9 || num1_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num1_1);
			system("cls");
		}
		printf("Ahora ingrese la siguiente cifra\n");		//2a cifra
		scanf("%d", &num2_1);
		system("cls");
		while(num2_1>9 || num2_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num2_1);
			system("cls");
		}
		if(!(num1_1 == num2_1)){
			printf("Su numero es:\n");
			printf("%d", num1_1);
			printf("%d\n", num2_1);
			system("pause");
			break;
		}
		printf("Los Numeros se repiten...\n");
		printf("Recuerde que ningun numero puede repetirse\n");
		printf("Intentelo de nuevo\n");
		system("pause");
		system("cls");
		}
	system("cls");
}

if(nivel == 3){
	while(nivel == 3){
		printf("Ingrese la primera cifra de su numero\n");	//1a cifra
		scanf("%d", &num1_1);
		system("cls");
		while(num1_1>9 || num1_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num1_1);
			system("cls");
		}
		printf("Ahora ingrese la siguiente cifra\n");		//2a cifra
		scanf("%d", &num2_1);
		system("cls");
		while(num2_1>9 || num2_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num2_1);
			system("cls");
		}
		printf("Ahora ingrese la siguiente cifra\n");		//3a cifra
		scanf("%d", &num3_1);
		system("cls");
			while(num3_1>9 || num3_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num3_1);
			system("cls");
		}
		if(!((num1_1 == num2_1) || (num1_1 == num3_1) || (num2_1 == num3_1))){
			printf("Su numero es:\n");
			printf("%d", num1_1);
			printf("%d", num2_1);
			printf("%d\n", num3_1);
			system("pause");
			break;
		}
		printf("2 o mas numeros se repiten...\n");
		printf("Recuerde que ningun numero puede repetirse\n");
		printf("Intentelo de nuevo\n");
		system("pause");
		system("cls");
	}
	system("cls");
}

if(nivel == 4){
	while(nivel == 4){
		printf("Ingrese la primera cifra de su numero\n");	//1a cifra
		scanf("%d", &num1_1);
		system("cls");
		while(num1_1>9 || num1_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num1_1);
			system("cls");
		}
		printf("Ahora ingrese la siguiente cifra\n");		//2a cifra
		scanf("%d", &num2_1);
		system("cls");
		while(num2_1>9 || num2_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num2_1);
			system("cls");
		}
		printf("Ahora ingrese la siguiente cifra\n");		//3a cifra
		scanf("%d", &num3_1);
		system("cls");
			while(num3_1>9 || num3_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num3_1);
			system("cls");
		}
		printf("Ahora ingrese la siguiente cifra\n");		//4a cifra
		scanf("%d", &num4_1);
		system("cls");
		while(num4_1>9 || num4_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num4_1);
			system("cls");
		}
		if(!((num1_1 == num2_1) || (num1_1 == num3_1) || (num1_1 == num4_1) || (num2_1 == num3_1) || (num2_1 == num4_1) || (num3_1 == num4_1))){
			printf("Su numero es:\n");
			printf("%d", num1_1);
			printf("%d", num2_1);
			printf("%d", num3_1);
			printf("%d\n", num4_1);
			system("pause");
			break;
		}
	printf("2 o mas numeros se repiten...\n");
	printf("Recuerde que ningun numero puede repetirse\n");
	printf("Intentelo de nuevo\n");
	system("pause");
	system("cls");
	}
	system("cls");
}

if(nivel == 5){
	while(nivel == 5){
		printf("Ingrese la primera cifra de su numero\n");	//1a cifra
		scanf("%d", &num1_1);
		system("cls");
		while(num1_1>9 || num1_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num1_1);
			system("cls");
		}
		printf("Ahora ingrese la siguiente cifra\n");		//2a cifra
		scanf("%d", &num2_1);
		system("cls");
		while(num2_1>9 || num2_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num2_1);
			system("cls");
		}
		printf("Ahora ingrese la siguiente cifra\n");		//3a cifra
		scanf("%d", &num3_1);
		system("cls");
		while(num3_1>9 || num3_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num3_1);
			system("cls");
		}
		printf("Ahora ingrese la siguiente cifra\n");		//4a cifra
		scanf("%d", &num4_1);
		system("cls");
		while(num4_1>9 || num4_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num4_1);
			system("cls");
		}
		printf("Ahora ingrese la siguiente cifra\n");		//5a cifra
		scanf("%d", &num5_1);
		system("cls");
		while(num5_1>9 || num5_1<0){
			printf("Cifra invalida, ingrese de nuevo\n");
			scanf("%d", &num5_1);
			system("cls");
		}
		if(!((num1_1 == num2_1) || (num1_1 == num3_1) || (num1_1 == num4_1) || (num2_1 == num3_1) || (num2_1 == num4_1) || (num3_1 == num4_1) || (num5_1 == num4_1) || (num5_1 == num3_1) || (num5_1 == num2_1) || (num5_1 == num1_1))){
			printf("Su numero es:\n");
			printf("%d", num1_1);
			printf("%d", num2_1);
			printf("%d", num3_1);
			printf("%d", num4_1);
			printf("%d\n", num5_1);
				system("pause");
			break;
		}
		printf("2 o mas numeros se repiten...\n");
		printf("Recuerde que ningun numero puede repetirse\n");
		printf("Intentelo de nuevo\n");
		system("pause");
		system("cls");
	}
	system("cls");
}
}
