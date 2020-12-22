#include <iostream>
#include <vector>
#include "bintree.h"

using namespace std;

bool es_inferior (bintree<int> & ab1, bintree<int> & ab2){
  vector<int> vector_ab1;
  vector<int> vector_ab2;
  typename bintree<int>::level_iterator i;

  for(i = ab1.begin_level(); i!=ab1.end_level(); ++i){
    vector_ab1.push_back(*i);
  }

  for(i = ab2.begin_level(); i!=ab2.end_level(); ++i){
    vector_ab2.push_back(*i);
  }


  for(unsigned int i = 0; i < vector_ab1.size(); i++){
    if(vector_ab1[i] > vector_ab2[i]){
      return false;
    }
  }

  return true;

}


  /* Arbol_1              Arbol 2
  //        2                 3
  //     /    \            /    \
  //    3      4          4      5
  //  /  \    / \        /  \   /   \
  // 5    6  7  8       6   7   8    9
                                             */


int main() {
  bool inferior;

  bintree<int> arbol_1(2);
  arbol_1.insert_left(arbol_1.root(), 3);
  arbol_1.insert_right(arbol_1.root(), 4);
  arbol_1.insert_left(arbol_1.root().left(), 5);
  arbol_1.insert_right(arbol_1.root().left(), 6);
  arbol_1.insert_left(arbol_1.root().right(), 7);
  arbol_1.insert_right(arbol_1.root().right(), 8);


  bintree<int> arbol_2(3);
  arbol_2.insert_left(arbol_2.root(), 4);
  arbol_2.insert_right(arbol_2.root(), 5);
  arbol_2.insert_left(arbol_2.root().left(), 6);
  arbol_2.insert_right(arbol_2.root().left(), 7);
  arbol_2.insert_left(arbol_2.root().right(), 8);
  arbol_2.insert_right(arbol_2.root().right(), 9);


  inferior = es_inferior(arbol_1, arbol_2);
  if(inferior){
    cout << "El arbol 1 es inferior al arbol 2" << endl;
  }else{
    cout << "El arbol 1 NO es inferior al arbol 2" << endl;
  }
}
