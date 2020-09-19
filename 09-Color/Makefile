.PHONY= test clean

test: ColorTest
	./ColorTest

ColorTest: ColorTest.cpp Color.o Color.h
	$(CXX) $(CXXFLAGS) ColorTest.cpp Color.o -o ColorTest

Color.o: Color.cpp Color.h
	$(CXX) $(CXXFLAGS) -c Color.cpp -o Color.o

clean:
	-rm -f ColorTest Color.o