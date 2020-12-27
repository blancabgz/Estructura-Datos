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

int main(){
  int busqueda, nodo;

  bintree<int> arbol(1);
  arbol.insert_left(arbol.root(), 2);
  arbol.insert_right(arbol.root(), 3);
  arbol.insert_left(arbol.root().left(), 4);
  arbol.insert_right(arbol.root().left(), 5);
  arbol.insert_left(arbol.root().right(), 5);
  arbol.insert_right(arbol.root().right(), 7);
  arbol.insert_left(arbol.root().left().right(), 8);
  arbol.insert_right(arbol.root().left().right(), 9);

  cout << "Introduce un nodo:  ";
  cin >> busqueda;
  nodo = buscar_nodo(arbol, busqueda);

  if(nodo){
    cout << "El siguiente nodo es: " << nodo << endl;
  }

}
