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
	ifstream in("input.txt");
	ofstream out("output.txt");
	Punto test={99,99};
	Poligono pol;
	Color pruebacol;
	pruebacol.col.at(0)=1;
	pruebacol.col.at(1)=33;
	pruebacol.col.at(2)=200;
	pol.nvertices=4;						//Vamos a usarlo para setear sus lados

	assert(ExtraerPoligono(in, pol))
	in.close();
	SalidaColor(out, pruebacol);
	cout<<pruebacol.col.at(0);
	return 0;
}
	/*
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
	
	*/



