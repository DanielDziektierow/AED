/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

#include "PoligonoCont.h"
//#include "PoligonoLink.h"
using namespace std;

//Main
int main (){
	ifstream in("input.txt");
	ofstream out("output.txt");
	float per=150;
	Poligono pol;

	assert(ExtracSalPoligono(in, out, pol, -1));		//Negativo te trae todos los poligonos , si es positivo nada mas poligonos con perimetros mayores a la cantidad que pasemos

	SetVertice(pol, 1, {212,344});
	assert(GetVertice(pol,1).x == 212);		//Último polinomio
	assert(GetCantidadLados(pol) == 4);
	assert(GetPerimetro(pol) > 1395);
	

	return 0;
}
