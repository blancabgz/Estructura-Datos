// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>

class tablero
{
private:
	matriz<bool> matriz;
	int filas, columnas;

public:
	tablero();

	tablero(int f, int c);

	~tablero();

	bool estaLibre(int fila, int columna);

};

#endif TABLERO_H
