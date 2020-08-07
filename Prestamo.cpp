#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <string>
#include "Prestamo.h"
#include "Libro.h"
#include "Usuario.h"
using namespace std;
struct Prestamo{
	char cod_usu [9] ="";
	char lib_1 [5] = "";
	char lib_2 [5] = "";
	char lib_3 [5] = "";
	char dia_ini[3] ="";
	char mes_ini[3] ="";
	char anio_ini[3] ="";
	char dia_f[3] ="";
	char mes_f[3] ="";
	char anio_f[3] ="";
	int cuota = 0;
	char status = '*';
};
int menuPrest() {
	char opcion[1];
	string nombre;
	
	do{
		system("cls");
		cin.clear();
		cout << "\t\t************************************" << endl;
		cout << "\t\t**         MENU DE PRESTAMO       **" << endl;
		cout << "\t\t************************************" << endl;
		cout << "\n\t\tQue desea hacer?" << endl;
		cout <<
			"\n\t\tA- Agregar un prestamo."
			"\n\t\tP- activar prestamo."
			"\n\t\tE- Eliminar prestamo."
			"\n\t\tD- Desactivar un prestamo."
			"\n\t\tV- Ver lista de prestamo."
			"\n\t\tS- Salir." << endl;
		cout << "\n\t\tDigite su opcion y luego enter>>> ";
		cin >> opcion;
		switch(opcion[0]){
		case 'a':
		case 'A':
			agregarPrest();
			system("pause");
			break;
			
		case 'm':
		case 'M':
			modificarPrestamo();
			system("pause");
			break;
			
		case 'p':
		case 'P':
			activarPrest();
			system("pause");
			break;
			
		case 'v':
		case 'V':
			verPrestamo();
			system("pause");
			break;
			
		case 'e':
		case 'E':
			eliminarPrestamo();
			system("pause");
			break;
			
		case 'd':
		case 'D':
			desactivarPrest();
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

void agregarPrest(){
	ofstream archivoGuardar("Prestamo.txt", ios::app);
	Prestamo prestamo;
	cin.ignore();
	
	fflush(stdin);
	cout << "\t\tIngrese codigo de ususario: ";
	cin.getline(prestamo.cod_usu,9);
	do{
		if(dniUnico(prestamo.cod_usu)==false) break;
		cout <<"\t\tDni no registrado, Ingrese otro: ";
		cin.getline(prestamo.cod_usu,9);
		
	}while(dniUnico(prestamo.cod_usu));
	
	cout << "\t\tIngrese codigo libro n° 1: ";
	cin.getline(prestamo.lib_1,5);
	do{
		if((codigoUnicoL(prestamo.lib_1)==false) && (libroEstado(prestamo.lib_1)==true)) break;
		cout <<"\t\tLibro no disponible!, Ingrese otro: ";
		cin.getline(prestamo.lib_1,5);
	}while((codigoUnicoL(prestamo.lib_1)==true) || (libroEstado(prestamo.lib_1)==false));
	inactivarLib(prestamo.lib_1);
	
	cout << "\t\tIngrese codigo libro n° 2: ";
	cin.getline(prestamo.lib_2,5);
	do{
		if((codigoUnicoL(prestamo.lib_2)==false) && (libroEstado(prestamo.lib_2)==true)) break;
		cout <<"\t\tLibro no disponible!, Ingrese otro: ";
		cin.getline(prestamo.lib_2,5);
	}while((codigoUnicoL(prestamo.lib_2)==true) || (libroEstado(prestamo.lib_2)==false));
	inactivarLib(prestamo.lib_2);
	
	cout << "\t\tIngrese codigo libro n° 3: ";
	cin.getline(prestamo.lib_3,5);
	do{
		if((codigoUnicoL(prestamo.lib_3)==false) && (libroEstado(prestamo.lib_3)==true)) break;
		cout <<"\t\tLibro no disponible!, Ingrese otro: ";
		cin.getline(prestamo.lib_3,5);
	}while((codigoUnicoL(prestamo.lib_3)==true) || (libroEstado(prestamo.lib_3)==false));
	inactivarLib(prestamo.lib_3);
	
	cout << "\t\tIngrese fecha de recogida del libro:\n ";
	do{cout << "\t\tIngrese dia de inicio: ";
	
	cin.getline(prestamo.dia_ini,3);}
	while(atoi(prestamo.dia_ini)>31);
	
	do{cout << "\t\tIngrese mes de inicio: ";
	cin.getline(prestamo.mes_ini,3);}
	while(atoi(prestamo.mes_ini)>12);
	
	cout << "\t\tIngrese año de inicio: ";
	cin.getline(prestamo.anio_ini,3);
	
	cout << "\t\tIngrese fecha entraga:\n ";
	do{cout << "\t\tIngrese dia de devolucion: ";
	cin.getline(prestamo.dia_f,3);}
	while(atoi(prestamo.dia_ini)>31  );
	
	do{cout << "\t\tIngrese mes de devolucion: ";
	cin.getline(prestamo.mes_f,3);}
	while(atoi(prestamo.mes_ini)>12);
	
	do{cout << "\t\tIngrese año de devolucion: ";
	cin.getline(prestamo.anio_f,3);}
	while(atoi(prestamo.anio_f)>atoi(prestamo.anio_ini));
	
	
	prestamo.cuota = 0;
	prestamo.status = 'A';
	
	archivoGuardar.write((char *)&prestamo, sizeof(prestamo));
	archivoGuardar.close();
	
}
	void verPrestamo(){
		system("cls");
		struct Prestamo prestamo;
		
		ifstream archivoMostrar("Prestamo.txt");
		archivoMostrar.read((char *)&prestamo, sizeof(prestamo));
		
		
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|   CODIGO DE USUARIO   |	LIBRO N°1	|    LIBRO N°2     |     LIBRON°3    |   	FECHA SALIDA	|     	FECHA ENTRAGA    |	CUOTA	|   CONDICION	|" << endl;
		
		while(archivoMostrar && !archivoMostrar.eof()){
			cout << " " << right << setw(9)
				<< prestamo.cod_usu <<"\t\t\t" << left << setw(20)				
				<< prestamo.lib_1 <<"  "<< left << setw(16)
				<< prestamo.lib_2 <<"  "<< left << setw(15)
				<< prestamo.lib_3 <<"  "<< left << setw(5)
				<< prestamo.dia_ini <<" "<< left << setw(5)
				<< prestamo.mes_ini <<" "<< left << setw(10)
				<< prestamo.anio_ini <<" "<< left << setw(5)
				<< prestamo.dia_f <<" "<< left << setw(5)
				<< prestamo.mes_f <<" "<< left << setw(13)
				<< prestamo.anio_f <<" "<< left << setw(13)
				<< prestamo.cuota <<" "<< left << setw(13)
				
				<< prestamo.status
				<< endl;
			archivoMostrar.read((char *)&prestamo, sizeof(prestamo));
		}
		archivoMostrar.close();
	}
		
	void modificarPrestamo(){
		
	}
			
	int prestamoLocalizado(string codigoBuscado){
			struct Prestamo prestamo;
			int counter = 0;
			string bufferCodigo;
			ifstream archivoMostrar("Prestamo.txt");
			archivoMostrar.read((char *)&prestamo, sizeof(prestamo));
			
			while(archivoMostrar && !archivoMostrar.eof()){
				counter++;
				bufferCodigo = prestamo.cod_usu;
				if(codigoBuscado == bufferCodigo){
					return counter;
				}
				archivoMostrar.read((char *)&prestamo, sizeof(prestamo));
			}
			archivoMostrar.close();
			return 0;
		}
			
		bool cambiadoPrestamo(int ubicacion){
				try{
					Prestamo prestamo;
					cin.ignore();
					
					cout << "\n\t\tIngrese codigo de usuario: ";
					cin.getline(prestamo.cod_usu,9);
					do{
						if(dniUnico(prestamo.cod_usu)==false) break;
						cout <<"\t\tDni no registrado, Ingrese otro: ";
						cin.getline(prestamo.cod_usu,9);
						
					}while(!dniUnico(prestamo.cod_usu));
					
					cout << "\t\tIngrese codigo de libro 1: ";
					cin.getline(prestamo.lib_1,5);
					do{
						if((codigoUnicoL(prestamo.lib_1)==false) && (libroEstado(prestamo.lib_1)==true)) break;
						cout <<"\t\tLibro no disponible!, Ingrese otro: ";
						cin.getline(prestamo.lib_1,5);
					}while((codigoUnicoL(prestamo.lib_1)==true) || (libroEstado(prestamo.lib_1)==false));
					inactivarLib(prestamo.lib_1);
			
					
					cout << "\t\tIngrese codigo de libro 2: ";
					cin.getline(prestamo.lib_2,5);
					do{
						if((codigoUnicoL(prestamo.lib_2)==false) && (libroEstado(prestamo.lib_2)==true)) break;
						cout <<"\t\tLibro no disponible!, Ingrese otro: ";
						cin.getline(prestamo.lib_2,5);
					}while((codigoUnicoL(prestamo.lib_2)==true) || (libroEstado(prestamo.lib_2)==false));
					inactivarLib(prestamo.lib_2);
					
					
					cout << "\t\tIngrese codigo de libro 3: ";
					cin.getline(prestamo.lib_3,5);
					do{
						if((codigoUnicoL(prestamo.lib_3)==false) && (libroEstado(prestamo.lib_3)==true)) break;
						cout <<"\t\tLibro no disponible!, Ingrese otro: ";
						cin.getline(prestamo.lib_3,5);
					}while((codigoUnicoL(prestamo.lib_3)==true) || (libroEstado(prestamo.lib_3)==false));
					inactivarLib(prestamo.lib_3);
					inactivarLib(prestamo.lib_3);
					
					cout << "\t\tIngrese fecha inicio:\n ";
					cout << "\tIngrese dia: ";
					cin.getline(prestamo.dia_ini,3);
					cout << "\tIngrese mes: ";
					cin.getline(prestamo.mes_ini,3);
					cout << "\tIngrese anio: ";
					cin.getline(prestamo.anio_ini,3);
					
					cout << "\t\tIngrese fecha entraga:\n ";
					cout << "\tIngrese dia: ";
					cin.getline(prestamo.dia_f,3);
					cout << "\tIngrese mes: ";
					cin.getline(prestamo.mes_f,3);
					cout << "\tIngrese anio: ";
					cin.getline(prestamo.anio_f,3);
					
					fstream archivoCambio("Prestamo.txt");
					archivoCambio.seekg((ubicacion-1)*sizeof(prestamo), ios::beg);
					
					archivoCambio.write((char *)&prestamo, sizeof(prestamo));
					archivoCambio.close();
					return true;
				}catch(exception e){
					cout << "Ha ocurrido un error"<< e.what();
					return false;
				}
			}
				void activarPrest(){
					char codigoBuscado [9];
					int ubicacion = 0;
					system("cls");
					
					verPrestamo();
					cin.ignore();
					cout << "\n\nIngrese codigo del usuario que solicito prestamo: ";
					cin.getline(codigoBuscado, 9);
					
					ubicacion = prestamoLocalizado(codigoBuscado);
					if(ubicacion) {
						cout << "Prestamo de usuario encontrado\n";
						cout << "....." << endl;
						if(activadoPres(ubicacion))
							cout << "El prestamo se ha activado" << endl;
						
					}else{
						cout << "Usuario no existe en el registro"<< endl;
					}
					
				}
				bool activadoPres(int ubicacion){
					try{
						int pos = ubicacion;
						struct Prestamo prestamo;
						ifstream archivoMostrar("Prestamo.txt");
						int c = 0;
						while(archivoMostrar && !archivoMostrar.eof()){
							archivoMostrar.read((char *)&prestamo, sizeof(prestamo));
							c++;
							if(c == ubicacion) break;
						}
					Prestamo prestamoin;
					strcpy(prestamoin.cod_usu, prestamo.cod_usu);
					strcpy(prestamoin.lib_1, prestamo.lib_1);
					strcpy(prestamoin.lib_2, prestamo.lib_2);
					strcpy(prestamoin.lib_3, prestamo.lib_3);
					strcpy(prestamoin.dia_ini, prestamo.dia_ini);
					strcpy(prestamoin.mes_ini, prestamo.mes_ini);
					strcpy(prestamoin.anio_ini, prestamo.anio_ini);
					strcpy(prestamoin.dia_f, prestamo.dia_f);
					strcpy(prestamoin.mes_f, prestamo.mes_f);
					strcpy(prestamoin.anio_f, prestamo.anio_f);
					
					prestamoin.cuota = actualizarPrest(prestamo.cod_usu,prestamo.dia_f,prestamo.mes_f,prestamo.anio_f);
					
					prestamoin.status = 'A';		
					
					fstream archivoCambio("Prestamo.txt");
					archivoCambio.seekg((pos-1)*sizeof(prestamo), ios::beg);
					archivoCambio.write((char *)&prestamoin, sizeof(prestamo));
					archivoCambio.close();
					archivoMostrar.close();
					
					return true;
				}catch(exception e){
					cout << "Ha ocurrido un error"<< e.what();
					return false;
					}
				}
					void desactivarPrest(){
						char codigoBuscado [9];
						int ubicacion = 0;
						system("cls");
						
						verPrestamo();
						cin.ignore();
						cout << "\n\nIngrese codigo del usuario que devolvio: ";
						cin.getline(codigoBuscado, 9);
						
						ubicacion = prestamoLocalizado(codigoBuscado);
						if(ubicacion) {
							cout << "Prestamo de usuario encontrado\n";
							cout << "....." << endl;
							if(desactivadoPres(ubicacion))
								cout << "El prestamo concluido" << endl;
							
						}else{
							cout << "Usuario no existe en el registro"<< endl;
						}
						
					}
						bool desactivadoPres(int ubicacion){
							try{
								int pos = ubicacion;
								struct Prestamo prestamo;
								ifstream archivoMostrar("Prestamo.txt");
								int c = 0;
								while(archivoMostrar && !archivoMostrar.eof()){
									archivoMostrar.read((char *)&prestamo, sizeof(prestamo));
									c++;
									if(c == ubicacion) break;
								}
								Prestamo prestamoin;
								strcpy(prestamoin.cod_usu, prestamo.cod_usu);
								strcpy(prestamoin.lib_1, prestamo.lib_1);
								strcpy(prestamoin.lib_2, prestamo.lib_2);
								strcpy(prestamoin.lib_3, prestamo.lib_3);
								strcpy(prestamoin.dia_ini, prestamo.dia_ini);
								strcpy(prestamoin.mes_ini, prestamo.mes_ini);
								strcpy(prestamoin.anio_ini, prestamo.anio_ini);
								strcpy(prestamoin.dia_f, prestamo.dia_f);
								strcpy(prestamoin.mes_f, prestamo.mes_f);
								strcpy(prestamoin.anio_f, prestamo.anio_f);
								
								prestamoin.cuota = 0;
								prestamoin.status = 'I';	
								reactivado(libroLocalizado(prestamo.lib_1));
								reactivado(libroLocalizado(prestamo.lib_2));
								reactivado(libroLocalizado(prestamo.lib_3));
								cout << "ingrese los datos de usuasrio que devolvio el libro.";
								eliminarPrestamo();
								
								fstream archivoCambio("Prestamo.txt");
								archivoCambio.seekg((pos-1)*sizeof(prestamo), ios::beg);
								archivoCambio.write((char *)&prestamoin, sizeof(prestamo));
								archivoCambio.close();
								archivoMostrar.close();
								return true;
							}catch(exception e){
								cout << "Ha ocurrido un error"<< e.what();
								return false;
							}
						}
							
				int actualizarPrest(char usu[9], char dF [9],char mF [9],char aF [9]){
					int dia_F = atoi(dF) ;
					int mes_F = atoi(mF);
					int anio_F = atoi(aF);
					time_t     now = time(0);
					struct tm  tstruct;
					char       buf[80];
					tstruct = *localtime(&now);
					double difference,castigo=1;
					strftime(buf, sizeof(buf), "%d-%m-%y", &tstruct);
					string ahora=buf;
					int dA=stoi(ahora.substr(0,2));
					int mA=stoi(ahora.substr(3,5));
					int anA=stoi(ahora.substr(6,7));
					{
						difference = ((anA*360)+(mA*30)+(dA))-((anio_F*360)+(mes_F*30)+(dia_F))*(castigo);
					}				
					if(difference>0){
						malo(usuarioLocalizado(usu));
						return difference;
					}else{
						bueno(usuarioLocalizado(usu));
						return 0;
					}
					
				}
					void eliminarPrestamo(){
						Prestamo prestamo;
						system("cls");
						verPrestamo();
						char bufferCodigo[9];
						cin.ignore();
						cout << "Ingrese el codigo del usuario, cone el prestamo a eliminar :";
						cin.getline(bufferCodigo, 9);
						if(prestamoLocalizado(bufferCodigo)){
							fstream archivoLectura("Prestamo.txt");
							ofstream archivoEscritura("auxiliar.txt");
							
							archivoLectura.read((char *) &prestamo, sizeof(prestamo));
							string codigoBuscado = bufferCodigo;
							while(archivoLectura && !archivoLectura.eof()){
								if(prestamo.cod_usu == codigoBuscado){
									//no hacer nada
								}else{
									archivoEscritura.write((char *) &prestamo, sizeof(prestamo));
								}
								archivoLectura.read((char *) &prestamo, sizeof(prestamo));
							}
							reactivado(libroLocalizado(prestamo.lib_1));
							reactivado(libroLocalizado(prestamo.lib_2));
							reactivado(libroLocalizado(prestamo.lib_3));
							archivoEscritura.close();
							archivoLectura.close();
							remove("Prestamo.txt");
							rename("auxiliar.txt", "Prestamo.txt");
							cout << "Ha sido eliminado el prestamo\n.";
							
						}else{
							cout << "No se ha encontrado el codigo: " << bufferCodigo << endl;
						}
					}
						
						
						void eliminarPrestamo(string bufferCodigo){
							Prestamo prestamo;
							if(prestamoLocalizado(bufferCodigo)){
								fstream archivoLectura("Prestamo.txt");
								ofstream archivoEscritura("auxiliar.txt");
								
								archivoLectura.read((char *) &prestamo, sizeof(prestamo));
								string codigoBuscado = bufferCodigo;
								while(archivoLectura && !archivoLectura.eof()){
									if(prestamo.cod_usu == codigoBuscado){
										//no hacer nada
									}else{
										archivoEscritura.write((char *) &prestamo, sizeof(prestamo));
									}
									archivoLectura.read((char *) &prestamo, sizeof(prestamo));
								}
								reactivado(libroLocalizado(prestamo.lib_1));
								reactivado(libroLocalizado(prestamo.lib_2));
								reactivado(libroLocalizado(prestamo.lib_3));
								archivoEscritura.close();
								archivoLectura.close();
								remove("Prestamo.txt");
								rename("auxiliar.txt", "Prestamo.txt");
								cout << "Ha sido eliminado el prestamo\n.";
								
							}else{
								cout << "No se ha encontrado el codigo: " << bufferCodigo << endl;
							}
						}
						void inactivarLib(string nom){
							inactivado(libroLocalizado(nom));
						}
						
					
				

