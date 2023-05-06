#include <stdio.h>

int n1=0, n2=1, suma, num;

int main(){
printf("Bienvenido al sistema de muestra de la secuencia de fibonacci\n");
printf("Ingrese el numero de la secuencia de fibonacci que desee saber:\n");
scanf("%d", &num);
if(num==1){
printf("El numero 1 de la secuencia es: 0\n");
}
if(num==2){
printf("El numero 2 de la secuencia es: 1\n");
}
if(num>=3){
for(int i=0;i<num;i++){
suma = n1+n2;
n1=n2;
n2=suma;
}
printf("El numero %d de la secuencia es: %d\n", num, suma);
}
printf("-----FIN DEL PROGRAMA-----\n");
return 0;
}
