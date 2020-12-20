#include <iostream>
#include <cmath>
#include <list>
#include "utilidades.h"
using namespace std;

int ppt(list<int> &lista, int n){
  list<int> last;
  int tam, avanza;
  list<int>::iterator it;
  list<int>::reverse_iterator rit, sub, sol, aux;
  bool encontrado;

  tam = lista.size();
  avanza = tam - n;

  // quito los elementos correspondientes a la jugada y los meto en otra lista
  for(int i = 0; i < n; i++){
    it = lista.begin();
    advance(it,avanza);
    last.splice(last.begin(),lista, it);
  }

  // el splice me los mete al contrario, asi que le doy la vuelta
  last.reverse();

  sub = last.rbegin();
  rit = lista.rbegin();
  sol = lista.rbegin();
  aux = lista.rend();
  encontrado = false;

  // compruebo que los elementos de la sublista estan en la lista
  while( rit != lista.rend() && !encontrado){
    if(*rit == *sub){
      // miro si no hay jugada en eso que ha encontrado
      if(aux == lista.rend()){
        aux = rit;
      }
      ++sub;
      // hemos encontrado la sublista en la lista con jugada
      encontrado = (sub == last.rend());
    }else{
      sub = last.rbegin();
      rit = ++aux;
      aux = lista.rend();
    }
    ++rit;
  }
  int resultado = 0;
  if(aux != lista.rbegin()){
    rit = lista.rbegin();
    ++rit;
    while(encontrado && rit != aux){
      ++rit;
      ++sol;
    }
    // obtengo la jugada
    resultado = *sol;
  }

  return resultado;

}
