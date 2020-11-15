#include <iostream>
#include <cmath>
#include <cstring>
#include "imagen.h"
#include "imagenES.h"
#include "utilidades.h"


using namespace std;


int main(int argc, char const *argv[]) {
  // definicion variables
  int fila,columna, fila_icon, columna_icon;
  // Valores umbralizaci´on
  int t_1, t_2;
  // Filas y columnas del icono
  int nf, nc;

  unsigned char *imagen_icono, *icono; //*img, *imgfinal_eg, *imgcolor,
  bool escribe_imagen, escribe_icono;

  // obtener argumentosescribeImagen =
  if(argc != 6){
    cout << "Numero erroneo de parametros. Debe haber 6 parametros.";
  }

  if(argv[2] > 0 && argv[3] > 0 && argv[4] > 0 && argv[5] > 0){
    t_1 = atoi(argv[2]);
    t_2 = atoi(argv[3]);
    nf = atoi(argv[4]);
    nc = atoi(argv[5]);
  }

  // leemos la imagen que me han pasado por argumento
  //img = LeerImagenPGM(argv[1], fila, columna);

  // creo una imagen
  //Imagen imagen(fila, columna, img);

  // ------------------------ UMBRALIZACIÓN ------------------------------------

  /*
  // compara pixeles usando escala de grises
  imgfinal_eg = compararPixeles(imagen, fila, columna, t_1, t_2);

  //Sacas la imagen con el umbral hecho
  escribe_imagen = EscribirImagenPGM("./imagenespgmppm/castillomod.pgm", imgfinal_eg, fila, columna);
  */

  // if(!escribe_imagen){
  //   cout << "Ha ocurrido un error";
  // }


  // ---------------------------- ICONO ----------------------------------------

  // Leemos la imagen que nos han pasado por parámetro
  imagen_icono = LeerImagenPGM(argv[1], fila_icon, columna_icon);

  // Creo la imagen para hacer el icono
  Imagen img_icono(fila_icon, columna_icon,imagen_icono);

  // Creación del icono
  icono = creaIcono(img_icono, nf, nc);

  // Escribimos la imagen iconizada
  escribe_icono = EscribirImagenPGM("./imagenespgmppm/castillomod.pgm", icono, nf, nc);

  delete [] icono;
  delete [] imagen_icono;

  // delete [] img;
  // delete [] imgfinal_eg;
  // delete [] imgcolor;

}
