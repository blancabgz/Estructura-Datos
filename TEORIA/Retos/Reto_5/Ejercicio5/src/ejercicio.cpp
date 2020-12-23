#include <iostream>
#include <vector>
#include "bintree.h"

using namespace std;

  void calculanumhijos(bintree<int>::node n, int cont, vector<pair<int, int> > & calculo){
    int hijos = 0;
    if(!n.left().null()){
      hijos++;
      calculanumhijos(n.left(), cont+1, calculo);
    }

    if(!n.right().null()){
      hijos++;
      calculanumhijos(n.left(), cont+1, calculo);
    }

    calculo[cont].first = *n;
    calculo[cont].second = hijos;

  }

  int onechild(bintree<int> &T){
    bintree<int>::node nodo;
    vector<pair<int, int> > calculo;
    int unhijo = 0;

    calculo.resize(T.size());
    for(unsigned int i = 0; i < T.size(); i++){
      calculo[i].first = 0;
      calculo[i].second = 0;
    }

    calculanumhijos(T.root(), 0, calculo);

    for(unsigned int i = 0; i < calculo.size(); i++){
      if(calculo[i].second == 1){
        unhijo++;
      }
    }

    return unhijo;
  }

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
