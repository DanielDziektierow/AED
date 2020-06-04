<!--HEAD -->
# Funciones y Comparacion
# Etapa # 1: Analisis del problema

- **Transcripcion del problema:** Desarrollar una función que, dada una magnitud en Farehnheit, calcule la equivalente en Celsius:
 __Celcius(x)=5*(x-32)/9__

Hay dos sub-problemas que se requieren solucionar antes de poder probar e implementar la función Celsius:
- Valor de la fracción versus la división entera de la expresión 5/9 en C++.

- Representación no precisa de los tipos flotantes.

Una solución al primer problema es realizar división entre flotantes. Para el segundo problema, debemos incorporar la comparación con tolerancia, para eso debemos diseñar una función bool que reciba dos flotantes a comparar y un flotante que repesente la tolerancia

- **Restriccion del problema**
1. Las pruebas deben realizarse con assert.
2. Los prototipos deben ser:

double Celsius(double);

bool AreNear(double, double, double = 0.001);

- **Hipotesis del problema**
Basicamente es desarrollar las funciones que dada una magnitud en farehnheit la transforme a celcius.

# Etapa # 2 Diseño de la Solución
* **Léxico del Algoritmo:**
    * Celcius: t ϵ R
    * AreNear: a, b, tolerancia ϵ R

* **Pruebas:**
        

* **Prototipos**
    * AreNear: bool AreNear(double, double, double)
    * Celcius: double Celcius(double)

* **Definiciones**
    * Absorcion: 
    * Valor Minimo: 
    * f3: