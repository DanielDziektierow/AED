<!--HEAD -->
# Funciones
# Etapa # 1: Analisis del problema

- **Transcripcion del problema:** Demostrar manejo de funciones definidas recursivamente e implementadas
con el operador condicional.

- **Restriccion del problema**
 1. Las pruebas deben realizarse con assert.
 2. Cada función debe aplicar el operador condicional.


- **Hipotesis del problema**
En la funcion Div lo que hace basicamente es devolver la division entre 2 numeros, cuantas veces puedo sumar un numero para llegar al otro sin sobrepasarme. Lo que hice para resolver este problema es simplemente crear la funcion y que dentro de esta devuelva por un lado la suma de 1 con la misma funcion con primer argumento el dividendo menos el divisor y segundo argumento el divisor. Con lo cual esta funcion va a llamarse asi misma hasta que el divisor sea mas grande que el dividendo.

- En la funcion Mcd lo que hace es sacar el maximo comun divisor de 2 numeros. la funcion compara que el segundo numero no sea 0, si es 0 devuelve el primer numero, sino se llama asi misma siendo el primer argumento el segundo de la funcion inicial, y como segudo argumento de esta nueva invocacion a Mcd el resto de la division entre los valores iniciales que le pasamos a Mcd.

- En la funcion Fact realiza el factorial de un numero. devolviendo 1 si es 0 o el numero por la funcion misma de el numero menos 1.

- En la funcion Fib va a realizar la funcion fibonacci, que seria dado un numero la funcion me va a devolver la suma de sus 2 funciones anteriores de fibonacci.
<!-- 
- **Modelo IPO**
![Imagen de modelo IPO](https://user-images.githubusercontent.com/48501354/87234896-dfd00f80-c3ab-11ea-8d90-c0f7b918c764.jpg "Modelo IPO")
-->

# Etapa # 2 Diseño de la Solución
* **Léxico del Algoritmo:**
    * Div: N x N -> N
    * Mcd: N x N -> N
    * Fact: Z -> R
    * Fib: Z -> Z  
      
----------------------------------
* **Pruebas:**
    * int main (){
        
        int n=5;
        
        unsigned u1=40, u2=30;
        
        assert(Fact(n) == 120);
        
        assert(Fib(n) == 5);
        
        assert(Mcd(u1, u2) == 10);
        
        assert(Div(u1, u2) == 1);
        
        return 0;}

* **Prototipos**
    * unsigned Div(unsigned, unsigned);
    * unsigned Mcd(unsigned, unsigned);
    * double Fact(int);			
    * int Fib(int);


* **Definiciones**
    *  unsigned Div(unsigned dividendo, unsigned divisor){

	        return dividendo >= divisor and divisor != 0 ? 1+ Div(dividendo - divisor, divisor) : 0;}


    * unsigned Mcd(unsigned n1, unsigned n2){
	    
            return n2 == 0 ? n1 : Mcd(n2, n1 % n2);}

    * double Fact(int n){
	        
            return n!=0 ? n* Fact(n-1) :  1; }

    * int Fib(int n){
	        
            return n>1? Fib(n-1) + Fib(n-2): (n==0? 0:1);}