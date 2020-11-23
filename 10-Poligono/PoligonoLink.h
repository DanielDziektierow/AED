/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

//Tarea: leer los poligonos desde el out

#include <iostream>
#include <cassert>
#include <cstdio>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include "C:\Users\DanielDziektierow\Documents\AED\11-Punto\Punto.h"
#include "Color.h"


struct NodoPto{
	Punto pto;
	NodoPto *nextpto;
};

struct Poligono{
	unsigned nvertices;
	NodoPto *ppunto;
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
bool ExtraerPuntos(ifstream &,  Poligono &);
bool ExtraerColor(ifstream &, Color &);

void SalidaPoligono(ofstream &, Poligono &);
void SalidaPunto(ofstream &, Punto &);
void SalidaColor(ofstream &, Color );//Color &

void AgregarColorpol(Poligono &, Color);
void MostrarColorPol(const Poligono &);

//funciones
void AgregarColorpol(Poligono &p, Color c){
	p.colr.col=c.col;
}

void MostrarColorPol(const Poligono &p){
	cout<<GetHtmlRGB(p.colr);
}

void AddVertice(Poligono &pol, Punto p){			
	NodoPto *nuevo= new NodoPto();
	//Cargo datos del nuevo nodo
	nuevo->pto=p;
	nuevo->nextpto=pol.ppunto;
	//Armo la pila en el poligono
	pol.ppunto=nuevo;		
	++pol.nvertices;
}


void SetVertice(Poligono &p, unsigned v, Punto point){
	unsigned i=0;
	NodoPto *aux=p.ppunto;
	while(i<v){			//Recorremos lista
		aux=aux->nextpto;
		i++;	
	}
	aux->pto=point;
}

Punto GetVertice(const Poligono &p, unsigned v){
	NodoPto *aux = p.ppunto;
	unsigned i=0;
    while (aux != nullptr and i !=v )
    {
        aux = aux->nextpto;
		++i;
    }
	return aux->pto;
}

void RemoveVertice(Poligono &p){	
	NodoPto *aux = p.ppunto;
    p.ppunto = aux->nextpto;
    delete aux;
	--p.nvertices;
}

unsigned GetCantidadLados(const Poligono &p){
	NodoPto *aux = p.ppunto;
	unsigned i=0;
    while (aux != nullptr)
    {
        ++i;
		aux = aux->nextpto;
    }
	return i;			
}

float GetPerimetro(const Poligono &p){
	NodoPto *aux = p.ppunto;
	NodoPto  *aux2=p.ppunto->nextpto;
	float per=0;
	while(aux !=nullptr and aux2 != nullptr){
		per=per+GetHip(aux->pto, aux2->pto);
		aux=aux->nextpto;
		aux2=aux2->nextpto;
	}
	per= per+ GetHip(aux->pto, p.ppunto->pto);		//distancia del ultimo pto con el inicial
	return per;
}

bool ExtracSalPoligono(ifstream &in, ofstream &out, Poligono &p, float per){
	bool aux;
	NodoPto *aux2 = p.ppunto;
	float xper;
	char carac;
	if(per <0){
		while(carac!='#')
		{
			aux=ExtraerColor(in, p.colr);
			aux=ExtraerPuntos(in, p);
			SalidaPoligono(out, p);
			in>>carac;
		}
	}
	else
	{
		while(carac!='#')
		{
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

bool ExtraerPuntos(ifstream &in, Poligono &pol){
	unsigned i;
	char carac;
	NodoPto *aux = pol.ppunto;
	in>>pol.nvertices;
	in>>carac;								//{
	if(carac =='{'){
		while (aux != nullptr and carac != '}'){
			in>>aux->pto.x;	
			in>>carac;
			in>>aux->pto.y;
			in>>carac;
			aux = aux->nextpto;
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
	NodoPto *aux = pol.ppunto;
	unsigned i=0;
	out<<"{";
	SalidaColor(out, pol.colr);
	while (i<GetCantidadLados(pol)){
		SalidaPunto(out, aux->pto);
		aux=aux->nextpto;
		++i;
	}
	out << "}\n" ;
}

void SalidaColor(ofstream &out, Color c){
	out<<"R:"<<int(c.col.at(0))<<" G: "<<int(c.col.at(1))<<" B: "<<int(c.col.at(2))<<" ";
}

void SalidaPunto(ofstream &out, Punto &p){
	out <<" ("<<p.x<< ","<< p.y<< ")" ;

}
