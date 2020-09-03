#include <iostream>
#include <cassert>
#include <string>
#include <array>

using namespace std;

//declaro structs
struct Punto{double x, y;};

using TriPtos =std::array<Punto,3>;
using Colores= std::array <string,4>;
using nPtos= std::array<Punto,10>;

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

