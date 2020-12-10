all:  Filtrar

Filtrar:  Filtrar.o Color.o ColorTest.o Punto.o PuntoTest.o PoligonoCont.o
	g++  Filtrar.o Color.o ColorTest.o Punto.o PuntoTest.o PoligonoCont.o -o Filtrar

PoligonoLink.o: PoligonoLink.cpp 
	g++ -c PoligonoLink.cpp

PoligonoCont.o: PoligonoCont.cpp 
	g++ -c PoligonoCont.cpp

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