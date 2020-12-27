#include <iostream>
#include <vector>
#include "bintree.h"
#include "utilidades.h"

using namespace std;

  /* arbol
  //        2
  //     /
  //    3
  //  /  \
  //  4   5
  */

int main() {
  int hijos;

  bintree<int> arbol(2);
  arbol.insert_left(arbol.root(), 3);
  // arbol.insert_right(arbol.root(), 6);
  arbol.insert_left(arbol.root().left(), 4);
  arbol.insert_right(arbol.root().left(), 5);

  hijos = onechild(arbol);

  cout << "El arbol tiene " << hijos << " hijos" << endl;

}
