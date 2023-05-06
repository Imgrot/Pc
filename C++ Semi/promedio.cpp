#include <stdio.h>
float contwhile=0;
float numero, promedio, suma;

int main(){
printf("Bienvenido al sistema de obtencion de promedio ideal de numeros\n");
printf("Si desea de ingresar numeros, digite y envie un 0\n");
printf("Ingrese el numero inicial a obtener de promedio:\n");
scanf("%f", &numero);
suma = numero;

while(numero!=0){
printf("Ahora ingrese el siguiente:\n");
scanf("%f", &numero);
if(numero==0){
break;
}
suma+=numero;
contwhile++;
}

promedio=suma/(contwhile+1);

printf("El promedio de sus numeros es: %.3f\n", promedio);
printf("-----FIN DE PROGRAMA-----\n");
return 0;
}
