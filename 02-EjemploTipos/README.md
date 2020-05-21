<!--HEAD -->
# Adicion
# Etapa # 2: Analisis del problema

- **Transcripcion del problema:**  Este es un trabajo no estructurado, que consiste en escribir un programa que
ejemplifique el uso de los tipos de datos básicos de C++ vistos en clase:
1. bool
2. char
3. unsigned
4. int
5. double
6. string

- **Restricciones:**
No extraer valores de cin, usar valores literales (constantes).

- **Refinamiento del problema e hipótesis de trabajo:**

<!--En este ejercicio vamos a declarar variables del tipo bool,char, unsigned int, double, string.
Y verificar su valor con la funcion assert de la libreria assert.h
-->

- **Creditos extra**
1. Responder: ¿Son esos realmente todos los tipos que vimos en clase?
Justifique.
2. No utilizar cout y sí utilizar assert para las pruebas.
# Modelo IPO

![Imagen de modelo IPO](https://user-images.githubusercontent.com/48501354/82489131-7f150c80-9ab7-11ea-93c8-33781b226afc.png "Modelo IPO")

# Etapa # 2 Diseño de la Solución
* **Léxico del Algoritmo:**  

* Pregunta1,Pregunta2 ∈ bool
* Carac,Carac2 ∈ char
* NumPos ∈ Unsigned Int
* NumDouble ∈ Double
* str ∈ Cadena de caracteres

## __Representacion textual__
Inicio

  Pregunta1<-true
  
  Pregunta2<-false
  
  Carac<-'D'
  
  Carac2<-111
  
  NumPos<-256
  
  NumDouble<-2.14159
  
  str<-"Cadena"

  Pregunta1= Pregunta1 & Pregunta2

  Funcion: assert (Pregunta1 = false)

  Carac2= Carac2 + 2

  Funcion: assert(Carac = 'D')

	Funcion: assert(Carac2 = 113);

  NumPos= NumPos+10

  Funcion:  assert(NumPos = 266)

  NumDouble=NumDouble + 1

  Funcion: assert(NumDouble = 3.14159)

  assert(str = "Cadena")

Fin