#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include "utilidades.h"
using namespace std;

void agrupar_elemento(int num_buscar, list<int> & array_lista){
  list<int>::iterator it;
  list<int>::iterator encontrado = find(array_lista.begin(), array_lista.end(), num_buscar);
  it = ++encontrado;

  while (it != array_lista.end()) {
    if(*it == num_buscar){
      array_lista.insert(encontrado, num_buscar);
      it = array_lista.erase(it);
    }else{
      ++it;
    }
  }
}
