#include "Color.h"
#include <cassert>

int main(){
	assert( isIgual(ROJO, ROJO) );
	assert( not isIgual(ROJO, AZUL) );
    return 0;
}