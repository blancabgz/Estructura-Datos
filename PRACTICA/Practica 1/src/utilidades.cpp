#include "utilidades.h"
#include "imagen.h"
#include <iostream>
using namespace std;

unsigned char *compararPixeles(Imagen img, int fils, int cols, int t1, int t2){
  unsigned char *res= new unsigned char[fils*cols];
  int aux = 0;

  for(int i = 0; i < fils; i++){
    for(int j = 0; j < cols; j++){
      // if(img.valor_pixel(i,j) <= t1 || img.valor_pixel(i,j) >= t2){
      //   res[aux] = 255;
      // }else{
        res[aux] = img.valor_pixel(i,j);
      // }
      aux++;
    }
  }

  return res;
}
