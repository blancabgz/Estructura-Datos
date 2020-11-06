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

  // leemos la imagen que me han pasado por argumento
  img = LeerImagenPGM(argv[1], fila, columna);

  // creo una imagen
  Imagen imagen(fila, columna, img);

  // compara pixeles
  imgfinal = compararPixeles(imagen, fila, columna, t_1, t_2);


  escribeImagen = EscribirImagenPGM("./imagenespgmppm/castillomod.pgm", imgfinal, fila, columna);

  if(!escribeImagen){
    cout << "Ha ocurrido un error";
  }

  delete [] img;
  delete []imgfinal;
}
