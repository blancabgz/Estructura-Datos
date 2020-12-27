#include <iostream>
#include <vector>
#include "bintree.h"
#include "utilidades.h"
using namespace std;

void buscar(bintree<int>::node nodo_bus, int etiqueta, bintree<int> arbol, bintree<int>::node & node){
  if(!nodo_bus.null()){
    if(*nodo_bus == etiqueta){
      node = nodo_bus;
    }else{
      if(!nodo_bus.right().null()){
        buscar(nodo_bus.right(), etiqueta, arbol, node);
      }

      if(!nodo_bus.left().null()){
        buscar(nodo_bus.left(), etiqueta, arbol, node);
      }
    }
  }
}

bintree<int>::node siguiente_nodo_nivel(const bintree<int>::node &n, const bintree<int> &arb){
  bintree<int>::node nodo;

  for(bintree<int>::const_level_iterator i = arb.begin_level(); i!=arb.end_level(); ++i){
    if(*n == *i){
      ++i;
      nodo = *i;
      return nodo;
    }
  }
  return -1;
}


int buscar_nodo(bintree<int> arbol, int etiqueta){
  bintree<int>::node nodo, nodo_siguiente;
  int siguiente = 0;

  buscar(arbol.root(), etiqueta, arbol, nodo);

  nodo_siguiente = siguiente_nodo_nivel(nodo, arbol);
  siguiente = *nodo_siguiente;

  return siguiente;
}
