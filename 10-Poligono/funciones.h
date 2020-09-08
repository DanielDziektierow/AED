#include <iostream>
#include <cassert>
#include <string>
#include <array>

using namespace std;

//const
const unsigned MAX=3;
const unsigned MAX_PTOS=10;
const unsigned MAX_COLOR=2;

//declaro structs
struct Punto{double x, y;};

using TriPtos =std::array<Punto,MAX>;
using Colores= std::array <uint8_t,MAX_COLOR>;
using nPtos= std::array<Punto,MAX_PTOS>;

struct Poligono{
	nPtos npto;
	//Color colr;
	};
	

//Prototipos

void SetVertice(Poligono &, unsigned);
Punto GetVertice(const Poligono &, unsigned);
//void AddVertice(Poligono &, Punto );
//void AgregarColorpol(Poligono &);

//void MostrarColorPol(const Poligono &);

void RemoveVertice(Poligono, Punto);
unsigned GetCantidadLados(const Poligono &); 
//double Get_GetPerímetro(const Poligono &);


/*
void AddVertice(Poligono &pol, Punto p){
	unsigned cantVertices;				
	//cantVertices=unsigned
	if(cantVertices != MAX_PTOS){
		pol.npto.at(cantVertices+1).x=p.x;
	}
}*/

Punto GetVertice(const Poligono &p, unsigned v){
	return p.npto.at(v);
}

void SetVertice(Poligono &p, unsigned cant){
	unsigned i=0;
	double x,y;
	cout<<"Poligono:"<<endl;
	while(i< cant){
		cout<<"px "<<i<<endl;
		cin>>x;						
		cout<<"py "<<i<<endl;
		cin>>y;
		p.npto.at(i)={x,y};
		i++;	
	};
}
