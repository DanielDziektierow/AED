/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

#include <iostream>
#include <cassert>
#include <string>
#include <array>
#include <cmath>
#include "Color.h"

using namespace std;

//const
const unsigned MAX=3;
const unsigned MAX_PTOS=10;
const unsigned MAX_COLOR=2;

//declaro structs
struct Punto{
	double x, y;
};

using nPtos= std::array<Punto,MAX_PTOS>;

struct Poligono{
	unsigned nvertices;
	nPtos npto;
	Colores colr;
	};
	

//Prototipos

int GetPhi(Punto , Punto );
int GetHip(int, int);

void SetVertice(Poligono &, unsigned);
Punto GetVertice(const Poligono &, unsigned);
void AddVertice(Poligono &, Punto);
void RemoveVertice(Poligono);
unsigned GetCantidadLados(const Poligono &); 
int GetPerimetro(const Poligono &);

void AgregarColorpol(Poligono &);

void MostrarColorPol(const Poligono &);

//funciones
void AgregarColorpol(Poligono &p, Color c){
	p.colr=c.col;
}

void MostrarColorPol(const Poligono &){
	cout<<GetHtmlRGB(p.colr);
}

/*int GetPhi(Punto p1, Punto p2){
	int disty, distx,phi, hip;
	disty=p2.y-p1.y;
	distx=p2.x-p1.x;
	hip= GetHip(disty,distx);
	sin(phi)=(p2.y-p1.y)/ hip;
	return phi;
}
*/

int GetHip(int cat1, int cat2){
	int hip;
	hip=pow(cat1,2)+pow(cat2,2);
	return hip;
}

void AddVertice(Poligono &pol, Punto p){
	if(pol.nvertices < MAX_PTOS){
		pol.nvertices=pol.nvertices +1;
		pol.npto.at(pol.nvertices)=p;
	}
}

Punto GetVertice(const Poligono &p, unsigned v){
	return p.npto.at(v);
}

void SetVertice(Poligono &p, unsigned cant){
	unsigned i=0;
	double x,y;
	cout<<"Poligono:"<<endl;
	if(cant > 3){
		while(i< cant){
		cout<<"px "<<i<<endl;
		cin>>x;						
		cout<<"py "<<i<<endl;
		cin>>y;
		p.npto.at(i)={x,y};
		i++;	
		}
	}
}

unsigned GetCantidadLados(const Poligono &p){
	return p.nvertices+1;			//ya que el array comienza en 0
}

void RemoveVertice(Poligono p){
	p.nvertices= p.nvertices -1;
}

int GetPerimetro(const Poligono &p){
	unsigned i=0, j=i+1;
	int per=0;
	while(i < p.nvertices){
		per=GetHip(p.npto.at(i),p.npto.at(j));
		i++;
	}
	if(i == p.nvertices){
		per= per+ GetHip(p.npto.at(i), p.npto(0));
	}
	return per;
}
