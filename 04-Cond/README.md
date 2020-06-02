<!--HEAD -->
# Funciones
# Etapa # 1: Analisis del problema

- **Transcripcion del problema:** Desarrollar las siguientes funciones:
1. Valor absoluto.
2. Valor mínimo entre dos valores.
3. Función , definida por:
    <!--[Grafico].-->

- **Restriccion del problema**
 1. Las pruebas deben realizarse con assert.
 2. Cada función debe aplicar el operador condicional.

- **Hipotesis del problema**
Basicamente es desarrollar las funciones absorcion, valor minimo y f3, de forma clara y sencilla.

# Etapa # 2 Diseño de la Solución
* **Léxico del Algoritmo:**
    * Absorcion: x ϵ R
    * Valor Minimo: x, y ϵ R
    * f3: x ϵ R 

* **Pruebas:**
        int main(){
            
            double numAbs=-39.1;
            double num1= 22.1,num2= 11.1;
            double x=2.1;
            assert(39.1 ==Abs(numAbs) );
            assert(Min(num1, num2) == 11.1);
            assert(f3(x)== -2.1);	    
        }

* **Prototipos**
    * Absorcion: double Abs(double);
    * Valor Minimo: double Min(double , double)
    * f3: double f3(double )

* **Definiciones**
    * Absorcion: 
    * Valor Minimo: 
    * f3: