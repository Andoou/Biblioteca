
#ifndef MATERIAL_H
#define MATERIAL_H
#include <iostream>
#include <string>
using namespace std;
class Material{
private:
	string codigo;
	string autor;
	string titulo;
	int anio;
	bool estado;
public:
	Material();
	Material(string cod, string aut, string tit, int anio, bool estado);
	string getCodigo();
	string getAutor();
	string getTitulo();
	int getAnio();
	bool getEstado();
};
#include "Material.cpp"
#endif
