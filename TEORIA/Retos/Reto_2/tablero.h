// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>

class tablero
{
private:
	matriz<bool> tablero;
	int filas, columnas;

public:
	tablero();

	tablero(int fila, int columna);

	~tablero();

	bool estaLibre(int fila, int columna);

	void consultarDimensiones(int & filas, int & columnas);

	bool encajaPieza(matriz<bool> pieza);

};

#endif TABLERO_H
