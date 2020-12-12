/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/
#ifndef PUNTO_H
#define PUNTO_H
#include <cmath>
#include <iostream>
#include <string>
#include <array>
#include <cstdint>
#include <fstream>
#include <cstdio>

using namespace std;
//Constantes
#define PI 3.14159265

//Estructura
struct Punto{
	float x, y;
};

//Prototipos

float GetHip(Punto, Punto);
void MoverPunto(Punto &, int, int);
Punto SumarPuntos(const Punto&, const Punto&);
void MostrarPunto(const Punto&);
unsigned GetCuadrante(const Punto&);
Punto RestarPuntos(const Punto&, const Punto&);
double GetDistancia(const Punto&, const Punto&);
double GetDistanciaAlOrigen (const Punto&);


#endif