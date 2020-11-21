#include <iostream>
#include <cmath>
#include <stack>
#include "utilidades.h"
using namespace std;

void lexico_stack(int &n){
  stack<int> pila, pila_rev;

  for(int i = 1; i <= n; i++){
    pila.push(i);

    while (! pila.empty()) {
      pila_rev.push(pila.top());
      pila.pop();
    }

    while(! pila_rev.empty()){
      cout << pila_rev.top();
      pila.push(pila_rev.top());
      pila_rev.pop();
    }
    cout << " ";
  }
  cout << endl;

}
