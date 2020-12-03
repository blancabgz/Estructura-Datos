/**
  * @file pila_min_vd.h
  * @brief Fichero cabecera del TDA Pila min
  *
  * Gestiona una secuencia de elementos con facilidades para la inserci�n y
  * borrado de elementos en un extremo
  *
  */

#ifndef __Pila_min_H__
#define __Pila_min_H__
#include "vd.h"
#include <cassert>
typedef struct{
  int ele; ///<elemento a almacenar
  int minimo; ///<el minimo
}elemento;  
ostream & operator<<(ostream & os,const elemento & a){
 os<<a.ele<< " Minimo: "<<a.minimo<<endl;
 return os;
} 
/**
 *  @brief T.D.A. Pila_min
 *
 *
 * Una instancia @e v del tipo de datos abstracto Pila_min sobre el tipo @c entero es 
 * una lista de pares de elementos <entero,entero > con un funcionamiento @e LIFO (Last In, 
 * First Out). En una pila, las operaciones de inserci�n y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila_min de longitud
 * @e n la denotamos

 * - [<a1,min{a1...an}>,<a2,min{a2...an}>,<a3,min{a3...an}>,..,<an,an>>

 * donde @e ai es el elemento de la posici�n i-�sima. Y @e min{ai,...aj} es el m�nimo del conjunto de * elementos que van desde @e ai a @e aj
 * En esta pila, tendremos acceso �nicamente al elemento del @e Tope, es decir, 
 * a @e an. El borrado o consulta de un elemento ser� sobre  @e an, y la
 * inserci�n de un nuevo elemento se har� sobre �ste. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila est� vac�a.

 * El espacio requerido para el almacenamiento es O(n). Donde n es el n�mero de
 * elementos de la Pila_min.
 *
 */

class Pila_min{
  private:
    VD<elemento> datos;
  public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    Pila_min(){
    }
    /**
     * @brief Constructor de copias
     * @param otra La pila de la que se har� la copia.
     */
    Pila_min(const Pila_min & otra):datos(otra.datos){}
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Pila_min(){}
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignaci�n
     * @param otra La pila que se va a asignar.
     */
    Pila_min& operator= (const Pila_min& otra){
      
      
    }
    /**
     * @brief Comprueba si la pila est� vac�a
     */
    bool vacia() const{
      
    }
    /**
     * @brief Devuelve el elemento del tope de la pila
     */
    elemento & tope (){
      
    }
    /**
     * @brief Devuelve el elemento del tope de una pila constante
     */
    const elemento & tope () const{
      
    }
    /**
     * @brief A�ade un elemento "encima" del tope de la pila
     * @param elem Elemento que se va a a�adir.
     */
    void poner(const int & elem){
      
    }   
    /**
     * @brief Quita el elemento del tope de la pila
     */
    void quitar(){
        
    }	
    /**
     * @brief Devuelve el n�mero de elementos de la pila
     */
    int num_elementos() const{
      
    }
};


#endif
