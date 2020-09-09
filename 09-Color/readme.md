<!--HEAD -->
# Funciones
# Etapa # 1: Analisis del problema

- **Transcripcion del problema:** Diseñar un tipo Color basado en el modelo RGB1, con tres canales de 8 bits.
Todo color está compuesto por tres componentes: intensidad de red (rojo), de green (verde), y de blue (azul). Cada intensidad está en el rango [0, 255]. Definir los valores para rojo, azul, verde, cyan, magenta, amarillo, negro, y blanco. Dos
colores se pueden mezclar, lo cual produce un nuevo color que tiene el promedio de intensidad para cada componente.


- **Restriccion del problema**
 1. Las operaciones de proyección para red, green, y blue se implementan con acceso directo a los componentes, no es necesario definir getters especiales.
Por la misma razón, los setters no son necesarios.
 2. Utilizar el tipo uint8_t de cstdint, si no es posible, usar unsigned char.
 3. Los colores primarios, secundarios, negro y blanco deben implementarse como ocho variables declaradas fuera de main y de toda función, con el
calificador const para que no puedan modificarse.
 4. Implementar la operación IsIgual que retorna true si un color es igual a otro, si no, false



- **Hipotesis del problema**
Para armar la estructura de Color tenemos 2 posibilidades, armar una estructura de 3 variables con el mismo tipo de dato o armar un array. En nuestro caso vamos a elegir un array. Para el tipo de dato tambien tenemos 2 posibilidades, uint8_t o unsigned char. En nuestro caso vamos a tomar uint8_t.

<!-- - **Modelo IPO**
![Imagen de modelo IPO](https://user-images.githubusercontent.com/48501354/87234896-dfd00f80-c3ab-11ea-8d90-c0f7b918c764.jpg "Modelo IPO")
-->

# Etapa # 2 Diseño de la Solución
* **Léxico del Algoritmo:** 
    * Mezclar: [Color]* X [Color]* --> Color
    * GetHtmlHex: [Color]* --> E*
    * GetHtmlRGB: [Color]* --> E*
    * Sumar: [Color]* X [Color]* --> Color
    * Restar: [Color]* X [Color]* --> Color
    * GetComplementario: [Color *]* --> Color
    * DecaHex: N --> E*
    * CrearSvgConTextoEscritoEnAltoContraste: E* X E* X [Color *]*
      
----------------------------------
* **Prototipos**
    * Color Mezclar(Color &, Color &);
    * string GetHtmlHex(const Color &);
    * string GetHtmlRGB(const Color &);
    * Color Sumar(Color &, Color &);
    * Color Restar(Color &, Color &);
    * Color GetComplementario(const Color &);
    * string DecaHex(unsigned n);
    * void CrearSvgConTextoEscritoEnAltoContraste(string , string , const Color& );

* **Definiciones**
    *  Color Mezclar(Color &c1, Color &c2){
	Color aux={0,0,0};
	unsigned i=0;
	while(i<3){
		aux.col.at(i)=c1.col.at(i) + c2.col.at(i);
		if(unsigned(c1.col.at(i)) + unsigned(c2.col.at(i)) >255){
			aux.col.at(i)=255;
		}
		aux.col.at(i)=aux.col.at(i)/2;
		i++;
	}
	return aux;

    * string GetHtmlHex(const Color &c){
	string aux="";
	unsigned i=0;
	while(i<3){
		aux= aux + DecaHex(c.col.at(i));	//DecaHex lo toma como unsigned
		i++;
	}	
	aux= "#" + aux ;
	return aux;

    * string DecaHex(unsigned n){
	string aux, aux2;
	if(n<16){
			switch(n){
				case 0:
					aux="0";
				break;
				case 1:
					aux="1";
				break;
				case 2:
					aux="2";
				break;
				case 3:
					aux="3";
				break;
				case 4:
					aux="4";
				break;
				case 5:
					aux="5";
				break;
				case 6:
					aux="6";
				break;
				case 7:
					aux="7";
				break;
				case 8:
					aux="8";
				break;
				case 9:
					aux="9";
				break;
				case 10:
					aux="A";
				break;
				case 11:
					aux="B";
				break;
				case 12:
					aux="C";
				break;
				case 13:
					aux="D";
				break;
				case 14:
					aux="E";
				break;
				case 15:
					aux="F";
				break;
			}
	}
	else{
		aux= DecaHex(n/16) ;
		aux2=DecaHex(n%16);
		aux=aux + aux2;
	}
	return aux;

    * string GetHtmlRGB(const Color &c){
	string aux="";
	unsigned i=0;
	while(i<3){
		if(i==0 or i==3){
			aux=aux+to_string(c.col.at(i));
		}
		else{
			aux=aux+","+to_string(c.col.at(i));
		}
		i++;
	}
	aux= "RGB("+aux+")";
	return aux;

    * Color GetComplementario(const Color &c){
	unsigned i=0;
	Color aux;
	while(i<3){
		aux.col.at(i)=255 - unsigned(c.col.at(i));
		i++;
	}
	return aux;

    * Color Sumar(Color &c1, Color &c2){
	Color aux;
	unsigned i=0;
	while(i<3){
		aux.col.at(i)=c1.col.at(i) + c2.col.at(i);
		i++;
	}
	return aux;

    * Color Restar(Color &c1, Color &c2){
	Color aux;
	unsigned i=0;
	while(i<3){
		aux.col.at(i)=c1.col.at(i) - c2.col.at(i);
		i++;
	}
	return aux;

    * void CrearSvgConTextoEscritoEnAltoContraste(string nombre, string mensaje, const Color& c){
std::ofstream file;
file.open(nombre + ".svg");
file << "<svg xmlns='http://www.w3.org/2000/svg'>\n";
file << "<rect x='0' y='0' height='100' width='500' style='fill: " << GetHtmlHex(GetComplementario(c)) << "'/> \n";
file << "<text x='5' y='18' style='fill: " << GetHtmlRGB(c) << ";background-color: "<<GetHtmlHex(GetComplementario(c)) <<"#ff0000'>\n";
file << mensaje << "\n";
file << "</text>\n</svg>\n";
file.close();
};

<!--* **Arbol**
![Imagen de Arbol](https://user-images.githubusercontent.com/48501354/87235248-81f1f680-c3b0-11ea-9f74-48d16670bd1d.jpg "Arbol")-->
