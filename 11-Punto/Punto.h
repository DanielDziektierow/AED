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
#include <array>
#include <cmath>

using namespace std;

//Constantes
#define PI 3.14159265

struct Punto{
	int x, y;
};

//Prototipos

int GetPhi(Punto , Punto);
int GetRho(Punto, Punto);
unsigned GetCuadrante(Punto);
//GetEje();
//GetSemiPlano();
unsigned GetHip(int, int);
void MoverPunto(Punto &, int, int);

//funciones

unsigned GetHip(int distx, int disty){
	unsigned hip, aux_x, aux_y;
	hip=pow(distx,2)+pow(disty,2);
	return hip;
}

int GetPhi(Punto p1, Punto p2){		//Respecto del origen
	unsigned dist1, dist2;
	dist1= GetHip(p1.x, p1.y);
	dist2= GetHip(p2.x, p2.y);
	return dist1 < dist2 ? acos(dist1/dist2) : acos(dist2/dist1);	 //debe ser en radianes
}

int GetRho(Punto p1, Punto p2){		//Respecto del origen
	unsigned dist1, dist2;
	dist1= GetHip(p1.x, p1.y);
	dist2= GetHip(p2.x, p2.y);
	return dist1 < dist2 ? asin(dist1/dist2) : acos(dist2/dist1);	 //debe ser en radianes
}

unsigned GetCuadrante(Punto p){
	if (p.x>0 and p.y>0) return 1;
	if (p.x<0 and p.y>0) return 2;
	if (p.x<0 and p.y<0) return 3;
	if (p.x>0 and p.y<0) return 4;
}

void MoverPunto(Punto & p, int x, int y){
	p.x=p.x + x;
	p.y= p.y + y;
}