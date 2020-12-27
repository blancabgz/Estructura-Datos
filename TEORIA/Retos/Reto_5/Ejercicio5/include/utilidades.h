#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <vector>
#include "bintree.h"
using namespace std;

/**
* @brief Calcula el numero de hijos que tiene un nodo
* @param n nodo
* @param cont contador
* @param calculo vector para guardar los nodos y el numero de hijos
* @author Blanca Abril
*/

void calculanumhijos(bintree<int>::node n, int cont, vector<pair<int, int> > & calculo);


/**
* @brief Devuelve cuantos nodos tienen exactamente un hijo
* @param T arbol a explorar
* @author Blanca Abril
*/

int onechild(bintree<int> &T);

#endif
