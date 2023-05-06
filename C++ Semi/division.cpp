#include <stdio.h>

int x,y,b;
int a=0;

int main(){
printf("Bienvenido al sistema de division por resta\n");
printf("Por favor ingresar el primer numero entero a dividirse\n");
scanf("%d", &x);

printf("Ahora ingrese el denominador\n");
scanf("%d", &y);

while(y==0){
printf("Error, ingrese otro denominador\n");
scanf("%d", &y);
}			//fin while

a=y;

for(int i=1; i<x; i++){
a+=y;
b=i;
if(x<a){		//si el denominador es mayor que el numerador, se termina
break;
}
}			//fin for

printf("%d cabe %d veces en %d\n", y, b, x);
printf("--------/------FIN DE PROGRAMA------/-------\n");

return 0;
}
