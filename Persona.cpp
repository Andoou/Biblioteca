/*
 * Persona.cpp
 *
 *  Created on: 11 jun. 2020
 *      Author: yeison
 */

#include "Persona.h"
#include <iostream>
#include "string.h"

Persona::Persona(){
	nombres = "";
	apellidos = "";
	correo = "";
	direccion = "";
	telefono = NULL;
	dni = NULL;
}

Persona::Persona(string nom, string ape, string cor, int tel[9], int dn[8], string dir){
	nombres = nom;
	apellidos = ape;
	correo = cor;
	telefono = new int[9];
	for(int i = 0; i < 9; i++){
		telefono[i] = tel[i];
	}
	dni = new int[8];
	for(int i = 0; i < 8; i++){
		dni[i] = dn[i];
	}
	direccion = dir;
}
string Persona::getNombres(){
	return nombres;
}
string Persona::getApellidos(){
	return apellidos;
}
string Persona::getCorreo(){
	return correo;
}
int* Persona::getTelefono(){
	return telefono;
}
int* Persona::getDNi(){
	return dni;
}
string Persona::getDireccion(){
	return direccion;
}
void Persona::toString(){
	cout << "---Datos---\n"<<"Nombres: "<< nombres <<"\n"<<
			"Apellidos: "<<apellidos << "\n"<<
			"Dni: ";
			for(int i = 0; i < 8; i++){cout << dni[i];};
			cout << "\n";
			cout << "Correo: "<< correo << "\n"<<
			"Telefono: ";
			for(int i = 0; i < 9; i++){cout << telefono[i];};
			cout << "\n";
			cout << "Direccion: "<< direccion <<endl;
}
Persona::~Persona(){
	delete []dni;
	delete []telefono;
}




