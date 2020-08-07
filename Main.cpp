
#include <iostream>
#include "Administrador.cpp"
#include "Libro.cpp"
#include "Usuario.cpp"
#include "Prestamo.cpp"
int main(){
	char opcion[1];
	char aux [9];
	char pass [9];
	system ("color 2F");
	system("cls");	
	do{
	system("cls");
		
	cout << "\t\t************************************" << endl;
	cout << "\t\t**         BIENVENIDO     **" << endl;
	cout << "\t\t************************************" << endl;
	cout << "\n\t\t Ingrese sus datos " << endl;
	cout <<"\t\tCodigo administrador : ";
	cin>>aux;
	cout <<"\t\tContraseña administrador: ";
	cin>>pass;
	if(autenticar(aux,pass)){	
	do{
	system("cls");
	cout << "\t\t************************************" << endl;
	cout << "\t\t**         MENU   **" << endl;
	cout << "\t\t************************************" << endl;
	cout << "\n\t\tIngrese que desea hacer " << endl;
	cout <<"\t\tA.Menu Administrador  "<< endl;
	cout <<"\t\tL.Menu Libros  "<< endl;
	cout <<"\t\tU.Menu Usuario  "<< endl;
	cout <<"\t\tP.Menu Prestamo  "<< endl;
	cout <<"\t\tS.Salir  "<< endl;
	cout<<"\n\n\tElige una opcion:  ";
	cin >> opcion;
	switch (opcion[0])
	{
	case 'a':
	case 'A':
		menuAdmin();
		system("pause");
		break;
	case 'l':
	case 'L':
		menuLibro();
		system("pause");
		break;
	case 'u':
	case 'U':
		menuUsuario();
		system("pause");
		break;
	case 'p':
	case 'P':
		menuPrest();
		system("pause");
		break;
	case 's':
	case 'S':
		break;
	}
	}while (opcion[0]!='s' && opcion[0]!='S');
	}else{
		cout<<"\t\tDATOS INCORRECTOS ... \n\n"<<endl;
	}
	cout<<"\n\n\t¿Quiere salir del sistema? si(S) no (N) ";
	cin >> opcion;
	}while(opcion[0]!='s' && opcion[0]!='S');
	
}
	





