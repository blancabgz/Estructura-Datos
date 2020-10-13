#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>

// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

class tablero
{
private: 
	matriz<bool> m;
	int filas, columnas;

public:
	tablero();

	tablero(int f, int c);

	~tablero();

	bool estaLibre(int fila, int columna);
	
};

#endif TABLERO_H