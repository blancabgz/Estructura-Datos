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
 cout<<"La guia insertada "<<g<<endl;
 cin.clear();
 cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 string n;

 while (getline(cin,n)&& n!= "-1"){
	   cout<<"Buscando "<<n<<"...."<<endl;
	   string tlf = g.gettelefono(n);
	   if (tlf==""){
		     cout<<"No existe ese nombre en la guia"<<endl;
	   }
	   else
	    cout<<"El telefono es "<<tlf<<endl;
	   cout<<"[Escriba -1 para finalizar] Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 }

 cin.clear();
 cout<<"Dime el nombre que quieres borrar"<<endl;


 while (getline(cin,n)&& n!= "-1"){
	   g.borrar(n);
	   cout<<"Ahora la guia es:"<<endl;
	   cout<<g<<endl;
	   cout<<"[Escriba -1 para finalizar] Dime el nombre que quieres borrar"<<endl;
 }

 string nombre_modificar;
 string telef;
 cout << "Introduce un contacto a modificar" << endl;
 getline(cin,nombre_modificar);
 cin.clear();
 cout << "Introduce el nuevo telefono " << endl;
 getline(cin,telef);
 cout << "Vamos a modificar el telefono " << telef << " en el contacto " << nombre_modificar << endl;

 if(g.modificar_contacto(nombre_modificar, telef)){
   cout << "Se ha modificado el contacto " << nombre_modificar << endl;
   cout<<g<<endl;
 }else{
   cout << "No se ha podido modificar el contacto " << nombre_modificar << " porque no está en la guía" <<  endl;
 }

 cin.clear();
 char letra;
 cout << "Introduce la letra para buscar " << endl;
 cin >> letra;
 Guia_Tlf guia_cortada = g.sacar_contactos_letra(letra);

 if(guia_cortada.size() > 0){
   cout << "Los contactos que empiezan por la letra " << letra << " son: " << endl;
   cout << guia_cortada << endl;
 }else{
   cout << "No hay contactos que empiecen por la letra " << letra << endl;
 }


 string numeros;
 cout << "Introduce un numero/numeros para buscar todos los telefonos que lo contienen" << endl;
 cin.clear();
 cin >> numeros;
 Guia_Tlf guia_cortada_num = g.sacar_contactos_numero(numeros);
 if(guia_cortada_num.size() > 0){
   cout << "Los contactos que contienen el numero/s " << numeros << " son: " << endl;
   cout << guia_cortada_num << endl;
 }else{
   cout << "No hay contactos que contengan el numero/s " << numeros << endl;
 }


 if( g.borrarTodo()){
   cout << "Borrando ... " << endl;
   cout << "Tiene " << g.size() << " elementos" << endl;
 }else{
   cout << "No se ha podido borrar la guia telefonica" << endl;
 }



 // cin.clear();
 // string nombre_guia;
 // Guia_Tlf otraguia;
 // cout<<"Introduce otra guia ([Pulse CTRL+D para finalizar])"<<endl;
 // cin>>nombre_guia;
 //
 // ifstream f_otraguia(nombre_guia);
 //
 // if (!f_otraguia){
 //     cout<<"No puedo abrir el fichero "<<nombre_guia<<endl;
 //     return 0;
 // }
 // f_otraguia>>otraguia;
 // Guia_Tlf un = g+otraguia;
 // Guia_Tlf dif = g-otraguia;
 // cout<<endl<<"La union de las dos guias: "<<un<<endl;
 //
 // cout<<endl<<"La diferencia de las dos guias:"<<dif<<endl;
 //
 // cout<<endl<<"Dime un nombre para establecer los previos"<<endl;
 // cin>>n;
 // string tlf= g.gettelefono(n);
 // Guia_Tlf p = g.previos(n,tlf);
 // cout<<endl<<"Los nombre previos: "<<p<<endl;
 //
 //
 // cout<<"Listando la guia con iteradores:"<<endl;
 // Guia_Tlf::iterator it;
 // for (it=g.begin(); it!=g.end(); ++it)
 //     cout<<*it<<endl;

}
