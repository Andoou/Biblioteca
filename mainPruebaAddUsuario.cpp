#include "Usuario.h"
#include "Persona.h"
#include "windows.h"
#include <iostream>
#include <string>
using namespace std;


int menu(){
	int x;
	system("cls");
	cout<<"---------Lista de Usuarios--------"<<endl<<endl;
	cout<<"1. Agregar Usuario"<<endl;
	cout<<"2. Ver Usuario"<<endl;
	cout<<"3. Buscar Usuario"<<endl;
	cout<<"4. Modificar Usuario"<<endl;
	cout<<"5. Eliminar Usuario"<<endl;
	cout<<"6. Salir."<<endl;
	cin>>x;
	return x;
}
int main() {
	int op;
	do{
		system("cls");
		op=menu();
		Usuario nuevo("nomebaa","apellasd","corsasd","teeel","dnoasd","direasdasd", "20123s");
		switch(op){
		case 1:
			nuevo.crearUsuario();
			break;
		case 2:
			nuevo.verUsuario();
			break;
		}
		
	} while(op!=6);
	return 0;
}

