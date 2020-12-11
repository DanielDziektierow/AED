/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/
#include "includes\PoligonoLink.h"
#include <cassert>
void mainPoligonoL(){
    Poligono pol;

    AgregarColorpol(pol, {0,100,200});
    MostrarColorPol(pol);
    

    AddVertice(pol, {2,2});
    AddVertice(pol, {2,1});
    AddVertice(pol, {1,1});
    AddVertice(pol, {1,0});

    SetVertice(pol, 3, {1,2});

    RemoveVertice(pol);
    
    assert(GetCantidadLados(pol) == 3);
    assert(GetPerimetro(pol) < 10);
    
}