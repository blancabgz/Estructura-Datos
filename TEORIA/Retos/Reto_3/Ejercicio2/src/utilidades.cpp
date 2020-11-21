#include <iostream>
#include <cmath>
#include <list>
#include "utilidades.h"
using namespace std;

bool contenido(list<list<int>> &ll, list<int> &l){
  list<int>::iterator itl, itlld;
  list<list<int>>::iterator itll;
  int cont;
  bool resultado;

  itl = l.begin();
  resultado = true;

  for(int j = 0; j < l.size(); j++){
    cont = 0;
    if(resultado){
      for(itll = ll.begin(); itll != ll.end(); itll++){
        list <int> t1 = *itll;
        for(itlld = t1.begin(); itlld != t1.end(); itlld++){
          if(*itl == *itlld){
            cont++;
          }
        }
      }
    }
    if(cont != 1){
      resultado = false;
    }
    ++itl;
  }

  return resultado;
}
