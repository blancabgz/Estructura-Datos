#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>
#include "data.h"


using namespace std;

 /*Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T. Puede usarse como
 un funtor.
 */
template <class T, class U>
bool operator< (const data<T,U> &d1,const data <T,U>&d2){
	   if (d1.clave<d2.clave)
		     return true;
	   return false;
}

/*Un diccionario es una lista de datos de los definidos anteriormente. Cuidado porque se
manejan listas de listas. Se añaden 2 funciones privadas que hacen más facil la implementación
de algunos operadores o funciones de la parte pública. Copiar copia un diccioario en
otro y borrar elimina todos los elementos de un diccionario. La implementación de copiar
puede hacerse usando iteradores o directamente usando la función assign.
*/
template <class T,class U>
class Diccionario{
	  private:
 		    list<data<T,U> > datos;

		    void Copiar(const Diccionario<T,U>& D){
         // se puede asignar un rango de valores y va desde begin hasta el end - 1
			   datos.assign(D.datos.begin(),D.datos.end());
		    }

		    void Borrar(){
            // rango de valores que queremos borrar
			      this->datos.erase(datos.begin(),datos.end());
		    }


	  public:
	   /* Constructor por defecto*/
		 Diccionario():datos(list<data<T,U> >()){}

		 /* Constructor de copias*/
		 Diccionario(const Diccionario &D);

		 /* Desstructor*/
		 ~Diccionario(){}

		 /* Operador de asignación*/
		 Diccionario<T,U> & operator=(const Diccionario<T,U> &D){
			   if (this!=&D){
				     Borrar();
				     Copiar(D);
			   }
			   return *this;
		 }

		/* Busca la clave p en el diccionario. Si está devuelve un iterador a
		dónde está clave. Si no está, devuelve end() y deja el iterador de salida
		apuntando al sitio dónde debería estar la clave
		*/
		bool Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out);

		 /* Inserta un nuevo registro en el diccionario. Lo hace a través de la clave
		 e inserta la lista con toda la información asociada a esa clave. Si el
		 diccionario no estuviera ordenado habría que usar la función sort()
		 */
		 void Insertar(const T& clave,const list<U> &info);

		 /*Añade una nueva informacion asocida a una clave que está en el diccionario.
		 la nueva información se inserta al final de la lista de información.
                  Si no esta la clave la inserta y añade la informacion asociada.
		 */
		 void AddSignificado_Palabra(const U & s ,const T &p);

		 /* Devuelve la información (una lista) asociada a una clave p. Podrían
		 haberse definido operator[] como
		 data<T,U> & operator[](int pos){ return datos.at(pos);}
		 const data<T,U> & operator[](int pos)const { return datos.at(pos);}
		  */
		  list<U>  getInfo_Asoc(const T & p);

			int getNumDefiniciones(list<U> l) const;

			void eliminar(const T clave);

			const T palabra_mas_definiciones();

			int total_definiciones();

			int promedio_Definiciones();

		/*Devuelve el tamaño del diccionario*/
		 int size()const;

		 class iterator{
		   private:
		     typename list<data<T,U> >::iterator it;
		   public:
		     iterator(){}
		     iterator & operator++(){
		       it ++;
		       // retorna un objeto de tipo iterator
		       return *this;
		     }
		     iterator & operator--(){
		       it--;
		       return *this;
		     }

		     data<const T,U> & operator*(){
		       return *it;
		     }

		     bool operator==(const iterator &i){
		       return it == i.it;
		     }

		     bool operator!=(const iterator &i){
		       return it != i.it;
		     }

		     friend class Diccionario;
		 };

		 class const_iterator{
		   private:
		     typename list<data<T,U> >::const_iterator it;
		   public:
		     const_iterator(){}
		     const_iterator & operator++(){
		       it ++;
		       // retorna un objeto de tipo iterator
		       return *this;
		     }
		     const_iterator & operator--(){
		       it--;
		       return *this;
		     }

		     const data<T,U> & operator*(){
		       return *it;
		     }

		     bool operator==(const const_iterator &i)const{
		       return it == i.it;
		     }

		     bool operator!=(const const_iterator &i)const{
		       return it != i.it;
		     }

		     friend class Diccionario;
		 };

		 /*Funciones begin y end asociadas al diccionario*/
     iterator begin(){
       iterator i;
       i.it = datos.begin();
       return i;
     }

     iterator end(){
       iterator i;
       i.it = datos.end();
       return i;
     }

     const_iterator begin()const{
       const_iterator i;
       i.it = datos.begin();
       return i;
     }

     const_iterator end()const{
       const_iterator i;
       i.it = datos.end();
       return i;
     }


};

#include <diccionario.cpp>
#endif
