#include <iostream>
#include <vector>
#include <list>
#include "bintree.h"
#include "utilidades.h"
using namespace std;

void calcularniveles(bintree<int>::node n, int prof, vector<int> & calculo){
  // if(!n.null()){ // si el nodo no es nulo
  //   if(prof > calculo.size()){
  //     int aux = calculo.size();
  //     calculo.resize(prof);
  //     for(int i = aux; i < prof; i++){
  //       calculo[i] = 0;
  //     }
  //   }
  //
  //   calculo[prof - 1] += *n; // guardo el valor
  //
  //   // recorrer el arbol de forma recursiva
  //   if(!n.right().null()){
  //     calcularniveles(n.right(), prof+1, calculo);
  //   }
  //
  //   if(!n.left().null()){
  //     calcularniveles(n.left(), prof+1, calculo);
  //   }
  // }
}

list<int> nivel(const bintree<int> &A){
  // vector<int> calculo;
  // list<int> lista;
  // calcularniveles(A.root(), 1 , calculo);

  // for(unsigned int i = 0; i < calculo.size(); i++){
  //   lista.push_back(calculo[i]);
  // }

}
