#include <iostream>
#include <cassert>
#include <cstdio>
#include <string>
#include <fstream>
#include <array>
#include <vector>
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


void SalidaPoligono(ofstream &, Poligono &);
void SalidaPunto(ofstream &, Punto &);
void SalidaColor(ofstream &, Color &);
void CopiarPoligonosConPerimetrosMayoresA(double,string,string);
void AgregarColorpol(Poligono &);
void MostrarColorPol(const Poligono &);
void LiberarMemoria(Poligono &);

//funciones
void AgregarColorpol(Poligono &p, Color c){
	p.colr.col=c.col;
}

void MostrarColorPol(const Poligono &p){
	cout<<GetHtmlRGB(p.colr);
}

void AddVertice(Poligono &pol, Punto p){
	if(pol.nvertices < MAX_PTOS){
		pol.npto.at(pol.nvertices)=p;
		++pol.nvertices;
	}
}

Punto GetVertice(const Poligono &p, unsigned v){
	return p.npto.at(v);
}

void SetVertice(Poligono &p, unsigned pos, Punto point){
	p.npto.at(pos)=point;
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
	while(i+1 < p.nvertices){
		per=per+GetHip(p.npto.at(i),p.npto.at(j));
		i++;
		++j;
	}
	per= per+ GetHip(p.npto.at(i), p.npto.at(0));		//distancia del ultimo pto con el inicial
	return per;
}

bool ExtracSalPoligono(ifstream &in,ofstream &out, Poligono & p, float per){
	bool aux=true;
	float xper;
	char carac;
	if(per < 0){
		while (carac!='#'){
			aux=ExtraerColor(in, p.colr);
			aux=ExtraerPuntos(in, p);
			SalidaPoligono(out, p);
			in>>carac;
		}
	}
	else
	{
		while (carac!='#'){
			aux=ExtraerColor(in, p.colr);
			aux=ExtraerPuntos(in, p);
			xper=GetPerimetro(p);
			if (xper > per)
			{
				SalidaPoligono(out, p);
			}			
			in>>carac;
		}
	}
	in.close();
	out.close();
	return bool(in);
}

bool ExtraerPoligono(ifstream &in, Poligono &p){
	bool aux=true;
	char carac;
	while ( carac != '#' and carac!='|')//#
	{
		aux=ExtraerColor(in, p.colr);
		aux=ExtraerPuntos(in, p);
		in>>carac;
	}
	return bool(in);
}

bool ExtraerPuntos(ifstream &in, Poligono &p){
	unsigned cant, i=0;
	char carac;
	in>>cant;
	p.nvertices=cant;
	in>>carac;
	if(carac == '{'){
		while (i<cant and carac != '}')
		{
			in>>p.npto.at(i).x;	//probando si lo toma
			in>>carac;
			in>>p.npto.at(i).y;
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

void SalidaPoligono(ofstream &out, Poligono &pol){
	unsigned i=0;			//Poligonos.size no tiene en cuenta el 0
	out<<"{";
	SalidaColor(out, pol.colr);
	while (i < pol.nvertices){
		SalidaPunto(out, pol.npto.at(i));
		++i;
	}
	out << "}\n" ;
	i=0;
}
	
void SalidaColor(ofstream &out, Color &c){
	out<<"R:"<<int(c.col.at(0))<<" G: "<<int(c.col.at(1))<<" B: "<<int(c.col.at(2))<<" ";
}

void SalidaPunto(ofstream &out, Punto &p){
	out <<" ("<<p.x<< ","<< p.y<< ")" ;
}

void CopiarPoligonosConPerimetrosMayoresA(double per,string polinput,string poloutput){
	ifstream in(polinput);
	ofstream out(poloutput);
	double perpol;
	bool flag;
	char carac;
	Poligono p;
	while (carac !='#')
	{
		flag=ExtraerPoligono(in,p);
		perpol=GetPerimetro(p);
		if (perpol > per)
		{
			SalidaPoligono(out,p);
		}
		LiberarMemoria(p);
		in>>carac;
	}
	
	//for(Poligono p; flag=ExtraerPoligono(in,p);){
	//	SalidaPoligono(out, p);	
	//}
	//flag=ExtraerPoligono(in, p);
	//SalidaPoligono(out, p);	
}

void LiberarMemoria(Poligono &p){
}