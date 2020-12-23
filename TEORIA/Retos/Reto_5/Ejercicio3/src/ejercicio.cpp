#include <iostream>
#include <vector>
#include "bintree.h"

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


/* creo un arbol_2:           creo un arbol_1:
//        2                          1
//     /    \                      /   \
//    3     4                     2    3
//  /  \    / \                 /  \  / \
// 5    6  7  8                4   5 6   7

*/

int main() {
  bool inferior;

  bintree<int> arbol_1(1);
  arbol_1.insert_left(arbol_1.root(), 2);
  arbol_1.insert_right(arbol_1.root(), 3);
  arbol_1.insert_left(arbol_1.root().left(), 4);
  arbol_1.insert_right(arbol_1.root().left(), 5);
  arbol_1.insert_left(arbol_1.root().right(), 6);
  arbol_1.insert_right(arbol_1.root().right(), 7);

  bintree<int> arbol_2(2);
  arbol_2.insert_left(arbol_2.root(), 3);
  arbol_2.insert_right(arbol_2.root(), 4);
  arbol_2.insert_left(arbol_2.root().left(), 5);
  arbol_2.insert_right(arbol_2.root().left(), 6);
  arbol_2.insert_left(arbol_2.root().right(), 7);
  arbol_2.insert_right(arbol_2.root().right(), 8);



  inferior = es_inferior(arbol_1, arbol_2);
  if(inferior){
    cout << "El arbol 1 es inferior al arbol 2" << endl;
  }else{
    cout << "El arbol 1 NO es inferior al arbol 2" << endl;
  }
}
