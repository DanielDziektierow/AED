/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

#include "Color.h"

int main(){
	Color c1={252,111,123}, c2={10,10,10}, comp;
	string hexa="", rgb="";
	
	c1=Mezclar(c1,c2);
	hexa=GetHtmlHex(c1);
	rgb=GetHtmlRGB(c1);
	comp=GetComplementario(c1);
	
	assert(c1.col.at(0) == 127);
	assert(c1.col.at(1) == 60);
	assert(c1.col.at(2) == 66);
	
	assert(hexa == "#7F3C42");
	assert(rgb=="RGB(127,60,66)");
	
	assert(comp.col.at(0)==128);
	assert(comp.col.at(1)==195);
	assert(comp.col.at(2)==189);
	
}

