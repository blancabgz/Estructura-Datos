#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include "utilidades.h"
using namespace std;

template <class T>
void dividir_lista(list<T> & lista, T k){
  list<int>::iterator it = lista.begin();
  while(it != lista.end()){
    if(k > *it){
      lista.push_back(*it);
      it = lista.erase(it);
    }else{
      ++it;
    }
  }

}
