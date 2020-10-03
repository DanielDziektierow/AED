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
	unsigned lados;
	Punto test={99,99};
	Poligono pol;
	pol.nvertices=4;						//Vamos a usarlo para setear sus lados
	
	SetVertice(pol,pol.nvertices);			
	//No olvidar setear el primer elemento en 1 para que no falle el assert
	AddVertice(pol,test);
	test=GetVertice(pol, pol.nvertices);	//posicion de array
	lados=GetCantidadLados(pol);
	AgregarColorpol(pol, ROJO);

	assert(pol.npto.at(0).x == 1);
	assert(pol.nvertices == 5);
	assert(test.y ==99 );
	assert(lados == 5);
	assert(pol.colr.col == ROJO.col);

	RemoveVertice(pol);
	assert(pol.nvertices == 4);
	
	
	return 0;
}


