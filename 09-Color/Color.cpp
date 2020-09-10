/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

#include "Color.h"

int main(){
	Color c1={252,111,123}, c2={10,10,10}, comp, suma, resta;
	string hexa="", rgb="";
	
	c1=Mezclar(c1,c2);
	hexa=GetHtmlHex(c1);
	rgb=GetHtmlRGB(c1);
	comp=GetComplementario(c1);
	suma=Sumar(c1, c2);
	resta=Restar(c1, c2);
	CrearSvgConTextoEscritoEnAltoContraste(hexa,rgb,c2);
	
	assert(ROJO.col.at(0) == 255);
	assert(AZUL.col.at(2) == 255);
	assert(AMARILLO.col.at(1) == 255);
	
	assert(c1.col.at(0) == 127);
	assert(c1.col.at(1) == 60);
	assert(c1.col.at(2) == 66);
	
	assert(hexa == "#7F3C42");
	assert(rgb=="RGB(127,60,66)");
	
	assert(comp.col.at(0)==128);
	assert(comp.col.at(1)==195);
	assert(comp.col.at(2)==189);
	
	assert(suma.col.at(0) == 137);
	assert(resta.col.at(0) == 117);
}

