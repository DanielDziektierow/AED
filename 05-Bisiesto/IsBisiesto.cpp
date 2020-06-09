/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Año y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/
#include <cassert>

bool Bisiesto(unsigned);

int main(){
	assert(Bisiesto(2800));
	assert(Bisiesto(2400));
	assert(Bisiesto(2000));
	assert(Bisiesto(1600));
}

bool Bisiesto(unsigned anio){
	return anio>=1582 and anio%4 == 0 and anio%100 == 0 and anio%400 == 0;
}
