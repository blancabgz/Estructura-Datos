#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>

class Documento{
private:
  map< string, set<int> > palabras;
public:
  Documento(const list<string> &texto){
    map< string, set<int> >::iterator p;
    list<int>::iterator it;
    int pos = 0;

    for(it = texto.cbegin(); it != texto.cend(); ++it, ++pos){
      p = palabras.find(*it);
      if(p == palabras.end()){
        set<int> aux;
        aux.insert(pos);
        pair <string, set<int> > c(*it, aux);
        palabras.insert(c);
      }else{
        p->second.insert(pos);
      }

    }
  }

  set<int> posiciones (string palabra) const{
      map< string, set<int> >::iterator p;
      p = palabras.find(palabra);
      if(p != palabras.end()){
        return p->second;
      }
  }

  string palabra(int i) const{
    map< string, set<int> >::iterator p;
    set<int>::const_iterator aux;

    for(p = palabras.cbegin(); p != palabras.cend(); ++p){
      aux = (*p).second.find(i);
      if(aux != *p).second.cend()){
        return *mit.first;
      }
    }
  }

}
