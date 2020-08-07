//============================================================================
// Name        : Libro.cpp
// Author      : Yerson
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <string.h>
#include "Libro.h"

using namespace std;

struct Libro{
	char codigo [5] = "";
	char titulo [30] = "";
	char autor [30] = "";
	char isbn [14] = "";
	char estado = 'A';
};


int menuLibro() {
	char opcion[1];
	do{
		system("cls");
		cin.clear();
		cout << "\t\t************************************" << endl;
		cout << "\t\t**         MENU DE LIBROS         **" << endl;
		cout << "\t\t************************************" << endl;
		cout << "\n\t\tQue desea hacer?" << endl;
		cout <<
				"\n\t\tA- Agregar un libro."
				"\n\t\tM- Modificar un libro."
				"\n\t\tE- Eliminar un libro."
				"\n\t\tV- Ver lista de libros."
			//Desechable Inactivar
				"\n\t\tI- Inactivar"
				"\n\t\tR- Reactivar"

			//Inactivar
				"\n\t\tS- Salir." << endl;
		cout << "\n\t\tDigite su opcion y luego enter>>> ";
		cin >> opcion;
		switch(opcion[0]){
		case 'a':
		case 'A':
			agregarLibro();
			system("pause");
			break;

		case 'm':
		case 'M':
			modificarLibro();
			system("pause");
			break;

		case 'e':
		case 'E':
			eliminarLibro();
			system("pause");
			break;

		case 'v':
		case 'V':
			verLibro();
			system("pause");
			break;

		case 'i':
		case 'I':
			inactivar();
			system("pause");
			break;

		case 'r':
		case 'R':
			reactivar();
			system("pause");
			break;

		case 's':
		case 'S':
			break;

		default:
			cout << "Opcion no valida, intente de nuevo" << endl;
			system("pause");
			break;
		}
	}while(opcion[0]!='s' && opcion[0]!='S');

	return 0;
}

void agregarLibro(){
	ofstream archivoGuardar("Libros.txt", ios::app);
	Libro libro;

	cin.ignore();

	cout << "\n\t\tIngrese codigo: ";
	char aux [5];
	cin.getline(aux,5);
	do{
		if(codigoUnicoL(aux)==true) break;
		cout <<"\t\tCodigo ya registrado!, Ingrese otro: ";
		cin.getline(aux,5);
	}while(!codigoUnicoL(aux));
	strcpy(libro.codigo, aux);
	cout << "\t\tIngrese titulo: ";
	cin.getline(libro.titulo,30);

	cout << "\t\tIngrese autor: ";
	cin.getline(libro.autor,30);

	cout << "\t\tIngrese ISBN: ";
	cin.getline(libro.isbn,14);

	archivoGuardar.write((char *)&libro, sizeof(libro));
	archivoGuardar.close();
}

void verLibro(){
	system("cls");
	struct Libro libro;

	ifstream archivoMostrar("Libros.txt");
	archivoMostrar.read((char *)&libro, sizeof(libro));

	cout << "\t\t---------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|   CODIGO   |           TITULO           |            AUTOR            |     ISBN     |  ESTADO  |" << endl;

	while(archivoMostrar && !archivoMostrar.eof()){
		cout << "\t\t" << right << setw(9)
				<< libro.codigo << "      " << left << setw(29)
				<< libro.titulo << left << setw(30)
				<< libro.autor << left << setw(16)
				<< libro.isbn << "   "
				<< libro.estado
				<< endl;
		archivoMostrar.read((char *)&libro, sizeof(libro));
	}
	archivoMostrar.close();
}

void modificarLibro(){
	char codigoBuscado [5];
	int ubicacion = 0;
	system("cls");

	verLibro();
	cin.ignore();
	cout << "\n\nIngrese codigo del libro a modificar: ";
	cin.getline(codigoBuscado, 5);

	ubicacion = libroLocalizado(codigoBuscado);
	if(ubicacion) {
		cout << "Libro encontrado\n";
		cout << "Presione cualquier tecla para continuar" << endl;
		if(cambiadoLibro(ubicacion))
			cout << "\nEl libro se ha modificado con exito" << endl;

	}else{
		cout << "Libro no existe en el archivo"<< endl;
	}

}

int libroLocalizado(string codigoBuscado){
	struct Libro libro;
	int counter = 0;
	string bufferCodigo;
	ifstream archivoMostrar("Libros.txt");
	archivoMostrar.read((char *)&libro, sizeof(libro));

	while(archivoMostrar && !archivoMostrar.eof()){
		counter++;
		bufferCodigo = libro.codigo;
		if(codigoBuscado == bufferCodigo){
			return counter;
		}
		archivoMostrar.read((char *)&libro, sizeof(libro));
	}
	archivoMostrar.close();
	return 0;
}

bool cambiadoLibro(int ubicacion){
	try{
		Libro libro;
		cin.ignore();

		cout << "\n\t\tIngrese codigo: ";
		cin.getline(libro.codigo,5);

		cout << "\t\tIngrese Titulo: ";
		cin.getline(libro.titulo,30);

		cout << "\t\tIngrese Autor: ";
		cin.getline(libro.autor,30);

		cout << "\t\tIngrese isbn: ";
		cin.getline(libro.isbn,14);
		
		libro.estado = 'A';

		fstream archivoCambio("Libros.txt");
		archivoCambio.seekg((ubicacion-1)*sizeof(libro), ios::beg);

		archivoCambio.write((char *)&libro, sizeof(libro));
		archivoCambio.close();
		return true;
	}catch(exception e){
		cout << "Ha ocurrido un error"<< e.what();
		return false;
	}
}

void eliminarLibro(){
	Libro libro;
	system("cls");
	verLibro();
	char bufferCodigo[5];
	cin.ignore();
	cout << "Ingrese la codigo de libro a eliminar :";
	cin.getline(bufferCodigo, 5);
	if(libroLocalizado(bufferCodigo)){
		fstream archivoLectura("Libros.txt");
		ofstream archivoEscritura("auxiliar.txt");

		archivoLectura.read((char *) &libro, sizeof(libro));
		string codigoBuscado = bufferCodigo;
		while(archivoLectura && !archivoLectura.eof()){
			if(libro.codigo == codigoBuscado){
				//no hacer nada
			}else{
				archivoEscritura.write((char *) &libro, sizeof(libro));
			}
			archivoLectura.read((char *) &libro, sizeof(libro));
		}
		archivoEscritura.close();
		archivoLectura.close();
		remove("libros.txt");
		rename("auxiliar.txt", "Libros.txt");
	}else{
		cout << "No se ha encontrado un libro con la codigo: " << bufferCodigo << endl;
	}
}

bool libroEstado(string codigoBuscado){ //ayudara para hacer lo de prestamos
	struct Libro libro;
	int ubicacion = libroLocalizado(codigoBuscado);
	ifstream archivoMostrar("Libros.txt");
	int c = 0;
	while(archivoMostrar && !archivoMostrar.eof()){
			archivoMostrar.read((char *)&libro, sizeof(libro));
			c++;
			if(c == ubicacion) break;
	}
	if(libro.estado ==  'A') {
		return true;
	}else{
		cout << "Algo va mal"<< endl;
	}
	return false;
}

bool codigoUnicoL(string codigoBuscado){

	struct Libro libro;
	ifstream archivoMostrar("Libros.txt");
	archivoMostrar.read((char *)&libro, sizeof(libro));
	while(archivoMostrar && !archivoMostrar.eof()){
				if(libro.codigo==codigoBuscado)
					return false;
			archivoMostrar.read((char *)&libro, sizeof(libro));
		}
		archivoMostrar.close();
	return true;
}

void inactivar(){
	char codigoBuscado [5];
	int ubicacion = 0;
	system("cls");

	verLibro();
	cin.ignore();
	cout << "\n\nIngrese codigo del libro a inactivar: ";
	cin.getline(codigoBuscado, 5);

	ubicacion = libroLocalizado(codigoBuscado);
	if(ubicacion) {
		cout << "Libro encontrado\n";
		cout << "....." << endl;
		if(inactivado(ubicacion))
			cout << "El libro se ha inactivado con exito" << endl;

	}else{
		cout << "Libro no existe en el archivo"<< endl;
	}

}

bool inactivado(int ubicacion){
	try{
		int pos = ubicacion;
		struct Libro libro;
		ifstream archivoMostrar("Libros.txt");
		int c = 0;
		while(archivoMostrar && !archivoMostrar.eof()){
				archivoMostrar.read((char *)&libro, sizeof(libro));
				c++;
				if(c == ubicacion) break;
		}
		Libro libroin;
		strcpy(libroin.codigo, libro.codigo);
		strcpy(libroin.titulo, libro.titulo);
		strcpy(libroin.autor, libro.autor);
		strcpy(libroin.isbn, libro.isbn);
		libroin.estado = 'I';

		fstream archivoCambio("Libros.txt");
		archivoCambio.seekg((pos-1)*sizeof(libro), ios::beg);
		archivoCambio.write((char *)&libroin, sizeof(libro));
		archivoCambio.close();
		archivoMostrar.close();
		return true;
	}catch(exception e){
		cout << "Ha ocurrido un error"<< e.what();
		return false;
	}
}

void reactivar(){
	char codigoBuscado [5];
	int ubicacion = 0;
	system("cls");

	verLibro();
	cin.ignore();
	cout << "\n\nIngrese codigo del libro a reactivar: ";
	cin.getline(codigoBuscado, 5);

	ubicacion = libroLocalizado(codigoBuscado);
	if(ubicacion) {
		cout << "Libro encontrado\n";
		cout << "....." << endl;
		if(reactivado(ubicacion))
			cout << "El libro se ha reactivado con exito" << endl;

	}else{
		cout << "Libro no existe en el archivo"<< endl;
	}

}

bool reactivado(int ubicacion){
	try{
		int pos = ubicacion;
		struct Libro libro;
		ifstream archivoMostrar("Libros.txt");
		int c = 0;
		while(archivoMostrar && !archivoMostrar.eof()){
				archivoMostrar.read((char *)&libro, sizeof(libro));
				c++;
				if(c == ubicacion) break;
		}
		Libro libroin;
		strcpy(libroin.codigo, libro.codigo);
		strcpy(libroin.titulo, libro.titulo);
		strcpy(libroin.autor, libro.autor);
		strcpy(libroin.isbn, libro.isbn);
		libroin.estado = 'A';

		fstream archivoCambio("Libros.txt");
		archivoCambio.seekg((pos-1)*sizeof(libro), ios::beg);
		archivoCambio.write((char *)&libroin, sizeof(libro));
		archivoCambio.close();
		archivoMostrar.close();
		return true;
	}catch(exception e){
		cout << "Ha ocurrido un error"<< e.what();
		return false;
	}
}
