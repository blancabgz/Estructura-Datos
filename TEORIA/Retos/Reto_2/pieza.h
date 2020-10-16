// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>

class pieza
{
private:
	matriz<bool> pieza;
	int filas, columnas;

public:
	pieza();

	pieza(int fila, int columna);

	~pieza();

	bool rotarPieza(Pieza pieza);

	void consultarDimensiones(int & filas, int & columnas);
