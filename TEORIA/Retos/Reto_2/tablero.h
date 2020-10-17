// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>

class Tablero
{
private:
	matriz<bool> Tablero;
	int filas, columnas;

public:
	Tablero();

	Tablero(int fila, int columna);

	~Tablero();

	bool estaLibre(int fila, int columna);

	void consultarDimensiones(int & filas, int & columnas);

	bool encajaPieza(matriz<bool> pieza);

	void aniadeFilaAleat(int posFila);

	void eliminaLinea (int fila);

	bool hayLineaCompleta (int fila, int &linsComple);

};

#endif TABLERO_H
