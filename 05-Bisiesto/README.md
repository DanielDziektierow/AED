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
Definir una funcion que me devuelva un TRUE si es anio bisiesto.

- **Modelo IPO**
![Imagen de modelo IPO](https://user-images.githubusercontent.com/48501354/83956596-2d4ddf80-a836-11ea-9bc4-a2b2b319a829.jpg "Modelo IPO")


# Etapa # 2 Diseño de la Solución
* **Léxico del Algoritmo:**
    * anio ϵ N 
----------------------------------
* **Pruebas:**
int main()
{

assert(Bisiesto(2800));
	
assert(Bisiesto(2400));

assert(Bisiesto(2000));

assert(Bisiesto(1600));
}

* **Prototipos**
    * bool Bisiesto(unsigned);

* **Definiciones**
    *  Bisiesto(x)=  x< 1582 False

                     x/4 + x/100 + x/400 = 0 True
                     
                     otro False

* **Arbol**
![Imagen de Arbol](https://user-images.githubusercontent.com/48501354/84184487-d299cb00-aa63-11ea-902a-2578808856f4.jpg "Arbol")
