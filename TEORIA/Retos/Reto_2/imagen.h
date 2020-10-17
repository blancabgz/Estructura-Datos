// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef IMAGEN_H
#define IMAGEN_H
#include <iostream>
#include "tablero.h"
#include "colaPieza.h"

class Imagen
{
public:
	bool guardaJuego(std::ostream fichero);

	bool cargaJuego(std::istream fichero);

	void dibujaJuego();

	void dibujaTablero(Tablero tablero);

	void dibujaCola(ColaPieza colaPieza);

	void dibujaMarcadores();
}