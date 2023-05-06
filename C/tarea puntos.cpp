#include <stdio.h>

int cant_prod, valor, precio_total, codigo;
char confirm_puntos;
int puntos= 0;
int puntos_totales = 0;

int main(){

printf("ingresar cantidad de productos\n");
scanf("%d", &cant_prod);

for(int i=0; i<cant_prod; i++){
printf("ingresar precio del producto %d\n", i+1);
scanf("%d", &valor);

printf("ingresar codigo de producto\n");
scanf("%d", &codigo);

printf("confirmacion de pago con puntos; y/n \n");
scanf("%c", &confirm_puntos);

if(confirm_puntos==121){
printf("ok\n");
}
else{
printf(":\n");
}
}
return 0;
}
