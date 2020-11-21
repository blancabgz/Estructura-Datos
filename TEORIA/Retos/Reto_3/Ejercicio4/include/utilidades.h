/**
  @file utilidades.h
  @brief Este archivo imprime todos los conjuntos de numeros hasta n
*/

#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <stack>
using namespace std;

/**
  * @brief  Dado un conjunto de numeros, los reordena de tal forma
  * que primero pone los pares y despues los impares en el mismo orden introducidos.
  * @param  pila la pila de numeros a ser ordenada
  * @result void. Pasa por referencia la pila ordenada
  * @author Blanca Abril
  * @date 21 noviembre
*/

void reordena(stack<int> &pila);

/**
  * @brief Imprime la pila que se le pasa por referencia
  * @param  pila la pila de numeros ordenada
  * @result void. Imprime la pila ordenada
  * @author Blanca Abril
  * @date 21 noviembre
*/

void imprimir_pila(stack<int> pila);

#endif
