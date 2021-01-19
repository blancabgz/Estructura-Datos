#include <iostream>
#include <vector>
#include "ArbolBinario.hpp"
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

  ArbolBinario<int> arbol(5);
  arbol.izquierda(arbol.raiz(), 7);
  arbol.derecha(arbol.raiz(), 15);
  arbol.izquierda(arbol.raiz()->izqda, 6);
  arbol.derecha(arbol.raiz().left(), 9);
  arbol.izquierda(arbol.raiz().right(), 12);
  arbol.derecha(arbol.raiz().right(), 20);

  bool hola = esABB(arbol);


}
