/*
Diseñar una funcion que dada una lista L devuelva otra lista R conteniendo
los elementos repetidos de L. Si no hay elementos repetidos de R, la lista estará vacia
 */

#include <iostream>
#include <list>
#include "utilidades.h"

using namespace std;

int main(){
  list<int> array_lista, final;
  int num, numero_user;

  cout << "Introduce el tamaño de la lista que vas a introducir: ";
  cin >> num;

  array_lista.resize(num);
  for(int i = 0; i < num; i++){
    cout << "Introduce un numero: " << endl;
    cin >> numero_user;
    array_lista.push_back(numero_user);
  }

  repetidos(array_lista, final);

  for(list<int>::iterator it = final.begin(); it != final.end(); ++it){
    cout << " " << *it;
  }

}
