/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*AÃ±o y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

using namespace std;
#include <iostream>
#include <assert.h>
int main(){
    bool Pregunta1= true, Pregunta2=false;
    char Carac='D', Carac2=111;
    unsigned  int NumPos=256;
    double NumDouble=  2.14159;
    string str="Cadena";
    
	//BOOL
    //El tipo de datos bool devuelve un True o False\n"<<"Por ejemplo: Estamos en el 2020?
    Pregunta1=Pregunta1 & Pregunta2;	//Guardamos en Pregunta1 el producto logico de Pregunta1 anterior y Pregunta2
    assert(Pregunta1 == false);
    //Como podemos ver la respuesta es FALSE y por eso todavia sigue funcionando la app
    
    //CHAR
/*	El CHAR es el que se utiliza normalmente para almacenar y manipular caracteres en la
    mayoria de las computadoras, generalmente ocupa 8 bits (1byte), y es el tipo que se utiliza
    como base para medir el tamaño de los demas tipos del C++.
    Se puede representar por un numero pequeño del 0 al 127 o se puede escribir su caracter entre comillas simples.
*/
	Carac2=Carac2+2;
	assert(Carac == 'D');
	assert(Carac2 == 113);
//	Como podemos ver la respuesta es D y 113(q) y la app todavia sigue funcionando. 
	
    //Unsigned e Int
/*  El tipo de variable INT se usa para declarar numeros enteros.
	Para especificar si los valores a los que se refieren tienen o no signo empleamos las palabras
    SIGNED y UNSIGNED delante del nombre del tipo (por ejemplo UNSIGNED INT para enteros sin signo.
*/
	NumPos= NumPos+10;
    assert(NumPos == 266);
//	Como podemos ver la respuesta es 266 y la app todavia sigue funcionando.
	
    //Double
/*  El tipo double es similar a float, pero se utiliza cuando la precision de una variable de coma flotante
	no es suficiente. Las variables declaradas como tipo double pueden contener aproximadamente el doble de
	digitos significativos que las variables de tipo float.
*/
	NumDouble++;
	assert(NumDouble == 3.14159);
//	Como podemos ver la respuesta es 3.14159 y la app todavia sigue funcionando.
	
	//String
/*	En computacion las strings de C son secuencia de caracteres guardados
    como una matriz de caracteres terminados con un caracter nulo (contrabarra 0) o ASCII 0.
*/
    assert(str == "Cadena");
//	Como podemos ver la respuesta es Cadena y la app todavia sigue funcionando.
    
//	No son los unicos tipos los que vimos por clase, ya que tambien existen, void, float, short int, long int, etc.
    
}
