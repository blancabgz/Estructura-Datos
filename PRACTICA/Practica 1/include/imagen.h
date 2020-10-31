/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   imagen.h
 * Author: Blanca Abril y Carlos Romero
 *
 * Created on 25 de octubre de 2020, 11:05
 */

/**
  * @file Imagen.h
  * @brief Fichero cabecera para la E/S de imágenes
  *
  * Permite la E/S de archivos de tipo PGM,PPM
  *
  */



#ifndef _IMAGEN_H_
#define _IMAGEN_H_

typedef unsigned char byte;  // tipo base de cada pixel

class Imagen{

  private:

    // Definición de los tipos para manejar imagenes digitales. Es solo un ejemplo de lo que
    // podría ser esta parte privada.

    int filas;     // Número de filas de la imagen
    int cols;      // Número de columnas de la imagen
    byte **img;    // La imagen en si: una matriz dinamica 2D de bytes

  public:

    void ReservaMemoria(int filas, int columnas);

    Imagen();

    Imagen(const Imagen &J);

    // [???] operator =

    /****************************************************************************/
    // Funcion: Imagen(int filas, int cols)
    // Tarea:   Crear una imagen en memoria con "filas" filas y "cols" columnas.
    //          Reserva memoria para alojar la imagen de "filas" x "cols" pixeles.
    // Recibe:  int filas, Número de filas de la imagen.
    //          int cols, Número de columnas de la imagen.
    // Devuelve: imagen, la imagen creada.
    // Comentarios://     1. Operación de tipo constructor.
    //     2. La imagen creada contiene "filas" filas y "cols" columnas.
    //     3. La imagen creada no esta inicializada.
    /*****************************************************************************/
    Imagen(int filas, int cols);

    /****************************************************************************/
    // Funcion: ~Imagen()// Tarea:   Liberar los recursos ocupados por la imagen.
    // Devuelve: void.
    // Comentarios:
    //     1. Operación de tipo destructor.
    //     2. La imagen destruida no puede usarse, salvo que se cree de nuevo.
    /****************************************************************************/

    ~Imagen();

    /****************************************************************************/
    // Funcion: int num_filas()  const
    // Tarea:   Calcular el numero de filas de la imagen.
    // Devuelve: int, Número de filas de la imagen.
    // Comentarios: La imagen no se modifica.
    /****************************************************************************/

    int num_filas() const;

    /****************************************************************************/
    // Funcion: int num_columnas() const
    // Tarea:   Calcular el numero de columnas de la imagen "i".
    // Devuelve: int, Número de columnas de la imagen.
    // Comentarios: La imagen no se modifica.
    /****************************************************************************/

    int num_columnas() const;

    /****************************************************************************/
    // Funcion: void asigna_pixel(int fila, int col, byte valor);
    // Tarea:   Asignar el valor "valor" al pixel ("fila", "col") de la imagen
    // Recibe:  int fila, \   fila y columna de la imagen "i"
    //          int col,  /   en la que escribir.
    //          byte valor, valor a escribir.
    // Precondiciones:
    //     1. 0 <= "fila" < i.num_filas()
    //     2. 0 <= "col" < i.num_columnas()
    //     3. 0 <= valor <= 255// Devuelve: void.
    // Postcondiciones:
    //     1. "i"("fil","col") == "valor".
    //     2. Los restantes píxeles no se modifican.
    /****************************************************************************/

    void asigna_pixel(int fila, int col, unsigned char valor);

    /****************************************************************************/
    // Funcion: byte valor_pixel (int fila, int col)  const
    // Tarea:   Consultar el valor de la casilla ("fila", "col") de la imagen
    // Recibe:  int fila, \   fila y columna de la imagen "i"
    //          int col,  /   a consultar.
    // Precondiciones:
    //     1. 0 <= "fila" < i.num_filas ()
    //     2. 0 <= "coln.h:61:1:" < i.num_columnas ()
    // Devuelve: byte, valor de "i"("fila","col").
    // Comentarios: La imagen no se modifica.
    /****************************************************************************/

    byte valor_pixel(int fila, int col);


  };

#endif

/* Fin Fichero: imagen.h */
