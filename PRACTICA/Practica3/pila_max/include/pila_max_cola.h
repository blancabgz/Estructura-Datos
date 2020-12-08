/**
  * @file pila_max_cola.h
  * @brief Fichero de cabecera del TDA Pila_Max
  *
  * Gestiona una secuencia de elementos como si fuera una pila usando
  * una cola.
  * @author Blanca Abril
  * @date Diciembre 2020
*/

#ifndef PILA_MAX_COLA
#define PILA_MAX_COLA

#include "cola.h"
#include "elemento.h"

using namespace std;

template <class T>

class Pila_max{
  private:
    Cola< elemento<T> > cola;
  public:
    /**
    * @brief Constructor por defecto
    */
    Pila_max<T>();

    /**
    * @brief Constructor de copias
    * @param copia Objeto de tipo pila para realizar la copia
    * @result Pila_max<T> devuelve una pila igual que la pasada por parametro
    */
    Pila_max<T>(const Pila_max<T> &copia);

    /**
    * @brief Método para comprobar si la pila esta vacia
    * @result bool donde true significa que está vacia y false que esta llena
    */
    bool vacia();

    /**
    * @brief Metodo que devuelve el tope de una pila
    * @result elemento<T> donde se obtienen los valores del elemento tope de la pila
    */

    elemento<T> tope();

    /**
    * @brief Metodo para introducir elementos en la pila
    * @param elemento introducir un elemento a almacenar
    */
    void poner(T elemento);

    /**
    * @brief Metodo para introducir un objeto elemento en la pila
    * @param elemento introducir un elemento a almacenar con su elemento y su maximo
    */
    void poner(elemento<T> elemento);

    /**
    * @brief Metodo para obtener el tamaño de la pila
    * @result T un valor que indica el tamaño
    */
    T tamano();

    /**
    * @brief Metodo para quitar elementos de la pila (quita el frente)
    */
    void quitar();

};

#include "pila_max_cola.cpp"
#endif
