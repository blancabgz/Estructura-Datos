
// File:   utilidades.h
// Author: Blanca Abril y Carlos Romero


#ifndef UTILIDADES_H
#define UTILIDADES_H
#include "imagen.h"

/****************************************************************************/
// Funcion: compararPixeles(Imagen & img, int fils, int cols, int t1, int t2);
// Tarea:   Generar a partir de una imagen origial otra imagen donde un pixel
//          de la imagen original tiene que tener un nivel de gris comprendido
//          entre los umbrales t1 y t2 que pasa el usuario por consola.
//
//          Si O(i,j) <= t1 ó O(i,j) >= t2 entonces ponemos 255
//          Si t1 < O(i,j) < t2 entonces dejamos el valor del pixel de esa posicion

// Recibe:  Imagen & img, Imagen original.
//          int fils, Filas que tiene la imagen.
//          int cols, Columnas que tiene la imagen.
//          int t1, umbral más bajo
//          int t2, umbral más alto

// Devuelve: unsigned char *.
/*****************************************************************************/

unsigned char *compararPixeles(Imagen & img, int fils, int cols, int t1, int t2);

/****************************************************************************/
// Funcion: creaIcono(Imagen & img, int fils_icono, int cols_icono);
// Tarea: Crear un icono a partir de una imagen original pasada por usuario
//        con las filas y columnas que nos indique también.
//
// Recibe:  Imagen & img, Imagen original.
//          int fils_icono, Filas del icono.
//          int cols_icono, Columnas del icono
// Devuelve: unsigned char *.
/*****************************************************************************/

unsigned char *creaIcono(Imagen & img, int fils_icono, int cols_icono);

/****************************************************************************/
// Funcion: convertirAGris(unsigned char * imgcolor, int fila, int columna); (opcional)
// Tarea: Transformar una imagen en color RGB a una imagen con escala de grises
//        con la fórmula:
//        Igris(i, j) = 0,2989 × R(i, j) + 0,587 × G(i, j) + 0,114 × B(i, j)
// Recibe:  unsigned char * imgcolor, Vector con los bytes de la imagen a color
//          int fila, Filas de la imagen
//          int columna, Columnas de la imagen
// Devuelve: unsigned char *.
/*****************************************************************************/

unsigned char * convertirAGris(unsigned char * imgcolor, int fila, int columna);

#endif
