/**
  * @file pila_max_cola.cpp
*/

/* _________________________________________________________________________ */
template <class T>
Pila_max<T>::Pila_max(){
  cola = Cola< elemento<T> >();
}
/* _________________________________________________________________________ */

template <class T>
Pila_max<T>::Pila_max(const Pila_max<T> &copia){
  cola = copia.cola;
}

/* _________________________________________________________________________ */
template <class T>
bool Pila_max<T>::vacia(){
  return cola.vacia(); // devuelve true si la pila esta vacia
}
/* _________________________________________________________________________ */
template <class T>
elemento<T> Pila_max<T>::tope(){
    return cola.ultimo(); // devuelve el tope de la pila
}

/* _________________________________________________________________________ */
template <class T>
void Pila_max<T>::poner(T elem){
  if(!vacia()){
    T maximo = cola.ultimo().max; // obtengo el maximo del tope de la pila
    if(maximo < elem){ // si el maximo es menor que el elemento introducido, introducimos elemento
      maximo = elem;
    }

    elemento<T> celda (elem,maximo); // creamos un elemento
    cola.poner(celda); // introducimos el elemento
  }else{ // si esta vacia
    elemento<T> celda (elem,elem); // se mete el primer elemento y ese es el maximo
    cola.poner(celda); // introducimos el elemento
  }
}

/* _________________________________________________________________________ */
template <class T>
void Pila_max<T>::poner(elemento<T> elemento){
  cola.poner(elemento); // introducimos el objeto elemento
}

/* _________________________________________________________________________ */
template <class T>
T Pila_max<T>::tamano(){
  return cola.num_elementos(); // devuelve el numero de elementos
}

/* _________________________________________________________________________ */
template <class T>

void Pila_max<T>::quitar(){
  int tam = cola.num_elementos();
  if(!vacia()){ // si la pila no esta vacia
    for(int i= 0; i < tam - 1; i++){
      cola.poner(cola.frente());
      cola.quitar();
    }
    cola.quitar();
  }else{
    cout << "cola vacia" << endl;
  }
}
