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
	unsigned lados;
	float per=100.2;
	Poligono pol;
	Punto point={1,2}, point2={3,8}, point3={-1,-5};
	pol.ppunto=nullptr;
	
	ifstream in("input.txt");
	ofstream out("output.txt"), mayores("polMayores.txt");
	
	AddVertice(pol,point);	//(1,2)
	
	AddVertice(pol,point2);	// [1](1,2) [0](3,8)
	cout<<GetVertice(pol, 0).y<<endl;
	
	AddVertice(pol,point3);	//[2](1,2) [1](3,8) [0](-1,-5)
	cout<<GetVertice(pol, 2).y<<endl;

	//MostrarPuntos(pol.ppunto);

	SetVertice(pol.ppunto,1,point);
	//MostrarPuntos(pol.ppunto);
	
	//RemoveVertice(pol);					//hacerla bool	
	//MostrarPuntos(pol.ppunto);
	cout<<"\n"<<GetCantidadLados(pol)<<endl;
	cout<<GetPerimetro(pol)<<endl;

	//AddPoligono(nd, pol);
	assert(ExtraerColor(in, pol.colr));
	assert(ExtraerPuntos(in,pol,pol.nvertices));
	SalidaColor(out,pol.colr);

	//assert(ExtraerPolXs_per(in, per));
	//SalidaPolXs_per(mayores);

	in.close();
	out.close();
	
	return 0;
}
