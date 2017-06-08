#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "scanner.h"
int tt[7][4] = {{2,1,0 ,5},{5, 1, 3, 5},{2, 2, 4, 5},{99, 99, 99, 99},{99, 99, 99, 99},{5, 5, 6, 5},{99,99,99,99}};
/* estados [0][0]
[1][0] [2][0] numeros, letra
[3][0] [4][0] aceptores
[5][0]        error
*/
char c;
char parser(FILE *automata)
    {
        /*variables*/
        int estado = 0;
        int caracter;
        enum tipo{LETRA, NUMERO, ESPACIOS, ERROR };
        /*variables*/

        /*funcion parser*/
       while (!debo_parar(estado, automata))
        {
        c = getc(automata);
        if (c != EOF)
            {
                if (esLetra(c))
                    {
                        caracter = LETRA;
                    }
                else if (esNumero(c))
                    {
                        caracter = NUMERO;
                    }
                else if (esEspacio(c))
                    {
                        caracter = ESPACIOS;
                    }
                else
                    {
                        caracter = ERROR;
                    }
                estado = tt[estado][caracter];
            }
        else {estado = tt[estado][ESPACIOS];}
        };
        return estado;
        };
        /*funcion parser*/

 /*aceptor / centinela*/
int debo_parar(int estado, FILE *automata)
{
    if (estado == 3 || estado == 4){
        if (estado == 99)
        {
            ungetc(c, automata);
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
int esLetra(char l){return islower(l);}
int esNumero(char l){return isdigit(l);}
int esEspacio(char l){return isspace(l);};
/*auxiliares no necesarias pero hacen el codigo mas legible en español*/


