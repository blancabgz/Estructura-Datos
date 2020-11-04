#include <iostream>
#include <cmath>
#include <cstring>
#include "imagen.h"
#include "imagenES.h"


using namespace std;


int main(int argc, char const *argv[]) {
  // definicion variables
  int fila1, fila2, columna1, columna2;
  int t_1, t_2;
  unsigned char *img1, *img2;

  // obtener argumentos
  if(argc != 5){
    cout << "Numero erroneo de parametros. Debe haber 4 parametros.";
  }

  if(argv[3] > 0 && argv[4] > 0){
    t_1 = atoi(argv[3]);
    t_2 = atoi(argv[4]);
  }

  img1 = LeerImagenPGM(argv[1], fila1, columna1);

  cout << fila1 << endl;
  cout << columna1 << endl;

  Imagen img_final;




  return 0;
}
