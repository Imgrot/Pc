#include <stdio.h>

int numero,resultado;
int factorial=1;

int main(){
printf("Bienvenido al sistema de obtencion de numeros factoriales\n");
printf("Ingrese un numero para ver su resultado factorial:\n");
scanf("%d", &numero);

for(int i=1; i<=numero; i++){
factorial*=i;
}

printf("%d factorial es igual a %d\n", numero, factorial);
printf("-------FIN DE PROGRAMA-------\n");
return 0;
}
