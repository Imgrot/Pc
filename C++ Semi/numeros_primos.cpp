#include <stdio.h>

int contador, numero, primo;

int main(){

printf("Bienvenido al sistema de obtencion de numeros primos:\n");
printf("Ingrese un numero mayor que 2 para saber que \n numeros entre el 2 y su numero son primos\n");
scanf("%d", &numero);

for(int i=2; i<numero; i++){
contador = 0;
primo = i;

for(int y=2; y<i; y++){
if((i%y)==0){
contador++;
break;
}
}	//for y

if(contador==0){
printf("%d\n", primo);
}

}	//for numero
printf("Estos son los numeros primos entre 2 y su numero\n");
return 0;
}
