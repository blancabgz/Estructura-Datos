/**
  * @file Pila_max.cpp
  * @brief Implementación del TDA Pila max
  *
  */

#include <cassert>
#include "Pila_max.h"

/* _________________________________________________________________________ */

template <class T>
Pila_max<T>::Pila_max(const Pila_max<T> & otra){
	if(otra.primera!=0){
		Celda *p = otra.primera;
		Celda *nueva;
		nueva = new Celda(p->elemento,0);					// Creamos el primer nodo
		p = p->siguiente;									// Avanzamos el puntero
		while(p != 0){
			nueva->siguiente = new Celda(p->elemento,0);	// Mientras queden elementos
			nueva = nueva->siguiente;						// Creamos un nuevo nodo
			p = p->siguiente;								// Avanzamos los punteros
		}
	} else{
		primera = 0;										// Si la pila original está vacía
	}
	num_elem = otra.num_elem;								// Copiamos el num_elem de la otra pila
}

/* _________________________________________________________________________ */

template <class T>
Pila_max<T>::~Pila(){
	Celda *aux;
	while (primera!=0){					// Mientras que la pila no esté vacía
		aux = primera;					// Copiamos el puntero al tope de la pila
		primera = primera->siguiente;	// Avanzamos la primera
		delete aux;						// Borramos el nodo de la pila max
	}
}

/* _________________________________________________________________________ */

template <class T>
Pila_max<T>& Pila_max::operator=(const Pila_max<T> & otra){
	Celda * p;

	if(this!=&otra){										// Comprobación de si son diferentes objetos
		while(primera!=0){									// Borramos la lista de nodos de la pila max *this
			p = primera;
			primera = primera->siguiente;
			detele p;
		}
		if(otra.primera!=0){								// Si la otra pila tiene elementos
			p = otra.primera;
			Celda *nueva;
			primera = nueva = new Celda(p->elemento,0);		// Reservamos el primer nodo
			p = p->siguiente;								// Avanzamos el puntero
			while(p!=0){									// Mientras queden elementos
				nueva->siguiente = new Celda(p->elemento,0);// Creamos un nuevo nodo
				nueva = nueva->siguiente;					// Avanzamos nueva (auxiliar)
				p = p->siguiente;							// Avanzamos el puntero
			}
		}
		num_elem = otra.num_elem;							// Copiamos el num_elem de la otra pila
	}
	return *this;											// Devolvemos el objeto para permitir el encadenamiento
}

/* _________________________________________________________________________ */

template <class T>
void Pila_max<T>::poner(const T & elem){
	primera = new Celda(elem, primera);		// Creamos un nuevo nodo en el tope
	num_elem++;								// Actualizamos num_elem
}

/* _________________________________________________________________________ */

template <class T>
void Pila_max<T>::quitar(){
	assert(primera!=0);					// Si la pila no tiene elementos, falla
	Celda *p = primera;					// Copiamos el puntero a tope
	primera = primera->siguiente;		// Actualizamos primera a la siguiente
	delete p;							// Eliminamos el nodo qe ocupaba el tope
	num_elem--;							// Actualizamos num_elem
}
