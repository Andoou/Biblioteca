#include "Revista.h"
#include "Material.h"
#include "windows.h"
#include <iostream>
#include <string>
#include <fstream>
#include "windows.h"

Revista::Revista(){
	this->editorial = "null";
}
Revista::Revista(string cod, string aut, string tit,int an, bool est,string edito):Material(cod,aut,tit,an,est){
	editorial = edito;
}
void Revista::crearRevista(){
	ofstream esc;
	system("cls");
	string cod,aut,tit,edito;
	int an;
	bool est=false;
	esc.open("Revistas.txt",ios::out | ios::app);
	cout<<"Codigo:";
	cin>>cod;
	cout<<"Autor:";
	cin>>aut;
	cout<<"Titulo:";
	cin>>tit;
	cout<<"Año:";
	cin>>an;
	cout<<"Editor:";
	cin>>edito;
	esc<<cod<<"\t"<<aut<<"\t"<<tit<<"\t"<<an<<"\t"<<est<<"\t"<<edito<<"\n";
	esc.close();
}
void Revista::verRevistas(){
	ifstream lec;
	system("cls");
	string cod,aut,tit,edito;
	int an;
	bool est=false;
	lec.open("Revistas.txt",ios::in);
	cout<<"<-------------Revistas------------->"<<endl;
	lec>>cod;
	while(!lec.eof()){
		lec>>aut;
		lec>>tit;
		lec>>an;
		lec>>est;
		lec>>edito;
		cout<<"Codigo--------: "<<cod<<endl;
		cout<<"Autor---------: "<<aut<<endl;
		cout<<"Titulo--------: "<<tit<<endl;
		cout<<"Año-----------: "<<an<<endl;
		cout<<"Estado--------: "<<est<<endl;
		cout<<"Editorial-----: "<<edito<<endl;
		cout<<"----------------------------------"<<endl;
		lec>>cod;
	}
	lec.close();
	system("pause");
	
}


void Revista::toString(){
	
}
