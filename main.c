#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int main()
{
    /*variables*/
    FILE *archivo;
    char resultado;
    int c = 0;
    int i = 0;
    int e = 0;
    /*variables*/
    archivo = fopen("automata.dat", "r"); //abre el archivo

    if (archivo == NULL) //verifica que no este vacio
    {
        printf("No esta el archivo automata.dat");
        return -1;
    }
    //bucle donde se ejecuta el automata
    while (!feof(archivo))
        {

            resultado = parser(archivo);
            switch(resultado)
            {
            case 3:
                printf("constante entera\n");
                c++;
                break;
            case 4:
                printf("identificador\n");
                i++;
                break;
            case 6:
                printf("error\n");
                e++;
                break;
            }
        }
    /*imprime totales*/
    printf("----------------------------------\n");
    printf("Totales:\n");
    printf("identificadores: %d \n", i);
    printf("constante entera: %d \n", c);
    printf("error: %d \n", e);
    /*imprime totales*/
    fclose(archivo); //cierra el archivo
    return 0;
}
