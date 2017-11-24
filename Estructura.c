// BY MRZ

#include <stdio.h>
#include <stdlib.h>
#define num 50






void menu();

void menuFutbol();
void registroFutbol();
void mostrarFutbol();
void maximoGoleador();
void mejorEquipoFutbol();

void menuBaloncesto();
void registroBaloncesto();
void mostrarBaloncesto();
void maximoTriplista();
void mejorEquipoBaloncesto();


int vacioFutbol = 0, vacioBaloncesto = 0, cantidadLigaFutbol, cantidadLigaBaloncesto;
int numero; 
int puntos; 

struct ligaBaloncesto
{
    char nombreEquipo[num];

    int numVictorias;
    int numDerrotas;

    int numPerdidasBalon;
    int numRebotesCogidos;

    char nombreMejorTriplista[num];
    int numMejorTriplista;

}ligaBaloncesto, baloncesto[num],*p_baloncesto=baloncesto;

struct ligaFutbol
{
    char nombreEquipo[num];

    int numVictorias;
    int numDerrotas;
    int numEmpates;

    int numGolesFavor;
    int numGolesContra;

    char nombreGoleador[num];
    int golesGoleador;

}ligaFutbol ,futbol[num],*p_futbol=futbol;


int main()
{
	system("color 9F");
    menu();
    return 0;
}

void menu(){
    int opcion = 0;
    do{
        printf("\n____________________________________________________________________");
        printf("\n|____________seleccione una de las siguientes opciones:____________|");
        printf("\n|__________________________________________________________________|");
        printf("\n|_____________________|______________________|_____________________|");
        printf("\n|                     |                      |                     |");
        printf("\n|   1. LIGA FUTBOL    | 2. LIGA BALONCESTO   |     0.REGRESAR      |");
        printf("\n|                     |                      |                     |");
        printf("\n|_____________________|______________________|_____________________|");
        printf("\n|__________________________________________________________________|");
        printf("\n\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 0:
                system("cls");
                printf("GRACIAS POR UTILIZAR ESTE SOFTWARE 'BY MRZ'.\n");
                exit(0);
            case 1:
                system("cls");
                menuFutbol();
                break;
            case 2:
                system("cls");
                menuBaloncesto();
                break;
            default:
                system("cls");
                printf("La opcion seleccionada no existe.\n");
        }
    }while(opcion != 0);
}


void menuBaloncesto(){
    if(vacioBaloncesto == 0){
        printf("\n\nCuantos equipos participaran en la liga?: ");
        scanf("%d", &cantidadLigaBaloncesto);
        vacioBaloncesto = 1;
        menuBaloncesto();
    }else{
        int opcion = 0;
        do{
            printf("\n______________________________________________");
            printf("\n|_seleccione una de las siguientes opciones:_|");
            printf("\n|____________________________________________|");
            printf("\n|____________________________________________|");
            printf("\n|____________________________________________|");
            printf("\n|                     |                      |");
            printf("\n|  1. AGREGAR INFO    |      2. VER INF      |");
            printf("\n|_____________________|______________________|");
            printf("\n|                     |                      |");
            printf("\n| 3. MEJOR ANOTADOR   |   4. MEJOR EQUIPO    |");
            printf("\n|_____________________|______________________|");
            printf("\n|                ___________                 |");
            printf("\n|                0. REGRESAR                 |");
            printf("\n|_____________________|______________________|");
            printf("\n|____________________________________________|");
            printf("\n\n");
            scanf("%d", &opcion);
            switch(opcion){
                case 0:
                    system("cls");
                    menu();
                case 1:
                    system("cls");
                    registroBaloncesto();
                    break;
                case 2:
                    system("cls");
                    mostrarBaloncesto();
                    break;
                case 3:
                    system("cls");
                    maximoTriplista();
                    break;
                case 4:
                    system("cls");
                    mejorEquipoBaloncesto();
                    break;
                default:
                    system("cls");
                    printf("La opcion selecciono es incorrecta.\n");
            }
        }while(opcion != 0);
    }
}

