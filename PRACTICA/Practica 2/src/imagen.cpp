 /**
  * @file imagen.cpp
  * @brief Fichero con definiciones para la E/S de imágenes
  *
  * Permite la E/S de archivos de tipo PGM,PPM
  *
  */

#include <iostream>
#include <fstream>
#include <string>
#include "imagen.h"

using namespace std;


void Imagen::LiberaMemoria(){
  if(this->img != nullptr){
    for(int i = 0; i < fils; i++){
      delete [] img[i];
    }
    delete [] img;
  }

  this->fils = 0;
  this->cols = 0;
  this->img = nullptr;
}

void Imagen::ReservaMemoria(int fils, int cols){
    this->fils = fils;
    this->cols = cols;

    img = new byte *[fils];
    for(int i = 0; i < fils; i++){
        img[i] = new byte [cols];
    }
}

// Constructor por defecto

Imagen::Imagen(){
    fils=0;
    cols=0;
    img=nullptr;
}

// Constructores por parametros
Imagen::Imagen(int fils, int cols){
    ReservaMemoria(fils, cols);
}

Imagen::Imagen(int fils, int cols, unsigned char * datos){
  // creamos una imagen con num_filas y num_columnas
  ReservaMemoria(fils, cols);

  // contador auxiliar
  int aux = 0;

  // rellenar los npixeles
  for(int i = 0; i < fils; i++){
    for(int j = 0; j < cols; j++){
      asigna_pixel(i,j,datos[aux]);
      aux++;
    }
  }

}

// Constructor de copia
Imagen::Imagen(const Imagen &imagen){
    *this=imagen;
}


//Destructor
Imagen::~Imagen(){
    LiberaMemoria();
}

// obtener num filas
int Imagen::num_filas() const{
    return this->fils;
}

// obtener num columnasmagen(fila, columna,
int Imagen::num_columnas() const{
    return this->cols;
}

void Imagen::asigna_pixel(int fila, int col, byte valor){
    if(fila >= 0 && fila < num_filas() &&
       col >= 0 && col < num_columnas() &&
       valor >= 0 && valor <= 255){
        img[fila][col] = valor;
    }
}

byte Imagen::valor_pixel(int fila, int col) const{
    byte valor;
    if(fila >= 0 && fila < num_filas() &&
       col >= 0 && col < num_columnas()){
        valor = img[fila][col];
    }
    return valor;
}

Imagen &Imagen::operator=(const Imagen &imge){
    byte valor;
    LiberaMemoria();
    ReservaMemoria(imge.num_filas(), imge.num_columnas());
    for(int i = 0; i < imge.num_filas(); i++){
      for(int j = 0; j < imge.num_columnas(); j++){
         valor = imge.valor_pixel(i,j);
        //this->asigna_pixel(i,j,valor);
      }
    }
    return *this;
}


/* Fin Fichero: imagen.cpp */
