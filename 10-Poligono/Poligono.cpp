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
	unsigned cant=5;
	Punto test;
	Poligono pol;
	
	SetVertice(pol,cant);
	test=GetVertice(pol, 4);
	
	//assert(test.x == 4);
	
	
	//AddVertice(pol, {99,99});
	return 0;
}

//Funciones



/*void AgregarColorpol(Poligono &p){
	unsigned i=0;
	string aux="";
	while(i<6 and aux!="0"){
		cout<<"color "<<i<<" (0 para salir)"<<endl;
		cin>>aux;
		p.colr.at(i)={aux};
		i++;	
	};
}*/

