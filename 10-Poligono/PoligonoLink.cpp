/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/
#include "includes\PoligonoLink.h"

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
	return p.nvertices;			
}

float GetPerimetro(const Poligono &p){
	NodoPto *aux = p.ppunto;
	unsigned i=1;
	float per=0;
	while(i<p.nvertices){
		per=per+GetHip(aux->pto, aux->nextpto->pto);
		aux=aux->nextpto;
		++i;
	}
	per= per+ GetHip(aux->pto, p.ppunto->pto);		//distancia del ultimo pto con el inicial
	cout<<per<<" "<<aux->pto.x<<" "<<p.ppunto->pto.x<<endl;
	return per;
}

bool ExtraerPoligono(ifstream &in, Poligono & p){
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

void CopiarPoligonosConPerimetrosMayoresA(double per, string polinput, string poloutput){
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
	in.close();
	out.close();
}

void BorrarPoligono(Poligono &p){
	NodoPto *aux = p.ppunto;
	while (aux != nullptr)
	{
		p.ppunto = aux->nextpto;
		delete aux;
		--p.nvertices;
		aux=p.ppunto;
	}
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
	Punto point;
	char carac;
	unsigned i;
	in>>i;
	in>>carac;							
	if(carac =='{'){
		while (carac != '}'){
			in>>point.x;
			in>>carac;
			in>>point.y;
			AddVertice(pol,point);
			in>>carac;
		}
	}
	pol.nvertices=i;
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

void LiberarMemoria(Poligono &p){
	unsigned i=0;
	while (i<p.nvertices)
	{
		delete p.ppunto;
		++i;
	}
	
}

