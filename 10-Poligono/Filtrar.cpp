/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

//#include "includes\PoligonoCont.h"
#include "includes\PoligonoLink.h"
using namespace std;

//Main
int main (){
	string todosin="input/Todos.txt", filtrout="output/Filtrados.txt";
	CopiarPoligonosConPerimetrosMayoresA( 250, todosin, filtrout);
	return 0;
}