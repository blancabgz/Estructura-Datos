#include <iostream>
#include <vector>
#include "bintree.h"

using namespace std;



  /* Arbol
  //        2
  //     /
  //    3
  //  /  \
  // 5    6
  */


int main() {
  bool inferior;

  bintree<int> arbol_1(2);
  arbol_1.insert_left(arbol_1.root(), 3);
  arbol_1.insert_right(arbol_1.root(), 4);
  arbol_1.insert_left(arbol_1.root().left(), 5);
  arbol_1.insert_right(arbol_1.root().left(), 6);
  // arbol_1.insert_left(arbol_1.root().right(), 7);

  inferior = es_inferior(arbol_1, arbol_2);
  if(inferior){
    cout << "El arbol 1 es inferior al arbol 2" << endl;
  }else{
    cout << "El arbol 1 NO es inferior al arbol 2" << endl;
  }
}
