#include <iostream>
#include <list>
#include "utilidades.h"

using namespace std;

int main(){
  int listas, elem, num, comp;
  list<int> l;
  list<int> lcomprueba;
  list<list<int>> ll;
  bool encontrado;

  cout << "¿Cuantas listas quieres introducir?" << endl;
  cin >> listas;

  for(int i = 0; i < listas; i++){
    cout << "Lista " << i + 1 << ": " << endl;
    cout << "¿Cuantos elementos quieres introducir? ";
    cin >> elem;
    if(elem > 0){
      l.clear();
      for(int j = 0; j < elem; j++){
        cout << "Introduce numero: ";
        cin >> num;
        l.push_back(num);
      }
    }
    ll.push_back(l);
  }

  cout << "¿Cuantas listas vas a comprobar? " << endl;
  cin >> comp;

  for(int i = 0; i < comp; i++){
    cout << "Lista " << i+1 << endl;
    cout << "¿Cuantos elementos quieres introducir? ";
    cin >> elem;
    if(elem > 0){
      lcomprueba.clear();
      for(int j = 0; j < elem; j++){
        cout << "Introduce numero: ";
        cin >> num;
        lcomprueba.push_back(num);
      }
      encontrado = contenido(ll,lcomprueba);
      if(encontrado){
        cout << "Cada elemento esta en una lista" << endl;
      }else{
        cout << "Los elementos se encontraban en mas de una lista o no estaban" << endl;
      }
    }

  }
}
