/*
Diseñar una funcion que dada una lista de enteros, elimine todos aquellos que no sean más grandes que todos los anteriores.
 */

#include <iostream>
#include <list>
#include "utilidades.h"

using namespace std;

int main(){
  list<int> array_lista;
  int num, numero_user, num_buscar;

  cout << "Introduce el tamaño de la lista que vas a introducir: ";
  cin >> num;

  array_lista.resize(num);
  for(int i = 0; i < num; i++){
    cout << "Introduce un numero: " << endl;
    cin >> numero_user;
    array_lista.push_back(numero_user);
  }

  subsecuencia(array_lista);

  for (list<int>::iterator it=array_lista.begin(); it != array_lista.end(); ++it)
    cout << ' ' << *it;
}
