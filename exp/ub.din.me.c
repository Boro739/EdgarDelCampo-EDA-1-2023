#include <string.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
    
    //setlocale(LC_ALL, ""); // para imprimir correctamente mensajes en español
    char name[100];
    char *description;
    strcpy(name, "Juanita");
    char Juanita[ ] = "Juanita es estudiante de la Facultad de Ingeniería";
    /* allocate memory dynamically */
    description = malloc(sizeof(Juanita));
    if( description == NULL ) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    } else {
        strcpy(description, Juanita) ;
    }
    printf("Name = %s\n", name );
    printf("Description: %s\n", description );
}