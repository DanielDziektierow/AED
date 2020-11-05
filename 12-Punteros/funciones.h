/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

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


struct Poligono{
	unsigned nvertices;
	Punto *ppunto;
	Color colr;
	};
	
//declaro vectores
vector <Poligono> Poligonos;
vector <Poligono> PolXs_per;

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
bool ExtraerPolXs_per(ifstream &, float);

void SalidaPoligono(ofstream &, Poligono &);
void SalidaPunto(ofstream &, Punto &);
void SalidaColor(ofstream &, Color &);
void SalidaPolXs_per(ofstream &, Poligono &);
void SalidaPolXs_per(ofstream &out);

void GuardarPoligono(const Poligono &);

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
	pol.ppunto=new Punto;
	*pol.ppunto= p;
	++pol.nvertices;
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
	while(i+1 < p.nvertices){
		per=per+GetHip(p.npto.at(i),p.npto.at(j));
		i++;
		++j;
	}
	per= per+ GetHip(p.npto.at(i), p.npto.at(0));		//distancia del ultimo pto con el inicial
	return per;
}

bool ExtraerPoligono(ifstream &in, Poligono & p){
	bool aux=true;
	char carac;
	in>>carac;
	while (carac!='#')
	{
		aux=ExtraerColor(in, p.colr);
		aux=ExtraerPuntos(in, p, p.nvertices);
		cout<<"p"<<p.npto.at(0).x<<" ";
		GuardarPoligono(p);
		in>>carac;
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

bool ExtraerPolXs_per(ifstream &in, float per){
	float aux;
	unsigned i=0;
	while (i+1 <= Poligonos.size())			//Poligonos.size empieza en 1
	{
		aux=GetPerimetro(Poligonos.at(i));
		if(aux>per){
			PolXs_per.push_back(Poligonos.at(i));
		}
		++i;
	}
	return bool(in);	
}

void SalidaPoligono(ofstream &out, Poligono &pol){
	unsigned i=0, j=0;			//Poligonos.size no tiene en cuenta el 0
	while (j < Poligonos.size())
	{
		out<<"{";
    	SalidaColor(out, Poligonos.at(j).colr);
    	while (i < pol.nvertices){
        	SalidaPunto(out, Poligonos.at(j).npto.at(i)) ;
        	++i;
    	}
    	out << "}\n" ;
		i=0;
		++j;
	}
}
	
void SalidaColor(ofstream &out, Color &c){
	//out.open("output.txt");
	out<<"R:"<<int(c.col.at(0))<<" G: "<<int(c.col.at(1))<<" B: "<<int(c.col.at(2))<<" ";

}

void SalidaPunto(ofstream &out, Punto &p){
	//cout<<"Hola\n";
	out <<" ("<<p.x<< ","<< p.y<< ")" ;

}

void SalidaPolXs_per(ofstream &out){
	unsigned i=0, j=0;
	while (j< PolXs_per.size())
	{
		out<<"{";
    	SalidaColor(out, PolXs_per.at(j).colr);
    	while (i < PolXs_per.at(j).nvertices){
        	SalidaPunto(out, PolXs_per.at(j).npto.at(i)) ;
        	++i;
    	}
    	out << "}\n" ;
		i=0;
		++j;
	}	
}

void GuardarPoligono(const Poligono &p){
	Poligonos.push_back(p);
}

