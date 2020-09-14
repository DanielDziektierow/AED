/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

#include "funciones.h"

//Main
int main (){
	unsigned ultimo_vertice=4;
	Punto test={99,99};
	Poligono pol;
	pol.nvertices=4;
	
	SetVertice(pol,pol.nvertices);
	AddVertice(pol,test);
	test=GetVertice(pol, pol.nvertices);	//posicion de array
	//assert(test.x == 4);
	//cout<<endl<<unsigned(test.x)<<endl;
	
	return 0;
}


