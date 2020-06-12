
# ifndef MATERIAL_H_
# define  MATERIAL_H
# include  < iostream > _
# include  < string.h >
using std :: string;
clase  Material {
	privado:
		int * codigo;
	string autor;
	string titulo;
	int anio;
	bool estado;
	
public:
	Material();
	Material(int codigo[5], string autor, string titulo, string anio, string estado)
		int getCodigo();
	string getAutor();
	string getTitulo();
	int getAnio();
	bool getEstado();
};
