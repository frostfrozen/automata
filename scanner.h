#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
/*funciones*/
char parser(FILE *automata); //funcion principal Automata Finito Deterministico
int debo_parar(int estado, FILE *automata);
int esLetra(char l);
int esNumero(char l);
int esEspacio(char l);
/*funciones*/
#endif // SCANNER_H_INCLUDED

