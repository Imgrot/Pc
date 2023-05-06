#include <stdio.h>
#define PI 3.14159
float radio, area, per;
int main(){
printf("Bienvenido al sistema de obtencion de:\n");
printf("Radio y Perimetro de una circunferencia\n");
printf("Ingrese el radio de su circunferencia:\n");
scanf("%f", &radio);
area=PI*radio*radio;
per=2*PI*radio;
printf("El area de su circulo es: %f\n", area);
printf("El perimetro de su circulo es: %f\n", per);
printf("-------FIN DEL PROGRAMA----------\n");

return 0;
}
