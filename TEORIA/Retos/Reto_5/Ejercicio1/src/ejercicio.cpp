#include <iostream>
#include "bintree.h"
#include <list>

using namespace std;

void calcularniveles(bintree<int>::node n, int prof, vector<pair<int, int>> & calculo){
  if(!n.null()){
    // cout << *n << " / " << prof << endl;
    if(prof > calculo.size()){
      int aux = calculo.size();
      calculo.resize(prof);
      for(int i = aux; i < prof; i++){
        calculo[i].first = 0;
        calculo[i].second = 0;
      }
    }

    calculo[prof - 1].first += *n;
    calculo[prof - 1].second ++;

    if(!n.right().null()){
      calcularniveles(n.right(), prof+1, calculo);
    }

    if(!n.left().null()){
      calcularniveles(n.left(), prof+1, calculo);
    }

  }

}

void prom_nivel(bintree<int> &T, list<float> & P){
  vector<pair<int, int> > calculo;
  calcularniveles(T.root(),1, calculo);

  for(unsigned int i = 0; i < calculo.size(); i++){
    float media = calculo[i].first * 1.0 / calculo[i].second;
    P.push_back(media);
  }
}


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
