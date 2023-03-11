#include <stdio.h>
/*
Este programa crea un apuntador de tipo entero
que apunta al inicio de un arreglo.

int main () {
short arr[5], *apArr;
apArr = &arr[0];
// imprime la dirección de memoria del arreglo en la posición [0]
printf("Dirección del arreglo en la primera posición: %x\n",&arr[0]);
// imprime la dirección de memoria del arreglo
// (el nombre del arreglo es un apuntador)
printf("Dirección del arreglo: %x\n",&arr);
// imprime la dirección de memoria del apuntador apArr
printf("Dirección del apuntador: %x\n",apArr);
return 0;
}*/

/*
void pasarValor(int);
void pasarReferencia(int *);
int main(){
int nums[] = {55,44,33,22,11};
int *ap, cont;
ap = nums;
printf("Pasar valor: %d\n", *ap);
pasarValor(*ap);
printf("Pasar referencia: %d\n", *ap);
pasarReferencia(ap);
printf("Valor final: %d\n", *ap);
return 0;
}
void pasarValor(int equis){
printf("%d\n", equis);
equis = 128;
printf("%d\n", equis);
}
void pasarReferencia(int *equis){
printf("%d\n", *equis);
*equis = 128;
printf("%d\n", *equis);
}*/
/*
Se imprimen 3 valores de un arreglo a través
de aritmética de direcciones.
int main () {
short arr[5] = {91,28,73,46,55};
short *apArr;
apArr = arr;
// apunta al inicio del arreglo
printf("*apArr = %i\n",*apArr);
// suma una localidad al inicio del arreglo e imprime su valor
printf("*(apArr+1) = %i\n",*(apArr+1));
printf("*(apArr+2) = %i\n",*(apArr+2));
return 0;
}*/
/*
int main(){
short nums[] = {55,44,33,22,11};
short *ap, cont;
ap = nums;
for (cont = 0; cont < 5 ; cont++)
printf("%x\n",(ap+cont));
return 0;
}*/

/*
Se recorre un arreglo bidimensional a través de un apuntador
*/
int main(){
int *ap, indice;
int nums[3][3] = {{99,88,77},
{66,55,44},
{33,22,11}};
ap = nums;
for (indice = 0; indice < 9 ; indice++){
if ((indice%3)==0)
printf("\n");
printf("%x\t",(ap+indice));
}
return 0;
}
