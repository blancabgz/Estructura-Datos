// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef COLA_PIEZA_H
#define COLA_PIEZA_H
#include <iostream>
#include "pieza.h"

using namespace std;

/**
 * @brief ColaPieza
 *
 * Una instancia del tipo de dato @c ColaPieza, es un objeto
 * compuesto por un vector cola, su tamaño inicial y el total de piezas que almacena
 *
 * @author Blanca Abril González
 * @author Carlos Romero de la Puente
 * @date Octubre 2020
 */

class ColaPieza
{
private:
	int tamInicial = 4;
	Pieza cola[tamInicial];
	int totalPiezas = 0;

public:

	/**
	 * @brief Constructor sin parametros
	 */

	ColaPieza();

	/**
	 * @brief Destructor de la clase Pieza
	 */

	~ColaPieza():

	/**
	 * @brief Coloca la pieza
	 * @param pieza Pieza que se quiere colocar
	 * @pre pieza != null
	 */

	void colocaPieza(Pieza &pieza);

	/**
	 * @brief Obtiene la siguiente pieza de la cola
	 */

	Pieza obtenerSiguiente();

	/**
	 * @brief Devuelve la pieza que hay en la posición indicada
	 * @param posicion Posicion de donde queremos la pieza
	 * @pre posicion >= totalPiezas && posicion <= totalPiezas
	 */

	Pieza consultaPieza(int posicion);

	/**
	 * @brief Añade una pieza al final de la cola
	 * @param pieza Pieza que queremos añadir
	 * @pre pieza != null
	 */

	void aniadePieza(Pieza &pieza);
}
