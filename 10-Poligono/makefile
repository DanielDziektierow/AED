all:  Filtrar

Filtrar:  Filtrar.o Color.o ColorTest.o Punto.o PuntoTest.o
	g++  Filtrar.o Color.o ColorTest.o Punto.o PuntoTest.o -o Filtrar

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