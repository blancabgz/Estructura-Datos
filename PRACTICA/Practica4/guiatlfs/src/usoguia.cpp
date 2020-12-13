#include <fstream>
#include "guiatlf.h"

using namespace std;

int main(int argc , char * argv[]){
  if (argc!=2){
      cout<<"Dime el nombre del fichero con la guia"<<endl;
      return 0;
  }
  ifstream f(argv[1]);
  if (!f){
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }

 Guia_Tlf g;

 f>>g;
 cout << "\n\e[1;34m-------------------------------------GUIA TELEFONICA--------------------------------\e[0m" << endl;
 cout<< "\n" <<g<<endl;
 cin.clear();

 cout << "\e[1;34m--------------------------------------------------------------------------------------\e[0m" << endl;
 cout << "\e[1;34mObtener el telefono de un contacto\e[0m" << endl;
 cout << "\e[1;34m--------------------------------------------------------------------------------------\e[0m" << endl;

 cout<<"\nDime un nombre sobre el que quieres obtener el telefono"<<endl;
 string n;

 while (getline(cin,n)&& n!= "-1"){
	   cout<<"Buscando "<<n<<"...."<<endl;
	   string tlf = g.gettelefono(n);
	   if (tlf==""){
		     cout<<"\e[1;31mNo existe ese nombre en la guia\e[0m"<<endl;
	   }
	   else
	    cout<<"\nEl telefono es "<<tlf<<endl;
	   cout<<"[Escriba -1 para finalizar] Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 }

 cin.clear();
 cout << "\n\e[1;34m--------------------------------------------------------------------------------------\e[0m" << endl;
 cout << "\e[1;34mBorrar un contacto\e[0m" << endl;
 cout << "\e[1;34m--------------------------------------------------------------------------------------\e[0m" << endl;

 cout<<"Dime el nombre que quieres borrar"<<endl;


 while (getline(cin,n)&& n!= "-1"){
	   g.borrar(n);
	   cout<<"\nAhora la guia es:\n"<<endl;
	   cout<<g<<endl;
	   cout<<"[Escriba -1 para finalizar] Dime el nombre que quieres borrar"<<endl;
 }

 cout << "\n\e[1;34m--------------------------------------------------------------------------------------\e[0m" << endl;
 cout << "\e[1;34mModificar un contacto\e[0m" << endl;
 cout << "\e[1;34m--------------------------------------------------------------------------------------\e[0m" << endl;

 string nombre_modificar;
 string telef;

 cin.clear();
 cout << "Introduce un contacto a modificar" << endl;

 while (getline(cin,nombre_modificar) && nombre_modificar!= "-1"){
   if(g.contabiliza(nombre_modificar) != 0){
     cout << "Introduce el nuevo telefono " << endl;
     getline(cin,telef);
     g.modificar_contacto(nombre_modificar, telef);
     cout << "Se ha modificado el contacto " << nombre_modificar << endl;
     cout << "\nGuia telefonica modificada: \n" << endl;
     cout<<g<<endl;
     cout << "\n\e[1;34m[Escriba -1 para finalizar]\e[0m Introduce un contacto a modificar" << endl;
   }else{
     cout << "\n\e[1;31mNo se ha podido modificar el contacto " << nombre_modificar << " porque no está en la guía\e[0m" <<  endl;
     cout << "\n\e[1;34m[Escriba -1 para finalizar]\e[0m Introduce un contacto a modificar" << endl;
   }
 }

 cout << "\n\e[1;34m--------------------------------------------------------------------------------------\e[0m" << endl;
 cout << "\e[1;34mMostrar la guia de todos los contactos que empiezan por la letra que indica el usuario\e[0m" << endl;
 cout << "\e[1;34m--------------------------------------------------------------------------------------\e[0m" << endl;

 cin.clear();
 char letra;
 cout << "Introduce la letra para buscar " << endl;
 cin >> letra;
 Guia_Tlf guia_cortada = g.sacar_contactos_letra(letra);

 if(guia_cortada.size() > 0){
   cout << "Los contactos que empiezan por la letra " << letra << " son: " << endl;
   cout << guia_cortada << endl;
 }else{
   cout << "\e[1;31mNo hay contactos que empiecen por la letra " << letra << "\e[0m" << endl;
 }

 cout << "\e[1;34m---------------------------------------------------------------------------------------------------\e[0m" << endl;
 cout << "\e[1;34mMostrar la guia de todos los contactos cuyo telefono contenta el/los numero/s que indica el usuario\e[0m" << endl;
 cout << "\e[1;34m----------------------------------------------------------------------------------------------------\e[0m" << endl;

 string numeros;
 cout << "Introduce un numero/numeros para buscar todos los telefonos que lo contienen" << endl;
 cin.clear();
 cin >> numeros;
 Guia_Tlf guia_cortada_num = g.sacar_contactos_numero(numeros);
 if(guia_cortada_num.size() > 0){
   cout << "\nLos contactos que contienen el numero/s " << numeros << " son:\n " << endl;
   cout << guia_cortada_num << endl;
 }else{
   cout << "\n\e[1;31mNo hay contactos que contengan el numero/s " << numeros << "\e[0m" << endl;
 }

 cout << "\e[1;34m---------------------------------------------------------------------------------------------------\e[0m" << endl;
 cout << "\e[1;34mBorrar la guía telefónica\e[0m" << endl;
 cout << "\e[1;34m----------------------------------------------------------------------------------------------------\e[0m" << endl;

 if( g.borrarTodo()){
   cout << "Borrando ... " << endl;
   cout << "Tiene " << g.size() << " elementos" << endl;
 }else{
   cout << "No se ha podido borrar la guia telefonica" << endl;
 }

}
