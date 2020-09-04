/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

#include "funciones.h"


//Main
int main (){
	double x=0.05, y=12;
	Triangulo ta;
	Poligono pol;
	
	AgregarPtostri(ta);
	AgregarColortri(ta);
	AgregarPtospol(pol);
	AgregarColorpol(pol);
	
//	assert(ta.trp.at(0).x==1);
//	assert(ta.color.at(1)=="azul");
//	assert(pol.npto.at(0).x==1);
//	assert(pol.color.at(0)=="cian");
//	MostrarTri(ta);
}

//Funciones
void AgregarPtostri(Triangulo &t){
	unsigned i=0;
	double x,y;
	cout<<"Triangulo:"<<endl;
	while(i<3){
		cout<<"px"<<i<<endl;
		cin>>x;
		cout<<"py"<<i<<endl;
		cin>>y;
		t.trp[i]={x,y};
		i++;	
	};
}

void AgregarColortri(Triangulo &t){
	unsigned i=0;
	string aux="";
	while(i<6 and aux!="0"){
		cout<<"color "<<i<<" (0 para salir)"<<endl;
		cin>>aux;
		t.color[i]={aux};
		i++;	
	};
}

void AgregarPtospol(Poligono &p){
	unsigned i=0;
	double x,y;
	cout<<"Poligono:"<<endl;
	while(i<3){
		cout<<"px"<<i<<endl;
		cin>>x;
		cout<<"py"<<i<<endl;
		cin>>y;
		p.npto[i]={x,y};
		i++;	
	};
}

void AgregarColorpol(Poligono &p){
	unsigned i=0;
	string aux="";
	while(i<6 and aux!="0"){
		cout<<"color "<<i<<" (0 para salir)"<<endl;
		cin>>aux;
		p.color[i]={aux};
		i++;	
	};
}

void MostrarTri(const Triangulo &t){
	cout<<t.trp[0].x<<endl;
};
