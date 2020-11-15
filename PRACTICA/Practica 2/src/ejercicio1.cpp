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
  unsigned char *img, *imgfinal_eg, *imgcolor;
  bool escribeImagen;

  // obtener argumentos
  if(argc != 4){
    cout << "Numero erroneo de parametros. Debe haber 4 parametros.";

  }

  if(argv[2] > 0 && argv[3] > 0){
    t_1 = atoi(argv[2]);
    t_2 = atoi(argv[3]);
  }

  // leemos la imagen que me han pasado por argumento
  img = LeerImagenPGM(argv[1], fila, columna);

  // creo una imagen
  Imagen imagen(fila, columna, img);

  // compara pixeles usando escala de grises
  imgfinal_eg = compararPixeles(imagen, fila, columna, t_1, t_2);


  //Sacas la imagen con el umbral hecho
  escribeImagen = EscribirImagenPGM("./imagenespgmppm/castillomod.pgm", imgfinal_eg, fila, columna);

  if(!escribeImagen){
    cout << "Ha ocurrido un error";
  }

  // imagen a color
  


  delete [] img;
  delete [] imgfinal_eg;
  delete [] imgcolor;

}
