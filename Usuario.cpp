#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <string>
#include "Usuario.h"
#include "Prestamo.h"

using namespace std;

struct Usuario{
    char dni [10] ="";
    char nombres [30] = "";
    char apellidos [30] = "";
    char correo [30] = "";
    char telefono[10] ="";
    char direccion[30] ="";
    char condicion = '*';
};


int menuUsuario(){
    char opcion[1];
    do{
        system("cls");
        cin.clear();
        cout << "\t\t************************************" << endl;
        cout << "\t\t**         MENU DE USUARIOS       **" << endl;
        cout << "\t\t************************************" << endl;
        cout << "\n\t\tQue desea hacer?" << endl;
        cout <<
             "\n\t\tA- Agregar un usuario."
             "\n\t\tM- Modificar datos de un usuario."
             "\n\t\tE- Eliminar un usuario."
             "\n\t\tV- Ver lista de usuarios."
             //Desechable Inactivar
             "\n\t\tI- Inactivar"
             "\n\t\tR- Reactivar"

             //Inactivar
             "\n\t\tS- Salir." << endl;
        cout << "\n\t\tDigite su opcion y luego enter>>> ";
        cin >> opcion;
        switch(opcion[0]){
            case 'a':
            case 'A':
                agregarUsuario();
                system("pause");
                break;

            case 'm':
            case 'M':
                modificarUsuario();
                system("pause");
                break;

            case 'e':
            case 'E':
                eliminarUsuario();
                system("pause");
                break;

            case 'v':
            case 'V':
                verUsuario();
                system("pause");
                break;

            case 'i':
            case 'I':
                condicionMala();
                system("pause");
                break;

            case 'r':
            case 'R':
                condicionBuena();
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
    } while(opcion[0]!='s' && opcion[0]!='S');
    return 0;
}


	bool isUsuario(string codigo){///si el administrador ingresa codigo y contraseña y si estan correctos los dos datos true
		struct Usuario user;
		ifstream archivoMostrar("Usuario.txt");
		archivoMostrar.read((char *)&user, sizeof(user));
		while(archivoMostrar && !archivoMostrar.eof()){
			if(user.dni==codigo)
				return true;
			archivoMostrar.read((char *)&user, sizeof(user));
		}
		archivoMostrar.close();
		return false;
	}	
bool intValido(string numero, int ingreso){
    int inicio=0;
    int tamanio = numero.length();
    bool isDigit=true;
    if(tamanio==0){
        cout <<"\t\t El dni esta vacio";
        isDigit=false;
    }
    if(tamanio==ingreso){
        for(int i=inicio;i<tamanio;i++){
            if(!isdigit(numero[i]))
                isDigit=false;;
        }}
    else{
        isDigit=false;
    }
    return isDigit;
}
bool esNumero(char *aux, int ingreso){
    bool esValido= false;
    esValido = intValido(aux, ingreso);
    return esValido;
}
bool isCaracter1(string palabra){
    int inicio=0;
    int tamanio = palabra.length();
    bool isChar=true;
    if(tamanio==0){
        isChar=false;
    }
    if(tamanio<30){
        for(int i=inicio;i<tamanio;i++){
            if(!isalpha(palabra[i])){
                if(palabra[i]==' '){isChar=true;}
                else isChar=false;
            }
        }
    }else{
        isChar=false;
    }
    return isChar;
}

char* esPalabra(char *aux, string atributo){

    bool esValido =false;
    while(!esValido){
        try{
            cout << "\t\tIngrese"<<atributo;
            cin.getline(aux,30);
            esValido=isCaracter1(aux);

            if(! esValido) throw aux;

        }
        catch(char* e){
            cout<<"\n\t\t El(Los)"<<atributo<<e<<" no es valido, contiene caracteres numericos"<<endl;
        }
    }
    return aux;
}
char* esDNIValido(char *aux, string atributo, int tamanio, int ingreso){
    bool validacion= false;

    while(!validacion){//true
        if(!dniUnico(aux)){

            cout <<"\t\tEl"<<atributo<<"ya esta registrado! \n\t\tIngrese"<<atributo<<": ";
            cin.getline(aux,tamanio);
            validacion=false;
        }else validacion=true;

        if(strlen(aux)!=(tamanio-2) || strlen(aux)==(tamanio-1) ){
            cout<< "\t\tEl"<<atributo<<"necesita ser de "<<(tamanio-2)<<" digitos \n\t\tIngrese"<<atributo<<": ";
            cin.getline(aux,tamanio);
            validacion=false;

            cin.clear();
        }
        else validacion=true;

        if(esNumero(aux, ingreso)==false){
            cout <<"\t\tHa ingresado un"<<atributo<<"que contiene datos no numericos \n\t\tIngrese"<<atributo<<": ";
            cin.getline(aux,tamanio);
            validacion =false;

        }else validacion =true;
    }
    return aux;
}
char* esFonoValido(char *aux, string atributo, int tamanio){
    bool validacion= false;
    if(esNumero(aux, 9)==false){
        cout <<"\t\tHa ingresado un"<<atributo<<"que contiene datos no numericos \n\t\tIngrese"<<atributo<<": ";
        cin.getline(aux,tamanio);
        validacion =false;

    }else validacion =true;
    return aux;
}

void agregarUsuario(){
    ofstream archivoGuardar("Usuario.txt", ios::app);
    Usuario usuario;

    cin.ignore();

    cout << "\n\t\tIngrese dni: ";
    char aux [9];
    cin.getline(aux,9);
    cin.clear();
    string dni=" dni ";
    strcpy(usuario.dni, esDNIValido(aux, dni,10, 8));

    //Ingrese nombre
    string nombre=" nombre(s): ";
    char aux1 [30];
    strcpy(usuario.nombres, esPalabra(aux1, nombre));

    //Ingrese apellidos
    string apellido=" apellido(s): ";
    char aux2 [30];
    strcpy(usuario.apellidos, esPalabra(aux2, apellido));


    cout << "\t\tIngrese correo: ";
    cin.getline(usuario.correo,30);

    //telefono
    cout << "\t\tIngrese telefono: ";
    char aux3 [10];
    cin.getline(aux3,10);
    cin.clear();
    string telefono=" telefono ";
    strcpy(usuario.telefono, esFonoValido(aux3, telefono,11));

    cout << "\t\tIngrese direccion: ";
    cin.getline(usuario.direccion,30);

    usuario.condicion = 'A';

    archivoGuardar.write((char *)&usuario, sizeof(usuario));
    archivoGuardar.close();
}

void verUsuario(){
    system("cls");
    struct Usuario usuario;

    ifstream archivoMostrar("Usuario.txt");
    archivoMostrar.read((char *)&usuario, sizeof(usuario));


    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|   DNI   |          NOMBRES          |         APELLIDOS           |           CORREO            |           TELEFONO           |          DIRECCION          |   CONDICION   |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    while(archivoMostrar && !archivoMostrar.eof()){

        cout << "" << right << setw(9)
             << usuario.dni <<"   " << left << setw(29)
             << usuario.nombres <<left << setw(30)
             << usuario.apellidos <<left << setw(30)
             << usuario.correo << left << setw(30)
             << usuario.telefono << left << setw(30)
             << usuario.direccion << left << setw(0)

             << usuario.condicion

             << endl;
        archivoMostrar.read((char *)&usuario, sizeof(usuario));
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    archivoMostrar.close();
}


void modificarUsuario(){
    char codigoBuscado [9];
    int ubicacion = 0;
    system("cls");

    verUsuario();
    cin.ignore();
    cout << "\n\nIngrese codigo del usuario a modificar: ";
    cin.getline(codigoBuscado, 9);

    ubicacion = usuarioLocalizado(codigoBuscado);
    if(ubicacion) {
        cout << "Usuario encontrado\n";
        cout << "Presione cualquier tecla para continuar" << endl;
        if(cambiadoUsuario(ubicacion))
            cout << "\nEl usuario se ha modificado con exito" << endl;

    }else{
        cout << "Usuario no existe en el archivo"<< endl;
    }

}

int usuarioLocalizado(string codigoBuscado){
    struct Usuario usuario;
    int counter = 0;
    string bufferCodigo;
    ifstream archivoMostrar("Usuario.txt");
    archivoMostrar.read((char *)&usuario, sizeof(usuario));

    while(archivoMostrar && !archivoMostrar.eof()){
        counter++;
        bufferCodigo = usuario.dni;
        if(codigoBuscado == bufferCodigo){
            return counter;
        }
        archivoMostrar.read((char *)&usuario, sizeof(usuario));
    }
    archivoMostrar.close();
    return 0;
}

bool cambiadoUsuario(int ubicacion){
    try{
        Usuario usuario;
        cin.ignore();

        cout << "\n\t\tIngrese dni: ";
        char aux [9];
        cin.getline(aux,9);
        cin.clear();
        string dni=" dni ";
        strcpy(usuario.dni, esDNIValido(aux, dni,10, 8));

        //Ingrese nombre
        string nombre=" nombre(s): ";
        char aux1 [30];
        strcpy(usuario.nombres, esPalabra(aux1, nombre));

        //Ingrese apellidos
        string apellido=" apellido(s): ";
        char aux2 [30];
        strcpy(usuario.apellidos, esPalabra(aux2, apellido));


        cout << "\t\tIngrese correo: ";
        cin.getline(usuario.correo,30);

        //telefono
        cout << "\t\tIngrese telefono: ";
        char aux3 [10];
        cin.getline(aux3,10);
        cin.clear();
        string telefono=" telefono ";
        strcpy(usuario.telefono, esFonoValido(aux3, telefono,11));

        cout << "\t\tIngrese direccion: ";
        cin.getline(usuario.direccion,30);


        fstream archivoCambio("Usuario.txt");
        archivoCambio.seekg((ubicacion-1)*sizeof(usuario), ios::beg);

        archivoCambio.write((char *)&usuario, sizeof(usuario));
        archivoCambio.close();
        return true;
    }catch(exception e){
        cout << "Ha ocurrido un error"<< e.what();
        return false;
    }
}

void eliminarUsuario(){
    Usuario usuario;
    system("cls");
    verUsuario();
    char bufferCodigo[9];
    cin.ignore();
    cout << "Ingrese la codigo del usuario a eliminar :";
    cin.getline(bufferCodigo, 9);
    if(usuarioLocalizado(bufferCodigo)){
        fstream archivoLectura("Usuario.txt");
        ofstream archivoEscritura("auxiliar.txt");

        archivoLectura.read((char *) &usuario, sizeof(usuario));
        string codigoBuscado = bufferCodigo;
        while(archivoLectura && !archivoLectura.eof()){
            if(usuario.dni == codigoBuscado){
                //no hacer nada
            }else{
                archivoEscritura.write((char *) &usuario, sizeof(usuario));
            }
            archivoLectura.read((char *) &usuario, sizeof(usuario));
        }
        archivoEscritura.close();
        archivoLectura.close();
		eliminarPrestamo(usuario.dni);
        remove("Usuario.txt");
        rename("auxiliar.txt", "Usuario.txt");
    }else{
        cout << "No se ha encontrado un libro con la codigo: " << bufferCodigo << endl;
    }
	
}

bool usuarioEstado(string codigoBuscado){ //ayudara para hacer lo de prestamos
    struct Usuario usuario;
    int ubicacion = usuarioLocalizado(codigoBuscado);
    ifstream archivoMostrar("Usuario.txt");
    int c = 0;
    while(archivoMostrar && !archivoMostrar.eof()){
        archivoMostrar.read((char *)&usuario, sizeof(usuario));
        c++;
        if(c == ubicacion) break;
    }
    if(usuario.condicion ==  'B') {
        return true;
    }else{
        cout << "Algo va mal"<< endl;
    }
    return false;
}

bool dniUnico(string codigoBuscado){

    struct Usuario usuario;
    ifstream archivoMostrar("Usuario.txt");
    archivoMostrar.read((char *)&usuario, sizeof(usuario));
    while(archivoMostrar && !archivoMostrar.eof()){
        if(usuario.dni==codigoBuscado)
            return false;
        archivoMostrar.read((char *)&usuario, sizeof(usuario));
    }
    archivoMostrar.close();
    return true;
}

void condicionMala(){
    char codigoBuscado [9];
    int ubicacion = 0;
    system("cls");

    verUsuario();
    cin.ignore();
    cout << "\n\nIngrese codigo del usuario a calificar: ";
    cin.getline(codigoBuscado, 9);

    ubicacion = usuarioLocalizado(codigoBuscado);
    if(ubicacion) {
        cout << "Usuario encontrado\n";
        cout << "....." << endl;
        if(malo(ubicacion))
            cout << "El usuario se ha calficado como malo" << endl;

    }else{
        cout << "Usuario no existe en el registro"<< endl;
    }

}

bool malo(int ubicacion){
    try{
        int pos = ubicacion;
        struct Usuario usuario;
        ifstream archivoMostrar("Usuario.txt");
        int c = 0;
        while(archivoMostrar && !archivoMostrar.eof()){
            archivoMostrar.read((char *)&usuario, sizeof(usuario));
            c++;
            if(c == ubicacion) break;
        }
        Usuario usuarioin;
        strcpy(usuarioin.dni, usuario.dni);
        strcpy(usuarioin.nombres, usuario.nombres);
        strcpy(usuarioin.apellidos, usuario.apellidos);
        strcpy(usuarioin.correo, usuario.correo);
        strcpy(usuarioin.telefono, usuario.telefono);
        strcpy(usuarioin.direccion, usuario.direccion);

        usuarioin.condicion = 'M';

        fstream archivoCambio("Usuario.txt");
        archivoCambio.seekg((pos-1)*sizeof(usuario), ios::beg);
        archivoCambio.write((char *)&usuarioin, sizeof(usuario));
        archivoCambio.close();
        archivoMostrar.close();
        return true;
    }catch(exception e){
        cout << "Ha ocurrido un error"<< e.what();
        return false;
    }
}

void condicionBuena(){
    char codigoBuscado [9];
    int ubicacion = 0;
    system("cls");

    verUsuario();
    cin.ignore();
    cout << "\n\nIngrese codigo del  usuario a calificar: ";
    cin.getline(codigoBuscado, 5);

    ubicacion = usuarioLocalizado(codigoBuscado);
    if(ubicacion) {
        cout << "Usuario encontrado\n";
        cout << "....." << endl;
        if(bueno(ubicacion))
            cout << "El usuario se ha reactivado " << endl;

    }else{
        cout << "Usuario no existe en el archivo"<< endl;
    }

}

bool bueno(int ubicacion){
    try{
        int pos = ubicacion;
        struct Usuario usuario;
        ifstream archivoMostrar("Usuario.txt");
        int c = 0;
        while(archivoMostrar && !archivoMostrar.eof()){
            archivoMostrar.read((char *)&usuario, sizeof(usuario));
            c++;
            if(c == ubicacion) break;
        }
        Usuario usuarioin;
        strcpy(usuarioin.dni, usuario.dni);
        strcpy(usuarioin.nombres, usuario.nombres);
        strcpy(usuarioin.apellidos, usuario.apellidos);
        strcpy(usuarioin.correo, usuario.correo);
        strcpy(usuarioin.telefono, usuario.telefono);
        strcpy(usuarioin.direccion, usuario.direccion);
        usuarioin.condicion = 'B';

        fstream archivoCambio("Usuario.txt");
        archivoCambio.seekg((pos-1)*sizeof(usuario), ios::beg);
        archivoCambio.write((char *)&usuarioin, sizeof(usuario));
        archivoCambio.close();
        archivoMostrar.close();
        return true;
    }catch(exception e){
        cout << "Ha ocurrido un error"<< e.what();
        return false;
    }
}


