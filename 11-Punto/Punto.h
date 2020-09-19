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

struct Punto{
	int x, y;
};

//Prototipos

int GetPhi(Punto , Punto );
unsigned GetHip(unsigned, unsigned);
void MoverPunto(Punto &, int, int);

//funciones

unsigned GetHip(Punto cat1, Punto cat2){
	unsigned hip, aux_x, aux_y;
	aux_x=cat2.x-cat1.x;
	aux_y=cat2.y-cat1.y;
	hip=pow(aux_x,2)+pow(aux_y,2);
	return hip;
}

/*int GetPhi(Punto p1, Punto p2){
	int disty, distx,phi, hip;
	disty=p2.y-p1.y;
	distx=p2.x-p1.x;
	hip= GetHip(disty,distx);
	sin(phi)=(p2.y-p1.y)/ hip;
	return phi;
}
*/