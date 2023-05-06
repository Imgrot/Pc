#include <stdio.h>
int x;
char y;

int main(){
printf("Bienvenido al programa de revelado de codigo\n");
printf("Con este programa puede ver cual es el codigo ASCII de cada caracter\n");
printf("Ingrese un caracter(letra):\n");
scanf("%c", &y);
x = 0 + y;
printf("El codigo ASCII de ese caracter es: %d\n", x);
printf("-----------FIN DEL PROGRAMA-------------\n");

return 0;
}
