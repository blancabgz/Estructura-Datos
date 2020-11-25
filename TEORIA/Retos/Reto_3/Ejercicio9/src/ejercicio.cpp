#include <iostream>
#include <stack>
#include "utilidades.h"

using namespace std;

int main(){
  stack<int> pila;
  int num;

  cout << "Introduce numeros naturales (0 para finalizar):" << endl;
  cin >> num;

  while(num != 0){
    if(num < 1){
      cout << "Has introducido un numero inválido" << endl;
    }else{
      pila.push(num);
    }
    cout << "Introduce numeros aleatorios (0 para finalizar):" << endl;
    cin >> num;
  }

  reordena(pila);
  imprimir_pila(pila);

  

}
