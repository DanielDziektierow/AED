/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Año y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/
//Bibliotecas
#include <cassert>

//Declaraciones
int Div(int, unsigned);
int Mcd(int, int);
double Fact(int);			
int Fib(int);

int main (){
	int n=5;
	assert(Fact(n) == 120);
	assert(Fib(n) == 5);
	return 0;
}

//Definiciones
/*int Div(int n, unsigned div){
	return 0;
}

int Mcd(int n1, int n2){
	n1%2? n1=n1/2 : 
}
*/
double Fact(int n){
	return n!=0 ? n* Fact(n-1) :  1; 
}

int Fib(int n){
	return n>1? Fib(n-1) + Fib(n-2): (n==0? 0:1);
}
