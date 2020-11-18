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


struct NodoPto{
	Punto pto;
	NodoPto *nextpto;
};

struct Poligono{
	unsigned nvertices;
	NodoPto *ppunto;
	Color colr;
};
	
struct Nodo
{
	Poligono p;
	Nodo *nextpol;
};
//Prototipos

void SetVertice(Poligono &, unsigned, Punto);
Punto GetVertice(const Poligono &, unsigned);
void AddVertice(Poligono &, Punto);
void RemoveVertice(Poligono&);
unsigned GetCantidadLados(const Poligono &); 
float GetPerimetro(const Poligono &);
void MostrarPuntos(Nodo *&);


//bool ExtraerPoligono(ifstream &, Poligono &);
bool ExtraerPuntos(ifstream &, Poligono &, unsigned);
bool ExtraerColor(ifstream &, Color &);
bool ExtraerPolXs_per(ifstream &, float);				//Extraer poligonos con erimetros mayores a....

void SalidaPoligono(ofstream &, Poligono &);
void SalidaPunto(ofstream &, Punto &);
void SalidaColor(ofstream &, Color );
void SalidaPolXs_per(ofstream &, Poligono &);			
void SalidaPolXs_per(ofstream &out);					//Enviar poligonos con erimetros mayores a....

void GuardarPoligono(const Poligono &);
void popPunto(Poligono &);
void popPoligono(Nodo &);
void AddPoligono(Nodo &, Poligono &);

void AgregarColorpol(Poligono &, Color);
void MostrarColorPol(const Poligono &);

//funciones
void AgregarColorpol(Poligono &p, Color c){
	p.colr.col=c.col;
}

void MostrarColorPol(const Poligono &p){
	cout<<GetHtmlRGB(p.colr);
}

void AddVertice(Poligono &pol, Punto p){			//*& Para que cambie ilimitadamente
	NodoPto *nuevo= new NodoPto();
	//Cargo datos del nuevo nodo
	nuevo->pto=p;
	nuevo->nextpto=pol.ppunto;
	//Armo la pila en el poligono
	pol.ppunto=nuevo;		
	++pol.nvertices;
}

void MostrarPuntos(NodoPto *&p)	//Opcional
{
    NodoPto *aux = p;
    while (aux != nullptr)
    {
        cout <<"("<< aux->pto.x<<", "<<aux->pto.y<<") " << endl;
        aux = aux->nextpto;
    }
}

void SetVertice(NodoPto *&l, unsigned v, Punto point){
	unsigned i=0;
	NodoPto *aux=l;
	while(i<v){			//Recorremos lista
		aux=aux->nextpto;
		i++;	
	}
	aux->pto=point;
}

//void AddPoligono(Nodo *&n, Poligono &p){
//	Nodo *nuevo=new Nodo();
//	nuevo->p=p;
//	nuevo->nextpol=n;
//	n =  nuevo;
//}

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


/*bool ExtraerPoligono(ifstream &in, Poligono & p){
	bool aux=true;
	char carac;
	in>>carac;
	aux=ExtraerColor(in, p.colr);
	aux=ExtraerPuntos(in, p, p.nvertices);
	in>>carac;
	return bool(in);
}
*/

bool ExtraerPuntos(ifstream &in, Poligono &pol, unsigned cant){
	unsigned i=0;
	char carac;
	NodoPto *aux = pol.ppunto;
	in>>cant;
	in>>carac;	//{
	if(carac =='{'){
		while (aux != nullptr and carac != '}'){
			in>>aux->pto.x;	//probando si lo toma
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
/*
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
*/	
void SalidaColor(ofstream &out, Color c){
	out<<"R:"<<int(c.col.at(0))<<" G: "<<int(c.col.at(1))<<" B: "<<int(c.col.at(2))<<" ";
}

/*void SalidaPunto(ofstream &out, Punto &p){
	//cout<<"Hola\n";
	out <<" ("<<p.x<< ","<< p.y<< ")" ;

}
/*
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
*/