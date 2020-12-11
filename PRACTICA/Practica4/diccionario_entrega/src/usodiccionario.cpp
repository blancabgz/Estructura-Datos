#include <iostream>
#include "diccionario.h"

/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre
listas de listas y otro sobre listas
*/
ostream & operator<<(ostream & os, const Diccionario<string,string> & D){
		// definimos un iterador sobre el diccionario
	  Diccionario<string, string>::const_iterator it;

	  for (it=D.begin(); it!=D.end(); ++it){

		    list<string>::const_iterator it_s;

		    os<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
		    for (it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
			      os<<(*it_s)<<endl;
		    }
		    os<<"*************************************************************"<<endl;
	  }

	  return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asociadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/

istream & operator >>(istream & is,Diccionario<string,string> &D){
	  int np;
	  is>>np;
	  is.ignore();//quitamos \n
	  Diccionario<string,string> Daux;
	  for (int i=0;i<np; i++){
		    string clave;

		    getline(is,clave);

		    int ns;
		    is>>ns;
		    is.ignore();//quitamos \n
		    list<string>laux;
		    for (int j=0;j<ns; j++){
			      string s;
			      getline(is,s);

			      // cout<<"Significado leido "<<s<<endl;
			      laux.insert(laux.end(),s);
		    }
		    Daux.Insertar(clave,laux);

	  }
	  D=Daux;
	  return is;
}

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string>&l){
	  list<string>::const_iterator it_s;

	  for (it_s=l.begin();it_s!=l.end();++it_s){
		    cout<<*it_s<<endl;
	  }
}


/*Lee un diccioario e imprime datos asociados a una clave.
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe:
                  ./usodiccionario < data.txt
*/
int main(){
	Diccionario<string,string> D;
	string palabra, b, max_def;

	cout << "\n\e[1;95m-------------------------------------DICCIONARIO---------------------------------------\e[0m" << endl;

	cin>>D;
	cout<<D;


	cin>>palabra;

	cout << "\n\e[1;95m--------------------------------------------------------------------------------------\e[0m" << endl;
	cout << "\e[1;95mObtener las definiciones de la palabra " << palabra << "\e[0m" << endl;
	cout << "\e[1;95m--------------------------------------------------------------------------------------\e[0m" << endl;

	list<string>l=D.getInfo_Asoc(palabra);
	if (l.size()>0)
		  EscribeSigni(l);
	else
		cout << "\e[0;31mNo se encuentra esta palabra en el diccionario\e[0m" << endl;

	cout << "\n\e[1;95m--------------------------------------------------------------------------------------\e[0m" << endl;
	cout << "\e[1;95m Obtener las palabras con más significados\e[0m" << endl;
	cout << "\e[1;95m--------------------------------------------------------------------------------------\e[0m" << endl;

	max_def = D.palabra_mas_definiciones();
	list<string>def=D.getInfo_Asoc(max_def);
	cout << "La palabra con más definiciones es " << max_def << " que tiene "
	<< D.getNumDefiniciones(def) << " definiciones" << endl;

	cout << "\n\e[1;95m--------------------------------------------------------------------------------------\e[0m" << endl;
	cout << "\e[1;95m Promedio de las definiciones por palabra\e[0m" << endl;
	cout << "\e[1;95m--------------------------------------------------------------------------------------\e[0m" << endl;

	cout << "El promedio de definiciones por palabra es " << D.promedio_Definiciones() << endl;

	cout << "\n\e[1;95m--------------------------------------------------------------------------------------\e[0m" << endl;
	cout << "\e[1;95m Numero de definiciones de una palabra\e[0m" << endl;
	cout << "\e[1;95m--------------------------------------------------------------------------------------\e[0m" << endl;

	int contador = D.getNumDefiniciones(l);
	if(contador == 0){
		cout << "La palabra " << palabra << "no tiene definiciones" << endl;
	}else if(contador == 1){
		cout << "La palabra " << palabra << " tiene " << contador << " definicion. "<<  endl;
	}else{
		cout << "La palabra " << palabra << " tiene " << contador << " definiciones. "<<  endl;
	}

	cout << "\n\e[1;95m--------------------------------------------------------------------------------------\e[0m" << endl;
	cout << "\e[1;95m Numero de palabras que tiene el diccionario antes del borrado\e[0m" << endl;
	cout << "\e[1;95m--------------------------------------------------------------------------------------\e[0m" << endl;

	cout << "El diccionario tiene " << D.size() << " palabras" << endl;

	cout << "\n\e[1;95m--------------------------------------------------------------------------------------\e[0m" << endl;
	cout << "\e[1;95m Numero de palabras que tiene el diccionario despues del borrado\e[0m" << endl;
	cout << "\e[1;95m--------------------------------------------------------------------------------------\e[0m" << endl;

	D.eliminar(palabra);
	cout << "El diccionario tiene " << D.size() << " palabras" << endl;

}
