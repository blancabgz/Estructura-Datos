// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
#include "matriz.h"

class Pieza
{
private:
	matriz<bool> Pieza;
	int filas, columnas;

public:
	Pieza();

	Pieza(int fila, int columna);

	~Pieza();

	bool rotarPieza(Pieza pieza);

	void consultarDimensiones(int & filas, int & columnas);
