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
  // Filas y columnas imagen color entrada y filas y columnas imagen de salida
  int nf_imgcolor, nc_imgcolor, nf_imgris, nc_imgris;

  unsigned char *imagen_icono, *icono, *imgcolor, *imgconvertida, *img, *imgfinal_eg; //
  bool escribe_imagen, escribe_icono;

  // obtener argumentosescribeImagen =
  if(argc != 7){
    cout << "Numero erroneo de parametros. Debe haber 6 parametros.";
  }

  if(argv[2] > 0 && argv[3] > 0 && argv[4] > 0 && argv[5] > 0){
    t_1 = atoi(argv[2]);
    t_2 = atoi(argv[3]);
    nf = atoi(argv[4]);
    nc = atoi(argv[5]);
  }

  // ------------------------ UMBRALIZACIÓN------------------------------------

  // leemos la imagen que me han pasado por argumento
  img = LeerImagenPGM(argv[1], fila, columna);

  // creo una imagen
  Imagen imagen(fila, columna, img);


  // compara pixeles usando escala de grises
  imgfinal_eg = compararPixeles(imagen, fila, columna, t_1, t_2);

  //Sacas la imagen con el umbral hecho
  escribe_imagen = EscribirImagenPGM("./imagenespgmppm/castillomod.pgm", imgfinal_eg, fila, columna);


  if(!escribe_imagen){
    cout << "Ha ocurrido un error";
  }


  // ---------------------------- ICONO ----------------------------------------

  // Leemos la imagen que nos han pasado por parámetro
  imagen_icono = LeerImagenPGM(argv[1], fila_icon, columna_icon);

  // Creo la imagen para hacer el icono
  Imagen img_icono(fila_icon, columna_icon,imagen_icono);

  // Creación del icono
  icono = creaIcono(img_icono, nf, nc);


  // Escribimos la imagen iconizada
  escribe_icono = EscribirImagenPGM("./imagenespgmppm/castillomod.pgm", icono, nf, nc);

  // ---------------------------- PASAR RGB A GRIS ----------------------------------

  imgcolor = LeerImagenPPM(argv[6],nf_img, nc_img);
  imgconvertida = convertirAGris(imgcolor, nf_img, nc_img);
  bool escribe_imagen_gris = EscribirImagenPGM("./imagenespgmppm/imagen_convertida.pgm", imgconvertida, nf_img, nc_img);




  delete [] icono;
  delete [] imagen_icono;
  delete [] imgconvertida;

  delete [] img;
  delete [] imgfinal_eg;
  delete [] imgcolor;

}
