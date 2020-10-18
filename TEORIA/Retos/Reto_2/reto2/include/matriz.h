// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>

using namespace std;

/**
 * @brief Matriz
 *
 * Un template del tipo de datos abstracto @c Matriz, se utiliza
 * para las clases @c Pieza y @c Tablero 
 *
 * @author Blanca Abril González
 * @author Carlos Romero de la Puente
 * @date Octubre 2020
 */

template <class M>
class Matriz
{
private:
	M **datos;
	int filas, columnas;

public:

	/**
	 * @brief Constructor sin parametros
	 */

	Matriz();

	/**
	 * @brief Constructor con dos parámetros, las filas y las columnas
	 * @param f Numero de filas que tiene la matriz
	 * @param c Numero de columnas que tiene la matriz
	 * @pre f > 0 && f != null
	 * @pre c > 0 && c != null
	 */

	Matriz(int f, int c);

	/**
	 * @brief Destructor de la clase Matriz
	 */

	~Matriz();

	/**
	 * @brief Obtenemos el valor que almacena la matriz
	 * @param fil Posicion de la fila
	 * @param col Posicion de la columna
	 * @pre fil >= 0 && fil <= filas
	 * @pre col >= 0 && col <= columnas
	 */

	M getContenido (int fil, int col);

	/**
	 * @brief Obtenemos el número de filas
	 */

	int getFila ();

	/**
	 * @brief Obtenemos el número de columnas
	 */

	int getColumna ();

	/**
	 * @brief Insertamos un valor dentro de la matriz
	 * @param fil Posicion de la fila
	 * @param col Posicion de la columna
	 * @param dato Dato que queremos introducir en la matriz
	 * @pre fil >= 0 && fil <= filas
	 * @pre col >= 0 && col <= columnas
	 * @pre dato != null
	 */

	void insertarContenido (int fil, int col, const M &dato);

	/**
	 * @brief Borramos un valor dentro de la matriz
	 * @param fil Posicion en la fila
	 * @param col Posicion en la columna
	 * @pre fil >= 0 && fil <= filas
	 * @pre col >= 0 && col <= columnas
	 */

	void borrarContenido (int fil, int col);

};

#endif MATRIZ_H
