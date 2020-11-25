#include <iostream>
#include <list>
#include "utilidades.h"

using namespace std;

int main(){
  list<int> lista;
  int jugada, prediccion;

  cout << "Inicio del programa: " << endl;
  cout << "--------------------------------------------------" << endl;
  cout << "Introduce tus jugadas de esta forma " << endl;
  cout << "Piedra: 1" << endl;
  cout << "Papel: 2" << endl;
  cout << "Tijera: 3" << endl;
  cout << "Parar de meter jugadas: 0" << endl;
  cout << "--------------------------------------------------" << endl;

  // obtengo las jugadas del jugador hasta que meta un 0
  cout << "Introduce una jugada (0 para finalizar):" << endl;
  cin >> jugada;
  while(jugada != 0){
    if(jugada >= 4){
      cout << "Has introducido un numero inválido" << endl;
    }else{
      lista.push_back(jugada);
    }
    cout << "Introduce una jugada (0 para finalizar):" << endl;
    cin >> jugada;
  }

  cout << endl;
  cout << "Introduce el numero de jugadas que quieres que prediga" << endl;
  cin >> prediccion;
  cout << "--------------------------------------------------" << endl;

  // funcion para predecir la jugada
  int num = ppt(lista,prediccion);

  if(num != 0){
    if(num == 1){
        cout << "Tu proxima jugada es: Piedra" << endl;
    }else if(num==2){
      cout << "Tu proxima jugada es: Papel" << endl;
    }else{
      cout << "Tu proxima jugada es: Tijera" << endl;
    }
  }else{
    cout << "No puedo predecir tu jugada porque no has hecho esa jugada antes" << endl;
  }

}
