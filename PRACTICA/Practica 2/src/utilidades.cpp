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


unsigned char *creaIcono(Imagen & img, int fila_icon, int cols_icono){
  unsigned char *icon = new unsigned char[fila_icon*cols_icono];
  int suma = 0;
  int nums = 0;
  int contador = 0;

  if(img.num_columnas() > cols_icono && img.num_filas() > fila_icon){
    // las reducciones tienen que ser proporcionales
    if(img.num_columnas() % cols_icono == 0 && img.num_filas() % fila_icon == 0){

      int total_filas = img.num_filas() / fila_icon;
      int total_col = img.num_columnas() / cols_icono;

      for(int fil = 0; fil < img.num_filas() - 1; fil += total_filas){
        for(int col = 0; col < img.num_columnas() - 1; col += total_col){
          for(int i = fil; i < total_filas + fil; i++){
            for(int j = col; j < total_col + col; j++){
              suma += img.valor_pixel(i,j);
              nums++;
            }
          }
            char total = suma/nums;
            icon[contador] = total;
            contador++;
            suma = 0;
            nums = 0;
        }
      }
    }else{
      cout << "Introduzca valores compatibles" << endl;
      return 0;
    }
  }else{
    cout << "No introduzca un valor mayor a la resolucion de la imagen" << endl;
    return 0;
  }


  return icon;
}



unsigned char * convertirAGris(unsigned char * imgcolor, int fila, int columna){
  unsigned char *imagen_gris = new unsigned char[fila*columna];
  int total = fila*columna*3;
  int aux = 0;

  for(int i = 0; i < total; i+=3){
    byte resultado = ((0.2989 * imgcolor[i]) + (0.587 * imgcolor[i+1]) + (0.114 * imgcolor[i+2]));
    imagen_gris[aux] = resultado;
    aux++;
  }
  return imagen_gris;
}
