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
	string editorial;
	bool estado;
public:
	Usuario();
	Usuario(string nom, string ape, string cor, string tel, string dn, string dir, string cod);
//	Usuario(string nombre, string apellido);
	void toString();
};

#endif /* USUARIO_H_ */