void registroBaloncesto(){
    printf("\nINFORMACION NECESARIA\n\n");
    int i;
    for(i=0;i<cantidadLigaBaloncesto;i++){
    	fflush(stdin);
        printf("INGRESE EL NOMBRE DEL EQUIPO: ");
        gets((*(p_baloncesto+i)).nombreEquipo);
        printf("INGRESE EL NUMERO VICTORIAS: ");
        scanf("%d", &(*(p_baloncesto+i)).numVictorias);
        printf("INGRESE EL NUMERO DERROTAS: ");
        scanf("%d", &(*(p_baloncesto+i)).numDerrotas);
        printf("INGRESE EL NUMERO DE PERDIDAS DE BALON: ");
        scanf("%d", &(*(p_baloncesto+i)).numPerdidasBalon);
        printf("INGRESE EL NUMERO DE REBOTES COGIDOS: ");
        scanf("%d", &(*(p_baloncesto+i)).numRebotesCogidos);
        fflush(stdin);
        printf("INGRESE EL NOMBRE DEL MEJOR TRIPLISTA: ");
        gets((*(p_baloncesto+i)).nombreMejorTriplista);
        printf("INGRESE EL NUMERO DE TRIPLES REALIZADOS: ");
        scanf("%d", &(*(p_baloncesto+i)).numMejorTriplista);
        printf("\n");
    }
}

void mostrarBaloncesto(){
    printf("\nINFORMACION A MOSTRAR\n");
    int i;
    for(i=0;i<cantidadLigaBaloncesto;i++){
        printf("\nINFORMACION DEL EQUIPO #%d\n", i+1);
        printf("NOMBRE DEL EQUIPO: %s", (*(p_baloncesto+i)).nombreEquipo);
        printf("\nNUMERO DE VICTORIAS: %d", (*(p_baloncesto+i)).numVictorias);
        printf("\nNUMERO DE DERROTAS: %d", (*(p_baloncesto+i)).numDerrotas);
        printf("\nNUMERO DE PERDIDAS DE BALON: %d", (*(p_baloncesto+i)).numPerdidasBalon);
        printf("\nNUMERO DE REBOTES COGIDOS: %d", (*(p_baloncesto+i)).numRebotesCogidos);
        printf("\nNOMBRE DEL MEJOR TRIPLISTA: %s", (*(p_baloncesto+i)).nombreMejorTriplista);
        printf("\nNUMERO DE TRIPLES: %d", (*(p_baloncesto+i)).numMejorTriplista);
        printf("\n");
    }
    printf("\n");
}

void maximoTriplista(){
    int mayorTriplista;

    mayorTriplista = (*(p_baloncesto+0)).numMejorTriplista;
    int i;
    for(i=0;i<cantidadLigaBaloncesto;i++){
        if((*(p_baloncesto+i)).numMejorTriplista > mayorTriplista){
            mayorTriplista = (*(p_baloncesto+i)).numMejorTriplista;
            numero = i;
        }
    }

    printf("\nTRIPLES CONSEGUIDOS: %d", mayorTriplista);
    printf("\nNOMBRE DEL MEJOR TRPLISTA: %s", (*(p_baloncesto+numero)).nombreMejorTriplista);
    printf("\n");
}

void mejorEquipoBaloncesto(){
    int mEquipoBaloncesto;

    mEquipoBaloncesto = (*(p_baloncesto+0)).numVictorias;
    int i;
    for(i=0;i<cantidadLigaBaloncesto;i++){
        if((*(p_baloncesto+i)).numVictorias > mEquipoBaloncesto){
            mEquipoBaloncesto = (*(p_baloncesto+i)).numVictorias;
            numero = i;
        }
    }

    printf("\nVICTORIAS CONSEGUIDAS: %d", mEquipoBaloncesto);
    printf("\nNOMBRE DEL EQUIPO GANADOR: %s", (*(p_baloncesto+numero)).nombreEquipo);
    printf("\n");
}

void menuFutbol(){
    if(vacioFutbol == 0){
        printf("\n\nCuantos equipos participan en la liga?: ");
        scanf("%d", &cantidadLigaFutbol);
        vacioFutbol = 1;
        menuFutbol();
    }else{
        int opcion = 0;
        do{
            printf("\n______________________________________________");
            printf("\n|_seleccione una de las siguientes opciones:_|");
            printf("\n|____________________________________________|");
            printf("\n|____________________________________________|");
            printf("\n|____________________________________________|");
            printf("\n|                     |                      |");
            printf("\n|  1. AGREGAR INFO    |      2. VER INF      |");
            printf("\n|_____________________|______________________|");
            printf("\n|                     |                      |");
            printf("\n| 3. MAYOR GOLEADOR   |   4. MEJOR EQUIPO    |");
            printf("\n|_____________________|______________________|");
            printf("\n|                ___________                 |");
            printf("\n|                0. REGRESAR                 |");
            printf("\n|_____________________|______________________|");
            printf("\n|____________________________________________|");
            printf("\n\n");
            scanf("%d", &opcion);
            switch(opcion){
                case 0:
                    system("cls");
                    menu();
                case 1:
                    system("cls");
                    registroFutbol();
                    break;
                case 2:
                    system("cls");
                    mostrarFutbol();
                    break;
                 case 3:
                    system("cls");
                    maximoGoleador();
                    break;
                 case 4:
                    system("cls");
                    mejorEquipoFutbol();
                    break;
                default:
                    system("cls");
                    printf("La opcion seleccionada es incorrecta.\n");
            }
        }while(opcion != 0);
    }
}


