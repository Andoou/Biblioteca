/*
 * Persona.h
 *
 *  Created on: 11 jun. 2020
 *      Author: yeison
 */


#ifndef PERSONA_H_
#define PERSONA_H
#include <iostream>_
#include <string.h>
using std::string;

class Persona{
private:
	string nombres;
	string apellidos;
	string correo;
	int *telefono;
	int *dni;
	string direccion;
public:
	Persona();
	Persona(string nom, string ape, string cor, int tel[9], int dn[8], string dir);
	string getNombres();
	string getApellidos();
	string getCorreo();
	int* getTelefono();
	int* getDNi();
	string getDireccion();
	~Persona();
};



#endif /* PERSONA_H_ */
