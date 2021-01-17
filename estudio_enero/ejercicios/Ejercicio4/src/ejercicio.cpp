/*
Dada una lista de enteros con elementos repetidos, diseñar una funcion con TDA lista
que construya a partir de ella una lista ordenada de listas, de forma que en la lista
resultado los elementos iguales se agrupen en la misma.
 */

#include <iostream>
#include <list>
#include "utilidades.h"

using namespace std;

int main(){
  list<int> array_lista;
  list < list<int> > final;
  int num, numero_user, num_buscar;

  cout << "Introduce el tamaño de la lista que vas a introducir: ";
  cin >> num;

  array_lista.resize(num);
  for(int i = 0; i < num; i++){
    cout << "Introduce un numero: " << endl;
    cin >> numero_user;
    array_lista.push_back(numero_user);
  }

  sublista(array_lista, final);

// recorremos la lista general
  for (auto it=final.begin(); it != final.end(); ++it) {
      // cada elemento de la lista, es otra lista, que podemos iterar
    for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
      cout << *it2 << " ";
    }
  }
}
