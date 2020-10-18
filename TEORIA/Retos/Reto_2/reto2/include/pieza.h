// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
#include "matriz.h"

using namespace std;

/**
 * @brief Pieza
 *
 * Una instancia del tipo de dato @c Pieza, es un objeto
 * compuesto por una matriz y sus filas y columnas  
 *
 * @author Blanca Abril González
 * @author Carlos Romero de la Puente
 * @date Octubre 2020
 */

class Pieza
{
private:
	matriz<bool> Pieza;
	int filas, columnas;

public:

	/**
	 * @brief Constructor sin parametros
	 */

	Pieza();

	/**
	 * @brief Constructor con dos parámetros, las filas y las columnas
	 * @param fila Numero de filas que tiene la pieza
	 * @param columna Numero de columnas que tiene la pieza
	 * @pre fila > 0 && fila != null
	 * @pre columna > 0 && columna != null
	 */

	Pieza(int fila, int columna);

	/**
	 * @brief Destructor de la clase Pieza
	 */

	~Pieza();

	/**
	 * @brief Rota la pieza
	 * @param pieza Pieza que se quiere rotar
	 * @param direccion en la que se quiere rotar (r = derecha, l = izquierda)
	 * @pre pieza != null
	 * @pre direccion != "r" || direccion != "l"
	 */

	bool rotarPieza(Pieza pieza, char direccion);

	/**
	 * @brief Consultor de las dimensiones de una pieza
	 * @param pieza Pieza de la que queremos conocer su dimension
	 * @pre pieza != null
	 */

	void consultarDimensiones(Pieza pieza);
