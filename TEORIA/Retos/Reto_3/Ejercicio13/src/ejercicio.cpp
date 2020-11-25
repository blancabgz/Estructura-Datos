#include <iostream>
#include <stack>
#include "utilidades.h"

using namespace std;

int main(){
  stack<int> pila1, pila2, ordenada;
  int num, introd;

  cout << "Introduce una lista ordenada 1" << endl;
  cout << "¿Cuantos numeros quieres introducir: ";
  cin >> num;

  // introduzco los numeros en la pila
  for(int i = 0; i < num; i++){
    cin >> introd;
    pila1.push(introd);
  }

  cout << "Introduce una lista ordenada 2" << endl;
  cout << "¿Cuantos numeros quieres introducir: ";
  cin >> num;

  for(int i = 0; i < num; i++){
    cin >> introd;
    pila2.push(introd);
  }

  ordenada = ordenarpilas(pila1, pila2);
  imprimir_pila(ordenada);
}
