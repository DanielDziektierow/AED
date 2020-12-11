all:  Filtrar

Filtrar:  Filtrar.o Color.o ColorTest.o Punto.o PuntoTest.o PoligonoCont.o PoligonoCTest.o
	g++  Filtrar.o Color.o ColorTest.o Punto.o PuntoTest.o PoligonoCont.o PoligonoCTest.o -o Filtrar

PoligonoLink.o: PoligonoLink.cpp 
	g++ -c PoligonoLink.cpp

PoligonoLTest.o: PoligonoLTest.cpp
	g++ -c PoligonoLTest.cpp

PoligonoCont.o: PoligonoCont.cpp 
	g++ -c PoligonoCont.cpp

PoligonoCTest.o: PoligonoCTest.cpp
	g++ -c PoligonoCTest.cpp

Color.o: Color.cpp 
	g++ -c Color.cpp

ColorTest.o: ColorTest.cpp 
	g++ -c ColorTest.cpp

Punto.o: Punto.cpp
	g++ -c Punto.cpp

PuntoTest.o: PuntoTest.cpp
	g++ -c PuntoTest.cpp

Filtrar.o: Filtrar.cpp
	g++ -c Filtrar.cpp

clean:
	rm *.o Filtrar.exe