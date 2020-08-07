/*
 * Libro.h
 *
 *  Created on: 20 jul. 2020
 *      Author: Yerson
 */

#ifndef LIBRO_H_
#define LIBRO_H_

using namespace std;

int menuLibro();
void agregarLibro();
void verLibro();
bool libroEstado(string);
void modificarLibro();
int libroLocalizado(string);
bool cambiadoLibro(int);
void eliminarLibro();
void inactivar();
bool inactivado(int ubicacion);
void reactivar();
bool reactivado(int ubicacion);
bool codigoUnicoL(string);
bool inactivado(int);
bool reactivado(int);

#endif /* LIBRO_H_ */
