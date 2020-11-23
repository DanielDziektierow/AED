/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

//#include "PoligonoCont.h"
#include "PoligonoLink.h"
using namespace std;

//Main
int main (){
	//ifstream in("inputLink.txt");
	ifstream in("inputCont.txt");
	ofstream out("output.txt");
	float per=150;
	Poligono pol;
	Punto point={1,2}, point2={3,8}, point3={-1,-5}, point4={-4,5};


	//todos los poligonos deben tener 4 vertices, sino adderir uno
	pol.ppunto=nullptr;
	AddVertice(pol,point);	//(1,2)
	AddVertice(pol,point2);	// [1](1,2) [0](3,8)	
	AddVertice(pol,point3);	//[2](1,2) [1](3,8) [0](-1,-5)
	AddVertice(pol,point4); //[3](1,2) [2](3,8) [1](-1,-5) [0](-4,5)

	cout<<pol.ppunto->pto.x<<","<<pol.ppunto->pto.y<<endl;

	SetVertice(pol, 1, {212,344});
	assert(GetVertice(pol,1).x == 212);		
	assert(GetCantidadLados(pol) == 4);
	assert(GetPerimetro(pol) > 800 and GetPerimetro(pol)<810);
	
	assert(ExtracSalPoligono(in, out, pol, -1));		//Negativo te trae todos los poligonos , si es positivo nada mas poligonos con perimetros mayores a la cantidad que pasemos

/*	SetVertice(pol, 1, {212,344});
	assert(GetVertice(pol,1).x == 212);		
	assert(GetCantidadLados(pol) == 4);
	assert(GetPerimetro(pol) > 1395);
*/	
	
	MostrarColorPol(pol);
	pol.colr=Mezclar(AZUL, pol.colr);
	cout<<"\n"<<GetHtmlHex(pol.colr);
	cout<<"\n"<<GetHtmlRGB(pol.colr);
	cout<<"\n"<<DecaHex(1000);
	CrearSvgConTextoEscritoEnAltoContraste("Hola","Chau",pol.colr);
	assert(not isIgual(pol.colr, VERDE));
	
	return 0;
}
