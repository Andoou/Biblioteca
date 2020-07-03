#include "Usuario.h"
#include "Persona.h"
#include "windows.h"
#include <iostream>
#include <string>
#include <fstream>
#include "windows.h"

Usuario::Usuario(){
	estado = 1;
	codigo = NULL;
}
Usuario::Usuario(string nom, string ape, string cor, string tel, string dn, string dir, string cod):Persona(nom, ape, cor, tel, dn, dir){
	codigo = NULL;
	estado = 1;
}

void Usuario::crearUsuario(){
	ofstream esc;
	system("cls");
	string nom,ape,cor,tel, dn, dir, cod;
	int an;
	bool est=false;
	esc.open("Usuarios.txt",ios::out | ios::app);
	cout<<"Codigo:";
	cin>>cod;
	cout<<"Nombres:";
	cin>>nom;
	cout<<"Apellidos:";
	cin>>ape;
	cout<<"DNI:";
	cin>>dn;
	cout<<"Telefono:";
	cin>>tel;
	cout<<"Direccion:";
	cin>>dir;
	cout<<"Correo:";
	cin>>cor;
	esc<<cod<<"\t"<<nom<<"\t"<<ape<<"\t"<<dn<<"\t"<<tel<<"\t"<<dir<<"\t"<<cor<<"\n";
	esc.close();
}

void Usuario::verUsuarios(){
	ifstream lec;
	system("cls");
	string nom,ape,cor,tel, dn, dir, cod;
	int an;
	lec.open("Usuarios.txt",ios::in);
	cout<<"<-------------Usuarios------------->"<<endl;
	lec>>cod;
	while(!lec.eof()){
		lec>>nom;
		lec>>ape;
		lec>>cor;
		lec>>tel;
		lec>>dn;
		lec>>dir;
		lec>>cod;
		cout<<"Codigo--------: "<<cod<<endl;
		cout<<"Nombres-------: "<<nom<<endl;
		cout<<"Apellidos-----: "<<ape<<endl;
		cout<<"DNI-----------: "<<dn<<endl;
		cout<<"Telefono------: "<<tel<<endl;
		cout<<"Correo--------: "<<cor<<endl;
		cout<<"Direccion-----: "<<dir<<endl;
		cout<<"----------------------------------"<<endl;
		lec>>cod;
	}
	lec.close();
	system("pause");
}

void Usuario::toString(){
	
}

