/*
TP0 - 2017

Un escáner elemental

Grupo 07

Aruquipa Mamani, Jhoselyn Sandra
1608678

Bogo, David
1498708

Kargman, Facundo
1559679

Rios, David Michel
1604554
*/
#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int main()
{
    /*variables*/
    FILE *archivo;
    char resultado = 6;
    int constEnt = 0;
    int identificadores = 0;
    int errores = 0;
    enum tipo {CONST = 3, IDENTIFICADOR = 4, ERROR = 6};
    /*variables*/
    archivo = fopen("automata.dat", "r"); //abre el archivo

    if (archivo == NULL) //verifica que no este vacio
    {
        printf("No esta el archivo automata.dat");
        return -1;
    }
    //bucle donde se ejecuta el automata
    while (!esFinal)
    {
        resultado = scanner(archivo);
        switch(resultado)
        {
        case CONST:
            printf("constante entera\n");
            constEnt++;
            break;
        case IDENTIFICADOR:
            printf("identificador\n");
            identificadores++;
            break;
        case ERROR:
            printf("error\n");
            errores++;
            break;
        }
    }
    /*imprime totales*/
    printf("----------------------------------\n");
    printf("Totales:\n");
    printf("identificadores: %d \n", identificadores);
    printf("constante entera: %d \n", constEnt);
    printf("error: %d \n", errores);
    /*imprime totales*/
    fclose(archivo); //cierra el archivo
    return 0;
}
