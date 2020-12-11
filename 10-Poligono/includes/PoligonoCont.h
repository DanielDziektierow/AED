/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/
#ifndef POLIGONOCONT_H
#define POLIGONOCONT_H
#include "Color.h"
#include "Punto.h"
//const
const unsigned MAX=3;
const unsigned MAX_PTOS=10;


//declaro structs
using nPtos= std::array<Punto,MAX_PTOS>;


struct Poligono{
	unsigned nvertices;
	nPtos npto;
	Color colr;
	};
	
//Prototipos

void SetVertice(Poligono &, unsigned, Punto);
Punto GetVertice(const Poligono &, unsigned);
void AddVertice(Poligono &, Punto);
void RemoveVertice(Poligono&);
unsigned GetCantidadLados(const Poligono &); 
float GetPerimetro(const Poligono &);

bool ExtracSalPoligono(ifstream &, ofstream &, Poligono &, float);
bool ExtraerPuntos(ifstream &, Poligono &);
bool ExtraerColor(ifstream &, Color &);
bool ExtraerPoligono(ifstream&, Poligono&);
void CopiarPoligonosConPerimetrosMayoresA(double,string,string);

void SalidaPoligono(ofstream &, Poligono &);
void SalidaPunto(ofstream &, Punto &);
void SalidaColor(ofstream &, Color &);

void AgregarColorpol(Poligono &, Color);
void MostrarColorPol(const Poligono &);
void LiberarMemoria(Poligono &);

#endif