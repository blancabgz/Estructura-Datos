/*
Dadas 2 listas de enteros L1 y L2 implementar una funcion: bool check_sum(const list<int> & L1, const list<int> & L2)
que devuelva true si los elementos de L1 pueden agruparse sumando de forma que se puedan obtener los de L2 sin alterar
el orden de los elementos.

 */

#include <iostream>
#include <list>
using namespace std;

bool check_sum(const list<int> & L1, const list<int> & L2){
  list<int>::iterator t1 = L1.begin();
  list<int>::iterator t2 = L2.begin();
  bool cumple_sum = true;
  int contador;

  while(t2 != L2.end() && cumple_sum){
    contador = 0;
    while(t1 != L1.end() && contador != *t2){
      contador += *t1;
    }
    if(contador != *t2){
      cumple_sum = false;
    }
  }
  return cumple_sum;
}
