#include <stdio.h>

int x,y;
int a=0;

int main(){
printf("Bienvenido al sistema de multiplicación por suma\n");
printf("Por favor ingresar el primer numero entero a multiplicar\n");
scanf("%d", &x);
printf("Ahora ingrese el segundo numero entero a multiplicar\n");
scanf("%d", &y);

a=y;

for(int i=1; i<x; i++){
a+=y;
}

printf("La multiplicacion de los numeros entregados es %d\n", a);
printf("--------/------FIN DE PROGRAMA------/-------\n");

return 0;
}
