#include <stdio.h>
#include <stdlib.h>
 
long int vendedores, ventas, venta_nueva, continuacion;
long int contador=0, venta_mayor=0, excelente=0, bueno=0;
long int sueldo_menor=2147483647, sueldo=0;

int main(){

printf("Bienvenido al sistema de obtencion de datos de sueldo\n");
printf("Porfavor ingrese el numero de vendedores:\n");
scanf("%d", &vendedores);

while(vendedores<=0){
printf("Numero invalido\n");
printf("Porfavor ingrese el numero de vendedores:\n");
scanf("%d", &vendedores);
}

for (int i=1; i<=vendedores;i++){     		//FOR numero de vendedores
contador = 0;
sueldo=450000;
printf("Ahora ingrese el monto de la primera venta del vendedor %d:\n", i);
scanf("%d", &venta_nueva);

while(venta_nueva<10000 || venta_nueva>100000){     	//filtro de monto
venta_nueva=0;
printf("El monto ingresado invalido, porfavor ingrese un monto valido\n");
scanf("%d", &venta_nueva);
}

if(venta_nueva>venta_mayor){    	//Verificador de venta mayor
venta_mayor=venta_nueva;
}
ventas = venta_nueva;
contador++;

printf("El vendedor %d hizo otra venta mas?: 1 = si / 2 = no\n", i);      	//confirmacion de mas ventas
scanf("%d", &continuacion);

while(continuacion!=1 && continuacion!=2){              	//filtro de opciones de ventas
printf("Opcion invalida, por favor indique de nuevo\n");
printf("El vendedor %d hizo otra venta mas?: 1 = si / 2 = no\n", i);      	//confirmacion de mas ventas
scanf("%d", &continuacion);
}

if(continuacion==1){

//WHILE digitacion de ventas
while(ventas>=10000){   			
printf("ahora ingrese la siguiente:\n");
scanf("%d", &venta_nueva);

while(venta_nueva<10000 || venta_nueva>100000){        	//filtro de monto
venta_nueva=0;
printf("El monto ingresado invalido, porfavor ingrese un monto valido\n");
scanf("%d", &venta_nueva);
}

if(venta_nueva>venta_mayor){		//Verificador de venta mayor
venta_mayor=venta_nueva;
}

ventas+=venta_nueva;
contador++;

printf("El vendedor %d hizo otra venta mas?: 1 = si / 2 = no\n", i);     	//confirmacion de mas ventas
scanf("%d", &continuacion);

while(continuacion!=1 && continuacion!=2){              	//filtro de opciones de ventas
printf("Opcion invalida, por favor indique de nuevo\n");
printf("El vendedor %d hizo otra venta mas?: 1 = si / 2 = no\n", i);     	//confirmacion de mas ventas
scanf("%d", &continuacion);
}

if(continuacion==2){
break;
}
}
//Fin WHILE digitacion de ventas
}

//inicio calculo de sueldo
if(ventas>=100000 && ventas<250000){
sueldo=sueldo+(ventas*0.03);
}
if(ventas>=100000 && ventas<400000){
sueldo=sueldo+(ventas*0.07);
bueno++;
}
if(ventas>=400000){
sueldo=sueldo+(ventas*0.15);
excelente++;
}

sueldo-=(sueldo*0.17);
//Fin del calculo de sueldo

if(sueldo<=sueldo_menor){
sueldo_menor=sueldo;
}

system("cls");
printf("El vendedor %d:\n", i);
printf("Vendio %d\n", ventas);
printf("Hizo %d Ventas\n", contador);

if(ventas<100000){
printf("Su cumplimiento fue deficiente...\n");
}
if(ventas>=100000 && ventas<250000){
printf("Su cumplimiento fue regular\n");
}
if(ventas>=250000 && ventas<400000){
printf("Su cumplimiento fue bueno\n");
}
if(ventas>=400000){
printf("Su cumplimiento fue excelente\n");
}

printf("Su sueldo final es: %d\n",sueldo);
system("pause");
system("cls");
}       	//Fin FOR vendedores

printf("La mayor venta individual realizada fue de: %d\n", venta_mayor);
printf("El sueldo menor pagado fue de %d\n", sueldo_menor);
printf("La cantidad de empleados que quedaron en la categoria de cumplimiento *Bueno* fue de: %d\n", bueno);
printf("La cantidad de empleados que quedaron en la categoria de cumplimiento *Excelente* fue de: %d\n", excelente);
system("pause");
system("cls");
printf("Gracias por usar nuestro sistema, agradecemos su preferencia\n");
printf("--------FIN DEL PROGRAMA--------\n");
return 0;
}
