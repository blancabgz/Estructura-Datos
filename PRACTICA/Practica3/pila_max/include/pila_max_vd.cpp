/**
  * @file pila_max_vd.cpp
*/

/* _________________________________________________________________________ */
template <class T>
Pila_max<T>::Pila_max(){

}

/* _________________________________________________________________________ */
template <class T>
Pila_max<T>::Pila_max(const Pila_max<T> &copia){
  v = vector< elemento<T> > (copia);
}

/* _________________________________________________________________________ */
template <class T>
bool Pila_max<T>::vacia(){
    return v.empty(); // devuelve true si la pila esta vacia
}

/* _________________________________________________________________________ */
template <class T>
void Pila_max<T>::poner(T elem){
  if(!vacia()){
    T maximo = v.back().max; // obtengo el maximo del tope de la pila
    if(maximo < elem){ // si el maximo es menor que el elemento introducido, introducimos elemento
      maximo = elem;
    }
    elemento<T> celda(elem, maximo); // creamos un elemento
    v.push_back(celda); // introducimos el elemento
  }else{ // si esta vacia
    elemento<T> celda(elem, elem); // se mete el primer elemento y ese es el maximo
    v.push_back(celda); // introducimos el elemento
  }
}

template <class T>
elemento<T> Pila_max<T>::tope(){
    return v.back(); // devuelve el tope de la pila
}

/* _________________________________________________________________________ */
template <class T>
void Pila_max<T>::quitar(){ // quitar el ultimo elemento del vector que corresponde con el tope de la lista
  v.pop_back();
}
