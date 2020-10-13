#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>

// Alumnos: Blanca Abril González
//			Carlos Romero de la Puente

template <class M>
class matriz
{
private: 
	M **datos;
	int filas, columnas;

public:
	matriz();

	matriz(int f, int c);

	~matriz();

	M getContenido (int fil, int col);

	int getFila ();

	int getColumna ();

	void insertarContenido (int fil, int col, const M &dato);

	void borrarContenido (int fil, int col);
	
};

#endif MATRIZ_H