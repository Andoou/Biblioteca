/*
* Usuario.cpp
*
*  Created on: 11 jun. 2020
*      Author: yeison
*/
#include "Usuario.h"

Administrador::Administrador(){
	PassAdmin= NULL;
	codigo = NULL;
}
Administrador::Administrador(string nom, string ape, string cor, int tel[9], int dn[8], string dir, char cod[4], char pas[4]):Persona(nom, ape, cor, tel, dn, dir){
	codigo = new char[4];
	strcpy(cod, codigo);
	strcpy(pas, PassAdmin);
	
	estado = 1;
}
void Administrador::toString(){
	Persona::toString();
	cout << "Codigo de usuario: ";
	for(int i = 0; i < 4; i++){cout << codigo[i];};
	cout << "\n";
	cout <<	"Estado: "<< estado << endl ;
}
/*
Usuario::Usuario(string nom, string ape){
nombres = nom;
apellidos = ape;
estado = 1;
codigo = NULL;
}*/
