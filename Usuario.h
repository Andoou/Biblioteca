//
// Created by SYSTEMNET on 6/08/20.
//

#ifndef BIBLIOTECA_USUARIO_H
#define BIBLIOTECA_USUARIO_H
#include <string.h>
#include <string>

#define USUARIO_H_

using namespace std;

int menuUsuario();
void agregarUsuario();
void verUsuario();
bool usuarioEstado(string);
void modificarUsuario();
int usuarioLocalizado(string);
bool cambiadoUsuario(int);
void eliminarUsuario();
void condicionMala();
void condicionBuena();
bool isUsusario(string codigo);
bool isCaracter1(string palabra);
bool codigoUnicoL(string);
bool inactivado(int);
bool reactivado(int);
bool dniUnico(string);
bool bueno(int);
bool malo(int);

#endif //BIBLIOTECA_USUARIO_H
