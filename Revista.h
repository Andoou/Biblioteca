#ifndef REVISTA_H_
#define REVISTA_H_
#include "Material.h"
#include <string.h>

class Revista:Material{
private:
	string editorial;
public:
	Revista();
	Revista(string cod, string aut, string tit,int an, bool est,string edito);
	void crearRevista();
	void verRevistas();
	void toString();
};
#include "Revista.cpp"
#endif /* USUARIO_H_ */


