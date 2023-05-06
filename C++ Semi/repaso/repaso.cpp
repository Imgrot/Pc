#include <stdio.h>
int  x, y, z;
int main (){
printf("Bienvenido al sistema de suma de numeros enteros\n");
printf("A continuacion, ingrese un numero:\n");
scanf("%d", &x);
printf("Ahora ingrese el segundo numero a sumar:\n");
scanf("%d", &y);
z = x + y;
printf("El resultado de la suma de sus numeros es:\n");
printf("---------------------- %d----------------------\n", z);
printf("----------------FIN DEL PROGRAMA---------------\n");

return 0;
}
