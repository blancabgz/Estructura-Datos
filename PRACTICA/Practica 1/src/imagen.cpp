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

Imagen::Imagen(){
    filas=0;
    cols=0;
    img=nullptr;
}

void Imagen::LiberaMemoria(){
    for(int i = 0; i < filas; i++){
        delete [] img[i];
    }
    delete [] img;
    this->filas = 0;
    this->cols = 0;
    this->img = nullptr;
}

void Imagen::ReservaMemoria(int fils, int columnas){
    filas = fils;
    cols = columnas;
    img = new byte *[filas];
    for(int i = 0; i < filas; i++){
        img[i] = new byte [cols];
    }
}

Imagen::Imagen(const Imagen &imagen){
    *this=imagen;
}

Imagen::Imagen(int filas, int cols){
    this->filas = filas;
    this->cols = cols;
    ReservaMemoria(filas, cols);
}

Imagen::~Imagen(){
    LiberaMemoria();
}

int Imagen::num_filas() const{
    return this->filas;
}

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
