/*
Agrupe en la primera parte de la lista los elementos menores a un numero k y en la segunda los mayores o iguales. Se utilizan iteradores
pero no se pueden usar estructuras auxiliares, no se puede modificar el tamaño de la lista
 */

#include <iostream>
#include <list>
#include "utilidades.h"

using namespace std;

int main(){
  list<int> array_lista;
  int num, numero_user, num_orde;

  cout << "Introduce el tamaño de la lista que vas a introducir: ";
  cin >> num;

  array_lista.resize(num);
  for(int i = 0; i < num; i++){
    cout << "Introduce un numero: " << endl;
    cin >> numero_user;
    array_lista.push_back(numero_user);
  }

  cout << "Introduce el numero a ordenar ";
  cin >> num_orde;
  dividir_lista(array_lista, num_orde);

  for (list<int>::iterator it=array_lista.begin(); it != array_lista.end(); ++it)
    cout << ' ' << *it;
}
