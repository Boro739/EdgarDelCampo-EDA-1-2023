#include <stdio.h>

void Alfil();
void Torre();

int main(){
    int opcion=0;
    while (1){
        printf("\n\t*** MOVIMIENTOS VALIDOS EN PIEZAS DE AJEDREZ ***\n");
        printf("¿Qué desea realizar?\n");
        printf("1) Alfil.\n");
        printf("2) Torre.\n");
        printf("3) Salir.\n\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:Alfil();break;
            case 2:Torre();break;
            case 3:printf("\t\t---Gracias, vuelva pronto---\n\n");return 0;
            default:printf("Opción no válida.\n");
        }
    }
    return 0;
}

//Funcion Afil
void Alfil(){
    int x,y;
    int tablero[8][8];

    for(int k=0;k<8;k++){
        for(int t=0;t<8;t++)
            tablero[k][t]=0;
    }

    printf("Ingrese las coordenadas (x,y) de la pieza Alfil en una matriz de 8x8");
    printf("\nCoordenada x: ");
    scanf("%i",&x);
    printf("\nCoordenada y: ");
    scanf("%i",&y);


    for (int i=x-1, j=y-1; (i<8&&j>=0); i++, j--)
        tablero[i][j]=1;

    for (int i=x-1, j=y-1; (i>=0&&j<8); i--, j++)
        tablero[i][j]=1;

    for (int i=x-1, j=y-1; (i<8&&j<8); i++, j++)
        tablero[i][j]=1;

    for (int i=x-1, j=y-1; (i>=0&&j>=0); i--, j--)
        tablero[i][j]=1;

    tablero[x-1][y-1]=2;

    for(int t=0;t<8;t++){   //columnas
        for(int k=0;k<8;k++){       //renglones
            if(tablero[k][t]==2)
                printf("|A");
            if(tablero[k][t]==1)
                printf("|X");
            if(tablero[k][t]==0)
                printf("|_");
        }
        printf("\n");
    }
}


//Funcion Torre
void Torre(){
    int tablero [8][8];
    int x,y;


    for(int k=0;k<8;k++){
        for(int t=0;t<8;t++)
            tablero[k][t]=0;
        }
    
    printf("Ingrese las coordenadas (x,y) de la pieza Torre en una matriz de 8x8");
    printf("\nCoordenada x: ");
    scanf("%i",&x);
    printf("\nCoordenada y: ");
    scanf("%i",&y);

        for (int i=x-1, j=y-1; (i<x||j>=0); i++, j--)
        tablero[i][j]=1;

    for (int i=x-1, j=y-1; (i>=x||j<8); i--, j++)
        tablero[i][j]=1;

    for (int i=x-1, j=y-1; (i<8||j<y); i++, j++)
        tablero[i][j]=1;

    for (int i=x-1, j=y-1; (i>=0||j>=y); i--, j--)
        tablero[i][j]=1;

    tablero[x-1][y-1]=2;

    for(int t=0;t<8;t++){   //columnas
        for(int k=0;k<8;k++){       //renglones
            if(tablero[k][t]==2)
                printf("|T");
            if(tablero[k][t]==1)
                printf("|X");
            if(tablero[k][t]==0)
                printf("|_");
        }
        printf("\n");
    }
    /*for (int k = 0; k < 8; k++)//columnas
    {
        for (int j = 0; j < 8; j++)//renglones
        {
            if(y==tablero[k][j] && x==j+1 )
                
                printf("|T");
                else if(y==k+1||x==j+1)
                    printf("|X");
                        else
                        printf("|_");
        }
        printf("\n");

    }*/
}
