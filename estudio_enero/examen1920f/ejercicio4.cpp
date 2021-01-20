#include <iostream>
#include <queue>
#include <limits>
#include "bintree.h"
using namespace std;

bintree<int>::node siguiente_inorden(bintree<int>::node n){
  if(!n.null()){// si no es nulo
    if(!n.right().null()){ // si no es nulo el de la derecha
      n = n.right() // buscamos el descendiente más a la izq del hijo derecho
      while (!n.left().null()) {
        n = n.left();
      }

    }else{ // si no hay hijo derecho
      n = n.parent();
    }
  }
  return n;
}
