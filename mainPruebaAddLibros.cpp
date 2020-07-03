#include "Libro.h"
#include "Material.h"
#include "windows.h"
#include <iostream>
#include <string>
using namespace std;


int menu(){
	int x;
	system("cls");
	cout<<"---------Menu de Libros--------"<<endl<<endl;
	cout<<"1. Agregar Libros"<<endl;
	cout<<"2. Ver Libros"<<endl;
	cout<<"3. Buscar Libros"<<endl;
	cout<<"4. Modificar Libros"<<endl;
	cout<<"5. Eliminar Libros"<<endl;
	cout<<"6. Salir del Menu Libros"<<endl;
	cin>>x;
	return x;
}
int main() {
	int op;
	do{
		system("cls");
		op=menu();
		Libro nuevo("","","",123,true);
		switch(op){
		case 1:
			nuevo.crearLibro();
			break;
		case 2:
			nuevo.verLibros();
			break;
		}
		
	} while(op!=6);
	return 0;
}

