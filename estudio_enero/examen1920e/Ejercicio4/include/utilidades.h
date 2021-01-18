#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <vector>
#include <list>
#include "bintree.h"
using namespace std;


list<int> nivel(const bintree<int> &A);


void calcularniveles(bintree<int>::node n, int prof, vector<int> & calculo);

#endif
