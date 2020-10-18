// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include "matriz.h"
#include "pieza.h"

using namespace std;

/**
 * @brief Tablero
 *
 * Una instancia del tipo de dato @c Tablero, es un objeto
 * compuesto por una matriz y sus filas y columnas  
 *
 * @author Blanca Abril González
 * @author Carlos Romero de la Puente
 * @date Octubre 2020
 */

class Tablero
{
private:
	matriz<bool> Tablero;
	int filas, columnas;

public:

	/**
	 * @brief Constructor sin parametros
	 */

	Tablero();

	/**
	 * @brief Constructor con dos parámetros, las filas y las columnas
	 * @param fila Numero de filas que tiene la pieza
	 * @param columna Numero de columnas que tiene la pieza
	 * @pre fila > 0 && fila != null
	 * @pre columna > 0 && columna != null
	 */

	Tablero(int fila, int columna);

	/**
	 * @brief Destructor de la clase Pieza
	 */

	~Tablero();

	/**
	 * @brief Consultor que nos dice si está libre esa posicion
	 * @param fila La posición en la fila
	 * @param columna La posición en la columna
	 * @pre fila >= 0 && fila <= filas
	 * @pre columna >= 0 && columna != columnas
	 */

	bool estaLibre(int fila, int columna);

	/**
	 * @brief Consulta por referencia las filas y las columnas
	 * @param fila La cantidad de filas
	 * @param columna La cantidad de columnas
	 */

	void consultarDimensiones(int & filas, int & columnas);

	/**
	 * @brief Consulta si una pieza puede encajar en una posición dada
	 * @param pieza Pieza que queremos encajar
	 * @param fila La posición en la fila
	 * @param columna La posición en la columna
	 * @pre pieza != null
	 * @pre fila >= 0 && fila <= filas
	 * @pre columna >= 0 && columna != columnas
	 */

	bool encajaPieza(Pieza & pieza, int fila, int columna);

	/**
	 * @brief Añade una fila en una posición dada
	 * @param posFila Posición donde queremos añadir la nueva fila
	 * @pre posFila >= 0
	 */

	void aniadeFila(int posFila);

	/**
	 * @brief Elimina una línea
	 * @param fila Posición donde queremos eliminar la linea
	 * @pre fila >= 0 && fila <= 0
	 */

	void eliminaLinea (int fila);

	/**
	 * @brief Comprueba que la línea está completa
	 * @param fila Posición donde queremos comprobar que la linea está completa
	 * @param linsComple Número de líneas completas
	 * @pre fila >= 0 && fila <= 0
	 */

	bool hayLineaCompleta (int fila, int &linsComple);

};

#endif TABLERO_H
