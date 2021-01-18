#include <iostream>
#include <list>
#include "bintree.h"
#include "utilidades.h"

using namespace std;

  /* arbol
  //        2
  //     /   \
  //    3     6
  //  /  \
  //  4   5
  */

int main() {
  list<int> max_nodos;

  /* creo un arbol:
  //        1
  //     /    \
  //    2      3
  //  /  \    / \
  // 4    5  6  7
  //    /  \
  //   8    9       */

  bintree<int> arbol(1);
  arbol.insert_left(arbol.root(), 2);
  arbol.insert_right(arbol.root(), 3);
  arbol.insert_left(arbol.root().left(), 4);
  arbol.insert_right(arbol.root().left(), 5);
  arbol.insert_left(arbol.root().right(), 6);
  arbol.insert_right(arbol.root().right(), 7);
  arbol.insert_left(arbol.root().left().right(), 8);
  arbol.insert_right(arbol.root().left().right(), 9);

  max_nodos = nivel(arbol);


}
