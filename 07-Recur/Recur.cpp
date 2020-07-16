/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Año y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

//Bibliotecas
#include <cassert>

//Prototipos o declaraciones
unsigned Div(unsigned, unsigned);
unsigned Mcd(unsigned, unsigned);
double Fact(int);			
int Fib(int);

int main (){
	int n=5;
	unsigned u1=40, u2=30;
	assert(Fact(n) == 120);
	assert(Fib(n) == 5);
	assert(Mcd(u1, u2) == 10);
	assert(Div(u1, u2) == 1);
	return 0;
}

//Definiciones
unsigned Div(unsigned dividendo, unsigned divisor){
	return dividendo >= divisor and divisor != 0 ? 1+ Div(dividendo - divisor, divisor) : 0;
}

unsigned Mcd(unsigned n1, unsigned n2){
	return n2 == 0 ? n1 : Mcd(n2, n1 % n2);
}

double Fact(int n){
	return n!=0 ? n* Fact(n-1) :  1; 
}

int Fib(int n){
	return n>1? Fib(n-1) + Fib(n-2): (n==0? 0:1);
}
