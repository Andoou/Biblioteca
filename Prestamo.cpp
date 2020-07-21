#include "Prestamo.h"
#include "windows.h"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <time.h>
using namespace std;
///variables a usar

float cuota=0;
bool status;
int lib1=0,lib2=0,lib3=0, cod_usu,dia_In, mes_In, anio_In,dia_F,mes_F,anio_F;
///variables aux
int comp;
bool encontrado = false;
int cod_aux;
char opca;
string auxautor;
Prestamo::Prestamo(){
	
}

void  Prestamo::altas(int cod_aux,int lib1e,int lib2e,int lib3e,int diaIn,int mesIn,int anioIn,int diaF,int mesF,int anioF){
	ofstream escritura;
	ifstream consulta;
	//Año de fin de prestamo debe tener los dos ultimo digitos nada más 
	do{
		escritura.open("prestamo.txt", ios::out | ios::app);
		consulta.open("prestamo.txt", ios::in);
		
		if (escritura.is_open() && consulta.is_open()){
			bool repetido=false;
			consulta>>cod_usu;
			while (!consulta.eof()){
				consulta>>lib1>>lib2>>lib3>>dia_In>>mes_In>> anio_In>>dia_F>>mes_F>>anio_F>>cuota>>status;
				
				if (cod_aux==cod_usu){
					cout<<"\t\tYa existe el codigo del usuario...\n";
					repetido=true;
					break;
				}
				consulta>>cod_usu;
			}
			
			if (repetido==false){
				fflush(stdin);
				cuota=0.0;
				status=true;
				escritura<<cod_aux<<" "<<lib1e<<" "<<lib2e<<" "<<lib3e<<" "<<diaIn<<" "<<mesIn<<" "<<anioIn<<" "<<diaF<<" "<<mesF<<" "<<anioF<<" "<<cuota<<" "<<status<<endl;
				cout<<"\n\tRegistro agregado...\n";
			}
			
			cout<<"\n\tDeseas ingresar otro libro? (S/N): ";
			cin>>opca;
			
		}else{
			cout<<"El archivo no se pudo abrir \n";
		}
		
		escritura.close();
		consulta.close();
		
	}while (opca=='S' or opca=='s');
	
}
void Prestamo::consultas()
{
	//Lectura de archivos
	
	ifstream lectura;
	lectura.open("prestamo.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
	if (lectura.is_open()){
		//LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
		lectura>>cod_usu;
		while (!lectura.eof()){
			lectura>>lib1>>lib2>>lib3>>dia_In>>mes_In>> anio_In>>dia_F>>mes_F>>anio_F>>cuota>>status;
			cout<<"\n";
			cout<<"\tCodigo usuario:   "<<cod_usu<<endl;
			cout<<"\tCodigo libro1:   "<<lib1<<endl;
			cout<<"\tCodigo libro2: "<<lib2<<endl;
			cout<<"\tCodigo libro3: "<<lib3<<endl;
			cout<<"\tFecha Inicio:   "<<dia_In<<"-"<<mes_In<<"-"<<anio_In<<endl;
			cout<<"\tFecha Fin:   "<<dia_F<<"-"<<mes_F<<"-"<<anio_F<<endl;
			cout<<"\tCuota: "<<cuota<<endl;
			cout<<"\tStatus: "<<status<<endl;
			lectura>>cod_usu;
			cout<<"\t________________________________\n";
		}
		
	}else{
		cout<<"El archivo no se pudo abrir \n";
	}
	lectura.close();
}
void Prestamo::actualizar(){//actualizar cuota 
	ofstream aux;
	ifstream lectura;
	encontrado=false;
	
	aux.open("prestamo_auxiliar.txt", ios::out);
	lectura.open("prestamo.txt", ios::in);
	
	if (aux.is_open() && lectura.is_open()){
		lectura>>cod_usu;
		while (!lectura.eof()){
			lectura>>lib1>>lib2>>lib3>>dia_In>>mes_In>> anio_In>>dia_F>>mes_F>>anio_F>>cuota>>status;
				encontrado=true;
				cout<<"\n";
				cout<<"\tCodigo usuario:   "<<cod_usu<<endl;
				cout<<"\tCodigo libro1:   "<<lib1<<endl;
				cout<<"\tCodigo libro2: "<<lib2<<endl;
				cout<<"\tCodigo libro3: "<<lib3<<endl;
				cout<<"\tFecha Inicio:   "<<dia_In<<"-"<<mes_In<<"-"<<anio_In<<endl;
				cout<<"\tFecha Fin:   "<<dia_F<<"-"<<mes_F<<"-"<<anio_F<<endl;
				cout<<"\tCuota: "<<cuota<<endl;
				cout<<"\tStatus: "<<status<<endl;
				cout<<"\t________________________________\n\n";
				
				time_t     now = time(0);
				struct tm  tstruct;
				char       buf[80];
				tstruct = *localtime(&now);
				double difference;
				strftime(buf, sizeof(buf), "%d-%m-%y", &tstruct);
				string ahora=buf;
				int dA=stoi(ahora.substr(0,2));
				int mA=stoi(ahora.substr(3,5));
				int anA=stoi(ahora.substr(6,7))+100;
				struct  tm a = {0,0,0,dia_F,mes_F,anio_F};
				struct  tm b = {0,0,0,dA,mA,anA};
				time_t x =  mktime(&a);
				time_t y =  mktime(&b);
				if ( x != ( time_t)(-1) && y != ( time_t)(-1) )
				{
					difference = difftime(y, x) / (60 * 60 * 24);
					
				}				
				if(difference>0){
				cuota=difference;
				}
				aux<<cod_usu<<" "<<lib1<<" "<<lib2<<" "<<lib3<<" "<<dia_In<<" "<<mes_In<<" "<<anio_In<<" "<<dia_F<<" "<<mes_F<<" "<<anio_F<<" "<<cuota<<" "<<status<<endl;
				cout<<"\n\n\t\t\tRegistro modificado...\n\t\t\a";
			
			lectura>>cod_usu;
		}
	}else{
		cout<<"\n\tEl archivo no se pudo abrir \n";
	}
	
	if (encontrado==false){
		cout<<"\n\tNo se encontro ningun registro con el codigo: "<<cod_aux<<"\n\n\t\t\t";
	}
	
	aux.close();
	lectura.close();
	remove ("prestamo.txt");
	rename("prestamo_auxiliar.txt", "prestamo.txt");
	
	
}

void Prestamo::buscar_id()
{	ifstream lectura;
lectura.open("prestamo.txt", ios::out | ios::in);
encontrado=false;
if (lectura.is_open()){
	cout<<"\n\tIngresa la codigo del usuario que deseas buscar: ";
	cin>>cod_aux;
	lectura>>cod_usu;
	while(!lectura.eof()){
		lectura>>lib1>>lib2>>lib3>>dia_In>>mes_In>> anio_In>>dia_F>>mes_F>>anio_F>>cuota>>status;
		//comparar cada registro para ver si es encontrado
		if (cod_aux==cod_usu){
			cout<<"\n";
			cout<<"\tCuota: "<<cuota<<endl;
			cout<<"\t________________________________\n";
			encontrado=true;
			break;
		}//fin del if mostrar encontrado
		
		//lectura adelantada
		lectura>>cod_usu;
	}//fin del while
	if (encontrado==false){
		cout<<"\n\n\tNo hay registros con el codigo: "<<cod_aux<<"\n\n\t\t\t";
	}
}else{
	cout<<"\n\tAun no se pudo abrir el archivo...";
}

lectura.close();
}
/*
void Prestamo::buscar()
{	ifstream lectura;
lectura.open("libro.txt", ios::out | ios::in);
encontrado=false;
if (lectura.is_open()){
	cout<<"\n\tIngresa la codigo del libro que deseas buscar: ";
	cin>>cod_aux;
	lectura>>cod;
	while(!lectura.eof()){
		lectura>>autor>>titulo>>anio>>status;
		//comparar cada registro para ver si es encontrado
		if (cod_aux==cod){
			cout<<"\n";
			cout<<"\tCodido:    "<<cod<<endl;
			cout<<"\tTitulo:   "<<titulo<<endl;
			cout<<"\tAutor:   "<<autor<<endl;
			cout<<"\tAño: "<<anio<<endl;
			cout<<"\tStatus: "<<status<<endl;
			cout<<"\t________________________________\n";
			encontrado=true;
			break;
		}//fin del if mostrar encontrado
		
		//lectura adelantada
		lectura>>cod;
	}//fin del while
	if (encontrado==false){
		cout<<"\n\n\tNo hay registros con el codigo: "<<cod_aux<<"\n\n\t\t\t";
	}
}else{
	cout<<"\n\tAun no se pudo abrir el archivo...";
}

lectura.close();
}*/

/*void Prestamo::actualizar()
{
	ofstream aux;
	ifstream lectura;
	
	encontrado=false;
	
	aux.open("libro_auxiliar.txt", ios::out);
	lectura.open("libro.txt", ios::in);
	
	if (aux.is_open() && lectura.is_open()){
		
		cout<<"\n";
		cout<<"\tIngresa la codigo del libro que deseas modificar: ";
		cin>>cod_aux;
		
		lectura>>cod;
		while (!lectura.eof()){
			lectura>>autor>>titulo>>anio>>status;
			
			if (cod_aux==cod){
				encontrado=true;
				cout<<"\n";
				cout<<"\tCodido:    "<<cod<<endl;
				cout<<"\tTitulo:   "<<titulo<<endl;
				cout<<"\tAutor:   "<<autor<<endl;
				cout<<"\tAño: "<<anio<<endl;
				cout<<"\tStatus: "<<status<<endl;
				cout<<"\t________________________________\n\n";
				cout<<"\tIngresa el nuevo nombre del autor del libro con el codigo: "<<cod_aux<<"\n\n\t---> ";
				cin>>auxautor;
				
				aux<<cod<<" "<<titulo<<" "<<auxautor<<" "<<anio<<" "<<status;
				cout<<"\n\n\t\t\tRegistro modificado...\n\t\t\a";
			}else{
				aux<<cod<<" "<<titulo<<" "<<auxautor<<" "<<anio<<" "<<status;
			}
			lectura>>cod;
		}
	}else{
		cout<<"\n\tEl archivo no se pudo abrir \n";
	}
	
	if (encontrado==false){
		cout<<"\n\tNo se encontro ningun registro con el codigo: "<<cod_aux<<"\n\n\t\t\t";
	}
	
	aux.close();
	lectura.close();
	remove ("libro.txt");
	rename("libro_auxiliar.txt", "libro.txt");
}*/

int main()
{
	int cod_usu,lib1=0,lib2=0,lib3=0,dia_In, mes_In, anio_In,dia_F,mes_F,anio_F;
	system ("color f0");
	int opc;
	Prestamo p=Prestamo();
	do{
		system("cls");
		
		cout<<"\n\tManejo de archivos en c++\n\n";
		cout<<"\n\t1.-Ingresar nuevo prestamo";
		cout<<"\n\t2.-Bajas";
		cout<<"\n\t3.-Consultas";
		cout<<"\n\t4.-Buscar un registro";
		cout<<"\n\t5.-Modificaciones";
		cout<<"\n\t6.-Salir";
		cout<<"\n\n\tElige una opcion:  ";
		cin>>opc;
		
		switch (opc)
		{
		case 1:{
			system("cls");
			cout<<"\tIngresa codigo del usuario:   ";
			cin>>cod_usu;
			cout<<"\tIngresa el cod del libro 1:   ";
			cin>>lib1;
			cout<<"\tIngresa el cod del libro 2:   ";
			cin>>lib2;
			cout<<"\tIngresa el cod del libro 3:   ";
			cin>>lib3;
			cout<<"\tIngresa el dia inicio:   ";
			cin>>dia_In;
			cout<<"\tIngresa el mes inicio:   ";
			cin>>mes_In;
			cout<<"\tIngresa el anio inicio:   ";
			cin>>anio_In;
			cout<<"\tIngresa el dia fin:   ";
			cin>>dia_F;
			cout<<"\tIngresa el mes fin:   ";
			cin>>mes_F;
			cout<<"\tIngresa el anio fin con el siguiente formato YY(ultimos dos digitos):   ";
			cin>>anio_F;
			p.altas(cod_usu,lib1,lib2,lib3,dia_In,mes_In,anio_In,dia_F,mes_F,anio_F);
			cout<<"\n\t\t";
			system ("pause");
			break;
		}
		case 2:{
				system("cls");
				//p.bajas();
				cout<<"\n\t\t";
				system ("pause");
				break;
			}
		case 3:{
					system("cls");
					p.consultas();
					cout<<"\n\t\t";
					system ("pause");
					break;
				}
		case 4:{
						system("cls");
						p.buscar_id();
						cout<<"\n\t\t";
						system ("pause");
						break;
					}
		case 5:{
							system("cls");
							p.actualizar();
							cout<<"\n\t\t";
							system ("pause");
							
							break;
						}
		case 6:{
								cout<<"\n\n\tHa elegido salir...\n\n\t\t"; system ("pause");
								break;
							}
		default:{
									cout<<"\n\n\tHa elegido una opcion inexistente...\n\n\t\t"; system ("pause");
									break;
								}
		}//fin switch
		
	}while (opc!=6);
	
	system("cls");
	
	return 0;
}
