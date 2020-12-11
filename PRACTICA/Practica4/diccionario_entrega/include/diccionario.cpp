#include <iostream>
#include "diccionario.h"

using namespace std;


// ----------------------------------------------------------------------------
template <class T,class U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){
  if (datos.size()>0){

      typename list<data<T,U> >::iterator it;

      for (it=datos.begin(); it!=datos.end() ;++it){
    if ((*it).clave==p) {
        it_out=it;
        return true;
    }
    else if ((*it).clave>p){
        it_out=it;
        return false;
    }

      }

      it_out=it;
      return false;
  }
  else {
      it_out=datos.end();
      return false;
  }
}
// ----------------------------------------------------------------------------
template <class T,class U>
void Diccionario<T,U>::Insertar(const T& clave,const list<U> &info){
  typename list<data<T,U> >::iterator it;

  if (!Esta_Clave(clave,it)){
      data<T,U> p;
      p.clave = clave;
      p.info_asoci=info;

      datos.insert(it,p);

  }
}

// ----------------------------------------------------------------------------
template <class T,class U>
void Diccionario<T,U>::AddSignificado_Palabra(const U & s ,const T &p){
  typename list<data<T,U> >::iterator it;

  if (!Esta_Clave(p,it)){
     datos.insert(it,p);
  }

   //Insertamos el siginificado al final
   (*it).info_asoci.insert((*it).info_asoci.end(),s);
}

// ----------------------------------------------------------------------------
template <class T,class U>
list<U> Diccionario<T,U>::getInfo_Asoc(const T & p) {
   typename list<data<T,U> >::iterator it;

   if (!Esta_Clave(p,it)){
     return list<U>();
   }
   else{
     return (*it).info_asoci;
   }
}

// ----------------------------------------------------------------------------
template <class T,class U>
int Diccionario<T,U>::size()const{
    return datos.size();
}

// ----------------------------------------------------------------------------
template <class T,class U>
int Diccionario<T,U>::getNumDefiniciones(list<U> l) const{
  typename list<U>::const_iterator it;
  int contador = 0;

  for(it=l.begin(); it != l.end(); it++){
    contador++;
  }
  return contador;
}

// ----------------------------------------------------------------------------
template <class T,class U>
void Diccionario<T,U>::eliminar(const T clave){
  typename list<data<T,U> >::iterator it;

  for (it=datos.begin(); it!=datos.end() ;++it){
    if ((*it).clave==clave) {
      it = datos.erase(it);
    }
  }
}

// ----------------------------------------------------------------------------
template <class T,class U>
const T Diccionario<T,U>::palabra_mas_definiciones(){
  typename list<data<T,U> >::iterator it;
  data<T,U> dato_max;
  long unsigned int max = 0;

  for(it=datos.begin(); it!=datos.end(); ++it){
    if(max <= it->info_asoci.size()){
      max = it->info_asoci.size();
      dato_max = (*it);
    }
  }
  return dato_max.clave;
}

// ----------------------------------------------------------------------------
template <class T,class U>
int Diccionario<T,U>::total_definiciones(){
  typename list<data<T,U> >::iterator it;
  int definiciones = 0;

  for(it=datos.begin(); it!=datos.end(); ++it){
    definiciones += it->info_asoci.size();
  }
  return definiciones;
}

// ----------------------------------------------------------------------------
template <class T,class U>
int Diccionario<T,U>::promedio_Definiciones(){
  typename list<data<T,U> >::iterator it;
  int definiciones = total_definiciones();
  int palabras = size();
  int promedio;

  promedio = definiciones/palabras;
  return promedio;
}
