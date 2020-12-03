/**
 * @file lista.h
 * @brief Fichero cabecera del TDA Lista
 *
*/
#ifndef __Lista__H
#define __Lista__H
#include <iostream>
#include <cassert>
using namespace std;


/**
  * @brief T.D.A Lista con cabecera
  * Una instancia @e c del tipo de dato abstracto Lista es una secuencia de datos de tipo T
  *       m1,m2,....mn
  * de manera que m1 es el primer elmento (posicion principio) y mn es el ultimo elemento (posicion final)
  * Si @e n=0 diremos que la lista esta vacía
  * El espacio requerido para almacenar la n datos de tipo T es O(n) .
*/
template <class T>
class Lista{

  struct Celda{
    T elemento;///< Elemento de informacion
    Celda * siguiente; ///< Puntero al siguiente nodo
    Celda * anterior; ///< Puntero al anterior nodo
    
       /**
       * @brief Constructor por defecto
       */
      Celda() : siguiente(0),anterior(0){
	
      }
      /**
       * @brief Constructor con parámetros
       * @param elem Elemento de información.
       * @param sig Puntero al siguiente nodo.
       */
      Celda(const T & elem, Celda * sig,Celda * ant): elemento(elem), siguiente(sig){
      }
    };

    Celda * primera; ///< Puntero al primer nodo de la lista.
    int num_elem;    ///< Número de elementos de la pila.

      /**
     * @brief Copia una lista en otra
     * @param otra La lista de la que se hara copia
     */
    
    void Copiar(const Lista<T>&otra);
   
    
    /**
     * @brief Libera le memoria opcupada por la lista
     */
    void Liberar();
    
  public:
       // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto. Reserva solamente la cabecera de la lista
     */
    Lista (){
      primera = new Celda;
      primera->siguiente=primera->anterior=0;
      num_elem=0;
    }
    
    /**
     * @brief Constructor de copias
     * @param otra La lista de la que se hará la copia.
     */
    
    Lista(const Lista<T> & otra);
  // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Lista();
    
     // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignación
     * @param otra La lista que se va a asignar.
     */
    Lista& operator= (const Lista<T>& otra);
    /**
     * @brief Comprueba si la lista está vacía
     */
    bool vacia() const{
      return (primera->siguiente==primera->anterior);
    }
    
    /**
     * @brief Devuelve el elemento en un posicion
     * @param pos: la posicion a consultar
    */
    
    const T& Get(int pos)const;
    
    /**
     * @brief Devuelve el elemento en un posicion
     * @param pos: la posicion a consultar
    */
    
    T & Get(int pos);
    
    /**
     * @brief Modifica el elemento en una posicion
     * @param pos: la posicion a modificar
     * @param v: el nuevo valor
    */
    
    void Set(int pos,const T & v);
    
    /**
     * @brief Insertaa un nuevo elemento en una posicion
     * @param pos: la posicion a insertar
     * @param nuevo: el nuevo valor
    */
    
    
    void Insertar(int pos,const T & nuevo);
    
    
    /**
     * @brief Borra un elemento de una posicion
     * @param pos: la posicion a borrar
     
    */
    void Borrar(int pos);
    
    
    /**
     * @brief Devuelve el numero de elementos
     
    */
    int Size()const{ return num_elem;}
    
};
#include "lista.tpp"
#endif
