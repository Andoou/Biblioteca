//============================================================================
// Name        : Biblioteca.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Usuario.h"
using namespace std;

int main() {
	int telefono[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int dni[] = {1, 2, 3, 4, 5, 6, 7, 8};
	Usuario a ("Miguel", "Salas", "miguelsalas@unsa.edu.pe", telefono, dni, "Calle primavera 123", "B211");
	a.toString();
	return 0;
}
