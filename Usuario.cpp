/*
 * Usuario.cpp
 *
 *  Created on: 11 jun. 2020
 *      Author: yeison
 */
#include "Usuario.h"

Usuario::Usuario(){
	estado = 1;
	codigo = NULL;
}
Usuario::Usuario(string nom, string ape, string cor, int tel[9], int dn[8], string dir, char cod[4]){
	codigo = new char[4];
	for(int i = 0; i < 4; i++){
		codigo[i] = cod[i];
	}
	estado = 1;
}
void Usuario::toString(){
	toString();
	cout << "Codigo de usuario: "<< codigo <<"\n"
		<<	"Estado: "<< estado << endl ;
}
/*
Usuario::Usuario(string nom, string ape){
	nombres = nom;
	apellidos = ape;
	estado = 1;
	codigo = NULL;
}*/



