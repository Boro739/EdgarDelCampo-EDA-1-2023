#include<stdio.h>

void crearMensaje();
void decifrarMensaje();

int main() {
    short option=0;

    while (1){
        printf("\n\t*** ESCITALA ESPARTANA ***\n");
        print("¿Que desea realizar?ªn");
        printf("1) Crear mensaje cifrado. \n");
        printf("2) Decifrar mensaje. \n");
        printf("3) Salir. \n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                crearMensaje();
                break;
            case 2:
                decifrarMensaje();
                break;
            case 3:
                return 0;
            default:
                printf("Opcion no vaida. \n");

        }

    }
    return 0;
}


void crearMensaje(){
    int ren, col, i, j, k=0;
    printf("ingresar el tamaño de la escitala: \n");
    printf("\nReglones: ");
    scanf("%i",&ren);
    printf("\nColumnas: ");
    scanf("%i",&col);

    char escitala[ren][col]
    char texto[ren*col];

    printf("Escriba el texto a cifrar: ªn");
    scanf("%s", texto);

    for (i=0; i<ren; i++)
        for(j=0;j<col;j++)
            escitala[i][j]=texto[k++];

    printf("El texto en la tira queda de la siguiente manera: \n");
    for (i=0; i<col; i++)
        for(j=0;j<col;j++)
            escital

}
