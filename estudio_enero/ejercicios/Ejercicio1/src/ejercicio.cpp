/*
Usando el TDA list<int>, construir una funcion void int agrupar_elemento(int num_buscar, list<int> & array_lista)
que agrupe de forma consecutiva en la lista de entrada todas las apariciones del elemento k en la lista a partir de
la primera ocurrencia.
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

  cout << "Introduce el numero a buscar ";
  cin >> num_buscar;
  agrupar_elemento(num_buscar, array_lista);

  for (list<int>::iterator it=array_lista.begin(); it != array_lista.end(); ++it)
    cout << ' ' << *it;
}
