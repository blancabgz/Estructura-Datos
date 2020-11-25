#include <iostream>
#include <stack>
#include "utilidades.h"

using namespace std;

int main(){
  int num;
  
  cout << "Introduce un numero natural para imprimir los conjuntos ordenados: ";
  cin >> num;

  lexico_stack(num);

}
