/**
 * @ file : guiatlf.h
 * @brief: TDA guia de telefonos
 * */

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>

using namespace std;

istream & operator>>(istream &is,pair<string,string> &d);

ostream & operator<<(ostream &os,const pair<const string,string> &d);


/**
  *  @brief T.D.A. Guia_Tlf
  *
  * Una instancia @e c del tipo de datos abstracto @c Guia_Tlf es un objeto
  * formado por una colección de pares {(e11,e21),(e12,e22),(e13,e23),...,(e1n-1,e2n-1)}
  * ordenados por la el primer elemento del par denominado clave o key. No existen
  * elementos repetidos.
  *
  *
  * Un ejemplo de su uso:
  *
  *
  * @author Rosa Rodríguez
  * @date Marzo 2012
  */

class Guia_Tlf{
  /**
  * @page repGuia_Tlf Rep del TDA Guia_Tlf
  *
  * @section invGuia_Tlf Invariante de la representación
  *
  * El invariante es \e para todo \e i y \e j tal que i<j entonces \e e1i y e1j son distintos
  *
  * @section faGuia_Tlf Función de abstracción
  *
  * Un objeto válido @e rep del TDA Guia_Tlf representa al valor
  *
  * {(rep.begin().first,rep.begin().second),(rep.begin()+1.first,rep.begin()+1.second),....,(rep.begin()+n-1.first,rep.begin()+n-1.second)}
  *
  */
    private:
        map<string,string> datos; //si admites que haya nombres repetidos tendrías que usar un
               //multimap

    public:

        /**
          @brief Acceso a un elemento
          @param nombre: nombre del elemento  elemento acceder
          @return devuelve el valor asociado a un nombre, es decir el teléfono
        */
        //si fuese un multimap no podriamos usar []. Ademas que deberiamos devolver p.e un vector con todos
        // los telefonos asociados a dicho nombre
        string & operator[](const string &nombre) {
            return datos[nombre];
        }


        string  gettelefono(const string & nombre);

        /**
          @brief Modificar contacto
          @param nombre: nombre que se quiere cambiar y otro telefono
          @note: esta funcion nos permite modificar el telefono asociado a ese nombre
        */

        bool modificar_contacto(const string &nombre,const string &otro_telef);

        /**
         * [sacar_contactos_letra description]
         * @param  letra [description]
         * @return       [description]
         */


        Guia_Tlf sacar_contactos_letra(const char &letra);

        Guia_Tlf sacar_contactos_numero(const string &numeros);

        /**
         @brief Insert un nuevo telefono
         @param nombre: nombre clave del nuevo telefono
         @param tlf: numero de telefono
         @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o
            o false en caso contrario
        */
        pair<map<string,string>::iterator,bool> insert(string nombre, string tlf);

        /**
         @brief Insert un nuevo telefono
         @param p: pair con el nombre y el telefono asociado

         @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o
            o false en caso contrario
        */
        pair<map<string,string>::iterator,bool>  insert(pair<string,string> p);
        /**
          @brief Borrar un telefono
          @param nombre: nombre que se quiere borrar
          @note: en caso de que fuese un multimap borraria todos con ese nombre
        */
        void borrar(const string &nombre);

        /**
          @brief Borrar un telefono
          @param nombre: nombre que se quiere borrar y telefono asociado
          @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
        */
        //con map siempre hay uno con multimap puede existir mas de uno
        void borrar(const string &nombre,const string &tlf);

        /**
         * @brief Borra toda la lista de telefonos
         * @return verdadero si se ha borrado
         */
        bool borrarTodo();

        /**
          @brief  Numero de telefonos
          @return el numero de telefonos asociados
         */
        int size()const;
        /**
          @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
          @param nombre: nombre sobre el que queremos consultar
          @return numero de telefonos asociados a un nombre

         */
        //al ser un map debe de ser 0 o 1. Si fuese un multimap podríamos tener mas de uno
        unsigned int contabiliza(const string &nombre);

        /**
          @brief Limpia la guia
         */
        void clear();
        /**
          @brief Union de guias de telefonos
          @param g: guia que se une
          @return: una nueva guia resultado de unir el objeto al que apunta this y g
        */
        Guia_Tlf operator+(const Guia_Tlf & g);

        /**
          @brief Diferencia de guias de telefonos
          @param g: guia a restar
          @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
        */
        Guia_Tlf operator-(const Guia_Tlf & g);

        Guia_Tlf operator*(const Guia_Tlf & g);

        /**
          @brief  Obtiene una guia con los nombre previos a uno dado
          @param nombre: nombre delimitador
          @param tlf: telefono asociado a nombre
          @return nueva guia sin nombres mayores que \a  nombre
         */
        Guia_Tlf previos(const string &nombre,const string &tlf);


        /**
          @brief Escritura de la guia de telefonos
          @param os: flujo de salida. Es MODIFICADO
          @param g: guia de telefonos que se escribe
          @return el flujo de salida
         */


        friend ostream & operator<<(ostream & os, Guia_Tlf & g);

        /**
          @brief Lectura de  la guia de telefonos
          @param is: flujo de entrada. ES MODIFICADO
          @param g: guia de telefonos. ES MODIFICADO
          @return el flujo de entrada
        */

        friend istream & operator>>(istream & is, Guia_Tlf & g);

        /**
         * @brief clase para iterar sobre la guia
         * */
        class iterator{
         private:
          map<string,string>::iterator it;
         public:
           iterator & operator++(){
             ++it;
             return *this;
           }
           iterator & operator--(){
             --it;
             return *this;
           }

           pair<const string,string> &operator*(){
             return *it;
           }

           iterator & operator= (const iterator &i){
             it = i.it;
             return *this;
           }

           bool operator==(const iterator &i){
             return i.it==it;
           }

           bool operator!=(const iterator &i){
             return i.it!=it;
           }

           friend class Guia_Tlf;
        };


        class const_iterator{
         private:
          map<string,string>::const_iterator it;
         public:
           const_iterator & operator++(){
             ++it;
             return *this;
           }
           const_iterator & operator--(){
             --it;
             return *this;
           }

           const pair<const string,string> &operator*(){
             return (*it);
           }

           const_iterator & operator= (const const_iterator &i){
             it = i.it;
             return *this;
           }

           bool operator==(const const_iterator &i){
             return i.it==it;
           }

           bool operator!=(const const_iterator &i){
             return i.it!=it;
           }

           friend class Guia_Tlf;
        };

        /**
         * @brief Inicializa un iterator al comienzo de la guia
         * */
        const_iterator begin() const{
          const_iterator i;
          i.it=datos.cbegin();
          return i;
        }
        /**
         * @brief Inicializa un iterator al final de la guia
         * */
        const_iterator end()const{
          const_iterator i;
          i.it=datos.cend();
          return i;
        }
        /**
         * @brief Inicializa un iterator al comienzo de la guia
         * */
        iterator begin(){
          iterator i;
          i.it=datos.begin();
          return i;
        }
        /**
         * @brief Inicializa un iterator al final de la guia
         * */
        iterator end(){
          iterator i;
          i.it=datos.end();
          return i;
        }




};
#endif
