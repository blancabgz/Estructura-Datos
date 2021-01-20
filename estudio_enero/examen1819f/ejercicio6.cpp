#include <unordered_map>
#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

bool mayor(const set<int> & s){
  set<int>::const_iterator it;
  for(it = s.begin(); it != s.end(); ++it){
    if(*it <= 20){
      return false;
    }
  }
  return true;
}


class contenedor{
  private:
    map<string, set<int> > datos;

  public:
    class iterator{
      private:
        map<string, set<int> > :: iterator it;
        map<string, set<int> > :: iterator f;

      public:
        iterator(){}
        bool operator== (const iterator & i){
          return i.it == it;
        }

        bool operator!= (const iterator & i){
          return i.it != it;
        }

        pair<string, set<int> > &operator*(){
          return *it;
        }

        iterator &operator++{
          do{
            ++it;
          }while(it != f && !mayor(*it.second))
        }
    };

    iterator begin(){
      iterator i;
      i.it = datos.begin();
      i.f = datos.end();
      if(!mayor(*(i.it).second))
        ++i;
      return i;
    }

    iterator end(){
      iterator i;
      i.it = datos.end();
      i.f = datos.end();
      return i;
    }
}
