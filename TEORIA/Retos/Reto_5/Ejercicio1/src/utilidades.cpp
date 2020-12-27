#include <iostream>
#include <list>
#include "bintree.h"
#include "utilidades.h"
using namespace std;

void calcularniveles(bintree<int>::node n, int prof, vector<pair<int, int>> & calculo){
  if(!n.null()){ // si el nodo no es nulo
    if(prof > calculo.size()){
      int aux = calculo.size();
      calculo.resize(prof);
      for(int i = aux; i < prof; i++){
        calculo[i].first = 0;
        calculo[i].second = 0;
      }
    }

    calculo[prof - 1].first += *n; // voy guardando en el vector la profundidad y el numero de nodos
    calculo[prof - 1].second ++;

    // recorrer el arbol de forma recursiva
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
    float media = calculo[i].first * 1.0 / calculo[i].second; // calculo para hacer el promedio
    P.push_back(media);
  }
}
