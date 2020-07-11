<!--HEAD -->
# Funciones
# Etapa # 1: Analisis del problema

- **Transcripcion del problema:** Dado un año, determinar si es bisiesto.

- **Restriccion del problema**
 1. Definir la logica en una funcion.
 2. El nombre de la funcion debe ser IsBisiesto.
 3. Aplicar operadores booleanos.
 4. No aplicar operador condicional.
 5. No aplicar if ni switch.

- **Hipotesis del problema**
Primero se debemos determinar cuál es la definición de año bisiesto. Como el año Bisiesto se empezo a considerar a partir de 1582 vamos a armar la funcion no signada y que esta funcion nos devuelva un verdadero si el año es bisiesto, y falso si no lo es. Dentro de la función utilizaremos booleanos con operadores lógicos y la operación "modulo" (resto de una división entera) representada como "%"

La definición de un año bisiesto es que sea divisible por 4. Además no debe ser divisible por 100, excepto que también sea divisible por 400.

- **Modelo IPO**
![Imagen de modelo IPO](https://user-images.githubusercontent.com/48501354/87234896-dfd00f80-c3ab-11ea-8d90-c0f7b918c764.jpg "Modelo IPO")


# Etapa # 2 Diseño de la Solución
* **Léxico del Algoritmo:**
    * IsBisiesto: N -> B  
      a^((c ^ -l) U k) 
    a: x>=1582
    l: x%100 =0
    k: x%400 =0
    c: x%4 = 0
----------------------------------
* **Pruebas:**
int main()
{

assert(IsBisiesto(2800));
	
assert(IsBisiesto(2400));

assert(IsBisiesto(2000));

assert(IsBisiesto(1600));
}

* **Prototipos**
    * bool IsBisiesto(unsigned);

* **Definiciones**
    *  IsBisiesto(x)=  x< 1582 False

                     (x%4 * -x%100) + x%400 = 0 True
                     
                     otro False

* **Arbol**
![Imagen de Arbol](https://user-images.githubusercontent.com/48501354/87235248-81f1f680-c3b0-11ea-9f74-48d16670bd1d.jpg "Arbol")
