#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "scanner.h"
int tt[7][4] = {{2 ,1 ,0 ,5 },
                {5 ,1 ,3 ,5 },
                {2 ,2 ,4 ,5 },
                {99,99,99,99},
                {99,99,99,99},
                {6 ,6 ,6 ,5 },
                {99,99,99,99}};
/* estados [0][0]
[1][0] [2][0] numeros, letra
[3][0] [4][0] aceptores
[5][0]        error
*/
char caracter; /* caracter que esta siendo escaneado*/
enum tipo {LETRA, NUMERO, ESPACIOS, ERROR }; /*columnas*/
extern int esFinal = 0; /* variable que chequea cuando debe parar*/

char scanner(FILE *automata)
{
    int estado = 0;
    /*funcion scanner*/
    while (!debo_parar(estado, automata))
    {
        caracter = getc(automata);
        if (caracter != EOF)
        {
            estado = tt[estado][obtener_columna(caracter)];
        }
        else
        {
            estado = tt[estado][ESPACIOS];
            esFinal = 1;
        }
    };
    return estado;
};
/*funcion scanner*/

/* funcion para obtener la columna*/
int obtener_columna (char caracter)
{
    int tipoCaracter;

     if (esLetra(caracter))
            {
                tipoCaracter = LETRA;
            }
            else if (esNumero(caracter))
            {
                tipoCaracter = NUMERO;
            }
            else if (esEspacio(caracter))
            {
                tipoCaracter = ESPACIOS;
            }
            else
            {
                tipoCaracter = ERROR;
            }
            return tipoCaracter;
}
/* funcion para obtener la columna*/

/*aceptor / centinela*/
int debo_parar(int estado, FILE *automata)
{
    if (estado == 3 || estado == 4)
    {
        if (estado == 99)
        {
            ungetc(caracter, automata);
        }
        return 1;
    }
    else
    {
        if (estado == 6)
            return 1;
        return 0;
    }
}
/*aceptor / centinela*/

/*auxiliares no necesarias pero hacen el codigo mas legible en español*/
int esLetra(char l)
{
    return islower(l);
}
int esNumero(char l)
{
    return isdigit(l);
}
int esEspacio(char l)
{
    return isspace(l);
};
/*auxiliares no necesarias pero hacen el codigo mas legible en español*/


