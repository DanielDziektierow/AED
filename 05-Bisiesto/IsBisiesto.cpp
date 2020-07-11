/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Año y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/
#include <cassert>

//Declaraciones
bool IsBisiesto(unsigned);

int main(){
	assert(IsBisiesto(2020));
	assert(IsBisiesto(2400));
	assert(IsBisiesto(2000));
	assert(IsBisiesto(1600));
}

//Funciones
bool IsBisiesto(unsigned anio){
	return  anio>=1582 and ((anio%4==0 and anio%100 != 0) or anio%400 == 0);
}
//a^(c u (l ^ k)) 
//Link de la info:
//https://docs.microsoft.com/es-es/office/troubleshoot/excel/determine-a-leap-year
