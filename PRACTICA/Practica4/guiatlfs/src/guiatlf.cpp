#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "guiatlf.h"

using namespace std;

istream & operator>>(istream &is,pair<string,string> &d){

    getline(is,d.first,'\t');
    getline(is,d.second);
    return is;
}

ostream & operator<<(ostream &os,const pair<const string,string> &d){

    os<<d.first<<'\t'<<d.second<<endl;
    return os;
}


string Guia_Tlf::gettelefono(const string & nombre){
    map<string,string>::iterator it=datos.find(nombre);
    if (it==datos.end())
      return string("");
    else return it->second;
}

bool Guia_Tlf::modificar_contacto(const string &nombre,const string &otro_telef){
  if(contabiliza(nombre) == 1){
    map<string,string>::iterator it=datos.find(nombre);
    it->second = otro_telef;
    return true;
  }
  return false;
}

Guia_Tlf Guia_Tlf::sacar_contactos_letra(const char &letra){
  Guia_Tlf aux;
  map<string,string>::iterator it;
  for (it=datos.begin();it != datos.end();++it){
    char nombre = it->first[0];
    if(nombre == toupper(letra)){
      aux.insert(*it);
    }
  }
  return aux;
}

Guia_Tlf Guia_Tlf::sacar_contactos_numero(const string &numeros){
  Guia_Tlf aux;
  string num;
  size_t found;

  map<string,string>::iterator it;
  for (it=datos.begin();it != datos.end();++it){
    num = it->second;
    found = num.find(numeros);
    if(found != std::string::npos){
      aux.insert(*it);
    }
  }
  return aux;
}

pair<map<string,string>::iterator,bool> Guia_Tlf::insert(string nombre, string tlf){
  pair<string,string> p (nombre,tlf);
  pair< map<string,string> ::iterator,bool> ret;

  ret=datos.insert(p); //datos.insert(datos.begin(),p); tambien funcionaría
  return ret;

}

pair<map<string,string>::iterator,bool> Guia_Tlf::insert(pair<string,string> p){

    pair<map<string,string> ::iterator,bool> ret;

    ret=datos.insert(p); //datos.insert(datos.begin(),p); tambien funcionaría
    return ret;

}


void Guia_Tlf::borrar(const string &nombre){
  map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
  map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
  if(itlow->first != nombre)return;
  datos.erase(itlow,itupper); //borramos todos aquellos que tiene dicho nombre
}

void Guia_Tlf::borrar(const string &nombre,const string &tlf){
 map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
 map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
 map<string,string>::iterator it;
 if(itlow->first != nombre) return;
 bool salir =false;
 for (it=itlow; it!=itupper && !salir;++it){
   if (it->second==tlf){
    datos.erase(it);
    salir =true;
   }
 }
}

bool Guia_Tlf::borrarTodo(){
  datos.clear();
  return true;
}

int Guia_Tlf::size()const{
    return datos.size();
}

unsigned int Guia_Tlf::contabiliza(const string &nombre){
    return datos.count(nombre);
}

void Guia_Tlf::clear(){
    datos.clear();
}

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf & g){
  Guia_Tlf aux(*this);
  map<string,string>::const_iterator it;
  for (it=g.datos.begin();it!=g.datos.end();++it){
     aux.insert(it->first,it->second);
  }
  return aux;
}

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf & g){
  Guia_Tlf aux(*this);
  map<string,string>::const_iterator it;
  for (it=g.datos.begin();it!=g.datos.end();++it){
     aux.borrar(it->first,it->second);
  }
  return aux;
}

Guia_Tlf Guia_Tlf::operator*(const Guia_Tlf & g){
  Guia_Tlf aux;
  map<string,string>::const_iterator it;

  for(it = g.datos.begin(); it != g.datos.end(); ++it){
    if(datos.find(it->first) != datos.end()){
      aux.insert(*it);
    }
  }
  return aux;
}

Guia_Tlf Guia_Tlf::previos(const string &nombre,const string &tlf){
  map<string,string>::value_compare vc=datos.value_comp(); //map<string,string>::key_compare vc=datos.key_comp()
  Guia_Tlf aux;
  pair<string,string>p(nombre,tlf);
  map<string,string>::iterator it=datos.begin();
  while (vc(*it,p)){
      aux.insert(*it++);

  }
  return aux;
}

ostream & operator<<(ostream & os, Guia_Tlf & g){
    map<string,string>::iterator it;
    for (it=g.datos.begin(); it!=g.datos.end();++it){
      os<<it->first<<"\t"<<it->second<<endl;
    }
    return os;
}

istream & operator>>(istream & is, Guia_Tlf & g){
    pair<string,string> p;
    Guia_Tlf aux;

    while (is>>p){
      aux.insert(p);
    }
    g=aux;
    return is;
}
