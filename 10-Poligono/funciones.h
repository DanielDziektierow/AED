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
#include <fstream>
#include <array>
#include "C:\Users\DanielDziektierow\Documents\AED\11-Punto\Punto.h"
#include "Color.h"

using namespace std;

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

void SetVertice(Poligono &, unsigned);
Punto GetVertice(const Poligono &, unsigned);
void AddVertice(Poligono &, Punto);
void RemoveVertice(Poligono&);
unsigned GetCantidadLados(const Poligono &); 
float GetPerimetro(const Poligono &);

bool ExtraerPoligono(Poligono &);
bool ExtraerPuntos(ifstream &, Poligono &, unsigned);
bool ExtraerColor(ifstream &, Color &);
void AgregarColorpol(Poligono &);
void MostrarColorPol(const Poligono &);

//funciones
void AgregarColorpol(Poligono &p, Color c){
	p.colr.col=c.col;
}

void MostrarColorPol(const Poligono &p){
	cout<<GetHtmlRGB(p.colr);
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
	float x,y;
	//cout<<"Poligono:"<<endl;
	if(cant > 3){
		while(i< cant){
		//cout<<"px "<<i<<endl;
		cin>>x;						
		//cout<<"py "<<i<<endl;
		cin>>y;
		p.npto.at(i)={x,y};
		i++;	
		}
	}
}

unsigned GetCantidadLados(const Poligono &p){
	return p.nvertices;			
}

void RemoveVertice(Poligono &p){
	p.nvertices= p.nvertices -1;
}

float GetPerimetro(const Poligono & p){
	unsigned i=0, j=i+1;
	float per=0;
	while(i < p.nvertices){
		per=GetHip(p.npto.at(i),p.npto.at(j));
		i++;
		j++;
	}
	if(i == p.nvertices){			//distancia del ultimo pto con el inicial
		per= per+ GetHip(p.npto.at(i), p.npto.at(0));
	}
	return per;
}

/*bool ExtraerPoligono(Poligono & p){
	ifstream in("input.txt");

	ExtraerColor(in, p.colr);
	//ExtraerPuntos(in, p);
	return in;
}
*/
bool ExtraerPuntos(ifstream &in, Poligono &pol, unsigned cant){
	unsigned aux=0;
	char carac;
	in>>cant;
	in>>carac;
	if(carac =="{"){
		while (cant == 0){
			in>>pol.npto.at(cant).x;	//probando si lo toma
			//pol.npto.at(cant).x=aux;
			in>>carac;
			in>>pol.npto.at(cant).y;
			if(cant == 1) in>>carac;	//}
		--cant;
		}
	}

	
	return bool(in);
}

bool ExtraerColor(ifstream &in, Color &c){
	unsigned i=0, aux=0;
	char coma;
	while (i<=3)
	{
		in>>aux;
		in>>coma;
        c.col.at(i)=aux;
		++i;
	}
    return (bool)in;
}