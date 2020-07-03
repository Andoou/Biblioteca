/*
* Usuario.h
*
*  Created on: 11 jun. 2020
*      Author: 
*/

#ifndef USUARIO_H_
#define USUARIO_H_
#include "Persona.cpp"

class Administrador:Persona{
private:
	char *codigo;
	char *PassAdmin;
public:
	Administrador();
	Administrador(string nom, string ape, string cor, int tel[9], int dn[8], string dir, char cod[4], char pas[8]);
	void crearAdministrador();
	void verAdministradores();
	void toString();
};

#endif /* USUARIO_H_ */
