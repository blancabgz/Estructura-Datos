#include <iostream>
#include <cmath>
#include <stack>
#include "utilidades.h"
using namespace std;

stack<int> ordenarpilas(stack<int> pila1, stack<int> pila2){

  stack<int> pilamezcla, pilaaux, pilaordenada;

  // vuelco pila 1 en la pila
  while(!pila1.empty()){
    pilamezcla.push(pila1.top());
    pila1.pop();
  }

  // vuelco pila 2 en la pila
  while(!pila2.empty()){
    pilamezcla.push(pila2.top());
    pila2.pop();
  }

  // ordeno de mayor a menor la pila
  while(!pilamezcla.empty()){
    int temp = pilamezcla.top();
    pilamezcla.pop();
    while(!pilaaux.empty() && pilaaux.top() > temp){
      pilamezcla.push(pilaaux.top());
      pilaaux.pop();
    }
    pilaaux.push(temp);
  }

  // le doy la vuelta a la pila volvando la auxiliar en la definitiva
  while(!pilaaux.empty()){
    pilaordenada.push(pilaaux.top());
    pilaaux.pop();
  }

  return pilaordenada;
}

void imprimir_pila(stack<int> pila){
  while(! pila.empty()){
    cout << pila.top() << " ";
    pila.pop();
  }
  cout << endl;
}
