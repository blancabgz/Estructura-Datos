#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include "utilidades.h"
using namespace std;

void repetidos(list<int> & array_lista, list<int> & final){
  list<int>::iterator p;
  int num, contador;


  array_lista.sort(); // ordeno
  while(!array_lista.empty()){
    p = array_lista.begin();
    num = *p;
    contador = 0;
    while(*p == num){
      contador++;
      p = array_lista.erase(p);
    }

    if(contador >= 2){
      final.push_back(num);
    }
  }
}
