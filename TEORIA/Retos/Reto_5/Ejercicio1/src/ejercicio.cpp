#include <iostream>
#include "utilidades.h"
#include "bintree.h"
#include <list>

using namespace std;

int main(){
  list<float> lista;
  int cont = 1;

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

  prom_nivel(arbol, lista);

  for (list<float>::iterator it=lista.begin(); it != lista.end(); ++it){
    cout << "En la profundidad " << cont << " la media es " << *it << endl;
    cont++;
  }

}
