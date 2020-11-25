/**
  @file utilidades.h
  @brief Este archivo obtiene 2 pilas ordenadas y las ordena en una única pila
*/

#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <stack>
using namespace std;

/**
* @brief Se introducen dos pilas ordenadas y las unimos en una única pila ordenada
* @param  pila1 primera pila ordenada
* @param  pila2 segunda pila ordenada
* @result stack <int> devuelve una pila ordenada
* @author Blanca Abril
* @date 21 noviembre
*/

stack<int> ordenarpilas(stack<int> pila1, stack<int> pila2);

/**
  * @brief Imprime la pila que se le pasa por referencia
  * @param  pila la pila de numeros ordenada
  * @result void. Imprime la pila ordenada
  * @author Blanca Abril
  * @date 21 noviembre
*/

void imprimir_pila(stack<int> pila);

#endif
