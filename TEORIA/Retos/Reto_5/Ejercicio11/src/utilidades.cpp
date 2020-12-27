#include <iostream>
#include <vector>
#include "bintree.h"
#include "utilidades.h"
using namespace std;

int nodos_k(bintree<int> &A, int k){
  int contador = 0;
  for (bintree<int>::preorder_iterator i = A.begin_preorder(); i!=A.end_preorder(); ++i)
    if(*i == k){
      contador++;
    }

  return contador;
}
