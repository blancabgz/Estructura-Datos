/**
  @file elemento.h
  @brief Este archivo es el struct que contiene el elemento al almacenar y el maximo de los elementos introducidos.
  @author Blanca Abril
  @date Diciembre 2020
*/

#ifndef ELEMENTO
#define ELEMENTO

#include <iostream>

using namespace std;

template <class T>
struct elemento{
  T ele; // elemento a almacenar
  T max; // elemento maximo

  /**
  * @brief Constructor por defecto
  * @param  ele elemento que se quiere almacenar
  * @param  max elemento mayor de los elementos introducidos
  */
  elemento(T e, T m) : ele(e), max(m){}

  inline elemento<T>& operator= (const elemento<T>& original){
    this.ele = original.ele;
    this.max = original.max;

    return *this;
  }
};

template <class T>
ostream& operator<<(ostream& os, const elemento<T>& elemento){
  os << elemento.ele << ", " << elemento.max << endl;

  return os;
}


#endif
