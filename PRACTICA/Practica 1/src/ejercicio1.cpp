#include <iostream>
#include <cmath>
#include <cstring>
#include "imagen.h"
#include "imagenES.h"
#include "utilidades.h"


using namespace std;


int main(int argc, char const *argv[]) {
  // definicion variables
  int fila,columna;
  int t_1, t_2;
  unsigned char *img, *imgfinal;
  bool escribeImagen;

  // obtener argumentos
  if(argc != 4){
    cout << "Numero erroneo de parametros. Debe haber 4 parametros.";
    exit (-1);
  }

  if(argv[2] > 0 && argv[3] > 0){
    t_1 = atoi(argv[2]);
    t_2 = atoi(argv[3]);
  }

  img = LeerImagenPGM(argv[1], fila, columna);

  Imagen imagen(fila, columna, img);

  int aux = 0;
  for(int i = 0; i < fila; i++){
    for(int j = 0; j < columna; j++){
      if(imagen.valor_pixel(i,j) != img[aux]){
        cout << "Son distintos" << endl;
      }
      aux++;
    }
  }
  imgfinal = compararPixeles(imagen, fila, columna, t_1, t_2);

  escribeImagen = EscribirImagenPGM("./imagenespgmppm/castillomod.pgm", img, fila, columna);

  if(escribeImagen != true){
    cout << "Ha ocurrido un error";
  }

  delete [] img;
  delete []imgfinal;
}
