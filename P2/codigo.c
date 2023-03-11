#include <stdio.h>

void Reina(int *q[]);
void Rey(int *q[]);

int main(){
    int opcion=0;
    int tablero[8][8], *q[8];

    while (1){
        for(int k=0;k<8;k++){
            q[k]=&tablero[k][0];
            for(int t=0;t<8;t++)
                tablero[k][t]=0;
        }

        printf("\n\t*** MOVIMIENTOS VALIDOS EN PIEZAS DE AJEDREZ ***\n");
        printf("¿Qué desea realizar?\n");
        printf("1) Reina.\n");
        printf("2) Rey.\n");
        printf("3) Salir.\n\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:Reina(q);break;
            case 2:Rey(q);break;
            case 3:printf("\t\t---Gracias, vuelva pronto---\n\n");return 0;
            default:printf("Opción no válida.\n");
        }
    }
    return 0;
}

void Reina(int *q[]){
    int x,y;

    printf("Ingrese las coordenadas (x,y) de la pieza Reina en una matriz de 8x8");
    printf("\nCoordenada x: ");
    scanf("%i",&x);
    printf("\nCoordenada y: ");
    scanf("%i",&y);

    for (int j = 0; j < 8; j++){//columnas
        for (int k = 0; k < 8; k++){//renglones  
            if(y==j+1||x==k+1)
                q[k][j]=1;
        }
    }

    for (int i=x-1, j=y-1; (i<8&&j>=0); i++, j--)
        q[i][j]=1;

    for (int i=x-1, j=y-1; (i>=0&&j<8); i--, j++)
        q[i][j]=1;

    for (int i=x-1, j=y-1; (i<8&&j<8); i++, j++)
        q[i][j]=1;

    for (int i=x-1, j=y-1; (i>=0&&j>=0); i--, j--)
        q[i][j]=1;

    q[x-1][y-1]=2;

    for(int t=0;t<8;t++){   //columnas
        for(int k=0;k<8;k++){       //renglones
            if(q[k][t]==2)
                printf("|A");
            if(q[k][t]==1)
                printf("|X");
            if(q[k][t]==0)
                printf("|_");
        }
        printf("\n");
    }
}

void Rey(int *q[]){
     int x,y;

    printf("Ingrese las coordenadas (x,y) de la pieza Reina en una matriz de 8x8");
    printf("\nCoordenada x: ");
    scanf("%i",&x);
    printf("\nCoordenada y: ");
    scanf("%i",&y);

    for (int j = 0; j < 8; j++){//columnas
        for (int k = 0; k < 8; k++){//renglones  
            if(x==k&&y-1==j)
                q[k][j]=1;
            if(x==k&&y==j)
                q[k][j]=1;
            if(x-1==k&&y-2==j)
                q[k][j]=1;
            if(x-2==k&&y-2==j)
                q[k][j]=1;
            if(x-2==k&&y-1==j)
                q[k][j]=1;
            if(x-2==k&&y==j)
                q[k][j]=1;
            if(x-1==k&&y==j)
                q[k][j]=1;
            if(x==k&&y-2==j)
                q[k][j]=1;
        }
    }

    q[x-1][y-1]=2;

    for(int t=0;t<8;t++){   //columnas
        for(int k=0;k<8;k++){       //renglones
            if(q[k][t]==2)
                printf("|R");
            if(q[k][t]==1)
                printf("|X");
            if(q[k][t]==0)
                printf("|_");
        }
        printf("\n");
    }
}