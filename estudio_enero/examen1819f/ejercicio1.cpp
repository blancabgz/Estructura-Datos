/*
Implementar una funcion void juntalista(list<int> &L, int n) que dada una lista L agrupe los elementos según n
dejando su suma. No pueden usarse estructuras auxiliares.
 */
// g++ -o  ejercicio ejercicio1.cpp


#include <iostream>
#include <list>
using namespace std;

void juntalista(list<int> & L, int n){

  if(n == 0 || L.size() == 0){
    return;
  }
  list<int>::iterator it = L.begin();

  while(it != L.end()){
    int cont = 0;
    int k = 0;
    list<int>::iterator inicio = it;
    while(it != L.end() && k < n){
      cont += *it;
      ++it;
      k++;
    }
    it = L.erase(inicio, it); // borra desde el inicio hasta donde esta it que es 3
    it = L.insert(it,cont); // meto en la pos it el valor
    ++it;
  }
}

int main(){
  int v[] = {1,2,3,4,5,6,7,8,9};
  list<int> l;
  l.assign(v,v+9);

  juntalista(l,3);

  list<int>::iterator it = l.begin();
  for(it; it != l.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;
}
