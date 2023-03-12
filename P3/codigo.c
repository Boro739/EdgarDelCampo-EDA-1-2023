#include <stdio.h>
#define TAM 8

struct piezas{
    int tablero [TAM][TAM];
    int x;
    int y;
    int *q[TAM];
}P;

void Caballo();
void Alfil();
void Torre();
void Reina();
void Rey();

int main(){
    int opcion=0;

    while (1){
        for(int k=0;k<8;k++){
            P.q[k]=&P.tablero[k][0];
            for(int t=0;t<8;t++)
                P.tablero[k][t]=0;
        }

        printf("\n\t*** MOVIMIENTOS VALIDOS EN PIEZAS DE AJEDREZ ***\n");
        printf("¿Qué desea realizar?\n");
        printf("1) Caballo.\n");
        printf("2) Alfil.\n");
        printf("3) Torre.\n");
        printf("4) Reina.\n");
        printf("5) Rey.\n");
        printf("6) Salir.\n\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:Caballo();break;
            case 2:Alfil();break;
            case 3:Torre();break;
            case 4:Reina();break;
            case 5:Rey();break;
            case 6:printf("\t\t---Gracias, vuelva pronto---\n\n");return 0;
            default:printf("Opción no válida.\n");
        }
    }
    return 0;
}

//Funcion Caballo
void Caballo(){
    
    printf("Ingrese las coordenadas (x,y) de la pieza Caballo en una matriz de 8x8");
    printf("\nCoordenada x: ");
    scanf("%i",&P.x);
    printf("\nCoordenada y: ");
    scanf("%i",&P.y);

    for (int j = 0; j < 8; j++){
        for (int k = 0; k < 8; k++){
            if((P.x==k && P.y+1==j)||(P.x==k && P.y-3==j))
                P.q[k][j]=1;
            if((P.x+1==k && P.y==j)||(P.x+1==k && P.y-2==j))
                P.q[k][j]=1;
            if((P.x-2==k && P.y+1==j)||(P.x-2==k && P.y-3==j))
                P.q[k][j]=1;
            if((P.x-3==k && P.y==j)||(P.x-3==k && P.y-2==j))
                P.q[k][j]=1;
        }
    }

    P.q[P.x-1][P.y-1]=2;

    for(int t=0;t<8;t++){   //columnas
        for(int k=0;k<8;k++){       //renglones
            if(P.tablero[k][t]==2)
                printf("|C");
            if(P.tablero[k][t]==1)
                printf("|X");
            if(P.tablero[k][t]==0)
                printf("|_");
        }
        printf("\n");
    }

}

//Funcion Afil
void Alfil(){

    printf("Ingrese las coordenadas (x,y) de la pieza Alfil en una matriz de 8x8");
    printf("\nCoordenada x: ");
    scanf("%i",&P.x);
    printf("\nCoordenada y: ");
    scanf("%i",&P.y);

    for (int i=P.x-1, j=P.y-1; (i<8&&j>=0); i++, j--)
        P.tablero[i][j]=1;

    for (int i=P.x-1, j=P.y-1; (i>=0&&j<8); i--, j++)
        P.tablero[i][j]=1;

    for (int i=P.x-1, j=P.y-1; (i<8&&j<8); i++, j++)
        P.tablero[i][j]=1;

    for (int i=P.x-1, j=P.y-1; (i>=0&&j>=0); i--, j--)
        P.tablero[i][j]=1;

    P.tablero[P.x-1][P.y-1]=2;

    for(int t=0;t<8;t++){   //columnas
        for(int k=0;k<8;k++){       //renglones
            if(P.tablero[k][t]==2)
                printf("|A");
            if(P.tablero[k][t]==1)
                printf("|X");
            if(P.tablero[k][t]==0)
                printf("|_");
        }
        printf("\n");
    }
}


//Funcion Torre
void Torre(){
    
    printf("Ingrese las coordenadas (x,y) de la pieza Torre en una matriz de 8x8");
    printf("\nCoordenada x: ");
    scanf("%i",&P.x);
    printf("\nCoordenada y: ");
    scanf("%i",&P.y);

    for (int j = 0; j < 8; j++)//columnas
    {
        for (int k = 0; k < 8; k++)//renglones
        {
                if(P.y==j+1||P.x==k+1)
                    P.tablero[k][j]=1;
                        else
                        P.tablero[k][j]=0;
        }
    }
    P.tablero[P.x-1][P.y-1]=2;

    for(int t=0;t<8;t++){   //columnas
        for(int k=0;k<8;k++){       //renglones
            if(P.tablero[k][t]==2)
                printf("|T");
            if(P.tablero[k][t]==1)
                printf("|X");
            if(P.tablero[k][t]==0)
                printf("|_");
        }
        printf("\n");
    }
}

//Funcion Reina
void Reina(int *q[]){

    printf("Ingrese las coordenadas (x,y) de la pieza Reina en una matriz de 8x8");
    printf("\nCoordenada x: ");
    scanf("%i",&P.x);
    printf("\nCoordenada y: ");
    scanf("%i",&P.y);

    for (int j = 0; j < 8; j++){//columnas
        for (int k = 0; k < 8; k++){//renglones  
            if(P.y==j+1||P.x==k+1)
                P.q[k][j]=1;
        }
    }

    for (int i=P.x-1, j=P.y-1; (i<8&&j>=0); i++, j--)
        P.q[i][j]=1;

    for (int i=P.x-1, j=P.y-1; (i>=0&&j<8); i--, j++)
        P.q[i][j]=1;

    for (int i=P.x-1, j=P.y-1; (i<8&&j<8); i++, j++)
        P.q[i][j]=1;

    for (int i=P.x-1, j=P.y-1; (i>=0&&j>=0); i--, j--)
        P.q[i][j]=1;

    P.q[P.x-1][P.y-1]=2;

    for(int t=0;t<8;t++){   //columnas
        for(int k=0;k<8;k++){       //renglones
            if(P.q[k][t]==2)
                printf("|Q");
            if(P.q[k][t]==1)
                printf("|X");
            if(P.q[k][t]==0)
                printf("|_");
        }
        printf("\n");
    }
}

//Funcion Rey
void Rey(){

    printf("Ingrese las coordenadas (x,y) de la pieza Rey en una matriz de 8x8");
    printf("\nCoordenada x: ");
    scanf("%i",&P.x);
    printf("\nCoordenada y: ");
    scanf("%i",&P.y);

    for (int j = 0; j < 8; j++){//columnas
        for (int k = 0; k < 8; k++){//renglones  
            if(P.x==k && P.y-1==j)
                P.q[k][j]=1;
            if(P.x==k && P.y==j)
                P.q[k][j]=1;
            if(P.x-1==k && P.y-2==j)
                P.q[k][j]=1;
            if(P.x-2==k && P.y-2==j)
                P.q[k][j]=1;
            if(P.x-2==k && P.y-1==j)
                P.q[k][j]=1;
            if(P.x-2==k && P.y==j)
                P.q[k][j]=1;
            if(P.x-1==k && P.y==j)
                P.q[k][j]=1;
            if(P.x==k && P.y-2==j)
                P.q[k][j]=1;
        }
    }

    P.q[P.x-1][P.y-1]=2;

    for(int t=0;t<8;t++){   //columnas
        for(int k=0;k<8;k++){       //renglones
            if(P.q[k][t]==2)
                printf("|R");
            if(P.q[k][t]==1)
                printf("|X");
            if(P.q[k][t]==0)
                printf("|_");
        }
        printf("\n");
    }
}