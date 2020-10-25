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
	float per=100.2;


	Punto test={99,99};
	Poligono pol;
	Color pruebacol;
	pruebacol.col.at(0)=1;
	pruebacol.col.at(1)=33;
	pruebacol.col.at(2)=200;
	pol.nvertices=4;						//Vamos a usarlo para setear sus lados

	assert(ExtraerPoligono(in, pol));
	//cout<<int(pol.colr.col.at(0));

	SalidaPoligono(out, pol);
	//SalidaColor(out, pol.colr);
	//SalidaPunto(out, pol.npto.at(0));

	assert(ExtraerPolXs_per(in, per));
	in.close();
	out.close();
	
	return 0;
}
