/**
  @file utilidades.h
  @brief Este archivo contiene la funcion contenido que nos dice si los elementos de una lista estan en otra una sola vez
*/

#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <list>
using namespace std;

/**
  * @brief  Dada una lista ll y una lista l, nos indica si cada elemento l esta una sola vez en ll.
  * La función contenido nos devuelve dada una lista ll y una lista l, true si
  * cada elemento de l esta contenido una y solo una lista de ll.
  * Si un elemento l no se encuentra contenida o esta contenida en mas de una lista
  * devuelve false.
  * @param lista con todas las listas introducidas por el usuario.
  * @param l con la lista que queremos comprobar
  * @result Nos devuelve un booleano.
  * Devolverá true si cada elemento se encuentra solamente en una lista.
  * Devolverá false si no esta el elemento en ninguna lista o está en más de una lista.
  * @author Blanca Abril
  * @date 21 noviembre
*/

bool contenido(list<list<int>> &ll, list<int> &l);

#endif
