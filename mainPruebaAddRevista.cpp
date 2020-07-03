#include "Revista.h"
#include "Material.h"
#include "windows.h"
#include <iostream>
#include <string>
using namespace std;


int menu(){
	int x;
	system("cls");
	cout<<"---------Menu de Revistas--------"<<endl<<endl;
	cout<<"1. Agregar Revista"<<endl;
	cout<<"2. Ver Revista"<<endl;
	cout<<"3. Buscar Revista"<<endl;
	cout<<"4. Modificar Revista"<<endl;
	cout<<"5. Eliminar Revista"<<endl;
	cout<<"6. Salir del Menu Revistas"<<endl;
	cin>>x;
	return x;
}
int main() {
	int op;
	do{
		system("cls");
		op=menu();
		Revista nuevo("ads","asd","sadf",123,true,"hl");
		switch(op){
		case 1:
			nuevo.crearRevista();
			break;
		case 2:
			nuevo.verRevistas();
			break;
		}
		
	} while(op!=6);
	return 0;
}

