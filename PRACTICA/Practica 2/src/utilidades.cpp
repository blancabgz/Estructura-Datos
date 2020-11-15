#include "utilidades.h"
#include "imagen.h"
#include <cmath>
#include <iostream>
using namespace std;


unsigned char *compararPixeles(Imagen & img, int fils, int cols, int t1, int t2){
  unsigned char *res= new unsigned char[fils*cols];
  int aux = 0;

  for(int i = 0; i < fils; i++){
    for(int j = 0; j < cols; j++){
      if(img.valor_pixel(i,j) <= t1 || img.valor_pixel(i,j) >= t2){
        res[aux] = 255;
      }else{
        res[aux] = img.valor_pixel(i,j);
      }
      aux++;
    }
  }

  return res;
}


unsigned char *creaIcono(Imagen & img, int fils_icono, int cols_icono){
  unsigned char *icon = new unsigned char[fils_icono*cols_icono];
  int aux = 0;

  int filas_a_recorrer = ceil(img.num_filas() / fils_icono);
  int columnas_a_recorrer = ceil(img.num_columnas() / cols_icono);

  // Si la imagen es par
  if(img.num_filas() % 2 == 0 && img.num_columnas() % 2 == 0){
    // Controlamos que las dimensiones a reducir sean divisores del tamaño
    if(img.num_filas() % filas_a_recorrer == 0 && img.num_columnas() % columnas_a_recorrer == 0){
      for(int i = 0; i < img.num_filas(); i += filas_a_recorrer){
        for(int j = 0; j < img.num_columnas(); j += columnas_a_recorrer){
          icon[aux] = (img.valor_pixel(i,j) + img.valor_pixel(i,j+cols_icono) + img.valor_pixel(i+fils_icono,j) + img.valor_pixel(i+fils_icono,j+cols_icono)) / fils_icono;
          aux++;
        }
      }
    }
  } else{
    cout << "La imagen es impar" << endl;
  }

  return icon;
}
