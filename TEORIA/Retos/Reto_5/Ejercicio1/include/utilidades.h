#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <list>
#include "bintree.h"
using namespace std;

/**
* @brief Calculo por niveles el numero de nodos que hay.
* @param  n nodo actual
* @param prof profundidad del arbol en ese momento
* @param calculo vector para guardar el nivel y los nodos que hay en cada nivel
* @author Blanca Abril
*/

void calcularniveles(bintree<int>::node n, int prof, vector<pair<int, int>> & calculo);


/**
* @brief Promedio por niveles
* @param  T arbol a explorar
* @param P lista con los niveles y los promedios
* @author Blanca Abril
*/

void prom_nivel(bintree<int> &T, list<float> & P);

#endif
