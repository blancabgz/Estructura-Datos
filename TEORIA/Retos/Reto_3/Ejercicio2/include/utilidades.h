#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <list>
using namespace std;

/**
* @brief predice la proxima jugada del oponente
* La funcion obtiene el numero de jugadas ultimas introducidas por el oponente,
* busca en el historial la ultima vez que se ha realizado una jugada e imprime
* la siguiente jugada que ha realizado.
* @param lista es la lista de jugadas
* @param n son las jugadas que hay que mirar
* @author Blanca Abril
* @date 21 noviembre
*/
int ppt(list<int> &lista, int n);

#endif
