/*
 * Usuario.h
 *
 *  Created on: 11 jun. 2020
 *      Author: yeison
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include "Persona.h"

class Usuario:Persona{
private:
	char *codigo;
	bool estado;
public:
	Usuario();
	Usuario(string nom, string ape, string cor, int tel[9], int dn[8], string dir, char cod[4]);
//	Usuario(string nombre, string apellido);
	void toString();
};

#endif /* USUARIO_H_ */
