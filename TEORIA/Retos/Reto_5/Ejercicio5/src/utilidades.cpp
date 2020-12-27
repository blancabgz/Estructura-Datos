#include <iostream>
#include <vector>
#include "bintree.h"
#include "utilidades.h"
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
