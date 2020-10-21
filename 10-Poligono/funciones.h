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

bool ExtraerPoligono(ifstream &, Poligono &);
bool ExtraerPuntos(ifstream &, Poligono &, unsigned);
bool ExtraerColor(ifstream &, Color &);
bool SalidaPoligono(ofstream &, Poligono &);
bool SalidaPuntos(ofstream &, Poligono &);
void SalidaColor(ofstream &, Color &);

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

bool ExtraerPoligono(ifstream &in, Poligono & p){
	while (not in.eof())
	{
		assert(ExtraerColor(in, p.colr));
		assert(ExtraerPuntos(in, p, p.nvertices));
	}
	return bool(in);
}

bool ExtraerPuntos(ifstream &in, Poligono &pol, unsigned cant){
	unsigned aux=0, i=0;
	char carac;
	in>>cant;
	in>>carac;	//{
	if(carac =='{'){
		while (i < cant and carac != '}'){
			in>>pol.npto.at(i).x;	//probando si lo toma
			in>>carac;
			in>>pol.npto.at(i).y;
			in>>carac;
			++i;
		}
	}
	return bool(in);
}

bool ExtraerColor(ifstream &in, Color &c){
	unsigned i=0, aux=0;
	char coma;
	while (i<3)
	{
		in>>aux;
		in>>coma;
        c.col.at(i)=aux;
		++i;
	}
	return bool(in);
}

bool SalidaPoligono(std::ostream &out, const Poligono &pol){
	unsigned i=0;
	out<<"{";
    SalidaColor(out, pol.c);
    while (i < pol.n){
        SalidaPunto(out, pol.npto.at(i)) ;
        ++i;
    }
    out << "} " <<"\n" ;
    return bool (os);
}

void SalidaColor(ofstream &out, Color &c){
	out.open("output.txt");
	out<<"R: "<<c.col.at(0)<<"G: "<<c.col.at(1)<<"B: "<<c.col.at(2)<<" ";
	out.close();
}

bool SalidaPuntos(ofstream &out, Punto &p){
	os <<"("<< p.x << "," << p.y << ")" ;
	return bool (os);
}

