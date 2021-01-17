#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include "utilidades.h"
using namespace std;

void subsecuencia(list<int> & array_lista){
  list<int>::iterator it = array_lista.begin(); // inicio el iterador
  list<int>::iterator siguiente; // iterador que apunta al siguiente elemento


  while(it != array_lista.end()){ // mientras no llegue al final
    siguiente = it;
    ++siguiente;
    if(*it >= *siguiente && siguiente != array_lista.end()){
      cout << "entro";
      it = array_lista.erase(it);
    }else{
      it = siguiente;
    }
  }



}
