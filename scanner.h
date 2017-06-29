#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
/*funciones*/
extern int esFinal;
char scanner(FILE *automata); //funcion principal Automata Finito Deterministico
int debo_parar(int estado, FILE *automata);
int esLetra(char l);
int esNumero(char l);
int esEspacio(char l);
int obtener_columna (char caracter);
/*funciones*/
#endif // SCANNER_H_INCLUDED