void registroFutbol(){
    printf("\nINFORMACION NECESARIA\n\n");
    int i;
    for(i=0;i<cantidadLigaFutbol;i++){
    	fflush(stdin);
        printf("INGRESE EL NOMBRE DEL EQUIPO: ");
        gets((*(p_futbol+i)).nombreEquipo);
        printf("INGRESE EL NUMERO VICTORIAS: ");
        scanf("%d", &(*(p_futbol+i)).numVictorias);
        printf("INGRESE EL NUMERO DERROTAS: ");
        scanf("%d", &(*(p_futbol+i)).numDerrotas);
        printf("INGRESE EL NUMERO EMPATES: ");
        scanf("%d", &(*(p_futbol+i)).numEmpates);
        printf("INGRESE EL NUMERO DE GOLES REALIZADOS: ");
        scanf("%d", &(*(p_futbol+i)).numGolesFavor);
        printf("INGRESE EL NUMERO DE GOLES RECIBIDOS: ");
        scanf("%d", &(*(p_futbol+i)).numGolesContra);
        fflush(stdin);
        printf("INGRESE EL NOMBRE DEL GOLEADOR: ");
        gets((*(p_futbol+i)).nombreGoleador);
        printf("INGRESE EL NUMERO DE GOLES: ");
        scanf("%d", &(*(p_futbol+i)).golesGoleador);
        printf("\n");
    }
}


void mostrarFutbol(){
    printf("\nINFORMACION A MOSTRAR\n");
    int i;
    for(i=0;i<cantidadLigaFutbol;i++){
        printf("\nINFORMACION DEL EQUIPO #%d\n", i+1);
        printf("NOMBRE DEL EQUIPO: %s", (*(p_futbol+i)).nombreEquipo);
        printf("\nNUMERO DE VICTORIAS: %d", (*(p_futbol+i)).numVictorias);
        printf("\nNUMERO DE DERROTAS: %d", (*(p_futbol+i)).numDerrotas);
        printf("\nNUMERO DE EMPATES: %d", (*(p_futbol+i)).numEmpates);
        printf("\nNUMERO DE GOLES REALIZADOS: %d", (*(p_futbol+i)).numGolesFavor);
        printf("\nNUMERO DE GOLES RECIBIDOS: %d", (*(p_futbol+i)).numGolesContra);
        printf("\nNOMBRE DEL GOLEADOR: %s", (*(p_futbol+i)).nombreGoleador);
        printf("\nNUMERO DE GOLES: %d", (*(p_futbol+i)).golesGoleador);
        printf("\n");
    }
    printf("\n");
}

void maximoGoleador(){
    int mayorGoleador;
    mayorGoleador = (*(p_futbol+0)).golesGoleador;
    int i;
    for( i=0;i<cantidadLigaFutbol;i++){
        if((*(p_futbol+i)).golesGoleador > mayorGoleador){
            mayorGoleador = (*(p_futbol+i)).golesGoleador;
            numero = i;
        }
    }

    printf("\nGOLES MARCADOS: %d", mayorGoleador);
    printf("\nNOMBRE DEL MAYOR GOLEADOR: %s", (*(p_futbol+numero)).nombreGoleador);
    printf("\n");
}

void mejorEquipoFutbol(){
    int mEquipoFutbol;

    mEquipoFutbol = (*(p_futbol+0)).numVictorias;
    int i;
    for(i=0;i<cantidadLigaFutbol;i++){
        if((*(p_futbol+i)).numVictorias > mEquipoFutbol){
            mEquipoFutbol = (*(p_futbol+i)).numVictorias;
            numero = i;
        }
    }

    puntos = (mEquipoFutbol*3) + ((*(p_futbol+numero)).numEmpates);

    printf("\nPUNTOS: %d PUNTOS", puntos);
    printf("\nVICTORIAS CONSEGUIDAS: %d", mEquipoFutbol);
    printf("\nNOMBRE DEL EQUIPO GANADOR: %s", (*(p_futbol+numero)).nombreEquipo);
    printf("\n");
}





/*BY MRZ */
