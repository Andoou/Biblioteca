#include "Material.h"
#include <iostream>
#include <string>
using namespace std;
Material::Material(){
	codigo="";
	autor="";
	titulo="";
	anio=0000;
	estado=false;
}

Material::Material(string cod, string aut, string tit, int an, bool est){
	codigo = cod;
	autor = aut ;
	titulo = tit ;
	anio= an;
	estado = est;
}
string Material::getCodigo(){
	return codigo;
}
string Material::getAutor(){
	return autor;
}
string Material::getTitulo(){
	return titulo;
}
int Material::getAnio(){
	return anio;
}
bool Material::getEstado(){
	return estado;
}
