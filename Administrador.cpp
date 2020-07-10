
#include "windows.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
//DEFINIENDO LAS VARIABLES NECESARIAS	
string nombre,apellido,correo,direccion;
char telefono[9], dni[8], cod[4], pas[8];
bool encontrado = false;
///variables aux
int comp;
char cod_aux[4];
char opca;
string auxnombre;
void altas()//Ingreso de datos a los archivos
{
	///Variables de la biblioteca fstream para el manejo de archivos
	ofstream escritura;
	ifstream consulta;
	
	do{
		escritura.open("administrador.txt", ios::out | ios::app);//crea y escribe, si ya tiene texto une al final del archivo
		//POR LO TANTO FUNCIONARA COMO UNA PEQUEÑA BASE DE DATOS DADO QUE DESPUES AL INGRESAR NUESTROS DATOS SE ENCONTRARÁN AHÍ Y NO SE SOBREESCRIBIRA ENCIMA DEL ARCHIVO QUE GUARDA NUESTROS DATOS
		consulta.open("administrador.txt", ios::in);//solamente consulta o lee usando la variable sobre el archivo físico alumnos.txt
		
		if (escritura.is_open() && consulta.is_open()){
			bool repetido=false;
			cout<<"\n";
			cout<<"\tIngresa el codigo del alumno:    ";
			cin>>cod_aux;
			//A continuación se aplica el tipo de lectura de archivos secuencial
			consulta>>cod;
			while (!consulta.eof()){
				consulta>>nombre>>apellido>>correo>>telefono>>dni>>direccion>>pas;
				comp=strcmp(cod_aux,cod);
				cout<<comp;
				cout<<cod;
				cout<<cod_aux;
				if (comp==0){
					cout<<"\t\tYa existe el codigo del administrador...\n";
					repetido=true;
					break;
				}
				consulta>>cod;
			}
			
			if (repetido==false){
				fflush(stdin);
				cout<<"\tIngresa el nombre del administrador:   ";
				cin>>nombre;
				cout<<"\tIngresa el apellido del administrador:   ";
				cin>>apellido;
				cout<<"\tIngresa el correo del administrador:   ";
				cin>>correo;
				cout<<"\tIngresa el telefono del administrador: ";
				cin>>telefono;
				cout<<"\tIngresa el DNI del administrador: ";
				cin>>dni;
				cout<<"\tIngresa la dirección del administrador:   ";
				cin>>direccion;
				cout<<"\tIngresa la contraseña:     ";
				cin>>pas;
				//ESCRIBIENDO LOS DATOS CAPTURADOS POR EL USUARIO EN EL ARCHIVO
				escritura<<cod_aux<<" "<<nombre<<" "<<apellido<<" "<<correo<<" "<<telefono<<" "<<dni<<" "<<direccion<<" "<<pas<<endl;
				cout<<"\n\tRegistro agregado...\n";
			}
			
			cout<<"\n\tDeseas ingresar otro alumno? (S/N): ";
			cin>>opca;
			
		}else{
			cout<<"El archivo no se pudo abrir \n";
		}
		
		escritura.close();
		consulta.close();
		
	}while (opca=='S' or opca=='s');
	
}
void bajas()
{
	ofstream aux;
	ifstream lectura;
	
	encontrado=false;
	
	aux.open("auxiliar.txt", ios::out);
	lectura.open("administrador.txt", ios::in);
	
	if (aux.is_open() && lectura.is_open()){
		
		cout<<"\n";
		cout<<"\tIngresa el codigo del Administrador que deseas eliminar: ";
		cin>>cod_aux;
		
		///De nuevo se aplica el tipo de lectura de archivos secuencial, esto quiere decir que lee campo por campo hasta
		///hasta llegar al final del archivo gracias a la funciÃ³n .eof()
		lectura>>cod;
		while (!lectura.eof()){
			lectura>>nombre>>apellido>>correo>>telefono>>dni>>direccion>>pas;
			comp==strcmp(cod,cod_aux);
			if (comp==0){
				
				encontrado=true;
				cout<<"\n";
				cout<<"\tCodido:    "<<cod<<endl;
				cout<<"\tNombre:   "<<nombre<<endl;
				cout<<"\tApellido:   "<<apellido<<endl;
				cout<<"\tCorreo: "<<correo<<endl;
				cout<<"\tTelefono: "<<telefono<<endl;
				cout<<"\tDNI:    "<<dni<<endl;
				cout<<"\tDireccion:    "<<direccion<<endl;
				cout<<"\t________________________________\n\n";
				cout<<"\tRealmente deseas eliminar el registro actual (S/N)? ---> ";
				cin>>opca;
				
				if (opca=='S' or opca=='s'){
					cout<<"\n\n\t\t\tRegistro eliminado...\n\n\t\t\a";
				}else{
					aux<<cod<<" "<<nombre<<" "<<apellido<<" "<<correo<<" "<<telefono<<" "<<dni<<" "<<direccion<<" "<<pas;
				}
				
			}else{
				aux<<cod<<" "<<nombre<<" "<<apellido<<" "<<correo<<" "<<telefono<<" "<<dni<<" "<<direccion<<" "<<pas;
			}
			lectura>>cod;
		}
	}else{
		cout<<"\n\tEl archivo no se pudo abrir \n";
	}
	
	if (encontrado==false){
		cout<<"\n\tNo se encontro ningun registro con la clave: "<<cod_aux<<"\n\n\t\t\t";
	}
	
	aux.close();
	lectura.close();
	remove ("administrador.txt");
	rename("auxiliar.txt", "administrador.txt");
}
void consultas()
{
	//Lectura de archivos
	
	ifstream lectura;
	lectura.open("administrador.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
	if (lectura.is_open()){
		//LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
		lectura>>cod;
		while (!lectura.eof()){
			lectura>>nombre>>apellido>>correo>>telefono>>dni>>direccion>>pas;
			cout<<"\n";
			cout<<"\tCodido:    "<<cod<<endl;
			cout<<"\tNombre:   "<<nombre<<endl;
			cout<<"\tApellido:   "<<apellido<<endl;
			cout<<"\tCorreo: "<<correo<<endl;
			cout<<"\tTelefono: "<<telefono<<endl;
			cout<<"\tDNI:    "<<dni<<endl;
			cout<<"\tDireccion:    "<<direccion<<endl;
			lectura>>cod;
			cout<<"\t________________________________\n";
		}
		
	}else{
		cout<<"El archivo no se pudo abrir \n";
	}
	lectura.close();
}
void buscar()
{
	ifstream lectura;
	lectura.open("administrador.txt", ios::out | ios::in);
	
	encontrado=false;
	
	if (lectura.is_open()){
		cout<<"\n\tIngresa la codigo del administrador que deseas buscar: ";
		cin>>cod_aux;
		
		lectura>>cod;
		while(!lectura.eof()){
			lectura>>nombre>>apellido>>correo>>telefono>>dni>>direccion>>pas;
			//comparar cada registro para ver si es encontrado
			comp==strcmp(cod,cod_aux);
			if (comp==0){
				cout<<"\n";
				cout<<"\tCodido:    "<<cod<<endl;
				cout<<"\tNombre:   "<<nombre<<endl;
				cout<<"\tApellido:   "<<apellido<<endl;
				cout<<"\tCorreo: "<<correo<<endl;
				cout<<"\tTelefono: "<<telefono<<endl;
				cout<<"\tDNI:    "<<dni<<endl;
				cout<<"\tDireccion:    "<<direccion<<endl;
				cout<<"\t________________________________\n";
				encontrado=true;
				break;
			}//fin del if mostrar encontrado
			
			//lectura adelantada
			lectura>>cod;
		}//fin del while
		if (encontrado==false){
			cout<<"\n\n\tNo hay registros con la clave: "<<cod_aux<<"\n\n\t\t\t";
		}
	}else{
		cout<<"\n\tAun no se pudo abrir el archivo...";
	}
	
	lectura.close();
}
void modificar()
{
	ofstream aux;
	ifstream lectura;
	
	encontrado=false;
	
	aux.open("auxiliar.txt", ios::out);
	lectura.open("administrador.txt", ios::in);
	
	if (aux.is_open() && lectura.is_open()){
		
		cout<<"\n";
		cout<<"\tIngresa la codigo del administrador que deseas modificar: ";
		cin>>cod_aux;
		
		lectura>>cod;
		while (!lectura.eof()){
			lectura>>nombre>>apellido>>correo>>telefono>>dni>>direccion>>pas;
			comp==strcmp(cod,cod_aux);
			if (comp==0){
				encontrado=true;
				cout<<"\n";
				cout<<"\tCodido:    "<<cod<<endl;
				cout<<"\tNombre:   "<<nombre<<endl;
				cout<<"\tApellido:   "<<apellido<<endl;
				cout<<"\tCorreo: "<<correo<<endl;
				cout<<"\tTelefono: "<<telefono<<endl;
				cout<<"\tDNI:    "<<dni<<endl;
				cout<<"\tDireccion:    "<<direccion<<endl;
				cout<<"\t________________________________\n\n";
				cout<<"\tIngresa el nuevo nombre del alumno con la clave: "<<cod_aux<<"\n\n\t---> ";
				cin>>auxnombre;
				
				aux<<cod<<" "<<auxnombre<<" "<<apellido<<" "<<correo<<" "<<telefono<<" "<<dni<<" "<<direccion<<" "<<pas;
				cout<<"\n\n\t\t\tRegistro modificado...\n\t\t\a";
			}else{
				aux<<cod<<" "<<nombre<<" "<<apellido<<" "<<correo<<" "<<telefono<<" "<<dni<<" "<<direccion<<" "<<pas;
			}
			lectura>>cod;
		}
	}else{
		cout<<"\n\tEl archivo no se pudo abrir \n";
	}
	
	if (encontrado==false){
		cout<<"\n\tNo se encontro ningun registro con la clave: "<<cod_aux<<"\n\n\t\t\t";
	}
	
	aux.close();
	lectura.close();
	remove ("administrador.txt");
	rename("auxiliar.txt", "administrador.txt");
}

int main()
{
	system ("color f0");
	int opc;
	
	do{
		system("cls");
		
		cout<<"\n\tManejo de archivos en c++\n\n";
		cout<<"\n\t1.-Altas";
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
			altas();
			cout<<"\n\t\t";
			system ("pause");
			break;
		}
		case 2:{
				system("cls");
				bajas();
				cout<<"\n\t\t";
				system ("pause");
				break;
			}
		case 3:{
					system("cls");
					consultas();
					cout<<"\n\t\t";
					system ("pause");
					break;
				}
		case 4:{
						system("cls");
						buscar();
						cout<<"\n\t\t";
						system ("pause");
						break;
					}
		case 5:{
							system("cls");
							modificar();
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



	
