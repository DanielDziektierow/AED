all:  Poligono

Poligono:  Poligono.o 
	g++  Poligono.o  -o Poligono

Poligono.o: Poligono.cpp PoligonoLink.h
	g++ -c Poligono.cpp

PoligonoTest.o: PoligonoTest.cpp 
	g++ -c PoligonoTest.cpp

clean:
	rm *.o Poligono