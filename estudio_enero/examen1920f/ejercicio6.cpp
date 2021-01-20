#include <list>
#include <map>
#include <iostream>
using namespace std;

bool es_primo(int x){
  if(x < 1){
    return false;
  }else if(x<=3){
    return true;
  }else if(x%2 == 0){
    return false;
  }else{
    return true;
  }
}


bool primo(const list<int> &l){

  for(list<int>::iterator it = l.begin(); it != l.end(); ++it){
    if(!es_primo(*it)){
      return false;
    }
  }
  return true;
}


class Diccionario{
  private:
    map<int, list<int> > datos;
  public:
    class iterator{
      private:
        map<int, list<int> >::iterator it;
        map<int, list<int> >::iterator f;
      public:
        iterator(){}
        bool operator== (const iterator & i){
          return i.it == it;
        }

        bool operator!= (const iterator & i){
          return i.it != it;
        }

        pair<int, list<int> > &operator*(){
          return *it;
        }

        iterator &operator++{
          do{
            ++it;
          }while(it != f && !primo(*it.second))
        }

    };
    iterator begin(){
      iterator i;
      i.it = datos.begin();
      i.f = datos.end();
      while(i.it != i.f && !primo(*(i.it).second))
        ++i;
      return i;
    }

    iterator end(){
      iterator i;
      i.it = datos.end();
      i.f = datos.end();
      return i;
    }
};
