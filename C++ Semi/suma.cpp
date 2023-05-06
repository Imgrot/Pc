#include <stdio.h>
int x,y,z;

int main(){

printf("Digite un numero:\n");
scanf("%i", &x);

printf("Digite otro numero:\n");
scanf("%i", &y);

z=x+y;

printf("La suma entre ambos es %i\n", z);
printf("FIN\n");

return 0;
}
