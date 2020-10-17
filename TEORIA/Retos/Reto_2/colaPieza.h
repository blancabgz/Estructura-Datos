// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef COLA_PIEZA_H
#define COLA_PIEZA_H
#include <iostream>
#include "pieza.h"

class ColaPieza
{
private:
	int tamInicial = 4;
	Pieza cola[tamInicial];
	int totalPiezas = 0;

public:

	void colocaPieza(Pieza &pieza);

	Pieza obtenerSiguiente();

	Pieza consultaPieza(int posicion);

	void aniadePieza(Pieza &pieza);
}