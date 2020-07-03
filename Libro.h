#ifndef LIBRO_H
#define LIBRO_H
#include "Material.h"
#include <string.h>

class Libro:Material{
public:
	Libro();
	Libro(string cod, string aut, string tit,int an, bool est);
	void crearLibro();
	void verLibros();
	void toString();
};
#include "Libro.cpp"
#endif


