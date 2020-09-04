#include <iostream>
#include <cassert>
#include <string>
#include <array>

using namespace std;

//const
const unsigned MAX=3;
const unsigned MAX_PTOS=10;
const unsigned MAX_COLOR=4;

//declaro structs
struct Punto{double x, y;};

using TriPtos =std::array<Punto,MAX>;
using Colores= std::array <string,MAX_COLOR>;
using nPtos= std::array<Punto,MAX_PTOS>;

struct Triangulo{
	TriPtos trp; 
	Colores color;
};
struct Poligono{
	nPtos npto;
	Colores color;
	};
	

//Prototipos
void AgregarPtostri(Triangulo &);
void AgregarColortri(Triangulo &);
void AgregarPtospol(Poligono &);
void AgregarColorpol(Poligono &);

void MostrarTri(const Triangulo &);
void MostrarColorTri(const Triangulo &);
void MostrarPol(const Poligono &);
void MostrarColorPol(const Poligono &);
