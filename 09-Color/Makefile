test: ColorTest.o Color.o
	g++ ColorTest.o Color.o -o test

ColorTest.o: ColorTest.cpp
	g++ -c ColorTest.cpp

Color.o: Color.cpp
	g++ -c Color.cpp

clean:
	rm *.o Color