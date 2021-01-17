#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include "utilidades.h"
using namespace std;

void sublista(list<int> & array_lista, list< list<int> > & final){
  list<int> lista_aux;
  list< list<int> >::iterator q;
    list<int>::iterator p;
  int elemento;
  
  array_lista.sort();
  while(!array_lista.empty()){
    p = array_lista.begin();
    elemento = *p;
    while(*p == elemento){
      lista_aux.push_back(elemento);
      p = array_lista.erase(p);
    }
    final.push_back(lista_aux);
    lista_aux.clear();

  }

}
