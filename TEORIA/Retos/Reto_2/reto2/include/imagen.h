// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef IMAGEN_H
#define IMAGEN_H
#include <iostream>
#include "tablero.h"
#include "colaPieza.h"

using namespace std;

/**
 * @brief Imagen
 *
 * Una instancia del tipo de dato @c Imagen, es un objeto
 * compuesto por un tablero, la cola de piezas y la puntación
 *
 * @author Blanca Abril González
 * @author Carlos Romero de la Puente
 * @date Octubre 2020
 */

class Imagen
{
private:
	Tablero tablero;
	ColaPieza colaPieza;
	int puntuacion;

public:

	/**
	 * @brief Constructor sin parametros
	 */

	Imagen();

	/**
	 * @brief Destructor de la clase Pieza
	 */

	~Imagen();

	/**
	 * @brief Guarda el juego en un fichero externo
	 * @param fichero Fichero en el que queremos guardar la partida
	 */

	bool guardaJuego(std::ostream fichero);

	/**
	 * @brief Carga el juego de un fichero
	 * @param fichero Fichero en el que se aloja la partida
	 */

	bool cargaJuego(std::istream fichero);

	/**
	 * @brief Muestra la interfaz del juego
	 */

	void dibujaJuego();

	/**
	 * @brief Dibuja solo el tablero de la partida
	 */

	void dibujaTablero();

	/**
	 * @brief Dibuja solo la cola de piezas de la partida
	 */

	void dibujaCola();

	/**
	 * @brief Devuelve la puntuacion de la partida
	 */

	int getPuntuacion();

	/**
	 * @brief Dibuja los marcadores con la puntuación de la partida
	 */

	void dibujaMarcadores();
}
