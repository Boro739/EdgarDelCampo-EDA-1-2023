#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
    int main() {
    setlocale(LC_ALL, ""); // para imprimir correctamente mensajes en español
    char name[100];
    char *description;
    strcpy(name, "Juanita Pérez");
    char Juanita[] = "Juanita es estudiante. ";
    /* allocate memory dynamically */
    description = malloc(sizeof(Juanita));
    if(description == NULL) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    } else {
        strcpy(description, Juanita);
    }
    /* suppose you want to store a bigger description */
    char Juanita2[ ] = "Estudia en la Facultad de Ingeniería.";
    description = realloc(description, sizeof(Juanita) + sizeof(Juanita2) );
    if(description == NULL) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    } else {
        strcat(description, Juanita2);
    }
    printf("Name = %s\n", name );
    printf("Description: %s\n", description );
    /* release memory using free() function */
    free(description);
    return 0;
    }