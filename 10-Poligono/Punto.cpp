/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/
#include "includes\Punto.h"

//funciones

float GetHip(Punto primer, Punto segundo){
	float hip;
	hip=sqrt(pow((segundo.x - primer.x),2)+pow((segundo.y - primer.y),2));
	return hip;
}

void MoverPunto(Punto & p, int x, int y){
	p.x=p.x + x;
	p.y= p.y + y;
}

Punto SumarPuntos (const Punto& p1, const Punto& p2){
    Punto sum;
    sum.x = p1.x + p2.x;
    sum.y = p1.y + p2.y;
    return sum;
}

void MostrarPunto(const Punto& p){
std::cout <<"(" <<p.x <<";" <<p.y <<")" <<"; ";
}

unsigned GetCuadrante(const Punto& p){
    if (p.x > 0 and p.y > 0) return 1;
     if (p.x < 0 and p.y > 0) return 2;
         if (p.x < 0 and p.y < 0) return 3;
             if (p.x > 0 and p.y < 0) return 4;
}

Punto RestarPuntos(const Punto& pa, const Punto& pb){
    Punto r;
    r.x = pa.x - pb.x;
    r.y = pa.y - pb.y;
    return r;
}

double GetDistancia(const Punto& pi, const Punto& pf){
    Punto v;
    double dist;
    v = RestarPuntos(pf, pi);
    dist = sqrt(pow(v.x,2) + pow(v.y,2));
    return dist;
}

double GetDistanciaAlOrigen(const Punto& p){
    double rta;
    rta = sqrt(pow(p.x,2) + pow(p.y,2));
    return rta;
}