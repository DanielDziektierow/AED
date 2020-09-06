/*Materia: Algoritmos y Estructura de Datos
*Curso: K1051
*Anio y Cuatrimestre: 2020 1er Cuat.
*Legajo: 1599872
*Apellido: Dziektierow
*Nombre: Daniel
*/

#include "Color.h"
//Prototipos
Color Mezclar(Color &, Color &);
string GetHtmlHex(const Color &);
string GetHtmlRGB(const Color &);
Color Sumar(Color &, Color &);
Color Restar(Color &, Color &);
Color GetComplementario(const Color &);
string DecaHex(unsigned n);


int main(){
	Color c1={222,111,123};
	Color c2={10,10,10};
}

Color Mezclar(Color &c1, Color &c2){
	Color aux={0,0,0};
	unsigned i=0;
	while(i<3){
		aux.col.at(i)=c1.col.at(i) + c2.col.at(i);
		i++;
	}
	return aux;
}

string GetHtmlHex(const Color &c){
	string aux="";
	unsigned i=0;
	while(i<3){
		aux= aux + DecaHex(c.col.at(i));	//DecaHex lo toma como unsigned
		i++;
	}	
	aux= "#" + aux ;
	return aux;
}

string DecaHex(unsigned n){
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
}

string GetHtmlRGB(const Color &c){
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
}

Color GetComplementario(const Color &c){
	unsigned i=0;
	Color aux;
	while(i<3){
		aux.col.at(i)=255 - unsigned(c.col.at(i));
		i++;
	}
	return aux;
}
