/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/
#include "includes\Color.h"
#include <cassert>
Color ROJO={255,0,0};
Color AZUL={0,0,255};
Color AMARILLO={255,255,0};
Color VERDE={0,255,0};
Color NARANJA={255,170,0};
Color VIOLETA={140,0,255};
Color NEGRO={0,0,0};
Color BLANCO={255,255,255};

void mainColor(){

    //Pruebas isIgual
    assert (isIgual(BLANCO, BLANCO));
    assert (not isIgual (BLANCO, ROJO));
    assert (not isIgual(AZUL, {250, 0, 0}));
    assert (isIgual (VERDE, {255, 0, 0}));

    //Pruebas Mezclar
    assert (isIgual (Mezclar (ROJO, AMARILLO), {255, 0, 127}));
    assert (not isIgual (Mezclar (ROJO, AZUL), NEGRO));

    //Pruebas MezclarConPartes
    assert (isIgual (Sumar(ROJO, NEGRO), {255,0,0} ));
    assert (not isIgual (Sumar(ROJO, AZUL), {255,0,0} ));

    //Pruebas RestarColores

    assert(isIgual(Restar(BLANCO, VERDE), {255,0,255}));
    assert (not isIgual (Restar(ROJO, AZUL), {0,0,0} ));

    //Pruebas GetComplementario

    assert (isIgual (GetComplementario (VIOLETA), BLANCO));
    assert (not isIgual (GetComplementario (NARANJA), NEGRO));

    //Pruebas GetHtmlHex

    assert ("#FF0000" == GetHtmlHex(ROJO));
    assert ("#FFFFFF" == GetHtmlHex(BLANCO));
    assert (not ("#FF00FF" == GetHtmlHex(NEGRO)));

    //Pruebas GetHtmlrgb

    assert ("RGB(255,0,0)" == GetHtmlRGB(ROJO));
    assert ("RGB(255,255,255)" == GetHtmlRGB(BLANCO));
    assert (not ("RGB(255,0,255)" == GetHtmlRGB(VERDE)));

    //Prueba CrearSvgConTextoEscritoEnAltoContraste

    CrearSvgConTextoEscritoEnAltoContraste("Prueba.svg", "Hola, Mundo!", AZUL);
    CrearSvgConTextoEscritoEnAltoContraste("Prueba 2.svg", "AED 2020 K1051", NEGRO);


}