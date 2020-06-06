#include <cassert>

bool Bisiesto(unsigned);

int main(){
	assert(Bisiesto(2800));
	assert(Bisiesto(2400));
	assert(Bisiesto(2000));
	assert(Bisiesto(1600));
}

bool Bisiesto(unsigned anio){
	return anio>=1582 and anio%4 == 0 and anio%100 == 0 and anio%400 == 0;
}
