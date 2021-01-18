#include <iostream>
#include <list>
using namespace std;

void reemplaza(list<int> & i, const list<int> & seq, const list<int> & reemp){
  list<int>::const_iterator seq_it, it_enc;
  list<int>::const_iterator reemp_it;
  list<int>::iterator i_it = i.begin();

  while(i_it != i.end()){ // mientras que no llegue al final de la lista
    it_enc = i_it; // guardo el primer valor de la lista
    seq_it = seq.cbegin();

    while(it_enc != i.end() && seq_it != seq.cend() && *it_enc == *seq_it){ // mientras las dos listas no lleguen al final y encuentres elementos iguales
      ++it_enc; // avanzo el iterador
      ++seq_it;
    }

    if(seq_it == seq.cend()){ // cuando llegue al final de la lista de comparaciones
      i_it = i.erase(i_it, it_enc); // quito el numero
      reemp_it = reemp.cbegin(); // pongo el iterador al principio de la lista
      while(reemp_it != reemp.cend()){ // mientras no llegue al final
        i_it = i.insert(i_it,*reemp_it);
        ++i_it;
        ++reemp_it;
      }
    }else{
      ++i_it;
    }
  }
}

int main(){
  int v1[] = {1,2,3,4};
  int v2[] = {1,3};
  int v3[] = {0,2};

  list<int> l1,l2,l3;
  l1.assign(v1,v1+4);
  l2.assign(v2,v2+2);
  l3.assign(v3,v3+2);
  reemplaza(l1,l2,l3);

  list<int>::iterator it;
  for(it = l1.begin(); it != l1.end(); ++it){
    cout << *it << " ";
  }
}
