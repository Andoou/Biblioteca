/*
* Usuario.cpp
*
*  Created on: 11 jun. 2020
*      Author: yeison
*/
#include "Administrador.h"
#include "windows.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

Administrador::Administrador(){
	PassAdmin= NULL;
	codigo = NULL;
}
Administrador::Administrador(string nom, string ape, string cor, int tel[9], int dn[8], string dir, char cod[4], char pas[8]):Persona(nom, ape, cor, tel, dn, dir){
	codigo = new char[4];
	PassAdmin = new char[8];
	strcpy(cod, codigo);
	strcpy(pas, PassAdmin);	
}
void Administrador::crearAdministrador(){
	ofstream esc;
	system("cls");
	
	string nom,ape,corr,di,dn,tel,cod,pas;
	esc.open("Administrador.txt",ios::out | ios::app);
	fflush(stdin);
	cout<<"Nombres:";
	getline(cin,nom);
	cout<<"Apellidos:";
	getline(cin,ape);
	cout<<"Correo:";
	getline(cin,corr);
	fflush(stdin);
	cout<<"DNI:";
	getline(cin,dn);
	cout<<"Telefono:";
	getline(cin,tel);	
	cout<<"Dirección:";
	getline(cin,di);
	cout<<"Código:";
	getline(cin,cod);
	cout<<"Contraseña:";
	getline(cin,pas);
	
	esc<<nom<<"\t"<<ape<<"\t"<<corr<<"\t"<<dn<<"\t"<<tel<<"\t"<<di<<"\t"<<cod<<"\n";
	esc.close();	
}
void Administrador::verAdministradores(){
	ifstream lec;
	system("cls");
	string nom,ape,cor,dir, tel,dn,cod;
	lec.open("Administrador.txt",ios::in);
	cout<<"<-------------Administradores------------->"<<endl;
	
	while(!lec.eof()){
		lec>>nom;
		lec>>ape;
		lec>>cor;
		lec>>dn;
		lec>>tel;
		lec>>dir;		
		lec>>cod;
		cout<<"Nombres--------: "<<nom<<endl;
		cout<<"Apellidos---------: "<<ape<<endl;
		cout<<"Correo--------: "<<cor<<endl;
		cout<<"DNI-----------: "<<dn<<endl;
		cout<<"Telefono--------: "<<tel<<endl;
		cout<<"Direccion-----: "<<dir<<endl;
		cout<<"Codigo--------: "<<cod<<endl;
		cout<<"----------------------------------"<<endl;
		lec>>cod;
	}
	lec.close();
	system("pause");
	
}

void Administrador::toString(){
	Persona::toString();
	cout << "Codigo de administrador: ";
	for(int i = 0; i < 4; i++){cout << codigo[i];};
	cout << "\n";
}

int main(){
	
	int tel[9]={9,5,8,8,4,3,9,5,7};
	int dni[8]={7,0,5,8,1,3,9,6};
	//Administrador prueba("Juan","Surco","esurcoa@unsa.edu.pe",tel,dni,"Juan Francisco","1234","12345678");
	Administrador prueba;
	prueba.verAdministradores();

	
	
}
	
