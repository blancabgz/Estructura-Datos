template <class T>
void Lista<T>::Copiar(const Lista<T> & otra){
  primera=new Celda;
  primera->siguiente=primera->anterior=0;
  if (otra.primera->siguiente!=otra.primera->anterior){ // no está vacía
    const  typename  Lista<T>::Celda * q= otra.primera;
    typename Lista<T>::Celda *p=primera;
    while (q->siguiente !=0){
      Lista<T>::Celda *nuevo = new Celda(q->siguiente->elemento,0,p);
      p->siguiente = nuevo;
      q=q->siguiente;
      p=p->siguiente;
    }
    
 }
 num_elem=otra.num_elem;
}
    
/*****************************************************************/
template <class T>
void Lista<T>::Liberar(){
  while (primera->siguiente!=0){
    typename Lista<T>::Celda *aux = primera->siguiente;
    primera->siguiente = primera->siguiente->siguiente;
    delete aux;
  }
  primera->anterior=primera->siguiente;
}
/*****************************************************************/
template <class T>
Lista<T>::Lista(const Lista<T> & otra){
    Copiar(otra);
}

/*****************************************************************/
template <class T>
Lista<T>::~Lista(){
    Liberar();
    delete primera;
}    

/*****************************************************************/
template <class T>
Lista<T>& Lista<T>::operator= (const Lista<T>& otra){
  if (this!=&otra){
    Liberar();
    delete primera;
    Copiar(otra);
  }
  return * this;
}  

/*****************************************************************/
template <class T>
const T& Lista<T>::Get(int pos)const{
  assert(pos>=0 && pos<num_elem);
  int i=0;
  typename  Lista<T>::Celda* p=primera;
  while (p->siguiente!=0 && i<pos){
    p=p->siguiente; i++;
  }
  return p->siguiente->elemento;

}

/*****************************************************************/
template <class T>
 T& Lista<T>::Get(int pos){
  assert(pos>=0 && pos<num_elem);
  int i=0;
  typename  Lista<T>::Celda* p=primera;
  while (p->siguiente!=0 && i<pos){
    p=p->siguiente; i++;
  }
  return p->siguiente->elemento;

}

/*****************************************************************/
template <class T>
void Lista<T>::Set(int pos,const T &v){
  assert(pos>=0 && pos<num_elem);
  int i=0;
  typename  Lista<T>::Celda * p=primera;
  while (p->siguiente!=0 && i<pos){
    p=p->siguiente; i++;
  }
  p->siguiente->elemento=v;
}  
/*****************************************************************/
template <class T>
void Lista<T>::Insertar(int pos,const T & nuevo){
  assert(pos>=0 && pos<=num_elem);
  int i=0;
  typename  Lista<T>::Celda * p=primera;
  while (p->siguiente!=0 && i<pos){
     p=p->siguiente; i++;
  }
  Lista<T>::Celda* nueva=new Lista<T>::Celda(nuevo,p->siguiente,p);
  
  p->siguiente = nueva;
  if (nueva->siguiente!=0)
   nueva->siguiente->anterior = nueva;
  num_elem++;
}

/*****************************************************************/
template <class T>
void Lista<T>::Borrar(int pos){
  assert(pos>=0 && pos<num_elem);
  int i=0;
  typename  Lista<T>::Celda * p=primera;
  while (p->siguiente!=0 && i<pos){
     p=p->siguiente; i++;
  }
  Lista<T>::Celda * aux = p->siguiente;
  p->siguiente = aux->siguiente;
  if (aux->siguiente!=0)
   aux->siguiente->anterior = p;
  delete aux;
  num_elem--;
  
}
