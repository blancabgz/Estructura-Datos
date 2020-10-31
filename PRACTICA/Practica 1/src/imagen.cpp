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

void Imagen::ReservaMemoria(int filas, int columnas){
  if (filas > 0 && columnas > 0){
    img = new byte *[filas];
    for(int i = 0; i < filas; i++){
        img[i] = new byte [cols];
    }
  }
}

Imagen::Imagen(){
    filas=0;
    cols=0;
    img=nullptr;
}

Imagen::Imagen(const Imagen &J){
    filas = J.filas;
    cols = J.cols;
    img = new byte *[filas];
    for(int i = 0; i < filas; i++){
        img[i] = new byte [cols];
    }
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < cols; j++){
            img[i][j] = J.img[i][j];
        }
    }
}

// [???] operator =

Imagen::Imagen(int filas, int cols){
    this->filas = filas;
    this->cols = cols;
    ReservaMemoria(filas, cols);
}

Imagen::~Imagen(){
    for(int i = 0; i < filas; i++){
        delete [] img[i];
    }
    delete [] img;
    this->filas = 0;
    this->cols = 0;
    this->img = nullptr;
}

int Imagen::num_filas() const{
    return this->filas;
}

int Imagen::num_columnas() const{
    return this->cols;
}

void Imagen::asigna_pixel(int fila, int col, unsigned char valor){
    if(fila >= 0 && fila < num_filas() &&
       col >= 0 && col < num_columnas() &&
       valor >= 0 && valor <= 255){
        img[fila][col] = valor;
    }
}

byte Imagen::valor_pixel(int fila, int col){
    byte valor;
    if(fila >= 0 && fila < num_filas() &&
       col >= 0 && col < num_columnas()){
        valor = img[fila][col];
    }
    return valor;
}


/* Fin Fichero: imagen.cpp */
