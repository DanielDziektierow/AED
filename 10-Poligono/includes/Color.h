/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

// Foo.h
//#ifndef FOO_H_INCLUDED 
//#define FOO_H_INCLUDED
#ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include <string>
#include <array>
#include <cstdint>
#include <fstream>
#include <cstdio>


using namespace std;
//const
const unsigned MAX_COLOR=3;


//Structs
using Colores= std::array <uint8_t,MAX_COLOR>;

struct Color{
	Colores col;
};



//Prototipos
Color Mezclar(Color &, Color &);
string GetHtmlHex(const Color &);
string GetHtmlRGB(const Color &);
Color Sumar(Color &, Color &);
Color Restar(Color &, Color &);
Color GetComplementario(const Color &);
string DecaHex(unsigned n);
void CrearSvgConTextoEscritoEnAltoContraste(string , string , const Color& );
bool isIgual(const Color &c1, const Color &c2);

#endif