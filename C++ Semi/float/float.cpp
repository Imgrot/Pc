#include <stdio.h>
float x,y,z;
int main(){
printf("Bienvenido al sistema de multiplicacion de numeros decimales\n");
printf("Digite un numero decimal\n");
scanf("%f", &x);
printf("Ahora digite el numero con el que se multiplicara ese numero:\n");
scanf("%f", &y);
z=x*y;
printf("El resultado de la multiplicacion de ambos numeros es:\n");
printf("--------------------------%f-------------------------\n", z);
printf("--------------------FIN DEL PROGRAMA-----------------\n");
return 0;
}
