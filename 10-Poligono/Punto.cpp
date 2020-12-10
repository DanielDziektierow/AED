/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/
#include "includes\Punto.h"

//funciones

float GetHip(Punto primer, Punto segundo){
	float hip;
	hip=sqrt(pow((segundo.x - primer.x),2)+pow((segundo.y - primer.y),2));
	return hip;
}

void MoverPunto(Punto & p, int x, int y){
	p.x=p.x + x;
	p.y= p.y + y;
}