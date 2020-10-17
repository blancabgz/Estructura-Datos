// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>


template <class M>
class Matriz
{
private:
	M **datos;
	int filas, columnas;

public:
	Matriz();

	Matriz(int f, int c);

	~Matriz();

	M getContenido (int fil, int col);

	int getFila ();

	int getColumna ();

	void insertarContenido (int fil, int col, const M &dato);

	void borrarContenido (int fil, int col);

};

#endif MATRIZ_H
