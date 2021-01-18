#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;

bool TodosPares(const list<int> & l){
  list<int>::const_iterator it;
  for(it = l.begin(); it != l.end(); ++it){
    if(*it % 2 == 1){
      return false;
    }
    return true;
  }
}

template <typename T>
class contenedor{
  private:
    unordered_map <T, list<int> > datos;
  public:
    class iterator(){
      private:
        typename unordered_map <T, list<int> >::iterator it;
        typename unordered_map <T, list<int> >::iterator f;
      public:
        iterator (){}
        bool operator== (const iterator & i) const{
          return i.it == it;
        }

        bool operator!= (const iterator & i) const{
          return i.it != it;
        }

        pair<T, list<int> > & operator*(){
          return *it;
        }

        iterator &operator++(){
          do{
            ++it;
          }while(it != f && !TodosPares(*it.second));

          return *this;
        }

        friend class contenedor;
    }
}
