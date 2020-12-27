#include <iostream>
#include <vector>
#include "bintree.h"
#include "utilidades.h"
using namespace std;

bool es_inferior(bintree<int> & ab1, bintree<int> & ab2){
  vector<int> arbol_1;
  vector<int> arbol_2;

  if(ab1.size() == ab2.size()){

    for (bintree<int>::preorder_iterator i = ab1.begin_preorder(); i!=ab1.end_preorder(); ++i){
      arbol_1.push_back(*i);
    }

    for(bintree<int>::preorder_iterator i = ab2.begin_preorder(); i!=ab2.end_preorder(); ++i){
      arbol_2.push_back(*i);
    }

    for( unsigned int i = 0; i < ab1.size(); i++){
      if(arbol_1[i] > arbol_2[i]){
        return false;
      }
    }
    return true;

  }else{
    return false;
  }

}
