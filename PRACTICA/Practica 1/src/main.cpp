#include <iostream>
#include <cmath>
#include <cstring>
#include "imagen.h"


using namespace std;


int main(int argc, char const *argv[]) {

  int nf, nc;

  if(argc < 3){
    cout << "Numero erroneo de parametros. Debe haber 2 parametros.";
  }

  if(argv[1] > 0 && argv[2] > 0){
    nf = atoi(argv[1]);
    nc = atoi(argv[2]);
  }

  Imagen I(nf, nc);

  for (int f=0; f < I.num_filas (); f++)
    for (int c=0; c < I.num_columnas (); c++)
      I.asigna_pixel (f, c, 255);

  for(int f = 0; f < I.num_filas(); f++){         // lado izquierdo
    I.asigna_pixel (f, 0, 0);
  }

  for (int f=0; f < I.num_filas(); f++){          // lado derecho
    I.asigna_pixel(f, I.num_columnas() -1 , 0);
  }

  for(int c = 0; c < I.num_columnas(); c++){      // lado superior
    I.asigna_pixel(0,c,0);
  }

  for(int c = 0; c < I.num_columnas(); c++){      // lado inferior
     I.asigna_pixel (I.num_filas () - 1, c, 0);
  }

  // resultado

  for(int i = 0; i < I.num_filas(); i++){
    for(int j = 0; j < I.num_columnas(); j++){
      cout << I.valor_pixel(i,j) << " ";
    }
    cout << endl;
  }
  return 0;
}
