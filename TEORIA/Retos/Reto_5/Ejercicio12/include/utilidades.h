#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <vector>
#include "bintree.h"
using namespace std;


/**
* @brief Recorre todos los nodos y busca si algun nodo coincide
* @param nodo nodo para recorrer el arbol
* @param etiqueta nodo a buscar
* @param arbol arbol donde buscamos
* @param node guardamos el nodo que coincide con la etiqueta
* @author Blanca Abril
*/

void buscar(bintree<int>::node nodo_bus, int etiqueta, bintree<int> arbol, bintree<int>::node & node);



/**
* @brief Encuentra el siguiente nodo en el mismo nivel
* @param n nodo donde se encontro la coincidencia
* @param arbol arbol donde buscamos
* @return nodo siguiente que esta en el mismo nivel que el nodo introducido
* @author Blanca Abril
*/

bintree<int>::node siguiente_nodo_nivel(const bintree<int>::node &n, const bintree<int> &arb);

/**
* @brief Obtiene la etiqueta de ese nodo y la muestra tras realizar toda la busqueda
* @param arbol arbol donde buscamos
* @param etiqueta nodo a buscar
* @return etiqueta del nodo siguiente al nodo introducido
* @author Blanca Abril
*/

int buscar_nodo(bintree<int> arbol, int etiqueta);

#endif
