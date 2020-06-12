# include  <Material.h>
# include  < iostream > _
# include  < string.h >
using std :: string;

Material :: Material () {
	codigo = { 0 , 0 , 0 , 0 , 0 };
	autor = " " ;
	titulo = " " ;
	anio= 0;
	estado = false
}

Material :: Material (int cod [5], string aut, string tit, int an, bool est) {
	codigo = cod;
	autor = aut ;
	titulo = tit ;
	anio= an;
	estado = est
}
int * Material :: getCodigo () {
	return codigo;
}
string Material :: getAutor () {
	regresar autor;
}
string Material :: getTitulo () {
	devolver titulo;
}
int Material :: getAnio () {
	return anio;
}
bool Material :: getEstado () {
	return estado;
}
