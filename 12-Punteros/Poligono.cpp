/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

#include "PoligonoLink.h"
using namespace std;
//Main
int main (){
	ifstream in("input.txt");
	ofstream out("output.txt");
	float per=150;
	Poligono pol;
	Punto point={1,2}, point2={3,8}, point3={-1,-5}, point4={-4,5};

	pol.ppunto=nullptr;
	

	
	AddVertice(pol,point);	//(1,2)
	AddVertice(pol,point2);	// [1](1,2) [0](3,8)	
	AddVertice(pol,point3);	//[2](1,2) [1](3,8) [0](-1,-5)
	AddVertice(pol,point4); //[3](1,2) [2](3,8) [1](-1,-5) [0](-4,5)

	cout<<pol.ppunto->pto.x<<","<<pol.ppunto->pto.y;
	
	//Extraemos nuevos poligonos
	assert(ExtracSalPoligono(in, out, pol, -1));		


	
	return 0;
}
