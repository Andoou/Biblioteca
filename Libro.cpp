#include "Libro.h"
#include "Material.h"
#include "windows.h"
#include <iostream>
#include <string>
#include <fstream>
#include "windows.h"

Libro::Libro(){
}
Libro::Libro(string cod, string aut, string tit,int an, bool est):Material(cod,aut,tit,an,est){
}
void Libro::crearLibro(){
	ofstream esc;
	system("cls");
	string cod,aut,tit;
	int an;
	bool est=false;
	esc.open("Libros.txt",ios::out | ios::app);
	cout<<"Codigo:";
	cin>>cod;
	cout<<"Autor:";
	cin>>aut;
	cout<<"Titulo:";
	cin>>tit;
	cout<<"Año:";
	cin>>an;
	esc<<cod<<"\t"<<aut<<"\t"<<tit<<"\t"<<an<<"\t"<<est<<"\n";
	esc.close();
}
void Libro::verLibros(){
	ifstream lec;
	system("cls");
	string cod,aut,tit;
	int an;
	bool est=false;
	lec.open("Libros.txt",ios::in);
	cout<<"<-------------Revistas------------->"<<endl;
	lec>>cod;
	while(!lec.eof()){
		lec>>aut;
		lec>>tit;
		lec>>an;
		lec>>est;
		cout<<"Codigo--------: "<<cod<<endl;
		cout<<"Autor---------: "<<aut<<endl;
		cout<<"Titulo--------: "<<tit<<endl;
		cout<<"Año-----------: "<<an<<endl;
		cout<<"Estado--------: "<<est<<endl;
		cout<<"----------------------------------"<<endl;
		lec>>cod;
	}
	lec.close();
	system("pause");
	
}


void Libro::toString(){
	
}
