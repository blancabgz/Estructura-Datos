/**
  * @file pila.h
  * @brief Fichero cabecera del TDA Pila
  *
  * Gestiona una secuencia de elementos con facilidades para la inserci�n y
  * borrado de elementos en un extremo
  *
  */

#ifndef __Pila_H__
#define __Pila_H__

#include <cassert>

/**
 *  @brief T.D.A. Pila_max
 *
 * @author Blanca Abril Gonz�lez y Carlos Romero de la Puente.
 * @date Noviembre 2020
 */

template <class T>
class Pila_max{
private:
  struct Celda{
    T elemento;       // Elemento de informaci�n
    T maximo;       // Elemento que almacena el mayor elemento de la pila
    Celda * siguiente;    // Puntero al siguiente nodo

    /**
        * @brief Constructor por defecto
        */
        Celda() : siguiente(0){
        }

        /**
        * @brief Constructor con par�metros
        * @param elem Elemento de informaci�n. Tambi�n se usar� para almacenar el primer m�ximo
        * @param sig Puntero al siguiente nodo.
        */
        Celda(const T & elem, Celda * sig){
          elemento = elem;
          if(elem > maximo)
            maximo = elem;
          siguiente = sig;
        }

  };

  Celda * primera;    // Puntero al primer nodo de la lista
  int num_elem;     // N�mero de elementos de la pila

public:
  // ---------------  Constructores ----------------
  /**
     * @brief Constructor por defecto
     */
    Pila_max(): primera(0), num_elem(0){
    }

    /**
     * @brief Constructor de copias
     * @param otra La pila de la que se har� la copia.
     */
    Pila_max(const Pila_max<T> & otra);

    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Pila_max();

    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignaci�n
     * @param otra La pila que se va a asignar.
     */
    Pila_max& operator= (const Pila_max<T>& otra);

    /**
     * @brief Comprueba si la pila est� vac�a
     */
    bool vacia() const{
      return (primera==0);
    }

    /**
     * @brief Devuelve el elemento del tope de la pila
     */
    T& tope (){
      assert(primera!=0);       //Si la pila est� vac�a, abortar
      return primera->elemento; //Devuelve el elemento del tope de la pila
    }

    /**
     * @brief Devuelve el elemento del tope de una pila constante
     */
    const T & tope () const{
      assert(primera!=0);       //Si la pila est� vac�a, abortar
      return primera->elemento; //Devuelve el elemento del tope de la pila
    }

    /**
     * @brief Devuelve el elemento m�ximo del tope de la pila
     */
    T& maximo (){
      assert(primera!=0);       //Si la pila est� vac�a, abortar
      return primera->maximo;   //Devuelve el elemento m�ximo del tope de la pila
    }

    /**
     * @brief Devuelve el elemento m�ximo del tope de una pila constante
     */
    const T & maximo () const{
      assert(primera!=0);       //Si la pila est� vac�a, abortar
      return primera->maximo; //Devuelve el elemento m�ximo del tope de la pila
    }

    /**
     * @brief A�ade un elemento "encima" del tope de la pila max
     * @param elem Elemento que se va a a�adir.
     */
    void poner(const T & elem);

    /**
     * @brief Quita el elemento del tope de la pila max
     */
    void quitar();

    /**
     * @brief Devuelve el n�mero de elementos de la pila
     */
    int num_elementos() const{
      return num_elem;
    }

};

#include <pila.cpp>

#endif // __Pila_H__
