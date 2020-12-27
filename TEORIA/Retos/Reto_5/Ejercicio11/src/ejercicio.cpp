#include <iostream>
#include <vector>
#include "bintree.h"
#include "utilidades.h"

using namespace std;



/* creo un arbol:
//        1
//     /    \
//    2      3
//  /  \    / \
// 4    5  6  7
//    /  \
//   8    9       */

int main() {
  int etiqueta;

  bintree<int> arbol(1);
  arbol.insert_left(arbol.root(), 2);
  arbol.insert_right(arbol.root(), 3);
  arbol.insert_left(arbol.root().left(), 4);
  arbol.insert_right(arbol.root().left(), 5);
  arbol.insert_left(arbol.root().right(), 5);
  arbol.insert_right(arbol.root().right(), 7);
  arbol.insert_left(arbol.root().left().right(), 8);
  arbol.insert_right(arbol.root().left().right(), 9);

  cout << "Introduce la etiqueta que quieres buscar: ";
  cin >> etiqueta;

  int nodos = nodos_k(arbol, etiqueta);

  cout << "Hay " << nodos << " nodo/s que coinciden con la etiqueta " << etiqueta << endl;


}
