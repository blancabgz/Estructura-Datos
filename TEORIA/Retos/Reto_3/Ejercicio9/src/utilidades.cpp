#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include "utilidades.h"
using namespace std;

void reordena(stack<int> &pila){
  queue<int> cola;
  int tam;

  // vuelco la pila en la cola
  while(!pila.empty()){
    cola.push(pila.top());
    pila.pop();
  }

  tam = cola.size();
  // los pares los meto en la pila, y los impares los vuelvo a introducir
  for(int i = 0; i < tam; i++){
    if(cola.front() % 2 != 0){
      pila.push(cola.front());
    }else{
      cola.push(cola.front());
    }
    cola.pop();
  }

  // introduzco en la pila los impares
  while(!cola.empty()){
    pila.push(cola.front());
    cola.pop();
  }
}

void imprimir_pila(stack<int> pila){
  while(! pila.empty()){
    cout << pila.top() << " ";
    pila.pop();
  }
  cout << endl;
}
