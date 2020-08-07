#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <string>
#include "Administrador.h"

using namespace std;
struct Admin{
	char codigo [10] = "";
	char password [10] = "";
	char nombres [30] = "";
	char apellidos [30] = "";
	char direccion [30] = "";
	char correo [30] = "";
	char telefono [11] = "";
};
int menuAdmin() {
	char opcion[1];
	do{
		system("cls");
		cin.clear();
		cout << "\t\t************************************" << endl;
		cout << "\t\t**         MENU DE ADMINISTRADOR         **" << endl;
		cout << "\t\t************************************" << endl;
		cout << "\n\t\tQue desea hacer?" << endl;
		cout <<
			"\n\t\tA- Agregar un administrador."
			"\n\t\tM- Modificar un administrador."
			"\n\t\tE- Eliminar un administrador."
			"\n\t\tV- Ver lista de administrador."
			"\n\t\tS- Salir." << endl;
		cout << "\n\t\tDigite su opcion y luego enter>>> ";
		cin >> opcion;
		switch(opcion[0]){
		case 'a':
		case 'A':
			agregarAdmin();
			
			system("pause");
			break;
			
		case 'm':
		case 'M':
			modificarAdmin();
			system("pause");
			break;
			
		case 'e':
		case 'E':
			eliminarAdmin();
			system("pause");
			break;
			
		case 'v':
		case 'V':
			verAdmin();
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
void agregarAdmin(){
	ofstream archivoGuardar("Administrador.txt", ios::app);
	Admin admin;
	bool esValido=false;
	bool a=false;
	char aux [9];
	cin.ignore();
	cout << "\n\t\tIngrese codigo: ";
	cin.getline(aux,10);
	while(!a){
		if(!codigoUnico(aux)){
		cout <<"\t\tCodigo ya registrado!, Ingrese otro: ";
		cin.getline(aux,10); 
		a=false;
		}else a=true;
		
		if(strlen(aux)!=8 || strlen(aux)==9 ){
			cout <<"\t\tCodigo necesita ser de 8 digitos, Ingrese nuevamente: ";
			cin.getline(aux,10);
			a=false;
			
			cin.clear();
		}
		else a=true;
	}
	cin.clear();
	strcpy(admin.codigo, aux);
	fflush(stdin);
	cout <<"\t\t Ingrese la contraseña : ";
	cin.getline(admin.password,10);
	while(strlen(admin.password)!=8 || strlen(admin.password)==9){		
	
			cout <<"\t\tLa contraseña necesita ser de 8 digitos, Ingrese nuevamente: ";
			cin.getline(admin.password,10);
			
			cin.clear();
	}
	
	
	
	
	while(!esValido){
		try{
			cout << "\t\tIngrese nombres: ";
			cin.getline(admin.nombres,30);
			esValido=isCaracter(admin.nombres);
			if(! esValido) throw admin.nombres;
		}
		catch(char* e){
			cout<<"\n\t\t el nombre "<<e<<" no es valido"<<endl;
		}
	}
	esValido=false;
	
	
	
	
	
	while(!esValido){
		try{
			cout << "\t\tIngrese apellidos: ";
			cin.getline(admin.apellidos,30);
			esValido=isCaracter(admin.apellidos);
			if(! esValido) throw admin.apellidos;
		}
		catch(char* e){
			cout<<"\n\t\t el apellido "<<e<<" no es valido"<<endl;
		}
	}
	esValido=false;
	
	
	do{	
	cout << "\t\tIngrese direccion: ";
	cin.getline(admin.direccion,30);
	}while(strlen(admin.direccion)>30);
	
	do{	
	cout << "\t\tIngrese correo: ";
	cin.getline(admin.correo,30);
	}while(strlen(admin.correo)>30);
	
	
	while(!esValido || strlen(admin.telefono)==10){		
		try{
			cout << "\t\tIngrese telefono: ";
			cin.getline(admin.telefono,11);
			esValido=intValido(admin.telefono);
			if(! esValido) throw admin.telefono;
		}
		catch(char* e){
			cout<<"\n\t\t el numero de telefono"<<e<<" no es valido"<<endl;
		}
		cin.clear();
	}
	
	
	archivoGuardar.write((char *)&admin, sizeof(admin));
	archivoGuardar.close();
}
bool isLong(string aux){
	if(aux.length()==8) return true;
	return false;
}
bool intValido(string numero){
			int inicio=0;
			bool isDigit=true;
			if(numero.length()==0){isDigit=false;}
			if(numero.length()==9){
			for(int i=inicio;i<numero.length();i++){
				if(!isdigit(numero[i]))isDigit=false;;
			}}
			else{
				isDigit=false;
			}
			return isDigit;
		}
bool isCaracter(string numero){
				int inicio=0;
				bool isChar=true;
				if(numero.length()==0){isChar=false;}
				if(numero.length()<30){
			    for(int i=inicio;i<numero.length();i++){
					if(!isalpha(numero[i])){
						if(numero[i]==' '){isChar=true;}
						else isChar=false;
					}
				}
				}else{
					isChar=false;
				}
				return isChar;
}
bool codigoUnico(string codigoBuscado){
		struct Admin admin;
		ifstream archivoMostrar("Administrador.txt");
		archivoMostrar.read((char *)&admin, sizeof(admin));
		while(archivoMostrar && !archivoMostrar.eof()){
			if(admin.codigo==codigoBuscado)
				return false;
			archivoMostrar.read((char *)&admin, sizeof(admin));
		}
		archivoMostrar.close();
		return true;
}

void verAdmin(){///Ver todos los administradores
			system("cls");
			struct Admin admin;
			
			ifstream archivoMostrar("Administrador.txt");
			archivoMostrar.read((char *)&admin, sizeof(admin));
			
			cout << "\t\t------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "\t\t|   CODIGO  |         NOMBRES          |            APELLIDOS           |           CORREO          |            TELEFONO           |            DIRECCION          |" << endl;
			
			while(archivoMostrar && !archivoMostrar.eof()){
				cout << "\t\t" << right << setw(9)
					<< admin.codigo << "      " << left << setw(29)
					<< admin.nombres << left << setw(30)
					<< admin.apellidos << left << setw(30)
					<< admin.correo << left << setw(30)
					<< admin.telefono << left << setw(30)
					<< admin.direccion << left << setw(0)
					<< endl;
				archivoMostrar.read((char *)&admin, sizeof(admin));
			}
			archivoMostrar.close();
		}
void eliminarAdmin(){///Elimina administrador por codigo
		Admin admin;
		system("cls");
		verAdmin();
		char bufferCodigo[9];
		cin.ignore();
		cout << "Ingrese la codigo del administrador a eliminar :";
		cin.getline(bufferCodigo, 9);
		if(adminLocalizado(bufferCodigo)){
			fstream archivoLectura("Administrador.txt");
			ofstream archivoEscritura("auxiliarAdmin.txt");
			archivoLectura.read((char *) &admin, sizeof(admin));
			string codigoBuscado = bufferCodigo;
			while(archivoLectura && !archivoLectura.eof()){
				if(admin.codigo == codigoBuscado){
							//no hacer nada
				}else{
				archivoEscritura.write((char *) &admin, sizeof(admin));
				}
			archivoLectura.read((char *) &admin, sizeof(admin));
			}
			archivoEscritura.close();
			archivoLectura.close();
			remove("Administrador.txt");
			rename("auxiliarAdmin.txt", "Administrador.txt");
		}else{
			cout << "No se ha encontrado un administrador con el  codigo: " << bufferCodigo << endl;
		}
}
bool autenticar(string codigoAuten,string passAten){///si el administrador ingresa codigo y contraseña y si estan correctos los dos datos true
	struct Admin admin;
	ifstream archivoMostrar("Administrador.txt");
	archivoMostrar.read((char *)&admin, sizeof(admin));
	while(archivoMostrar && !archivoMostrar.eof()){
		if(admin.codigo==codigoAuten && admin.password==passAten)
			return true;
		archivoMostrar.read((char *)&admin, sizeof(admin));
	}
	archivoMostrar.close();
	return false;
}
int adminLocalizado(string codigoBuscado){
	
		struct Admin admin;
		int counter = 0;
		string bufferCodigo;
		ifstream archivoMostrar("Administrador.txt");
		archivoMostrar.read((char *)&admin, sizeof(admin));
		
		while(archivoMostrar && !archivoMostrar.eof()){
			counter++;
			bufferCodigo = admin.codigo;
			if(codigoBuscado == bufferCodigo){
				return counter;
			}
			archivoMostrar.read((char *)&admin, sizeof(admin));
		}
		archivoMostrar.close();
		return 0;
}
void modificarAdmin(){///Solo modifica la contraseña
	Admin admin;
	system("cls");
	verAdmin();
	char bufferCodigo[9];
	char pass_aux[9];
	cin.ignore();
	cout << "Ingrese la codigo del administrador a modificar :";
	cin.getline(bufferCodigo, 9);
	if(adminLocalizado(bufferCodigo)){
		fstream archivoLectura("Administrador.txt");
		ofstream archivoEscritura("auxiliarAdmin.txt");
		archivoLectura.read((char *) &admin, sizeof(admin));
		string codigoBuscado = bufferCodigo;
		while(archivoLectura && !archivoLectura.eof()){
			if(admin.codigo == codigoBuscado){
				cout << "Ingrese la nueva contraseña del administrador a modificar :";
				cin.getline(admin.password, 10);
				while(strlen(admin.password)!=8 || strlen(admin.password)==9){		
					
					cout <<"\t\tLa contraseña necesita ser de 8 digitos, Ingrese nuevamente: ";
					cin.getline(admin.password,10);
					
					cin.clear();
				}
			}
			archivoEscritura.write((char *) &admin, sizeof(admin));
			archivoLectura.read((char *) &admin, sizeof(admin));
		}
		archivoEscritura.close();
		archivoLectura.close();
		remove("Administrador.txt");
		rename("auxiliarAdmin.txt", "Administrador.txt");
	}else{
		cout << "No se ha encontrado un administrador con el  codigo: " << bufferCodigo << endl;
	}
}

