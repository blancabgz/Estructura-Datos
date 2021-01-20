/*
Implementar una funcion inall(list< set<int> > & LS, set<int> & S); que devuelve true si algun conjunto esta incluido
en todos los demas y tal conjunto lo devuelva en S.
 */
#include <iostream>
#include <list>
#include <set>
using namespace std;
bool operator==(const set<int> &S1, const set<int> & S2){
  set<int>::iterator p;
  for(p = S1.begin(); p != S1.end(); ++p){
    set<int>::iterator p2 = S2.find(*p); // mira a ver si esta
    if(p2 == S2.end()){ // si llega al final
      return false;
    }
  }
  return true;
}


bool inall(list< set<int> > & LS, set<int> & S){
  list< set<int> >::iterator it;
    list< set<int> >::iterator it2;
    bool esta;
  for(it = LS.begin(); it != LS.end(); ++it){
    it2 = LS.begin();
    esta = true;
    while(it2 != LS.end() && esta){
      if(*it2 == *it){
        ++it2;
      }else{
        esta = false;
      }
    }

    if(esta){
      S = *it;
      return true;
    }

  }
  return false;
}

int main(){
  set<int> s; // coincide
  int v[] = {1,2,3};
  set<int>s1(v,v+3);
  int v2[] = {1,2,3,4};
  set<int>s2(v2,v2+4);
  int v3[] = {1,2,3,4,5};
  set<int>s3(v3,v3+5);
  list<set<int> > LS;
  LS.push_back(s1);
  LS.push_back(s2);
  LS.push_back(s3);

  if(inall(LS,s)){
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it){
      cout << *it << " ";
    }
    cout << endl;
  }


}
